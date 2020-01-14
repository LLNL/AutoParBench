/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 3.0 structured OpenMP C versions - MG
  This benchmark is an OpenMP C version of the NPB MG code.
  
  The OpenMP C 2.3 versions are derived by RWCP from the serial Fortran versions 
  in "NPB 2.3-serial" developed by NAS. 3.0 translation is performed by the UVSQ.
  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.
  Information on OpenMP activities at RWCP is available at:
           http://pdplab.trc.rwcp.or.jp/pdperf/Omni/
  
  Information on NAS Parallel Benchmarks 2.3 is available at:
  
           http://www.nas.nasa.gov/NAS/NPB/
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
  Authors: E. Barszcz
           P. Frederickson
           A. Woo
           M. Yarrow
  OpenMP C version: S. Satoh
  3.0 structure translation: F. Conti
  
--------------------------------------------------------------------*/
#include "../common/npb-C.h"
#include "globals.h"
/* parameters */
#define T_BENCH	1
#define	T_INIT	2
/* global variables */
/* common /grid/ */
#include <omp.h> 
static int is1;
static int is2;
static int is3;
static int ie1;
static int ie2;
static int ie3;
/* functions prototypes */
static void setup(int *n1,int *n2,int *n3,int lt);
static void mg3P(double ****u,double ***v,double ****r,double a[4],double c[4],int n1,int n2,int n3,int k);
static void psinv(double ***r,double ***u,int n1,int n2,int n3,double c[4],int k);
static void resid(double ***u,double ***v,double ***r,int n1,int n2,int n3,double a[4],int k);
static void rprj3(double ***r,int m1k,int m2k,int m3k,double ***s,int m1j,int m2j,int m3j,int k);
static void interp(double ***z,int mm1,int mm2,int mm3,double ***u,int n1,int n2,int n3,int k);
static void norm2u3(double ***r,int n1,int n2,int n3,double *rnm2,double *rnmu,int nx,int ny,int nz);
static void rep_nrm(double ***u,int n1,int n2,int n3,char *title,int kk);
static void comm3(double ***u,int n1,int n2,int n3,int kk);
static void zran3(double ***z,int n1,int n2,int n3,int nx,int ny,int k);
static void showall(double ***z,int n1,int n2,int n3);
static double power(double a,int n);
static void bubble(double ten[1037][2],int j1[1037][2],int j2[1037][2],int j3[1037][2],int m,int ind);
static void zero3(double ***z,int n1,int n2,int n3);
static void nonzero(double ***z,int n1,int n2,int n3);
/*--------------------------------------------------------------------
      program mg
c-------------------------------------------------------------------*/

int main(int argc,char *argv[])
{
/*-------------------------------------------------------------------------
c k is the current level. It is passed down through subroutine args
c and is NOT global. it is the current iteration
c------------------------------------------------------------------------*/
  int k;
  int it;
  double t;
  double tinit;
  double mflops;
  int nthreads = 1;
/*-------------------------------------------------------------------------
c These arrays are in common because they are quite large
c and probably shouldn't be allocated on the stack. They
c are always passed as subroutine args. 
c------------------------------------------------------------------------*/
  double ****u;
  double ***v;
  double ****r;
  double a[4];
  double c[4];
  double rnm2;
  double rnmu;
  double epsilon = 1.0e-8;
  int n1;
  int n2;
  int n3;
  int nit;
  double verify_value;
  boolean verified;
  int i;
  int j;
  int l;
  FILE *fp;
  timer_clear(1);
  timer_clear(2);
  timer_start(2);
/*----------------------------------------------------------------------
c Read in and broadcast input data
c---------------------------------------------------------------------*/
  printf("\n\n NAS Parallel Benchmarks 3.0 structured OpenMP C version - MG Benchmark\n\n");
  fp = fopen("mg.input","r");
  if (fp != ((void *)0)) {
    printf(" Reading from input file mg.input\n");
    fscanf(fp,"%d",&lt);
    while(fgetc(fp) != '\n')
      ;
    fscanf(fp,"%d%d%d",&nx[lt],&ny[lt],&nz[lt]);
    while(fgetc(fp) != '\n')
      ;
    fscanf(fp,"%d",&nit);
    while(fgetc(fp) != '\n')
      ;
    for (i = 0; i <= 7; i += 1) {
      fscanf(fp,"%d",&debug_vec[i]);
    }
    fclose(fp);
  }
   else {
    printf(" No input file. Using compiled defaults\n");
    lt = 8;
    nit = 4;
    nx[lt] = 256;
    ny[lt] = 256;
    nz[lt] = 256;
    
#pragma omp parallel for private (i)
    for (i = 0; i <= 7; i += 1) {
      debug_vec[i] = 0;
    }
  }
  if (nx[lt] != ny[lt] || nx[lt] != nz[lt]) {
    Class = 'U';
  }
   else if (nx[lt] == 32 && nit == 4) {
    Class = 'S';
  }
   else if (nx[lt] == 64 && nit == 40) {
    Class = 'W';
  }
   else if (nx[lt] == 256 && nit == 20) {
    Class = 'B';
  }
   else if (nx[lt] == 512 && nit == 20) {
    Class = 'C';
  }
   else if (nx[lt] == 256 && nit == 4) {
    Class = 'A';
  }
   else {
    Class = 'U';
  }
/*--------------------------------------------------------------------
c  Use these for debug info:
c---------------------------------------------------------------------
c     debug_vec(0) = 1 !=> report all norms
c     debug_vec(1) = 1 !=> some setup information
c     debug_vec(1) = 2 !=> more setup information
c     debug_vec(2) = k => at level k or below, show result of resid
c     debug_vec(3) = k => at level k or below, show result of psinv
c     debug_vec(4) = k => at level k or below, show result of rprj
c     debug_vec(5) = k => at level k or below, show result of interp
c     debug_vec(6) = 1 => (unused)
c     debug_vec(7) = 1 => (unused)
c-------------------------------------------------------------------*/
  a[0] = - 8.0 / 3.0;
  a[1] = 0.0;
  a[2] = 1.0 / 6.0;
  a[3] = 1.0 / 12.0;
  if (Class == 'A' || Class == 'S' || Class == 'W') {
/*--------------------------------------------------------------------
c     Coefficients for the S(a) smoother
c-------------------------------------------------------------------*/
    c[0] = - 3.0 / 8.0;
    c[1] = 1.0 / 32.0;
    c[2] = - 1.0 / 64.0;
    c[3] = 0.0;
  }
   else {
/*--------------------------------------------------------------------
c     Coefficients for the S(b) smoother
c-------------------------------------------------------------------*/
    c[0] = - 3.0 / 17.0;
    c[1] = 1.0 / 33.0;
    c[2] = - 1.0 / 61.0;
    c[3] = 0.0;
  }
  lb = 1;
  setup(&n1,&n2,&n3,lt);
  u = ((double ****)(malloc((lt + 1) * sizeof(double ***))));
  for (l = lt; l >= 1; l += -1) {
    u[l] = ((double ***)(malloc(m3[l] * sizeof(double **))));
    for (k = 0; k <= m3[l] - 1; k += 1) {
      u[l][k] = ((double **)(malloc(m2[l] * sizeof(double *))));
      for (j = 0; j <= m2[l] - 1; j += 1) {
        u[l][k][j] = ((double *)(malloc(m1[l] * sizeof(double ))));
      }
    }
  }
  v = ((double ***)(malloc(m3[lt] * sizeof(double **))));
  for (k = 0; k <= m3[lt] - 1; k += 1) {
    v[k] = ((double **)(malloc(m2[lt] * sizeof(double *))));
    for (j = 0; j <= m2[lt] - 1; j += 1) {
      v[k][j] = ((double *)(malloc(m1[lt] * sizeof(double ))));
    }
  }
  r = ((double ****)(malloc((lt + 1) * sizeof(double ***))));
  for (l = lt; l >= 1; l += -1) {
    r[l] = ((double ***)(malloc(m3[l] * sizeof(double **))));
    for (k = 0; k <= m3[l] - 1; k += 1) {
      r[l][k] = ((double **)(malloc(m2[l] * sizeof(double *))));
      for (j = 0; j <= m2[l] - 1; j += 1) {
        r[l][k][j] = ((double *)(malloc(m1[l] * sizeof(double ))));
      }
    }
  }
  zero3(u[lt],n1,n2,n3);
  zran3(v,n1,n2,n3,nx[lt],ny[lt],lt);
  norm2u3(v,n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt]);
/*    printf("\n norms of random v are\n");
    printf(" %4d%19.12e%19.12e\n", 0, rnm2, rnmu);
    printf(" about to evaluate resid, k= %d\n", lt);*/
  printf(" Size: %3dx%3dx%3d (class %1c)\n",nx[lt],ny[lt],nz[lt],Class);
  printf(" Iterations: %3d\n",nit);
  resid(u[lt],v,r[lt],n1,n2,n3,a,lt);
  norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt]);
/*c---------------------------------------------------------------------
c     One iteration for startup
c---------------------------------------------------------------------*/
  mg3P(u,v,r,a,c,n1,n2,n3,lt);
  resid(u[lt],v,r[lt],n1,n2,n3,a,lt);
  setup(&n1,&n2,&n3,lt);
  zero3(u[lt],n1,n2,n3);
  zran3(v,n1,n2,n3,nx[lt],ny[lt],lt);
  timer_stop(2);
  timer_start(1);
  resid(u[lt],v,r[lt],n1,n2,n3,a,lt);
  norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt]);
  for (it = 1; it <= nit; it += 1) {
    mg3P(u,v,r,a,c,n1,n2,n3,lt);
    resid(u[lt],v,r[lt],n1,n2,n3,a,lt);
  }
  norm2u3(r[lt],n1,n2,n3,&rnm2,&rnmu,nx[lt],ny[lt],nz[lt]);
{
//#if defined(_OPENMP)
//  nthreads = omp_get_num_threads();
//#endif /* _OPENMP */
/* end parallel */
  }
  timer_stop(1);
  t = timer_read(1);
  tinit = timer_read(2);
  verified = 0;
  verify_value = 0.0;
  printf(" Initialization time: %15.3f seconds\n",tinit);
  printf(" Benchmark completed\n");
  if (Class != 'U') {
    if (Class == 'S') {
      verify_value = 0.530770700573e-04;
    }
     else if (Class == 'W') {
/* 40 iterations*/
      verify_value = 0.250391406439e-17;
/*				0.183103168997d-044 iterations*/
    }
     else if (Class == 'A') {
      verify_value = 0.2433365309e-5;
    }
     else if (Class == 'B') {
      verify_value = 0.180056440132e-5;
    }
     else if (Class == 'C') {
      verify_value = 0.570674826298e-06;
    }
    if (fabs(rnm2 - verify_value) <= epsilon) {
      verified = 1;
      printf(" VERIFICATION SUCCESSFUL\n");
      printf(" L2 Norm is %20.12e\n",rnm2);
      printf(" Error is   %20.12e\n",rnm2 - verify_value);
    }
     else {
      verified = 0;
      printf(" VERIFICATION FAILED\n");
      printf(" L2 Norm is             %20.12e\n",rnm2);
      printf(" The correct L2 Norm is %20.12e\n",verify_value);
    }
  }
   else {
    verified = 0;
    printf(" Problem size unknown\n");
    printf(" NO VERIFICATION PERFORMED\n");
  }
  if (t != 0.0) {
    int nn = nx[lt] * ny[lt] * nz[lt];
    mflops = 58. * nit * nn * 1.0e-6 / t;
  }
   else {
    mflops = 0.0;
  }
  c_print_results("MG",Class,nx[lt],ny[lt],nz[lt],nit,nthreads,t,mflops,"          floating point",verified,"3.0 structured","28 Nov 2019","(none)","(none)","-lm","(none)","(none)","(none)","randdp");
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void setup(int *n1,int *n2,int *n3,int lt)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int k;
  for (k = lt - 1; k >= 1; k += -1) {
    nx[k] = nx[k + 1] / 2;
    ny[k] = ny[k + 1] / 2;
    nz[k] = nz[k + 1] / 2;
  }
  
#pragma omp parallel for private (k)
  for (k = 1; k <= lt; k += 1) {
    m1[k] = nx[k] + 2;
    m2[k] = nz[k] + 2;
    m3[k] = ny[k] + 2;
  }
  is1 = 1;
  ie1 = nx[lt];
   *n1 = nx[lt] + 2;
  is2 = 1;
  ie2 = ny[lt];
   *n2 = ny[lt] + 2;
  is3 = 1;
  ie3 = nz[lt];
   *n3 = nz[lt] + 2;
  if (debug_vec[1] >= 1) {
    printf(" in setup, \n");
    printf("  lt  nx  ny  nz  n1  n2  n3 is1 is2 is3 ie1 ie2 ie3\n");
    printf("%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d%4d\n",lt,nx[lt],ny[lt],nz[lt], *n1, *n2, *n3,is1,is2,is3,ie1,ie2,ie3);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void mg3P(double ****u,double ***v,double ****r,double a[4],double c[4],int n1,int n2,int n3,int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     multigrid V-cycle routine
c-------------------------------------------------------------------*/
  int j;
/*--------------------------------------------------------------------
c     down cycle.
c     restrict the residual from the find grid to the coarse
c-------------------------------------------------------------------*/
  for (k = lt; k >= lb + 1; k += -1) {
    j = k - 1;
    rprj3(r[k],m1[k],m2[k],m3[k],r[j],m1[j],m2[j],m3[j],k);
  }
  k = lb;
/*--------------------------------------------------------------------
c     compute an approximate solution on the coarsest grid
c-------------------------------------------------------------------*/
  zero3(u[k],m1[k],m2[k],m3[k]);
  psinv(r[k],u[k],m1[k],m2[k],m3[k],c,k);
  for (k = lb + 1; k <= lt - 1; k += 1) {
    j = k - 1;
/*--------------------------------------------------------------------
c        prolongate from level k-1  to k
c-------------------------------------------------------------------*/
    zero3(u[k],m1[k],m2[k],m3[k]);
    interp(u[j],m1[j],m2[j],m3[j],u[k],m1[k],m2[k],m3[k],k);
/*--------------------------------------------------------------------
c        compute residual for level k
c-------------------------------------------------------------------*/
    resid(u[k],r[k],r[k],m1[k],m2[k],m3[k],a,k);
/*--------------------------------------------------------------------
c        apply smoother
c-------------------------------------------------------------------*/
    psinv(r[k],u[k],m1[k],m2[k],m3[k],c,k);
  }
  j = lt - 1;
  k = lt;
  interp(u[j],m1[j],m2[j],m3[j],u[lt],n1,n2,n3,k);
  resid(u[lt],v,r[lt],n1,n2,n3,a,k);
  psinv(r[lt],u[lt],n1,n2,n3,c,k);
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void psinv(double ***r,double ***u,int n1,int n2,int n3,double c[4],int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     psinv applies an approximate inverse as smoother:  u = u + Cr
c
c     This  implementation costs  15A + 4M per result, where
c     A and M denote the costs of Addition and Multiplication.  
c     Presuming coefficient c(3) is zero (the NPB assumes this,
c     but it is thus not a general case), 2A + 1M may be eliminated,
c     resulting in 13A + 3M.
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/
  int i3;
  int i2;
  int i1;
  double r1[1037];
  double r2[1037];
  for (i3 = 1; i3 <= n3 - 1 - 1; i3 += 1) {
    for (i2 = 1; i2 <= n2 - 1 - 1; i2 += 1) {
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        r1[i1] = r[i3][i2 - 1][i1] + r[i3][i2 + 1][i1] + r[i3 - 1][i2][i1] + r[i3 + 1][i2][i1];
        r2[i1] = r[i3 - 1][i2 - 1][i1] + r[i3 - 1][i2 + 1][i1] + r[i3 + 1][i2 - 1][i1] + r[i3 + 1][i2 + 1][i1];
      }
      for (i1 = 1; i1 <= n1 - 1 - 1; i1 += 1) {
        u[i3][i2][i1] = u[i3][i2][i1] + c[0] * r[i3][i2][i1] + c[1] * (r[i3][i2][i1 - 1] + r[i3][i2][i1 + 1] + r1[i1]) + c[2] * (r2[i1] + r1[i1 - 1] + r1[i1 + 1]);
/*--------------------------------------------------------------------
c  Assume c(3) = 0    (Enable line below if c(3) not= 0)
c---------------------------------------------------------------------
c    >                     + c(3) * ( r2(i1-1) + r2(i1+1) )
c-------------------------------------------------------------------*/
      }
    }
  }
/*--------------------------------------------------------------------
c     exchange boundary points
c-------------------------------------------------------------------*/
  comm3(u,n1,n2,n3,k);
  if (debug_vec[0] >= 1) {
    rep_nrm(u,n1,n2,n3,"   psinv",k);
  }
  if (debug_vec[3] >= k) {
    showall(u,n1,n2,n3);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void resid(double ***u,double ***v,double ***r,int n1,int n2,int n3,double a[4],int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     resid computes the residual:  r = v - Au
c
c     This  implementation costs  15A + 4M per result, where
c     A and M denote the costs of Addition (or Subtraction) and 
c     Multiplication, respectively. 
c     Presuming coefficient a(1) is zero (the NPB assumes this,
c     but it is thus not a general case), 3A + 1M may be eliminated,
c     resulting in 12A + 3M.
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/
  int i3;
  int i2;
  int i1;
  double u1[1037];
  double u2[1037];
  for (i3 = 1; i3 <= n3 - 1 - 1; i3 += 1) {
    for (i2 = 1; i2 <= n2 - 1 - 1; i2 += 1) {
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        u1[i1] = u[i3][i2 - 1][i1] + u[i3][i2 + 1][i1] + u[i3 - 1][i2][i1] + u[i3 + 1][i2][i1];
        u2[i1] = u[i3 - 1][i2 - 1][i1] + u[i3 - 1][i2 + 1][i1] + u[i3 + 1][i2 - 1][i1] + u[i3 + 1][i2 + 1][i1];
      }
      for (i1 = 1; i1 <= n1 - 1 - 1; i1 += 1) {
        r[i3][i2][i1] = v[i3][i2][i1] - a[0] * u[i3][i2][i1] - a[2] * (u2[i1] + u1[i1 - 1] + u1[i1 + 1]) - a[3] * (u2[i1 - 1] + u2[i1 + 1]);
/*--------------------------------------------------------------------
c  Assume a(1) = 0      (Enable 2 lines below if a(1) not= 0)
c---------------------------------------------------------------------
c    >                     - a(1) * ( u(i1-1,i2,i3) + u(i1+1,i2,i3)
c    >                              + u1(i1) )
c-------------------------------------------------------------------*/
      }
    }
  }
/*--------------------------------------------------------------------
c     exchange boundary data
c--------------------------------------------------------------------*/
  comm3(r,n1,n2,n3,k);
  if (debug_vec[0] >= 1) {
    rep_nrm(r,n1,n2,n3,"   resid",k);
  }
  if (debug_vec[2] >= k) {
    showall(r,n1,n2,n3);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void rprj3(double ***r,int m1k,int m2k,int m3k,double ***s,int m1j,int m2j,int m3j,int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     rprj3 projects onto the next coarser grid, 
c     using a trilinear Finite Element projection:  s = r' = P r
c     
c     This  implementation costs  20A + 4M per result, where
c     A and M denote the costs of Addition and Multiplication.  
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  
c-------------------------------------------------------------------*/
  int j3;
  int j2;
  int j1;
  int i3;
  int i2;
  int i1;
  int d1;
  int d2;
  int d3;
  double x1[1037];
  double y1[1037];
  double x2;
  double y2;
  if (m1k == 3) {
    d1 = 2;
  }
   else {
    d1 = 1;
  }
  if (m2k == 3) {
    d2 = 2;
  }
   else {
    d2 = 1;
  }
  if (m3k == 3) {
    d3 = 2;
  }
   else {
    d3 = 1;
  }
  for (j3 = 1; j3 <= m3j - 1 - 1; j3 += 1) {
    i3 = 2 * j3 - d3;
/*C        i3 = 2*j3-1*/
    for (j2 = 1; j2 <= m2j - 1 - 1; j2 += 1) {
      i2 = 2 * j2 - d2;
/*C           i2 = 2*j2-1*/
      for (j1 = 1; j1 <= m1j - 1; j1 += 1) {
        i1 = 2 * j1 - d1;
/*C             i1 = 2*j1-1*/
        x1[i1] = r[i3 + 1][i2][i1] + r[i3 + 1][i2 + 2][i1] + r[i3][i2 + 1][i1] + r[i3 + 2][i2 + 1][i1];
        y1[i1] = r[i3][i2][i1] + r[i3 + 2][i2][i1] + r[i3][i2 + 2][i1] + r[i3 + 2][i2 + 2][i1];
      }
      for (j1 = 1; j1 <= m1j - 1 - 1; j1 += 1) {
        i1 = 2 * j1 - d1;
/*C             i1 = 2*j1-1*/
        y2 = r[i3][i2][i1 + 1] + r[i3 + 2][i2][i1 + 1] + r[i3][i2 + 2][i1 + 1] + r[i3 + 2][i2 + 2][i1 + 1];
        x2 = r[i3 + 1][i2][i1 + 1] + r[i3 + 1][i2 + 2][i1 + 1] + r[i3][i2 + 1][i1 + 1] + r[i3 + 2][i2 + 1][i1 + 1];
        s[j3][j2][j1] = 0.5 * r[i3 + 1][i2 + 1][i1 + 1] + 0.25 * (r[i3 + 1][i2 + 1][i1] + r[i3 + 1][i2 + 1][i1 + 2] + x2) + 0.125 * (x1[i1] + x1[i1 + 2] + y2) + 0.0625 * (y1[i1] + y1[i1 + 2]);
      }
    }
  }
  comm3(s,m1j,m2j,m3j,k - 1);
  if (debug_vec[0] >= 1) {
    rep_nrm(s,m1j,m2j,m3j,"   rprj3",k - 1);
  }
  if (debug_vec[4] >= k) {
    showall(s,m1j,m2j,m3j);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void interp(double ***z,int mm1,int mm2,int mm3,double ***u,int n1,int n2,int n3,int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     interp adds the trilinear interpolation of the correction
c     from the coarser grid to the current approximation:  u = u + Qu'
c     
c     Observe that this  implementation costs  16A + 4M, where
c     A and M denote the costs of Addition and Multiplication.  
c     Note that this vectorizes, and is also fine for cache 
c     based machines.  Vector machines may get slightly better 
c     performance however, with 8 separate "do i1" loops, rather than 4.
c-------------------------------------------------------------------*/
  int i3;
  int i2;
  int i1;
  int d1;
  int d2;
  int d3;
  int t1;
  int t2;
  int t3;
/*
c note that m = 1037 in globals.h but for this only need to be
c 535 to handle up to 1024^3
c      integer m
c      parameter( m=535 )
*/
  double z1[1037];
  double z2[1037];
  double z3[1037];
  if (n1 != 3 && n2 != 3 && n3 != 3) {
    for (i3 = 0; i3 <= mm3 - 1 - 1; i3 += 1) {
      for (i2 = 0; i2 <= mm2 - 1 - 1; i2 += 1) {
        for (i1 = 0; i1 <= mm1 - 1; i1 += 1) {
          z1[i1] = z[i3][i2 + 1][i1] + z[i3][i2][i1];
          z2[i1] = z[i3 + 1][i2][i1] + z[i3][i2][i1];
          z3[i1] = z[i3 + 1][i2 + 1][i1] + z[i3 + 1][i2][i1] + z1[i1];
        }
        for (i1 = 0; i1 <= mm1 - 1 - 1; i1 += 1) {
          u[2 * i3][2 * i2][2 * i1] = u[2 * i3][2 * i2][2 * i1] + z[i3][i2][i1];
          u[2 * i3][2 * i2][2 * i1 + 1] = u[2 * i3][2 * i2][2 * i1 + 1] + 0.5 * (z[i3][i2][i1 + 1] + z[i3][i2][i1]);
        }
        for (i1 = 0; i1 <= mm1 - 1 - 1; i1 += 1) {
          u[2 * i3][2 * i2 + 1][2 * i1] = u[2 * i3][2 * i2 + 1][2 * i1] + 0.5 * z1[i1];
          u[2 * i3][2 * i2 + 1][2 * i1 + 1] = u[2 * i3][2 * i2 + 1][2 * i1 + 1] + 0.25 * (z1[i1] + z1[i1 + 1]);
        }
        for (i1 = 0; i1 <= mm1 - 1 - 1; i1 += 1) {
          u[2 * i3 + 1][2 * i2][2 * i1] = u[2 * i3 + 1][2 * i2][2 * i1] + 0.5 * z2[i1];
          u[2 * i3 + 1][2 * i2][2 * i1 + 1] = u[2 * i3 + 1][2 * i2][2 * i1 + 1] + 0.25 * (z2[i1] + z2[i1 + 1]);
        }
        for (i1 = 0; i1 <= mm1 - 1 - 1; i1 += 1) {
          u[2 * i3 + 1][2 * i2 + 1][2 * i1] = u[2 * i3 + 1][2 * i2 + 1][2 * i1] + 0.25 * z3[i1];
          u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] = u[2 * i3 + 1][2 * i2 + 1][2 * i1 + 1] + 0.125 * (z3[i1] + z3[i1 + 1]);
        }
      }
    }
  }
   else {
    if (n1 == 3) {
      d1 = 2;
      t1 = 1;
    }
     else {
      d1 = 1;
      t1 = 0;
    }
    if (n2 == 3) {
      d2 = 2;
      t2 = 1;
    }
     else {
      d2 = 1;
      t2 = 0;
    }
    if (n3 == 3) {
      d3 = 2;
      t3 = 1;
    }
     else {
      d3 = 1;
      t3 = 0;
    }
{
      for (i3 = d3; i3 <= mm3 - 1; i3 += 1) {
        for (i2 = d2; i2 <= mm2 - 1; i2 += 1) {
          for (i1 = d1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - d3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - d3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] + z[i3 - 1][i2 - 1][i1 - 1];
          }
          for (i1 = 1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - d3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - d3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] + 0.5 * (z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
        }
        for (i2 = 1; i2 <= mm2 - 1; i2 += 1) {
          for (i1 = d1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - d3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - d3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] + 0.5 * (z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
          for (i1 = 1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - d3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - d3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] + 0.25 * (z[i3 - 1][i2][i1] + z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
        }
      }
      for (i3 = 1; i3 <= mm3 - 1; i3 += 1) {
        for (i2 = d2; i2 <= mm2 - 1; i2 += 1) {
          for (i1 = d1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - d1 - 1] + 0.5 * (z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
          for (i1 = 1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - d2 - 1][2 * i1 - t1 - 1] + 0.25 * (z[i3][i2 - 1][i1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
        }
        for (i2 = 1; i2 <= mm2 - 1; i2 += 1) {
          for (i1 = d1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - d1 - 1] + 0.25 * (z[i3][i2][i1 - 1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
          for (i1 = 1; i1 <= mm1 - 1; i1 += 1) {
            u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] = u[2 * i3 - t3 - 1][2 * i2 - t2 - 1][2 * i1 - t1 - 1] + 0.125 * (z[i3][i2][i1] + z[i3][i2 - 1][i1] + z[i3][i2][i1 - 1] + z[i3][i2 - 1][i1 - 1] + z[i3 - 1][i2][i1] + z[i3 - 1][i2 - 1][i1] + z[i3 - 1][i2][i1 - 1] + z[i3 - 1][i2 - 1][i1 - 1]);
          }
        }
      }
    }
//end #pragma omp parallel
  }
  if (debug_vec[0] >= 1) {
    rep_nrm(z,mm1,mm2,mm3,"z: inter",k - 1);
    rep_nrm(u,n1,n2,n3,"u: inter",k);
  }
  if (debug_vec[5] >= k) {
    showall(z,mm1,mm2,mm3);
    showall(u,n1,n2,n3);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void norm2u3(double ***r,int n1,int n2,int n3,double *rnm2,double *rnmu,int nx,int ny,int nz)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     norm2u3 evaluates approximations to the L2 norm and the
c     uniform (or L-infinity or Chebyshev) norm, under the
c     assumption that the boundaries are periodic or zero.  Add the
c     boundaries in with half weight (quarter weight on the edges
c     and eighth weight at the corners) for inhomogeneous boundaries.
c-------------------------------------------------------------------*/
  double s = 0.0;
  int i3;
  int i2;
  int i1;
  int n;
  double a = 0.0;
  double tmp = 0.0;
  n = nx * ny * nz;
  for (i3 = 1; i3 <= n3 - 1 - 1; i3 += 1) {
    for (i2 = 1; i2 <= n2 - 1 - 1; i2 += 1) {
      for (i1 = 1; i1 <= n1 - 1 - 1; i1 += 1) {
        s = s + r[i3][i2][i1] * r[i3][i2][i1];
        a = fabs(r[i3][i2][i1]);
        if (a > tmp) 
          tmp = a;
      }
    }
  }
   *rnmu = tmp;
   *rnm2 = sqrt(s / ((double )n));
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void rep_nrm(double ***u,int n1,int n2,int n3,char *title,int kk)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     report on norm
c-------------------------------------------------------------------*/
  double rnm2;
  double rnmu;
  norm2u3(u,n1,n2,n3,&rnm2,&rnmu,nx[kk],ny[kk],nz[kk]);
  printf(" Level%2d in %8s: norms =%21.14e%21.14e\n",kk,title,rnm2,rnmu);
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void comm3(double ***u,int n1,int n2,int n3,int kk)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     comm3 organizes the communication on all borders 
c-------------------------------------------------------------------*/
  int i1;
  int i2;
  int i3;
/* axis = 1 */
{
    
#pragma omp parallel for private (i1,i2,i3) firstprivate (n3)
    for (i3 = 1; i3 <= n3 - 1 - 1; i3 += 1) {
      
#pragma omp parallel for private (i2)
      for (i2 = 1; i2 <= n2 - 1 - 1; i2 += 1) {
        u[i3][i2][n1 - 1] = u[i3][i2][1];
        u[i3][i2][0] = u[i3][i2][n1 - 2];
      }
//    }
/* axis = 2 */
//#pragma omp for
//    for ( i3 = 1; i3 < n3-1; i3++) {
      
#pragma omp parallel for private (i1)
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        u[i3][n2 - 1][i1] = u[i3][1][i1];
        u[i3][0][i1] = u[i3][n2 - 2][i1];
      }
    }
/* axis = 3 */
    
#pragma omp parallel for private (i1,i2) firstprivate (n1,n2)
    for (i2 = 0; i2 <= n2 - 1; i2 += 1) {
      
#pragma omp parallel for private (i1) firstprivate (n3)
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        u[n3 - 1][i2][i1] = u[1][i2][i1];
        u[0][i2][i1] = u[n3 - 2][i2][i1];
      }
    }
//end #pragma omp parallel
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void zran3(double ***z,int n1,int n2,int n3,int nx,int ny,int k)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     zran3  loads +1 at ten randomly chosen points,
c     loads -1 at a different ten random points,
c     and zero elsewhere.
c-------------------------------------------------------------------*/
#define MM	10
#define	A	pow(5.0,13)
#define	X	314159265.e0    
  int i0;
  int m0;
  int m1;
  int i1;
  int i2;
  int i3;
  int d1;
  int e1;
  int e2;
  int e3;
  double xx;
  double x0;
  double x1;
  double a1;
  double a2;
  double ai;
  double ten[10][2];
  double best;
  int i;
  int j1[10][2];
  int j2[10][2];
  int j3[10][2];
  int jg[4][10][2];
  double rdummy;
  a1 = power((pow(5.0,13)),nx);
  a2 = power((pow(5.0,13)),nx * ny);
  zero3(z,n1,n2,n3);
  i = is1 - 1 + nx * (is2 - 1 + ny * (is3 - 1));
  ai = power((pow(5.0,13)),i);
  d1 = ie1 - is1 + 1;
  e1 = ie1 - is1 + 2;
  e2 = ie2 - is2 + 2;
  e3 = ie3 - is3 + 2;
  x0 = 314159265.e0;
  rdummy = randlc(&x0,ai);
  for (i3 = 1; i3 <= e3 - 1; i3 += 1) {
    x1 = x0;
    for (i2 = 1; i2 <= e2 - 1; i2 += 1) {
      xx = x1;
      vranlc(d1,&xx,(pow(5.0,13)),&z[i3][i2][0]);
      rdummy = randlc(&x1,a1);
    }
    rdummy = randlc(&x0,a2);
  }
/*--------------------------------------------------------------------
c       call comm3(z,n1,n2,n3)
c       call showall(z,n1,n2,n3)
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     each processor looks for twenty candidates
c-------------------------------------------------------------------*/
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 9; i += 1) {
    ten[i][1] = 0.0;
    j1[i][1] = 0;
    j2[i][1] = 0;
    j3[i][1] = 0;
    ten[i][0] = 1.0;
    j1[i][0] = 0;
    j2[i][0] = 0;
    j3[i][0] = 0;
  }
  for (i3 = 1; i3 <= n3 - 1 - 1; i3 += 1) {
    for (i2 = 1; i2 <= n2 - 1 - 1; i2 += 1) {
      for (i1 = 1; i1 <= n1 - 1 - 1; i1 += 1) {
        if (z[i3][i2][i1] > ten[0][1]) {
          ten[0][1] = z[i3][i2][i1];
          j1[0][1] = i1;
          j2[0][1] = i2;
          j3[0][1] = i3;
          bubble(ten,j1,j2,j3,10,1);
        }
        if (z[i3][i2][i1] < ten[0][0]) {
          ten[0][0] = z[i3][i2][i1];
          j1[0][0] = i1;
          j2[0][0] = i2;
          j3[0][0] = i3;
          bubble(ten,j1,j2,j3,10,0);
        }
      }
    }
  }
/*--------------------------------------------------------------------
c     Now which of these are globally best?
c-------------------------------------------------------------------*/
  i1 = 10 - 1;
  i0 = 10 - 1;
  for (i = 10 - 1; i >= 0; i += -1) {
    best = z[j3[i1][1]][j2[i1][1]][j1[i1][1]];
    if (best == z[j3[i1][1]][j2[i1][1]][j1[i1][1]]) {
      jg[0][i][1] = 0;
      jg[1][i][1] = is1 - 1 + j1[i1][1];
      jg[2][i][1] = is2 - 1 + j2[i1][1];
      jg[3][i][1] = is3 - 1 + j3[i1][1];
      i1 = i1 - 1;
    }
     else {
      jg[0][i][1] = 0;
      jg[1][i][1] = 0;
      jg[2][i][1] = 0;
      jg[3][i][1] = 0;
    }
    ten[i][1] = best;
    best = z[j3[i0][0]][j2[i0][0]][j1[i0][0]];
    if (best == z[j3[i0][0]][j2[i0][0]][j1[i0][0]]) {
      jg[0][i][0] = 0;
      jg[1][i][0] = is1 - 1 + j1[i0][0];
      jg[2][i][0] = is2 - 1 + j2[i0][0];
      jg[3][i][0] = is3 - 1 + j3[i0][0];
      i0 = i0 - 1;
    }
     else {
      jg[0][i][0] = 0;
      jg[1][i][0] = 0;
      jg[2][i][0] = 0;
      jg[3][i][0] = 0;
    }
    ten[i][0] = best;
  }
  m1 = i1 + 1;
  m0 = i0 + 1;
/*    printf(" negative charges at");
    for (i = 0; i < MM; i++) {
	if (i%5 == 0) printf("\n");
	printf(" (%3d,%3d,%3d)", jg[1][i][0], jg[2][i][0], jg[3][i][0]);
    }
    printf("\n positive charges at");
    for (i = 0; i < MM; i++) {
	if (i%5 == 0) printf("\n");
	printf(" (%3d,%3d,%3d)", jg[1][i][1], jg[2][i][1], jg[3][i][1]);
    }
    printf("\n small random numbers were\n");
    for (i = MM-1; i >= 0; i--) {
	printf(" %15.8e", ten[i][0]);
    }
    printf("\n and they were found on processor number\n");
    for (i = MM-1; i >= 0; i--) {
	printf(" %4d", jg[0][i][0]);
    }
    printf("\n large random numbers were\n");
    for (i = MM-1; i >= 0; i--) {
	printf(" %15.8e", ten[i][1]);
    }
    printf("\n and they were found on processor number\n");
    for (i = MM-1; i >= 0; i--) {
	printf(" %4d", jg[0][i][1]);
    }
    printf("\n");*/
  
#pragma omp parallel for private (i1,i2,i3)
  for (i3 = 0; i3 <= n3 - 1; i3 += 1) {
    
#pragma omp parallel for private (i1,i2)
    for (i2 = 0; i2 <= n2 - 1; i2 += 1) {
      
#pragma omp parallel for private (i1)
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        z[i3][i2][i1] = 0.0;
      }
    }
  }
  for (i = 10 - 1; i >= m0; i += -1) {
    z[j3[i][0]][j2[i][0]][j1[i][0]] = - 1.0;
  }
  for (i = 10 - 1; i >= m1; i += -1) {
    z[j3[i][1]][j2[i][1]][j1[i][1]] = 1.0;
  }
  comm3(z,n1,n2,n3,k);
/*--------------------------------------------------------------------
c          call showall(z,n1,n2,n3)
c-------------------------------------------------------------------*/
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void showall(double ***z,int n1,int n2,int n3)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int i1;
  int i2;
  int i3;
  int m1;
  int m2;
  int m3;
  m1 = (n1 < 18?n1 : 18);
  m2 = (n2 < 14?n2 : 14);
  m3 = (n3 < 18?n3 : 18);
  printf("\n");
  for (i3 = 0; i3 <= m3 - 1; i3 += 1) {
    for (i1 = 0; i1 <= m1 - 1; i1 += 1) {
      for (i2 = 0; i2 <= m2 - 1; i2 += 1) {
        printf("%6.3f",z[i3][i2][i1]);
      }
      printf("\n");
    }
    printf(" - - - - - - - \n");
  }
  printf("\n");
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static double power(double a,int n)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     power  raises an integer, disguised as a double
c     precision real, to an integer power
c-------------------------------------------------------------------*/
  double aj;
  int nj;
  double rdummy;
  double power;
  power = 1.0;
  nj = n;
  aj = a;
  while(nj != 0){
    if (nj % 2 == 1) 
      rdummy = randlc(&power,aj);
    rdummy = randlc(&aj,aj);
    nj = nj / 2;
  }
  return power;
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void bubble(double ten[1037][2],int j1[1037][2],int j2[1037][2],int j3[1037][2],int m,int ind)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c     bubble        does a bubble sort in direction dir
c-------------------------------------------------------------------*/
  double temp;
  int i;
  int j_temp;
  if (ind == 1) {
    for (i = 0; i <= m - 1 - 1; i += 1) {
      if (ten[i][ind] > ten[i + 1][ind]) {
        temp = ten[i + 1][ind];
        ten[i + 1][ind] = ten[i][ind];
        ten[i][ind] = temp;
        j_temp = j1[i + 1][ind];
        j1[i + 1][ind] = j1[i][ind];
        j1[i][ind] = j_temp;
        j_temp = j2[i + 1][ind];
        j2[i + 1][ind] = j2[i][ind];
        j2[i][ind] = j_temp;
        j_temp = j3[i + 1][ind];
        j3[i + 1][ind] = j3[i][ind];
        j3[i][ind] = j_temp;
      }
       else {
        return ;
      }
    }
  }
   else {
    for (i = 0; i <= m - 1 - 1; i += 1) {
      if (ten[i][ind] < ten[i + 1][ind]) {
        temp = ten[i + 1][ind];
        ten[i + 1][ind] = ten[i][ind];
        ten[i][ind] = temp;
        j_temp = j1[i + 1][ind];
        j1[i + 1][ind] = j1[i][ind];
        j1[i][ind] = j_temp;
        j_temp = j2[i + 1][ind];
        j2[i + 1][ind] = j2[i][ind];
        j2[i][ind] = j_temp;
        j_temp = j3[i + 1][ind];
        j3[i + 1][ind] = j3[i][ind];
        j3[i][ind] = j_temp;
      }
       else {
        return ;
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void zero3(double ***z,int n1,int n2,int n3)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int i1;
  int i2;
  int i3;
  
#pragma omp parallel for private (i1,i2,i3) firstprivate (n2,n3)
  for (i3 = 0; i3 <= n3 - 1; i3 += 1) {
    
#pragma omp parallel for private (i1,i2) firstprivate (n1)
    for (i2 = 0; i2 <= n2 - 1; i2 += 1) {
      
#pragma omp parallel for private (i1)
      for (i1 = 0; i1 <= n1 - 1; i1 += 1) {
        z[i3][i2][i1] = 0.0;
      }
    }
  }
}
/*---- end of program ------------------------------------------------*/
