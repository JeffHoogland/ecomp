#!/bin/sh

srcdir=$(dirname "$0")
test -z "$srcdir" && srcdir=.

ORIGDIR=`pwd`
cd $srcdir

mkdir -p m4
aclocal -I m4 --install || exit 1
autoreconf --verbose --force --install || exit 1
intltoolize --copy --force --automake || exit 1

cd $ORIGDIR || exit $?

if [ -z "$NOCONFIGURE" ]; then
    "$srcdir/configure" "$@" || exit 1
fi
