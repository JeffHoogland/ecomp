## Process this file with automake to produce Makefile.in
PFLAGS=-module -avoid-version -no-undefined

libexpo_la_LDFLAGS = $(PFLAGS)
libexpo_la_LIBADD = @ECOMP_LIBS@ -lGLU
libexpo_la_SOURCES = expo_options.c expo_options.h expo.c

AM_CPPFLAGS =                           \
	-I$(top_srcdir)/include             \
	@ECOMP_CFLAGS@                      \
	-DDATADIR='"$(compdatadir)"'        \
	-DLIBDIR='"$(libdir)"'              \
	-DLOCALEDIR="\"@datadir@/locale\""  \
	-DIMAGEDIR='"$(imagedir)"'          \
	-DMETADATADIR=\"$(metadatadir)\"

moduledir = $(plugindir)


module_LTLIBRARIES = libexpo.la

CLEANFILES = *_options.c *_options.h

expo_options.h: ../metadata/expo.xml
		$(BCOP_BIN) --header $@ $<

expo_options.c: ../metadata/expo.xml expo_options.h
		$(BCOP_BIN) --source $@ $<
