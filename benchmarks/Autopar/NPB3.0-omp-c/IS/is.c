/*--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 2.3 OpenMP C versions - IS
  This benchmark is an OpenMP C version of the NPB IS code.
  
  The OpenMP C versions are developed by RWCP and derived from the serial
  Fortran versions in "NPB 2.3-serial" developed by NAS.
  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.
  
  Send comments on the OpenMP C versions to pdp-openmp@rwcp.or.jp
  Information on OpenMP activities at RWCP is available at:
           http://pdplab.trc.rwcp.or.jp/pdperf/Omni/
  
  Information on NAS Parallel Benchmarks 2.3 is available at:
  
           http://www.nas.nasa.gov/NAS/NPB/
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
  Author: M. Yarrow
  OpenMP C version: S. Satoh
  
--------------------------------------------------------------------*/
#include "npbparams.h"
#include <stdlib.h>
#include <stdio.h>
//#if defined(_OPENMP)
//#include <omp.h>
//#endif /* _OPENMP */
/*****************************************************************/
/* For serial IS, buckets are not really req'd to solve NPB1 IS  */
/* spec, but their use on some machines improves performance, on */
/* other machines the use of buckets compromises performance,    */
/* probably because it is extra computation which is not req'd.  */
/* (Note: Mechanism not understood, probably cache related)      */
/* Example:  SP2-66MhzWN:  50% speedup with buckets              */
/* Example:  SGI Indy5000: 50% slowdown with buckets             */
/* Example:  SGI O2000:   400% slowdown with buckets (Wow!)      */
/*****************************************************************/
/* #define USE_BUCKETS  */
/* buckets are not used in the OpenMP C version */
/******************/
/* default values */
/******************/
#ifndef CLASS
#define CLASS 'S'
#endif
/*************/
/*  CLASS S  */
/*************/
#if CLASS == 'S'
#define  TOTAL_KEYS_LOG_2    16
#define  MAX_KEY_LOG_2       11
#define  NUM_BUCKETS_LOG_2   9
#endif
/*************/
/*  CLASS W  */
/*************/
#if CLASS == 'W'
#define  TOTAL_KEYS_LOG_2    20
#define  MAX_KEY_LOG_2       16
#define  NUM_BUCKETS_LOG_2   10
#endif
/*************/
/*  CLASS A  */
/*************/
#if CLASS == 'A'
#define  TOTAL_KEYS_LOG_2    23
#define  MAX_KEY_LOG_2       19
#define  NUM_BUCKETS_LOG_2   10
#endif
/*************/
/*  CLASS B  */
/*************/
#if CLASS == 'B'
#define  TOTAL_KEYS_LOG_2    25
#define  MAX_KEY_LOG_2       21
#define  NUM_BUCKETS_LOG_2   10
#endif
/*************/
/*  CLASS C  */
/*************/
#if CLASS == 'C'
#define  TOTAL_KEYS_LOG_2    27
#define  MAX_KEY_LOG_2       23
#define  NUM_BUCKETS_LOG_2   10
#endif
#define  TOTAL_KEYS          (1 << TOTAL_KEYS_LOG_2)
#define  MAX_KEY             (1 << MAX_KEY_LOG_2)
#define  NUM_BUCKETS         (1 << NUM_BUCKETS_LOG_2)
#define  NUM_KEYS            TOTAL_KEYS
#define  SIZE_OF_BUFFERS     NUM_KEYS  
#define  MAX_ITERATIONS      10
#define  TEST_ARRAY_SIZE     5
/*************************************/
/* Typedef: if necessary, change the */
/* size of int here by changing the  */
/* int type to, say, long            */
/*************************************/
#include <omp.h> 
typedef int INT_TYPE;
/********************/
/* Some global info */
/********************/
/* used by full_verify to get */
INT_TYPE *key_buff_ptr_global;
/* copies of rank info        */
int passed_verification;
/************************************/
/* These are the three main arrays. */
/* See SIZE_OF_BUFFERS def above    */
/************************************/
INT_TYPE key_array[8388608];
INT_TYPE key_buff1[8388608];
INT_TYPE key_buff2[8388608];
INT_TYPE partial_verify_vals[5];
#ifdef USE_BUCKETS
#endif
/**********************/
/* Partial verif info */
/**********************/
INT_TYPE test_index_array[5];
INT_TYPE test_rank_array[5];
INT_TYPE S_test_index_array[5] = {(48427), (17148), (23627), (62548), (4431)};
INT_TYPE S_test_rank_array[5] = {(0), (18), (346), (64917), (65463)};
INT_TYPE W_test_index_array[5] = {(357773), (934767), (875723), (898999), (404505)};
INT_TYPE W_test_rank_array[5] = {(1249), (11698), (1039987), (1043896), (1048018)};
INT_TYPE A_test_index_array[5] = {(2112377), (662041), (5336171), (3642833), (4250760)};
INT_TYPE A_test_rank_array[5] = {(104), (17523), (123928), (8288932), (8388264)};
INT_TYPE B_test_index_array[5] = {(41869), (812306), (5102857), (18232239), (26860214)};
INT_TYPE B_test_rank_array[5] = {(33422937), (10244), (59149), (33135281), (99)};
INT_TYPE C_test_index_array[5] = {(44172927), (72999161), (74326391), (129606274), (21736814)};
INT_TYPE C_test_rank_array[5] = {(61147), (882988), (266290), (133997595), (133525895)};
/***********************/
/* function prototypes */
/***********************/
double randlc(double *X,double *A);
void full_verify();
/*
 *    FUNCTION RANDLC (X, A)
 *
 *  This routine returns a uniform pseudorandom double precision number in the
 *  range (0, 1) by using the linear congruential generator
 *
 *  x_{k+1} = a x_k  (mod 2^46)
 *
 *  where 0 < x_k < 2^46 and 0 < a < 2^46.  This scheme generates 2^44 numbers
 *  before repeating.  The argument A is the same as 'a' in the above formula,
 *  and X is the same as x_0.  A and X must be odd double precision integers
 *  in the range (1, 2^46).  The returned value RANDLC is normalized to be
 *  between 0 and 1, i.e. RANDLC = 2^(-46) * x_1.  X is updated to contain
 *  the new seed x_1, so that subsequent calls to RANDLC using the same
 *  arguments will generate a continuous sequence.
 *
 *  This routine should produce the same results on any computer with at least
 *  48 mantissa bits in double precision floating point data.  On Cray systems,
 *  double precision should be disabled.
 *
 *  David H. Bailey     October 26, 1990
 *
 *     IMPLICIT DOUBLE PRECISION (A-H, O-Z)
 *     SAVE KS, R23, R46, T23, T46
 *     DATA KS/0/
 *
 *  If this is the first call to RANDLC, compute R23 = 2 ^ -23, R46 = 2 ^ -46,
 *  T23 = 2 ^ 23, and T46 = 2 ^ 46.  These are computed in loops, rather than
 *  by merely using the ** operator, in order to insure that the results are
 *  exact on all systems.  This code assumes that 0.5D0 is represented exactly.
 */
/*****************************************************************/
/*************           R  A  N  D  L  C             ************/
/*************                                        ************/
/*************    portable random number generator    ************/
/*****************************************************************/

double randlc(X,A)
double *X;
double *A;
{
  static int KS = 0;
  static double R23;
  static double R46;
  static double T23;
  static double T46;
  double T1;
  double T2;
  double T3;
  double T4;
  double A1;
  double A2;
  double X1;
  double X2;
  double Z;
  int i;
  int j;
  if (KS == 0) {
    R23 = 1.0;
    R46 = 1.0;
    T23 = 1.0;
    T46 = 1.0;
    
#pragma omp parallel for private (i) reduction (*:R23,T23)
    for (i = 1; i <= 23; i += 1) {
      R23 = 0.50 * R23;
      T23 = 2.0 * T23;
    }
    
#pragma omp parallel for private (i) reduction (*:R46,T46)
    for (i = 1; i <= 46; i += 1) {
      R46 = 0.50 * R46;
      T46 = 2.0 * T46;
    }
    KS = 1;
  }
/*  Break A into two parts such that A = 2^23 * A1 + A2 and set X = N.  */
  T1 = R23 *  *A;
  j = T1;
  A1 = j;
  A2 =  *A - T23 * A1;
/*  Break X into two parts such that X = 2^23 * X1 + X2, compute
    Z = A1 * X2 + A2 * X1  (mod 2^23), and then
    X = 2^23 * Z + A2 * X2  (mod 2^46).                            */
  T1 = R23 *  *X;
  j = T1;
  X1 = j;
  X2 =  *X - T23 * X1;
  T1 = A1 * X2 + A2 * X1;
  j = (R23 * T1);
  T2 = j;
  Z = T1 - T23 * T2;
  T3 = T23 * Z + A2 * X2;
  j = (R46 * T3);
  T4 = j;
   *X = T3 - T46 * T4;
  return R46 *  *X;
}
/*****************************************************************/
/*************      C  R  E  A  T  E  _  S  E  Q      ************/
/*****************************************************************/

void create_seq(double seed,double a)
{
  double x;
  int i;
  int j;
  int k;
  k = (1 << 19) / 4;
  for (i = 0; i <= 8388607; i += 1) {
    x = randlc(&seed,&a);
    x += randlc(&seed,&a);
    x += randlc(&seed,&a);
    x += randlc(&seed,&a);
    key_array[i] = (k * x);
  }
}
/*****************************************************************/
/*************    F  U  L  L  _  V  E  R  I  F  Y     ************/
/*****************************************************************/

void full_verify()
{
  INT_TYPE i;
  INT_TYPE j;
  INT_TYPE k;
  INT_TYPE m;
  INT_TYPE unique_keys;
/*  Now, finally, sort the keys:  */
  for (i = 0; i <= 8388607; i += 1) {
    key_array[--key_buff_ptr_global[key_buff2[i]]] = key_buff2[i];
  }
/*  Confirm keys correctly sorted: count incorrectly sorted keys, if any */
  j = 0;
  
#pragma omp parallel for private (i) reduction (+:j)
  for (i = 1; i <= 8388607; i += 1) {
    if (key_array[i - 1] > key_array[i]) 
      j++;
  }
  if (j != 0) {
    printf("Full_verify: number of keys out of sort: %d\n",j);
  }
   else 
    passed_verification++;
}
/*****************************************************************/
/*************             R  A  N  K             ****************/
/*****************************************************************/

void rank(int iteration)
{
  INT_TYPE i;
  INT_TYPE j;
  INT_TYPE k;
  INT_TYPE l;
  INT_TYPE m;
  INT_TYPE shift = 19 - 10;
  INT_TYPE key;
  INT_TYPE min_key_val;
  INT_TYPE max_key_val;
  INT_TYPE prv_buff1[524288];
{
    key_array[iteration] = iteration;
    key_array[iteration + 10] = (1 << 19) - iteration;
/*  Determine where the partial verify test keys are, load into  */
/*  top of array bucket_size                                     */
    
#pragma omp parallel for private (i)
    for (i = 0; i <= 4; i += 1) {
      partial_verify_vals[i] = key_array[test_index_array[i]];
    }
/*  Clear the work array */
    
#pragma omp parallel for private (i)
    for (i = 0; i <= 524287; i += 1) {
      key_buff1[i] = 0;
    }
  }
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 524287; i += 1) {
    prv_buff1[i] = 0;
  }
/*  Copy keys into work array; keys in key_array will be reused each iter. */
  for (i = 0; i <= 8388607; i += 1) {
    key_buff2[i] = key_array[i];
/*  Ranking of all keys occurs in this section:                 */
/*  In this section, the keys themselves are used as their 
    own indexes to determine how many of each there are: their
    individual population                                       */
/* Now they have individual key   */
    prv_buff1[key_buff2[i]]++;
  }
/* population                     */
  for (i = 0; i <= 524286; i += 1) {
    prv_buff1[i + 1] += prv_buff1[i];
  }
{
    
#pragma omp parallel for private (i)
    for (i = 0; i <= 524287; i += 1) {
      key_buff1[i] += prv_buff1[i];
    }
  }
/*  To obtain ranks of each key, successively add the individual key
    population, not forgetting to add m, the total of lesser keys,
    to the first key population                                          */
{
/* This is the partial verify test section */
/* Observe that test_rank_array vals are   */
/* shifted differently for different cases */
    for (i = 0; i <= 4; i += 1) {
/* test vals were put here */
      k = partial_verify_vals[i];
      if (0 <= k && k <= (1 << 23) - 1) 
        switch('A'){
          case 'S':
          if (i <= 2) {
            if (key_buff1[k - 1] != test_rank_array[i] + iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
           else {
            if (key_buff1[k - 1] != test_rank_array[i] - iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
          break; 
          case 'W':
          if (i < 2) {
            if (key_buff1[k - 1] != test_rank_array[i] + (iteration - 2)) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
           else {
            if (key_buff1[k - 1] != test_rank_array[i] - iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
          break; 
          case 'A':
          if (i <= 2) {
            if (key_buff1[k - 1] != test_rank_array[i] + (iteration - 1)) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
           else {
            if (key_buff1[k - 1] != test_rank_array[i] - (iteration - 1)) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
          break; 
          case 'B':
          if (i == 1 || i == 2 || i == 4) {
            if (key_buff1[k - 1] != test_rank_array[i] + iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
           else {
            if (key_buff1[k - 1] != test_rank_array[i] - iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
          break; 
          case 'C':
          if (i <= 2) {
            if (key_buff1[k - 1] != test_rank_array[i] + iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
           else {
            if (key_buff1[k - 1] != test_rank_array[i] - iteration) {
              printf("Failed partial verification: iteration %d, test key %d\n",iteration,i);
            }
             else 
              passed_verification++;
          }
          break; 
        }
    }
/*  Make copies of rank info for use by full_verify: these variables
    in rank are local; making them global slows down the code, probably
    since they cannot be made register by compiler                        */
    if (iteration == 10) 
      key_buff_ptr_global = key_buff1;
/* end master */
  }
}
/*****************************************************************/
/*************             M  A  I  N             ****************/
/*****************************************************************/

int main(argc,argv)
int argc;
char **argv;
{
  int i;
  int iteration;
  int itemp;
  int nthreads = 1;
  double timecounter;
  double maxtime;
/*  Initialize the verification arrays if a valid class */
  
#pragma omp parallel for private (i)
  for (i = 0; i <= 4; i += 1) {
    switch('A'){
      case 'S':
      test_index_array[i] = S_test_index_array[i];
      test_rank_array[i] = S_test_rank_array[i];
      break; 
      case 'A':
      test_index_array[i] = A_test_index_array[i];
      test_rank_array[i] = A_test_rank_array[i];
      break; 
      case 'W':
      test_index_array[i] = W_test_index_array[i];
      test_rank_array[i] = W_test_rank_array[i];
      break; 
      case 'B':
      test_index_array[i] = B_test_index_array[i];
      test_rank_array[i] = B_test_rank_array[i];
      break; 
      case 'C':
      test_index_array[i] = C_test_index_array[i];
      test_rank_array[i] = C_test_rank_array[i];
      break; 
    }
  }
  ;
/*  Printout initial NPB info */
  printf("\n\n NAS Parallel Benchmarks 2.3 OpenMP C version - IS Benchmark\n\n");
  printf(" Size:  %d  (class %c)\n",1 << 23,'A');
  printf(" Iterations:   %d\n",10);
/*  Initialize timer  */
  timer_clear(0);
/*  Generate random number sequence and subsequent keys on all procs */
/* Random number gen seed */
  create_seq(314159265.00,1220703125.00);
/* Random number gen mult */
/*  Do one interation for free (i.e., untimed) to guarantee initialization of  
    all data and code pages and respective tables */
  rank(1);
/*  Start verification counter */
  passed_verification = 0;
  if ('A' != 'S') 
    printf("\n   iteration\n");
/*  Start timer  */
  timer_start(0);
/*  This is the main iteration */
  for (iteration = 1; iteration <= 10; iteration += 1) {
    if ('A' != 'S') 
      printf("        %d\n",iteration);
    rank(iteration);
//#if defined(_OPENMP)	
//	nthreads = omp_get_num_threads();
//#endif /* _OPENMP */	
  }
/*  End of timing, obtain maximum time of all processors */
  timer_stop(0);
  timecounter = (timer_read(0));
/*  This tests that keys are in sequence: sorting of last ranked key seq
    occurs here, but is an untimed operation                             */
  full_verify();
/*  The final printout  */
  if (passed_verification != 5 * 10 + 1) 
    passed_verification = 0;
  c_print_results("IS",'A',1 << 23,0,0,10,nthreads,timecounter,((double )(10 * (1 << 23))) / timecounter / 1000000.,"keys ranked",passed_verification,"3.0 structured","14 Jan 2020","(none)","(none)","-lm","(none)","(none)","(none)","randlc");
/**************************/
/*  E N D  P R O G R A M  */
}
/**************************/
