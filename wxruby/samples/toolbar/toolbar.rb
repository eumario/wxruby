
require 'wxruby'
include Wx

ID_TOOLBAR = 500

TOOLBAR_STYLE = TB_FLAT | TB_DOCKABLE | TB_TEXT


IDM_TOOLBAR_TOGGLETOOLBARSIZE = 200
IDM_TOOLBAR_TOGGLETOOLBARORIENT = 201
IDM_TOOLBAR_TOGGLETOOLBARROWS = 202
IDM_TOOLBAR_ENABLEPRINT = 203
IDM_TOOLBAR_DELETEPRINT = 204
IDM_TOOLBAR_INSERTPRINT = 205
IDM_TOOLBAR_TOGGLEHELP = 206
IDM_TOOLBAR_TOGGLE_TOOLBAR = 207
IDM_TOOLBAR_TOGGLE_ANOTHER_TOOLBAR = 208
IDM_TOOLBAR_CHANGE_TOOLTIP = 209
IDM_TOOLBAR_SHOW_TEXT = 210
IDM_TOOLBAR_SHOW_ICONS = 211
IDM_TOOLBAR_SHOW_BOTH = 212

ID_COMBO = 1000


class MyFrame < Frame
    def initialize(parent,id = -1,title = "ToolBar Sample",pos = DEFAULT_POSITION,
                size = DEFAULT_SIZE,style = DEFAULT_FRAME_STYLE)
        super(parent, id, title, pos, size, style)

        @m_tbar = nil
        @m_textWindow = TextCtrl.new(self, -1, "", Point.new(0, 0), Size.new(-1, -1), TE_MULTILINE)

        @m_smallToolbar = TRUE
        @m_horzToolbar = TRUE
        @m_rows = 1
        @m_nPrint = 1

        # Give it a status line
        create_status_bar()

        # Give it an icon
        set_icon(Icon.new("mondrian.xpm"))

        # Make a menubar
        tbarMenu = Menu.new
        tbarMenu.append_check_item(IDM_TOOLBAR_TOGGLE_TOOLBAR,
                                  "Toggle &toolbar\tCtrl-Z",
                                  "show or hide the toolbar")

        tbarMenu.append_check_item(IDM_TOOLBAR_TOGGLE_ANOTHER_TOOLBAR,
                                  "Toggle &another toolbar\tCtrl-A",
                                  "show/hide another test toolbar")

        tbarMenu.append_check_item(IDM_TOOLBAR_TOGGLETOOLBARSIZE,
                                  "&Toggle toolbar size\tCtrl-S",
                                  "Toggle between big/small toolbar")

        tbarMenu.append_check_item(IDM_TOOLBAR_TOGGLETOOLBARORIENT,
                                  "Toggle toolbar &orientation\tCtrl-O",
                                  "Toggle toolbar orientation")

        tbarMenu.append_check_item(IDM_TOOLBAR_TOGGLETOOLBARROWS,
                                  "Toggle number of &rows\tCtrl-R",
                                  "Toggle number of toolbar rows between 1 and 2")

        tbarMenu.append_separator()

        tbarMenu.append(IDM_TOOLBAR_ENABLEPRINT, "&enable print button\tCtrl-E", "")
        tbarMenu.append(IDM_TOOLBAR_DELETEPRINT, "&Delete print button\tCtrl-D", "")
        tbarMenu.append(IDM_TOOLBAR_INSERTPRINT, "&Insert print button\tCtrl-I", "")
        tbarMenu.append(IDM_TOOLBAR_TOGGLEHELP, "Toggle &help button\tCtrl-T", "")
        tbarMenu.append_separator()
        tbarMenu.append(IDM_TOOLBAR_CHANGE_TOOLTIP, "Change tool tip", "")
        tbarMenu.append_separator()
        tbarMenu.append_radio_item(IDM_TOOLBAR_SHOW_TEXT, "show &text\tAlt-T")
        tbarMenu.append_radio_item(IDM_TOOLBAR_SHOW_ICONS, "show &icons\tAlt-I")
        tbarMenu.append_radio_item(IDM_TOOLBAR_SHOW_BOTH, "show &both\tAlt-B")

        fileMenu = Menu.new
        fileMenu.append(ID_EXIT, "E&xit\tAlt-X", "Quit toolbar sample" )

        helpMenu = Menu.new
        helpMenu.append(ID_HELP, "&About", "About toolbar sample")

        menuBar = MenuBar.new( MB_DOCKABLE )

        menuBar.append(fileMenu, "&File")
        menuBar.append(tbarMenu, "&Toolbar")
        menuBar.append(helpMenu, "&Help")

        # Associate the menu bar with the frame
        set_menu_bar(menuBar)

        menuBar.check(IDM_TOOLBAR_SHOW_BOTH, TRUE)

        # Create the toolbar
        RecreateToolbar()

        evt_size {|event| onSize(event) }

        evt_menu(ID_EXIT) {|event| onQuit(event) }
        evt_menu(ID_HELP) {|event| onAbout(event) }

        evt_menu(IDM_TOOLBAR_TOGGLE_TOOLBAR) {|event| onToggleToolbar(event) }
        evt_menu(IDM_TOOLBAR_TOGGLE_ANOTHER_TOOLBAR) {|event| onToggleAnotherToolbar(event) }
        evt_menu(IDM_TOOLBAR_TOGGLETOOLBARSIZE) {|event| onToggleToolbarSize(event) }
        evt_menu(IDM_TOOLBAR_TOGGLETOOLBARORIENT) {|event| onToggleToolbarOrient(event) }
        evt_menu(IDM_TOOLBAR_TOGGLETOOLBARROWS) {|event| onToggleToolbarRows(event) }

        evt_menu(IDM_TOOLBAR_ENABLEPRINT) {|event| onEnablePrint(event) }
        evt_menu(IDM_TOOLBAR_DELETEPRINT) {|event| onDeletePrint(event) }
        evt_menu(IDM_TOOLBAR_INSERTPRINT) {|event| onInsertPrint(event) }
        evt_menu(IDM_TOOLBAR_TOGGLEHELP) {|event| onToggleHelp(event) }
        evt_menu(IDM_TOOLBAR_CHANGE_TOOLTIP) {|event| onChangeToolTip(event) }

        evt_menu_range(IDM_TOOLBAR_SHOW_TEXT, IDM_TOOLBAR_SHOW_BOTH) {|event| onToolbarStyle(event) }

#        evt_menu(-1) {|event| onToolLeftClick(event) }

        evt_combobox(ID_COMBO) {|event| onCombo(event) }

        evt_tool_enter(ID_TOOLBAR) {|event| onToolEnter(event) }

        evt_update_ui(ID_COPY) {|event| onUpdateCopyAndCut(event) }
        evt_update_ui(ID_CUT) {|event| onUpdateCopyAndCut(event) }

    end

    def RecreateToolbar()

        # delete and recreate the toolbar
        toolBar = get_tool_bar()
        style = toolBar ? toolBar.get_window_style_flag() : TOOLBAR_STYLE

        if toolBar != nil
            toolBar.free
        end

        set_tool_bar(nil)

        style &= ~(TB_HORIZONTAL | TB_VERTICAL)
        style |= @m_horzToolbar ? TB_HORIZONTAL : TB_VERTICAL

        toolBar = create_tool_bar(style, ID_TOOLBAR)

        # Set up toolbar
        toolBarBitmaps = [ Bitmap.new("bitmaps/new.xpm"),
            Bitmap.new("bitmaps/open.xpm"),
            Bitmap.new("bitmaps/save.xpm"),
            Bitmap.new("bitmaps/copy.xpm"),
            Bitmap.new("bitmaps/cut.xpm"),
            Bitmap.new("bitmaps/preview.xpm"),
            Bitmap.new("bitmaps/print.xpm"),
            Bitmap.new("bitmaps/help.xpm")]

        if  !@m_smallToolbar
            w = 2*toolBarBitmaps[0].get_width()
            h = 2*toolBarBitmaps[0].get_height()
            for n in 0 ... toolBarBitmaps.length
                toolBarBitmaps[n] =
                    Bitmap.new(toolBarBitmaps[n].convert_to_image().scale(w, h))
            end

            toolBar.set_tool_bitmap_size(Size.new(w, h))
        end

        toolBar.add_tool(ID_NEW, "New", toolBarBitmaps[0], "New file")
        toolBar.add_tool(ID_OPEN, "Open", toolBarBitmaps[1], "Open file")

        if  @m_horzToolbar
            combo = ComboBox.new(toolBar, ID_COMBO, "", DEFAULT_POSITION, Size.new(200,-1) )
            combo.append("This")
            combo.append("is a")
            combo.append("combobox")
            combo.append("in a")
            combo.append("toolbar")
            toolBar.add_control(combo)
        end

        toolBar.add_tool(ID_SAVE, "Save", toolBarBitmaps[2], "Toggle button 1", ITEM_CHECK)
        toolBar.add_tool(ID_COPY, "Copy", toolBarBitmaps[3], "Toggle button 2", ITEM_CHECK)
        toolBar.add_tool(ID_CUT, "Cut", toolBarBitmaps[4], "Toggle/Untoggle help button")
        toolBar.add_tool(ID_PASTE, "Paste", toolBarBitmaps[5], "Paste")
        toolBar.add_tool(ID_PRINT, "Print", toolBarBitmaps[6], "Delete self tool")
        toolBar.add_separator()
        toolBar.add_tool(ID_HELP, "Help", toolBarBitmaps[7], "Help button", ITEM_CHECK)

        # after adding the buttons to the toolbar, must call realize() to reflect
        # the changes
        toolBar.realize()

        toolBar.set_rows(@m_horzToolbar ? @m_rows : 10 / @m_rows)
    end

    def LayoutChildren()

        size = get_client_size()

        if @m_tbar
            @m_tbar.set_size_xy(-1, size.y)
            @m_tbar.move(Point.new(0, 0))
            offset = @m_tbar.get_size().x
        else
            offset = 0
        end

        @m_textWindow.set_dimensions(offset, 0, size.x - offset, size.y)
    end

    def onSize(event)
        if @m_tbar
            LayoutChildren()
        else
            event.skip()
        end
    end

    def onToggleToolbar(event)
        tbar = get_tool_bar()

        if !tbar
            RecreateToolbar()
        else
            tbar.free
            set_tool_bar(nil)
        end
    end

    def onEnablePrint(event)
        DoEnablePrint()
    end

    def onDeletePrint(event)
        DoDeletePrint()
    end

    def onToggleHelp(event)
        DoToggleHelp()
    end

    def onToggleAnotherToolbar(event)
        if @m_tbar
            @m_tbar.free
            @m_tbar = nil
        else
            tb = get_tool_bar()
            style = 0
            style = tb.get_window_style_flag() if tb

            style &= ~TB_HORIZONTAL
            style |= TB_VERTICAL

            @m_tbar = ToolBar.new(self, -1,
                                   DEFAULT_POSITION, DEFAULT_SIZE,
                                   style)

            @m_tbar.set_margins(4, 4)

            @m_tbar.add_radio_tool(ID_NEW, "First", Bitmap.new("bitmaps/new.xpm"))
            @m_tbar.add_radio_tool(ID_OPEN, "Second", Bitmap.new("bitmaps/open.xpm"))
            @m_tbar.add_radio_tool(ID_SAVE, "Third", Bitmap.new("bitmaps/save.xpm"))
            @m_tbar.add_separator()
            @m_tbar.add_tool(ID_HELP, "Help", Bitmap.new("bitmaps/help.xpm"))

            @m_tbar.realize()
        end

        LayoutChildren()
    end

    def onToggleToolbarSize(event)
        @m_smallToolbar = !@m_smallToolbar

        RecreateToolbar()
    end

    def onToggleToolbarRows(event)
        # @m_rows may be only 1 or 2
        @m_rows = 3 - @m_rows

        get_tool_bar().set_rows((@m_horzToolbar != nil) ? @m_rows : 10 / @m_rows)

        #RecreateToolbar() -- self is unneeded
    end

    def onToggleToolbarOrient(event)
        @m_horzToolbar = !@m_horzToolbar
        RecreateToolbar()
    end

    def onQuit(event)
        close(TRUE)
    end

    def onAbout(event)
        message_box("Windows toolbar sample", "About ToolBar")
    end

    def onToolLeftClick(event)
        str = sprintf( "Clicked on tool %d\n", event.get_id())
        @m_textWindow.write_text( str )

        if event.get_id() == ID_HELP
            if event.get_extra_long() != 0
                @m_textWindow.write_text( "Help button down now.\n" )
            else
                @m_textWindow.write_text( "Help button up now.\n" )
            end
        end

        if event.get_id() == ID_COPY
            DoEnablePrint()
        end

        if event.get_id() == ID_CUT
            DoToggleHelp()
        end

        if event.get_id() == ID_PRINT
            DoDeletePrint()
        end
    end

    def onCombo(event)
        log_status("Combobox string '%s' selected", event.get_string())
    end

    def DoEnablePrint()
        if !@m_nPrint
            return nil
        end

        tb = get_tool_bar()
        tb.enable_tool(ID_PRINT, !tb.get_tool_enabled(ID_PRINT)) if tb
    end

    def DoDeletePrint()
        if  !@m_nPrint
            return nil
        end

        tb = get_tool_bar()
        tb.delete_tool( ID_PRINT ) if tb

        @m_nPrint -= 1
    end

    def DoToggleHelp()
        tb = get_tool_bar()
        tb.toggle_tool( ID_HELP, !tb.get_tool_state( ID_HELP ) ) if tb
    end

    def onUpdateCopyAndCut(event)
        event.enable( @m_textWindow.can_copy() )
    end

    def onChangeToolTip(event)
        get_tool_bar().set_tool_short_help(ID_NEW, "New toolbar button")
    end

    def onToolbarStyle(event)
        tb = get_tool_bar()
        style = 0
        style = tb.get_window_style_flag() if tb
        style &= ~(TB_NOICONS | TB_TEXT)

        case  event.get_id()
            when IDM_TOOLBAR_SHOW_TEXT
                style |= TB_NOICONS | TB_TEXT
            when IDM_TOOLBAR_SHOW_ICONS
                # nothing to do
            when IDM_TOOLBAR_SHOW_BOTH
                style |= TB_TEXT
        end

        get_tool_bar().set_window_style_flag(style)
    end

    def onInsertPrint(event)
        @m_nPrint += 1

        tb = get_tool_bar()
        tb.insert_tool(0, ID_PRINT, "New print",
                       Bitmap.new("bitmaps/print.xpm"), NULL_BITMAP,
                       ITEM_NORMAL,
                       "Delete self tool",
                       "This button was inserted into the toolbar")

        # must call realize() after adding a new button
        tb.realize()
    end

    def onToolEnter(event)
        if event.get_selection() > -1
            str = sprintf("This is tool number %d", event.get_selection())
            set_status_text(str)
        else
            set_status_text("")
        end
    end

end

class MyApp < App
    def on_init
        # Create the main frame window
        frame = MyFrame.new(nil, -1,
                                 "ToolBar Sample",
                                 Point.new(100, 100), Size.new(550, 300))

        frame.show(TRUE)

        frame.set_status_text("Hello, Windows")

        set_top_window(frame)
    end

    
end

a = MyApp.new
a.main_loop()
