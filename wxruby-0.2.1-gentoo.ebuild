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
	    einfo "wxruby needs wxGTK compiled without 'unicode' support."
	    einfo "Please re-emerge wxGTK."
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
	make install || die
	dodoc ../ChangeLog ../README ../README.linux ../README.mingw ../README.mswin ../README.osx
	cp -r ../samples ${D}/usr/share/doc/${PF}
}

