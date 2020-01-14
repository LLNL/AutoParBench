/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 3.0 structured OpenMP C versions - FT
  This benchmark is an OpenMP C version of the NPB FT code.
  
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
  Authors: D. Bailey
           W. Saphir
  OpenMP C version: S. Satoh
  
  3.0 structure translation: M. Popov
--------------------------------------------------------------------*/
#include "../common/npb-C.h"
/* global variables */
#include "global.h"
/* function declarations */
#include <omp.h> 
static void evolve(dcomplex u0[128][256][256],dcomplex u1[128][256][256],int t,int indexmap[128][256][256],int d[3]);
static void compute_initial_conditions(dcomplex u0[128][256][256],int d[3]);
static void ipow46(double a,int exponent,double *result);
static void setup();
static void compute_indexmap(int indexmap[128][256][256],int d[3]);
static void print_timers();
static void fft(int dir,dcomplex x1[128][256][256],dcomplex x2[128][256][256]);
static void cffts1(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18]);
static void cffts2(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18]);
static void cffts3(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18]);
static void fft_init(int n);
static void cfftz(int is,int m,int n,dcomplex x[256][18],dcomplex y[256][18]);
static void fftz2(int is,int l,int m,int n,int ny,int ny1,dcomplex u[256],dcomplex x[256][18],dcomplex y[256][18]);
static int ilog2(int n);
static void checksum(int i,dcomplex u1[128][256][256],int d[3]);
static void verify(int d1,int d2,int d3,int nt,boolean *verified,char *class);
/*--------------------------------------------------------------------
c FT benchmark
c-------------------------------------------------------------------*/

int main(int argc,char **argv)
{
/*c-------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int i;
  int ierr;
/*------------------------------------------------------------------
c u0, u1, u2 are the main arrays in the problem. 
c Depending on the decomposition, these arrays will have different 
c dimensions. To accomodate all possibilities, we allocate them as 
c one-dimensional arrays and pass them to subroutines for different 
c views
c  - u0 contains the initial (transformed) initial condition
c  - u1 and u2 are working arrays
c  - indexmap maps i,j,k of u0 to the correct i^2+j^2+k^2 for the
c    time evolution operator. 
c-----------------------------------------------------------------*/
/*--------------------------------------------------------------------
c Large arrays are in common so that they are allocated on the
c heap rather than the stack. This common block is not
c referenced directly anywhere else. Padding is to avoid accidental 
c cache problems, since all array sizes are powers of two.
c-------------------------------------------------------------------*/
  static dcomplex u0[128][256][256];
  static dcomplex pad1[3];
  static dcomplex u1[128][256][256];
  static dcomplex pad2[3];
  static dcomplex u2[128][256][256];
  static dcomplex pad3[3];
  static int indexmap[128][256][256];
  int iter;
  int nthreads = 1;
  double total_time;
  double mflops;
  boolean verified;
  char class;
/*--------------------------------------------------------------------
c Run the entire problem once to make sure all data is touched. 
c This reduces variable startup costs, which is important for such a 
c short benchmark. The other NPB 2 implementations are similar. 
c-------------------------------------------------------------------*/
  for (i = 0; i <= 6; i += 1) {
    timer_clear(i);
  }
  setup();
  compute_indexmap(indexmap,dims[2]);
  compute_initial_conditions(u1,dims[0]);
  fft_init(dims[0][0]);
  fft(1,u1,u0);
/*--------------------------------------------------------------------
c Start over from the beginning. Note that all operations must
c be timed, in contrast to other benchmarks. 
c-------------------------------------------------------------------*/
  for (i = 0; i <= 6; i += 1) {
    timer_clear(i);
  }
  timer_start(0);
  if (0 == 1) 
    timer_start(1);
  compute_indexmap(indexmap,dims[2]);
  compute_initial_conditions(u1,dims[0]);
  fft_init(dims[0][0]);
  if (0 == 1) {
    timer_stop(1);
  }
  if (0 == 1) {
    timer_start(2);
  }
  fft(1,u1,u0);
  if (0 == 1) {
    timer_stop(2);
  }
  for (iter = 1; iter <= niter; iter += 1) {
    if (0 == 1) {
      timer_start(3);
    }
    evolve(u0,u1,iter,indexmap,dims[0]);
    if (0 == 1) {
      timer_stop(3);
    }
    if (0 == 1) {
      timer_start(2);
    }
    fft(- 1,u1,u2);
    if (0 == 1) {
      timer_stop(2);
    }
    if (0 == 1) {
      timer_start(4);
    }
    checksum(iter,u2,dims[0]);
    if (0 == 1) {
      timer_stop(4);
    }
  }
  verify(256,256,128,niter,&verified,&class);
{
//#if defined(_OPENMP)
//    nthreads = omp_get_num_threads();
//#endif /* _OPENMP */    
/* end parallel */
  }
  timer_stop(0);
  total_time = timer_read(0);
  if (total_time != 0.0) {
    mflops = 1.0e-6 * ((double )8388608) * (14.8157 + 7.19641 * log((double )8388608) + (5.23518 + 7.21113 * log((double )8388608)) * niter) / total_time;
  }
   else {
    mflops = 0.0;
  }
  c_print_results("FT",class,256,256,128,niter,nthreads,total_time,mflops,"          floating point",verified,"3.0 structured","14 Jan 2020","(none)","(none)","-lm","(none)","(none)","(none)","randdp");
  if (0 == 1) 
    print_timers();
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void evolve(dcomplex u0[128][256][256],dcomplex u1[128][256][256],int t,int indexmap[128][256][256],int d[3])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c evolve u0 -> u1 (t time steps) in fourier space
c-------------------------------------------------------------------*/
  int i;
  int j;
  int k;
  for (k = 0; k <= d[2] - 1; k += 1) {
    for (j = 0; j <= d[1] - 1; j += 1) {
      for (i = 0; i <= d[0] - 1; i += 1) {
        (u1[k][j][i] . real = u0[k][j][i] . real * ex[t * indexmap[k][j][i]] , u1[k][j][i] . imag = u0[k][j][i] . imag * ex[t * indexmap[k][j][i]]);
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void compute_initial_conditions(dcomplex u0[128][256][256],int d[3])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c Fill in array u0 with initial conditions from 
c random number generator 
c-------------------------------------------------------------------*/
  int k;
  double x0;
  double start;
  double an;
  double dummy;
  static double tmp[131073];
  int i;
  int j;
  int t;
  start = 314159265.0;
/*--------------------------------------------------------------------
c Jump to the starting element for our first plane.
c-------------------------------------------------------------------*/
  ipow46(1220703125.0,(zstart[0] - 1) * 2 * 256 * 256 + (ystart[0] - 1) * 2 * 256,&an);
  dummy = randlc(&start,an);
  ipow46(1220703125.0,2 * 256 * 256,&an);
/*--------------------------------------------------------------------
c Go through by z planes filling in one square at a time.
c-------------------------------------------------------------------*/
  for (k = 0; k <= dims[0][2] - 1; k += 1) {
    x0 = start;
    vranlc(2 * 256 * dims[0][1],&x0,1220703125.0,tmp);
    t = 1;
    for (j = 0; j <= dims[0][1] - 1; j += 1) {
      for (i = 0; i <= 255; i += 1) {
        u0[k][j][i] . real = tmp[t++];
        u0[k][j][i] . imag = tmp[t++];
      }
    }
    if (k != dims[0][2]) 
      dummy = randlc(&start,an);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void ipow46(double a,int exponent,double *result)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c compute a^exponent mod 2^46
c-------------------------------------------------------------------*/
  double dummy;
  double q;
  double r;
  int n;
  int n2;
/*--------------------------------------------------------------------
c Use
c   a^n = a^(n/2)*a^(n/2) if n even else
c   a^n = a*a^(n-1)       if n odd
c-------------------------------------------------------------------*/
   *result = 1;
  if (exponent == 0) 
    return ;
  q = a;
  r = 1;
  n = exponent;
  while(n > 1){
    n2 = n / 2;
    if (n2 * 2 == n) {
      dummy = randlc(&q,q);
      n = n2;
    }
     else {
      dummy = randlc(&r,q);
      n = n - 1;
    }
  }
  dummy = randlc(&r,q);
   *result = r;
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void setup()
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int ierr;
  int i;
  int j;
  int fstatus;
  printf("\n\n NAS Parallel Benchmarks 3.0 structured OpenMP C version - FT Benchmark\n\n");
  niter = 6;
  printf(" Size                : %3dx%3dx%3d\n",256,256,128);
  printf(" Iterations          :     %7d\n",niter);
/* 1004 format(' Number of processes :     ', i7)
 1005 format(' Processor array     :     ', i3, 'x', i3)
 1006 format(' WARNING: compiled for ', i5, ' processes. ',
     >       ' Will not verify. ')*/
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 2; i += 1) {
    dims[i][0] = 256;
    dims[i][1] = 256;
    dims[i][2] = 128;
  }
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 2; i += 1) {
    xstart[i] = 1;
    xend[i] = 256;
    ystart[i] = 1;
    yend[i] = 256;
    zstart[i] = 1;
    zend[i] = 128;
  }
/*--------------------------------------------------------------------
c Set up info for blocking of ffts and transposes.  This improves
c performance on cache-based systems. Blocking involves
c working on a chunk of the problem at a time, taking chunks
c along the first, second, or third dimension. 
c
c - In cffts1 blocking is on 2nd dimension (with fft on 1st dim)
c - In cffts2/3 blocking is on 1st dimension (with fft on 2nd and 3rd dims)
c Since 1st dim is always in processor, we'll assume it's long enough 
c (default blocking factor is 16 so min size for 1st dim is 16)
c The only case we have to worry about is cffts1 in a 2d decomposition. 
c so the blocking factor should not be larger than the 2nd dimension. 
c-------------------------------------------------------------------*/
  fftblock = 16;
  fftblockpad = 18;
  if (fftblock != 16) 
    fftblockpad = fftblock + 3;
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void compute_indexmap(int indexmap[128][256][256],int d[3])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c compute function from local (i,j,k) to ibar^2+jbar^2+kbar^2 
c for time evolution exponent. 
c-------------------------------------------------------------------*/
  int i;
  int j;
  int k;
  int ii;
  int ii2;
  int jj;
  int ij2;
  int kk;
  double ap;
/*--------------------------------------------------------------------
c basically we want to convert the fortran indices 
c   1 2 3 4 5 6 7 8 
c to 
c   0 1 2 3 -4 -3 -2 -1
c The following magic formula does the trick:
c mod(i-1+n/2, n) - n/2
c-------------------------------------------------------------------*/
  
#pragma omp parallel for private (ii,ii2,jj,ij2,kk,i,j,k)
  for (i = 0; i <= dims[2][0] - 1; i += 1) {
    ii = (i + 1 + xstart[2] - 2 + 256 / 2) % 256 - 256 / 2;
    ii2 = ii * ii;
    
#pragma omp parallel for private (jj,ij2,kk,j,k) firstprivate (ii2)
    for (j = 0; j <= dims[2][1] - 1; j += 1) {
      jj = (j + 1 + ystart[2] - 2 + 256 / 2) % 256 - 256 / 2;
      ij2 = jj * jj + ii2;
      
#pragma omp parallel for private (kk,k) firstprivate (ij2)
      for (k = 0; k <= dims[2][2] - 1; k += 1) {
        kk = (k + 1 + zstart[2] - 2 + 128 / 2) % 128 - 128 / 2;
        indexmap[k][j][i] = kk * kk + ij2;
      }
    }
  }
/*--------------------------------------------------------------------
c compute array of exponentials for time evolution. 
c-------------------------------------------------------------------*/
  ap = - 4.0 * 1.0e-6 * 3.141592653589793238 * 3.141592653589793238;
  ex[0] = 1.0;
  ex[1] = exp(ap);
  for (i = 2; i <= 221184; i += 1) {
    ex[i] = ex[i - 1] * ex[1];
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void print_timers()
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int i;
  char *tstrings[] = {"          total ", "          setup ", "            fft ", "         evolve ", "       checksum ", "         fftlow ", "        fftcopy "};
  for (i = 0; i <= 6; i += 1) {
    if (timer_read(i) != 0.0) {
      printf("timer %2d(%16s( :%10.6f\n",i,tstrings[i],(timer_read(i)));
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void fft(int dir,dcomplex x1[128][256][256],dcomplex x2[128][256][256])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  dcomplex y0[256][18];
  dcomplex y1[256][18];
/*--------------------------------------------------------------------
c note: args x1, x2 must be different arrays
c note: args for cfftsx are (direction, layout, xin, xout, scratch)
c       xin/xout may be the same and it can be somewhat faster
c       if they are
c-------------------------------------------------------------------*/
  if (dir == 1) {
/* x1 -> x1 */
    cffts1(1,dims[0],x1,x1,y0,y1);
/* x1 -> x1 */
    cffts2(1,dims[1],x1,x1,y0,y1);
/* x1 -> x2 */
    cffts3(1,dims[2],x1,x2,y0,y1);
  }
   else {
/* x1 -> x1 */
    cffts3(- 1,dims[2],x1,x1,y0,y1);
/* x1 -> x1 */
    cffts2(- 1,dims[1],x1,x1,y0,y1);
/* x1 -> x2 */
    cffts1(- 1,dims[0],x1,x2,y0,y1);
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void cffts1(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int logd[3];
  int i;
  int j;
  int k;
  int jj;
  for (i = 0; i <= 2; i += 1) {
    logd[i] = ilog2(d[i]);
  }
{
    dcomplex y0[256][18];
    dcomplex y1[256][18];
    for (k = 0; k <= d[2] - 1; k += 1) {
      for (jj = 0; jj <= d[1] - fftblock; jj += fftblock) {
/*          if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,j)
        for (j = 0; j <= fftblock - 1; j += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= d[0] - 1; i += 1) {
            y0[i][j] . real = x[k][j + jj][i] . real;
            y0[i][j] . imag = x[k][j + jj][i] . imag;
          }
        }
/*          if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
/*          if (TIMERS_ENABLED == TRUE) timer_start(T_FFTLOW); */
        cfftz(is,logd[0],d[0],y0,y1);
/*          if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTLOW); */
/*          if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,j)
        for (j = 0; j <= fftblock - 1; j += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= d[0] - 1; i += 1) {
            xout[k][j + jj][i] . real = y0[i][j] . real;
            xout[k][j + jj][i] . imag = y0[i][j] . imag;
          }
        }
/*          if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void cffts2(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int logd[3];
  int i;
  int j;
  int k;
  int ii;
  for (i = 0; i <= 2; i += 1) {
    logd[i] = ilog2(d[i]);
  }
{
    dcomplex y0[256][18];
    dcomplex y1[256][18];
    for (k = 0; k <= d[2] - 1; k += 1) {
      for (ii = 0; ii <= d[0] - fftblock; ii += fftblock) {
/*	    if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,j)
        for (j = 0; j <= d[1] - 1; j += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= fftblock - 1; i += 1) {
            y0[j][i] . real = x[k][j][i + ii] . real;
            y0[j][i] . imag = x[k][j][i + ii] . imag;
          }
        }
/*	    if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
/*	    if (TIMERS_ENABLED == TRUE) timer_start(T_FFTLOW); */
        cfftz(is,logd[1],d[1],y0,y1);
/*          if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTLOW); */
/*          if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,j)
        for (j = 0; j <= d[1] - 1; j += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= fftblock - 1; i += 1) {
            xout[k][j][i + ii] . real = y0[j][i] . real;
            xout[k][j][i + ii] . imag = y0[j][i] . imag;
          }
        }
/*           if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void cffts3(int is,int d[3],dcomplex x[128][256][256],dcomplex xout[128][256][256],dcomplex y0[256][18],dcomplex y1[256][18])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int logd[3];
  int i;
  int j;
  int k;
  int ii;
  for (i = 0; i <= 2; i += 1) {
    logd[i] = ilog2(d[i]);
  }
{
    dcomplex y0[256][18];
    dcomplex y1[256][18];
    for (j = 0; j <= d[1] - 1; j += 1) {
      for (ii = 0; ii <= d[0] - fftblock; ii += fftblock) {
/*	    if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,k)
        for (k = 0; k <= d[2] - 1; k += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= fftblock - 1; i += 1) {
            y0[k][i] . real = x[k][j][i + ii] . real;
            y0[k][i] . imag = x[k][j][i + ii] . imag;
          }
        }
/*           if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
/*           if (TIMERS_ENABLED == TRUE) timer_start(T_FFTLOW); */
        cfftz(is,logd[2],d[2],y0,y1);
/*           if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTLOW); */
/*           if (TIMERS_ENABLED == TRUE) timer_start(T_FFTCOPY); */
        
#pragma omp parallel for private (i,k)
        for (k = 0; k <= d[2] - 1; k += 1) {
          
#pragma omp parallel for private (i)
          for (i = 0; i <= fftblock - 1; i += 1) {
            xout[k][j][i + ii] . real = y0[k][i] . real;
            xout[k][j][i + ii] . imag = y0[k][i] . imag;
          }
        }
/*           if (TIMERS_ENABLED == TRUE) timer_stop(T_FFTCOPY); */
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void fft_init(int n)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c compute the roots-of-unity array that will be used for subsequent FFTs. 
c-------------------------------------------------------------------*/
  int m;
  int nu;
  int ku;
  int i;
  int j;
  int ln;
  double t;
  double ti;
/*--------------------------------------------------------------------
c   Initialize the U array with sines and cosines in a manner that permits
c   stride one access at each FFT iteration.
c-------------------------------------------------------------------*/
  nu = n;
  m = ilog2(n);
  u[0] . real = ((double )m);
  u[0] . imag = 0.0;
  ku = 1;
  ln = 1;
  for (j = 1; j <= m; j += 1) {
    t = 3.141592653589793238 / ln;
    for (i = 0; i <= ln - 1; i += 1) {
      ti = i * t;
      u[i + ku] . real = cos(ti);
      u[i + ku] . imag = sin(ti);
    }
    ku = ku + ln;
    ln = 2 * ln;
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void cfftz(int is,int m,int n,dcomplex x[256][18],dcomplex y[256][18])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c   Computes NY N-point complex-to-complex FFTs of X using an algorithm due
c   to Swarztrauber.  X is both the input and the output array, while Y is a 
c   scratch array.  It is assumed that N = 2^M.  Before calling CFFTZ to 
c   perform FFTs, the array U must be initialized by calling CFFTZ with IS 
c   set to 0 and M set to MX, where MX is the maximum value of M for any 
c   subsequent call.
c-------------------------------------------------------------------*/
  int i;
  int j;
  int l;
  int mx;
/*--------------------------------------------------------------------
c   Check if input parameters are invalid.
c-------------------------------------------------------------------*/
  mx = ((int )u[0] . real);
  if (is != 1 && is != - 1 || m < 1 || m > mx) {
    printf("CFFTZ: Either U has not been initialized, or else\none of the input parameters is invalid%5d%5d%5d\n",is,m,mx);
    exit(1);
  }
/*--------------------------------------------------------------------
c   Perform one variant of the Stockham FFT.
c-------------------------------------------------------------------*/
  for (l = 1; l <= m; l += 2) {
    fftz2(is,l,m,n,fftblock,fftblockpad,u,x,y);
    if (l == m) 
      break; 
    fftz2(is,l + 1,m,n,fftblock,fftblockpad,u,y,x);
  }
/*--------------------------------------------------------------------
c   Copy Y to X.
c-------------------------------------------------------------------*/
  if (m % 2 == 1) {
    
#pragma omp parallel for private (i,j) firstprivate (fftblock,n)
    for (j = 0; j <= n - 1; j += 1) {
      
#pragma omp parallel for private (i)
      for (i = 0; i <= fftblock - 1; i += 1) {
        x[j][i] . real = y[j][i] . real;
        x[j][i] . imag = y[j][i] . imag;
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void fftz2(int is,int l,int m,int n,int ny,int ny1,dcomplex u[256],dcomplex x[256][18],dcomplex y[256][18])
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c   Performs the L-th iteration of the second variant of the Stockham FFT.
c-------------------------------------------------------------------*/
  int k;
  int n1;
  int li;
  int lj;
  int lk;
  int ku;
  int i;
  int j;
  int i11;
  int i12;
  int i21;
  int i22;
  dcomplex u1;
  dcomplex x11;
  dcomplex x21;
/*--------------------------------------------------------------------
c   Set initial parameters.
c-------------------------------------------------------------------*/
  n1 = n / 2;
  if (l - 1 == 0) {
    lk = 1;
  }
   else {
    lk = 2 << l - 1 - 1;
  }
  if (m - l == 0) {
    li = 1;
  }
   else {
    li = 2 << m - l - 1;
  }
  lj = 2 * lk;
  ku = li;
  for (i = 0; i <= li - 1; i += 1) {
    i11 = i * lk;
    i12 = i11 + n1;
    i21 = i * lj;
    i22 = i21 + lk;
    if (is >= 1) {
      u1 . real = u[ku + i] . real;
      u1 . imag = u[ku + i] . imag;
    }
     else {
      u1 . real = u[ku + i] . real;
      u1 . imag = -u[ku + i] . imag;
    }
/*--------------------------------------------------------------------
c   This loop is vectorizable.
c-------------------------------------------------------------------*/
    for (k = 0; k <= lk - 1; k += 1) {
      
#pragma omp parallel for private (j) firstprivate (i11,i12,i21,i22)
      for (j = 0; j <= ny - 1; j += 1) {
        double x11real;
        double x11imag;
        double x21real;
        double x21imag;
        x11real = x[i11 + k][j] . real;
        x11imag = x[i11 + k][j] . imag;
        x21real = x[i12 + k][j] . real;
        x21imag = x[i12 + k][j] . imag;
        y[i21 + k][j] . real = x11real + x21real;
        y[i21 + k][j] . imag = x11imag + x21imag;
        y[i22 + k][j] . real = u1 . real * (x11real - x21real) - u1 . imag * (x11imag - x21imag);
        y[i22 + k][j] . imag = u1 . real * (x11imag - x21imag) + u1 . imag * (x11real - x21real);
      }
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static int ilog2(int n)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int nn;
  int lg;
  if (n == 1) {
    return 0;
  }
  lg = 1;
  nn = 2;
  while(nn < n){
    nn = nn << 1;
    lg++;
  }
  return lg;
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void checksum(int i,dcomplex u1[128][256][256],int d[3])
{
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
    int j;
    int q;
    int r;
    int s;
    int ierr;
    dcomplex chk;
    dcomplex allchk;
    chk . real = 0.0;
    chk . imag = 0.0;
    for (j = 1; j <= 1024; j += 1) {
      q = j % 256 + 1;
      if (q >= xstart[0] && q <= xend[0]) {
        r = 3 * j % 256 + 1;
        if (r >= ystart[0] && r <= yend[0]) {
          s = 5 * j % 128 + 1;
          if (s >= zstart[0] && s <= zend[0]) {
            (chk . real = chk . real + u1[s - zstart[0]][r - ystart[0]][q - xstart[0]] . real , chk . imag = chk . imag + u1[s - zstart[0]][r - ystart[0]][q - xstart[0]] . imag);
          }
        }
      }
    }
{
      sums[i] . real += chk . real;
      sums[i] . imag += chk . imag;
    }
{
/* complex % real */
      sums[i] . real = sums[i] . real / ((double )8388608);
      sums[i] . imag = sums[i] . imag / ((double )8388608);
      printf("T = %5d     Checksum = %22.12e %22.12e\n",i,sums[i] . real,sums[i] . imag);
    }
  }
}
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/

static void verify(int d1,int d2,int d3,int nt,boolean *verified,char *class)
{
/*--------------------------------------------------------------------
c-------------------------------------------------------------------*/
  int ierr;
  int size;
  int i;
  double err;
  double epsilon;
/*--------------------------------------------------------------------
c   Sample size reference checksums
c-------------------------------------------------------------------*/
/*--------------------------------------------------------------------
c   Class S size reference checksums
c-------------------------------------------------------------------*/
  double vdata_real_s[7] = {(0.0), (5.546087004964e+02), (5.546385409189e+02), (5.546148406171e+02), (5.545423607415e+02), (5.544255039624e+02), (5.542683411902e+02)};
  double vdata_imag_s[7] = {(0.0), (4.845363331978e+02), (4.865304269511e+02), (4.883910722336e+02), (4.901273169046e+02), (4.917475857993e+02), (4.932597244941e+02)};
/*--------------------------------------------------------------------
c   Class W size reference checksums
c-------------------------------------------------------------------*/
  double vdata_real_w[7] = {(0.0), (5.673612178944e+02), (5.631436885271e+02), (5.594024089970e+02), (5.560698047020e+02), (5.530898991250e+02), (5.504159734538e+02)};
  double vdata_imag_w[7] = {(0.0), (5.293246849175e+02), (5.282149986629e+02), (5.270996558037e+02), (5.260027904925e+02), (5.249400845633e+02), (5.239212247086e+02)};
/*--------------------------------------------------------------------
c   Class A size reference checksums
c-------------------------------------------------------------------*/
  double vdata_real_a[7] = {(0.0), (5.046735008193e+02), (5.059412319734e+02), (5.069376896287e+02), (5.077892868474e+02), (5.085233095391e+02), (5.091487099959e+02)};
  double vdata_imag_a[7] = {(0.0), (5.114047905510e+02), (5.098809666433e+02), (5.098144042213e+02), (5.101336130759e+02), (5.104914655194e+02), (5.107917842803e+02)};
/*--------------------------------------------------------------------
c   Class B size reference checksums
c-------------------------------------------------------------------*/
  double vdata_real_b[21] = {(0.0), (5.177643571579e+02), (5.154521291263e+02), (5.146409228649e+02), (5.142378756213e+02), (5.139626667737e+02), (5.137423460082e+02), (5.135547056878e+02), (5.133910925466e+02), (5.132470705390e+02), (5.131197729984e+02), (5.130070319283e+02), (5.129070537032e+02), (5.128182883502e+02), (5.127393733383e+02), (5.126691062020e+02), (5.126064276004e+02), (5.125504076570e+02), (5.125002331720e+02), (5.124551951846e+02), (5.124146770029e+02)};
  double vdata_imag_b[21] = {(0.0), (5.077803458597e+02), (5.088249431599e+02), (5.096208912659e+02), (5.101023387619e+02), (5.103976610617e+02), (5.105948019802e+02), (5.107404165783e+02), (5.108576573661e+02), (5.109577278523e+02), (5.110460304483e+02), (5.111252433800e+02), (5.111968077718e+02), (5.112616233064e+02), (5.113203605551e+02), (5.113735928093e+02), (5.114218460548e+02), (5.114656139760e+02), (5.115053595966e+02), (5.115415130407e+02), (5.115744692211e+02)};
/*--------------------------------------------------------------------
c   Class C size reference checksums
c-------------------------------------------------------------------*/
  double vdata_real_c[21] = {(0.0), (5.195078707457e+02), (5.155422171134e+02), (5.144678022222e+02), (5.140150594328e+02), (5.137550426810e+02), (5.135811056728e+02), (5.134569343165e+02), (5.133651975661e+02), (5.132955192805e+02), (5.132410471738e+02), (5.131971141679e+02), (5.131605205716e+02), (5.131290734194e+02), (5.131012720314e+02), (5.130760908195e+02), (5.130528295923e+02), (5.130310107773e+02), (5.130103090133e+02), (5.129905029333e+02), (5.129714421109e+02)};
  double vdata_imag_c[21] = {(0.0), (5.149019699238e+02), (5.127578201997e+02), (5.122251847514e+02), (5.121090289018e+02), (5.121143685824e+02), (5.121496764568e+02), (5.121870921893e+02), (5.122193250322e+02), (5.122454735794e+02), (5.122663649603e+02), (5.122830879827e+02), (5.122965869718e+02), (5.123075927445e+02), (5.123166486553e+02), (5.123241541685e+02), (5.123304037599e+02), (5.123356167976e+02), (5.123399592211e+02), (5.123435588985e+02), (5.123465164008e+02)};
  epsilon = 1.0e-12;
   *verified = 1;
   *class = 'U';
  if (d1 == 64 && d2 == 64 && d3 == 64 && nt == 6) {
     *class = 'S';
    for (i = 1; i <= nt; i += 1) {
      err = (sums[i] . real - vdata_real_s[i]) / vdata_real_s[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
      err = (sums[i] . imag - vdata_imag_s[i]) / vdata_imag_s[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
    }
  }
   else if (d1 == 128 && d2 == 128 && d3 == 32 && nt == 6) {
     *class = 'W';
    for (i = 1; i <= nt; i += 1) {
      err = (sums[i] . real - vdata_real_w[i]) / vdata_real_w[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
      err = (sums[i] . imag - vdata_imag_w[i]) / vdata_imag_w[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
    }
  }
   else if (d1 == 256 && d2 == 256 && d3 == 128 && nt == 6) {
     *class = 'A';
    for (i = 1; i <= nt; i += 1) {
      err = (sums[i] . real - vdata_real_a[i]) / vdata_real_a[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
      err = (sums[i] . imag - vdata_imag_a[i]) / vdata_imag_a[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
    }
  }
   else if (d1 == 512 && d2 == 256 && d3 == 256 && nt == 20) {
     *class = 'B';
    for (i = 1; i <= nt; i += 1) {
      err = (sums[i] . real - vdata_real_b[i]) / vdata_real_b[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
      err = (sums[i] . imag - vdata_imag_b[i]) / vdata_imag_b[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
    }
  }
   else if (d1 == 512 && d2 == 512 && d3 == 512 && nt == 20) {
     *class = 'C';
    for (i = 1; i <= nt; i += 1) {
      err = (sums[i] . real - vdata_real_c[i]) / vdata_real_c[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
      err = (sums[i] . imag - vdata_imag_c[i]) / vdata_imag_c[i];
      if (fabs(err) > epsilon) {
         *verified = 0;
        break; 
      }
    }
  }
  if (( *class) != 'U') {
    printf("Result verification successful\n");
  }
   else {
    printf("Result verification failed\n");
  }
  printf("class = %1c\n",( *class));
}
