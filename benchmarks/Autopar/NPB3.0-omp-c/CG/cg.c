/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 3.0 structured OpenMP C versions - CG
  This benchmark is an OpenMP C version of the NPB CG code.
  
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
  Authors: M. Yarrow
           C. Kuszmaul
  OpenMP C version: S. Satoh
  
  3.0 structure translation: F. Conti 
--------------------------------------------------------------------*/
/*
c---------------------------------------------------------------------
c  Note: please observe that in the routine conj_grad three 
c  implementations of the sparse matrix-vector multiply have
c  been supplied.  The default matrix-vector multiply is not
c  loop unrolled.  The alternate implementations are unrolled
c  to a depth of 2 and unrolled to a depth of 8.  Please
c  experiment with these to find the fastest for your particular
c  architecture.  If reporting timing results, any of these three may
c  be used without penalty.
c---------------------------------------------------------------------
*/
#include "../common/npb-C.h"
#include "npbparams.h"
#define	NZ	NA*(NONZER+1)*(NONZER+1)+NA*(NONZER+2)
/* global variables */
/* common /partit_size/ */
#include <omp.h> 
static int naa;
static int nzz;
static int firstrow;
static int lastrow;
static int firstcol;
static int lastcol;
/* common /main_int_mem/ */
/* colidx[1:NZ] */
static int colidx[2198001];
/* rowstr[1:NA+1] */
static int rowstr[14002];
/* iv[1:2*NA+1] */
static int iv[28002];
/* arow[1:NZ] */
static int arow[2198001];
/* acol[1:NZ] */
static int acol[2198001];
/* common /main_flt_mem/ */
/* v[1:NA+1] */
static double v[14002];
/* aelt[1:NZ] */
static double aelt[2198001];
/* a[1:NZ] */
static double a[2198001];
/* x[1:NA+2] */
static double x[14003];
/* z[1:NA+2] */
static double z[14003];
/* p[1:NA+2] */
static double p[14003];
/* q[1:NA+2] */
static double q[14003];
/* r[1:NA+2] */
static double r[14003];
//static double w[NA+2+1];	/* w[1:NA+2] */
/* common /urando/ */
static double amult;
static double tran;
/* function declarations */
static 
//double w[],
void conj_grad(int colidx[],int rowstr[],double x[],double z[],double a[],double p[],double q[],double r[],double *rnorm);
static void makea(int n,int nz,double a[],int colidx[],int rowstr[],int nonzer,int firstrow,int lastrow,int firstcol,int lastcol,double rcond,int arow[],int acol[],double aelt[],double v[],int iv[],double shift);
static void sparse(double a[],int colidx[],int rowstr[],int n,int arow[],int acol[],double aelt[],int firstrow,int lastrow,double x[],boolean mark[],int nzloc[],int nnza);
static void sprnvc(int n,int nz,double v[],int iv[],int nzloc[],int mark[]);
static int icnvrt(double x,int ipwr2);
static void vecset(int n,double v[],int iv[],int *nzv,int i,double val);
/*--------------------------------------------------------------------
      program cg
--------------------------------------------------------------------*/

int main(int argc,char **argv)
{
  int i;
  int j;
  int k;
  int it;
  int nthreads = 1;
  double zeta;
  double rnorm;
  double norm_temp11;
  double norm_temp12;
  double t;
  double mflops;
  char class;
  boolean verified;
  double zeta_verify_value;
  double epsilon;
  firstrow = 1;
  lastrow = 14000;
  firstcol = 1;
  lastcol = 14000;
  if (14000 == 1400 && 11 == 7 && 15 == 15 && 20.0 == 10.0) {
    class = 'S';
    zeta_verify_value = 8.5971775078648;
  }
   else if (14000 == 7000 && 11 == 8 && 15 == 15 && 20.0 == 12.0) {
    class = 'W';
    zeta_verify_value = 10.362595087124;
  }
   else if (14000 == 14000 && 11 == 11 && 15 == 15 && 20.0 == 20.0) {
    class = 'A';
    zeta_verify_value = 17.130235054029;
  }
   else if (14000 == 75000 && 11 == 13 && 15 == 75 && 20.0 == 60.0) {
    class = 'B';
    zeta_verify_value = 22.712745482631;
  }
   else if (14000 == 150000 && 11 == 15 && 15 == 75 && 20.0 == 110.0) {
    class = 'C';
    zeta_verify_value = 28.973605592845;
  }
   else {
    class = 'U';
  }
  printf("\n\n NAS Parallel Benchmarks 3.0 structured OpenMP C version - CG Benchmark\n");
  printf(" Size: %10d\n",14000);
  printf(" Iterations: %5d\n",15);
  naa = 14000;
  nzz = 14000 * (11 + 1) * (11 + 1) + 14000 * (11 + 2);
/*--------------------------------------------------------------------
c  Initialize random number generator
c-------------------------------------------------------------------*/
  tran = 314159265.0;
  amult = 1220703125.0;
  zeta = randlc(&tran,amult);
/*--------------------------------------------------------------------
c  
c-------------------------------------------------------------------*/
  makea(naa,nzz,a,colidx,rowstr,11,firstrow,lastrow,firstcol,lastcol,1.0e-1,arow,acol,aelt,v,iv,20.0);
/*---------------------------------------------------------------------
c  Note: as a result of the above call to makea:
c        values of j used in indexing rowstr go from 1 --> lastrow-firstrow+1
c        values of colidx which are col indexes go from firstcol --> lastcol
c        So:
c        Shift the col index vals from actual (firstcol --> lastcol ) 
c        to local, i.e., (1 --> lastcol-firstcol+1)
c---------------------------------------------------------------------*/
{
    for (j = 1; j <= lastrow - firstrow + 1; j += 1) {
      
#pragma omp parallel for private (k)
      for (k = rowstr[j]; k <= rowstr[j + 1] - 1; k += 1) {
        colidx[k] = colidx[k] - firstcol + 1;
      }
    }
/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/
    
#pragma omp parallel for private (i)
    for (i = 1; i <= 14001; i += 1) {
      x[i] = 1.0;
    }
    
#pragma omp parallel for private (j)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      q[j] = 0.0;
      z[j] = 0.0;
      r[j] = 0.0;
      p[j] = 0.0;
    }
// end omp parallel
  }
  zeta = 0.0;
/*-------------------------------------------------------------------
c---->
c  Do one iteration untimed to init all code and data page tables
c---->                    (then reinit, start timing, to niter its)
c-------------------------------------------------------------------*/
  for (it = 1; it <= 1; it += 1) {
/*--------------------------------------------------------------------
c  The call to the conjugate gradient routine:
c-------------------------------------------------------------------*/
/* w,*/
    conj_grad(colidx,rowstr,x,z,a,p,q,r,&rnorm);
/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/
    norm_temp11 = 0.0;
    norm_temp12 = 0.0;
    
#pragma omp parallel for private (j) reduction (+:norm_temp11,norm_temp12)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      norm_temp11 = norm_temp11 + x[j] * z[j];
      norm_temp12 = norm_temp12 + z[j] * z[j];
    }
    norm_temp12 = 1.0 / sqrt(norm_temp12);
/*--------------------------------------------------------------------
c  Normalize z to obtain x
c-------------------------------------------------------------------*/
    
#pragma omp parallel for private (j) firstprivate (norm_temp12)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      x[j] = norm_temp12 * z[j];
    }
/* end of do one iteration untimed */
  }
/*--------------------------------------------------------------------
c  set starting vector to (1, 1, .... 1)
c-------------------------------------------------------------------*/
  
#pragma omp parallel for private (i)
  for (i = 1; i <= 14001; i += 1) {
    x[i] = 1.0;
  }
  zeta = 0.0;
  timer_clear(1);
  timer_start(1);
/*--------------------------------------------------------------------
c---->
c  Main Iteration for inverse power method
c---->
c-------------------------------------------------------------------*/
  for (it = 1; it <= 15; it += 1) {
/*--------------------------------------------------------------------
c  The call to the conjugate gradient routine:
c-------------------------------------------------------------------*/
/*, w*/
    conj_grad(colidx,rowstr,x,z,a,p,q,r,&rnorm);
/*--------------------------------------------------------------------
c  zeta = shift + 1/(x.z)
c  So, first: (x.z)
c  Also, find norm of z
c  So, first: (z.z)
c-------------------------------------------------------------------*/
    norm_temp11 = 0.0;
    norm_temp12 = 0.0;
    
#pragma omp parallel for private (j) reduction (+:norm_temp11,norm_temp12)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      norm_temp11 = norm_temp11 + x[j] * z[j];
      norm_temp12 = norm_temp12 + z[j] * z[j];
    }
    norm_temp12 = 1.0 / sqrt(norm_temp12);
    zeta = 20.0 + 1.0 / norm_temp11;
    if (it == 1) {
      printf("   iteration           ||r||                 zeta\n");
    }
    printf("    %5d       %20.14e%20.13e\n",it,rnorm,zeta);
/*--------------------------------------------------------------------
c  Normalize z to obtain x
c-------------------------------------------------------------------*/
    
#pragma omp parallel for private (j) firstprivate (norm_temp12)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      x[j] = norm_temp12 * z[j];
    }
/* end of main iter inv pow meth */
  }
{
//#if defined(_OPENMP)
//    nthreads = omp_get_num_threads();
//#endif /* _OPENMP */
/* end parallel */
  }
  timer_stop(1);
/*--------------------------------------------------------------------
c  End of timed section
c-------------------------------------------------------------------*/
  t = timer_read(1);
  printf(" Benchmark completed\n");
  epsilon = 1.0e-10;
//epsilon = 1.0e-2;
  if (class != 'U') {
    if (fabs(zeta - zeta_verify_value) <= epsilon) {
      verified = 1;
      printf(" VERIFICATION SUCCESSFUL\n");
      printf(" Zeta is    %20.12e\n",zeta);
      printf(" Error is   %20.12e\n",zeta - zeta_verify_value);
    }
     else {
      verified = 0;
      printf(" VERIFICATION FAILED\n");
      printf(" Zeta                %20.12e\n",zeta);
      printf(" The correct zeta is %20.12e\n",zeta_verify_value);
    }
  }
   else {
    verified = 0;
    printf(" Problem size unknown\n");
    printf(" NO VERIFICATION PERFORMED\n");
  }
  if (t != 0.0) {
    mflops = 2.0 * 15 * 14000 * (3.0 + (11 * (11 + 1)) + 25.0 * (5.0 + (11 * (11 + 1))) + 3.0) / t / 1000000.0;
  }
   else {
    mflops = 0.0;
  }
  c_print_results("CG",class,14000,0,0,15,nthreads,t,mflops,"          floating point",verified,"3.0 structured","14 Jan 2020","(none)","(none)","-lm","(none)","(none)","(none)","randdp");
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void conj_grad(
/* colidx[1:nzz] */
int colidx[],
/* rowstr[1:naa+1] */
int rowstr[],
/* x[*] */
double x[],
/* z[*] */
double z[],
/* a[1:nzz] */
double a[],
/* p[*] */
double p[],
/* q[*] */
double q[],
/* r[*] */
double r[],
//double w[],		/* w[*] */
double *rnorm)
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*---------------------------------------------------------------------
c  Floaging point arrays here are named as in NPB1 spec discussion of 
c  CG algorithm
c---------------------------------------------------------------------*/
{
  static int callcount = 0;
  double d;
  double sum;
  double rho;
  double rho0;
  double alpha;
  double beta;
  int i;
  int j;
  int k;
  int cgit;
  int cgitmax = 25;
  rho = 0.0;
/*--------------------------------------------------------------------
c  Initialize the CG algorithm:
c-------------------------------------------------------------------*/
{
    
#pragma omp parallel for private (j) firstprivate (naa)
    for (j = 1; j <= naa + 1; j += 1) {
      q[j] = 0.0;
      z[j] = 0.0;
      r[j] = x[j];
      p[j] = r[j];
//w[j] = 0.0;
    }
/*--------------------------------------------------------------------
c  rho = r.r
c  Now, obtain the norm of r: First, sum squares of r elements locally...
c-------------------------------------------------------------------*/
    
#pragma omp parallel for private (j) reduction (+:rho)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      rho = rho + r[j] * r[j];
    }
/* end omp parallel */
  }
/*--------------------------------------------------------------------
c---->
c  The conj grad iteration loop
c---->
c-------------------------------------------------------------------*/
  for (cgit = 1; cgit <= cgitmax; cgit += 1) {
    rho0 = rho;
    d = 0.0;
    rho = 0.0;
{
/*--------------------------------------------------------------------
c  q = A.p
c  The partition submatrix-vector multiply: use workspace w
c---------------------------------------------------------------------
C
C  NOTE: this version of the multiply is actually (slightly: maybe %5) 
C        faster on the sp2 on 16 nodes than is the unrolled-by-2 version 
C        below.   On the Cray t3d, the reverse is true, i.e., the 
C        unrolled-by-two version is some 10% faster.  
C        The unrolled-by-8 version below is significantly faster
C        on the Cray t3d - overall speed of code is 1.5 times faster.
*/
/* rolled version */
      
#pragma omp parallel for private (sum,j,k)
      for (j = 1; j <= lastrow - firstrow + 1; j += 1) {
        sum = 0.0;
        
#pragma omp parallel for private (k) reduction (+:sum)
        for (k = rowstr[j]; k <= rowstr[j + 1] - 1; k += 1) {
          sum = sum + a[k] * p[colidx[k]];
        }
//w[j] = sum;
        q[j] = sum;
      }
/* unrolled-by-two version
        for (j = 1; j <= lastrow-firstrow+1; j++) {
	    int iresidue;
	    double sum1, sum2;
	    i = rowstr[j]; 
            iresidue = (rowstr[j+1]-i) % 2;
            sum1 = 0.0;
            sum2 = 0.0;
            if (iresidue == 1) sum1 = sum1 + a[i]*p[colidx[i]];
	    for (k = i+iresidue; k <= rowstr[j+1]-2; k += 2) {
		sum1 = sum1 + a[k]   * p[colidx[k]];
		sum2 = sum2 + a[k+1] * p[colidx[k+1]];
	    }
            w[j] = sum1 + sum2;
        }
*/
/* unrolled-by-8 version
        for (j = 1; j <= lastrow-firstrow+1; j++) {
	    int iresidue;
            i = rowstr[j]; 
            iresidue = (rowstr[j+1]-i) % 8;
            sum = 0.0;
            for (k = i; k <= i+iresidue-1; k++) {
                sum = sum +  a[k] * p[colidx[k]];
            }
            for (k = i+iresidue; k <= rowstr[j+1]-8; k += 8) {
                sum = sum + a[k  ] * p[colidx[k  ]]
                          + a[k+1] * p[colidx[k+1]]
                          + a[k+2] * p[colidx[k+2]]
                          + a[k+3] * p[colidx[k+3]]
                          + a[k+4] * p[colidx[k+4]]
                          + a[k+5] * p[colidx[k+5]]
                          + a[k+6] * p[colidx[k+6]]
                          + a[k+7] * p[colidx[k+7]];
            }
            w[j] = sum;
        }
*/
/*	
	for (j = 1; j <= lastcol-firstcol+1; j++) {
            q[j] = w[j];
	}
*/
/*--------------------------------------------------------------------
c  Clear w for reuse...
c-------------------------------------------------------------------*/
/*
	for (j = 1; j <= lastcol-firstcol+1; j++) {
            w[j] = 0.0;
	}
*/
/*--------------------------------------------------------------------
c  Obtain p.q
c-------------------------------------------------------------------*/
      
#pragma omp parallel for private (j) reduction (+:d)
      for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
        d = d + p[j] * q[j];
      }
/*--------------------------------------------------------------------
c  Obtain alpha = rho / (p.q)
c-------------------------------------------------------------------*/
      alpha = rho0 / d;
/*--------------------------------------------------------------------
c  Save a temporary of rho
c-------------------------------------------------------------------*/
/*	rho0 = rho;*/
/*---------------------------------------------------------------------
c  Obtain z = z + alpha*p
c  and    r = r - alpha*q
c---------------------------------------------------------------------*/
      
#pragma omp parallel for private (j) reduction (+:rho) firstprivate (alpha)
      for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
        z[j] = z[j] + alpha * p[j];
        r[j] = r[j] - alpha * q[j];
//	}
/*---------------------------------------------------------------------
c  rho = r.r
c  Now, obtain the norm of r: First, sum squares of r elements locally...
c---------------------------------------------------------------------*/
/*
	for (j = 1; j <= lastcol-firstcol+1; j++) {*/
        rho = rho + r[j] * r[j];
      }
/*--------------------------------------------------------------------
c  Obtain beta:
c-------------------------------------------------------------------*/
      beta = rho / rho0;
/*--------------------------------------------------------------------
c  p = r + beta*p
c-------------------------------------------------------------------*/
      
#pragma omp parallel for private (j) firstprivate (beta)
      for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
        p[j] = r[j] + beta * p[j];
      }
      callcount++;
/* end omp parallel */
    }
/* end of do cgit=1,cgitmax */
  }
/*---------------------------------------------------------------------
c  Compute residual norm explicitly:  ||r|| = ||x - A.z||
c  First, form A.z
c  The partition submatrix-vector multiply
c---------------------------------------------------------------------*/
  sum = 0.0;
{
    
#pragma omp parallel for private (d,j,k) firstprivate (firstrow,lastrow)
    for (j = 1; j <= lastrow - firstrow + 1; j += 1) {
      d = 0.0;
      
#pragma omp parallel for private (k) reduction (+:d)
      for (k = rowstr[j]; k <= rowstr[j + 1] - 1; k += 1) {
        d = d + a[k] * z[colidx[k]];
      }
      r[j] = d;
    }
/*--------------------------------------------------------------------
c  At this point, r contains A.z
c-------------------------------------------------------------------*/
    
#pragma omp parallel for private (d,j) reduction (+:sum) firstprivate (firstcol,lastcol)
    for (j = 1; j <= lastcol - firstcol + 1; j += 1) {
      d = x[j] - r[j];
      sum = sum + d * d;
    }
//end omp parallel
  }
   *rnorm = sqrt(sum);
}
/*---------------------------------------------------------------------
c       generate the test problem for benchmark 6
c       makea generates a sparse matrix with a
c       prescribed sparsity distribution
c
c       parameter    type        usage
c
c       input
c
c       n            i           number of cols/rows of matrix
c       nz           i           nonzeros as declared array size
c       rcond        r*8         condition number
c       shift        r*8         main diagonal shift
c
c       output
c
c       a            r*8         array for nonzeros
c       colidx       i           col indices
c       rowstr       i           row pointers
c
c       workspace
c
c       iv, arow, acol i
c       v, aelt        r*8
c---------------------------------------------------------------------*/

static void makea(int n,int nz,
/* a[1:nz] */
double a[],
/* colidx[1:nz] */
int colidx[],
/* rowstr[1:n+1] */
int rowstr[],int nonzer,int firstrow,int lastrow,int firstcol,int lastcol,double rcond,
/* arow[1:nz] */
int arow[],
/* acol[1:nz] */
int acol[],
/* aelt[1:nz] */
double aelt[],
/* v[1:n+1] */
double v[],
/* iv[1:2*n+1] */
int iv[],double shift)
{
  int i;
  int nnza;
  int iouter;
  int ivelt;
  int ivelt1;
  int irow;
  int nzv;
/*--------------------------------------------------------------------
c      nonzer is approximately  (int(sqrt(nnza /n)));
c-------------------------------------------------------------------*/
  double size;
  double ratio;
  double scale;
  int jcol;
  size = 1.0;
  ratio = pow(rcond,1.0 / ((double )n));
  nnza = 0;
/*---------------------------------------------------------------------
c  Initialize colidx(n+1 .. 2n) to zero.
c  Used by sprnvc to mark nonzero positions
c---------------------------------------------------------------------*/
  
#pragma omp parallel for private (i)
  for (i = 1; i <= n; i += 1) {
    colidx[n + i] = 0;
  }
  for (iouter = 1; iouter <= n; iouter += 1) {
    nzv = nonzer;
    sprnvc(n,nzv,v,iv,&colidx[0],&colidx[n]);
    vecset(n,v,iv,&nzv,iouter,0.5);
    for (ivelt = 1; ivelt <= nzv; ivelt += 1) {
      jcol = iv[ivelt];
      if (jcol >= firstcol && jcol <= lastcol) {
        scale = size * v[ivelt];
        for (ivelt1 = 1; ivelt1 <= nzv; ivelt1 += 1) {
          irow = iv[ivelt1];
          if (irow >= firstrow && irow <= lastrow) {
            nnza = nnza + 1;
            if (nnza > nz) {
              printf("Space for matrix elements exceeded in makea\n");
              printf("nnza, nzmax = %d, %d\n",nnza,nz);
              printf("iouter = %d\n",iouter);
              exit(1);
            }
            acol[nnza] = jcol;
            arow[nnza] = irow;
            aelt[nnza] = v[ivelt1] * scale;
          }
        }
      }
    }
    size = size * ratio;
  }
/*---------------------------------------------------------------------
c       ... add the identity * rcond to the generated matrix to bound
c           the smallest eigenvalue from below by rcond
c---------------------------------------------------------------------*/
  for (i = firstrow; i <= lastrow; i += 1) {
    if (i >= firstcol && i <= lastcol) {
      iouter = n + i;
      nnza = nnza + 1;
      if (nnza > nz) {
        printf("Space for matrix elements exceeded in makea\n");
        printf("nnza, nzmax = %d, %d\n",nnza,nz);
        printf("iouter = %d\n",iouter);
        exit(1);
      }
      acol[nnza] = i;
      arow[nnza] = i;
      aelt[nnza] = rcond - shift;
    }
  }
/*---------------------------------------------------------------------
c       ... make the sparse matrix from list of elements with duplicates
c           (v and iv are used as  workspace)
c---------------------------------------------------------------------*/
  sparse(a,colidx,rowstr,n,arow,acol,aelt,firstrow,lastrow,v,&iv[0],&iv[n],nnza);
}
/*---------------------------------------------------
c       generate a sparse matrix from a list of
c       [col, row, element] tri
c---------------------------------------------------*/

static void sparse(
/* a[1:*] */
double a[],
/* colidx[1:*] */
int colidx[],
/* rowstr[1:*] */
int rowstr[],int n,
/* arow[1:*] */
int arow[],
/* acol[1:*] */
int acol[],
/* aelt[1:*] */
double aelt[],int firstrow,int lastrow,
/* x[1:n] */
double x[],
/* mark[1:n] */
boolean mark[],
/* nzloc[1:n] */
int nzloc[],int nnza)
/*---------------------------------------------------------------------
c       rows range from firstrow to lastrow
c       the rowstr pointers are defined for nrows = lastrow-firstrow+1 values
c---------------------------------------------------------------------*/
{
  int nrows;
  int i;
  int j;
  int jajp1;
  int nza;
  int k;
  int nzrow;
  double xi;
/*--------------------------------------------------------------------
c    how many rows of result
c-------------------------------------------------------------------*/
  nrows = lastrow - firstrow + 1;
/*--------------------------------------------------------------------
c     ...count the number of triples in each row
c-------------------------------------------------------------------*/
  
#pragma omp parallel for private (j)
  for (j = 1; j <= n; j += 1) {
    rowstr[j] = 0;
    mark[j] = 0;
  }
  rowstr[n + 1] = 0;
  for (nza = 1; nza <= nnza; nza += 1) {
    j = arow[nza] - firstrow + 1 + 1;
    rowstr[j] = rowstr[j] + 1;
  }
  rowstr[1] = 1;
  for (j = 2; j <= nrows + 1; j += 1) {
    rowstr[j] = rowstr[j] + rowstr[j - 1];
  }
/*---------------------------------------------------------------------
c     ... rowstr(j) now is the location of the first nonzero
c           of row j of a
c---------------------------------------------------------------------*/
/*---------------------------------------------------------------------
c     ... preload data pages
c---------------------------------------------------------------------*/
  for (j = 0; j <= nrows - 1; j += 1) {
    
#pragma omp parallel for private (k)
    for (k = rowstr[j]; k <= rowstr[j + 1] - 1; k += 1) {
      a[k] = 0.0;
    }
  }
/*--------------------------------------------------------------------
c     ... do a bucket sort of the triples on the row index
c-------------------------------------------------------------------*/
  for (nza = 1; nza <= nnza; nza += 1) {
    j = arow[nza] - firstrow + 1;
    k = rowstr[j];
    a[k] = aelt[nza];
    colidx[k] = acol[nza];
    rowstr[j] = rowstr[j] + 1;
  }
/*--------------------------------------------------------------------
c       ... rowstr(j) now points to the first element of row j+1
c-------------------------------------------------------------------*/
  for (j = nrows; j >= 1; j += -1) {
    rowstr[j + 1] = rowstr[j];
  }
  rowstr[1] = 1;
/*--------------------------------------------------------------------
c       ... generate the actual output rows by adding elements
c-------------------------------------------------------------------*/
  nza = 0;
  
#pragma omp parallel for private (i) firstprivate (n)
  for (i = 1; i <= n; i += 1) {
    x[i] = 0.0;
    mark[i] = 0;
  }
  jajp1 = rowstr[1];
  for (j = 1; j <= nrows; j += 1) {
    nzrow = 0;
/*--------------------------------------------------------------------
c          ...loop over the jth row of a
c-------------------------------------------------------------------*/
    for (k = jajp1; k <= rowstr[j + 1] - 1; k += 1) {
      i = colidx[k];
      x[i] = x[i] + a[k];
      if (mark[i] == 0 && x[i] != 0.0) {
        mark[i] = 1;
        nzrow = nzrow + 1;
        nzloc[nzrow] = i;
      }
    }
/*--------------------------------------------------------------------
c          ... extract the nonzeros of this row
c-------------------------------------------------------------------*/
    for (k = 1; k <= nzrow; k += 1) {
      i = nzloc[k];
      mark[i] = 0;
      xi = x[i];
      x[i] = 0.0;
      if (xi != 0.0) {
        nza = nza + 1;
        a[nza] = xi;
        colidx[nza] = i;
      }
    }
    jajp1 = rowstr[j + 1];
    rowstr[j + 1] = nza + rowstr[1];
  }
}
/*---------------------------------------------------------------------
c       generate a sparse n-vector (v, iv)
c       having nzv nonzeros
c
c       mark(i) is set to 1 if position i is nonzero.
c       mark is all zero on entry and is reset to all zero before exit
c       this corrects a performance bug found by John G. Lewis, caused by
c       reinitialization of mark on every one of the n calls to sprnvc
---------------------------------------------------------------------*/

static void sprnvc(int n,int nz,
/* v[1:*] */
double v[],
/* iv[1:*] */
int iv[],
/* nzloc[1:n] */
int nzloc[],
/* mark[1:n] */
int mark[])
{
  int nn1;
  int nzrow;
  int nzv;
  int ii;
  int i;
  double vecelt;
  double vecloc;
  nzv = 0;
  nzrow = 0;
  nn1 = 1;
  do {
    nn1 = 2 * nn1;
  }while (nn1 < n);
/*--------------------------------------------------------------------
c    nn1 is the smallest power of two not less than n
c-------------------------------------------------------------------*/
  while(nzv < nz){
    vecelt = randlc(&tran,amult);
/*--------------------------------------------------------------------
c   generate an integer between 1 and n in a portable manner
c-------------------------------------------------------------------*/
    vecloc = randlc(&tran,amult);
    i = icnvrt(vecloc,nn1) + 1;
    if (i > n) 
      continue; 
/*--------------------------------------------------------------------
c  was this integer generated already?
c-------------------------------------------------------------------*/
    if (mark[i] == 0) {
      mark[i] = 1;
      nzrow = nzrow + 1;
      nzloc[nzrow] = i;
      nzv = nzv + 1;
      v[nzv] = vecelt;
      iv[nzv] = i;
    }
  }
  for (ii = 1; ii <= nzrow; ii += 1) {
    i = nzloc[ii];
    mark[i] = 0;
  }
}
/*---------------------------------------------------------------------
* scale a double precision number x in (0,1) by a power of 2 and chop it
*---------------------------------------------------------------------*/

static int icnvrt(double x,int ipwr2)
{
  return (int )(ipwr2 * x);
}
/*--------------------------------------------------------------------
c       set ith element of sparse vector (v, iv) with
c       nzv nonzeros to val
c-------------------------------------------------------------------*/

static void vecset(int n,
/* v[1:*] */
double v[],
/* iv[1:*] */
int iv[],int *nzv,int i,double val)
{
  int k;
  boolean set;
  set = 0;
  
#pragma omp parallel for private (k)
  for (k = 1; k <=  *nzv; k += 1) {
    if (iv[k] == i) {
      v[k] = val;
      set = 1;
    }
  }
  if (set == 0) {
     *nzv =  *nzv + 1;
    v[ *nzv] = val;
    iv[ *nzv] = i;
  }
}
