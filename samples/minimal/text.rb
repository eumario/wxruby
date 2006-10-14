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
include Wx

class MyFrame < Frame
  def initialize()
    super(nil,-1,'test')

        panel = self#Panel.new(self)
	@m_spintext = TextCtrl.new( panel, -1, '')
  	#@m_spintext.destroy
  end
end

class RbApp < App
  def on_init
    frame = MyFrame.new
    frame.show(TRUE)
  end
end

a = RbApp.new
a.main_loop()
