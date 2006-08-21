require 'wx'
include Wx

# menu items
Caret_Quit = ID_EXIT
Caret_About = ID_ABOUT
Caret_set_blink_time = 3
Caret_Move = 4

# controls start here (the numbers are, of course, arbitrary)
Caret_Text = 1000


# MyCanvas is a canvas on which you can type
class MyCanvas < ScrolledWindow
  def initialize(parent)
    super(parent, -1,
          DEFAULT_POSITION, DEFAULT_SIZE,
          SUNKEN_BORDER )

    set_background_colour(WHITE)

    @font = Font.new(12, FONTFAMILY_TELETYPE,
                     FONTSTYLE_NORMAL, FONTWEIGHT_NORMAL)

    @x_caret = @y_caret =
      @x_chars = @y_chars = 0

    @x_margin = @y_margin = 5
    @text = nil

    create_caret()

    evt_paint {on_paint}
    evt_size {|event| on_size(event)}
    evt_char {|event| on_char(event)}
  end

  def [](x,y)
    @text[x + @x_chars * y,1]
  end

  def []=(x,y,z)
    @text[x + @x_chars * y,1] = z
  end

  # caret movement
  def home_pos()
    @x_caret = 0
  end

  def end_pos()
    @x_caret = @x_chars - 1
  end

  def first_line()
    @y_caret = 0
  end

  def last_line()
    @y_caret = @y_chars - 1
  end

  def prev_char()
    if @x_caret == 0
      end_pos()
      prev_line()
    else
      @x_caret -= 1
    end
  end

  def next_char()
    @x_caret += 1
    if @x_caret == @x_chars
      home_pos()
      next_line()
    end
  end

  def prev_line()
    if @y_caret == 0
      last_line()
    else
      @y_caret -= 1
    end
  end

  def next_line()
    @y_caret += 1
    if @y_caret == @y_chars
      first_line()
    end
  end

  def create_caret()
    dc = ClientDC.new(self)
    dc.set_font(@font)
    @height_char = dc.get_char_height()
    @width_char = dc.get_char_width()

    caret = Caret.new(self, Size.new(@width_char, @height_char))
    set_caret(caret)

    caret.move(Point.new(@x_margin, @y_margin))
    caret.show()
  end

  def move_caret(x,y)
    @x_caret = x
    @y_caret = y

    do_move_caret()
  end

  def do_move_caret()
    log_status("Caret is at (%d, %d)", @x_caret, @y_caret)

    get_caret().move_xy(@x_margin + @x_caret * @width_char,
                        @y_margin + @y_caret * @height_char)
  end

  def on_size(event)
    @x_chars = (event.get_size().x - 2*@x_margin) / @width_char
    @y_chars = (event.get_size().y - 2*@y_margin) / @height_char
    if @x_chars <= 0
      @x_chars = 1
    end
    if @y_chars <= 0
      @y_chars = 1
    end
    if @x_caret >= @x_chars
      @x_caret = @x_chars-1
    end
    if @y_caret >= @y_chars
      @y_caret = @y_chars-1
    end

    @text = " " * @x_chars * @y_chars

    frame = get_parent()
    if frame && frame.get_status_bar()
      msg = sprintf("Panel size is (%d, %d)", @x_chars, @y_chars)
      frame.set_status_text(msg, 1)
      frame.refresh
    end
    event.skip()
  end

  def on_paint
    caret = get_caret()
    if caret
      caret.hide()
    end

    dc = PaintDC.new(self)
    prepare_dc(dc)
    dc.clear()

    dc.set_font(@font)

    for y in 0 ... @y_chars
      line = @text[@x_chars * y,@x_chars]
      dc.draw_text( line, @x_margin, @y_margin + y * @height_char )
    end

    dc.free

    if caret
      caret.show()
    end

  end

  def on_char(event)
    case event.key_code()
    when K_LEFT
      prev_char()
    when K_RIGHT
      next_char()
    when K_UP
      prev_line()
    when K_DOWN
      next_line()
    when K_HOME
      home_pos()
    when K_END
      end_pos()
    when K_RETURN
      home_pos()
      next_line()
    else
      if !event.alt_down()
        ch = event.key_code()
        self[@x_caret, @y_caret] = ch.chr

        caret = get_caret()
        if caret
          caret.hide()
        end

        dc = ClientDC.new(self)
        dc.set_font(@font)
        dc.set_background_mode(SOLID) # overwrite old value
        dc.draw_text(ch.chr, @x_margin + @x_caret * @width_char,
                     @y_margin + @y_caret * @height_char )
        dc.free

        next_char()
        if caret
          caret.show()
        end
      else
        event.skip()
      end
    end
    do_move_caret()
  end

end

class MyFrame < Frame
  def initialize(title,pos,size)
    super(nil, -1, title, pos, size)
    # set the frame icon
    icon_file = File.join(File.dirname(__FILE__), 'mondrian.xpm')
    set_icon(Icon.new(icon_file, BITMAP_TYPE_XPM))

    # create a menu bar
    menu_file = Menu.new

    menu_file.append(Caret_set_blink_time, "&Blink time...\tCtrl-B")
    menu_file.append(Caret_Move, "&Move caret\tCtrl-C")
    menu_file.append_separator()
    menu_file.append(Caret_About, "&About...\tCtrl-A", "Show about dialog")
    menu_file.append_separator()
    menu_file.append(Caret_Quit, "E&xit\tAlt-X", "Quit self program")

    # now append the freshly created menu to the menu bar...
    menu_bar = MenuBar.new
    menu_bar.append(menu_file, "&File")

    # ... and attach self menu bar to the frame
    set_menu_bar(menu_bar)

    @canvas = MyCanvas.new(self)

    # create a status bar just for fun (by default with 1 pane only)
    create_status_bar(2)
    set_status_text("Welcome to Windows!")

    evt_menu(Caret_Quit) {on_quit}
    evt_menu(Caret_About) {on_about}
    evt_menu(Caret_set_blink_time) {on_set_blink_time}
    evt_menu(Caret_Move) {on_caret_move}
  end
  
  def on_quit
    # true is to force the frame to close
    close(true)
  end

  def on_about
    message_box("The caret Windows sample, adapted for WxRuby",
                "About Caret", OK | ICON_INFORMATION, self)
  end

  def on_caret_move
    @canvas.move_caret(10, 10)
  end

  def on_set_blink_time
    blink_time = get_number_from_user(
                   "The caret blink time is the time between two blinks",
                   "Time in milliseconds:",
                   "Caret sample",
                   Caret::get_blink_time(), 0, 10000,
                   self)
    if blink_time != -1
      Caret::set_blink_time(blink_time)
      @canvas.create_caret()
      log_status(self,"Blink time set to %d milliseconds.", blink_time)
    end
  end
end

class CaretApp < App
  def on_init()    
    frame = MyFrame.new("Caret Windows sample", 
                        Point.new(50, 50), Size.new(450, 340))
    frame.show(true)
  end
end

# ensure handlers for xpm images are loaded
Wx::init_all_image_handlers()

a = CaretApp.new
a.main_loop()
