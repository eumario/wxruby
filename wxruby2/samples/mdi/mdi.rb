#! /usr/bin/env ruby

# MDI sample for wxRuby
# slapped together quickly by Kevin Smith


require 'wx'

ID_NEXT = 1
ID_PREVIOUS = 2
ID_CASCADE = 3
ID_TILE = 4
ID_CREATE = 5
ID_CLOSE = 6
ID_EXIT = 99

class MyFrame < Wx::MDIParentFrame
  def initialize(title)
    super(nil, -1, title)
    
    @child_number = 0
    
    menuFile = Wx::Menu.new
    menuFile.append(ID_EXIT, "E&xit\tAlt-X")
    menuMDI = Wx::Menu.new
    menuMDI.append(ID_NEXT, "&Next Child\tCtrl-F6")
    menuMDI.append(ID_PREVIOUS, "&Previous Child")
    menuMDI.append_separator()
    menuMDI.append(ID_CASCADE, "&Cascade")
    menuMDI.append(ID_TILE, "&Tile")
    menuMDI.append_separator()
    menuMDI.append(ID_CREATE, "&Add Child")
    menuMDI.append(ID_CLOSE, "&Remove Child\tCtrl-F4")
    menuBar = Wx::MenuBar.new
    menuBar.append(menuFile, "&File")
    menuBar.append(menuMDI, "&Window")
    set_menu_bar(menuBar)
    
    evt_menu(ID_EXIT) { close }
    evt_menu(ID_NEXT) { activate_next }
    evt_menu(ID_PREVIOUS) { activate_previous }
    evt_menu(ID_CASCADE) { cascade }
    evt_menu(ID_TILE) { tile }
    evt_menu(ID_CREATE) { create_child }
    evt_menu(ID_CLOSE) { on_close_child }
    
    create_status_bar(2).set_status_widths([100, -1])
    set_status_text("Some features only work on MS Windows", 1)

    create_child
    create_child
    create_child
  end
  
  def on_close_child
    active = get_active_child
    if(active)
        active.close
    end
  end
  
  def create_child
    @child_number += 1
    name = "Child #{@child_number.to_s}"
    Wx::MDIChildFrame.new(self, -1, name)
  end
end

class NothingApp < Wx::App
  def on_init
    frame = MyFrame.new("MDI App")
	frame.show
  end
end

a = NothingApp.new
a.main_loop()
