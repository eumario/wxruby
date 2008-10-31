# wxRuby2 Sample Code. Copyright (c) 2007-???? Mario J. Steele
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

if /darwin/ =~ RUBY_PLATFORM
  $LOCALHOST_NAME = "127.0.0.1"
else
  $LOCALHOST_NAME = "localhost"
end

class SocketGUI < Wx::Frame
  @@constants = []

  def initialize(*args)
    super
    icon_file = File.join( File.dirname(__FILE__), 'res', 'message-new.png')
    self.icon = Wx::Icon.new(icon_file,Wx::BITMAP_TYPE_PNG)

    @il = Wx::ImageList.new(16,16)
    # User icon courtesy of http://www.famfamfam.com/lab/icons/silk/
    icon_file = File.join( File.dirname(__FILE__), 'res', 'user.png')
    @il.add( Wx::Bitmap.new(icon_file, Wx::BITMAP_TYPE_PNG) )
    hbox = Wx::BoxSizer.new(Wx::HORIZONTAL)
    vbox = Wx::BoxSizer.new(Wx::VERTICAL)

    # For display of Text Events
    @output = Wx::TextCtrl.new( self, :style => Wx::TE_RICH2|
                                Wx::TE_READONLY|Wx::SUNKEN_BORDER|
                                Wx::TE_MULTILINE|Wx::TE_AUTO_URL)
    # List of Users
    @users = Wx::ListCtrl.new( self, :style => Wx::LC_REPORT|
                               Wx::LC_NO_HEADER|Wx::LC_SINGLE_SEL)
    @users.set_image_list(@il,Wx::IMAGE_LIST_SMALL)
    @users.insert_column(0,"Users")
    # For Input from the User
    @input = Wx::TextCtrl.new(self, :style => Wx::TE_PROCESS_ENTER)
    vbox.add(@output,2,Wx::EXPAND)
    vbox.add(@input,0,Wx::GROW)
    hbox.add(vbox,2,Wx::EXPAND)
    hbox.add(@users,0,Wx::GROW)
    self.sizer = hbox
    @@constants.each_with_index do |const,i|
      self.class.const_set(const,1001+i)
    end
    create_menus()
    create_status_bar()
    on_init()
    @font = Wx::Font.new(10,Wx::FONTFAMILY_TELETYPE,Wx::NORMAL,Wx::NORMAL)
    @progStyle = Wx::TextAttr.new(Wx::BLUE, Wx::YELLOW, @font)
    @defStyle = Wx::TextAttr.new(Wx::BLACK, Wx::WHITE, @font)
    @errStyle = Wx::TextAttr.new(Wx::RED, Wx::GREEN, @font)
    self.set_size([640,480])
  end
  
  def add_user(user)
    #@users.append_item(@root,user,0)
    @users.insert_item(0,user,0)
  end
  
  def clear_users()
    @users.delete_all_items
  end
  
  def create_menus()
    # Holder Function
  end
  
  def on_init()
    # Holder Function
  end
  
  def append_text(msg)
    @output.freeze
    c, sl = @output.position_to_xy(@output.get_last_position)
    @output.append_text(msg)
    @output.thaw
    c, el = @output.position_to_xy(@output.get_last_position)
    @output.scroll_lines((el-sl)+2) unless sl == nil || el == nil
  end
  
  def append_prog_msg(msg)
    @output.set_default_style(@progStyle)
    msg += "\n" if msg[-1].chr != "\n"
    append_text(msg)
  end
  
  def append_msg(msg)
    @output.set_default_style(@defStyle)
    msg += "\n" if msg[-1].chr != "\n"
    append_text(msg)
  end
  
  def append_error(msg)
    @output.set_default_style(@errStyle)
    msg += "\n" if msg[-1].chr != "\n"
    append_text(msg)
  end
end
