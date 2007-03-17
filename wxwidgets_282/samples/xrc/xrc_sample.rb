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

# Basic Frame Class. This creates the dialog window
class SimpleFrame < Wx::Frame 

	FILE_DIALOG = 1001
	
	def initialize()
		super(nil,-1,"Sample",Wx::Point.new(50,50),Wx::Size.new(300,300))
        txt = "Choose 'Open Dialog' from the menu to see a dialog made with XRC"
        Wx::StaticText.new( self, -1, txt, Wx::Point.new(10, 10) )

		# Create a new menu
		bar = Wx::MenuBar.new()
		menu = Wx::Menu.new()
		menu.append(FILE_DIALOG,"Open Dialog")
		menu.append(Wx::ID_EXIT,"Quit")
		bar.append(menu,"File")
		
		set_menu_bar(bar)
		
		# 
		# Assign the menu events
		#
		evt_menu(FILE_DIALOG) do
			SimpleDialog.new(self).show_modal()
		end
		
		evt_menu(Wx::ID_EXIT) do
          puts Wx::get_app.get_app_name
          Wx::get_app.exit_main_loop()
		end
		
		evt_close() do
			Wx::get_app.exit_main_loop()
		end
	end
	
end

# Dialog subclass. The components within the dialog are loaded from XRC.
class SimpleDialog < Wx::Dialog
	def initialize(parent)
		super()
		
		# Load the dialog from XRC. We define $xml in on_init.
		# We could use XmlResource.get() over and over again, but
		# honestly, thats just too much work.
		$xml.load_dialog_subclass(self,parent,'SAMPLE_DIALOG')

		# Get the buttons. The xrcid method turns a string identifier
        # used in an xml file into a numeric identifier as used in
        # wxruby. 
        @ok      = find_window_by_id( Wx::xrcid('wxID_OK') )
        @cancel  = find_window_by_id( Wx::xrcid('wxID_CANCEL') )
        @message = find_window_by_id( Wx::xrcid('SAMPLE_MESSAGE') )

		# Bind the buttons to event handlers
        evt_button( @ok.get_id ) { end_modal(Wx::ID_OK) }
        evt_button( @cancel.get_id ) { end_modal(Wx::ID_CANCEL) }
		evt_button( @message.get_id ) do
          Wx::message_box("And now a message from our sponsors.")
		end
	end
end

#
# Application class.
#
class XrcApp < Wx::App

	def on_init
		# Create a resource handler
		$xml = Wx::XmlResource.get();
		$xml.init_all_handlers();


		# Load a resource file
        xrc_file = File.join( File.dirname(__FILE__), 'samples.xrc' )
		$xml.load(xrc_file)

		# Show the main frame.
		main = SimpleFrame.new()
		main.show(true)
	end

end

XrcApp.new.main_loop()
