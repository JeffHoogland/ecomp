## Process this file with automake to produce Makefile.in
PFLAGS=-module -avoid-version -no-undefined

libshift_la_LDFLAGS = $(PFLAGS)
libshift_la_LIBADD = @ECOMP_LIBS@
libshift_la_SOURCES = shift_options.c shift_options.h shift.c

AM_CPPFLAGS =                           \
	-I$(top_srcdir)/include             \
	@ECOMP_CFLAGS@                      \
	-DDATADIR='"$(compdatadir)"'        \
	-DLIBDIR='"$(libdir)"'              \
	-DLOCALEDIR="\"@datadir@/locale\""  \
	-DIMAGEDIR='"$(imagedir)"'          

moduledir = $(plugindir)


module_LTLIBRARIES = libshift.la

CLEANFILES = *_options.c *_options.h

shift_options.h: ../metadata/shift.xml
		$(BCOP_BIN) --header $@ $<

shift_options.c: ../metadata/shift.xml shift_options.h
		$(BCOP_BIN) --source $@ $<
