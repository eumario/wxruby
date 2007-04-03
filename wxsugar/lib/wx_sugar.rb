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
# As of version 0.1.14, the WxSugar extensions require the latest
# version of WxRuby2, preview 0.0.39. Support for the old series of
# WxRuby (version 0.6.0) has now been dropped. 
# 
# The simplest way to use WxSugar is to load all the behaviours. You
# should load the wx library first:
#
#  require 'wx'
#  require 'wx_sugar'
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
# of all relevant Wx classes, and affects all new instances. The
# following are listed in order of interest
#
# [accessors] 
#  Provide ruby-style getters, setters and question-mark methods
# [keyword_constructors] 
#  Use keyword-style hash arguments to construct widgets
# [event_connector] 
#  Neater syntax for connecting event listeners
# [layout] 
#  Easy interface to using WxWidgets Sizers to arrange controls
# [wx_classes]
#  Useful ruby methods added to individual Wx classes.
# [menu] 
#  Create and update menus without a mess of system ids
# [enumerable controls]
#  Treat list-like GUI controls as Ruby enumerables with an +each+ method
# [delayed_constructors] 
#  Required by +layout+, of limited independent interest
#
# === Deprecated extensions
#
# This module is deprecated and will soon be removed.
#
# [itemdata.rb] 
#  Linking ruby objects with wx controls; use the
#  get/set_item_data methods in core wxruby2 instead.


require 'wx_sugar/all'
