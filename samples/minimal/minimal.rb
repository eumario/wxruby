require 'wx'
include Wx


Minimal_Quit = 1
Minimal_About = ID_ABOUT


class MyFrame < Frame
  def initialize(title,pos,size,style=DEFAULT_FRAME_STYLE)
    super(nil,-1,title,pos,size,style)

    if RUBY_PLATFORM == "WXMSW"
      set_icon(Icon.new("mondrian.ico",BITMAP_TYPE_ICO))
    else
      set_icon(Icon.new("mondrian.xpm",BITMAP_TYPE_XPM))
    end

    menuFile = Menu.new("")   # Parameter should NOT be needed!
    helpMenu = Menu.new("")   # Parameter should NOT be needed!
    helpMenu.append(Minimal_About, "&About...\tF1", "Show about dialog")
    menuFile.append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program")
    menuBar = MenuBar.new(0)  # Parameter should NOT be needed!
    menuBar.append(menuFile, "&File")
    menuBar.append(helpMenu, "&Help")
    set_menu_bar(menuBar)

    create_status_bar(2)
    set_status_text("Welcome to wxRuby!")

    evt_menu(Minimal_Quit) {onQuit}
    evt_menu(Minimal_About) {onAbout}

  end

  def onQuit
    close(TRUE)
  end

  def onAbout
    GC.start
    msg =  sprintf("This is the About dialog of the minimal sample.\n" \
    		   "Welcome to %s", VERSION_STRING)

    message_box(msg, "About Minimal", OK | ICON_INFORMATION, self)

  end
end

class RbApp < App
  def on_init
    frame = MyFrame.new("Minimal wxRuby App",Point.new(50, 50), Size.new(450, 340))

    frame.show(TRUE)

  end
end

a = RbApp.new
a.main_loop()
puts("back from main_loop...")
GC.start
puts("survived gc")
