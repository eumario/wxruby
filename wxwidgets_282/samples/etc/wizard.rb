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
    s = Wx::StaticText.new(self, -1, 'The Wizard has completed')


    evt_menu(Wx::ID_EXIT) { on_quit }
    evt_menu(Wx::ID_ABOUT) { on_about }
    w = Wx::Wizard.new(self, -1, 'The WxRuby Wizard')
    p1 = Wx::WizardPageSimple.new(w)
    s = Wx::StaticText.new(p1, -1, 'This is the first page')
    p2 = Wx::WizardPageSimple.new(w, p1)
    p1.set_next(p2)
    s = Wx::StaticText.new(p2, -1, 'This is the second page')
    p3 = Wx::WizardPageSimple.new(w, p2)
    p2.set_next(p3)
    s = Wx::StaticText.new(p3, -1, 'This is the final page')

    evt_wizard_page_changed(w.get_id) { p "page changed" }
    evt_wizard_page_changing(w.get_id) { p "page changing" }
    evt_wizard_help(w.get_id) { p "wizard help" }
    evt_wizard_cancel(w.get_id) { p "wizard cancelled" }
    evt_wizard_finished(w.get_id) { p "wizard finished" }


    w.run_wizard(p1)
  end

  def on_quit
    close(Wx::TRUE)
  end

  def on_about
    msg =  sprintf("This is the About dialog of the wizard sample.\n" \
                    "Welcome to %s", Wx::VERSION_STRING)
    Wx::message_box(msg, "About Wizard", Wx::OK|Wx::ICON_INFORMATION, self)
  end
end

class RbApp < Wx::App
  def on_init
    frame = MyFrame.new("Wizard wxRuby App",
                        Wx::Point.new(50, 50), 
                        Wx::Size.new(450, 340))

    frame.show(TRUE)

  end
end

app = RbApp.new
app.main_loop()

