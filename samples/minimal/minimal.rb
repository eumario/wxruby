# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

require 'wx'

# The frame or self-contained window for this application
class MinimalFrame < Wx::Frame
  def initialize(title, pos, size, style = Wx::DEFAULT_FRAME_STYLE)
    
    # A main application frame has no parent (nil)
    # -1 means this frame will be supplied a default id
    super(nil, -1, title, pos, size, style)

    # Set the frame's icon - use .ico on windows, else .xpm
    if RUBY_PLATFORM == "WXMSW"
      set_icon( Wx::Icon.new(local_icon_file("mondrian.ico"), 
                             Wx::BITMAP_TYPE_ICO) )
    else
      set_icon( Wx::Icon.new(local_icon_file("mondrian.xpm"), 
                             Wx::BITMAP_TYPE_XPM) )
    end

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

  # end the application
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
    about_dlg.show_modal()
	about_dlg.destroy()
  end

  # utility function to find an icon relative to this ruby script
  def local_icon_file(icon_name)
    File.join( File.dirname(__FILE__), icon_name) 
  end
end

# Wx::App is the container class for any wxruby app - only a single
# instance is required
class MinimalApp < Wx::App
  def on_init
    frame = MinimalFrame.new("Minimal wxRuby App",
                             Wx::Point.new(50, 50), 
                             Wx::Size.new(450, 340))
    set_app_name('Minimal')
    # required
    frame.show()
  end
  
  def on_assert(file, line, condition, message)
  	puts("ASSERT: #{file} #{line}: #{condition}; #{message}")
	raise
  end
end

# Create an instance ...
app = MinimalApp.new
# ... and run the application
app.main_loop()
