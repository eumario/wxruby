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
# The extensions can currently be used with either WxRuby (0.6.0) or
# WxRuby2 (the SWIG version). To use all of the extensions, simple write
#
#   # EITHER ... New development
#  require 'wx'
#   # OR ... old non-SWIG beta veresion
#  require 'wxruby'
# 
#  require 'wx_sugar/all'
#  ... 
# 
# If you only want to load specific behaviours, just +require+ the
# desired extensions only
#  
#  require 'wx_sugar/keyword_constructors'
#  require 'wx_sugar/acccessors'
#
# == Overview of extensions
#
# [accessors.rb] 
#  Provide ruby-style getters, setters and question-mark methods
# [delayed_constructors.rb] 
#  For use with +layout+, limited independent interest
# [event_connector.rb] 
#  Neater syntax for connecting event listeners
# [itemdata.rb] 
#  Associate ruby objects with items in controls *NEEDS UPDATE*
# [keyword_constructors.rb] 
#  Use keyword-style hash arguments to construct widgets
# [layout.rb] 
#  Easy interface to using WxWidgets Sizers
# [menu.rb] 
#  Create and update menus without a mess of system ids

%w[ accessors delayed_constructors event_connector itemdata 
    keyword_constructors layout menu wx_classes ].each do | ext_feature |
  require 'wx_sugar/' + ext_feature    
end 
