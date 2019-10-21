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
#include "wtime.h"
#include <stdlib.h>
/*  Prototype  */
void wtime_(double * );
/*  */
/*          E  L  A  P  S  E  D  _  T  I  M  E */
/*  */
double elapsed_time(void )
{
	double t;
	wtime_( & t);
	return t;
}

double start[64], elapsed[64];
/*  */
/*             T  I  M  E  R  _  C  L  E  A  R */
/*  */
void timer_clear(int n)
{
	elapsed[n]=0.0;
	return ;
}

/*  */
/*             T  I  M  E  R  _  S  T  A  R  T */
/*  */
void timer_start(int n)
{
	start[n]=elapsed_time();
	return ;
}

/*  */
/*             T  I  M  E  R  _  S  T  O  P */
/*  */
void timer_stop(int n)
{
	double t, now;
	now=elapsed_time();
	t=(now-start[n]);
	elapsed[n]+=t;
	return ;
}

/*  */
/*             T  I  M  E  R  _  R  E  A  D */
/*  */
double timer_read(int n)
{
	double _ret_val_0;
	_ret_val_0=elapsed[n];
	return _ret_val_0;
}
