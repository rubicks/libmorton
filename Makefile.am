# github.com/rubicks/morton/Makefile.am


ACLOCAL_AMFLAGS = -I m4

AM_CFLAGS =        \
  -Wall            \
  -Wconversion     \
  -Werror          \
  -Wextra          \
  -pedantic-errors


lib_LTLIBRARIES = libmorton.la
libmorton_la_SOURCES = morton.h morton.c
include_HEADERS = morton.h


# bin_PROGRAMS = demo
# demo_SOURCES = demo.cc
# demo_LDADD = libmorton.la


# When check_PROGRAMS are linked against dynamic lib_LTLIBRARIES, automake
# generates them as posix shell scripts.
#
# When check_PROGRAMS are linked against static noinst_LTLIBRARIES, automake
# generates them as stand-alone binaries.

noinst_LTLIBRARIES = libcommon.la
libcommon_la_SOURCES = $(libmorton_la_SOURCES)

check_PROGRAMS = \
  test_impl      \
  test_iface

test_impl_SOURCES = test/impl.c

test_iface_SOURCES = test/iface.c
test_iface_LDADD = libmorton.la

TESTS = $(check_PROGRAMS)
