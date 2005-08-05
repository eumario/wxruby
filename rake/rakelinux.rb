# rakelinux.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license


#############################
# platform-dependent settings

use_wx_config

$extra_ldflags = '-shared'

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
