## Process this file with automake to produce Makefile.in
PFLAGS=-module -avoid-version -no-undefined

libthumbnail_la_LDFLAGS = $(PFLAGS)
libthumbnail_la_LIBADD = @ECOMP_LIBS@
libthumbnail_la_SOURCES = thumbnail_options.c \
			  thumbnail_options.h \
			  thumbnail.c         \
			  thumbnail_tex.h

AM_CPPFLAGS =                           \
	-I$(top_srcdir)/include             \
	@ECOMP_CFLAGS@                      \
	-DDATADIR='"$(compdatadir)"'        \
	-DLIBDIR='"$(libdir)"'              \
	-DLOCALEDIR="\"@datadir@/locale\""  \
	-DIMAGEDIR='"$(imagedir)"'          

moduledir = $(plugindir)


module_LTLIBRARIES = libthumbnail.la

CLEANFILES = *_options.c *_options.h

thumbnail_options.h: ../metadata/thumbnail.xml
		$(BCOP_BIN) --header $@ $<

thumbnail_options.c: ../metadata/thumbnail.xml thumbnail_options.h
		$(BCOP_BIN) --source $@ $<
