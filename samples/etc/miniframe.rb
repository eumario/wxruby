require 'wx'

class MyFrame < Wx::Frame
  def initialize(title, pos, size, style = Wx::DEFAULT_FRAME_STYLE)
    super(nil, -1, title, pos, size, style)


    menuFile = Wx::Menu.new()
    helpMenu = Wx::Menu.new()
    helpMenu.append(Wx::ID_ABOUT, "&About...\tF1", "Show about dialog")
    menuFile.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")
    menuBar = Wx::MenuBar.new()
    menuBar.append(menuFile, "&File")
    menuBar.append(helpMenu, "&Help")
    set_menu_bar(menuBar)

    create_status_bar(2)
    set_status_text("Welcome to wxRuby!")

    evt_menu(Wx::ID_EXIT) { onQuit }
    evt_menu(Wx::ID_ABOUT) { onAbout }
    m = Wx::MiniFrame.new(nil, -1, 'Mini Frame')
    m.show()

  end

  def onQuit
    close(Wx::TRUE)
  end

  def onAbout
    msg =  sprintf("This is the About dialog of the miniframe sample.\n" \
                    "Welcome to %s", Wx::VERSION_STRING)
    Wx::message_box(msg, "About MiniFrame", Wx::OK|Wx::ICON_INFORMATION, self)
    
  end
end

class RbApp < Wx::App
  def on_init
    frame = MyFrame.new("Mini Frame wxRuby App",
                        Wx::Point.new(50, 50), 
                        Wx::Size.new(450, 340))

    frame.show(TRUE)

  end
end

app = RbApp.new
app.main_loop()

