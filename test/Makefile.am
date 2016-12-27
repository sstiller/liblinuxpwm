## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-std=c++11

bin_PROGRAMS =  \
	linuxpwmtest

linuxpwmtest_SOURCES =  \
	linuxpwmtest.cpp

linuxpwmtest_LDFLAGS = \
  -L$(abs_builddir)/../src/

linuxpwmtest_LDADD =  \
  -llinuxpwm