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
