/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 3.0 structured OpenMP C versions - EP
  This benchmark is an OpenMP C version of the NPB EP code.
  
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
  Author: P. O. Frederickson 
          D. H. Bailey
          A. C. Woo
  OpenMP C version: S. Satoh
  
  3.0 structure translation: M. Popov  
  
--------------------------------------------------------------------*/
#include "../common/npb-C.h"
#include "npbparams.h"
/* parameters */
#define	MK		16
#define	MM		(M - MK)
#define	NN		(1 << MM)
#define	NK		(1 << MK)
#define	NQ		10
#define EPSILON		1.0e-8
#define	A		1220703125.0
#define	S		271828183.0
#define	TIMERS_ENABLED	FALSE
/* global variables */
/* common /storage/ */
#include <omp.h> 
static double x[131072];
static double q[10];
/*--------------------------------------------------------------------
      program EMBAR
c-------------------------------------------------------------------*/
/*
c   This is the serial version of the APP Benchmark 1,
c   the "embarassingly parallel" benchmark.
c
c   M is the Log_2 of the number of complex pairs of uniform (0, 1) random
c   numbers.  MK is the Log_2 of the size of each batch of uniform random
c   numbers.  MK can be set for convenience on a given system, since it does
c   not affect the results.
*/

int main(int argc,char **argv)
{
  double Mops;
  double t1;
  double t2;
  double t3;
  double t4;
  double x1;
  double x2;
  double sx;
  double sy;
  double tm;
  double an;
  double tt;
  double gc;
  double dum[3] = {(1.0), (1.0), (1.0)};
  int np;
  int ierr;
  int node;
  int no_nodes;
  int i;
  int ik;
  int kk;
  int l;
  int k;
  int nit;
  int ierrcode;
  int no_large_nodes;
  int np_add;
  int k_offset;
  int j;
  int nthreads = 1;
  boolean verified;
/* character*13 */
  char size[14];
/*
c   Because the size of the problem is too large to store in a 32-bit
c   integer for some classes, we put it into a string (for printing).
c   Have to strip off the decimal point put in there by the floating
c   point print statement (internal file)
*/
  printf("\n\n NAS Parallel Benchmarks 3.0 structured OpenMP C version - EP Benchmark\n");
  sprintf(size,"%12.0f",(pow(2.0,(28 + 1))));
  
#pragma omp parallel for private (j)
  for (j = 13; j >= 1; j += -1) {
    if (size[j] == '.') 
      size[j] = ' ';
  }
  printf(" Number of random numbers generated: %13s\n",size);
  verified = 0;
/*
c   Compute the number of "batches" of random number pairs generated 
c   per processor. Adjust if the number of processors does not evenly 
c   divide the total number
*/
  np = 1 << 28 - 16;
/*
c   Call the random number generator functions and initialize
c   the x-array to reduce the effects of paging on the timings.
c   Also, call all mathematical functions that are used. Make
c   sure these initializations cannot be eliminated as dead code.
*/
  vranlc(0,&dum[0],dum[1],&dum[2]);
  dum[0] = randlc(&dum[1],dum[2]);
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 131071; i += 1) {
    x[i] = - 1.0e99;
  }
  Mops = log((sqrt((fabs((1.0 > 1.0?1.0 : 1.0))))));
  timer_clear(1);
  timer_clear(2);
  timer_clear(3);
  timer_start(1);
  vranlc(0,&t1,1220703125.0,x);
/*   Compute AN = A ^ (2 * NK) (mod 2^46). */
  t1 = 1220703125.0;
  for (i = 1; i <= 17; i += 1) {
    t2 = randlc(&t1,t1);
  }
  an = t1;
  tt = 271828183.0;
  gc = 0.0;
  sx = 0.0;
  sy = 0.0;
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 9; i += 1) {
    q[i] = 0.0;
  }
/*
c   Each instance of this loop may be performed independently. We compute
c   the k offsets separately to take into account the fact that some nodes
c   have more numbers to generate than others
*/
  k_offset = - 1;
{
    double t1;
    double t2;
    double t3;
    double t4;
    double x1;
    double x2;
    int kk;
    int i;
    int ik;
    int l;
/* private copy of q[0:NQ-1] */
    double qq[10];
    
#pragma omp parallel for private (i)
    for (i = 0; i <= 9; i += 1) {
      qq[i] = 0.0;
    }
//#pragma omp parallel for copyin(x, qq) private(x1, x2, t1, t2, t3, t4, ik, kk, i, l) reduction(+:sx) reduction(+:sy) 
    for (k = 1; k <= np; k += 1) {
      kk = k_offset + k;
      t1 = 271828183.0;
      t2 = an;
/*      Find starting seed t1 for this kk. */
      for (i = 1; i <= 100; i += 1) {
        ik = kk / 2;
        if (2 * ik != kk) 
          t3 = randlc(&t1,t2);
        if (ik == 0) 
          break; 
        t3 = randlc(&t2,t2);
        kk = ik;
      }
/*      Compute uniform pseudorandom numbers. */
      if (0 == 1) 
        timer_start(3);
      vranlc(2 * (1 << 16),&t1,1220703125.0,x - 1);
      if (0 == 1) 
        timer_stop(3);
/*
c       Compute Gaussian deviates by acceptance-rejection method and 
c       tally counts in concentric square annuli.  This loop is not 
c       vectorizable.
*/
      if (0 == 1) 
        timer_start(2);
      for (i = 0; i <= 65535; i += 1) {
        x1 = 2.0 * x[2 * i] - 1.0;
        x2 = 2.0 * x[2 * i + 1] - 1.0;
        t1 = x1 * x1 + x2 * x2;
        if (t1 <= 1.0) {
          t2 = sqrt(- 2.0 * log(t1) / t1);
/* Xi */
          t3 = x1 * t2;
/* Yi */
          t4 = x2 * t2;
          l = ((fabs(t3) > fabs(t4)?fabs(t3) : fabs(t4)));
/* counts */
          qq[l] += 1.0;
/* sum of Xi */
          sx = sx + t3;
/* sum of Yi */
          sy = sy + t4;
        }
      }
      if (0 == 1) 
        timer_stop(2);
    }
{
      
#pragma omp parallel for private (i)
      for (i = 0; i <= 9; i += 1) {
        q[i] += qq[i];
      }
    }
//#if defined(_OPENMP)
//    nthreads = omp_get_num_threads();
//#endif /* _OPENMP */    
/* end of parallel region */
  }
  
#pragma omp parallel for private (i) reduction (+:gc)
  for (i = 0; i <= 9; i += 1) {
    gc = gc + q[i];
  }
  timer_stop(1);
  tm = timer_read(1);
  nit = 0;
  if (28 == 24) {
    if (fabs((sx - - 3.247834652034740e3) / sx) <= 1.0e-8 && fabs((sy - - 6.958407078382297e3) / sy) <= 1.0e-8) {
      verified = 1;
    }
  }
   else if (28 == 25) {
    if (fabs((sx - - 2.863319731645753e3) / sx) <= 1.0e-8 && fabs((sy - - 6.320053679109499e3) / sy) <= 1.0e-8) {
      verified = 1;
    }
  }
   else if (28 == 28) {
    if (fabs((sx - - 4.295875165629892e3) / sx) <= 1.0e-8 && fabs((sy - - 1.580732573678431e4) / sy) <= 1.0e-8) {
      verified = 1;
    }
  }
   else if (28 == 30) {
    if (fabs((sx - 4.033815542441498e4) / sx) <= 1.0e-8 && fabs((sy - - 2.660669192809235e4) / sy) <= 1.0e-8) {
      verified = 1;
    }
  }
   else if (28 == 32) {
    if (fabs((sx - 4.764367927995374e4) / sx) <= 1.0e-8 && fabs((sy - - 8.084072988043731e4) / sy) <= 1.0e-8) {
      verified = 1;
    }
  }
  Mops = pow(2.0,(28 + 1)) / tm / 1000000.0;
  printf("EP Benchmark Results: \nCPU Time = %10.4f\nN = 2^%5d\nNo. Gaussian Pairs = %15.0f\nSums = %25.15e %25.15e\nCounts:\n",tm,28,gc,sx,sy);
  for (i = 0; i <= 9; i += 1) {
    printf("%3d %15.0f\n",i,q[i]);
  }
  c_print_results("EP",'A',28 + 1,0,0,nit,nthreads,tm,Mops,"Random numbers generated",verified,"3.0 structured","14 Jan 2020","(none)","(none)","-lm","(none)","(none)","(none)","randdp");
  if (0 == 1) {
    printf("Total time:     %f",(timer_read(1)));
    printf("Gaussian pairs: %f",(timer_read(2)));
    printf("Random numbers: %f",(timer_read(3)));
  }
}
