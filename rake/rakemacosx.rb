# rakemacosx.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project


#############################
# platform-dependent settings


use_wx_config

$cpp = "g++"
$ld = "g++"

=begin
    CONFIG['CC'] = "g++"
    CONFIG['LDSHARED'].gsub!("cc","g++")
    if (!$DEBUG)
      CONFIG['CFLAGS'].gsub!("-g","")
    else
      CONFIG['CFLAGS'].gsub!("-Os","-O0")
    end

    $CFLAGS += " `wx-config --cxxflags` "
    $CPPFLAGS += ' -x objective-c++ '
    $LDFLAGS += " `wx-config --libs` -framework Carbon "
=end

$extra_cppflags = '-x objective-c++'
$extra_ldflags = "-dynamic -bundle -undefined suppress -flat_namespace -framework Carbon"
#$extra_objs = "obj/macstart.o"
