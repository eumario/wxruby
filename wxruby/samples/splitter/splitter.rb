
require 'wxruby'
include Wx

SPLIT_QUIT = 0
SPLIT_HORIZONTAL = 1
SPLIT_VERTICAL = 2
SPLIT_UNSPLIT = 3
SPLIT_LIVE = 4
SPLIT_SETPOSITION = 5
SPLIT_SETMINSIZE = 6

class MyCanvas < ScrolledWindow
    def initialize(parent)
        super(parent, -1)
    end

    def on_draw(dc)
        #GC.start
        dc.set_pen(BLACK_PEN)
        dc.draw_line(0, 0, 100, 100)

        dc.set_background_mode(TRANSPARENT)
        dc.draw_text("Testing", 50, 50)

        dc.set_pen(RED_PEN)
        dc.set_brush(GREEN_BRUSH)
        dc.draw_rectangle(120, 120, 100, 80)
    end

end

class MySplitterWindow < SplitterWindow
    def initialize(parent)
        super(parent, -1,
                       DEFAULT_POSITION, DEFAULT_SIZE,
                       SP_3D | SP_LIVE_UPDATE | CLIP_CHILDREN)

        @m_frame = parent

        evt_splitter_sash_pos_changed(-1) {|event| onPositionChanged(event) }
        evt_splitter_sash_pos_changing(-1) {|event| onPositionChanging(event) }

        evt_splitter_dclick(-1) {|event| onDClick(event) }

        evt_splitter_unsplit(-1) {|event| onUnsplit(event) }

    end

    def onPositionChanged(event)
        log_status(@m_frame, "Position has changed, now = %d (or %d)",
                event.get_sash_position(), get_sash_position())

        event.skip()
    end

    def onPositionChanging(event)
        log_status(@m_frame, "Position is changing, now = %d (or %d)",
                event.get_sash_position(), get_sash_position())

        event.skip()
    end

    def onDClick(event)
        @m_frame.set_status_text("Splitter double clicked", 1)
        event.skip()
    end

    def onUnsplit(event)
        @m_frame.set_status_text("Splitter unsplit", 1)
        event.skip()
    end
end

class MyFrame < Frame
    def initialize
        super(nil, -1, "SplitterWindow sample",
                 DEFAULT_POSITION, Size.new(420, 300),
                 DEFAULT_FRAME_STYLE | NO_FULL_REPAINT_ON_RESIZE)

        create_status_bar(2)

        # Make a menubar
        splitMenu = Menu.new
        splitMenu.append(SPLIT_VERTICAL,
                          "Split &Vertically\tCtrl-V",
                          "Split vertically")
        splitMenu.append(SPLIT_HORIZONTAL,
                          "Split &Horizontally\tCtrl-H",
                          "Split horizontally")
        splitMenu.append(SPLIT_UNSPLIT,
                          "&unsplit\tCtrl-U",
                          "unsplit")
        splitMenu.append_separator()

        splitMenu.append_check_item(SPLIT_LIVE,
                                   "&Live update\tCtrl-L",
                                   "Toggle live update mode")
        splitMenu.append(SPLIT_SETPOSITION,
                          "Set splitter &position\tCtrl-P",
                          "Set the splitter position")
        splitMenu.append(SPLIT_SETMINSIZE,
                          "Set &min size\tCtrl-M",
                          "Set minimum pane size")
        splitMenu.append_separator()

        splitMenu.append(SPLIT_QUIT, "E&xit\tAlt-X", "Exit")

        menuBar = MenuBar.new
        menuBar.append(splitMenu, "&Splitter")

        set_menu_bar(menuBar)

        menuBar.check(SPLIT_LIVE, TRUE)
        @m_splitter = MySplitterWindow.new(self)


        @m_left = MyCanvas.new(@m_splitter)
        @m_left.set_background_colour(RED)
        @m_left.set_scrollbars(20, 20, 50, 50)
        @m_left.set_cursor(Cursor.new(CURSOR_MAGNIFIER))

        @m_right = MyCanvas.new(@m_splitter)
        @m_right.set_background_colour(CYAN)
        @m_right.set_scrollbars(20, 20, 50, 50)

        # for testing kbd navigation inside the splitter
    #    @m_left = new TextCtrl(@m_splitter, -1, "first text")
    #    @m_right = new TextCtrl(@m_splitter, -1, "second text")

        # you can also do self to start with a single window

    #    @m_right.show(FALSE)
    #    @m_splitter.Initialize(@m_left)

        # you can also try -100
        @m_splitter.split_vertically(@m_left, @m_right, 100)


        set_status_text("Min pane size = 0", 1)

        evt_menu(SPLIT_VERTICAL) {|event| onSplitVertical(event) }
        evt_menu(SPLIT_HORIZONTAL) {|event| onSplitHorizontal(event) }
        evt_menu(SPLIT_UNSPLIT) {|event| onUnsplit(event) }
        evt_menu(SPLIT_LIVE) {|event| onToggleLive(event) }
        evt_menu(SPLIT_SETPOSITION) {|event| onSetPosition(event) }
        evt_menu(SPLIT_SETMINSIZE) {|event| onSetMinSize(event) }

        evt_menu(SPLIT_QUIT) {|event| onQuit(event) }

        evt_update_ui(SPLIT_VERTICAL) {|event| onUpdateUIVertical(event) }
        evt_update_ui(SPLIT_HORIZONTAL) {|event| onUpdateUIHorizontal(event) }
        evt_update_ui(SPLIT_UNSPLIT) {|event| onUpdateUIUnsplit(event) }

    end

    def onQuit(event)
        close(TRUE)
    end

    def onSplitHorizontal(event )
        if @m_splitter.is_split()
            @m_splitter.unsplit()
        end
        @m_left.show(TRUE)
        @m_right.show(TRUE)
        @m_splitter.split_horizontally( @m_left, @m_right )

        set_status_text("Splitter split horizontally", 1)
    end

    def onSplitVertical(event )
        if @m_splitter.is_split()
            @m_splitter.unsplit()
        end
        @m_left.show(TRUE)
        @m_right.show(TRUE)
        @m_splitter.split_vertically( @m_left, @m_right )

        set_status_text("Splitter split vertically", 1)
    end

    def onUnsplit(event)
        if @m_splitter.is_split()
            @m_splitter.unsplit()
        end
        set_status_text("No splitter")
    end

    def onToggleLive(event)
        style = @m_splitter.get_window_style_flag()
        if event.is_checked()
            style |= SP_LIVE_UPDATE
        else
            style &= ~SP_LIVE_UPDATE
        end
        @m_splitter.set_window_style_flag(style)
    end

    def onSetPosition(event)

        str = sprintf("%d", @m_splitter.get_sash_position())
        str = get_text_from_user("Enter splitter position:", "", str, self)
        if str == ""
            return nil
        end

        pos = str.to_i
#        if  !str.ToLong(&pos)
#            LogError("The splitter position should be an integer.")
#            return nil
#        end

        @m_splitter.set_sash_position(pos)

        log_status(self, "Splitter position set to %d", pos)
    end

    def onSetMinSize(event)
        str = sprintf("%d", @m_splitter.get_minimum_pane_size())
        str = get_text_from_user("Enter minimal size for panes:", "", str, self)
        if str == ""
            return nil
        end

        minsize = str.to_i
        @m_splitter.set_minimum_pane_size(minsize)
        str = sprintf( "Min pane size = %d", minsize)
        set_status_text(str, 1)
    end

    def onUpdateUIHorizontal(event)
        event.enable( (!@m_splitter.is_split()) || (@m_splitter.get_split_mode() != SPLIT_HORIZONTAL) )
    end

    def onUpdateUIVertical(event)
        event.enable( ( (!@m_splitter.is_split()) || (@m_splitter.get_split_mode() != SPLIT_VERTICAL) ) )
    end

    def onUpdateUIUnsplit(event)
        event.enable( @m_splitter.is_split() )
    end

end


class MyApp < App
    def on_init
        # create and show the main frame
        frame = MyFrame.new

        frame.show(TRUE)
    end
end


a = MyApp.new
a.main_loop()
