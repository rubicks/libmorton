# github.com/rubicks/libmorton/configure.ac

AC_PREREQ([2.69])
AC_INIT([libmorton],
        [m4_esyscmd_s([git describe --always --dirty --tags])],
        [rubicks00@gmail.com],
        [libmorton],
        [https://github.com/rubicks/libmorton])
AC_LANG_PUSH([C])
AC_CONFIG_SRCDIR([morton.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AM_INIT_AUTOMAKE([foreign subdir-objects dist-bzip2 dist-xz tar-pax])
LT_PREREQ([2.4.6])
#LT_INIT([dlopen])
#LT_INIT([disable-shared])
LT_INIT

# Checks for programs.
PKG_PROG_PKG_CONFIG([])
AC_PROG_CC_STDC

# Checks for header files.
AC_HEADER_STDC # stdlib, stdarg, string, float.h
AC_CHECK_HEADERS([limits.h],[],[AC_MSG_ERROR([limits.h missing])],[])
AC_CHECK_HEADERS([inttypes.h],[],[AC_MSG_ERROR([inttypes.h missing])],[])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE

AC_CHECK_DECL([__BYTE_ORDER__],
              [],[AC_MSG_ERROR([undefined __BYTE_ORDER__])])
AC_CHECK_DECL([__ORDER_LITTLE_ENDIAN__],
              [],[AC_MSG_ERROR([undefined __ORDER_LITTLE_ENDIAN__])])
AC_CHECK_DECL([__ORDER_BIG_ENDIAN__],
              [],[AC_MSG_ERROR([undefined __ORDER_BIG_ENDIAN__])])

AC_TYPE_INT8_T
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_UINT8_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T

AC_CONFIG_FILES([Makefile libmorton.pc])
AC_OUTPUT
