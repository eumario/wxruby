
require 'wxruby'
include Wx

BASIC_EXIT    =   1
BASIC_OPEN	= 100
BASIC_ABOUT	= 200

TITLE = "Basic - Step 3: Responding to events"

class BasicFrame < Frame
  def initialize(title,xpos,ypos,width,height)
    super(nil,-1,title,Point.new(xpos,ypos),Size.new(width,height))

    @theText = TextCtrl.new(self,
  	  -1,
  	  ("This is a text control\n\n" \
  	           "The text control supports" \
                   " basic text editing operations\n" \
  	           "along with copy, cut, paste, " \
                   "delete, select all and undo.\n\n" \
  	           "Right click on the control" \
                   " to see the pop-up menu.\n"
  	          ),
  	  DEFAULT_POSITION,
  	  DEFAULT_SIZE,
  	  TE_MULTILINE)

  fileMenu = Menu.new
  fileMenu.append(BASIC_OPEN,  "&Open file")
  fileMenu.append(BASIC_ABOUT, "&About")
  fileMenu.append_separator
  fileMenu.append(BASIC_EXIT,  "E&xit")

  menuBar = MenuBar.new
  menuBar.append(fileMenu, "&File")
  set_menu_bar(menuBar)
  create_status_bar(3)

  evt_menu (BASIC_EXIT) {onExit}
  evt_menu (BASIC_ABOUT) {onAbout}
  evt_menu (BASIC_OPEN) {onOpenFile}

  end

  def onOpenFile 
    @theText.load_file("data.txt")
  end


  def onAbout 
    t = TITLE
    t << "\nDB 2001"

    aboutDialog = MessageDialog.new(self, t, "About Basic",
    OK | CANCEL)
    aboutDialog.show_modal
  end

  def onExit 
    close(TRUE)
  end

end

class RbApp < App
  def on_init
    frame = BasicFrame.new("wxWindows Basic Steps - Step 1:" \
        " A simple application",
         50, 50, 200, 200)

    frame.show(TRUE)
    set_top_window(frame)
  end

end


a = RbApp.new
a.main_loop
