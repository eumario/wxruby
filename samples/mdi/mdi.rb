#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'

# Simple MDI-based parent frame with menus to create, cycle through and
# close child frames within in.
#
# NB: MDI is only properly implemented on Windows, and is simulated by
# using a Notebook on Linux and OS X. Therefore its use is not
# recommended for cross-platform applications. An alternative interface
# strategy may be to use separate frames, or possibly the AUI classes.
class MyFrame < Wx::MDIParentFrame
  def initialize(title)
    super(nil, :title => title, :size => [ 500, 400 ] )
    
    @child_number = 0
    
    menuFile = Wx::Menu.new
    menuFile.append(Wx::ID_EXIT, "E&xit\tAlt-X")
    evt_menu Wx::ID_EXIT, :close

    menuMDI = Wx::Menu.new
    menuMDI.append(Wx::ID_FORWARD, "&Next Child\tCtrl-F6")
    evt_menu Wx::ID_FORWARD, :activate_next
    menuMDI.append(Wx::ID_BACKWARD, "&Previous Child")
    evt_menu Wx::ID_BACKWARD, :activate_previous
    menuMDI.append_separator

    mi_cascade = menuMDI.append("&Cascade")
    evt_menu mi_cascade, :cascade
    mi_tile    = menuMDI.append("&Tile")
    evt_menu mi_tile, :tile
    menuMDI.append_separator

    menuMDI.append(Wx::ID_NEW, "&Add Child")
    evt_menu Wx::ID_NEW, :create_child
    menuMDI.append(Wx::ID_CLOSE, "&Remove Child\tCtrl-F4")
    evt_menu Wx::ID_CLOSE, :on_close_child

    menuBar = Wx::MenuBar.new
    menuBar.append(menuFile, "&File")
    menuBar.append(menuMDI, "&Window")

    self.menu_bar = menuBar
    
    create_status_bar(2).set_status_widths([100, -1])
    set_status_text("Some features only work on MS Windows", 1)

    3.times { create_child }
  end
  
  def on_close_child
    if active_child
        active_child.close
    end
  end
  
  def create_child
    @child_number += 1
    name = "Child #{@child_number.to_s}"
    Wx::MDIChildFrame.new(self, -1, name)
  end
end

class MDIApp < Wx::App
  def on_init
    frame = MyFrame.new("MDI App")
	frame.show
  end
end

MDIApp.new.main_loop
