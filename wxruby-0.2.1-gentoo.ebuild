# Copyright 1999-2003 Gentoo Technologies, Inc.
# Distributed under the terms of the GNU General Public License v2
# $Header$


DESCRIPTION="wxRuby are Ruby language bindings for wxWindows GUI toolkit"
HOMEPAGE="http://rubyforge.org/projects/wxruby/"
SRC_URI="http://rubyforge.org/download.php/401/${PN}-src-${PV}.tar.gz"
LICENSE="wxWinLL-3"
SLOT="0"
KEYWORDS="~x86"
IUSE=""
DEPEND=">=dev-lang/ruby-1.8.0
	>=x11-libs/wxGTK-2.4.1"

src_compile() {
	if [ `use unicode` ]; 
	then
	    eerror "wxruby needs wxGTK compiled without 'unicode' support. Run:"
	    eerror "USE='-unicode' emerge wxGTK wxruby"
	    die
	else
	    cd src
	    ruby extconf.rb || die
	    make || die
	fi
}

src_install() {
	cd src
	DESTDIR=${D}
	local rubyhdr=$(ruby -r rbconfig -e 'print Config::CONFIG["sitearchdir"]')	
	cp Makefile Makefile.orig 
	cat Makefile.orig  \
	| sed "s:hdrdir = .*:hdrdir = ${rubyhdr}:" \
	> Makefile || die "sed failed"
	#addwrite $(ruby -r rbconfig -e 'print Config::CONFIG["sitearchdir"]')
	make install || die "make install failed"
	for doc in ../COPYING.LIB ../ChangeLog ../README ../README.linux \
	../README.mingw ../README.mswin ../README.osx; do
	    [ -s "$doc" ] && dodoc $doc
	done
	if [[ -d sample ]]; then
	    dodir /usr/share/doc/${PF}
	    cp -a sample ${D}/usr/share/doc/${PF} || die "cp samples failed"
	fi
}

