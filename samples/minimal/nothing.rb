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

# This is a really really bare minimum frame and application
class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
  end
end

class NothingApp < Wx::App
  def on_init
    frame = MyFrame.new("Minimal wxRuby App")
    frame.show
    return true
  end
end

NothingApp.new.main_loop
