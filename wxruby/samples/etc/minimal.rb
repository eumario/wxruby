require 'wxruby'
include Wx


Minimal_Quit = 1
Minimal_About = ID_ABOUT

class RbApp < App
  def on_init
    frame = MyFrame.new("Hello wxRuby")
    frame.show(TRUE)
  end
end

def labeledEntry(parent,sizer,label,default)
  sizer.add(StaticText.new(parent,-1,label.to_s, DEFAULT_POSITION,DEFAULT_SIZE,ALIGN_RIGHT),1,ALIGN_CENTER_VERTICAL)
  sizer.add(r=TextCtrl.new(parent,-1,default.to_s, DEFAULT_POSITION,DEFAULT_SIZE,ALIGN_LEFT),1,ALIGN_CENTER_VERTICAL)
  return r
end
class MyFrame < Frame
  def initialize(title)
    super(nil,-1,title)

    if RUBY_PLATFORM == "WXMSW"
      set_icon(Icon.new("mondrian.ico",BITMAP_TYPE_ICO))
    else
      set_icon(Icon.new("mondrian.xpm",BITMAP_TYPE_XPM))
    end

    menuFile = Menu.new
    helpMenu = Menu.new
    helpMenu.append(Minimal_About, "&About...\tF1", "Show about dialog")
    menuFile.append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program")
    menuBar = MenuBar.new
    menuBar.append(menuFile, "&File")
    menuBar.append(helpMenu, "&Help")
    set_menu_bar(menuBar)

    evt_menu(Minimal_Quit) {onQuit}
    evt_menu(Minimal_About) {onAbout}

    create_status_bar(2)
    set_status_text("Welcome to wxWindows!")

    topSizer = BoxSizer.new(HORIZONTAL)

    simulBox = StaticBox.new(self,-1,"Simulation area")
    sizer1 = StaticBoxSizer.new(simulBox,VERTICAL)

    sizer11 = FlexGridSizer.new(2,10,10)
    xsize=labeledEntry(self,sizer11,'X',1000)
    ysize=labeledEntry(self,sizer11,'Y',1000)
    sizer1.add(sizer11)
    topSizer.add(sizer1)
    message_box("X is: #{xsize.get_value}","ho",OK, self)

    agentBox = StaticBox.new(self,-1,"Agent properties")
    sizer2 = StaticBoxSizer.new(agentBox,VERTICAL)

    sizer21 = FlexGridSizer.new(2,10,10)
    labeledEntry(self,sizer21,'Time to stay',10)

    sizer2.add(sizer21)
    topSizer.add(sizer2)


    set_sizer_and_fit(topSizer)
  end

  def onQuit
    puts "OnQuit"
    close(TRUE)
  end

  def onAbout
    puts "OnAbout"
    msg =  sprintf("This is the About dialog of the minimal sample.\n" \
    		   "Welcome to %s", VERSION_STRING)

    message_box(msg, "About Minimal", OK | ICON_INFORMATION, self)

  end
end

a = RbApp.new
a.main_loop
