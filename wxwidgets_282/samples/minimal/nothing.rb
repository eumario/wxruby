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

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
  end
end

class NothingApp < Wx::App
  def on_init
    puts("in on_init")
    $frame = MyFrame.new("Minimal wxRuby App")
    puts("about to call show")
	$frame.show
    puts("returning from on_init")
    return true
  end
  
  def on_fatal_exception
    puts("on_fatal_exception")
  end
  
  def on_exit
    puts("on_exit")
    return super
  end
end

a = NothingApp.new
a.main_loop()
puts("back from main_loop...")
GC.start
puts("survived gc")
