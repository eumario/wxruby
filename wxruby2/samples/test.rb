#!/usr/bin/env ruby
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

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

#Wx::entry

#o = Wx::Object.new

class MyApp < Wx::App
    def wx_initialize
        puts("called wx_initialize\n")
        return false
    end
    
    def initialized
        puts("called initialized\n")
        return super
    end
    
	def on_init
		puts("on_init")
        f = Wx::Frame.new(nil, -1, "wxRuby/SWIG Example")
        f.show
        set_top_window(f)
		return super
	end
    
    def on_init_gui
        puts("on_init_gui")
        return super
    end
    
    def on_run
        puts("on_run")
        return super
    end
    
    def on_exit
        puts("on_exit")
        return super
    end
    
    def clean_up
        puts("Skipping cleanup")
    end
    
    def set_app_name(name)
        puts("setting app name to #{name}")
        return super(name)
    end
end

a = MyApp.new
#Wx::disown_App(a)
#puts("Vendor name: #{a.get_vendor_name}")
#a.set_vendor_name("Ted")
#puts("Vendor name: #{a.get_vendor_name}")

#a.on_init

puts("Calling main_loop\n")
a.main_loop
puts("Returned from main_loop\n")
GC.start
puts("Completed gc\n")
