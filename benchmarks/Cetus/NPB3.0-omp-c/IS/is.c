/*
Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it andor
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http:www.gnu.org/licenses/>. 
*/
/*
This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it. 
*/
/*
glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default. 
*/
/*
wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISOIEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters
*/
/*
--------------------------------------------------------------------
  
  NAS Parallel Benchmarks 2.3 OpenMP C versions - IS

  This benchmark is an OpenMP C version of the NPB IS code.
  
  The OpenMP C versions are developed by RWCP and derived from the serial
  Fortran versions in "NPB 2.3-serial" developed by NAS.

  Permission to use, copy, distribute and modify this software for any
  purpose with or without fee is hereby granted.
  This software is provided "as is" without express or implied warranty.
  
  Send comments on the OpenMP C versions to pdp-openmp@rwcp.or.jp

  Information on OpenMP activities at RWCP is available at:

           http:pdplab.trc.rwcp.or.jppdperf/Omni/
  
  Information on NAS Parallel Benchmarks 2.3 is available at:
  
           http:www.nas.nasa.gov/NAS/NPB/

--------------------------------------------------------------------
*/
/*
--------------------------------------------------------------------

  Author: M. Yarrow

  OpenMP C version: S. Satoh
  
--------------------------------------------------------------------
*/
#include "npbparams.h"
#include <stdlib.h>
#include <stdio.h>
/* #if defined(_OPENMP) */
/* #include <omp.h> */
/* #endif _OPENMP */
/*  */
/* For serial IS, buckets are not really req'd to solve NPB1 IS  */
/* spec, but their use on some machines improves performance, on */
/* other machines the use of buckets compromises performance,    */
/* probably because it is extra computation which is not req'd.  */
/* (Note: Mechanism not understood, probably cache related)      */
/* Example:  SP2-66MhzWN:  50% speedup with buckets              */
/* Example:  SGI Indy5000: 50% slowdown with buckets             */
/* Example:  SGI O2000:   400% slowdown with buckets (Wow!)      */
/*  */
/* #define USE_BUCKETS  */
/* buckets are not used in the OpenMP C version */
/*  */
/* default values */
/*  */
/*  */
/*  CLASS S  */
/*  */
/*  */
/*  CLASS W  */
/*  */
/*  */
/*  CLASS A  */
/*  */
/*  */
/*  CLASS B  */
/*  */
/*  */
/*  CLASS C  */
/*  */
/*  */
/* Typedef: if necessary, change the */
/* size of int here by changing the  */
/* int type to, say, long            */
/*  */
typedef int INT_TYPE;
/*  */
/* Some global info */
/*  */
INT_TYPE * key_buff_ptr_global;
/* used by full_verify to get */
/* copies of rank info        */
int passed_verification;
/*  */
/* These are the three main arrays. */
/* See SIZE_OF_BUFFERS def above    */
/*  */
INT_TYPE key_array[(1<<23)], key_buff1[(1<<23)], key_buff2[(1<<23)], partial_verify_vals[5];
/*  */
/* Partial verif info */
/*  */
INT_TYPE test_index_array[5], test_rank_array[5], S_test_index_array[5] = {48427, 17148, 23627, 62548, 4431}, S_test_rank_array[5] = {0, 18, 346, 64917, 65463}, W_test_index_array[5] = {357773, 934767, 875723, 898999, 404505}, W_test_rank_array[5] = {1249, 11698, 1039987, 1043896, 1048018}, A_test_index_array[5] = {2112377, 662041, 5336171, 3642833, 4250760}, A_test_rank_array[5] = {104, 17523, 123928, 8288932, 8388264}, B_test_index_array[5] = {41869, 812306, 5102857, 18232239, 26860214}, B_test_rank_array[5] = {33422937, 10244, 59149, 33135281, 99}, C_test_index_array[5] = {44172927, 72999161, 74326391, 129606274, 21736814}, C_test_rank_array[5] = {61147, 882988, 266290, 133997595, 133525895};
/*  */
/* function prototypes */
/*  */
double randlc(double * X, double * A);
void full_verify(void );
/*

    FUNCTION RANDLC (X, A)
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
/*  */
/*            R  A  N  D  L  C */
/*  */
/*     portable random number generator */
/*  */
double randlc(double * X, double * A)
{
	static int KS = 0;
	static double R23, R46, T23, T46;
	double T1, T2, T3, T4;
	double A1;
	double A2;
	double X1;
	double X2;
	double Z;
	int i, j;
	double _ret_val_0;
	if (KS==0)
	{
		R23=1.0;
		R46=1.0;
		T23=1.0;
		T46=1.0;
		#pragma loop name randlc#0 
		#pragma cetus reduction(*: R23, T23) 
		#pragma cetus parallel 
		#pragma omp parallel for reduction(*: R23, T23)
		for (i=1; i<=23; i ++ )
		{
			R23=(0.5*R23);
			T23=(2.0*T23);
		}
		#pragma loop name randlc#1 
		#pragma cetus reduction(*: R46, T46) 
		#pragma cetus parallel 
		#pragma omp parallel for reduction(*: R46, T46)
		for (i=1; i<=46; i ++ )
		{
			R46=(0.5*R46);
			T46=(2.0*T46);
		}
		KS=1;
	}
	/*  Break A into two parts such that A = 2^23 A1 + A2 and set X = N.  */
	T1=(R23*( * A));
	j=T1;
	A1=j;
	A2=(( * A)-(T23*A1));
	/*
	 Break X into two parts such that X = 2^23 X1 + X2, compute
	    Z = A1 * X2 + A2 * X1  (mod 2^23), and then
	    X = 2^23 * Z + A2 * X2  (mod 2^46).                           
	*/
	T1=(R23*( * X));
	j=T1;
	X1=j;
	X2=(( * X)-(T23*X1));
	T1=((A1*X2)+(A2*X1));
	j=(R23*T1);
	T2=j;
	Z=(T1-(T23*T2));
	T3=((T23*Z)+(A2*X2));
	j=(R46*T3);
	T4=j;
	( * X)=(T3-(T46*T4));
	_ret_val_0=(R46*( * X));
	return _ret_val_0;
}

/*  */
/*       C  R  E  A  T  E  _  S  E  Q */
/*  */
void create_seq(double seed, double a)
{
	double x;
	int i, j, k;
	k=((1<<19)/4);
	#pragma loop name create_seq#0 
	for (i=0; i<(1<<23); i ++ )
	{
		x=randlc( & seed,  & a);
		x+=randlc( & seed,  & a);
		x+=randlc( & seed,  & a);
		x+=randlc( & seed,  & a);
		key_array[i]=(k*x);
	}
	return ;
}

/*  */
/*     F  U  L  L  _  V  E  R  I  F  Y */
/*  */
void full_verify()
{
	INT_TYPE i, j;
	INT_TYPE k;
	INT_TYPE m, unique_keys;
	/*  Now, finally, sort the keys:  */
	#pragma loop name full_verify#0 
	for (i=0; i<(1<<23); i ++ )
	{
		key_array[ -- key_buff_ptr_global[key_buff2[i]]]=key_buff2[i];
	}
	/*  Confirm keys correctly sorted: count incorrectly sorted keys, if any */
	j=0;
	#pragma loop name full_verify#1 
	#pragma cetus reduction(+: j) 
	#pragma cetus parallel 
	#pragma omp parallel for reduction(+: j)
	for (i=1; i<(1<<23); i ++ )
	{
		if (key_array[i-1]>key_array[i])
		{
			j ++ ;
		}
	}
	if (j!=0)
	{
		printf("Full_verify: number of keys out of sort: %d\n", j);
	}
	else
	{
		passed_verification ++ ;
	}
	return ;
}

/*  */
/*              R  A  N  K */
/*  */
void rank(int iteration)
{
	INT_TYPE i, j, k;
	INT_TYPE l, m;
	INT_TYPE shift = 19-10;
	INT_TYPE key;
	INT_TYPE min_key_val, max_key_val;
	INT_TYPE prv_buff1[(1<<19)];
	key_array[iteration]=iteration;
	key_array[iteration+10]=((1<<19)-iteration);
	/*  Determine where the partial verify test keys are, load into  */
	/*  top of array bucket_size                                     */
	#pragma loop name rank#0 
	for (i=0; i<5; i ++ )
	{
		partial_verify_vals[i]=key_array[test_index_array[i]];
	}
	/*  Clear the work array */
	#pragma loop name rank#1 
	#pragma cetus parallel 
	#pragma omp parallel for
	for (i=0; i<(1<<19); i ++ )
	{
		key_buff1[i]=0;
	}
	#pragma loop name rank#2 
	#pragma cetus parallel 
	#pragma omp parallel for
	for (i=0; i<(1<<19); i ++ )
	{
		prv_buff1[i]=0;
	}
	/*  Copy keys into work array; keys in key_array will be reused each iter. */
	#pragma loop name rank#3 
	#pragma cetus reduction(+: prv_buff1[key_buff2[i]]) 
	for (i=0; i<(1<<23); i ++ )
	{
		key_buff2[i]=key_array[i];
		/*  Ranking of all keys occurs in this section:                 */
		/*
		 In this section, the keys themselves are used as their 
		    own indexes to determine how many of each there are: their
		    individual population                                      
		*/
		prv_buff1[key_buff2[i]] ++ ;
		/* Now they have individual key   */
	}
	/* population                     */
	#pragma loop name rank#4 
	for (i=0; i<((1<<19)-1); i ++ )
	{
		prv_buff1[i+1]+=prv_buff1[i];
	}
	#pragma loop name rank#5 
	for (i=0; i<(1<<19); i ++ )
	{
		key_buff1[i]+=prv_buff1[i];
	}
	/*
	 To obtain ranks of each key, successively add the individual key
	    population, not forgetting to add m, the total of lesser keys,
	    to the first key population                                         
	*/
	/* This is the partial verify test section */
	/* Observe that test_rank_array vals are   */
	/* shifted differently for different cases */
	#pragma loop name rank#6 
	#pragma cetus reduction(+: passed_verification) 
	for (i=0; i<5; i ++ )
	{
		k=partial_verify_vals[i];
		/* test vals were put here */
		if ((0<=k)&&(k<=((1<<23)-1)))
		{
			switch ('A')
			{
				case 'S':
				if (i<=2)
				{
					if (key_buff1[k-1]!=(test_rank_array[i]+iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				else
				{
					if (key_buff1[k-1]!=(test_rank_array[i]-iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				break;
				case 'W':
				if (i<2)
				{
					if (key_buff1[k-1]!=(test_rank_array[i]+(iteration-2)))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				else
				{
					if (key_buff1[k-1]!=(test_rank_array[i]-iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				break;
				case 'A':
				if (i<=2)
				{
					if (key_buff1[k-1]!=(test_rank_array[i]+(iteration-1)))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				else
				{
					if (key_buff1[k-1]!=(test_rank_array[i]-(iteration-1)))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				break;
				case 'B':
				if (((i==1)||(i==2))||(i==4))
				{
					if (key_buff1[k-1]!=(test_rank_array[i]+iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				else
				{
					if (key_buff1[k-1]!=(test_rank_array[i]-iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				break;
				case 'C':
				if (i<=2)
				{
					if (key_buff1[k-1]!=(test_rank_array[i]+iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				else
				{
					if (key_buff1[k-1]!=(test_rank_array[i]-iteration))
					{
						printf("Failed partial verification: ""iteration %d, test key %d\n", iteration, i);
					}
					else
					{
						passed_verification ++ ;
					}
				}
				break;
			}
		}
	}
	/*
	 Make copies of rank info for use by full_verify: these variables
	    in rank are local; making them global slows down the code, probably
	    since they cannot be made register by compiler                       
	*/
	if (iteration==10)
	{
		key_buff_ptr_global=key_buff1;
	}
	/* end master */
	return ;
}

/*  */
/*              M  A  I  N */
/*  */
 main(int argc, char * * argv)
{
	int i, iteration, itemp;
	int nthreads = 1;
	double timecounter, maxtime;
	/*  Initialize the verification arrays if a valid class */
	int _ret_val_0;
	#pragma loop name main#0 
	for (i=0; i<5; i ++ )
	{
		switch ('A')
		{
			case 'S':
			test_index_array[i]=S_test_index_array[i];
			test_rank_array[i]=S_test_rank_array[i];
			break;
			case 'A':
			test_index_array[i]=A_test_index_array[i];
			test_rank_array[i]=A_test_rank_array[i];
			break;
			case 'W':
			test_index_array[i]=W_test_index_array[i];
			test_rank_array[i]=W_test_rank_array[i];
			break;
			case 'B':
			test_index_array[i]=B_test_index_array[i];
			test_rank_array[i]=B_test_rank_array[i];
			break;
			case 'C':
			test_index_array[i]=C_test_index_array[i];
			test_rank_array[i]=C_test_rank_array[i];
			break;
		}
	}
	;
	/*  Printout initial NPB info */
	printf("\n\n NAS Parallel Benchmarks 2.3 OpenMP C version"" - IS Benchmark\n\n");
	printf(" Size:  %d  (class %c)\n", 1<<23, 'A');
	printf(" Iterations:   %d\n", 10);
	/*  Initialize timer  */
	timer_clear(0);
	/*  Generate random number sequence and subsequent keys on all procs */
	/* Random number gen seed */
	create_seq(3.14159265E8, 1.220703125E9);
	/* Random number gen mult */
	/*
	 Do one interation for free (i.e., untimed) to guarantee initialization of  
	    all data and code pages and respective tables
	*/
	rank(1);
	/*  Start verification counter */
	passed_verification=0;
	printf("\n   iteration\n");
	/*  Start timer  */
	timer_start(0);
	/*  This is the main iteration */
	#pragma loop name main#1 
	for (iteration=1; iteration<=10; iteration ++ )
	{
		printf("        %d\n", iteration);
		rank(iteration);
		/* #if defined(_OPENMP)	 */
		/* 	nthreads = omp_get_num_threads(); */
		/* #endif _OPENMP	 */
	}
	/*  End of timing, obtain maximum time of all processors */
	timer_stop(0);
	timecounter=timer_read(0);
	/*
	 This tests that keys are in sequence: sorting of last ranked key seq
	    occurs here, but is an untimed operation                            
	*/
	full_verify();
	/*  The final printout  */
	if (passed_verification!=((5*10)+1))
	{
		passed_verification=0;
	}
	c_print_results("IS", 'A', 1<<23, 0, 0, 10, nthreads, timecounter, (((double)(10*(1<<23)))/timecounter)/1000000.0, "keys ranked", passed_verification, "3.0 structured", "28 Nov 2019", "(none)", "(none)", "-lm", "(none)", "(none)", "(none)", "randlc");
	/*  */
	return _ret_val_0;
}
