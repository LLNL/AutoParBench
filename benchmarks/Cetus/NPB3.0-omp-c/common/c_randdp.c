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


*/
/*
c---------------------------------------------------------------------
c---------------------------------------------------------------------
*/
double randlc(double * x, double a)
{
	/*
	c---------------------------------------------------------------------
	c---------------------------------------------------------------------
	*/
	/*
	c---------------------------------------------------------------------
	c
	c   This routine returns a uniform pseudorandom double precision number in the
	c   range (0, 1) by using the linear congruential generator
	c
c   x_{k+1} = a x_k  (mod 2^46)
	c
	c   where 0 < x_k < 2^46 and 0 < a < 2^46.  This scheme generates 2^44 numbers
	c   before repeating.  The argument A is the same as 'a' in the above formula,
	c   and X is the same as x_0.  A and X must be odd double precision integers
	c   in the range (1, 2^46).  The returned value RANDLC is normalized to be
	c   between 0 and 1, i.e. RANDLC = 2^(-46) x_1.  X is updated to contain
	c   the new seed x_1, so that subsequent calls to RANDLC using the same
	c   arguments will generate a continuous sequence.
	c
	c   This routine should produce the same results on any computer with at least
	c   48 mantissa bits in double precision floating point data.  On 64 bit
	c   systems, double precision should be disabled.
	c
	c   David H. Bailey     October 26, 1990
	c
	c---------------------------------------------------------------------
	*/
	double t1, t2, t3, t4, a1, a2, x1, x2, z;
	/*
	c---------------------------------------------------------------------
	c   Break A into two parts such that A = 2^23 A1 + A2.
	c---------------------------------------------------------------------
	*/
	double _ret_val_0;
	t1=(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*a);
	a1=((int)t1);
	a2=(a-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*a1));
	/*
	c---------------------------------------------------------------------
	c   Break X into two parts such that X = 2^23 X1 + X2, compute
	c   Z = A1 * X2 + A2 * X1  (mod 2^23), and then
	c   X = 2^23 * Z + A2 * X2  (mod 2^46).
	c---------------------------------------------------------------------
	*/
	t1=(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*( * x));
	x1=((int)t1);
	x2=(( * x)-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*x1));
	t1=((a1*x2)+(a2*x1));
	t2=((int)(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*t1));
	z=(t1-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*t2));
	t3=((((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*z)+(a2*x2));
	t4=((int)((((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5))*t3));
	( * x)=(t3-((((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0))*t4));
	_ret_val_0=((((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5))*( * x));
	return _ret_val_0;
}

/*
c---------------------------------------------------------------------
c---------------------------------------------------------------------
*/
void vranlc(int n, double * x_seed, double a, double y[])
{
	/*
	c---------------------------------------------------------------------
	c---------------------------------------------------------------------
	*/
	/*
	c---------------------------------------------------------------------
	c
	c   This routine generates N uniform pseudorandom double precision numbers in
	c   the range (0, 1) by using the linear congruential generator
	c
c   x_{k+1} = a x_k  (mod 2^46)
	c
	c   where 0 < x_k < 2^46 and 0 < a < 2^46.  This scheme generates 2^44 numbers
	c   before repeating.  The argument A is the same as 'a' in the above formula,
	c   and X is the same as x_0.  A and X must be odd double precision integers
	c   in the range (1, 2^46).  The N results are placed in Y and are normalized
	c   to be between 0 and 1.  X is updated to contain the new seed, so that
	c   subsequent calls to VRANLC using the same arguments will generate a
	c   continuous sequence.  If N is zero, only initialization is performed, and
	c   the variables X, A and Y are ignored.
	c
	c   This routine is the standard version designed for scalar or RISC systems.
	c   However, it should produce the same results on any single processor
	c   computer with at least 48 mantissa bits in double precision floating point
	c   data.  On 64 bit systems, double precision should be disabled.
	c
	c---------------------------------------------------------------------
	*/
	int i;
	double x, t1, t2, t3, t4, a1, a2, x1, x2, z;
	/*
	c---------------------------------------------------------------------
	c   Break A into two parts such that A = 2^23 A1 + A2.
	c---------------------------------------------------------------------
	*/
	t1=(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*a);
	a1=((int)t1);
	a2=(a-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*a1));
	x=( * x_seed);
	/*
	c---------------------------------------------------------------------
	c   Generate N results.   This loop is not vectorizable.
	c---------------------------------------------------------------------
	*/
	#pragma loop name vranlc#0 
	for (i=1; i<=n; i ++ )
	{
		/*
		c---------------------------------------------------------------------
		c   Break X into two parts such that X = 2^23 X1 + X2, compute
		c   Z = A1 * X2 + A2 * X1  (mod 2^23), and then
		c   X = 2^23 * Z + A2 * X2  (mod 2^46).
		c---------------------------------------------------------------------
		*/
		t1=(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*x);
		x1=((int)t1);
		x2=(x-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*x1));
		t1=((a1*x2)+(a2*x1));
		t2=((int)(((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*t1));
		z=(t1-(((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*t2));
		t3=((((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*z)+(a2*x2));
		t4=((int)((((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5))*t3));
		x=(t3-((((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*((((((((((((((((((((((2.0*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0)*2.0))*t4));
		y[i]=((((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*((((((((((((((((((((((0.5*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5)*0.5))*x);
	}
	( * x_seed)=x;
	return ;
}
