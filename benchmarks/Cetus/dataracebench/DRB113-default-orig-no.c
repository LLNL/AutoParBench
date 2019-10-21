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

Copyright (c) 2017, Lawrence Livermore National Security, LLC.
Produced at the Lawrence Livermore National Laboratory
Written by Chunhua Liao, Pei-Hung Lin, Joshua Asplund,
Markus Schordan, and Ian Karlin
(email: liao6@llnl.gov, lin32@llnl.gov, asplund1@llnl.gov,
schordan1@llnl.gov, karlin1@llnl.gov)
LLNL-CODE-732144
All rights reserved.

This file is part of DataRaceBench. For details, see
https:github.comLLNL/dataracebench. Please also see the LICENSE file
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
/*

Two-dimensional array computation:
default(none) to enforce explictly list all variables in data-sharing attribute clauses
default(shared) to cover another option.

*/
int a[100][100];
int b[100][100];
int main()
{
	int i, j;
	int _ret_val_0;
	#pragma cetus private(i, j) 
	#pragma loop name main#0 
	#pragma cetus parallel 
	#pragma omp parallel for private(i, j)
	for (i=0; i<100; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name main#0#0 
		#pragma cetus parallel 
		#pragma omp parallel for private(j)
		for (j=0; j<100; j ++ )
		{
			a[i][j]=i;
			b[i][j]=i;
		}
	}
	#pragma cetus private(i, j) 
	#pragma loop name main#1 
	#pragma cetus parallel 
	#pragma omp parallel for private(i, j)
	for (i=0; i<100; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name main#1#0 
		#pragma cetus parallel 
		#pragma omp parallel for private(j)
		for (j=0; j<100; j ++ )
		{
			a[i][j]=(a[i][j]+1);
		}
	}
	#pragma cetus private(i, j) 
	#pragma loop name main#2 
	#pragma cetus parallel 
	#pragma omp parallel for private(i, j)
	for (i=0; i<100; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name main#2#0 
		#pragma cetus parallel 
		#pragma omp parallel for private(j)
		for (j=0; j<100; j ++ )
		{
			b[i][j]=(b[i][j]+1);
		}
	}
	#pragma cetus private(i, j) 
	#pragma loop name main#3 
	for (i=0; i<100; i ++ )
	{
		#pragma cetus private(j) 
		#pragma loop name main#3#0 
		for (j=0; j<100; j ++ )
		{
			printf("%d %d\n", a[i][j], b[i][j]);
		}
	}
	_ret_val_0=0;
	return _ret_val_0;
}
