AM_CPPFLAGS =                       \
	@ECOMP_CFLAGS@                  \
	@GL_CFLAGS@                     \
	-I$(top_srcdir)/include	        \
	-DPLUGINDIR=\"$(plugindir)\"    \
	-DIMAGEDIR=\"$(imagedir)\"      \
	-DMETADATADIR=\"$(metadatadir)\"

bin_PROGRAMS = ecomorph

ecomorph_LDADD = @ECOMP_LIBS@ @GL_LIBS@ -lm -ldl
ecomorph_LDFLAGS = -export-dynamic
ecomorph_SOURCES =   \
	main.c	   \
	privates.c \
	texture.c  \
	display.c  \
	screen.c   \
	window.c   \
	event.c    \
	paint.c	   \
	option.c   \
	plugin.c   \
	fragment.c \
	matrix.c   \
	match.c    \
	metadata.c
