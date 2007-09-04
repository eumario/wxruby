#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems' 
    load 'wx'
  rescue
    raise no_wx_err
  end
end

# The frame or self-contained window for this application
class MinimalFrame < Wx::Frame
  def initialize(title)
    
    # A main application frame has no parent (nil)
    super(nil, :title => title, :size => [ 400, 300 ])

    # PNG is a good choice for cross-platofrm icons
    icon_file = File.join( File.dirname(__FILE__), 'mondrian.png')
    self.icon = Wx::Icon.new(icon_file)

    menu_file = Wx::Menu.new()
    menu_help = Wx::Menu.new()
    # Using Wx::ID_ABOUT default id means the menu item will be placed
    # in the correct platform-specific place
    menu_help.append(Wx::ID_ABOUT, "&About...\tF1", "Show about dialog")
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")
    menu_bar = Wx::MenuBar.new()
    menu_bar.append(menu_file, "&File")
    menu_bar.append(menu_help, "&Help")
    # Assign the menus to this frame
    set_menu_bar(menu_bar)

    create_status_bar(2)
    set_status_text("Welcome to wxRuby!")

    # handle menu events
    evt_menu(Wx::ID_EXIT) { on_quit }
    evt_menu(Wx::ID_ABOUT) { on_about }
  end

  # End the application; it should finish automatically when the last
  # window is closed.
  def on_quit
    close()
  end

  # show an 'About' dialog
  def on_about
    msg =  sprintf("This is the About dialog of the minimal sample.\n" \
                   "Welcome to wxRuby, version %s", Wx::WXRUBY_VERSION)

    # create a simple message dialog with OK button
    about_dlg = Wx::MessageDialog.new( self, msg, 'About Minimal',
                                       Wx::OK|Wx::ICON_INFORMATION )
    about_dlg.show_modal
  end
end

# Wx::App is the container class for any wxruby app - only a single
# instance is required
class MinimalApp < Wx::App
  # This method is called when main_loop is entered; it should set up
  # the application's and display initial GUI windows.
  def on_init
    self.app_name = 'Minimal'
    frame = MinimalFrame.new("Minimal wxRuby App")
    # This is required,
    frame.show
    # on_init must return a true value else the app will not start
    true
  end
end

# Create an instance ...
app = MinimalApp.new
# ... and run the application
app.main_loop()
