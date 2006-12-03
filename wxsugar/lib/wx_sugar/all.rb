# = WxSugar
# 
# WxSugar is a set of additions to the WxRuby API, written in pure
# ruby. They're intended to:
#  
# * Make some tricky WxWidgets things easier and more consistent
# * Reduce repetitiveness and redundancy for common tasks
# * Make code more expressive
# * Make code more idiomatically Rubyish
#
# Not everyone will like all the extensions to WxRuby here. So the
# Sugar modules:
#
# * Can generally be used separately, without depending on each other
# * Supplement rather than replace the underlying 'raw' API
# 
# == Using WxSugar
# 
# The extensions can currently be used with WxRuby2 or the old WxRuby
# (0.6.0). WxRuby2 is strongly recommended, and support for the old
# series may be dropped in the future.
# 
# The simplest way to use WxSugar is to load all the behaviours. You
# should load the wx library first:
#
#  require 'wx'
#   # OR ... old non-SWIG beta veresion
#  require 'wxruby'
# 
#  require 'wx_sugar/all'
#  ... 
# 
# If you only want to load specific WxSugar behaviours, just +require+
# the desired extensions only
#  
#  require 'wx_sugar/keyword_constructors'
#  require 'wx_sugar/acccessors'
#
# == Overview of extensions
# 
# The following are the WxSugar behaviours that are available. In
# general you require one of these extensions, it modifies the behaviour
# of all relevant Wx classes, and affects all new instances.
#
# [accessors] 
#  Provide ruby-style getters, setters and question-mark methods
# [delayed_constructors] 
#  Required by +layout+, of limited independent interest
# [event_connector] 
#  Neater syntax for connecting event listeners
# [keyword_constructors] 
#  Use keyword-style hash arguments to construct widgets
# [layout] 
#  Easy interface to using WxWidgets Sizers to arrange controls
# [menu] 
#  Create and update menus without a mess of system ids
# [wx_classes]
#  Useful ruby methods added to individual Wx classes.
#
# === Deprecated extensions
#
# This module is deprecated and will soon be removed.
#
# [itemdata.rb] 
#  Linking ruby objects with wx controls; use the
#  get/set_item_data methods in core wxruby2 instead.


%w[ accessors delayed_constructors event_connector 
    keyword_constructors layout menu wx_classes ].each do | ext_feature |
  require 'wx_sugar/' + ext_feature    
end 

begin
  require 'wx_sugar/version'
rescue LoadError
  WxSugar::VERSION = ''
end
