
require 'wx'
include Wx

# menu items
Caret_Quit = 1
Caret_About = 2
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

        @m_font = Font.new(12, FONTFAMILY_TELETYPE,
                        FONTSTYLE_NORMAL, FONTWEIGHT_NORMAL)

        @m_xCaret = @m_yCaret =
        @m_xChars = @m_yChars = 0

        @m_xMargin = @m_yMargin = 5
        @m_text = nil

        CreateCaret()

        evt_paint {onPaint}
        evt_size {|event| onSize(event)}
        evt_char {|event| onChar(event)}
    end

    def [](x,y)
        @m_text[x + @m_xChars * y,1]
    end

    def []=(x,y,z)
        @m_text[x + @m_xChars * y,1] = z
    end

    # caret movement
    def Home()
        @m_xCaret = 0
    end

    def End()
        @m_xCaret = @m_xChars - 1
    end

    def FirstLine()
        @m_yCaret = 0
    end

    def LastLine()
        @m_yCaret = @m_yChars - 1
    end

    def PrevChar()
        if @m_xCaret == 0
          End()
          PrevLine()
        else
          @m_xCaret -= 1
        end
    end

    def NextChar()
        @m_xCaret += 1
        if @m_xCaret == @m_xChars
            Home()
            NextLine()
        end
    end

    def PrevLine()
        if @m_yCaret == 0
            LastLine()
        else
            @m_yCaret -= 1
        end
    end

    def NextLine()
        @m_yCaret += 1
        if @m_yCaret == @m_yChars
            FirstLine()
        end
    end

    def CreateCaret()
        dc = ClientDC.new(self)
        dc.set_font(@m_font)
        @m_heightChar = dc.get_char_height()
        @m_widthChar = dc.get_char_width()

        caret = Caret.new(self, Size.new(@m_widthChar, @m_heightChar))
        set_caret(caret)

        caret.move(Point.new(@m_xMargin, @m_yMargin))
        caret.show()
    end

    def MoveCaret(x,y)
        @m_xCaret = x
        @m_yCaret = y

        DoMoveCaret()
    end

    def DoMoveCaret()
        log_status("Caret is at (%d, %d)", @m_xCaret, @m_yCaret)

        get_caret().move_xy(@m_xMargin + @m_xCaret * @m_widthChar,
                         @m_yMargin + @m_yCaret * @m_heightChar)
    end

    def onSize(event)
        @m_xChars = (event.get_size().x - 2*@m_xMargin) / @m_widthChar
        @m_yChars = (event.get_size().y - 2*@m_yMargin) / @m_heightChar
        if @m_xChars == 0
            @m_xChars = 1
        end
        if @m_yChars == 0
            @m_yChars = 1
        end

        @m_text = " " * @m_xChars * @m_yChars

        frame = get_parent()
        if frame && frame.get_status_bar()
            msg = sprintf("Panel size is (%d, %d)", @m_xChars, @m_yChars)
            frame.set_status_text(msg, 1)
        end
        event.skip()
    end

    def onPaint
        m_caret = get_caret()
        if m_caret
            m_caret.hide()
        end

        dc = PaintDC.new(self)
        prepare_dc(dc)
        dc.clear()

        dc.set_font(@m_font)

        for y in 0 ... @m_yChars
            line = @m_text[@m_xChars * y,@m_xChars]
            dc.draw_text( line, @m_xMargin, @m_yMargin + y * @m_heightChar )
        end

        dc.free

        if m_caret
            m_caret.show()
        end

    end

    def onChar(event)
        case event.key_code()
            when K_LEFT
                PrevChar()
            when K_RIGHT
                NextChar()
            when K_UP
                PrevLine()
            when K_DOWN
                NextLine()
            when K_HOME
                Home()
            when K_END
                End()
            when K_RETURN
                Home()
                NextLine()
            else
                if !event.alt_down()
                    ch = event.key_code()
                    self[@m_xCaret, @m_yCaret] = ch.chr

                    m_caret = get_caret()
                    if m_caret
                        m_caret.hide()
                    end

                    dc = ClientDC.new(self)
                    dc.set_font(@m_font)
                    dc.set_background_mode(SOLID) # overwrite old value
                    dc.draw_text(ch.chr, @m_xMargin + @m_xCaret * @m_widthChar,
                                    @m_yMargin + @m_yCaret * @m_heightChar )
                    dc.free

                    NextChar()
                    if m_caret
                        m_caret.show()
                    end
                else
                    event.skip()
                end
        end
        DoMoveCaret()
    end

end

class MyFrame < Frame
    def initialize(title,pos,size)
        super(nil, -1, title, pos, size)
        # set the frame icon
        set_icon(Icon.new("mondrian.xpm",BITMAP_TYPE_XPM))

        # create a menu bar
        menuFile = Menu.new

        menuFile.append(Caret_set_blink_time, "&Blink time...\tCtrl-B")
        menuFile.append(Caret_Move, "&Move caret\tCtrl-C")
        menuFile.append_separator()
        menuFile.append(Caret_About, "&About...\tCtrl-A", "Show about dialog")
        menuFile.append_separator()
        menuFile.append(Caret_Quit, "E&xit\tAlt-X", "Quit self program")

        # now append the freshly created menu to the menu bar...
        menuBar = MenuBar.new
        menuBar.append(menuFile, "&File")

        # ... and attach self menu bar to the frame
        set_menu_bar(menuBar)

        @m_canvas = MyCanvas.new(self)

        # create a status bar just for fun (by default with 1 pane only)
        create_status_bar(2)
        set_status_text("Welcome to Windows!")

        evt_menu(Caret_Quit) {onQuit}
        evt_menu(Caret_About) {onAbout}
        evt_menu(Caret_set_blink_time) {onSet_blink_time}
        evt_menu(Caret_Move) {onCaretMove}

    end

    def onQuit
        # TRUE is to force the frame to close
        close(TRUE)
    end

    def onAbout
        message_box("The caret Windows sample.\n© 1999 Vadim Zeitlin",
                 "About Caret", OK | ICON_INFORMATION, self)
    end

    def onCaretMove
        @m_canvas.MoveCaret(10, 10)
    end

    def onSet_blink_time

        blinkTime = get_number_from_user(
                      "The caret blink time is the time between two blinks",
                      "Time in milliseconds:",
                      "Caret sample",
                      Caret::get_blink_time(), 0, 10000,
                      self)
        if blinkTime != -1
            Caret::set_blink_time(blinkTime)
            @m_canvas.CreateCaret()
            log_status(self,"Blink time set to %d milliseconds.", blinkTime)
        end
    end
end

class RbApp < App
    def on_init()    
  	    frame = MyFrame.new("Caret Windows sample", Point.new(50, 50), Size.new(450, 340))
	    frame.show(TRUE)
    end
end

a = RbApp.new
a.main_loop()
