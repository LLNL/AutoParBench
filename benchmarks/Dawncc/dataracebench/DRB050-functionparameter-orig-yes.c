/*
Copyright (c) 2017, Lawrence Livermore National Security, LLC.
Produced at the Lawrence Livermore National Laboratory
Written by Chunhua Liao, Pei-Hung Lin, Joshua Asplund,
Markus Schordan, and Ian Karlin
(email: liao6@llnl.gov, lin32@llnl.gov, asplund1@llnl.gov,
schordan1@llnl.gov, karlin1@llnl.gov)
LLNL-CODE-732144
All rights reserved.

This file is part of DataRaceBench. For details, see
https://github.com/LLNL/dataracebench. Please also see the LICENSE file
for our additional BSD notice.

Redistribution and use in source and binary forms, with
or without modification, are permitted provided that the following
conditions are met:

* Redistributions of source code must retain the above copyright
  notice, this list of conditions and the disclaimer below.

* Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the disclaimer (as noted below)
  in the documentation and/or other materials provided with the
  distribution.

* Neither the name of the LLNS/LLNL nor the names of its contributors
  may be used to endorse or promote products derived from this
  software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL
SECURITY, LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
#include <stdlib.h>
/*
Arrays passed as function parameters
*/
void foo1(double o1[], double c[], int len) {
  int i;

  long long int AI1[6];
  AI1[0] = len + -1;
  AI1[1] = 8 * AI1[0];
  AI1[2] = AI1[1] + 8;
  AI1[3] = AI1[2] / 8;
  AI1[4] = (AI1[3] > 0);
  AI1[5] = (AI1[4] ? AI1[3] : 0);
  char RST_AI1 = 0;
  RST_AI1 |= !(((void*) (c + 0) > (void*) (o1 + AI1[5]))
  || ((void*) (o1 + 0) > (void*) (c + AI1[5])));
  #pragma omp target data map(to: c[0:AI1[5]]) map(tofrom: o1[0:AI1[5]]) if(!RST_AI1)
  {
  #pragma omp target parallel for 
  for (i = 0; i < len; ++i) {
    double volnew_o8 = 0.5 * c[i];
    o1[i] = volnew_o8;
  }
}
}

int main() {
  double o1[101];
  double c[101];
  int i;
  int len = 100;
  char RST_AI1 = 0;
  #pragma omp target data map(tofrom: c[0:101],o1[0:101]) if(!RST_AI1)
  {
  #pragma omp target parallel for 
  for (i = 0; i < len; ++i) {
    c[i] = i + 1.01;
    o1[i] = i + 1.01;
  }
}

  foo1(&o1[1], &o1[0], 100);

  for (i = 0; i < len; ++i) {
    printf("%lf\n", o1[i]);
  }
  return 0;
}

