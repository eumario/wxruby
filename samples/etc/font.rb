# wxruby font sample
# written by Nobuaki Arima

require 'wxruby'
include Wx

BASIC_EXIT    =   1
BASIC_ABOUT	= 200


class BasicFrame < Frame
  def initialize(title,xpos,ypos,width,height)
    super(nil,-1,title,Point.new(xpos,ypos),Size.new(width,height))
    
    @theText = TextCtrl.new(self,
      -1,"This is a rich text control\n\n",
      DEFAULT_POSITION,
      DEFAULT_SIZE,
      TE_MULTILINE|TE_RICH)
    font = Font.new(NORMAL_FONT.get_point_size, DEFAULT, NORMAL, NORMAL)
    font.set_weight(BOLD)
    @theText.set_default_style(TextAttr.new(Colour.new("BLACK"), NULL_COLOUR, font))
    @theText << "Bold font\n\n"
    font.set_point_size(NORMAL_FONT.get_point_size * 2)
    @theText.set_default_style(TextAttr.new(Colour.new("BLACK"), NULL_COLOUR, font))
    @theText << "Larger font\n\n"
    font.set_weight(NORMAL)
    font.set_style(ITALIC)
    @theText.set_default_style(TextAttr.new(Colour.new("RED"), NULL_COLOUR, font))
    @theText << "Red italic font\n\n"
    font.set_style(NORMAL)
    font.set_underlined(TRUE)
    # NOTE: under GTK, it doesn't actually display as underlined. 2003-12-29 kbs.
    @theText.set_default_style(TextAttr.new(Colour.new("BROWN"), NULL_COLOUR, font))
    @theText << "Underlined text\n\n"
    font.set_underlined(FALSE)
    font.set_face_name("FixedSys")
    @theText.set_default_style(TextAttr.new(Colour.new("BLUE"), NULL_COLOUR, font))
    @theText << "Other typeface --- FixedSys.\n"
    
    fileMenu = Menu.new
    fileMenu.append(BASIC_ABOUT, "&About")
    fileMenu.append_separator
    fileMenu.append(BASIC_EXIT,  "E&xit")
    
    menuBar = MenuBar.new
    menuBar.append(fileMenu, "&File")
    set_menu_bar(menuBar)

    evt_menu (BASIC_EXIT) {onExit}
    evt_menu (BASIC_ABOUT) {onAbout}

  end


  def onAbout 
    t = "Rich text control sample"
    aboutDialog = MessageDialog.new(self, t, "About",
    OK | CANCEL)
    aboutDialog.show_modal
  end

  def onExit 
    close(TRUE)
  end

end

class RbApp < App
  def on_init
    frame = BasicFrame.new("Rich text control sample",
         50, 50, 400, 350)

    frame.show(TRUE)
    set_top_window(frame)
  end

end


a = RbApp.new
a.main_loop
