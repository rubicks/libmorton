# github.com/rubicks/libmorton/Makefile.am

ACLOCAL_AMFLAGS = -I m4

AM_CPPFLAGS = \
  -Wundef \
  -Wunused

AM_CFLAGS = \
  -Wall \
  -Wconversion \
  -Werror \
  -Wextra \
  -pedantic-errors \
  -std=c99

include_HEADERS = morton.h

# When check_PROGRAMS are dynamically linked against lib_LTLIBRARIES, automake
# generates them as posix shell scripts.
#
# When check_PROGRAMS are statically linked against lib_LTLIBRARIES, automake
# generates them as stand-alone binaries.

lib_LTLIBRARIES = libmorton.la
libmorton_la_SOURCES = morton.c morton.h binlit.h
libmorton_la_LDFLAGS = -export-symbols-regex '^morton_'

check_PROGRAMS = \
  test_binlit \
  test_impl \
  test_iface

test_binlit_SOURCES = test/binlit.c

test_impl_SOURCES = test/impl.c

test_iface_SOURCES = test/iface.c
test_iface_LDADD = libmorton.la
test_iface_LDFLAGS = -static

TESTS = $(check_PROGRAMS)

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = libmorton.pc
