
require 'wxruby'
include Wx

MENU_FILE_OPEN,MENU_FILE_SAVE,MENU_FILE_QUIT,MENU_INFO_ABOUT,MENU_OPTION_BACKGROUNDCOLOR,MENU_OPTION_FONT,MENU_OPTION_DIRECTORY = 1,2,3,4,5,6,7

class NumTextCtrl < TextCtrl
  def initialize(parent,id,value,pos,size,style)
    super

    evt_char do |event|
      if event.get_key_code.chr =~ /\d/
        event.skip
      else
        bell()
      end
	end
  end
end

class TextFrame < Frame
  def initialize(title,xpos,ypos,width,height)
	super(nil, -1, title, Point.new(xpos, ypos), Size.new(width, height))
	@m_pTextCtrl = TextCtrl.new(self, -1, "Type some text...",DEFAULT_POSITION, DEFAULT_SIZE, TE_MULTILINE)
#	@m_pTextCtrl = NumTextCtrl.new(self, -1, "Type some text...",DEFAULT_POSITION, DEFAULT_SIZE, TE_MULTILINE)
	@m_pMenuBar = MenuBar.new
	@m_pFileMenu = Menu.new
	@m_pFileMenu.append(MENU_FILE_OPEN, "&Open", "Opens an existing file")
	@m_pFileMenu.append(MENU_FILE_SAVE, "&Save", "Save the content")
	@m_pFileMenu.append_separator()
	@m_pFileMenu.append(MENU_FILE_QUIT, "&Quit", "Quit the application")
	@m_pMenuBar.append(@m_pFileMenu, "&File")

	@m_pOptionMenu = Menu.new
	@m_pOptionMenu.append(MENU_OPTION_BACKGROUNDCOLOR, "&Background Color")
	@m_pOptionMenu.append(MENU_OPTION_FONT, "&Font")
	@m_pOptionMenu.append(MENU_OPTION_DIRECTORY, "&Directory")
	@m_pMenuBar.append(@m_pOptionMenu, "&Option")

	@m_pInfoMenu = Menu.new
	@m_pInfoMenu.append(MENU_INFO_ABOUT, "&About", "Shows information about the application")
	@m_pMenuBar.append(@m_pInfoMenu, "&Info")
	set_menu_bar(@m_pMenuBar)
	create_status_bar(3)
	set_status_text("Ready", 0)

	evt_menu(MENU_FILE_OPEN) {|event| onMenuFileOpen(event) }
	evt_menu(MENU_FILE_SAVE) {|event| onMenuFileSave(event) }
	evt_menu(MENU_FILE_QUIT) {|event| onMenuFileQuit(event) }
	evt_menu(MENU_INFO_ABOUT) {|event| onMenuInfoAbout(event) }
	evt_menu(MENU_OPTION_BACKGROUNDCOLOR) {|event| onMenuOptionBackgroundColor(event) }
	evt_menu(MENU_OPTION_FONT) {|event| onMenuOptionFont(event) }
	evt_menu(MENU_OPTION_DIRECTORY) {|event| onMenuOptionDirectory(event) }
	evt_close {|event| onClose(event) }

  end

  def onMenuFileOpen(event)
	  dlg = FileDialog.new(self, "Open a text file",
	                                       "", "", "All files(*.*)|*.*|Text Files(*.txt)|*.txt",
	                                       OPEN, DEFAULT_POSITION)
	  if dlg.show_modal() == ID_OK
	    @m_pTextCtrl.load_file(dlg.get_filename())
	    set_status_text(dlg.get_filename(), 0)
	  end
	  dlg.destroy()
  end

  def onMenuFileSave(event)
	  dlg = FileDialog.new(self, "Save a text file",
	                                       "", "", "All files(*.*)|*.*|Text Files(*.txt)|*.txt",
	                                       SAVE, DEFAULT_POSITION)
	  if dlg.show_modal == ID_OK
	    @m_pTextCtrl.save_file(dlg.get_path)
	    set_status_text(dlg.get_filename, 0)
	  end
	  dlg.destroy
  end

  def onMenuFileQuit(event)
    close(FALSE)
  end

  def onMenuOptionBackgroundColor(event)
	  colour = @m_pTextCtrl.get_background_colour
	  colourData = ColourData.new
	  colourData.set_colour(colour)
	  colourData.set_choose_full(TRUE)
	  c = colourData.get_colour
	  dlg = ColourDialog.new(self, colourData)
	  if dlg.show_modal == ID_OK
	    colourData = dlg.get_colour_data
	    @m_pTextCtrl.set_background_colour(colourData.get_colour)
	    @m_pTextCtrl.refresh
	  end
	  dlg.destroy
  end

  def onMenuOptionFont(event)
	  font = @m_pTextCtrl.get_font
	  fontData = FontData.new
	  fontData.set_initial_font(font)
	  colour = @m_pTextCtrl.get_foreground_colour
	  fontData.set_colour(colour)
	  fontData.set_show_help(TRUE)

	  dlg = FontDialog.new(self, fontData)
	  if dlg.show_modal == ID_OK
	    fontData = dlg.get_font_data
	    font = fontData.get_chosen_font
	    @m_pTextCtrl.set_font(font)
	    @m_pTextCtrl.set_foreground_colour(fontData.get_colour)
	    @m_pTextCtrl.refresh
	  end
	  dlg.destroy
  end

  def onMenuOptionDirectory(event)
	  dlg = DirDialog.new(self, "Select a new working directory", get_cwd())
	  if dlg.show_modal == ID_OK
	    set_working_directory(dlg.get_path)
	  end
	  dlg.destroy
  end

  def onMenuInfoAbout(event)
    log_message("File About Menu Selected")
  end

  def onClose(event)
     destroy = true
     if event.can_veto
       if @m_pTextCtrl.is_modified
          dlg =
               MessageDialog.new(self, "Text is changed!\nAre you sure you want to exit?",
                                   "Text changed!!!", YES_NO | NO_DEFAULT)
          result = dlg.show_modal
          if result == ID_NO
            event.veto
            destroy = false
          end
      end
    end
    destroy() if destroy
  end
end

class RbApp < App
  def OnInit()
  	frame = TextFrame.new("Simple Text Editor", 100, 100, 400, 300)
	frame.show(TRUE)
  end

end

a = RbApp.new
a.main_loop()
