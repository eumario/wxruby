%w[ accessors delayed_constructors event_connector 
    keyword_constructors layout menu wx_classes ].each do | ext_feature |
  require 'wx_sugar/' + ext_feature    
end 

begin
  require 'wx_sugar/version'
rescue LoadError
  WxSugar::VERSION = ''
end
