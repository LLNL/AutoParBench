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
/* 	TIMER CODE */
/* ===============================================================================================================================================================================================================200 */
/* ======================================================================================================================================================150 */
/* 	INCLUDEDEFINE */
/* ======================================================================================================================================================150 */
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
enum timer_c_23 { P_ALL, P_PID, P_PGID };
/* Wait for any child.  */
/* Wait for specified process.  */
/* Wait for members of process group.  */
typedef enum timer_c_23 idtype_t;
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
struct named_timer_c_40
{
	int quot;
	/* Quotient.  */ 
	int rem;
};

/* Remainder.  */
typedef struct named_timer_c_40 div_t;
/* Returned by `ldiv'.  */
struct named_timer_c_59
{
	long int quot;
	/* Quotient.  */ 
	long int rem;
};

/* Remainder.  */
typedef struct named_timer_c_59 ldiv_t;
/* Returned by `lldiv'.  */
struct named_timer_c_83
{
	long long int quot;
	/* Quotient.  */ 
	long long int rem;
};

/* Remainder.  */
typedef struct named_timer_c_83 lldiv_t;
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
struct named_timer_c_1195
{
	int __val[2];
};

typedef struct named_timer_c_1195 __fsid_t;
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
struct named_timer_c_1933
{
	unsigned long int __val[(1024/(8*sizeof (unsigned long int)))];
};

typedef struct named_timer_c_1933 __sigset_t;
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
struct named_timer_c_2028
{
	/* XPG4.2 requires this member name.  Otherwise avoid the name
	       from the global namespace.  */ 
	__fd_mask __fds_bits[(1024/(8*((int)sizeof (__fd_mask))))];
};

typedef struct named_timer_c_2028 fd_set;
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
struct named_timer_c_2381
{
	unsigned int __low;
	unsigned int __high;
};

union named_timer_c_2366
{
	unsigned long long int __wseq;
	struct named_timer_c_2381 __wseq32;
};

struct named_timer_c_2420
{
	unsigned int __low;
	unsigned int __high;
};

union named_timer_c_2405
{
	unsigned long long int __g1_start;
	struct named_timer_c_2420 __g1_start32;
};

struct __pthread_cond_s
{
	union named_timer_c_2366 ;
	union named_timer_c_2405 ;
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
union named_timer_c_2502
{
	char __size[4];
	int __align;
};

typedef union named_timer_c_2502 pthread_mutexattr_t;
/*
Data structure for condition variable handling.  The structure of
   the attribute type is not exposed on purpose. 
*/
union named_timer_c_2524
{
	char __size[4];
	int __align;
};

typedef union named_timer_c_2524 pthread_condattr_t;
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
union named_timer_c_2593
{
	struct __pthread_mutex_s __data;
	char __size[40];
	long int __align;
};

typedef union named_timer_c_2593 pthread_mutex_t;
union named_timer_c_2624
{
	struct __pthread_cond_s __data;
	char __size[48];
	long long int __align;
};

typedef union named_timer_c_2624 pthread_cond_t;
/*
Data structure for reader-writer lock variable handling.  The
   structure of the attribute type is deliberately not exposed. 
*/
union named_timer_c_2658
{
	struct __pthread_rwlock_arch_t __data;
	char __size[56];
	long int __align;
};

typedef union named_timer_c_2658 pthread_rwlock_t;
union named_timer_c_2689
{
	char __size[8];
	long int __align;
};

typedef union named_timer_c_2689 pthread_rwlockattr_t;
/* POSIX spinlock data type.  */
typedef volatile int pthread_spinlock_t;
/*
POSIX barriers data type.  The structure of the type is
   deliberately not exposed. 
*/
union named_timer_c_2722
{
	char __size[32];
	long int __align;
};

typedef union named_timer_c_2722 pthread_barrier_t;
union named_timer_c_2746
{
	char __size[4];
	int __align;
};

typedef union named_timer_c_2746 pthread_barrierattr_t;
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
Structure crudely representing a timezone.
   This is obsolete and should never be used. 
*/
struct timezone
{
	int tz_minuteswest;
	/* Minutes west of GMT.  */ 
	int tz_dsttime;
};

/* Nonzero if DST is ever in effect.  */
typedef struct timezone * __timezone_ptr_t;
/*
Get the current time of day and timezone information,
   putting it intoTV and *TZ.  If TZ is NULL, *TZ is not filled.
   Returns 0 on success, -1 on errors.
   NOTE: This form of timezone information is obsolete.
   Use the functions and variables declared in <time.h> instead. 
*/
extern int gettimeofday(struct timeval * __tv, __timezone_ptr_t __tz);
/*
Set the current time of day and timezone information.
   This call is restricted to the super-user. 
*/
extern int settimeofday(const struct timeval * __tv, const struct timezone * __tz);
/*
Adjust the current time of day by the amount in DELTA.
   If OLDDELTA is not NULL, it is filled in with the amount
   of time adjustment remaining to be done from the last `adjtime' call.
   This call is restricted to the super-user. 
*/
extern int adjtime(const struct timeval * __delta, struct timeval * __olddelta);
/* Values for the first argument to `getitimer' and `setitimer'.  */
enum __itimer_which { ITIMER_REAL = 0, ITIMER_VIRTUAL = 1, ITIMER_PROF = 2 };
/* Timers run in real time.  */
/* Timers run only when the process is executing.  */
/*
Timers run when the process is executing and when
       the system is executing on behalf of the process. 
*/
/*
Type of the second argument to `getitimer' and
   the second and third arguments `setitimer'. 
*/
struct itimerval
{
	/* Value to put into `it_value' when the timer expires.  */ 
	struct timeval it_interval;
	/* Time to the next timer expiration.  */ 
	struct timeval it_value;
};

struct timeval;

typedef int __itimer_which_t;
/*
SetVALUE to the current setting of timer WHICH.
   Return 0 on success, -1 on errors. 
*/
extern int getitimer(__itimer_which_t __which, struct itimerval * __value);
/*
Set the timer WHICH toNEW.  If OLD is not NULL,
   set *OLD to the old value of timer WHICH.
   Returns 0 on success, -1 on errors. 
*/
extern int setitimer(__itimer_which_t __which, const struct itimerval * __new, struct itimerval * __old);
/*
Change the access time of FILE to TVP[0] and the modification time of
   FILE to TVP[1].  If TVP is a null pointer, use the current time instead.
   Returns 0 on success, -1 on errors. 
*/
extern int utimes(const char * __file, const struct timeval __tvp[2]);
/* Same as `utimes', but does not follow symbolic links.  */
extern int lutimes(const char * __file, const struct timeval __tvp[2]);
/* Same as `utimes', but takes an open file descriptor instead of a name.  */
extern int futimes(int __fd, const struct timeval __tvp[2]);
/*
Convenience macros for operations on timevals.
   NOTE: `timercmp' does not work for >= or <=. 
*/
/* ======================================================================================================================================================150 */
/* 	FUNCTIONS */
/* ======================================================================================================================================================150 */
/* ====================================================================================================100 */
/* 	DISPLAY TIME */
/* ====================================================================================================100 */
/* Returns the current system time in microseconds */
long long get_time()
{
	struct timeval tv;
	long long _ret_val_0;
	gettimeofday( & tv, (void * )0);
	_ret_val_0=((tv.tv_sec*1000000)+tv.tv_usec);
	return _ret_val_0;
}
