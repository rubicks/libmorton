# github.com/rubicks/morton/Makefile.am

ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS =        \
  -Wall            \
  -Wconversion     \
  -Werror          \
  -Wextra          \
  -pedantic-errors \
  -std=c99

noinst_LTLIBRARIES = libcommon.la
libcommon_la_SOURCES = morton.h morton.c

# When check_PROGRAMS are dynamically linked against lib_LTLIBRARIES, automake
# generates them as posix shell scripts.
#
# When check_PROGRAMS are statically linked against lib_LTLIBRARIES, automake
# generates them as stand-alone binaries.

lib_LTLIBRARIES = libmorton.la
libmorton_la_SOURCES =
libmorton_la_LIBADD = libcommon.la
include_HEADERS = morton.h

check_PROGRAMS = \
  test_impl      \
  test_iface

test_impl_SOURCES = test/impl.c

test_iface_SOURCES = test/iface.c
test_iface_LDADD = libmorton.la
test_iface_LDFLAGS = -static

TESTS = $(check_PROGRAMS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmorton.pc
