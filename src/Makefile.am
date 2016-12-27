## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-std=c++11

AM_CFLAGS =\
	 -Wall\
	 -g

lib_LTLIBRARIES = liblinuxpwm.la


liblinuxpwm_la_SOURCES = \
	pwm-handler.cpp \
	pwm-pin.cpp \
	linux-pwm-pin.cpp

liblinuxpwm_la_LDFLAGS = 

liblinuxpwm_la_LIBADD = 



include_HEADERS = \
	liblinuxpwm.h
	pwm-handler.h \
	pwm-pin.h \ 
	linux-pwm-pin.h 

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = liblinuxpwm.pc

EXTRA_DIST = \
	liblinuxpwm.pc.in
