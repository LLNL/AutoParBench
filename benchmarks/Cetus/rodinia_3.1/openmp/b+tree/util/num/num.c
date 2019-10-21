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
/* ===============================================================================================================================================================================================================200 */
/* 	DESCRIPTION */
/* ===============================================================================================================================================================================================================200 */
/* Returns:	0 if string does not represent integer */
/* 			1 if string represents integer */
/* ===============================================================================================================================================================================================================200 */
/* 	NUM CODE */
/* ===============================================================================================================================================================================================================200 */
/* ======================================================================================================================================================150 */
/* 	ISINTEGER FUNCTION */
/* ======================================================================================================================================================150 */
int isInteger(char * str)
{
	/* ====================================================================================================100 */
	/* 	make sure it's not empty */
	/* ====================================================================================================100 */
	int _ret_val_0;
	if (( * str)=='\0')
	{
		_ret_val_0=0;
		return _ret_val_0;
	}
	/* ====================================================================================================100 */
	/* 	if any digit is not a number, return false */
	/* ====================================================================================================100 */
	#pragma loop name isInteger#0 
	for (; ( * str)!='\0'; str ++ )
	{
		if ((( * str)<48)||(( * str)>57))
		{
			/* digit characters (need to include . if checking for float) */
			_ret_val_0=0;
			return _ret_val_0;
		}
	}
	/* ====================================================================================================100 */
	/* 	it got past all my checks so I think it's a number */
	/* ====================================================================================================100 */
	_ret_val_0=1;
	return _ret_val_0;
}
