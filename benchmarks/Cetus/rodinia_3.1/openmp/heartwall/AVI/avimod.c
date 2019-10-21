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
/* #ifdef __cplusplus */
/* extern "C" { */
	/* #endif */
	/* =============================================================================================================================================================================================================== */
	/* 	DEFINE INCLUDE */
	/* =============================================================================================================================================================================================================== */
	/* =============================================================================================================================================================================================================== */
	/* 	DEFINE INCLUDE */
	/* =============================================================================================================================================================================================================== */
	/*
	
	  avilib.h
	 *
	 *  Copyright (C) Thomas ?streich - June 2001
	 *  multiple audio track support Copyright (C) 2002 Thomas ?streich
	 *
	 *  Original code:
	 *  Copyright (C) 1999 Rainer Johanni <Rainer@Johanni.de> 
	 *
	 *  This file is part of transcode, a linux video stream processing tool
	 *      
	 *  transcode is free software; you can redistribute it and/or modify
	 *  it under the terms of the GNU General Public License as published by
	 *  the Free Software Foundation; either version 2, or (at your option)
	 *  any later version.
	 *   
	 *  transcode is distributed in the hope that it will be useful,
	 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
	 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	 *  GNU General Public License for more details.
	 *   
	 *  You should have received a copy of the GNU General Public License
	 *  along with GNU Make; see the file COPYING.  If not, write to
	 *  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. 
	
	
	*/
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
	
		POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
	
	*/
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
	These are defined by the user (or the compiler)
	   to specify the desired environment:
	
	   __STRICT_ANSI__	ISO Standard C.
	   _ISOC99_SOURCE	Extensions to ISO C89 from ISO C99.
	   _ISOC11_SOURCE	Extensions to ISO C99 from ISO C11.
	   __STDC_WANT_LIB_EXT2__
				Extensions to ISO C99 from TR 27431-2:2010.
	   __STDC_WANT_IEC_60559_BFP_EXT__
				Extensions to ISO C11 from TS 18661-1:2014.
	   __STDC_WANT_IEC_60559_FUNCS_EXT__
				Extensions to ISO C11 from TS 18661-4:2015.
	   __STDC_WANT_IEC_60559_TYPES_EXT__
				Extensions to ISO C11 from TS 18661-3:2015.
	
	   _POSIX_SOURCE	IEEE Std 1003.1.
	   _POSIX_C_SOURCE	If ==1, like _POSIX_SOURCE; if >=2 add IEEE Std 1003.2;
				if >=199309L, add IEEE Std 1003.1b-1993;
				if >=199506L, add IEEE Std 1003.1c-1995;
				if >=200112L, all of IEEE 1003.1-2004
				if >=200809L, all of IEEE 1003.1-2008
	   _XOPEN_SOURCE	Includes POSIX and XPG things.  Set to 500 if
				Single Unix conformance is wanted, to 600 for the
				sixth revision, to 700 for the seventh revision.
	   _XOPEN_SOURCE_EXTENDED XPG things and XOpen Unix extensions.
	   _LARGEFILE_SOURCE	Some more functions for correct standard I/O.
	   _LARGEFILE64_SOURCE	Additional functionality from LFS for large files.
	   _FILE_OFFSET_BITS=N	Select default filesystem interface.
	   _ATFILE_SOURCE	Additional *at interfaces.
	   _GNU_SOURCE		All of the above, plus GNU extensions.
	   _DEFAULT_SOURCE	The default set of features (taking precedence over
				__STRICT_ANSI__).
	
	   _FORTIFY_SOURCE	Add security hardening to many library functions.
				Set to 1 or 2; 2 performs stricter checks than 1.
	
	   _REENTRANT, _THREAD_SAFE
				Obsolete; equivalent to _POSIX_C_SOURCE=199506L.
	
	   The `-ansi' switch to the GNU C compiler, and standards conformance
	   options such as `-std=c99', define __STRICT_ANSI__.  If none of
	   these are defined, or if _DEFAULT_SOURCE is defined, the default is
	   to have _POSIX_SOURCE set to one and _POSIX_C_SOURCE set to
	   200809L, as well as enabling miscellaneous functions from BSD and
	   SVID.  If more than one of these are defined, they accumulate.  For
	   example __STRICT_ANSI__, _POSIX_SOURCE and _POSIX_C_SOURCE together
	   give you ISO C, 1003.1, and 1003.2, but nothing else.
	
	   These are defined by this file and are used by the
	   header files to decide what to declare or define:
	
	   __GLIBC_USE (F)	Define things from feature set F.  This is defined
				to 1 or 0; the subsequent macros are either defined
				or undefined, and those tests should be moved to
				__GLIBC_USE.
	   __USE_ISOC11		Define ISO C11 things.
	   __USE_ISOC99		Define ISO C99 things.
	   __USE_ISOC95		Define ISO C90 AMD1 (C95) things.
	   __USE_ISOCXX11	Define ISO C++11 things.
	   __USE_POSIX		Define IEEE Std 1003.1 things.
	   __USE_POSIX2		Define IEEE Std 1003.2 things.
	   __USE_POSIX199309	Define IEEE Std 1003.1, and .1b things.
	   __USE_POSIX199506	Define IEEE Std 1003.1, .1b, .1c and .1i things.
	   __USE_XOPEN		Define XPG things.
	   __USE_XOPEN_EXTENDED	Define X/Open Unix things.
	   __USE_UNIX98		Define Single Unix V2 things.
	   __USE_XOPEN2K        Define XPG6 things.
	   __USE_XOPEN2KXSI     Define XPG6 XSI things.
	   __USE_XOPEN2K8       Define XPG7 things.
	   __USE_XOPEN2K8XSI    Define XPG7 XSI things.
	   __USE_LARGEFILE	Define correct standard I/O things.
	   __USE_LARGEFILE64	Define LFS things with separate names.
	   __USE_FILE_OFFSET64	Define 64bit interface as default.
	   __USE_MISC		Define things from 4.3BSD or System V Unix.
	   __USE_ATFILE		Define *at interfaces and AT_* constants for them.
	   __USE_GNU		Define GNU extensions.
	   __USE_FORTIFY_LEVEL	Additional security measures used, according to level.
	
	   The macros `__GNU_LIBRARY__', `__GLIBC__', and `__GLIBC_MINOR__' are
	   defined by this file unconditionally.  `__GNU_LIBRARY__' is provided
	   only for compatibility.  All new code should use the other symbols
	   to test for features.
	
	   All macros listed above as possibly being defined by this file are
	   explicitly undefined if they are not explicitly defined.
	   Feature-test macros that are not defined by the user or compiler
	   but are implied by the other feature-test macros defined (or by the
	   lack of any definitions) are defined by the file.
	
	   ISO C feature test macros depend on the definition of the macro
	   when an affected header is included, not when the first system
	   header is included, and so they are handled in
	   <bits/libc-header-start.h>, which does not have a multiple include
	   guard.  Feature test macros that can be handled from the first
	   system header included are handled here. 
	*/
	/* Undefine everything, so we get a clean slate.  */
	/*
	Suppress kernel-name space pollution unless user expressedly asks
	   for it. 
	*/
	/*
	Convenience macro to test the version of gcc.
	   Use like this:
	   #if __GNUC_PREREQ (2,8)
	   ... code requiring gcc 2.8 or later ...
	   #endif
	   Note: only works for GCC 2.0 and later, because __GNUC_MINOR__ was
	   added in 2.0. 
	*/
	/*
	Similarly for clang.  Features added to GCC after version 4.2 may
	   or may not also be available in clang, and clang's definitions of
	   __GNUC(_MINOR)__ are fixed at 4 and 2 respectively.  Not all such
	   features can be queried via __has_extension__has_feature. 
	*/
	/* Whether to use feature set F.  */
	/*
	_BSD_SOURCE and _SVID_SOURCE are deprecated aliases for
	   _DEFAULT_SOURCE.  If _DEFAULT_SOURCE is present we do not
	   issue a warning; the expectation is that the source is being
	   transitioned to use the new macro. 
	*/
	/* If _GNU_SOURCE was defined by the user, turn on all the other features.  */
	/*
	If nothing (other than _GNU_SOURCE and _DEFAULT_SOURCE) is defined,
	   define _DEFAULT_SOURCE. 
	*/
	/* This is to enable the ISO C11 extension.  */
	/* This is to enable the ISO C99 extension.  */
	/* This is to enable the ISO C90 Amendment 1:1995 extension.  */
	/*
	If none of the ANSIPOSIX macros are defined, or if _DEFAULT_SOURCE
	   is defined, use POSIX.1-2008 (or another version depending on
	   _XOPEN_SOURCE). 
	*/
	/*
	Some C libraries once required _REENTRANT andor _THREAD_SAFE to be
	   defined in all multithreaded code.  GNU libc has not required this
	   for many years.  We now treat them as compatibility synonyms for
	   _POSIX_C_SOURCE=199506L, which is the earliest level of POSIX with
	   comprehensive support for multithreaded code.  Using them never
	   lowers the selected level of POSIX conformance, only raises it. 
	*/
	/*
	The function 'gets' existed in C89, but is impossible to use
	   safely.  It has been removed from ISO C11 and ISO C++14.  Note: for
	   compatibility with various implementations of <cstdio>, this test
	   must consider only the value of __cplusplus when compiling C++. 
	*/
	/*
	Get definitions of __STDC_ predefined macros, if the compiler has
	   not preincluded this header automatically. 
	*/
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
	This macro indicates that the installed library is the GNU C Library.
	   For historic reasons the value now is 6 and this will stay from now
	   on.  The use of this variable is deprecated.  Use __GLIBC__ and
	   __GLIBC_MINOR__ now (see below) when you want to test for a specific
	   GNU C library version and use the values in <gnulib-names.h> to get
	   the sonames of the shared libraries. 
	*/
	/*
	Major and minor version number of the GNU C library package.  Use
	   these macros to test for features in specific releases. 
	*/
	/* This is here only because every header file already includes this one.  */
	/*
	Copyright (C) 1992-2018 Free Software Foundation, Inc.
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
	/* We are almost always included from features.h. */
	/*
	The GNU libc does not support any K&R compilers or the traditional mode
	   of ISO C compilers anymore.  Check for some of the combinations not
	   anymore supported. 
	*/
	/* Some user header file might have defined this before.  */
	/*
	All functions, except those with callbacks or those that
	   synchronize memory, are leaf functions. 
	*/
	/*
	GCC can always grok prototypes.  For C++ programs we add throw()
	   to help it optimize the function calls.  But this works only with
	   gcc 2.8.x and egcs.  For gcc 3.2 and up we even mark C functions
	   as non-throwing using a function attribute since programs can use
	   the -fexceptions options for C code as well. 
	*/
	/*
	Compilers that are not clang may object to
	       #if defined __clang__ && __has_extension(...)
	   even though they do not need to evaluate the right-hand side of the &&. 
	*/
	/*
	These two macros are not used in glibc anymore.  They are kept here
	   only because some other projects expect the macros to be defined. 
	*/
	/*
	For these things, GCC behaves the ANSI way normally,
	   and the non-ANSI way under -traditional. 
	*/
	/* This is not a typedef so `const __ptr_t' does the right thing.  */
	/* C++ needs to know that types and declarations are C, not C++.  */
	/* Fortify support.  */
	/*
	Support for flexible arrays.
	   Headers that should use flexible arrays only if they're "real"
	   (e.g. only if they won't affect sizeof()) should test
	   #if __glibc_c99_flexarr_available. 
	*/
	/*
	__asm__ ("xyz") is used throughout the headers to rename functions
	   at the assembly language level.  This is wrapped by the __REDIRECT
	   macro, in order to support compilers that can do this some other
	   way.  When compilers don't support asm-names at all, we have to do
	   preprocessor tricks instead (which don't have exactly the right
	   semantics, but it's the best we can do).
	
	   Example:
	   int __REDIRECT(setpgrp, (__pid_t pid, __pid_t pgrp), setpgid);
	*/
	/*
	
	#elif __SOME_OTHER_COMPILER__
	
	# define __REDIRECT(name, proto, alias) name proto; 	_Pragma("let " #name " = " #alias)
	)
	
	*/
	/*
	GCC has various useful declarations that can be made with the
	   `__attribute__' syntax.  All of the ways we use this do fine if
	   they are omitted for compilers that don't understand it.
	*/
	/*
	At some point during the gcc 2.96 development the `malloc' attribute
	   for functions was introduced.  We don't want to use it unconditionally
	   (although this would be possible) since it generates warnings. 
	*/
	/*
	Tell the compiler which arguments to an allocation function
	   indicate the size of the allocation. 
	*/
	/*
	At some point during the gcc 2.96 development the `pure' attribute
	   for functions was introduced.  We don't want to use it unconditionally
	   (although this would be possible) since it generates warnings. 
	*/
	/* This declaration tells the compiler that the value is constant.  */
	/*
	At some point during the gcc 3.1 development the `used' attribute
	   for functions was introduced.  We don't want to use it unconditionally
	   (although this would be possible) since it generates warnings. 
	*/
	/* Since version 3.2, gcc allows marking deprecated functions.  */
	/*
	Since version 4.5, gcc also allows one to specify the message printed
	   when a deprecated function is used.  clang claims to be gcc 4.2, but
	   may also support this feature. 
	*/
	/*
	At some point during the gcc 2.8 development the `format_arg' attribute
	   for functions was introduced.  We don't want to use it unconditionally
	   (although this would be possible) since it generates warnings.
	   If several `format_arg' attributes are given for the same function, in
	   gcc-3.0 and older, all but the last one are ignored.  In newer gccs,
	   all designated arguments are considered. 
	*/
	/*
	At some point during the gcc 2.97 development the `strfmon' format
	   attribute for functions was introduced.  We don't want to use it
	   unconditionally (although this would be possible) since it
	   generates warnings. 
	*/
	/*
	The nonull function attribute allows to mark pointer parameters which
	   must not be NULL. 
	*/
	/*
	If fortification mode, we warn about unused results of certain
	   function calls which can lead to problems. 
	*/
	/* Forces a function to be always inlined.  */
	/*
	The Linux kernel defines __always_inline in stddef.h (283d7573), and
	   it conflicts with this definition.  Therefore undefine it first to
	   allow either header to be included first. 
	*/
	/*
	Associate error messages with the source location of the call site rather
	   than with the source location inside the function. 
	*/
	/*
	GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
	   inline semantics, unless -fgnu89-inline is used.  Using __GNUC_STDC_INLINE__
	   or __GNUC_GNU_INLINE is not a good enough check for gcc because gcc versions
	   older than 4.3 may define these macros and still not guarantee GNU inlining
	   semantics.
	
	   clang++ identifies itself as gcc-4.2, but has support for GNU inlining
	   semantics, that can be checked fot by using the __GNUC_STDC_INLINE_ and
	   __GNUC_GNU_INLINE__ macro definitions. 
	*/
	/*
	GCC 4.3 and above allow passing all anonymous arguments of an
	   __extern_always_inline function to some other vararg function. 
	*/
	/*
	It is possible to compile containing GCC extensions even if GCC is
	   run in pedantic mode if the uses are carefully marked using the
	   `__extension__' keyword.  But this is not generally available before
	   version 2.8. 
	*/
	/* __restrict is known in EGCS 1.2 and above. */
	/*
	ISO C99 also allows to declare arrays as non-overlapping.  The syntax is
	     array_name[restrict]
	   GCC 3.1 supports this. 
	*/
	/*
	Describes a char array whose address can safely be passed as the first
	   argument to strncpy and strncat, as the char array is not necessarily
	   a NUL-terminated string. 
	*/
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/*
	Properties of long double type.  ldbl-96 version.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it andor
	   modify it under the terms of the GNU Lesser General Public
	   License  published by the Free Software Foundation; either
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
	long double is distinct from double, so there is nothing to
	   define here. 
	*/
	/*
	__glibc_macro_warning (MESSAGE) issues warning MESSAGE.  This is
	   intended for use in preprocessor macros.
	
	   Note: MESSAGE must be a _single_ string; concatenation of string
	   literals is not supported. 
	*/
	/*
	Generic selection (ISO C11) is a C-only feature, available in GCC
	   since version 4.9.  Previous versions do not provide generic
	   selection, even though they might set __STDC_VERSION__ to 201112L,
	   when in -std=c11 mode.  Thus, we must check for !defined __GNUC__
	   when testing __STDC_VERSION__ for generic selection support.
	   On the other hand, Clang also defines __GNUC__, so a clang-specific
	   check is required to enable the use of generic selection. 
	*/
	/*
	If we don't have __REDIRECT, prototypes will be missing if
	   __USE_FILE_OFFSET64 but not __USE_LARGEFILE[64].
	*/
	/* Decide whether we can define 'extern inline' functions in headers.  */
	/*
	This is here only because every header file already includes this one.
	   Get the definitions of all the appropriate `__stub_FUNCTION' symbols.
	   <gnustubs.h> contains `#define __stub_FUNCTION' when FUNCTION is a stub
	   that will always return failure (and set errno to ENOSYS). 
	*/
	/*
	This file is automatically generated.
	   This file selects the right generated file of `__stub_FUNCTION' macros
	   based on the architecture being compiled for. 
	*/
	/*
	This file is automatically generated.
	   It defines a symbol `__stub_FUNCTION' for each function
	   in the C library which is a stub, meaning it will fail
	   every time called, usually setting errno to ENOSYS. 
	*/
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
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
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/* Convenience types.  */
	typedef unsigned char __u_char;
	typedef unsigned short int __u_short;
	typedef unsigned int __u_int;
	typedef unsigned long int __u_long;
	/* Fixed-size types, underlying types depend on word size and compiler.  */
	typedef signed char __int8_t;
	typedef unsigned char __uint8_t;
	typedef signed short int __int16_t;
	typedef unsigned short int __uint16_t;
	typedef signed int __int32_t;
	typedef unsigned int __uint32_t;
	typedef signed long int __int64_t;
	typedef unsigned long int __uint64_t;
	/* Smallest types with at least a given width.  */
	typedef __int8_t __int_least8_t;
	typedef __uint8_t __uint_least8_t;
	typedef __int16_t __int_least16_t;
	typedef __uint16_t __uint_least16_t;
	typedef __int32_t __int_least32_t;
	typedef __uint32_t __uint_least32_t;
	typedef __int64_t __int_least64_t;
	typedef __uint64_t __uint_least64_t;
	/* quad_t is also 64 bits.  */
	typedef long int __quad_t;
	typedef unsigned long int __u_quad_t;
	/* Largest integral types.  */
	typedef long int __intmax_t;
	typedef unsigned long int __uintmax_t;
	/*
	The machine-dependent file <bitstypesizes.h> defines __*_T_TYPE
	   macros for each of the OS types we define below.  The definitions
	   of those macros must use the following macros for underlying types.
	   We define __S<SIZE>_TYPE and __U<SIZE>_TYPE for the signed and unsigned
	   variants of each of the following integer types on this machine.
	
		16		-- "natural" 16-bit type (always short)
		32		-- "natural" 32-bit type (always int)
		64		-- "natural" 64-bit type (long or long long)
		LONG32		-- 32-bit type, traditionally long
		QUAD		-- 64-bit type, always long long
		WORD		-- natural type of __WORDSIZE bits (int or long)
		LONGWORD	-- type of __WORDSIZE bits, traditionally long
	
	   We distinguish WORD/LONGWORD, 32/LONG32, and 64/QUAD so that the
	   conventional uses of `long' or `long long' type modifiers match the
	   types we define, even when a less-adorned type would be the same size.
	   This matters for (somewhat) portably writing printf/scanf formats for
	   these types, where using the appropriate l or ll format modifiers can
	   make the typedefs and the formats match up across all GNU platforms.  If
	   we used `long' when it's 64 bits where `long long' is expected, then the
	   compiler would warn about the formats not matching the argument types,
	   and the programmer changing them to shut up the compiler would break the
	   program's portability.
	
	   Here we assume what is presently the case in all the GCC configurations
	   we support: long long is always 64 bits, long is always word/address size,
	   and int is always 32 bits. 
	*/
	/* No need to mark the typedef with __extension__.   */
	/*
	bitstypesizes.h -- underlying types for *_t.  Linux/x86-64 version.
	   Copyright (C) 2012-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	See <bitstypes.h> for the meaning of these macros.  This file exists so
	   that <bits/types.h> need not vary across different GNU platforms. 
	*/
	/* X32 kernel interface is 64-bit.  */
	/*
	Tell the libc code that off_t and off64_t are actually the same type
	   for all ABI purposes, even if possibly expressed as different base types
	   for C type-checking purposes. 
	*/
	/* Same for ino_t and ino64_t.  */
	/* And for __rlim_t and __rlim64_t.  */
	/* Number of descriptors that can fit in an `fd_set'.  */
	typedef unsigned long int __dev_t;
	/* Type of device numbers.  */
	typedef unsigned int __uid_t;
	/* Type of user identifications.  */
	typedef unsigned int __gid_t;
	/* Type of group identifications.  */
	typedef unsigned long int __ino_t;
	/* Type of file serial numbers.  */
	typedef unsigned long int __ino64_t;
	/* Type of file serial numbers (LFS). */
	typedef unsigned int __mode_t;
	/* Type of file attribute bitmasks.  */
	typedef unsigned long int __nlink_t;
	/* Type of file link counts.  */
	typedef long int __off_t;
	/* Type of file sizes and offsets.  */
	typedef long int __off64_t;
	/* Type of file sizes and offsets (LFS).  */
	typedef int __pid_t;
	/* Type of process identifications.  */
	struct named_avimod_c_317
	{
		int __val[2];
	};
	
	typedef struct named_avimod_c_317 __fsid_t;
	/* Type of file system IDs.  */
	typedef long int __clock_t;
	/* Type of CPU usage counts.  */
	typedef unsigned long int __rlim_t;
	/* Type for resource measurement.  */
	typedef unsigned long int __rlim64_t;
	/* Type for resource measurement (LFS).  */
	typedef unsigned int __id_t;
	/* General type for IDs.  */
	typedef long int __time_t;
	/* Seconds since the Epoch.  */
	typedef unsigned int __useconds_t;
	/* Count of microseconds.  */
	typedef long int __suseconds_t;
	/* Signed count of microseconds.  */
	typedef int __daddr_t;
	/* The type of a disk address.  */
	typedef int __key_t;
	/* Type of an IPC key.  */
	/* Clock ID used in clock and timer functions.  */
	typedef int __clockid_t;
	/* Timer ID returned by `timer_create'.  */
	typedef void * __timer_t;
	/* Type to represent block size.  */
	typedef long int __blksize_t;
	/* Types from the Large File Support interface.  */
	/* Type to count number of disk blocks.  */
	typedef long int __blkcnt_t;
	typedef long int __blkcnt64_t;
	/* Type to count file system blocks.  */
	typedef unsigned long int __fsblkcnt_t;
	typedef unsigned long int __fsblkcnt64_t;
	/* Type to count file system nodes.  */
	typedef unsigned long int __fsfilcnt_t;
	typedef unsigned long int __fsfilcnt64_t;
	/* Type of miscellaneous file system fields.  */
	typedef long int __fsword_t;
	typedef long int __ssize_t;
	/* Type of a byte count, or error.  */
	/* Signed long type used in system calls.  */
	typedef long int __syscall_slong_t;
	/* Unsigned long type used in system calls.  */
	typedef unsigned long int __syscall_ulong_t;
	/*
	These few don't really vary by system, they always correspond
	   to one of the other defined types. 
	*/
	typedef __off64_t __loff_t;
	/* Type of file sizes and offsets (LFS).  */
	typedef char * __caddr_t;
	/* Duplicates info from stdint.h but this is used in unistd.h.  */
	typedef long int __intptr_t;
	/* Duplicate info from syssocket.h.  */
	typedef unsigned int __socklen_t;
	/*
	C99: An integer type that can be accessed as an atomic entity,
	   even in the presence of asynchronous interrupts.
	   It is not currently necessary for this to be machine-specific. 
	*/
	typedef int __sig_atomic_t;
	typedef __u_char u_char;
	typedef __u_short u_short;
	typedef __u_int u_int;
	typedef __u_long u_long;
	typedef __quad_t quad_t;
	typedef __u_quad_t u_quad_t;
	typedef __fsid_t fsid_t;
	typedef __loff_t loff_t;
	typedef __ino_t ino_t;
	typedef __dev_t dev_t;
	typedef __gid_t gid_t;
	typedef __mode_t mode_t;
	typedef __nlink_t nlink_t;
	typedef __uid_t uid_t;
	typedef __off_t off_t;
	typedef __pid_t pid_t;
	typedef __id_t id_t;
	typedef __ssize_t ssize_t;
	typedef __daddr_t daddr_t;
	typedef __caddr_t caddr_t;
	typedef __key_t key_t;
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Returned by `clock'.  */
	typedef __clock_t clock_t;
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Clock ID used in clock and timer functions.  */
	typedef __clockid_t clockid_t;
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Returned by `time'.  */
	typedef __time_t time_t;
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Timer ID returned by `timer_create'.  */
	typedef __timer_t timer_t;
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	typedef long unsigned int size_t;
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/* Old compatibility names for C types.  */
	typedef unsigned long int ulong;
	typedef unsigned short int ushort;
	typedef unsigned int uint;
	/* These size-specific names are used by some of the inet code.  */
	/*
	Define intN_t types.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	typedef __int8_t int8_t;
	typedef __int16_t int16_t;
	typedef __int32_t int32_t;
	typedef __int64_t int64_t;
	/* For GCC 2.7 and later, we can use specific type-size attributes.  */
	typedef unsigned int u_int8_t;
	typedef unsigned int u_int16_t;
	typedef unsigned int u_int32_t;
	typedef unsigned int u_int64_t;
	typedef int register_t;
	/*
	Some code from BIND tests this macro to see if the types above are
	   defined. 
	*/
	/* In BSD <systypes.h> is expected to define BYTE_ORDER.  */
	/*
	Copyright (C) 1992-2018 Free Software Foundation, Inc.
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
	Definitions for byte order, according to significance of bytes,
	   from low addresses to high addresses.  The value is what you get by
	   putting '4' in the most significant byte, '3' in the second most
	   significant byte, '2' in the second least significant byte, and '1'
	   in the least significant byte, and then writing down one digit for
	   each byte, starting with the byte at the lowest address at the left,
	   and proceeding to the byte with the highest address at the right. 
	*/
	/* This file defines `__BYTE_ORDER' for the particular machine.  */
	/* i386x86_64 are little-endian.  */
	/*
	Some machines may need to use a different endianness for floating point
	   values. 
	*/
	/* Conversion interfaces.  */
	/*
	Macros and inline functions to swap the order of bytes in integer values.
	   Copyright (C) 1997-2018 Free Software Foundation, Inc.
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
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Swap bytes in 16-bit value.  */
	static inline __uint16_t __bswap_16(__uint16_t __bsx)
	{
		__uint16_t _ret_val_0;
		_ret_val_0=__builtin_bswap16(__bsx);
		return _ret_val_0;
	}
	
	/* Swap bytes in 32-bit value.  */
	static inline __uint32_t __bswap_32(__uint32_t __bsx)
	{
		__uint32_t _ret_val_0;
		_ret_val_0=__builtin_bswap32(__bsx);
		return _ret_val_0;
	}
	
	/* Swap bytes in 64-bit value.  */
	static inline __uint64_t __bswap_64(__uint64_t __bsx)
	{
		__uint64_t _ret_val_0;
		_ret_val_0=__builtin_bswap64(__bsx);
		return _ret_val_0;
	}
	
	/*
	Inline functions to return unsigned integer values unchanged.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	These inline functions are to ensure the appropriate type
	   conversions and associated diagnostics from macros that convert to
	   a given endianness. 
	*/
	static inline __uint16_t __uint16_identity(__uint16_t __x)
	{
		return __x;
	}
	
	static inline __uint32_t __uint32_identity(__uint32_t __x)
	{
		return __x;
	}
	
	static inline __uint64_t __uint64_identity(__uint64_t __x)
	{
		return __x;
	}
	
	/* It also defines `fd_set' and the FD_ macros for `select'.  */
	/*
	`fd_set' type and related macros, and `select'`pselect' declarations.
	   Copyright (C) 1996-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	/* 	POSIX 1003.1g: 6.2 Select from File Descriptor Sets <sysselect.h>  */
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
	/* Get definition of needed basic types.  */
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* Get __FD_ definitions.  */
	/*
	Copyright (C) 1997-2018 Free Software Foundation, Inc.
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
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/* Get sigset_t.  */
	struct named_avimod_c_1066
	{
		unsigned long int __val[(1024/(8*sizeof (unsigned long int)))];
	};
	
	typedef struct named_avimod_c_1066 __sigset_t;
	/* A set of signals to be blocked, unblocked, or waited for.  */
	typedef __sigset_t sigset_t;
	/* Get definition of timer specification structures.  */
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	A time value that is accurate to the nearest
	   microsecond but also has a range of years. 
	*/
	struct timeval
	{
		__time_t tv_sec;
		/* Seconds.  */ 
		__suseconds_t tv_usec;
	};
	
	/* Microseconds.  */
	/* NB: Include guard matches what <linuxtime.h> uses.  */
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	POSIX.1b structure for a time value.  This is like a `struct timeval' but
	   has nanoseconds instead of microseconds. 
	*/
	struct timespec
	{
		__time_t tv_sec;
		/* Seconds.  */ 
		__syscall_slong_t tv_nsec;
	};
	
	/* Nanoseconds.  */
	typedef __suseconds_t suseconds_t;
	/* The fd_set member is required to be an array of longs.  */
	typedef long int __fd_mask;
	/* Some versions of <linuxposix_types.h> define this macros.  */
	/* It's easier to assume 8-bit bytes than to get CHAR_BIT.  */
	/* fd_set for select and pselect.  */
	struct named_avimod_c_1161
	{
		/* XPG4.2 requires this member name.  Otherwise avoid the name
		       from the global namespace.  */ 
		__fd_mask __fds_bits[(1024/(8*((int)sizeof (__fd_mask))))];
	};
	
	typedef struct named_avimod_c_1161 fd_set;
	/* Maximum number of file descriptors in `fd_set'.  */
	/* Sometimes the fd_set member is assumed to have this type.  */
	typedef __fd_mask fd_mask;
	/* Number of bits per word of `fd_set' (some code assumes this is 32).  */
	/* Access macros for `fd_set'.  */
	/*
	Check the first NFDS descriptors each in READFDS (if not NULL) for read
	   readiness, in WRITEFDS (if not NULL) for write readiness, and in EXCEPTFDS
	   (if not NULL) for exceptional conditions.  If TIMEOUT is not NULL, time out
	   after waiting the interval specified therein.  Returns the number of ready
	   descriptors, or -1 for errors.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int select(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, struct timeval * __timeout);
	/*
	Same as above only that the TIMEOUT value is given with higher
	   resolution and a sigmask which is been set temporarily.  This version
	   should be used.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int pselect(int __nfds, fd_set * __readfds, fd_set * __writefds, fd_set * __exceptfds, const struct timespec * __timeout, const __sigset_t * __sigmask);
	/* Define some inlines helping to catch common problems.  */
	typedef __blksize_t blksize_t;
	/* Types from the Large File Support interface.  */
	typedef __blkcnt_t blkcnt_t;
	/* Type to count number of disk blocks.  */
	typedef __fsblkcnt_t fsblkcnt_t;
	/* Type to count file system blocks.  */
	typedef __fsfilcnt_t fsfilcnt_t;
	/* Type to count file system inodes.  */
	/* Now add the thread types.  */
	/*
	Declaration of common pthread types for all architectures.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	/* For internal mutex and condition variable definitions.  */
	/*
	Common threading primitives definitions for both POSIX and C11.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	Arch-specific definitions.  Each architecture must define the following
	   macros to define the expected sizes of pthread data types:
	
	   __SIZEOF_PTHREAD_ATTR_T        - size of pthread_attr_t.
	   __SIZEOF_PTHREAD_MUTEX_T       - size of pthread_mutex_t.
	   __SIZEOF_PTHREAD_MUTEXATTR_T   - size of pthread_mutexattr_t.
	   __SIZEOF_PTHREAD_COND_T        - size of pthread_cond_t.
	   __SIZEOF_PTHREAD_CONDATTR_T    - size of pthread_condattr_t.
	   __SIZEOF_PTHREAD_RWLOCK_T      - size of pthread_rwlock_t.
	   __SIZEOF_PTHREAD_RWLOCKATTR_T  - size of pthread_rwlockattr_t.
	   __SIZEOF_PTHREAD_BARRIER_T     - size of pthread_barrier_t.
	   __SIZEOF_PTHREAD_BARRIERATTR_T - size of pthread_barrierattr_t.
	
	   Also, the following macros must be define for internal pthread_mutex_t
	   struct definitions (struct __pthread_mutex_s):
	
	   __PTHREAD_COMPAT_PADDING_MID   - any additional members after 'kind'
					    and before '__spin' (for 64 bits) or
					    '__nusers' (for 32 bits).
	   __PTHREAD_COMPAT_PADDING_END   - any additional members at the end of
					    the internal structure.
	   __PTHREAD_MUTEX_LOCK_ELISION   - 1 if the architecture supports lock
					    elision or 0 otherwise.
	   __PTHREAD_MUTEX_NUSERS_AFTER_KIND - control where to put __nusers.  The
					       preferred value for new architectures
					       is 0.
	   __PTHREAD_MUTEX_USE_UNION      - control whether internal __spins and
					    __list will be place inside a union for
					    linuxthreads compatibility.
					    The preferred value for new architectures
					    is 0.
	
	   For a new port the preferred values for the required defines are:
	
	   #define __PTHREAD_COMPAT_PADDING_MID
	   #define __PTHREAD_COMPAT_PADDING_END
	   #define __PTHREAD_MUTEX_LOCK_ELISION         0
	   #define __PTHREAD_MUTEX_NUSERS_AFTER_KIND    0
	   #define __PTHREAD_MUTEX_USE_UNION            0
	
	   __PTHREAD_MUTEX_LOCK_ELISION can be set to 1 if the hardware plans to
	   eventually support lock elision using transactional memory.
	
	   The additional macro defines any constraint for the lock alignment
	   inside the thread structures:
	
	   __LOCK_ALIGNMENT - for internal lockfutex usage.
	
	   Same idea but for the once locking primitive:
	
	   __ONCE_ALIGNMENT - for pthread_once_t/once_flag definition.
	
	   And finally the internal pthread_rwlock_t (struct __pthread_rwlock_arch_t)
	   must be defined.
	
	*/
	/*
	Copyright (C) 2002-2018 Free Software Foundation, Inc.
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
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/* Definitions for internal mutex struct.  */
	struct __pthread_rwlock_arch_t
	{
		unsigned int __readers;
		unsigned int __writers;
		unsigned int __wrphase_futex;
		unsigned int __writers_futex;
		unsigned int __pad3;
		unsigned int __pad4;
		int __cur_writer;
		int __shared;
		signed char __rwelision;
		unsigned char __pad1[7];
		unsigned long int __pad2;
		/* FLAGS must stay at this position in the structure to maintain
		     binary compatibility.  */ 
		unsigned int __flags;
	};
	
	/* Common definition of pthread_mutex_t. */
	struct __pthread_internal_list
	{
		struct __pthread_internal_list * __prev;
		struct __pthread_internal_list * __next;
	};
	
	typedef struct __pthread_internal_list __pthread_list_t;
	/* Lock elision support.  */
	struct __pthread_mutex_s
	{
		int __lock;
		unsigned int __count;
		int __owner;
		unsigned int __nusers;
		/* KIND must stay at this position in the structure to maintain
		     binary compatibility with static initializers.  */ 
		int __kind;
		short __spins;
		short __elision;
		__pthread_list_t __list;
	};
	
	/* Common definition of pthread_cond_t. */
	struct named_avimod_c_1514
	{
		unsigned int __low;
		unsigned int __high;
	};
	
	union named_avimod_c_1499
	{
		unsigned long long int __wseq;
		struct named_avimod_c_1514 __wseq32;
	};
	
	struct named_avimod_c_1553
	{
		unsigned int __low;
		unsigned int __high;
	};
	
	union named_avimod_c_1538
	{
		unsigned long long int __g1_start;
		struct named_avimod_c_1553 __g1_start32;
	};
	
	struct __pthread_cond_s
	{
		union named_avimod_c_1499 ;
		union named_avimod_c_1538 ;
		unsigned int __g_refs[2];
		unsigned int __g_size[2];
		unsigned int __g1_orig_size;
		unsigned int __wrefs;
		unsigned int __g_signals[2];
	};
	
	/*
	Thread identifiers.  The structure of the attribute type is not
	   exposed on purpose. 
	*/
	typedef unsigned long int pthread_t;
	/*
	Data structures for mutex handling.  The structure of the attribute
	   type is not exposed on purpose. 
	*/
	union named_avimod_c_1635
	{
		char __size[4];
		int __align;
	};
	
	typedef union named_avimod_c_1635 pthread_mutexattr_t;
	/*
	Data structure for condition variable handling.  The structure of
	   the attribute type is not exposed on purpose. 
	*/
	union named_avimod_c_1657
	{
		char __size[4];
		int __align;
	};
	
	typedef union named_avimod_c_1657 pthread_condattr_t;
	/* Keys for thread-specific data */
	typedef unsigned int pthread_key_t;
	/* Once-only execution */
	typedef int pthread_once_t;
	union pthread_attr_t
	{
		char __size[56];
		long int __align;
	};
	
	typedef union pthread_attr_t pthread_attr_t;
	union named_avimod_c_1726
	{
		struct __pthread_mutex_s __data;
		char __size[40];
		long int __align;
	};
	
	typedef union named_avimod_c_1726 pthread_mutex_t;
	union named_avimod_c_1757
	{
		struct __pthread_cond_s __data;
		char __size[48];
		long long int __align;
	};
	
	typedef union named_avimod_c_1757 pthread_cond_t;
	/*
	Data structure for reader-writer lock variable handling.  The
	   structure of the attribute type is deliberately not exposed. 
	*/
	union named_avimod_c_1791
	{
		struct __pthread_rwlock_arch_t __data;
		char __size[56];
		long int __align;
	};
	
	typedef union named_avimod_c_1791 pthread_rwlock_t;
	union named_avimod_c_1822
	{
		char __size[8];
		long int __align;
	};
	
	typedef union named_avimod_c_1822 pthread_rwlockattr_t;
	/* POSIX spinlock data type.  */
	typedef volatile int pthread_spinlock_t;
	/*
	POSIX barriers data type.  The structure of the type is
	   deliberately not exposed. 
	*/
	union named_avimod_c_1855
	{
		char __size[32];
		long int __align;
	};
	
	typedef union named_avimod_c_1855 pthread_barrier_t;
	union named_avimod_c_1879
	{
		char __size[4];
		int __align;
	};
	
	typedef union named_avimod_c_1879 pthread_barrierattr_t;
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
	
		POSIX Standard: 5.6 File Characteristics	<sys/stat.h>
	
	*/
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
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/* NB: Include guard matches what <linuxtime.h> uses.  */
	/*
	The Single Unix specification says that some more types are
	   available here. 
	*/
	/*
	Copyright (C) 1999-2018 Free Software Foundation, Inc.
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
	/* Versions of the `struct stat' data structure.  */
	/* x86-64 versions of the `xmknod' interface.  */
	struct stat
	{
		__dev_t st_dev;
		/* Device.  */ 
		__ino_t st_ino;
		/* File serial number.	*/ 
		__nlink_t st_nlink;
		/* Link count.  */ 
		__mode_t st_mode;
		/* File mode.  */ 
		__uid_t st_uid;
		/* User ID of the file's owner.	*/ 
		__gid_t st_gid;
		/* Group ID of the file's group.*/ 
		int __pad0;
		__dev_t st_rdev;
		/* Device number, if device.  */ 
		__off_t st_size;
		/* Size of file, in bytes.  */ 
		__blksize_t st_blksize;
		/* Optimal block size for I/O.  */ 
		__blkcnt_t st_blocks;
		/* Number 512-byte blocks allocated. */ 
		/* Nanosecond resolution timestamps are stored in a format
		       equivalent to 'struct timespec'.  This is the type used
		       whenever possible but the Unix namespace rules do not allow the
		       identifier 'timespec' to appear in the <sys/stat.h> header.
		       Therefore we have to handle the use of this header in strictly
		       standard-compliant sources special.  */ 
		struct timespec st_atim;
		/* Time of last access.  */ 
		struct timespec st_mtim;
		/* Time of last modification.  */ 
		struct timespec st_ctim;
		/* Time of last status change.  */ 
		__syscall_slong_t __glibc_reserved[3];
	};
	
	struct timespec;
	
	/* Tell code we have these members.  */
	/* Nanosecond resolution time values are supported.  */
	/* Encoding of the file mode.  */
	/* File types.  */
	/*
	POSIX.1b objects.  Note that these macros always evaluate to zero.  But
	   they do it by enforcing the correct use of the macros. 
	*/
	/* Protection bits.  */
	/* Test macros for file types.	 */
	/*
	These are from POSIX.1b.  If the objects are not implemented using separate
	   distinct file types, the macros always will evaluate to zero.  Unlike the
	   other S_ macros the following three take a pointer to a `struct stat'
	   object as the argument. 
	*/
	/* Protection bits.  */
	/* Save swapped text after use (sticky bit).  This is pretty well obsolete.  */
	/* Read, write, and execute by owner.  */
	/* Read, write, and execute by group.  */
	/* Read, write, and execute by others.  */
	/* Macros for common mode bit masks.  */
	/* Get file attributes for FILE and put them in BUF.  */
	extern int stat(const char * __file, struct stat * __buf);
	/*
	Get file attributes for the file, device, pipe, or socket
	   that file descriptor FD is open on and put them in BUF. 
	*/
	extern int fstat(int __fd, struct stat * __buf);
	/*
	Similar to stat, get the attributes for FILE and put them in BUF.
	   Relative path names are interpreted relative to FD unless FD is
	   AT_FDCWD. 
	*/
	extern int fstatat(int __fd, const char * __file, struct stat * __buf, int __flag);
	/*
	Get file attributes about FILE and put them in BUF.
	   If FILE is a symbolic link, do not follow it. 
	*/
	extern int lstat(const char * __file, struct stat * __buf);
	/*
	Set file access permissions for FILE to MODE.
	   If FILE is a symbolic link, this affects its target instead. 
	*/
	extern int chmod(const char * __file, __mode_t __mode);
	/*
	Set file access permissions for FILE to MODE.
	   If FILE is a symbolic link, this affects the link itself
	   rather than its target. 
	*/
	extern int lchmod(const char * __file, __mode_t __mode);
	/* Set file access permissions of the file FD is open on to MODE.  */
	extern int fchmod(int __fd, __mode_t __mode);
	/*
	Set file access permissions of FILE relative to
	   the directory FD is open on. 
	*/
	extern int fchmodat(int __fd, const char * __file, __mode_t __mode, int __flag);
	/*
	Set the file creation mask of the current process to MASK,
	   and return the old creation mask. 
	*/
	extern __mode_t umask(__mode_t __mask);
	/* Create a new directory named PATH, with permission bits MODE.  */
	extern int mkdir(const char * __path, __mode_t __mode);
	/*
	Like mkdir, create a new directory with permission bits MODE.  But
	   interpret relative PATH names relative to the directory associated
	   with FD. 
	*/
	extern int mkdirat(int __fd, const char * __path, __mode_t __mode);
	/*
	Create a device file named PATH, with permission and special bits MODE
	   and device number DEV (which can be constructed from major and minor
	   device numbers with the `makedev' macro above). 
	*/
	extern int mknod(const char * __path, __mode_t __mode, __dev_t __dev);
	/*
	Like mknod, create a new device file with permission bits MODE and
	   device number DEV.  But interpret relative PATH names relative to
	   the directory associated with FD. 
	*/
	extern int mknodat(int __fd, const char * __path, __mode_t __mode, __dev_t __dev);
	/* Create a new FIFO named PATH, with permission bits MODE.  */
	extern int mkfifo(const char * __path, __mode_t __mode);
	/*
	Like mkfifo, create a new FIFO with permission bits MODE.  But
	   interpret relative PATH names relative to the directory associated
	   with FD. 
	*/
	extern int mkfifoat(int __fd, const char * __path, __mode_t __mode);
	/*
	Set file access and modification times relative to directory file
	   descriptor. 
	*/
	extern int utimensat(int __fd, const char * __path, const struct timespec __times[2], int __flags);
	/* Set file access and modification times of the file associated with FD.  */
	extern int futimens(int __fd, const struct timespec __times[2]);
	/*
	To allow the `struct stat' structure and the file type `mode_t'
	   bits to vary without changing shared library major version number,
	   the `stat' family of functions and `mknod' are in fact inline
	   wrappers around calls to `xstat', `fxstat', `lxstat', and `xmknod',
	   which all take a leading version-number argument designating the
	   data structure and bits used.  <bitsstat.h> defines _STAT_VER with
	   the version number corresponding to `struct stat' as defined in
	   that file; and _MKNOD_VER with the version number corresponding to
	   the S_IF* macros defined therein.  It is arranged that when not
	   inlined these function are always statically linked; that way a
	   dynamically-linked executable always encodes the version number
	   corresponding to the data structures it uses, so the `x' functions
	   in the shared library can adapt without needing to recompile all
	   callers. 
	*/
	/* Wrappers for stat and mknod system calls.  */
	extern int __fxstat(int __ver, int __fildes, struct stat * __stat_buf);
	extern int __xstat(int __ver, const char * __filename, struct stat * __stat_buf);
	extern int __lxstat(int __ver, const char * __filename, struct stat * __stat_buf);
	extern int __fxstatat(int __ver, int __fildes, const char * __filename, struct stat * __stat_buf, int __flag);
	extern int __xmknod(int __ver, const char * __path, __mode_t __mode, __dev_t * __dev);
	extern int __xmknodat(int __ver, int __fd, const char * __path, __mode_t __mode, __dev_t * __dev);
	/*
	Define ISO C stdio on top of C++ iostreams.
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
	
		ISO C99 Standard: 7.19 Input/output	<stdio.h>
	
	*/
	/*
	Handle feature test macros at the start of a header.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
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
	This header is internal to glibc and should not be included outside
	   of glibc headers.  Headers including it must define
	   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
	   cannot have multiple include guards because ISO C feature test
	   macros depend on the definition of the macro when an affected
	   header is included, not when the first system header is
	   included. 
	*/
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
	ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-4:2015 defines the
	   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro. 
	*/
	/*
	ISOIEC TS 18661-3:2015 defines the
	   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
	*/
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.15  Variable arguments  <stdarg.h>
	
	*/
	/* Define __gnuc_va_list.  */
	typedef __builtin_va_list __gnuc_va_list;
	/*
	Define the standard macros for the user,
	   if this invocation was from the user program. 
	*/
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	Integral type unchanged by default argument promotions that can
	   hold any value corresponding to members of the extended character
	   set, as well as at least one value that does not correspond to any
	   member of the extended character set. 
	*/
	/* Conversion state information.  */
	union named_avimod_c_3115
	{
		unsigned int __wch;
		char __wchb[4];
	};
	
	struct named_avimod_c_3107
	{
		int __count;
		union named_avimod_c_3115 __value;
	};
	
	/* Value so far.  */
	typedef struct named_avimod_c_3107 __mbstate_t;
	/*
	The tag name of this struct is _G_fpos_t to preserve historic
	   C++ mangled names for functions taking fpos_t arguments.
	   That name should not be used in new code. 
	*/
	struct _G_fpos_t
	{
		__off_t __pos;
		__mbstate_t __state;
	};
	
	typedef struct _G_fpos_t __fpos_t;
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	The tag name of this struct is _G_fpos64_t to preserve historic
	   C++ mangled names for functions taking fpos_t andor fpos64_t
	   arguments.  That name should not be used in new code. 
	*/
	struct _G_fpos64_t
	{
		__off64_t __pos;
		__mbstate_t __state;
	};
	
	typedef struct _G_fpos64_t __fpos64_t;
	struct _IO_FILE;
	
	typedef struct _IO_FILE __FILE;
	struct _IO_FILE;
	
	/* The opaque type of streams.  This is the definition used elsewhere.  */
	typedef struct _IO_FILE FILE;
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
	Caution: The contents of this file are not part of the official
	   stdio.h API.  However, much of it is part of the officialbinary*
	   interface, and therefore cannot be changed. 
	*/
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	struct _IO_FILE;
	
	struct _IO_marker;
	
	struct _IO_codecvt;
	
	struct _IO_wide_data;
	
	/*
	During the build of glibc itself, _IO_lock_t will already have been
	   defined by internal headers. 
	*/
	typedef void _IO_lock_t;
	/*
	The tag name of this struct is _IO_FILE to preserve historic
	   C++ mangled names for functions taking FILE arguments.
	   That name should not be used in new code. 
	*/
	struct _IO_FILE
	{
		int _flags;
		/* High-order word is _IO_MAGIC; rest is flags. */ 
		/* The following pointers correspond to the C++ streambuf protocol. */ 
		char * _IO_read_ptr;
		/* Current read pointer */ 
		char * _IO_read_end;
		/* End of get area. */ 
		char * _IO_read_base;
		/* Start of putback+get area. */ 
		char * _IO_write_base;
		/* Start of put area. */ 
		char * _IO_write_ptr;
		/* Current put pointer. */ 
		char * _IO_write_end;
		/* End of put area. */ 
		char * _IO_buf_base;
		/* Start of reserve area. */ 
		char * _IO_buf_end;
		/* End of reserve area. */ 
		/* The following fields are used to support backing up and undo. */ 
		char * _IO_save_base;
		/* Pointer to start of non-current get area. */ 
		char * _IO_backup_base;
		/* Pointer to first valid character of backup area */ 
		char * _IO_save_end;
		/* Pointer to end of non-current get area. */ 
		struct _IO_marker * _markers;
		struct _IO_FILE * _chain;
		int _fileno;
		int _flags2;
		__off_t _old_offset;
		/* This used to be _offset but it's too small.  */ 
		/* 1+column number of pbase(); 0 is unknown. */ 
		unsigned short _cur_column;
		signed char _vtable_offset;
		char _shortbuf[1];
		_IO_lock_t * _lock;
		__off64_t _offset;
		/* Wide character stream stuff.  */ 
		struct _IO_codecvt * _codecvt;
		struct _IO_wide_data * _wide_data;
		struct _IO_FILE * _freeres_list;
		void * _freeres_buf;
		size_t __pad5;
		int _mode;
		/* Make sure we don't get into trouble again.  */ 
		char _unused2[(((15*sizeof (int))-(4*sizeof (void * )))-sizeof (size_t))];
	};
	
	struct _IO_FILE;
	
	/* These macros are used by bitsstdio.h and internal headers.  */
	/* Many more flag bits are defined internally.  */
	typedef __gnuc_va_list va_list;
	/* The type of the second argument to `fgetpos' and `fsetpos'.  */
	typedef __fpos_t fpos_t;
	/* The possibilities for the third argument to `setvbuf'.  */
	/* Default buffer size.  */
	/*
	The value returned by fgetc and similar functions to indicate the
	   end of the file. 
	*/
	/*
	The possibilities for the third argument to `fseek'.
	   These values should not be changed. 
	*/
	/* Default path prefix for `tempnam' and `tmpnam'.  */
	/*
	Get the values:
	   L_tmpnam	How long an array of chars must be to be passed to `tmpnam'.
	   TMP_MAX	The minimum number of unique filenames generated by tmpnam
			(and tempnam when it uses tmpnam's name space),
			or tempnam (the two are separate).
	   L_ctermid	How long an array to pass to `ctermid'.
	   L_cuserid	How long an array to pass to `cuserid'.
	   FOPEN_MAX	Minimum number of files that can be open at once.
	   FILENAME_MAX	Maximum length of a filename. 
	*/
	/*
	Copyright (C) 1994-2018 Free Software Foundation, Inc.
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
	/* Standard streams.  */
	extern FILE * stdin;
	/* Standard input stream.  */
	extern FILE * stdout;
	/* Standard output stream.  */
	extern FILE * stderr;
	/* Standard error output stream.  */
	/* C89C99 say they're macros.  Make them happy.  */
	/* Remove file FILENAME.  */
	extern int remove(const char * __filename);
	/* Rename file OLD to NEW.  */
	extern int rename(const char * __old, const char * __new);
	/* Rename file OLD relative to OLDFD to NEW relative to NEWFD.  */
	extern int renameat(int __oldfd, const char * __old, int __newfd, const char * __new);
	/*
	Create a temporary file and open it readwrite.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern FILE *tmpfile(void );
	/* Generate a temporary filename.  */
	extern char *tmpnam(char * __s);
	/*
	This is the reentrant variant of `tmpnam'.  The only difference is
	   that it does not allow S to be NULL. 
	*/
	extern char *tmpnam_r(char * __s);
	/*
	Generate a unique temporary filename using up to five characters of PFX
	   if it is not NULL.  The directory to put this file in is searched for
	   as follows: First the environment variable "TMPDIR" is checked.
	   If it contains the name of a writable directory, that directory is used.
	   If not and if DIR is not NULL, that value is checked.  If that fails,
	   P_tmpdir is tried and finally "tmp".  The storage for the filename
	   is allocated by `malloc'. 
	*/
	extern char *tempnam(const char * __dir, const char * __pfx);
	/*
	Close STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fclose(FILE * __stream);
	/*
	Flush STREAM, or all streams if STREAM is NULL.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fflush(FILE * __stream);
	/*
	Faster versions when locking is not required.
	
	   This function is not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation it is a cancellation point and
	   therefore not marked with __THROW. 
	*/
	extern int fflush_unlocked(FILE * __stream);
	/*
	Open a file and create a new stream for it.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern FILE *fopen(const char * __filename, const char * __modes);
	/*
	Open a file, replacing an existing stream with it.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern FILE *freopen(const char * __filename, const char * __modes, FILE * __stream);
	/* Create a new stream that refers to an existing system file descriptor.  */
	extern FILE *fdopen(int __fd, const char * __modes);
	/* Create a new stream that refers to a memory buffer.  */
	extern FILE *fmemopen(void * __s, size_t __len, const char * __modes);
	/*
	Open a stream that writes into a malloc'd buffer that is expanded as
	   necessary.BUFLOC and *SIZELOC are updated with the buffer's location
	   and the number of characters written on fflush or fclose. 
	*/
	extern FILE *open_memstream(char * * __bufloc, size_t * __sizeloc);
	/*
	If BUF is NULL, make STREAM unbuffered.
	   Else make it use buffer BUF, of size BUFSIZ. 
	*/
	extern void setbuf(FILE * __stream, char * __buf);
	/*
	Make STREAM use buffering mode MODE.
	   If BUF is not NULL, use N bytes of it for buffering;
	   else allocate an internal buffer N bytes long. 
	*/
	extern int setvbuf(FILE * __stream, char * __buf, int __modes, size_t __n);
	/*
	If BUF is NULL, make STREAM unbuffered.
	   Else make it use SIZE bytes of BUF for buffering. 
	*/
	extern void setbuffer(FILE * __stream, char * __buf, size_t __size);
	/* Make STREAM line-buffered.  */
	extern void setlinebuf(FILE * __stream);
	/*
	Write formatted output to STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fprintf(FILE * __stream, const char * __format,  ...);
	/*
	Write formatted output to stdout.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int printf(const char * __format,  ...);
	/* Write formatted output to S.  */
	extern int sprintf(char * __s, const char * __format,  ...);
	/*
	Write formatted output to S from argument list ARG.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int vfprintf(FILE * __s, const char * __format, __gnuc_va_list __arg);
	/*
	Write formatted output to stdout from argument list ARG.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int vprintf(const char * __format, __gnuc_va_list __arg);
	/* Write formatted output to S from argument list ARG.  */
	extern int vsprintf(char * __s, const char * __format, __gnuc_va_list __arg);
	/* Maximum chars of output to write in MAXLEN.  */
	extern int snprintf(char * __s, size_t __maxlen, const char * __format,  ...);
	extern int vsnprintf(char * __s, size_t __maxlen, const char * __format, __gnuc_va_list __arg);
	/* Write formatted output to a file descriptor.  */
	extern int vdprintf(int __fd, const char * __fmt, __gnuc_va_list __arg);
	extern int dprintf(int __fd, const char * __fmt,  ...);
	/*
	Read formatted input from STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fscanf(FILE * __stream, const char * __format,  ...);
	/*
	Read formatted input from stdin.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int scanf(const char * __format,  ...);
	/* Read formatted input from S.  */
	extern int sscanf(const char * __s, const char * __format,  ...);
	/*
	For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
	   GNU extension which conflicts with valid %a followed by letter
	   s, S or [. 
	*/
	extern int fscanf(FILE * __stream, const char * __format,  ...);
	extern int scanf(const char * __format,  ...);
	extern int sscanf(const char * __s, const char * __format,  ...);
	/*
	Read formatted input from S into argument list ARG.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int vfscanf(FILE * __s, const char * __format, __gnuc_va_list __arg);
	/*
	Read formatted input from stdin into argument list ARG.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int vscanf(const char * __format, __gnuc_va_list __arg);
	/* Read formatted input from S into argument list ARG.  */
	extern int vsscanf(const char * __s, const char * __format, __gnuc_va_list __arg);
	/*
	For strict ISO C99 or POSIX compliance disallow %as, %aS and %a[
	   GNU extension which conflicts with valid %a followed by letter
	   s, S or [. 
	*/
	extern int vfscanf(FILE * __s, const char * __format, __gnuc_va_list __arg);
	extern int vscanf(const char * __format, __gnuc_va_list __arg);
	extern int vsscanf(const char * __s, const char * __format, __gnuc_va_list __arg);
	/*
	Read a character from STREAM.
	
	   These functions are possible cancellation points and therefore not
	   marked with __THROW. 
	*/
	extern int fgetc(FILE * __stream);
	extern int getc(FILE * __stream);
	/*
	Read a character from stdin.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int getchar(void );
	/*
	These are defined in POSIX.1:1996.
	
	   These functions are possible cancellation points and therefore not
	   marked with __THROW. 
	*/
	extern int getc_unlocked(FILE * __stream);
	extern int getchar_unlocked(void );
	/*
	Faster version when locking is not necessary.
	
	   This function is not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation it is a cancellation point and
	   therefore not marked with __THROW. 
	*/
	extern int fgetc_unlocked(FILE * __stream);
	/*
	Write a character to STREAM.
	
	   These functions are possible cancellation points and therefore not
	   marked with __THROW.
	
	   These functions is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fputc(int __c, FILE * __stream);
	extern int putc(int __c, FILE * __stream);
	/*
	Write a character to stdout.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int putchar(int __c);
	/*
	Faster version when locking is not necessary.
	
	   This function is not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation it is a cancellation point and
	   therefore not marked with __THROW. 
	*/
	extern int fputc_unlocked(int __c, FILE * __stream);
	/*
	These are defined in POSIX.1:1996.
	
	   These functions are possible cancellation points and therefore not
	   marked with __THROW. 
	*/
	extern int putc_unlocked(int __c, FILE * __stream);
	extern int putchar_unlocked(int __c);
	/* Get a word (int) from STREAM.  */
	extern int getw(FILE * __stream);
	/* Write a word (int) to STREAM.  */
	extern int putw(int __w, FILE * __stream);
	/*
	Get a newline-terminated string of finite length from STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern char *fgets(char * __s, int __n, FILE * __stream);
	/*
	Read up to (and including) a DELIMITER from STREAM intoLINEPTR
	   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
	   NULL), pointing to *N characters of space.  It is realloc'd as
	   necessary.  Returns the number of characters read (not including the
	   null terminator), or -1 on error or EOF.
	
	   These functions are not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation they are cancellation points and
	   therefore not marked with __THROW. 
	*/
	extern __ssize_t __getdelim(char * * __lineptr, size_t * __n, int __delimiter, FILE * __stream);
	extern __ssize_t getdelim(char * * __lineptr, size_t * __n, int __delimiter, FILE * __stream);
	/*
	Like `getdelim', but reads up to a newline.
	
	   This function is not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation it is a cancellation point and
	   therefore not marked with __THROW. 
	*/
	extern __ssize_t getline(char * * __lineptr, size_t * __n, FILE * __stream);
	/*
	Write a string to STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fputs(const char * __s, FILE * __stream);
	/*
	Write a string, followed by a newline, to stdout.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int puts(const char * __s);
	/*
	Push a character back onto the input buffer of STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int ungetc(int __c, FILE * __stream);
	/*
	Read chunks of generic data from STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern size_t fread(void * __ptr, size_t __size, size_t __n, FILE * __stream);
	/*
	Write chunks of generic data to STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern size_t fwrite(const void * __ptr, size_t __size, size_t __n, FILE * __s);
	/*
	Faster versions when locking is not necessary.
	
	   These functions are not part of POSIX and therefore no official
	   cancellation point.  But due to similarity with an POSIX interface
	   or due to the implementation they are cancellation points and
	   therefore not marked with __THROW. 
	*/
	extern size_t fread_unlocked(void * __ptr, size_t __size, size_t __n, FILE * __stream);
	extern size_t fwrite_unlocked(const void * __ptr, size_t __size, size_t __n, FILE * __stream);
	/*
	Seek to a certain position on STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fseek(FILE * __stream, long int __off, int __whence);
	/*
	Return the current position of STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern long int ftell(FILE * __stream);
	/*
	Rewind to the beginning of STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern void rewind(FILE * __stream);
	/*
	The Single Unix Specification, Version 2, specifies an alternative,
	   more adequate interface for the two functions above which deal with
	   file offset.  `long int' is not the right type.  These definitions
	   are originally defined in the Large File Support API. 
	*/
	/*
	Seek to a certain position on STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fseeko(FILE * __stream, __off_t __off, int __whence);
	/*
	Return the current position of STREAM.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern __off_t ftello(FILE * __stream);
	/*
	Get STREAM's position.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fgetpos(FILE * __stream, fpos_t * __pos);
	/*
	Set STREAM's position.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int fsetpos(FILE * __stream, const fpos_t * __pos);
	/* Clear the error and EOF indicators for STREAM.  */
	extern void clearerr(FILE * __stream);
	/* Return the EOF indicator for STREAM.  */
	extern int feof(FILE * __stream);
	/* Return the error indicator for STREAM.  */
	extern int ferror(FILE * __stream);
	/* Faster versions when locking is not required.  */
	extern void clearerr_unlocked(FILE * __stream);
	extern int feof_unlocked(FILE * __stream);
	extern int ferror_unlocked(FILE * __stream);
	/*
	Print a message describing the meaning of the value of errno.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern void perror(const char * __s);
	/*
	Provide the declarations for `sys_errlist' and `sys_nerr' if they
	   are available on this system.  Even if available, these variables
	   should not be used directly.  The `strerror' function provides
	   all the necessary functionality. 
	*/
	/*
	Declare sys_errlist and sys_nerr, or don't.  Compatibility (do) version.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
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
	/* sys_errlist and sys_nerr are deprecated.  Use strerror instead.  */
	extern int sys_nerr;
	extern const char * const sys_errlist[];
	/* Return the system file descriptor for STREAM.  */
	extern int fileno(FILE * __stream);
	/* Faster version when locking is not required.  */
	extern int fileno_unlocked(FILE * __stream);
	/*
	Create a new stream connected to a pipe running the given command.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern FILE *popen(const char * __command, const char * __modes);
	/*
	Close a stream opened by popen and return the status of its child.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int pclose(FILE * __stream);
	/* Return the name of the controlling terminal.  */
	extern char *ctermid(char * __s);
	/* These are defined in POSIX.1:1996.  */
	/* Acquire ownership of STREAM.  */
	extern void flockfile(FILE * __stream);
	/*
	Try to acquire ownership of STREAM but do not block if it is not
	   possible. 
	*/
	extern int ftrylockfile(FILE * __stream);
	/* Relinquish the ownership granted for STREAM.  */
	extern void funlockfile(FILE * __stream);
	/*
	Slow-path routines used by the optimized inline functions in
	   bitsstdio.h. 
	*/
	extern int __uflow(FILE * );
	extern int __overflow(FILE * , int );
	/*
	If we are compiling with optimizing read this file.  It contains
	   several optimizing inline functions and macros. 
	*/
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
	
		POSIX Standard: 6.5 File Control Operations	<fcntl.h>
	
	*/
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
	/* This must be early so <bitsfcntl.h> can define types winningly.  */
	/* Get __mode_t, __dev_t and __off_t  . */
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	Get the definitions of O_, F_*, FD_*: all the
	   numbers and flag bits for `open', `fcntl', et al. 
	*/
	/*
	O_, F_*, FD_* bit values for Linux/x86.
	   Copyright (C) 2001-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	/* Not necessary, we always have 64-bit offsets.  */
	struct flock
	{
		short int l_type;
		/* Type of lock: F_RDLCK, F_WRLCK, or F_UNLCK.	*/ 
		short int l_whence;
		/* Where `l_start' is relative to (like `lseek').  */ 
		__off_t l_start;
		/* Offset where the lock begins.  */ 
		__off_t l_len;
		/* Size of the locked area; zero means until EOF.  */ 
		__pid_t l_pid;
	};
	
	/* Process holding the lock.  */
	/* Include generic Linux declarations.  */
	/*
	O_, F_*, FD_* bit values for Linux.
	   Copyright (C) 2001-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	This file contains shared definitions between Linux architectures
	   and is included by <bitsfcntl.h> to declare them.  The various
	   #ifndef cases allow the architecture specific file to define those
	   values with different values.
	
	   A minimal <bits/fcntl.h> contains just:
	
   struct flock {...}
	   #ifdef __USE_LARGEFILE64
   struct flock64 {...}
	   #endif
	   #include <bits/fcntl-linux.h>
	
	*/
	/* openfcntl.  */
	/*
	open file description locks.
	
	   Usually record locks held by a process are released onany* close and are
	   not inherited across a fork.
	
	   These cmd values will set locks that conflict with process-associated record
	   locks, but are "owned" by the opened file description, not the process.
	   This means that they are inherited across fork or clone with CLONE_FILES
	   like BSD (flock) locks, and they are only released automatically when the
	   last reference to the the file description against which they were acquired
	   is put.
	*/
	/*
	For now, Linux has no separate synchronicity options for read
	   operations.  We define O_RSYNC therefore as the same as O_SYNC
	   since this is a superset. 
	*/
	/* Values for the second argument to `fcntl'.  */
	/* For F_[GET|SET]FD.  */
	/* For posix fcntl() and `l_type' field of a `struct flock' for lockf().  */
	/* For old implementation of BSD flock.  */
	/* Operations for BSD flock, also used by the kernel implementation.  */
	/*
	Define some more compatibility macros to be backward compatible with
	   BSD systems which did not managed to hide these kernel macros. 
	*/
	/* Advise to `posix_fadvise'.  */
	/* Values for `at' functions.  */
	/*
	Detect if open needs mode as a third argument (or for openat as a fourth
	   argument). 
	*/
	/*
	POSIX.1-2001 specifies that these types are defined by <fcntl.h>.
	   Earlier POSIX standards permitted any type ending in `_t' to be defined
	   by any POSIX header, so we don't conditionalize the definitions here. 
	*/
	/* For XPG all symbols from <sysstat.h> should also be available.  */
	/* NB: Include guard matches what <linuxtime.h> uses.  */
	/*
	Copyright (C) 1999-2018 Free Software Foundation, Inc.
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
	/* Protection bits.  */
	/* Save swapped text after use (sticky bit).  This is pretty well obsolete.  */
	/* Read, write, and execute by owner.  */
	/* Read, write, and execute by group.  */
	/* Read, write, and execute by others.  */
	/*
	Values for the second argument to access.
	   These may be OR'd together. 
	*/
	/* XPG wants the following symbols.   <stdio.h> has the same definitions.  */
	/*
	Do the file control operation described by CMD on FD.
	   The remaining arguments are interpreted depending on CMD.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int fcntl(int __fd, int __cmd,  ...);
	/*
	Open FILE and return a new file descriptor for it, or -1 on error.
	   OFLAG determines the type of access used.  If O_CREAT or O_TMPFILE is set
	   in OFLAG, the third argument is taken as a `mode_t', the mode of the
	   created file.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int open(const char * __file, int __oflag,  ...);
	/*
	Similar to `open' but a relative path name is interpreted relative to
	   the directory for which FD is a descriptor.
	
	   NOTE: some other `openat' implementation support additional functionality
	   through this interface, especially using the O_XATTR flag.  This is not
	   yet supported here.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int openat(int __fd, const char * __file, int __oflag,  ...);
	/*
	Create and open FILE, with mode MODE.  This takes an `int' MODE
	   argument because that is what `mode_t' will be widened to.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int creat(const char * __file, mode_t __mode);
	/*
	NOTE: These declarations also appear in <unistd.h>; be sure to keep both
	   files consistent.  Some systems have them there and some here, and some
	   software depends on the macros being defined without including both. 
	*/
	/*
	`lockf' is a simpler interface to the locking facilities of `fcntl'.
	   LEN is always relative to the current file position.
	   The CMD argument is one of the following. 
	*/
	extern int lockf(int __fd, int __cmd, off_t __len);
	/*
	Advice the system about the expected behaviour of the application with
	   respect to the file associated with FD. 
	*/
	extern int posix_fadvise(int __fd, off_t __offset, off_t __len, int __advise);
	/*
	Reserve storage for the data of the file associated with FD.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int posix_fallocate(int __fd, off_t __offset, off_t __len);
	/* Define some inlines helping to catch common problems.  */
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
	
		POSIX Standard: 2.10 Symbolic Constants		<unistd.h>
	
	*/
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
	These may be used to determine what facilities are present at compile time.
	   Their values can be obtained at run time from `sysconf'. 
	*/
	/* POSIX Standard approved as ISOIEC 9945-1 as of September 2008.  */
	/*
	These are not #ifdef __USE_POSIX2 because they are
	   in the theoretically application-owned namespace. 
	*/
	/* The utilities on GNU systems also correspond to this version.  */
	/* The utilities on GNU systems also correspond to this version.  */
	/* This symbol was required until the 2001 edition of POSIX.  */
	/*
	If defined, the implementation supports the
	   C Language Bindings Option. 
	*/
	/*
	If defined, the implementation supports the
	   C Language Development Utilities Option. 
	*/
	/*
	If defined, the implementation supports the
	   Software Development Utilities Option. 
	*/
	/*
	If defined, the implementation supports the
	   creation of locales with the localedef utility. 
	*/
	/* XOpen version number to which the library conforms.  It is selectable.  */
	/* Commands and utilities from XPG4 are available.  */
	/* We are compatible with the old published standards as well.  */
	/* The XOpen Unix extensions are available.  */
	/*
	The enhanced internationalization capabilities according to XPG4.2
	   are present. 
	*/
	/* The legacy interfaces are also available.  */
	/*
	Get values of POSIX options:
	
	   If these symbols are defined, the corresponding features are
	   always available.  If not, they may be available sometimes.
	   The current values can be obtained with `sysconf'.
	
	   _POSIX_JOB_CONTROL		Job control is supported.
	   _POSIX_SAVED_IDS		Processes have a saved set-user-ID
					and a saved set-group-ID.
	   _POSIX_REALTIME_SIGNALS	Real-time, queued signals are supported.
	   _POSIX_PRIORITY_SCHEDULING	Priority scheduling is supported.
	   _POSIX_TIMERS		POSIX.4 clocks and timers are supported.
	   _POSIX_ASYNCHRONOUS_IO	Asynchronous IO is supported.
	   _POSIX_PRIORITIZED_IO	Prioritized asynchronous I/O is supported.
	   _POSIX_SYNCHRONIZED_IO	Synchronizing file data is supported.
	   _POSIX_FSYNC			The fsync function is present.
	   _POSIX_MAPPED_FILES		Mapping of files to memory is supported.
	   _POSIX_MEMLOCK		Locking of all memory is supported.
	   _POSIX_MEMLOCK_RANGE		Locking of ranges of memory is supported.
	   _POSIX_MEMORY_PROTECTION	Setting of memory protections is supported.
	   _POSIX_MESSAGE_PASSING	POSIX.4 message queues are supported.
	   _POSIX_SEMAPHORES		POSIX.4 counting semaphores are supported.
	   _POSIX_SHARED_MEMORY_OBJECTS	POSIX.4 shared memory objects are supported.
	   _POSIX_THREADS		POSIX.1c pthreads are supported.
	   _POSIX_THREAD_ATTR_STACKADDR	Thread stack address attribute option supported.
	   _POSIX_THREAD_ATTR_STACKSIZE	Thread stack size attribute option supported.
	   _POSIX_THREAD_SAFE_FUNCTIONS	Thread-safe functions are supported.
	   _POSIX_THREAD_PRIORITY_SCHEDULING
					POSIX.1c thread execution scheduling supported.
	   _POSIX_THREAD_PRIO_INHERIT	Thread priority inheritance option supported.
	   _POSIX_THREAD_PRIO_PROTECT	Thread priority protection option supported.
	   _POSIX_THREAD_PROCESS_SHARED	Process-shared synchronization supported.
	   _POSIX_PII			Protocol-independent interfaces are supported.
	   _POSIX_PII_XTI		XTI protocol-indep. interfaces are supported.
	   _POSIX_PII_SOCKET		Socket protocol-indep. interfaces are supported.
	   _POSIX_PII_INTERNET		Internet family of protocols supported.
	   _POSIX_PII_INTERNET_STREAM	Connection-mode Internet protocol supported.
	   _POSIX_PII_INTERNET_DGRAM	Connectionless Internet protocol supported.
	   _POSIX_PII_OSI		ISO/OSI family of protocols supported.
	   _POSIX_PII_OSI_COTS		Connection-mode ISO/OSI service supported.
	   _POSIX_PII_OSI_CLTS		Connectionless ISO/OSI service supported.
	   _POSIX_POLL			Implementation supports `poll' function.
	   _POSIX_SELECT		Implementation supports `select' and `pselect'.
	
	   _XOPEN_REALTIME		X/Open realtime support is available.
	   _XOPEN_REALTIME_THREADS	X/Open realtime thread support is available.
	   _XOPEN_SHM			Shared memory interface according to XPG4.2.
	
	   _XBS5_ILP32_OFF32		Implementation provides environment with 32-bit
					int, long, pointer, and off_t types.
	   _XBS5_ILP32_OFFBIG		Implementation provides environment with 32-bit
					int, long, and pointer and off_t with at least
					64 bits.
	   _XBS5_LP64_OFF64		Implementation provides environment with 32-bit
					int, and 64-bit long, pointer, and off_t types.
	   _XBS5_LPBIG_OFFBIG		Implementation provides environment with at
					least 32 bits int and long, pointer, and off_t
					with at least 64 bits.
	
	   If any of these symbols is defined as -1, the corresponding option is not
	   true for any file.  If any is defined as other than -1, the corresponding
	   option is true for all files.  If a symbol is not defined at all, the value
	   for a specific file can be obtained from `pathconf' and `fpathconf'.
	
	   _POSIX_CHOWN_RESTRICTED	Only the super user can use `chown' to change
					the owner of a file.  `chown' can only be used
					to change the group ID of a file to a group of
					which the calling process is a member.
	   _POSIX_NO_TRUNC		Pathname components longer than
					NAME_MAX generate an error.
	   _POSIX_VDISABLE		If defined, if the value of an element of the
					`c_cc' member of `struct termios' is
					_POSIX_VDISABLE, no character will have the
					effect associated with that element.
	   _POSIX_SYNC_IO		Synchronous I/O may be performed.
	   _POSIX_ASYNC_IO		Asynchronous I/O may be performed.
	   _POSIX_PRIO_IO		Prioritized Asynchronous I/O may be performed.
	
	   Support for the Large File Support interface is not generally available.
	   If it is available the following constants are defined to one.
	   _LFS64_LARGEFILE		Low-level I/O supports large files.
	   _LFS64_STDIO			Standard I/O supports large files.
	  
	*/
	/*
	Define POSIX options for Linux.
	   Copyright (C) 1996-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it andor
	   modify it under the terms of the GNU Lesser General Public License as
	   published by the Free Software Foundation; either version 2.1 of the
	   License, or (at your option) any later version.
	
	   The GNU C Library is distributed in the hope that it will be useful,
	   but WITHOUT ANY WARRANTY; without even the implied warranty of
	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	   Lesser General Public License for more details.
	
	   You should have received a copy of the GNU Lesser General Public
	   License along with the GNU C Library; see the file COPYING.LIB.  If
	   not, see <http:www.gnu.org/licenses/>. 
	*/
	/* Job control is supported.  */
	/* Processes have a saved set-user-ID and a saved set-group-ID.  */
	/* Priority scheduling is supported.  */
	/* Synchronizing file data is supported.  */
	/* The fsync function is present.  */
	/* Mapping of files to memory is supported.  */
	/* Locking of all memory is supported.  */
	/* Locking of ranges of memory is supported.  */
	/* Setting of memory protections is supported.  */
	/* Some filesystems allow all users to change file ownership.  */
	/*
	`c_cc' member of 'struct termios' structure can be disabled by
	   using the value _POSIX_VDISABLE. 
	*/
	/* Filenames are not silently truncated.  */
	/* XOpen realtime support is available.  */
	/* XOpen thread realtime support is available.  */
	/* XPG4.2 shared memory is supported.  */
	/* Tell we have POSIX threads.  */
	/* We have the reentrant functions described in POSIX.  */
	/* We provide priority scheduling for threads.  */
	/* We support user-defined stack sizes.  */
	/* We support user-defined stacks.  */
	/* We support priority inheritence.  */
	/*
	We support priority protection, though only for non-robust
	   mutexes. 
	*/
	/* We support priority inheritence for robust mutexes.  */
	/* We do not support priority protection for robust mutexes.  */
	/* We support POSIX.1b semaphores.  */
	/* Real-time signals are supported.  */
	/* We support asynchronous IO.  */
	/* Alternative name for Unix98.  */
	/* Support for prioritization is also available.  */
	/* The LFS support in asynchronous IO is also available.  */
	/* The rest of the LFS is also available.  */
	/* POSIX shared memory objects are implemented.  */
	/* CPU-time clocks support needs to be checked at runtime.  */
	/* Clock support in threads must be also checked at runtime.  */
	/* GNU libc provides regular expression handling.  */
	/* ReaderWriter locks are available.  */
	/* We have a POSIX shell.  */
	/* We support the Timeouts option.  */
	/* We support spinlocks.  */
	/* The `spawn' function family is supported.  */
	/* We have POSIX timers.  */
	/* The barrier functions are available.  */
	/* POSIX message queues are available.  */
	/* Thread process-shared synchronization is supported.  */
	/* The monotonic clock might be available.  */
	/* The clock selection interfaces are available.  */
	/* Advisory information interfaces are available.  */
	/* IPv6 support is available.  */
	/* Raw socket support is available.  */
	/* We have at least one terminal.  */
	/* Neither process nor thread sporadic server interfaces is available.  */
	/* trace.h is not available.  */
	/* Typed memory objects are not available.  */
	/* Get the environment definitions from Unix98.  */
	/*
	Copyright (C) 1999-2018 Free Software Foundation, Inc.
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
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/*
	This header should define the following symbols under the described
	   situations.  A value `1' means that the model is always supported,
	   `-1' means it is never supported.  Undefined means it cannot be
	   statically decided.
	
	   _POSIX_V7_ILP32_OFF32   32bit int, long, pointers, and off_t type
	   _POSIX_V7_ILP32_OFFBIG  32bit int, long, and pointers and larger off_t type
	
	   _POSIX_V7_LP64_OFF32	   64bit long and pointers and 32bit off_t type
	   _POSIX_V7_LPBIG_OFFBIG  64bit long and pointers and large off_t type
	
	   The macros _POSIX_V6_ILP32_OFF32, _POSIX_V6_ILP32_OFFBIG,
	   _POSIX_V6_LP64_OFF32, _POSIX_V6_LPBIG_OFFBIG, _XBS5_ILP32_OFF32,
	   _XBS5_ILP32_OFFBIG, _XBS5_LP64_OFF32, and _XBS5_LPBIG_OFFBIG were
	   used in previous versions of the Unix standard and are available
	   only for compatibility.
	
	*/
	/*
	Environments with 32-bit wide pointers are optionally provided.
	   Therefore following macros aren't defined:
	   # undef _POSIX_V7_ILP32_OFF32
	   # undef _POSIX_V7_ILP32_OFFBIG
	   # undef _POSIX_V6_ILP32_OFF32
	   # undef _POSIX_V6_ILP32_OFFBIG
	   # undef _XBS5_ILP32_OFF32
	   # undef _XBS5_ILP32_OFFBIG
	   and users need to check at runtime. 
	*/
	/*
	We also have no use (for now) for an environment with bigger pointers
	   and offsets. 
	*/
	/* By default we have 64-bit wide `long int', pointers and `off_t'.  */
	/* Standard file descriptors.  */
	/* All functions that are not declared anywhere else.  */
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/*
	The Single Unix specification says that some more types are
	   available here. 
	*/
	typedef __useconds_t useconds_t;
	typedef __intptr_t intptr_t;
	typedef __socklen_t socklen_t;
	/*
	Values for the second argument to access.
	   These may be OR'd together. 
	*/
	/* Test for access to NAME using the real UID and real GID.  */
	extern int access(const char * __name, int __type);
	/*
	Test for access to FILE relative to the directory FD is open on.
	   If AT_EACCESS is set in FLAG, then use effective IDs like `eaccess',
	   otherwise use real IDs like `access'. 
	*/
	extern int faccessat(int __fd, const char * __file, int __type, int __flag);
	/* Values for the WHENCE argument to lseek.  */
	/* Old BSD names for the same constants; just for compatibility.  */
	/*
	Move FD's file position to OFFSET bytes from the
	   beginning of the file (if WHENCE is SEEK_SET),
	   the current position (if WHENCE is SEEK_CUR),
	   or the end of the file (if WHENCE is SEEK_END).
	   Return the new file position. 
	*/
	extern __off_t lseek(int __fd, __off_t __offset, int __whence);
	/*
	Close the file descriptor FD.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int close(int __fd);
	/*
	Read NBYTES into BUF from FD.  Return the
	   number read, -1 for errors or 0 for EOF.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern ssize_t read(int __fd, void * __buf, size_t __nbytes);
	/*
	Write N bytes of BUF to FD.  Return the number written, or -1.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern ssize_t write(int __fd, const void * __buf, size_t __n);
	/*
	Read NBYTES into BUF from FD at the given position OFFSET without
	   changing the file pointer.  Return the number read, -1 for errors
	   or 0 for EOF.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern ssize_t pread(int __fd, void * __buf, size_t __nbytes, __off_t __offset);
	/*
	Write N bytes of BUF to FD at the given position OFFSET without
	   changing the file pointer.  Return the number written, or -1.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern ssize_t pwrite(int __fd, const void * __buf, size_t __n, __off_t __offset);
	/*
	Create a one-way communication channel (pipe).
	   If successful, two file descriptors are stored in PIPEDES;
	   bytes written on PIPEDES[1] can be read from PIPEDES[0].
	   Returns 0 if successful, -1 if not. 
	*/
	extern int pipe(int __pipedes[2]);
	/*
	Schedule an alarm.  In SECONDS seconds, the process will get a SIGALRM.
	   If SECONDS is zero, any currently scheduled alarm will be cancelled.
	   The function returns the number of seconds remaining until the last
	   alarm scheduled would have signaled, or zero if there wasn't one.
	   There is no return value to indicate an error, but you can set `errno'
	   to 0 and check its value after calling `alarm', and this might tell you.
	   The signal may come late due to processor scheduling. 
	*/
	extern unsigned int alarm(unsigned int __seconds);
	/*
	Make the process sleep for SECONDS seconds, or until a signal arrives
	   and is not ignored.  The function returns the number of seconds less
	   than SECONDS which it actually slept (thus zero if it slept the full time).
	   If a signal handler does a `longjmp' or modifies the handling of the
	   SIGALRM signal while inside `sleep' call, the handling of the SIGALRM
	   signal afterwards is undefined.  There is no return value to indicate
	   error, but if `sleep' returns SECONDS, it probably didn't work.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern unsigned int sleep(unsigned int __seconds);
	/*
	Set an alarm to go off (generating a SIGALRM signal) in VALUE
	   microseconds.  If INTERVAL is nonzero, when the alarm goes off, the
	   timer is reset to go off every INTERVAL microseconds thereafter.
	   Returns the number of microseconds remaining before the alarm. 
	*/
	extern __useconds_t ualarm(__useconds_t __value, __useconds_t __interval);
	/*
	Sleep USECONDS microseconds, or until a signal arrives that is not blocked
	   or ignored.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int usleep(__useconds_t __useconds);
	/*
	Suspend the process until a signal arrives.
	   This always returns -1 and sets `errno' to EINTR.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int pause(void );
	/* Change the owner and group of FILE.  */
	extern int chown(const char * __file, __uid_t __owner, __gid_t __group);
	/* Change the owner and group of the file that FD is open on.  */
	extern int fchown(int __fd, __uid_t __owner, __gid_t __group);
	/*
	Change owner and group of FILE, if it is a symbolic
	   link the ownership of the symbolic link is changed. 
	*/
	extern int lchown(const char * __file, __uid_t __owner, __gid_t __group);
	/*
	Change the owner and group of FILE relative to the directory FD is open
	   on. 
	*/
	extern int fchownat(int __fd, const char * __file, __uid_t __owner, __gid_t __group, int __flag);
	/* Change the process's working directory to PATH.  */
	extern int chdir(const char * __path);
	/* Change the process's working directory to the one FD is open on.  */
	extern int fchdir(int __fd);
	/*
	Get the pathname of the current working directory,
	   and put it in SIZE bytes of BUF.  Returns NULL if the
	   directory couldn't be determined or SIZE was too small.
	   If successful, returns BUF.  In GNU, if BUF is NULL,
	   an array is allocated with `malloc'; the array is SIZE
	   bytes long, unless SIZE == 0, in which case it is as
	   big as necessary. 
	*/
	extern char *getcwd(char * __buf, size_t __size);
	/*
	Put the absolute pathname of the current working directory in BUF.
	   If successful, return BUF.  If not, put an error message in
	   BUF and return NULL.  BUF should be at least PATH_MAX bytes long. 
	*/
	extern char *getwd(char * __buf);
	/* Duplicate FD, returning a new file descriptor on the same file.  */
	extern int dup(int __fd);
	/* Duplicate FD to FD2, closing FD2 and making it open on the same file.  */
	extern int dup2(int __fd, int __fd2);
	/* NULL-terminated array of "NAME=VALUE" environment variables.  */
	extern char * * __environ;
	/*
	Replace the current process, executing PATH with arguments ARGV and
	   environment ENVP.  ARGV and ENVP are terminated by NULL pointers. 
	*/
	extern int execve(const char * __path, char * const __argv[], char * const __envp[]);
	/*
	Execute the file FD refers to, overlaying the running program image.
	   ARGV and ENVP are passed to the new program, as for `execve'. 
	*/
	extern int fexecve(int __fd, char * const __argv[], char * const __envp[]);
	/* Execute PATH with arguments ARGV and environment from `environ'.  */
	extern int execv(const char * __path, char * const __argv[]);
	/*
	Execute PATH with all arguments after PATH until a NULL pointer,
	   and the argument after that for environment. 
	*/
	extern int execle(const char * __path, const char * __arg,  ...);
	/*
	Execute PATH with all arguments after PATH until
	   a NULL pointer and environment from `environ'. 
	*/
	extern int execl(const char * __path, const char * __arg,  ...);
	/*
	Execute FILE, searching in the `PATH' environment variable if it contains
	   no slashes, with arguments ARGV and environment from `environ'. 
	*/
	extern int execvp(const char * __file, char * const __argv[]);
	/*
	Execute FILE, searching in the `PATH' environment variable if
	   it contains no slashes, with all arguments after FILE until a
	   NULL pointer and environment from `environ'. 
	*/
	extern int execlp(const char * __file, const char * __arg,  ...);
	/* Add INC to priority of the current process.  */
	extern int nice(int __inc);
	/* Terminate program execution with the low-order 8 bits of STATUS.  */
	extern void _exit(int __status);
	/*
	Get the `_PC_' symbols for the NAME argument to `pathconf' and `fpathconf';
	   the `_SC_*' symbols for the NAME argument to `sysconf';
	   and the `_CS_*' symbols for the NAME argument to `confstr'. 
	*/
	/*
	`sysconf', `pathconf', and `confstr' NAME values.  Generic version.
	   Copyright (C) 1993-2018 Free Software Foundation, Inc.
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
	/* Values for the NAME argument to `pathconf' and `fpathconf'.  */
enum avimod_c_7418 { _PC_LINK_MAX, _PC_MAX_CANON, _PC_MAX_INPUT, _PC_NAME_MAX, _PC_PATH_MAX, _PC_PIPE_BUF, _PC_CHOWN_RESTRICTED, _PC_NO_TRUNC, _PC_VDISABLE, _PC_SYNC_IO, _PC_ASYNC_IO, _PC_PRIO_IO, _PC_SOCK_MAXBUF, _PC_FILESIZEBITS, _PC_REC_INCR_XFER_SIZE, _PC_REC_MAX_XFER_SIZE, _PC_REC_MIN_XFER_SIZE, _PC_REC_XFER_ALIGN, _PC_ALLOC_SIZE_MIN, _PC_SYMLINK_MAX, _PC_2_SYMLINKS };
	/* Values for the argument to `sysconf'.  */
enum avimod_c_7485 { _SC_ARG_MAX, _SC_CHILD_MAX, _SC_CLK_TCK, _SC_NGROUPS_MAX, _SC_OPEN_MAX, _SC_STREAM_MAX, _SC_TZNAME_MAX, _SC_JOB_CONTROL, _SC_SAVED_IDS, _SC_REALTIME_SIGNALS, _SC_PRIORITY_SCHEDULING, _SC_TIMERS, _SC_ASYNCHRONOUS_IO, _SC_PRIORITIZED_IO, _SC_SYNCHRONIZED_IO, _SC_FSYNC, _SC_MAPPED_FILES, _SC_MEMLOCK, _SC_MEMLOCK_RANGE, _SC_MEMORY_PROTECTION, _SC_MESSAGE_PASSING, _SC_SEMAPHORES, _SC_SHARED_MEMORY_OBJECTS, _SC_AIO_LISTIO_MAX, _SC_AIO_MAX, _SC_AIO_PRIO_DELTA_MAX, _SC_DELAYTIMER_MAX, _SC_MQ_OPEN_MAX, _SC_MQ_PRIO_MAX, _SC_VERSION, _SC_PAGESIZE, _SC_RTSIG_MAX, _SC_SEM_NSEMS_MAX, _SC_SEM_VALUE_MAX, _SC_SIGQUEUE_MAX, _SC_TIMER_MAX, _SC_BC_BASE_MAX, _SC_BC_DIM_MAX, _SC_BC_SCALE_MAX, _SC_BC_STRING_MAX, _SC_COLL_WEIGHTS_MAX, _SC_EQUIV_CLASS_MAX, _SC_EXPR_NEST_MAX, _SC_LINE_MAX, _SC_RE_DUP_MAX, _SC_CHARCLASS_NAME_MAX, _SC_2_VERSION, _SC_2_C_BIND, _SC_2_C_DEV, _SC_2_FORT_DEV, _SC_2_FORT_RUN, _SC_2_SW_DEV, _SC_2_LOCALEDEF, _SC_PII, _SC_PII_XTI, _SC_PII_SOCKET, _SC_PII_INTERNET, _SC_PII_OSI, _SC_POLL, _SC_SELECT, _SC_UIO_MAXIOV, _SC_IOV_MAX = _SC_UIO_MAXIOV, _SC_PII_INTERNET_STREAM, _SC_PII_INTERNET_DGRAM, _SC_PII_OSI_COTS, _SC_PII_OSI_CLTS, _SC_PII_OSI_M, _SC_T_IOV_MAX, _SC_THREADS, _SC_THREAD_SAFE_FUNCTIONS, _SC_GETGR_R_SIZE_MAX, _SC_GETPW_R_SIZE_MAX, _SC_LOGIN_NAME_MAX, _SC_TTY_NAME_MAX, _SC_THREAD_DESTRUCTOR_ITERATIONS, _SC_THREAD_KEYS_MAX, _SC_THREAD_STACK_MIN, _SC_THREAD_THREADS_MAX, _SC_THREAD_ATTR_STACKADDR, _SC_THREAD_ATTR_STACKSIZE, _SC_THREAD_PRIORITY_SCHEDULING, _SC_THREAD_PRIO_INHERIT, _SC_THREAD_PRIO_PROTECT, _SC_THREAD_PROCESS_SHARED, _SC_NPROCESSORS_CONF, _SC_NPROCESSORS_ONLN, _SC_PHYS_PAGES, _SC_AVPHYS_PAGES, _SC_ATEXIT_MAX, _SC_PASS_MAX, _SC_XOPEN_VERSION, _SC_XOPEN_XCU_VERSION, _SC_XOPEN_UNIX, _SC_XOPEN_CRYPT, _SC_XOPEN_ENH_I18N, _SC_XOPEN_SHM, _SC_2_CHAR_TERM, _SC_2_C_VERSION, _SC_2_UPE, _SC_XOPEN_XPG2, _SC_XOPEN_XPG3, _SC_XOPEN_XPG4, _SC_CHAR_BIT, _SC_CHAR_MAX, _SC_CHAR_MIN, _SC_INT_MAX, _SC_INT_MIN, _SC_LONG_BIT, _SC_WORD_BIT, _SC_MB_LEN_MAX, _SC_NZERO, _SC_SSIZE_MAX, _SC_SCHAR_MAX, _SC_SCHAR_MIN, _SC_SHRT_MAX, _SC_SHRT_MIN, _SC_UCHAR_MAX, _SC_UINT_MAX, _SC_ULONG_MAX, _SC_USHRT_MAX, _SC_NL_ARGMAX, _SC_NL_LANGMAX, _SC_NL_MSGMAX, _SC_NL_NMAX, _SC_NL_SETMAX, _SC_NL_TEXTMAX, _SC_XBS5_ILP32_OFF32, _SC_XBS5_ILP32_OFFBIG, _SC_XBS5_LP64_OFF64, _SC_XBS5_LPBIG_OFFBIG, _SC_XOPEN_LEGACY, _SC_XOPEN_REALTIME, _SC_XOPEN_REALTIME_THREADS, _SC_ADVISORY_INFO, _SC_BARRIERS, _SC_BASE, _SC_C_LANG_SUPPORT, _SC_C_LANG_SUPPORT_R, _SC_CLOCK_SELECTION, _SC_CPUTIME, _SC_THREAD_CPUTIME, _SC_DEVICE_IO, _SC_DEVICE_SPECIFIC, _SC_DEVICE_SPECIFIC_R, _SC_FD_MGMT, _SC_FIFO, _SC_PIPE, _SC_FILE_ATTRIBUTES, _SC_FILE_LOCKING, _SC_FILE_SYSTEM, _SC_MONOTONIC_CLOCK, _SC_MULTI_PROCESS, _SC_SINGLE_PROCESS, _SC_NETWORKING, _SC_READER_WRITER_LOCKS, _SC_SPIN_LOCKS, _SC_REGEXP, _SC_REGEX_VERSION, _SC_SHELL, _SC_SIGNALS, _SC_SPAWN, _SC_SPORADIC_SERVER, _SC_THREAD_SPORADIC_SERVER, _SC_SYSTEM_DATABASE, _SC_SYSTEM_DATABASE_R, _SC_TIMEOUTS, _SC_TYPED_MEMORY_OBJECTS, _SC_USER_GROUPS, _SC_USER_GROUPS_R, _SC_2_PBS, _SC_2_PBS_ACCOUNTING, _SC_2_PBS_LOCATE, _SC_2_PBS_MESSAGE, _SC_2_PBS_TRACK, _SC_SYMLOOP_MAX, _SC_STREAMS, _SC_2_PBS_CHECKPOINT, _SC_V6_ILP32_OFF32, _SC_V6_ILP32_OFFBIG, _SC_V6_LP64_OFF64, _SC_V6_LPBIG_OFFBIG, _SC_HOST_NAME_MAX, _SC_TRACE, _SC_TRACE_EVENT_FILTER, _SC_TRACE_INHERIT, _SC_TRACE_LOG, _SC_LEVEL1_ICACHE_SIZE, _SC_LEVEL1_ICACHE_ASSOC, _SC_LEVEL1_ICACHE_LINESIZE, _SC_LEVEL1_DCACHE_SIZE, _SC_LEVEL1_DCACHE_ASSOC, _SC_LEVEL1_DCACHE_LINESIZE, _SC_LEVEL2_CACHE_SIZE, _SC_LEVEL2_CACHE_ASSOC, _SC_LEVEL2_CACHE_LINESIZE, _SC_LEVEL3_CACHE_SIZE, _SC_LEVEL3_CACHE_ASSOC, _SC_LEVEL3_CACHE_LINESIZE, _SC_LEVEL4_CACHE_SIZE, _SC_LEVEL4_CACHE_ASSOC, _SC_LEVEL4_CACHE_LINESIZE, _SC_IPV6 = (_SC_LEVEL1_ICACHE_SIZE+50), _SC_RAW_SOCKETS, _SC_V7_ILP32_OFF32, _SC_V7_ILP32_OFFBIG, _SC_V7_LP64_OFF64, _SC_V7_LPBIG_OFFBIG, _SC_SS_REPL_MAX, _SC_TRACE_EVENT_NAME_MAX, _SC_TRACE_NAME_MAX, _SC_TRACE_SYS_MAX, _SC_TRACE_USER_EVENT_MAX, _SC_XOPEN_STREAMS, _SC_THREAD_ROBUST_PRIO_INHERIT, _SC_THREAD_ROBUST_PRIO_PROTECT };
	/*
	Values for the argument to `sysconf'
	       corresponding to _POSIX2_ symbols. 
	*/
	/* Values according to POSIX 1003.1c (POSIX threads).  */
	/* Leave room here, maybe we need a few more cache levels some day.  */
	/* Values for the NAME argument to `confstr'.  */
enum avimod_c_8142 { _CS_PATH, _CS_V6_WIDTH_RESTRICTED_ENVS, _CS_GNU_LIBC_VERSION, _CS_GNU_LIBPTHREAD_VERSION, _CS_V5_WIDTH_RESTRICTED_ENVS, _CS_V7_WIDTH_RESTRICTED_ENVS, _CS_LFS_CFLAGS = 1000, _CS_LFS_LDFLAGS, _CS_LFS_LIBS, _CS_LFS_LINTFLAGS, _CS_LFS64_CFLAGS, _CS_LFS64_LDFLAGS, _CS_LFS64_LIBS, _CS_LFS64_LINTFLAGS, _CS_XBS5_ILP32_OFF32_CFLAGS = 1100, _CS_XBS5_ILP32_OFF32_LDFLAGS, _CS_XBS5_ILP32_OFF32_LIBS, _CS_XBS5_ILP32_OFF32_LINTFLAGS, _CS_XBS5_ILP32_OFFBIG_CFLAGS, _CS_XBS5_ILP32_OFFBIG_LDFLAGS, _CS_XBS5_ILP32_OFFBIG_LIBS, _CS_XBS5_ILP32_OFFBIG_LINTFLAGS, _CS_XBS5_LP64_OFF64_CFLAGS, _CS_XBS5_LP64_OFF64_LDFLAGS, _CS_XBS5_LP64_OFF64_LIBS, _CS_XBS5_LP64_OFF64_LINTFLAGS, _CS_XBS5_LPBIG_OFFBIG_CFLAGS, _CS_XBS5_LPBIG_OFFBIG_LDFLAGS, _CS_XBS5_LPBIG_OFFBIG_LIBS, _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS, _CS_POSIX_V6_ILP32_OFF32_CFLAGS, _CS_POSIX_V6_ILP32_OFF32_LDFLAGS, _CS_POSIX_V6_ILP32_OFF32_LIBS, _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS, _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS, _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS, _CS_POSIX_V6_ILP32_OFFBIG_LIBS, _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS, _CS_POSIX_V6_LP64_OFF64_CFLAGS, _CS_POSIX_V6_LP64_OFF64_LDFLAGS, _CS_POSIX_V6_LP64_OFF64_LIBS, _CS_POSIX_V6_LP64_OFF64_LINTFLAGS, _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS, _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS, _CS_POSIX_V6_LPBIG_OFFBIG_LIBS, _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS, _CS_POSIX_V7_ILP32_OFF32_CFLAGS, _CS_POSIX_V7_ILP32_OFF32_LDFLAGS, _CS_POSIX_V7_ILP32_OFF32_LIBS, _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS, _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS, _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS, _CS_POSIX_V7_ILP32_OFFBIG_LIBS, _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS, _CS_POSIX_V7_LP64_OFF64_CFLAGS, _CS_POSIX_V7_LP64_OFF64_LDFLAGS, _CS_POSIX_V7_LP64_OFF64_LIBS, _CS_POSIX_V7_LP64_OFF64_LINTFLAGS, _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS, _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS, _CS_POSIX_V7_LPBIG_OFFBIG_LIBS, _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS, _CS_V6_ENV, _CS_V7_ENV };
	/* The default search path.  */
	/* Get file-specific configuration information about PATH.  */
	extern long int pathconf(const char * __path, int __name);
	/* Get file-specific configuration about descriptor FD.  */
	extern long int fpathconf(int __fd, int __name);
	/* Get the value of the system variable NAME.  */
	extern long int sysconf(int __name);
	/* Get the value of the string-valued system variable NAME.  */
	extern size_t confstr(int __name, char * __buf, size_t __len);
	/* Get the process ID of the calling process.  */
	extern __pid_t getpid(void );
	/* Get the process ID of the calling process's parent.  */
	extern __pid_t getppid(void );
	/* Get the process group ID of the calling process.  */
	extern __pid_t getpgrp(void );
	/* Get the process group ID of process PID.  */
	extern __pid_t __getpgid(__pid_t __pid);
	extern __pid_t getpgid(__pid_t __pid);
	/*
	Set the process group ID of the process matching PID to PGID.
	   If PID is zero, the current process's process group ID is set.
	   If PGID is zero, the process ID of the process is used. 
	*/
	extern int setpgid(__pid_t __pid, __pid_t __pgid);
	/*
	Both System V and BSD have `setpgrp' functions, but with different
	   calling conventions.  The BSD function is the same as POSIX.1 `setpgid'
	   (above).  The System V function takes no arguments and puts the calling
	   process in its on group like `setpgid (0, 0)'.
	
	   New programs should always use `setpgid' instead.
	
	   GNU provides the POSIX.1 function. 
	*/
	/*
	Set the process group ID of the calling process to its own PID.
	   This is exactly the same as `setpgid (0, 0)'. 
	*/
	extern int setpgrp(void );
	/*
	Create a new session with the calling process as its leader.
	   The process group IDs of the session and the calling process
	   are set to the process ID of the calling process, which is returned. 
	*/
	extern __pid_t setsid(void );
	/* Return the session ID of the given process.  */
	extern __pid_t getsid(__pid_t __pid);
	/* Get the real user ID of the calling process.  */
	extern __uid_t getuid(void );
	/* Get the effective user ID of the calling process.  */
	extern __uid_t geteuid(void );
	/* Get the real group ID of the calling process.  */
	extern __gid_t getgid(void );
	/* Get the effective group ID of the calling process.  */
	extern __gid_t getegid(void );
	/*
	If SIZE is zero, return the number of supplementary groups
	   the calling process is in.  Otherwise, fill in the group IDs
	   of its supplementary groups in LIST and return the number written. 
	*/
	extern int getgroups(int __size, __gid_t __list[]);
	/*
	Set the user ID of the calling process to UID.
	   If the calling process is the super-user, set the real
	   and effective user IDs, and the saved set-user-ID to UID;
	   if not, the effective user ID is set to UID. 
	*/
	extern int setuid(__uid_t __uid);
	/*
	Set the real user ID of the calling process to RUID,
	   and the effective user ID of the calling process to EUID. 
	*/
	extern int setreuid(__uid_t __ruid, __uid_t __euid);
	/* Set the effective user ID of the calling process to UID.  */
	extern int seteuid(__uid_t __uid);
	/*
	Set the group ID of the calling process to GID.
	   If the calling process is the super-user, set the real
	   and effective group IDs, and the saved set-group-ID to GID;
	   if not, the effective group ID is set to GID. 
	*/
	extern int setgid(__gid_t __gid);
	/*
	Set the real group ID of the calling process to RGID,
	   and the effective group ID of the calling process to EGID. 
	*/
	extern int setregid(__gid_t __rgid, __gid_t __egid);
	/* Set the effective group ID of the calling process to GID.  */
	extern int setegid(__gid_t __gid);
	/*
	Clone the calling process, creating an exact copy.
	   Return -1 for errors, 0 to the new process,
	   and the process ID of the new process to the old process. 
	*/
	extern __pid_t fork(void );
	/*
	Clone the calling process, but without copying the whole address space.
	   The calling process is suspended until the new process exits or is
	   replaced by a call to `execve'.  Return -1 for errors, 0 to the new process,
	   and the process ID of the new process to the old process. 
	*/
	extern __pid_t vfork(void );
	/*
	Return the pathname of the terminal FD is open on, or NULL on errors.
	   The returned storage is good only until the next call to this function. 
	*/
	extern char *ttyname(int __fd);
	/*
	Store at most BUFLEN characters of the pathname of the terminal FD is
	   open on in BUF.  Return 0 on success, otherwise an error number. 
	*/
	extern int ttyname_r(int __fd, char * __buf, size_t __buflen);
	/*
	Return 1 if FD is a valid descriptor associated
	   with a terminal, zero if not. 
	*/
	extern int isatty(int __fd);
	/*
	Return the index into the active-logins file (utmp) for
	   the controlling terminal. 
	*/
	extern int ttyslot(void );
	/* Make a link to FROM named TO.  */
	extern int link(const char * __from, const char * __to);
	/*
	Like link but relative paths in TO and FROM are interpreted relative
	   to FROMFD and TOFD respectively. 
	*/
	extern int linkat(int __fromfd, const char * __from, int __tofd, const char * __to, int __flags);
	/* Make a symbolic link to FROM named TO.  */
	extern int symlink(const char * __from, const char * __to);
	/*
	Read the contents of the symbolic link PATH into no more than
	   LEN bytes of BUF.  The contents are not null-terminated.
	   Returns the number of characters read, or -1 for errors. 
	*/
	extern ssize_t readlink(const char * __path, char * __buf, size_t __len);
	/* Like symlink but a relative path in TO is interpreted relative to TOFD.  */
	extern int symlinkat(const char * __from, int __tofd, const char * __to);
	/* Like readlink but a relative PATH is interpreted relative to FD.  */
	extern ssize_t readlinkat(int __fd, const char * __path, char * __buf, size_t __len);
	/* Remove the link NAME.  */
	extern int unlink(const char * __name);
	/* Remove the link NAME relative to FD.  */
	extern int unlinkat(int __fd, const char * __name, int __flag);
	/* Remove the directory PATH.  */
	extern int rmdir(const char * __path);
	/* Return the foreground process group ID of FD.  */
	extern __pid_t tcgetpgrp(int __fd);
	/* Set the foreground process group ID of FD set PGRP_ID.  */
	extern int tcsetpgrp(int __fd, __pid_t __pgrp_id);
	/*
	Return the login name of the user.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern char *getlogin(void );
	/*
	Return at most NAME_LEN characters of the login name of the user in NAME.
	   If it cannot be determined or some other error occurred, return the error
	   code.  Otherwise return 0.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int getlogin_r(char * __name, size_t __name_len);
	/* Set the login name returned by `getlogin'.  */
	extern int setlogin(const char * __name);
	/*
	Get definitions and prototypes for functions to process the
	   arguments in ARGV (ARGC of them, minus the program name) for
	   options given in OPTS. 
	*/
	/*
	Declarations for getopt (POSIX compatibility shim).
	   Copyright (C) 1989-2018 Free Software Foundation, Inc.
	   Unlike the bulk of the getopt implementation, this file is NOT part
	   of gnulib.
	
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
	Declarations for getopt (basic, portable features only).
	   Copyright (C) 1989-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library and is also part of gnulib.
	   Patches to this file should be submitted to both projects.
	
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
	This header should not be used directly; include getopt.h or
	   unistd.h instead.  Unlike most bits headers, it does not have
	   a protective #error, because the guard macro for getopt.h in
	   gnulib is not fixed. 
	*/
	/*
	For communication from 'getopt' to the caller.
	   When 'getopt' finds an option that takes an argument,
	   the argument value is returned here.
	   Also, when 'ordering' is RETURN_IN_ORDER,
	   each non-option ARGV-element is returned here. 
	*/
	extern char * optarg;
	/*
	Index in ARGV of the next element to be scanned.
	   This is used for communication to and from the caller
	   and for communication between successive calls to 'getopt'.
	
	   On entry to 'getopt', zero means this is the first call; initialize.
	
	   When 'getopt' returns -1, this is the index of the first of the
	   non-option elements that the caller should itself scan.
	
	   Otherwise, 'optind' communicates from one call to the next
	   how much of ARGV has been scanned so far. 
	*/
	extern int optind;
	/*
	Callers store zero here to inhibit the error message 'getopt' prints
	   for unrecognized options. 
	*/
	extern int opterr;
	/* Set to an option character which was unrecognized.  */
	extern int optopt;
	/*
	Get definitions and prototypes for functions to process the
	   arguments in ARGV (ARGC of them, minus the program name) for
	   options given in OPTS.
	
	   Return the option character from OPTS just read.  Return -1 when
	   there are no more options.  For unrecognized options, or options
	   missing arguments, 'optopt' is set to the option letter, and '?' is
	   returned.
	
	   The OPTS string is a list of characters which are recognized option
	   letters, optionally followed by colons, specifying that that letter
	   takes an argument, to be placed in 'optarg'.
	
	   If a letter in OPTS is followed by two colons, its argument is
	   optional.  This behavior is specific to the GNU 'getopt'.
	
	   The argument '--' causes premature termination of argument
	   scanning, explicitly telling 'getopt' that there are no more
	   options.
	
	   If OPTS begins with '-', then non-option arguments are treated as
	   arguments to the option '\1'.  This behavior is specific to the GNU
	   'getopt'.  If OPTS begins with '+', or POSIXLY_CORRECT is set in
	   the environment, then do not permute arguments.
	
	   For standards compliance, the 'argv' argument has the type
	   charconst *, but this is inaccurate; if argument permutation is
	   enabled, the argv array (not the strings it points to) must be
	   writable. 
	*/
	extern int getopt(int ___argc, char * const * ___argv, const char * __shortopts);
	/*
	Put the name of the current host in no more than LEN bytes of NAME.
	   The result is null-terminated if LEN is large enough for the full
	   name and the terminator. 
	*/
	extern int gethostname(char * __name, size_t __len);
	/*
	Set the name of the current host to NAME, which is LEN bytes long.
	   This call is restricted to the super-user. 
	*/
	extern int sethostname(const char * __name, size_t __len);
	/*
	Set the current machine's Internet number to ID.
	   This call is restricted to the super-user. 
	*/
	extern int sethostid(long int __id);
	/*
	Get and set the NIS (aka YP) domain name, if any.
	   Called just like `gethostname' and `sethostname'.
	   The NIS domain name is usually the empty string when not using NIS. 
	*/
	extern int getdomainname(char * __name, size_t __len);
	extern int setdomainname(const char * __name, size_t __len);
	/*
	Revoke access permissions to all processes currently communicating
	   with the control terminal, and then send a SIGHUP signal to the process
	   group of the control terminal. 
	*/
	extern int vhangup(void );
	/* Revoke the access of all descriptors currently open on FILE.  */
	extern int revoke(const char * __file);
	/*
	Enable statistical profiling, writing samples of the PC into at most
	   SIZE bytes of SAMPLE_BUFFER; every processor clock tick while profiling
	   is enabled, the system examines the user PC and increments
	   SAMPLE_BUFFER[((PC - OFFSET) 2) * SCALE / 65536].  If SCALE is zero,
	   disable profiling.  Returns zero on success, -1 on error. 
	*/
	extern int profil(unsigned short int * __sample_buffer, size_t __size, size_t __offset, unsigned int __scale);
	/*
	Turn accounting on if NAME is an existing file.  The system will then write
	   a record for each process as it terminates, to this file.  If NAME is NULL,
	   turn accounting off.  This call is restricted to the super-user. 
	*/
	extern int acct(const char * __name);
	/* Successive calls return the shells listed in `etc/shells'.  */
	extern char *getusershell(void );
	extern void endusershell(void );
	/* Discard cached info.  */
	extern void setusershell(void );
	/* Rewind and re-read the file.  */
	/*
	Put the program in the background, and dissociate from the controlling
	   terminal.  If NOCHDIR is zero, do `chdir ("")'.  If NOCLOSE is zero,
	   redirects stdin, stdout, and stderr to /dev/null. 
	*/
	extern int daemon(int __nochdir, int __noclose);
	/*
	Make PATH be the root directory (the starting point for absolute paths).
	   This call is restricted to the super-user. 
	*/
	extern int chroot(const char * __path);
	/*
	Prompt with PROMPT and read a string from the terminal without echoing.
	   Usesdev/tty if possible; otherwise stderr and stdin. 
	*/
	extern char *getpass(const char * __prompt);
	/*
	Make all changes done to FD actually appear on disk.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int fsync(int __fd);
	/* Return identifier for the current host.  */
	extern long int gethostid(void );
	/* Make all changes done to all files actually appear on disk.  */
	extern void sync(void );
	/*
	Return the number of bytes in a page.  This is the system's page size,
	   which is not necessarily the same as the hardware page size. 
	*/
	extern int getpagesize(void );
	/*
	Return the maximum number of file descriptors
	   the current process could possibly have. 
	*/
	extern int getdtablesize(void );
	/* Truncate FILE to LENGTH bytes.  */
	extern int truncate(const char * __file, __off_t __length);
	/* Truncate the file FD is open on to LENGTH bytes.  */
	extern int ftruncate(int __fd, __off_t __length);
	/*
	Set the end of accessible data space (aka "the break") to ADDR.
	   Returns zero on success and -1 for errors (with errno set). 
	*/
	extern int brk(void * __addr);
	/*
	Increase or decrease the end of accessible data space by DELTA bytes.
	   If successful, returns the address the previous end of data space
	   (i.e. the beginning of the new space, if DELTA > 0);
	   returns (void) -1 for errors (with errno set). 
	*/
	extern void *sbrk(intptr_t __delta);
	/*
	Invoke `system call' number SYSNO, passing it the remaining arguments.
	   This is completely system-dependent, and not often useful.
	
	   In Unix, `syscall' sets `errno' for all errors and most calls return -1
	   for errors; in many systems you cannot pass arguments or get return
	   values for all system calls (`pipe', `fork', and `getppid' typically
	   among them).
	
	   In Mach, all system calls take normal arguments and always return an
	   error code (zero for success). 
	*/
	extern long int syscall(long int __sysno,  ...);
	/*
	Synchronize at least the data part of a file with the underlying
	   media. 
	*/
	extern int fdatasync(int __fildes);
	/*
	One-way hash PHRASE, returning a string suitable for storage in the
	   user database.  SALT selects the one-way function to use, and
	   ensures that no two users' hashes are the same, even if they use
	   the same passphrase.  The return value points to static storage
	   which will be overwritten by the next call to crypt. 
	*/
	extern char *crypt(const char * __key, const char * __salt);
	/*
	Prior to Issue 6, the Single Unix Specification required these
	   prototypes to appear in this header.  They are also found in
	   <stdio.h>. 
	*/
	/*
	Unix98 requires this function to be declared here.  In other
	   standards it is in <pthread.h>. 
	*/
	/*
	Write LENGTH bytes of randomness starting at BUFFER.  Return 0 on
	   success or -1 on error. 
	*/
	int getentropy(void * __buffer, size_t __length);
	/* Define some macros helping to catch buffer overflows.  */
	/* #include <windows.h> */
	/*
	Copyright (C) 1997-2018 Free Software Foundation, Inc.
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
	
		ISO C99: 7.8 Format conversion of integer types	<inttypes.h>
	
	*/
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
	/* Get the type definitions.  */
	/*
	Copyright (C) 1997-2018 Free Software Foundation, Inc.
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
	
		ISO C99: 7.18 Integer types <stdint.h>
	
	*/
	/*
	Handle feature test macros at the start of a header.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
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
	This header is internal to glibc and should not be included outside
	   of glibc headers.  Headers including it must define
	   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
	   cannot have multiple include guards because ISO C feature test
	   macros depend on the definition of the macro when an affected
	   header is included, not when the first system header is
	   included. 
	*/
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
	ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-4:2015 defines the
	   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro. 
	*/
	/*
	ISOIEC TS 18661-3:2015 defines the
	   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
	*/
	/*
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	/*
	wchar_t type related definitions.
	   Copyright (C) 2000-2018 Free Software Foundation, Inc.
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
	The fallback definitions, for when __WCHAR_MAX__ or __WCHAR_MIN__
	   are not defined, give the right value and type as long as both int
	   and wchar_t are 32-bit types.  Adding L'\0' to a constant value
	   ensures that the type is correct; it is necessary to use (L'\0' +
	   0) rather than just L'\0' so that the type in C++ is the promoted
	   version of wchar_t rather than the distinct wchar_t type itself.
	   Because wchar_t in preprocessor #if expressions is treated as
	   intmax_t or uintmax_t, the expression (L'\0' - 1) would have the
	   wrong value for WCHAR_MAX in such expressions and so cannot be used
	   to define __WCHAR_MAX in the unsigned case. 
	*/
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/* Exact integral types.  */
	/* Signed.  */
	/*
	Define intN_t types.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	/* Unsigned.  */
	/*
	Define uintN_t types.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	bitstypes.h -- definitions of __*_t types underlying *_t types.
	   Copyright (C) 2002-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it and/or
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
	
	 Never include this file directly; use <sys/types.h> instead.
	
	*/
	typedef __uint8_t uint8_t;
	typedef __uint16_t uint16_t;
	typedef __uint32_t uint32_t;
	typedef __uint64_t uint64_t;
	/* Small types.  */
	/* Signed.  */
	typedef __int_least8_t int_least8_t;
	typedef __int_least16_t int_least16_t;
	typedef __int_least32_t int_least32_t;
	typedef __int_least64_t int_least64_t;
	/* Unsigned.  */
	typedef __uint_least8_t uint_least8_t;
	typedef __uint_least16_t uint_least16_t;
	typedef __uint_least32_t uint_least32_t;
	typedef __uint_least64_t uint_least64_t;
	/* Fast types.  */
	/* Signed.  */
	typedef signed char int_fast8_t;
	typedef long int int_fast16_t;
	typedef long int int_fast32_t;
	typedef long int int_fast64_t;
	/* Unsigned.  */
	typedef unsigned char uint_fast8_t;
	typedef unsigned long int uint_fast16_t;
	typedef unsigned long int uint_fast32_t;
	typedef unsigned long int uint_fast64_t;
	/* Types for `void' pointers.  */
	typedef unsigned long int uintptr_t;
	/* Largest integral types.  */
	typedef __intmax_t intmax_t;
	typedef __uintmax_t uintmax_t;
	/* Limits of integral types.  */
	/* Minimum of signed integral types.  */
	/* Maximum of signed integral types.  */
	/* Maximum of unsigned integral types.  */
	/* Minimum of signed integral types having a minimum size.  */
	/* Maximum of signed integral types having a minimum size.  */
	/* Maximum of unsigned integral types having a minimum size.  */
	/* Minimum of fast signed integral types having a minimum size.  */
	/* Maximum of fast signed integral types having a minimum size.  */
	/* Maximum of fast unsigned integral types having a minimum size.  */
	/* Values to test for integral types holding `void' pointer.  */
	/* Minimum for largest signed integral type.  */
	/* Maximum for largest signed integral type.  */
	/* Maximum for largest unsigned integral type.  */
	/* Limits of other integer types.  */
	/* Limits of `ptrdiff_t' type.  */
	/* Limits of `sig_atomic_t'.  */
	/* Limit of `size_t' type.  */
	/* Limits of `wchar_t'.  */
	/* These constants might also be defined in <wchar.h>.  */
	/* Limits of `wint_t'.  */
	/* Signed.  */
	/* Unsigned.  */
	/* Maximal type.  */
	/* Get a definition for wchar_t.  But we must not define wchar_t itself.  */
	typedef int __gwchar_t;
	/* Macros for printing format specifiers.  */
	/* Decimal notation.  */
	/* Octal notation.  */
	/* Unsigned integers.  */
	/* lowercase hexadecimal notation.  */
	/* UPPERCASE hexadecimal notation.  */
	/* Macros for printing `intmax_t' and `uintmax_t'.  */
	/* Macros for printing `intptr_t' and `uintptr_t'.  */
	/* Macros for scanning format specifiers.  */
	/* Signed decimal notation.  */
	/* Signed decimal notation.  */
	/* Unsigned decimal notation.  */
	/* Octal notation.  */
	/* Hexadecimal notation.  */
	/* Macros for scanning `intmax_t' and `uintmax_t'.  */
	/* Macros for scaning `intptr_t' and `uintptr_t'.  */
	/* We have to define the `uintmax_t' type using `ldiv_t'.  */
	struct named_avimod_c_10811
	{
		long int quot;
		/* Quotient.  */ 
		long int rem;
	};
	
	/* Remainder.  */
	typedef struct named_avimod_c_10811 imaxdiv_t;
	/* Compute absolute value of N.  */
	extern intmax_t imaxabs(intmax_t __n);
	/* Return the `imaxdiv_t' representation of the value of NUMER over DENOM. */
	extern imaxdiv_t imaxdiv(intmax_t __numer, intmax_t __denom);
	/* Like `strtol' but convert to `intmax_t'.  */
	extern intmax_t strtoimax(const char * __nptr, char * * __endptr, int __base);
	/* Like `strtoul' but convert to `uintmax_t'.  */
	extern uintmax_t strtoumax(const char * __nptr, char * * __endptr, int __base);
	/* Like `wcstol' but convert to `intmax_t'.  */
	extern intmax_t wcstoimax(const __gwchar_t * __nptr, __gwchar_t * * __endptr, int __base);
	/* Like `wcstoul' but convert to `uintmax_t'.  */
	extern uintmax_t wcstoumax(const __gwchar_t * __nptr, __gwchar_t * * __endptr, int __base);
	/*
	Copyright (C) 1992-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify it under
	the terms of the GNU General Public License as published by the Free
	Software Foundation; either version 3, or (at your option) any later
	version.
	
	GCC is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
	for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	This administrivia gets added to the beginning of limits.h
	   if the system has its own version of limits.h. 
	*/
	/*
	We use _GCC_LIMITS_H_ because we want this not to match
	   any macros that the system's limits.h uses for its own purposes. 
	*/
	/* Use "..." so that we find syslimits.h only in this same directory.  */
	/*
	syslimits.h stands for the system's own limits.h file.
	   If we can use it ok unmodified, then we install this text.
	   If fixincludes fixes it, then the fixed version is installed
	   instead of this text. 
	*/
	/*
	Copyright (C) 1992-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify it under
	the terms of the GNU General Public License as published by the Free
	Software Foundation; either version 3, or (at your option) any later
	version.
	
	GCC is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
	for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	This administrivia gets added to the beginning of limits.h
	   if the system has its own version of limits.h. 
	*/
	/*
	We use _GCC_LIMITS_H_ because we want this not to match
	   any macros that the system's limits.h uses for its own purposes. 
	*/
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
	
		ISO C99 Standard: 7.10/5.2.4.2.1 Sizes of integer types	<limits.h>
	
	*/
	/*
	Handle feature test macros at the start of a header.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
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
	This header is internal to glibc and should not be included outside
	   of glibc headers.  Headers including it must define
	   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
	   cannot have multiple include guards because ISO C feature test
	   macros depend on the definition of the macro when an affected
	   header is included, not when the first system header is
	   included. 
	*/
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
	ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-4:2015 defines the
	   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro. 
	*/
	/*
	ISOIEC TS 18661-3:2015 defines the
	   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
	*/
	/*
	Maximum length of any multibyte character in any locale.
	   We define this value here since the gcc header does not define
	   the correct value. 
	*/
	/*
	If we are not using GNU CC we have to define all the symbols ourself.
	   Otherwise use gcc's definitions (see below). 
	*/
	/*
	Get the compiler's limits.h, which defines almost all the ISO constants.
	
	    We put this #include_next outside the double inclusion check because
	    it should be possible to include this file more than once and still get
	    the definitions from gcc's header. 
	*/
	/*
	The <limits.h> files in some gcc versions don't define LLONG_MIN,
	   LLONG_MAX, and ULLONG_MAX.  Instead only the values gcc defined for
	   ages are available. 
	*/
	/*
	The integer width macros are not defined by GCC's <limits.h> before
	   GCC 7, or if _GNU_SOURCE rather than
	   __STDC_WANT_IEC_60559_BFP_EXT__ is used to enable this feature. 
	*/
	/* POSIX adds things to <limits.h>.  */
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
	
		POSIX Standard: 2.9.2 Minimum Values	Added to <limits.h>
	 *
	 *	Never include this file directly; use <limits.h> instead.
	
	*/
	/* Determine the wordsize from the preprocessor defines.  */
	/* Both x86-64 and x32 use the 64-bit system call interface.  */
	/* These are the standard-mandated minimum values.  */
	/* Minimum number of operations in one list IO call.  */
	/* Minimal number of outstanding asynchronous IO operations.  */
	/* Maximum length of arguments to `execve', including environment.  */
	/* Maximum simultaneous processes per real user ID.  */
	/* Minimal number of timer expiration overruns.  */
	/*
	Maximum length of a host name (not including the terminating null)
	   as returned from the GETHOSTNAME function. 
	*/
	/* Maximum link count of a file.  */
	/* Maximum length of login name.  */
	/* Number of bytes in a terminal canonical input queue.  */
	/*
	Number of bytes for which space will be
	   available in a terminal input queue. 
	*/
	/* Maximum number of message queues open for a process.  */
	/* Maximum number of supported message priorities.  */
	/* Number of bytes in a filename.  */
	/* Number of simultaneous supplementary group IDs per process.  */
	/* Number of files one process can have open at once.  */
	/* Number of bytes in a pathname.  */
	/* Number of bytes than can be written atomically to a pipe.  */
	/*
	The number of repeated occurrences of a BRE permitted by the
	   REGEXEC and REGCOMP functions when using the interval notation. 
	*/
	/* Minimal number of realtime signals reserved for the application.  */
	/* Number of semaphores a process can have.  */
	/* Maximal value of a semaphore.  */
	/* Number of pending realtime signals.  */
	/* Largest value of a `ssize_t'.  */
	/* Number of streams a process can have open at once.  */
	/* The number of bytes in a symbolic link.  */
	/*
	The number of symbolic links that can be traversed in the
	   resolution of a pathname in the absence of a loop. 
	*/
	/* Number of timer for a process.  */
	/* Maximum number of characters in a tty name.  */
	/* Maximum length of a timezone name (element of `tzname').  */
	/* Maximum clock resolution in nanoseconds.  */
	/* Get the implementation-specific values for the above.  */
	/*
	Minimum guaranteed maximum values for system limits.  Linux version.
	   Copyright (C) 1993-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it andor
	   modify it under the terms of the GNU Lesser General Public License as
	   published by the Free Software Foundation; either version 2.1 of the
	   License, or (at your option) any later version.
	
	   The GNU C Library is distributed in the hope that it will be useful,
	   but WITHOUT ANY WARRANTY; without even the implied warranty of
	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	   Lesser General Public License for more details.
	
	   You should have received a copy of the GNU Lesser General Public
	   License along with the GNU C Library; see the file COPYING.LIB.  If
	   not, see <http:www.gnu.org/licenses/>. 
	*/
	/*
	The kernel header pollutes the namespace with the NR_OPEN symbol
	   and defines LINK_MAX although filesystems have different maxima.  A
	   similar thing is true for OPEN_MAX: the limit can be changed at
	   runtime and therefore the macro must not be defined.  Remove this
	   after including the header if necessary. 
	*/
	/* The kernel sources contain a file with all the needed information.  */
	/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
	/* Have to remove NR_OPEN?  */
	/* Have to remove LINK_MAX?  */
	/* Have to remove OPEN_MAX?  */
	/* Have to remove ARG_MAX?  */
	/* The number of data keys per process.  */
	/* This is the value this implementation supports.  */
	/* Controlling the iterations of destructors for thread-specific data.  */
	/* Number of iterations this implementation does.  */
	/* The number of threads per process.  */
	/* We have no predefined limit on the number of threads.  */
	/*
	Maximum amount by which a process can descrease its asynchronous IO
	   priority level. 
	*/
	/* Minimum size for a thread.  We are free to choose a reasonable value.  */
	/* Maximum number of timer expiration overruns.  */
	/* Maximum tty name length.  */
	/* Maximum login name length.  This is arbitrary.  */
	/* Maximum host name length.  */
	/* Maximum message queue priority level.  */
	/* Maximum value the semaphore can have.  */
	/*
	ssize_t is not formally required to be the signed type
	   corresponding to size_t, but it is for all configurations supported
	   by glibc. 
	*/
	/*
	This value is a guaranteed minimum maximum.
	   The current maximum can be got from `sysconf'. 
	*/
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
	
	 Never include this file directly; include <limits.h> instead.
	
	*/
	/* The maximum `ibase' and `obase' values allowed by the `bc' utility.  */
	/* The maximum number of elements allowed in an array by the `bc' utility.  */
	/* The maximum `scale' value allowed by the `bc' utility.  */
	/* The maximum length of a string constant accepted by the `bc' utility.  */
	/*
	The maximum number of weights that can be assigned to an entry of
	   the LC_COLLATE `order' keyword in the locale definition file. 
	*/
	/*
	The maximum number of expressions that can be nested
	   within parentheses by the `expr' utility. 
	*/
	/* The maximum length, in bytes, of an input line.  */
	/*
	The maximum number of repeated occurrences of a regular expression
   permitted when using the interval notation `\{M,N\}'. 
	*/
	/*
	The maximum number of bytes in a character class name.  We have no
	   fixed limit, 2048 is a high number. 
	*/
	/*
	These values are implementation-specific,
	   and may vary within the implementation.
	   Their precise values can be obtained from sysconf. 
	*/
	/* This value is defined like this in regex.h.  */
	/*
	Copyright (C) 1991-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify it under
	the terms of the GNU General Public License as published by the Free
	Software Foundation; either version 3, or (at your option) any later
	version.
	
	GCC is distributed in the hope that it will be useful, but WITHOUT ANY
	WARRANTY; without even the implied warranty of MERCHANTABILITY or
	FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
	for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/* Number of bits in a `char'.  */
	/* Maximum length of a multibyte character.  */
	/* Minimum and maximum values a `signed char' can hold.  */
	/* Maximum value an `unsigned char' can hold.  (Minimum is 0).  */
	/* Minimum and maximum values a `char' can hold.  */
	/* Minimum and maximum values a `signed short int' can hold.  */
	/* Maximum value an `unsigned short int' can hold.  (Minimum is 0).  */
	/* Minimum and maximum values a `signed int' can hold.  */
	/* Maximum value an `unsigned int' can hold.  (Minimum is 0).  */
	/*
	Minimum and maximum values a `signed long int' can hold.
	   (Same as `int'). 
	*/
	/* Maximum value an `unsigned long int' can hold.  (Minimum is 0).  */
	/* Minimum and maximum values a `signed long long int' can hold.  */
	/* Maximum value an `unsigned long long int' can hold.  (Minimum is 0).  */
	/*
	This administrivia gets added to the end of limits.h
	   if the system has its own version of limits.h. 
	*/
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
	
		ISO C99 Standard: 7.20 General utilities	<stdlib.h>
	
	*/
	/*
	Handle feature test macros at the start of a header.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
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
	This header is internal to glibc and should not be included outside
	   of glibc headers.  Headers including it must define
	   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
	   cannot have multiple include guards because ISO C feature test
	   macros depend on the definition of the macro when an affected
	   header is included, not when the first system header is
	   included. 
	*/
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
	ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-4:2015 defines the
	   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro. 
	*/
	/*
	ISOIEC TS 18661-3:2015 defines the
	   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
	*/
	/* Get size_t, wchar_t and NULL from <stddef.h>.  */
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	On BSD386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
	   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
	   symbols in the _FOO_T_ family, stays defined even after its
	   corresponding type is defined).  If we define wchar_t, then we
	   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
	   we undef _WCHAR_T_, then we must also define rune_t, since 
	   headers like runetype.h assume that if machine/ansi.h is included,
	   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
	   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
	   the same type."
	*/
	/*
	FreeBSD 5 can't be handled well using "traditional" logic above
	   since it no longer defines _BSD_RUNE_T_ yet still desires to export
	   rune_t in some cases...
	*/
	typedef int wchar_t;
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/* XPG requires a few symbols from <syswait.h> being defined.  */
	/*
	Definitions of flag bits for `waitpid' et al.
	   Copyright (C) 1992-2018 Free Software Foundation, Inc.
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
	/* Bits in the third argument to `waitpid'.  */
	/* Bits in the fourth argument to `waitid'.  */
	/* The following values are used by the `waitid' function.  */
	/*
	The Linux kernel defines these bare, rather than an enum,
	   which causes a conflict if the include order is reversed.
	*/
enum avimod_c_11074 { P_ALL, P_PID, P_PGID };
	/* Wait for any child.  */
	/* Wait for specified process.  */
	/* Wait for members of process group.  */
	typedef enum avimod_c_11074 idtype_t;
	/*
	Definitions of status bits for `wait' et al.
	   Copyright (C) 1992-2018 Free Software Foundation, Inc.
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
	/* Everything extant so far uses these same bits.  */
	/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
	/* If WIFSIGNALED(STATUS), the terminating signal.  */
	/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
	/* Nonzero if STATUS indicates normal termination.  */
	/* Nonzero if STATUS indicates termination by a signal.  */
	/* Nonzero if STATUS indicates the child is stopped.  */
	/*
	Nonzero if STATUS indicates the child continued after a stop.  We only
	   define this if <bitswaitflags.h> provides the WCONTINUED flag bit. 
	*/
	/* Nonzero if STATUS indicates the child dumped core.  */
	/* Macros for constructing status values.  */
	/* Define the macros <syswait.h> also would define this way.  */
	/* _FloatN API tests for enablement.  */
	/*
	Macros to control TS 18661-3 glibc features on x86.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	Defined to 1 if the current compiler invocation provides a
	   floating-point type with the IEEE 754 binary128 format, and this
	   glibc includes correspondingf128 interfaces for it.  The required
	   libgcc support was added some time after the basic compiler
	   support, for x86_64 and x86. 
	*/
	/*
	Defined to 1 if __HAVE_FLOAT128 is 1 and the type is ABI-distinct
	   from the default float, double and long double types in this glibc. 
	*/
	/*
	Defined to 1 if the current compiler invocation provides a
	   floating-point type with the right format for _Float64x, and this
	   glibc includes correspondingf64x interfaces for it. 
	*/
	/*
	Defined to 1 if __HAVE_FLOAT64X is 1 and _Float64x has the format
	   of long double.  Otherwise, if __HAVE_FLOAT64X is 1, _Float64x has
	   the format of _Float128, which must be different from that of long
	   double. 
	*/
	/*
	Defined to concatenate the literal suffix to be used with _Float128
	   types, if __HAVE_FLOAT128 is 1.
	*/
	/* Defined to a complex binary128 type if __HAVE_FLOAT128 is 1.  */
	/* The remaining of this file provides support for older compilers.  */
	/* The type _Float128 exists only since GCC 7.0.  */
	/* __builtin_huge_valf128 doesn't exist before GCC 7.0.  */
	/*
	Older GCC has only a subset of built-in functions for _Float128 on
	   x86, and __builtin_infq is not usable in static initializers.
	   Converting a narrower sNaN to _Float128 produces a quiet NaN, so
	   attempts to use _Float128 sNaNs will not work properly with older
	   compilers. 
	*/
	/*
	In mathmath.h, __MATH_TG will expand signbit to __builtin_signbit*,
	   e.g.: __builtin_signbitf128, before GCC 6.  However, there has never
	   been a __builtin_signbitf128 in GCC and the type-generic builtin is
	   only available since GCC 6. 
	*/
	/*
	Macros to control TS 18661-3 glibc features where the same
	   definitions are appropriate for all platforms.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	Properties of long double type.  ldbl-96 version.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	
	   The GNU C Library is free software; you can redistribute it andor
	   modify it under the terms of the GNU Lesser General Public
	   License  published by the Free Software Foundation; either
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
	long double is distinct from double, so there is nothing to
	   define here. 
	*/
	/*
	This header should be included at the bottom of each bitsfloatn.h.
	   It defines the following macros for each _FloatN and _FloatNx type,
	   where the same definitions, or definitions based only on the macros
	   in bits/floatn.h, are appropriate for all glibc configurations. 
	*/
	/*
	Defined to 1 if the current compiler invocation provides a
	   floating-point type with the right format for this type, and this
	   glibc includes correspondingfN or *fNx interfaces for it. 
	*/
	/*
	Defined to 1 if the corresponding __HAVE_<type> macro is 1 and the
	   type is the first with its format in the sequence of (the default
	   choices for) float, double, long double, _Float16, _Float32,
	   _Float64, _Float128, _Float32x, _Float64x, _Float128x for this
	   glibc; that is, if functions present once per floating-point format
	   rather than once per type are present for this type.
	
	   All configurations supported by glibc have _Float32 the same format
	   as float, _Float64 and _Float32x the same format as double, the
	   _Float64x the same format as either long double or _Float128.  No
	   configurations support _Float128x or, as of GCC 7, have compiler
	   support for a type meeting the requirements for _Float128x. 
	*/
	/*
	Defined to 1 if the corresponding _FloatN type is not binary compatible
	   with the corresponding ISO C type in the current compilation unit as
	   opposed to __HAVE_DISTINCT_FLOATN, which indicates the default types built
	   in glibc. 
	*/
	/*
	Defined to 1 if any _FloatN or _FloatNx types that are not
	   ABI-distinct are however distinct types at the C language level (so
	   for the purposes of __builtin_types_compatible_p and _Generic). 
	*/
	/*
	Defined to concatenate the literal suffix to be used with _FloatN
	   or _FloatNx types, if __HAVE_<type> is 1.  The corresponding
	   literal suffixes exist since GCC 7, for C only. 
	*/
	/* Defined to a complex type if __HAVE_<type> is 1.  */
	/* The remaining of this file provides support for older compilers.  */
	/*
	If double, long double and _Float64 all have the same set of
	   values, TS 18661-3 requires the usual arithmetic conversions on
	   long double and _Float64 to produce _Float64.  For this to be the
	   case when building with a compiler without a distinct _Float64
	   type, _Float64 must be a typedef for long double, not for
	   double. 
	*/
	/* Returned by `div'.  */
	struct named_avimod_c_11091
	{
		int quot;
		/* Quotient.  */ 
		int rem;
	};
	
	/* Remainder.  */
	typedef struct named_avimod_c_11091 div_t;
	/* Returned by `ldiv'.  */
	struct named_avimod_c_11110
	{
		long int quot;
		/* Quotient.  */ 
		long int rem;
	};
	
	/* Remainder.  */
	typedef struct named_avimod_c_11110 ldiv_t;
	/* Returned by `lldiv'.  */
	struct named_avimod_c_11134
	{
		long long int quot;
		/* Quotient.  */ 
		long long int rem;
	};
	
	/* Remainder.  */
	typedef struct named_avimod_c_11134 lldiv_t;
	/* The largest number rand will return (same as INT_MAX).  */
	/*
	We define these the same for all machines.
	   Changes from this to the outside world should be done in `_exit'. 
	*/
	/* Maximum length of a multibyte character in the current locale.  */
	extern size_t __ctype_get_mb_cur_max(void );
	/* Convert a string to a floating-point number.  */
	extern double atof(const char * __nptr);
	/* Convert a string to an integer.  */
	extern int atoi(const char * __nptr);
	/* Convert a string to a long integer.  */
	extern long int atol(const char * __nptr);
	/* Convert a string to a long long integer.  */
	extern long long int atoll(const char * __nptr);
	/* Convert a string to a floating-point number.  */
	extern double strtod(const char * __nptr, char * * __endptr);
	/* Likewise for `float' and `long double' sizes of floating-point numbers.  */
	extern float strtof(const char * __nptr, char * * __endptr);
	extern long double strtold(const char * __nptr, char * * __endptr);
	/* Likewise for '_FloatN' and '_FloatNx'.  */
	/* Convert a string to a long integer.  */
	extern long int strtol(const char * __nptr, char * * __endptr, int __base);
	/* Convert a string to an unsigned long integer.  */
	extern unsigned long int strtoul(const char * __nptr, char * * __endptr, int __base);
	/* Convert a string to a quadword integer.  */
	extern long long int strtoq(const char * __nptr, char * * __endptr, int __base);
	/* Convert a string to an unsigned quadword integer.  */
	extern unsigned long long int strtouq(const char * __nptr, char * * __endptr, int __base);
	/* Convert a string to a quadword integer.  */
	extern long long int strtoll(const char * __nptr, char * * __endptr, int __base);
	/* Convert a string to an unsigned quadword integer.  */
	extern unsigned long long int strtoull(const char * __nptr, char * * __endptr, int __base);
	/* Convert a floating-point number to a string.  */
	/*
	Convert N to base 64 using the digits ".0-9A-Za-z", least-significant
	   digit first.  Returns a pointer to static storage overwritten by the
	   next call. 
	*/
	extern char *l64a(long int __n);
	/* Read a number from a string S in base 64 as above.  */
	extern long int a64l(const char * __s);
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
	
		POSIX Standard: 2.6 Primitive System Data Types	<sys/types.h>
	
	*/
	/*
	These are the functions that actually do things.  The `random', `srandom',
	   `initstate' and `setstate' functions are those from BSD Unices.
	   The `rand' and `srand' functions are required by the ANSI standard.
	   We provide both interfaces to the same random number generator. 
	*/
	/* Return a random long integer between 0 and RAND_MAX inclusive.  */
	extern long int random(void );
	/* Seed the random number generator with the given number.  */
	extern void srandom(unsigned int __seed);
	/*
	Initialize the random number generator to use state buffer STATEBUF,
	   of length STATELEN, and seed it with SEED.  Optimal lengths are 8, 16,
	   32, 64, 128 and 256, the bigger the better; values less than 8 will
	   cause an error and values greater than 256 will be rounded down. 
	*/
	extern char *initstate(unsigned int __seed, char * __statebuf, size_t __statelen);
	/*
	Switch the random number generator to state buffer STATEBUF,
	   which should have been previously initialized by `initstate'. 
	*/
	extern char *setstate(char * __statebuf);
	/*
	Reentrant versions of the `random' family of functions.
	   These functions all use the following data structure to contain
	   state, rather than global state variables. 
	*/
	struct random_data
	{
		int32_t * fptr;
		/* Front pointer.  */ 
		int32_t * rptr;
		/* Rear pointer.  */ 
		int32_t * state;
		/* Array of state values.  */ 
		int rand_type;
		/* Type of random number generator.  */ 
		int rand_deg;
		/* Degree of random number generator.  */ 
		int rand_sep;
		/* Distance between front and rear.  */ 
		int32_t * end_ptr;
	};
	
	/* Pointer behind state table.  */
	extern int random_r(struct random_data * __buf, int32_t * __result);
	extern int srandom_r(unsigned int __seed, struct random_data * __buf);
	extern int initstate_r(unsigned int __seed, char * __statebuf, size_t __statelen, struct random_data * __buf);
	extern int setstate_r(char * __statebuf, struct random_data * __buf);
	/* Return a random integer between 0 and RAND_MAX inclusive.  */
	extern int rand(void );
	/* Seed the random number generator with the given number.  */
	extern void srand(unsigned int __seed);
	/* Reentrant interface according to POSIX.1.  */
	extern int rand_r(unsigned int * __seed);
	/* System V style 48-bit random number generator functions.  */
	/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
	extern double drand48(void );
	extern double erand48(unsigned short int __xsubi[3]);
	/* Return non-negative, long integer in [0,2^31).  */
	extern long int lrand48(void );
	extern long int nrand48(unsigned short int __xsubi[3]);
	/* Return signed, long integers in [-2^31,2^31).  */
	extern long int mrand48(void );
	extern long int jrand48(unsigned short int __xsubi[3]);
	/* Seed random number generator.  */
	extern void srand48(long int __seedval);
	extern unsigned short int *seed48(unsigned short int __seed16v[3]);
	extern void lcong48(unsigned short int __param[7]);
	/*
	Data structure for communication with thread safe versions.  This
	   type is to be regarded as opaque.  It's only exported because users
	   have to allocate objects of this type. 
	*/
	struct drand48_data
	{
		unsigned short int __x[3];
		/* Current state.  */ 
		unsigned short int __old_x[3];
		/* Old state.  */ 
		unsigned short int __c;
		/* Additive const. in congruential formula.  */ 
		unsigned short int __init;
		/* Flag for initializing.  */ 
		unsigned long long int __a;
	};
	
	/*
	Factor in congruential
							   formula. 
	*/
	/* Return non-negative, double-precision floating-point value in [0.0,1.0).  */
	extern int drand48_r(struct drand48_data * __buffer, double * __result);
	extern int erand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, double * __result);
	/* Return non-negative, long integer in [0,2^31).  */
	extern int lrand48_r(struct drand48_data * __buffer, long int * __result);
	extern int nrand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, long int * __result);
	/* Return signed, long integers in [-2^31,2^31).  */
	extern int mrand48_r(struct drand48_data * __buffer, long int * __result);
	extern int jrand48_r(unsigned short int __xsubi[3], struct drand48_data * __buffer, long int * __result);
	/* Seed random number generator.  */
	extern int srand48_r(long int __seedval, struct drand48_data * __buffer);
	extern int seed48_r(unsigned short int __seed16v[3], struct drand48_data * __buffer);
	extern int lcong48_r(unsigned short int __param[7], struct drand48_data * __buffer);
	/* Allocate SIZE bytes of memory.  */
	extern void *malloc(size_t __size);
	/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */
	extern void *calloc(size_t __nmemb, size_t __size);
	/*
	Re-allocate the previously allocated block
	   in PTR, making the new block SIZE bytes long. 
	*/
	/*
	__attribute_malloc__ is not used, because if realloc returns
	   the same pointer that was passed to it, aliasing needs to be allowed
	   between objects pointed by the old and new pointers. 
	*/
	extern void *realloc(void * __ptr, size_t __size);
	/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
	extern void free(void * __ptr);
	/*
	Copyright (C) 1992-2018 Free Software Foundation, Inc.
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
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/* Remove any previous definitions.  */
	/* Allocate a block that will be freed when the calling function exits.  */
	extern void *alloca(size_t __size);
	/* Allocate SIZE bytes on a page boundary.  The storage cannot be freed.  */
	extern void *valloc(size_t __size);
	/* Allocate memory of SIZE bytes with an alignment of ALIGNMENT.  */
	extern int posix_memalign(void * * __memptr, size_t __alignment, size_t __size);
	/* ISO C variant of aligned allocation.  */
	extern void *aligned_alloc(size_t __alignment, size_t __size);
	/* Abort execution and generate a core-dump.  */
	extern void abort(void );
	/* Register a function to be called when `exit' is called.  */
	extern int atexit(void (* __func)(void ));
	/* Register a function to be called when `quick_exit' is called.  */
	extern int at_quick_exit(void (* __func)(void ));
	/*
	Register a function to be called with the status
	   given to `exit' and the given argument. 
	*/
	extern int on_exit(void (* __func)(int __status, void * __arg), void * __arg);
	/*
	Call all functions registered with `atexit' and `on_exit',
	   in the reverse of the order in which they were registered,
	   perform stdio cleanup, and terminate program execution with STATUS. 
	*/
	extern void exit(int __status);
	/*
	Call all functions registered with `at_quick_exit' in the reverse
	   of the order in which they were registered and terminate program
	   execution with STATUS. 
	*/
	extern void quick_exit(int __status);
	/*
	Terminate the program with STATUS without calling any of the
	   functions registered with `atexit' or `on_exit'. 
	*/
	extern void _Exit(int __status);
	/* Return the value of envariable NAME, or NULL if it doesn't exist.  */
	extern char *getenv(const char * __name);
	/* The SVID says this is in <stdio.h>, but this seems a better place.	 */
	/*
	Put STRING, which is of the form "NAME=VALUE", in the environment.
	   If there is no `=', remove NAME from the environment. 
	*/
	extern int putenv(char * __string);
	/*
	Set NAME to VALUE in the environment.
	   If REPLACE is nonzero, overwrite an existing value. 
	*/
	extern int setenv(const char * __name, const char * __value, int __replace);
	/* Remove the variable NAME from the environment.  */
	extern int unsetenv(const char * __name);
	/*
	The `clearenv' was planned to be added to POSIX.1 but probably
	   never made it.  Nevertheless the POSIX.9 standard (POSIX bindings
	   for Fortran 77) requires this function. 
	*/
	extern int clearenv(void );
	/*
	Generate a unique temporary file name from TEMPLATE.
	   The last six characters of TEMPLATE must be "XXXXXX";
	   they are replaced with a string that makes the file name unique.
	   Always returns TEMPLATE, it's either a temporary file name or a null
	   string if it cannot get a unique file name. 
	*/
	extern char *mktemp(char * __template);
	/*
	Generate a unique temporary file name from TEMPLATE.
	   The last six characters of TEMPLATE must be "XXXXXX";
	   they are replaced with a string that makes the filename unique.
	   Returns a file descriptor open on the file for reading and writing,
	   or -1 if it cannot create a uniquely-named file.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int mkstemp(char * __template);
	/*
	Similar to mkstemp, but the template can have a suffix after the
	   XXXXXX.  The length of the suffix is specified in the second
	   parameter.
	
	   This function is a possible cancellation point and therefore not
	   marked with __THROW. 
	*/
	extern int mkstemps(char * __template, int __suffixlen);
	/*
	Create a unique temporary directory from TEMPLATE.
	   The last six characters of TEMPLATE must be "XXXXXX";
	   they are replaced with a string that makes the directory name unique.
	   Returns TEMPLATE, or a null pointer if it cannot get a unique name.
	   The directory is created mode 700. 
	*/
	extern char *mkdtemp(char * __template);
	/*
	Execute the given line as a shell command.
	
	   This function is a cancellation point and therefore not marked with
	   __THROW. 
	*/
	extern int system(const char * __command);
	/*
	Return the canonical absolute name of file NAME.  If RESOLVED is
	   null, the result is malloc'd; otherwise, if the canonical name is
	   PATH_MAX chars or more, returns null with `errno' set to
	   ENAMETOOLONG; if the name fits in fewer than PATH_MAX chars,
	   returns the name in RESOLVED. 
	*/
	extern char *realpath(const char * __name, char * __resolved);
	/* Shorthand for type of comparison functions.  */
	typedef int (* __compar_fn_t)(const void * , const void * );
	/*
	Do a binary search for KEY in BASE, which consists of NMEMB elements
	   of SIZE bytes each, using COMPAR to perform the comparisons. 
	*/
	extern void *bsearch(const void * __key, const void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
	/*
	Sort NMEMB elements of BASE, of SIZE bytes each,
	   using COMPAR to perform the comparisons. 
	*/
	extern void qsort(void * __base, size_t __nmemb, size_t __size, __compar_fn_t __compar);
	/* Return the absolute value of X.  */
	extern int abs(int __x);
	extern long int labs(long int __x);
	extern long long int llabs(long long int __x);
	/*
	Return the `div_t', `ldiv_t' or `lldiv_t' representation
	   of the value of NUMER over DENOM.
	*/
	/* GCC may have built-ins for these someday.  */
	extern div_t div(int __numer, int __denom);
	extern ldiv_t ldiv(long int __numer, long int __denom);
	extern lldiv_t lldiv(long long int __numer, long long int __denom);
	/*
	Convert floating point numbers to strings.  The returned values are
	   valid only until another call to the same function. 
	*/
	/*
	Convert VALUE to a string with NDIGIT digits and return a pointer to
	   this.  SetDECPT with the position of the decimal character and *SIGN
	   with the sign of the number. 
	*/
	extern char *ecvt(double __value, int __ndigit, int * __decpt, int * __sign);
	/*
	Convert VALUE to a string rounded to NDIGIT decimal digits.  SetDECPT
	   with the position of the decimal character and *SIGN with the sign of
	   the number. 
	*/
	extern char *fcvt(double __value, int __ndigit, int * __decpt, int * __sign);
	/*
	If possible convert VALUE to a string with NDIGIT significant digits.
	   Otherwise use exponential representation.  The resulting string will
	   be written to BUF. 
	*/
	extern char *gcvt(double __value, int __ndigit, char * __buf);
	/* Long double versions of above functions.  */
	extern char *qecvt(long double __value, int __ndigit, int * __decpt, int * __sign);
	extern char *qfcvt(long double __value, int __ndigit, int * __decpt, int * __sign);
	extern char *qgcvt(long double __value, int __ndigit, char * __buf);
	/*
	Reentrant version of the functions above which provide their own
	   buffers. 
	*/
	extern int ecvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
	extern int fcvt_r(double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
	extern int qecvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
	extern int qfcvt_r(long double __value, int __ndigit, int * __decpt, int * __sign, char * __buf, size_t __len);
	/*
	Return the length of the multibyte character
	   in S, which is no longer than N. 
	*/
	extern int mblen(const char * __s, size_t __n);
	/*
	Return the length of the given multibyte character,
	   putting its `wchar_t' representation inPWC. 
	*/
	extern int mbtowc(wchar_t * __pwc, const char * __s, size_t __n);
	/*
	Put the multibyte character represented
	   by WCHAR in S, returning its length. 
	*/
	extern int wctomb(char * __s, wchar_t __wchar);
	/* Convert a multibyte string to a wide char string.  */
	extern size_t mbstowcs(wchar_t * __pwcs, const char * __s, size_t __n);
	/* Convert a wide char string to multibyte string.  */
	extern size_t wcstombs(char * __s, const wchar_t * __pwcs, size_t __n);
	/*
	Determine whether the string value of RESPONSE matches the affirmation
	   or negative response expression as specified by the LC_MESSAGES category
	   in the program's current locale.  Returns 1 if affirmative, 0 if
	   negative, and -1 if not matching. 
	*/
	extern int rpmatch(const char * __response);
	/*
	Parse comma separated suboption fromOPTIONP and match against
	   strings in TOKENS.  If found return index and set *VALUEP to
	   optional value introduced by an equal sign.  If the suboption is
	   not part of TOKENS return in *VALUEP beginning of unknown
	   suboption.  On exit *OPTIONP is set to the beginning of the next
	   token or at the terminating NUL character. 
	*/
	extern int getsubopt(char * * __optionp, char * const * __tokens, char * * __valuep);
	/* XOpen pseudo terminal handling.  */
	/*
	Put the 1 minute, 5 minute and 15 minute load averages into the first
	   NELEM elements of LOADAVG.  Return the number written (never more than
	   three, but may be less than NELEM), or -1 if an error occurred. 
	*/
	extern int getloadavg(double __loadavg[], int __nelem);
	/*
	Floating-point inline functions for stdlib.h.
	   Copyright (C) 2012-2018 Free Software Foundation, Inc.
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
	/* Define some macros helping to catch buffer overflows.  */
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
	
		ISO C99 Standard: 7.21 String handling	<string.h>
	
	*/
	/*
	Handle feature test macros at the start of a header.
	   Copyright (C) 2016-2018 Free Software Foundation, Inc.
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
	This header is internal to glibc and should not be included outside
	   of glibc headers.  Headers including it must define
	   __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION first.  This header
	   cannot have multiple include guards because ISO C feature test
	   macros depend on the definition of the macro when an affected
	   header is included, not when the first system header is
	   included. 
	*/
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
	ISOIEC TR 24731-2:2010 defines the __STDC_WANT_LIB_EXT2__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-1:2014 defines the __STDC_WANT_IEC_60559_BFP_EXT__
	   macro. 
	*/
	/*
	ISOIEC TS 18661-4:2015 defines the
	   __STDC_WANT_IEC_60559_FUNCS_EXT__ macro. 
	*/
	/*
	ISOIEC TS 18661-3:2015 defines the
	   __STDC_WANT_IEC_60559_TYPES_EXT__ macro. 
	*/
	/* Get size_t and NULL from <stddef.h>.  */
	/*
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/* Tell the caller that we provide correct C++ prototypes.  */
	/* Copy N bytes of SRC to DEST.  */
	extern void *memcpy(void * __dest, const void * __src, size_t __n);
	/*
	Copy N bytes of SRC to DEST, guaranteeing
	   correct behavior for overlapping strings. 
	*/
	extern void *memmove(void * __dest, const void * __src, size_t __n);
	/*
	Copy no more than N bytes of SRC to DEST, stopping when C is found.
	   Return the position in DEST one byte past where C was copied,
	   or NULL if C was not found in the first N bytes of SRC. 
	*/
	extern void *memccpy(void * __dest, const void * __src, int __c, size_t __n);
	/* Set N bytes of S to C.  */
	extern void *memset(void * __s, int __c, size_t __n);
	/* Compare N bytes of S1 and S2.  */
	extern int memcmp(const void * __s1, const void * __s2, size_t __n);
	/* Search N bytes of S for C.  */
	extern void *memchr(const void * __s, int __c, size_t __n);
	/* Copy SRC to DEST.  */
	extern char *strcpy(char * __dest, const char * __src);
	/* Copy no more than N characters of SRC to DEST.  */
	extern char *strncpy(char * __dest, const char * __src, size_t __n);
	/* Append SRC onto DEST.  */
	extern char *strcat(char * __dest, const char * __src);
	/* Append no more than N characters from SRC onto DEST.  */
	extern char *strncat(char * __dest, const char * __src, size_t __n);
	/* Compare S1 and S2.  */
	extern int strcmp(const char * __s1, const char * __s2);
	/* Compare N characters of S1 and S2.  */
	extern int strncmp(const char * __s1, const char * __s2, size_t __n);
	/* Compare the collated forms of S1 and S2.  */
	extern int strcoll(const char * __s1, const char * __s2);
	/* Put a transformation of SRC into no more than N bytes of DEST.  */
	extern size_t strxfrm(char * __dest, const char * __src, size_t __n);
	/* POSIX.1-2008 extended locale interface (see locale.h).  */
	/*
	Definition of locale_t.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	Definition of struct __locale_struct and __locale_t.
	   Copyright (C) 1997-2018 Free Software Foundation, Inc.
	   This file is part of the GNU C Library.
	   Contributed by Ulrich Drepper <drepper@cygnus.com>, 1997.
	
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
	POSIX.1-2008: the locale_t type, representing a locale context
	   (implementation-namespace version).  This type should be treated
	   as opaque by applications; some details are exposed for the sake of
	   efficiency in e.g. ctype functions. 
	*/
	struct __locale_struct
	{
		/* Note: LC_ALL is not a valid index into this array.  */ 
		struct __locale_data * __locales[13];
		/* 13 = __LC_LAST. */ 
		/* To increase the speed of this solution we add some special members.  */ 
		const unsigned short int * __ctype_b;
		const int * __ctype_tolower;
		const int * __ctype_toupper;
		/* Note: LC_ALL is not a valid index into this array.  */ 
		const char * __names[13];
	};
	
	struct __locale_data;
	
	typedef struct __locale_struct * __locale_t;
	typedef __locale_t locale_t;
	/* Compare the collated forms of S1 and S2, using sorting rules from L.  */
	extern int strcoll_l(const char * __s1, const char * __s2, locale_t __l);
	/*
	Put a transformation of SRC into no more than N bytes of DEST,
	   using sorting rules from L. 
	*/
	extern size_t strxfrm_l(char * __dest, const char * __src, size_t __n, locale_t __l);
	/* Duplicate S, returning an identical malloc'd string.  */
	extern char *strdup(const char * __s);
	/*
	Return a malloc'd copy of at most N bytes of STRING.  The
	   resultant string is terminated even if no null terminator
	   appears before STRING[N]. 
	*/
	extern char *strndup(const char * __string, size_t __n);
	/* Find the first occurrence of C in S.  */
	extern char *strchr(const char * __s, int __c);
	/* Find the last occurrence of C in S.  */
	extern char *strrchr(const char * __s, int __c);
	/*
	Return the length of the initial segment of S which
	   consists entirely of characters not in REJECT. 
	*/
	extern size_t strcspn(const char * __s, const char * __reject);
	/*
	Return the length of the initial segment of S which
	   consists entirely of characters in ACCEPT. 
	*/
	extern size_t strspn(const char * __s, const char * __accept);
	/* Find the first occurrence in S of any character in ACCEPT.  */
	extern char *strpbrk(const char * __s, const char * __accept);
	/* Find the first occurrence of NEEDLE in HAYSTACK.  */
	extern char *strstr(const char * __haystack, const char * __needle);
	/* Divide S into tokens separated by characters in DELIM.  */
	extern char *strtok(char * __s, const char * __delim);
	/*
	Divide S into tokens separated by characters in DELIM.  Information
	   passed between calls are stored in SAVE_PTR. 
	*/
	extern char *__strtok_r(char * __s, const char * __delim, char * * __save_ptr);
	extern char *strtok_r(char * __s, const char * __delim, char * * __save_ptr);
	/* Return the length of S.  */
	extern size_t strlen(const char * __s);
	/*
	Find the length of STRING, but scan at most MAXLEN characters.
	   If no '\0' terminator is found in that many characters, return MAXLEN. 
	*/
	extern size_t strnlen(const char * __string, size_t __maxlen);
	/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
	extern char *strerror(int __errnum);
	/*
	Reentrant version of `strerror'.
	   There are 2 flavors of `strerror_r', GNU which returns the string
	   and may or may not use the supplied temporary buffer and POSIX one
	   which fills the string into the buffer.
	   To use the POSIX version, -D_XOPEN_SOURCE=600 or -D_POSIX_C_SOURCE=200112L
	   without -D_GNU_SOURCE is needed, otherwise the GNU version is
	   preferred. 
	*/
	/*
	Fill BUF with a string describing the meaning of the `errno' code in
	   ERRNUM. 
	*/
	extern int strerror_r(int __errnum, char * __buf, size_t __buflen);
	/* Translate error number to string according to the locale L.  */
	extern char *strerror_l(int __errnum, locale_t __l);
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
	Copyright (C) 1989-2018 Free Software Foundation, Inc.
	
	This file is part of GCC.
	
	GCC is free software; you can redistribute it andor modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 3, or (at your option)
	any later version.
	
	GCC is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.
	
	Under Section 7 of GPL version 3, you are granted additional
	permissions described in the GCC Runtime Library Exception, version
	3.1, as published by the Free Software Foundation.
	
	You should have received a copy of the GNU General Public License and
	a copy of the GCC Runtime Library Exception along with this program;
	see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
	<http:www.gnu.org/licenses/>. 
	*/
	/*
	
	 ISO C Standard:  7.17  Common definitions  <stddef.h>
	
	*/
	/*
	Any one of these symbols __need_ means that GNU libc
	   wants us just to define one data type.  So don't define
	   the symbols that indicate this file's entire job has been done. 
	*/
	/*
	This avoids lossage on SunOS but only if stdtypes.h comes first.
	   There's no way to win with the other order!  Sun lossage. 
	*/
	/*
	On 4.3bsd-net2, make sure ansi.h is included, so we have
	   one less case to deal with in the following. 
	*/
	/* On FreeBSD 5, machineansi.h does not exist anymore... */
	/*
	In 4.3bsd-net2, machineansi.h defines these symbols, which are
	   defined if the corresponding type is *not* defined.
	   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_.
	   NetBSD defines _I386_ANSI_H_ and _X86_64_ANSI_H_ instead of _ANSI_H_
	*/
	/*
	Sequent's header files use _PTRDIFF_T_ in some conflicting way.
	   Just ignore it. 
	*/
	/*
	On VxWorks, <typevxTypesBase.h> may have defined macros like
	   _TYPE_size_t which will typedef size_t.  fixincludes patched the
	   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
	   not defined, and so that defining this macro defines _GCC_SIZE_T.
	   If we find that the macros are still defined at this point, we must
	   invoke them so that the type is defined as expected. 
	*/
	/*
	In case nobody has defined these types, but we aren't running under
	   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
	   __WCHAR_TYPE__ have reasonable values.  This can happen if the
	   parts of GCC is compiled by an older compiler, that actually
	   include gstddef.h, such as collect2. 
	*/
	/* Signed type of difference of two pointers.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/* Unsigned type of `sizeof' something.  */
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	Wide character type.
	   Locale-writers should change this as necessary to
	   be big enough to hold unique values not between 0 and 127,
	   and not (wchar_t) -1, for each defined multibyte character. 
	*/
	/*
	Define this type if we are doing the whole job,
	   or if we want this type in particular. 
	*/
	/*
	 In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
	    are already defined. 
	*/
	/*  BSDOS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
	/*  NetBSD 5 requires the I386_ANSI_H and X86_64_ANSI_H checks here.  */
	/* A null pointer constant.  */
	/* Tell the caller that we provide correct C++ prototypes.  */
	/* Compare N bytes of S1 and S2 (same as memcmp).  */
	extern int bcmp(const void * __s1, const void * __s2, size_t __n);
	/* Copy N bytes of SRC to DEST (like memmove, but args reversed).  */
	extern void bcopy(const void * __src, void * __dest, size_t __n);
	/* Set N bytes of S to 0.  */
	extern void bzero(void * __s, size_t __n);
	/* Find the first occurrence of C in S (same as strchr).  */
	extern char *index(const char * __s, int __c);
	/* Find the last occurrence of C in S (same as strrchr).  */
	extern char *rindex(const char * __s, int __c);
	/*
	Return the position of the first bit set in I, or 0 if none are set.
	   The least-significant bit is position 1, the most-significant 32. 
	*/
	extern int ffs(int __i);
	/*
	The following two functions are non-standard but necessary for non-32 bit
	   platforms. 
	*/
	extern int ffsl(long int __l);
	extern int ffsll(long long int __ll);
	/* Compare S1 and S2, ignoring case.  */
	extern int strcasecmp(const char * __s1, const char * __s2);
	/* Compare no more than N chars of S1 and S2, ignoring case.  */
	extern int strncasecmp(const char * __s1, const char * __s2, size_t __n);
	/* POSIX.1-2008 extended locale interface (see locale.h).  */
	/*
	Definition of locale_t.
	   Copyright (C) 2017-2018 Free Software Foundation, Inc.
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
	/* Compare S1 and S2, ignoring case, using collation rules from LOC.  */
	extern int strcasecmp_l(const char * __s1, const char * __s2, locale_t __loc);
	/*
	Compare no more than N chars of S1 and S2, ignoring case, using
	   collation rules from LOC. 
	*/
	extern int strncasecmp_l(const char * __s1, const char * __s2, size_t __n, locale_t __loc);
	/*
	Set N bytes of S to 0.  The compiler will not delete a call to this
	   function, even if S is dead after the call. 
	*/
	extern void explicit_bzero(void * __s, size_t __n);
	/*
	Return the next DELIM-delimited token fromSTRINGP,
	   terminating it with a '\0', and update *STRINGP to point past it. 
	*/
	extern char *strsep(char * * __stringp, const char * __delim);
	/* Return a string describing the meaning of the signal number in SIG.  */
	extern char *strsignal(int __sig);
	/* Copy SRC to DEST, returning the address of the terminating '\0' in DEST.  */
	extern char *__stpcpy(char * __dest, const char * __src);
	extern char *stpcpy(char * __dest, const char * __src);
	/*
	Copy no more than N characters of SRC to DEST, returning the address of
	   the last character written into DEST. 
	*/
	extern char *__stpncpy(char * __dest, const char * __src, size_t __n);
	extern char *stpncpy(char * __dest, const char * __src, size_t __n);
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
	
		ISO C99 Standard: 7.5 Errors	<errno.h>
	
	*/
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
	/* The system-specific definitions of the E constants, as macros.  */
	/*
	Error constants.  Linux specific version.
	   Copyright (C) 1996-2018 Free Software Foundation, Inc.
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
	/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
	/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
	/*
	
	 This error code is special: arch syscall entry code will return
	 * -ENOSYS if users try to call a syscall that doesn't exist.  To keep
	 * failures of syscalls that really do exist distinguishable from
	 * failures due to attempts to use a nonexistent syscall, syscall
	 * implementations should refrain from returning -ENOSYS.
	
	*/
	/* for robust mutexes */
	/* Older Linux headers do not define these constants.  */
	/*
	When included from assembly language, this header only provides the
	   E constants. 
	*/
	/* The error code set by various library functions.  */
	extern int *__errno_location(void );
	struct named_avimod_c_18166
	{
		unsigned long key;
		unsigned long pos;
		unsigned long len;
	};
	
	typedef struct named_avimod_c_18166 video_index_entry;
	struct named_avimod_c_18196
	{
		unsigned long pos;
		unsigned long len;
		unsigned long tot;
	};
	
	typedef struct named_avimod_c_18196 audio_index_entry;
	struct track_s
	{
		long a_fmt;
		/* Audio format, see #defines below */ 
		long a_chans;
		/* Audio channels, 0 for no audio */ 
		long a_rate;
		/* Rate in Hz */ 
		long a_bits;
		/* bits per audio sample */ 
		long mp3rate;
		/* mp3 bitrate kbs*/ 
		long audio_strn;
		/* Audio stream number */ 
		long audio_bytes;
		/* Total number of bytes of audio data */ 
		long audio_chunks;
		/* Chunks of audio data in the file */ 
		char audio_tag[4];
		/* Tag of audio data */ 
		long audio_posc;
		/* Audio position: chunk */ 
		long audio_posb;
		/* Audio position: byte within chunk */ 
		long a_codech_off;
		/* absolut offset of audio codec information */ 
		long a_codecf_off;
		/* absolut offset of audio codec information */ 
		audio_index_entry * audio_index;
	};
	
	typedef struct track_s track_t;
	struct named_avimod_c_18311
	{
		long fdes;
		/* File descriptor of AVI file */ 
		long mode;
		/* 0 for reading, 1 for writing */ 
		long width;
		/* Width  of a video frame */ 
		long height;
		/* Height of a video frame */ 
		double fps;
		/* Frames per second */ 
		char compressor[8];
		/* Type of compressor, 4 bytes + padding for 0 byte */ 
		char compressor2[8];
		/* Type of compressor, 4 bytes + padding for 0 byte */ 
		long video_strn;
		/* Video stream number */ 
		long video_frames;
		/* Number of video frames */ 
		char video_tag[4];
		/* Tag of video data */ 
		long video_pos;
		/* Number of next frame to be read
							   (if index present) */ 
		unsigned long max_len;
		/* maximum video chunk present */ 
		track_t track[8];
		// up to AVI_MAX_TRACKS audio tracks supported 
		unsigned long pos;
		/* position in file */ 
		long n_idx;
		/* number of index entries actually filled */ 
		long max_idx;
		/* number of index entries actually allocated */ 
		long v_codech_off;
		/* absolut offset of video codec (strh) info */ 
		long v_codecf_off;
		/* absolut offset of video codec (strf) info */ 
		unsigned char (* idx)[16];
		/* index entries (AVI idx1 tag) */ 
		video_index_entry * video_index;
		unsigned long last_pos;
		/* Position of last frame written */ 
		unsigned long last_len;
		/* Length of last frame written */ 
		int must_use_index;
		/* Flag if frames are duplicated */ 
		unsigned long movi_start;
		int anum;
		// total number of audio tracks  
		int aptr;
	};
	
	/* current audio working track  */
	typedef struct named_avimod_c_18311 avi_t;
	/* The error codes delivered by avi_open_input_file */
	/* Possible Audio formats */
	avi_t *AVI_open_output_file(char * filename);
	void AVI_set_video(avi_t * AVI, int width, int height, double fps, char * compressor);
	void AVI_set_audio(avi_t * AVI, int channels, long rate, int bits, int format, long mp3rate);
	int AVI_write_frame(avi_t * AVI, char * data, long bytes, int keyframe);
	int AVI_dup_frame(avi_t * AVI);
	int AVI_write_audio(avi_t * AVI, char * data, long bytes);
	int AVI_append_audio(avi_t * AVI, char * data, long bytes);
	long AVI_bytes_remain(avi_t * AVI);
	int AVI_close(avi_t * AVI);
	long AVI_bytes_written(avi_t * AVI);
	avi_t *AVI_open_input_file(char * filename, int getIndex);
	avi_t *AVI_open_fd(int fd, int getIndex);
	int avi_parse_input_file(avi_t * AVI, int getIndex);
	long AVI_audio_mp3rate(avi_t * AVI);
	long AVI_video_frames(avi_t * AVI);
	int AVI_video_width(avi_t * AVI);
	int AVI_video_height(avi_t * AVI);
	double AVI_frame_rate(avi_t * AVI);
	char *AVI_video_compressor(avi_t * AVI);
	int AVI_audio_channels(avi_t * AVI);
	int AVI_audio_bits(avi_t * AVI);
	int AVI_audio_format(avi_t * AVI);
	long AVI_audio_rate(avi_t * AVI);
	long AVI_audio_bytes(avi_t * AVI);
	long AVI_audio_chunks(avi_t * AVI);
	long AVI_max_video_chunk(avi_t * AVI);
	long AVI_frame_size(avi_t * AVI, long frame);
	long AVI_audio_size(avi_t * AVI, long frame);
	int AVI_seek_start(avi_t * AVI);
	int AVI_set_video_position(avi_t * AVI, long frame);
	long AVI_get_video_position(avi_t * AVI, long frame);
	long AVI_read_frame(avi_t * AVI, char * vidbuf, int * keyframe);
	int AVI_set_audio_position(avi_t * AVI, long byte);
	int AVI_set_audio_bitrate(avi_t * AVI, long bitrate);
	long AVI_read_audio(avi_t * AVI, char * audbuf, long bytes);
	long AVI_audio_codech_offset(avi_t * AVI);
	long AVI_audio_codecf_offset(avi_t * AVI);
	long AVI_video_codech_offset(avi_t * AVI);
	long AVI_video_codecf_offset(avi_t * AVI);
	int AVI_read_data(avi_t * AVI, char * vidbuf, long max_vidbuf, char * audbuf, long max_audbuf, long * len);
	void AVI_print_error(char * str);
	char *AVI_strerror();
	char *AVI_syserror();
	int AVI_scan(char * name);
	int AVI_dump(char * name, int mode);
	char *AVI_codec2str(short cc);
	int AVI_file_check(char * import_file);
	void AVI_info(avi_t * avifile);
	uint64_t AVI_max_size();
	int avi_update_header(avi_t * AVI);
	int AVI_set_audio_track(avi_t * AVI, int track);
	int AVI_get_audio_track(avi_t * AVI);
	int AVI_audio_tracks(avi_t * AVI);
	struct riff_struct
	{
		unsigned char id[4];
		/* RIFF */ 
		unsigned long len;
		unsigned char wave_id[4];
	};
	
	/* WAVE */
	struct chunk_struct
	{
		unsigned char id[4];
		unsigned long len;
	};
	
	struct common_struct
	{
		unsigned short wFormatTag;
		unsigned short wChannels;
		unsigned long dwSamplesPerSec;
		unsigned long dwAvgBytesPerSec;
		unsigned short wBlockAlign;
		unsigned short wBitsPerSample;
	};
	
	/* Only for PCM */
	struct wave_header
	{
		struct riff_struct riff;
		struct chunk_struct format;
		struct common_struct common;
		struct chunk_struct data;
	};
	
	struct chunk_struct;
	
	struct AVIStreamHeader
	{
		long fccType;
		long fccHandler;
		long dwFlags;
		long dwPriority;
		long dwInitialFrames;
		long dwScale;
		long dwRate;
		long dwStart;
		long dwLength;
		long dwSuggestedBufferSize;
		long dwQuality;
		long dwSampleSize;
	};
	
	/* =============================================================================================================================================================================================================== */
	/* 	DEFINE INCLUDE */
	/* =============================================================================================================================================================================================================== */
	float *chop_flip_image(char * image, int height, int width, int cropped, int scaled, int converted);
	float *get_frame(avi_t * cell_file, int frame_num, int cropped, int scaled, int converted);
	/* =============================================================================================================================================================================================================== */
	/* 	FUNCTIONS */
	/* =============================================================================================================================================================================================================== */
	/* Flips the specified image and crops it to the specified dimensions */
	/* If scaled == true, all values are scaled to the range [0.0, 1.0 */
	float *chop_flip_image(char * image, int height, int width, int cropped, int scaled, int converted)
	{
		/* fixed dimensions for cropping or not cropping, square vertices starting from initial point in top left corner going down and right */
		int top;
		int bottom;
		int left;
		int right;
		int height_new = (bottom-top)+1;
		int width_new = (right-left)+1;
		int i, j;
		float * result = (float * )malloc((height_new*width_new)*sizeof (float));
		float temp;
		float * result_converted = (float * )malloc((height_new*width_new)*sizeof (float));
		if (cropped==1)
		{
			top=0;
			bottom=0;
			left=0;
			right=0;
		}
		else
		{
			top=0;
			bottom=(height-1);
			left=0;
			right=(width-1);
		}
		/* dimensions of new cropped image */
		/* counters */
		/* allocate memory for croppedflipped frame */
		/* cropflip and scale frame */
		if (scaled)
		{
			float scale = 1.0/255.0;
			#pragma loop name chop_flip_image#0 
			for (i=0; i<height_new; i ++ )
			{
				/* rows */
				#pragma loop name chop_flip_image#0#0 
				for (j=0; j<width_new; j ++ )
				{
					/* colums */
					temp=(((float)image[(((height-1)-(i+top))*width)+(j+left)])*scale);
					if (temp<0)
					{
						result[(i*width_new)+j]=(temp+256);
					}
					else
					{
						result[(i*width_new)+j]=temp;
					}
				}
			}
		}
		else
		{
			#pragma loop name chop_flip_image#1 
			for (i=0; i<height_new; i ++ )
			{
				/* rows */
				#pragma loop name chop_flip_image#1#0 
				for (j=0; j<width_new; j ++ )
				{
					/* colums */
					temp=((float)image[(((height-1)-(i+top))*width)+(j+left)]);
					if (temp<0)
					{
						result[(i*width_new)+j]=(temp+256);
					}
					else
					{
						result[(i*width_new)+j]=temp;
					}
				}
			}
		}
		/* convert storage method (from row-major to column-major) */
		if (converted==1)
		{
			#pragma loop name chop_flip_image#2 
			for (i=0; i<width_new; i ++ )
			{
				/* rows */
				#pragma loop name chop_flip_image#2#0 
				for (j=0; j<height_new; j ++ )
				{
					/* colums */
					result_converted[(i*height_new)+j]=result[(j*width_new)+i];
				}
			}
		}
		else
		{
			result_converted=result;
		}
		free(result);
		/* return */
		return result_converted;
	}
	
	/* Returns the specified frame from the specified video file */
	/* If cropped == true, the frame is cropped to pre-determined dimensions */
	/*  (hardcoded to the boundaries of the blood vessel in the test video) */
	/* If scaled == true, all values are scaled to the range [0.0, 1.0] */
	float *get_frame(avi_t * cell_file, int frame_num, int cropped, int scaled, int converted)
	{
		/* variable */
		int dummy;
		int width = AVI_video_width(cell_file);
		int height = AVI_video_height(cell_file);
		int status;
		/* There are 600 frames in this file (i.e. frame_num = 600 causes an error) */
		char * image_buf = (char * )malloc((width*height)*sizeof (char));
		float * image_chopped;
		AVI_set_video_position(cell_file, frame_num);
		/* Read in the frame from the AVI */
		status=AVI_read_frame(cell_file, image_buf,  & dummy);
		if (status==( - 1))
		{
			AVI_print_error((char * )"Error with AVI_read_frame");
			exit( - 1);
		}
		/* The image is read in upside-down, so we need to flip it */
		image_chopped=chop_flip_image(image_buf, height, width, cropped, scaled, converted);
		/* free image buffer */
		free(image_buf);
		/* return */
		return image_chopped;
	}
