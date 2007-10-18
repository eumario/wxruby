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

# This sample shows a fairly minimal Wx::App using a Frame, with a
# MenuBar and StatusBar but no controls. For the absolute minimum app,
# see nothing.rb

# A Wx::Frame is a self-contained, top-level Window that can contain
# controls, menubars, and statusbars
class MinimalFrame < Wx::Frame
  def initialize(title)
    # The main application frame has no parent (nil)
    super(nil, :title => title, :size => [ 400, 300 ])

    # Different platforms use different file formats for a frame icon.
    icon_type = case Wx::PLATFORM
      when 'WXMSW' : 'ico'
      when 'WXGTK', 'WXMAC' : 'png'
    end 
    icon_file = File.join( File.dirname(__FILE__), "mondrian.#{icon_type}")
    # Although OS X doesn't have "Frame" icons, so this will have no effect
    self.icon = Wx::Icon.new(icon_file)

    menu_bar = Wx::MenuBar.new
    # The "file" menu
    menu_file = Wx::Menu.new
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")
    menu_bar.append(menu_file, "&File")

    # The "help" menu
    menu_help = Wx::Menu.new
    # Using Wx::ID_ABOUT default id means the menu item will be placed
    # in the correct platform-specific place - eg on OS X
    menu_help.append(Wx::ID_ABOUT, "&About...\tF1", "Show about dialog")
    menu_bar.append(menu_help, "&Help")

    # Assign the menubar to this frame
    self.menu_bar = menu_bar

    # Create a status bar
    create_status_bar(2)
    self.status_text = "Welcome to wxRuby!"

    # Set it up to handle menu events using the relevant methods
    evt_menu Wx::ID_EXIT, :on_quit
    evt_menu Wx::ID_ABOUT, :on_about
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
    # Display the dialog on top of and blocking other windows, until
    # dismissed by clicking the 'OK' button
    about_dlg.show_modal
  end
end

# Wx::App is the container class for any wxruby app. To start an
# application, either define a subclass of Wx::App, create an instance,
# and call its main_loop method, OR, simply call the Wx::App.run class
# method, as shown here.
Wx::App.run do 
  self.app_name = 'Minimal'
  frame = MinimalFrame.new("Minimal wxRuby App")
  frame.show
end
