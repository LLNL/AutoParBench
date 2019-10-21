/**
 * template.c: This file is part of the PolyBench/C 3.2 test suite.
 *
 *
 * Contact: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 * Web address: http://polybench.sourceforge.net
 * License: /LICENSE.OSU.txt
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
/* Include polybench common header. */
#include "../polybench/polybench.h"
/* Include benchmark-specific header. */
/* Default data type is double, default size is N=1024. */
#include "template-for-new-benchmark.h"
/* Array initialization. */
#include <omp.h> 

static void init_array(int n,double C[1024][1024])
{
  int i;
  int j;
  
#pragma omp parallel for private (i,j) firstprivate (n)
  for (i = 0; i <= n - 1; i += 1) {
    
#pragma omp parallel for private (j)
    for (j = 0; j <= n - 1; j += 1) {
      C[i][j] = 42;
    }
  }
}
/* DCE code. Must scan the entire live-out data.
   Can be used also to check the correctness of the output. */

static void print_array(int n,double C[1024][1024])
{
  int i;
  int j;
  for (i = 0; i <= n - 1; i += 1) {
    for (j = 0; j <= n - 1; j += 1) {
      fprintf(stderr,"%0.2lf ",C[i][j]);
      if (i % 20 == 0) 
        fprintf(stderr,"\n");
    }
  }
  fprintf(stderr,"\n");
}
/* Main computational kernel. The whole function will be timed,
   including the call and return. */

static void kernel_template(int n,double C[1024][1024])
{
  int i;
  int j;
  
#pragma omp parallel for private (i,j) firstprivate (n)
  for (i = 0; i <= n - 1; i += 1) {
    
#pragma omp parallel for private (j)
    for (j = 0; j <= n - 1; j += 1) {
      C[i][j] += 42;
    }
  }
}

int main(int argc,char **argv)
{
/* Retrieve problem size. */
  int n = 1024;
/* Variable declaration/allocation. */
  double (*C)[1024][1024];
  C = ((double (*)[1024][1024])(polybench_alloc_data(((1024 + 0) * (1024 + 0)),(sizeof(double )))));
  ;
/* Initialize array(s). */
  init_array(n, *C);
/* Start timer. */
  ;
/* Run kernel. */
  kernel_template(n, *C);
/* Stop and print timer. */
  ;
  ;
/* Prevent dead-code elimination. All live-out data must be printed
     by the function call in argument. */
  if (argc > 42 && !strcmp(argv[0],"")) 
    print_array(n, *C);
/* Be clean. */
  free((void *)C);
  ;
  return 0;
}
