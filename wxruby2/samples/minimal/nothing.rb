#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems'
    require 'wx'
  rescue LoadError
    raise no_wx_err
  end
end

# This is the minimum code to start a WxRuby app - create a Frame, and
# show it.
Wx::App.run do 
  frame = Wx::Frame.new(nil, :title => "Minimal wxRuby App")
  frame.show
end
