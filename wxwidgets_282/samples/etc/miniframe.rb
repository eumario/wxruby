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
  attr_reader :mini

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

    evt_menu(Wx::ID_EXIT) { on_quit }
    evt_menu(Wx::ID_ABOUT) { on_about }

    make_miniframe()
  end

  def make_miniframe
    @mini = Wx::MiniFrame.new(self, -1, 'Mini Frame', 
                              Wx::Point.new(300, 75), Wx::Size.new(300, 150),
                              Wx::DEFAULT_FRAME_STYLE|Wx::STAY_ON_TOP)
    sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    text = Wx::StaticText.new(mini, -1, 'This is a MiniFrame.')
    sizer.add(text, 0, Wx::ALL, 2)
    text = Wx::StaticText.new(mini, -1, 'It has a small title bar so it')
    sizer.add(text, 0, Wx::ALL, 2)
    text = Wx::StaticText.new(mini, -1, 'doesn\'t take up too much space.')
    sizer.add(text, 0, Wx::ALL, 2)
    text = Wx::StaticText.new(mini, -1, 'This MiniFrame has been set to')
    sizer.add(text, 0, Wx::ALL, 2)
    text = Wx::StaticText.new(mini, -1, 'stay above the main app window.')
    sizer.add(text, 0, Wx::ALL, 2)
    mini.set_sizer(sizer)
    mini.show()
    mini.raise()
  end

  def on_quit
    mini.close()
    close()
  end

  def on_about
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
    frame.show()
  end
end

app = RbApp.new
app.main_loop()

