# rakelinux.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project


#############################
# platform-dependent settings

use_wx_config

$extra_ldflags = '-shared'

$debug = false
if($debug)
    $wx_libs.sub!(/lwx_gtk/, 'lwx_gtkd')
end

# this isn't implemented yet, but as of 2005-07-24 
# it worked on Ubuntu with wxgtk-2.5.3
if($link_wx_statically)
	$extra_libs = "-Wl,-Bdynamic -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 " + 
	"-lgdk_pixbuf-2.0 -lpangoxft-1.0 -lpangox-1.0 -lpango-1.0 " + 
	"-lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lglib-2.0 " +
	"-ljpeg -lpng -ltiff" 
	libs = $wx_libs.split(' ')
	libs.collect! do | lib |
		if(lib =~ /lwx_/)
			lib = "-Wl,-Bstatic #{lib} -Wl,-Bdynamic "
		end
		lib
	end
	$wx_libs = libs.join(' ')
end
