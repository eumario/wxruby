# Demo created by Robert Carlin, 
#  based on the wxPython demo by Robin Dunn
#  Modified a bit by Kevin Smith

require 'wx'

MENU_EXIT = 100
TREE_ID = 101

OVR_TEXT = "This is the WxRuby Demo.  It was ported from the wxPython Demo, created by Robin Dunn.  Many thanks to him for all his hard work - this demo is what it is because of him.  Click on any of the items in the tree control to start the demo.  Don't forget to check out the Demo Code tab - you can see the source code for each demo!\nHope you like it!"

$tree_list = [
    #new stuff
    #['Recent Additions', [
    #    'wxMaskedNumCtrl',
    #    'FloatCanvas',
    #    ]],

    # managed windows == things with a [optional] caption you can close
    ['Base Frames and Dialogs', [
        'wxDialog',
        'wxFrame',
        'wxMDIWindows',
        #'wxMiniFrame',
        #'wxWizard',
        ]],

    # the common dialogs
    ['Common Dialogs', [
        'wxColourDialog',
        'wxDirDialog',
        'wxFileDialog',
        'wxFileDialog_Save',
        'wxFindReplaceDialog',
        'wxFontDialog',
        'wxMessageDialog',
        #'wxPageSetupDialog',
        #'wxPrintDialog',
        'wxProgressDialog',
        'wxSingleChoiceDialog',
        'wxTextEntryDialog',
        ]],

    # dialogs from libraries
    ['More Dialogs', [
    #    'ErrorDialogs',
    #    'ImageBrowser',
        'wxMultipleChoiceDialog',
        'wxScrolledMessageDialog'
        ]],

    # core controls
    ['Core Windows/Controls', [
        'PopupMenu',
        'wxButton',
        'wxCheckBox',
        'wxCheckListBox',
        'wxChoice',
        'wxComboBox',
        'wxGauge',
        #'wxGenericDirCtrl',
        'wxGrid',
        #'wxGrid_MegaExample',
        'wxListBox',
        #'wxListCtrl',
        'wxListCtrl_virtual',
        'wxMenu',
        'wxNotebook',
        #'wxPopupWindow',
        'wxRadioBox',
        'wxRadioButton',
        #'wxSashWindow',
        'wxScrolledWindow',
        'wxSlider',
        'wxSpinButton',
        'wxSpinCtrl',
        'wxSplitterWindow',
        'wxStaticBitmap',
        'wxStaticText',
        'wxStatusBar',
        'wxTextCtrl',
        'wxToggleButton',
        'wxToolBar',
        'wxTreeCtrl',
        #'wxValidator',
        ]],

    # controls coming from other libraries
    ['More Windows/Controls', [
        #'wxFloatBar',          deprecated
        #'wxMVCTree',           deprecated
        #'wxRightTextCtrl',     deprecated as we have wxTE_RIGHT now.
        #'AnalogClockWindow',
        #'ColourSelect',
        #'ContextHelp',
        #'FancyText',
        #'FloatCanvas',
        #'FileBrowseButton',
        #'GenericButtons',
        #'MaskedEditControls',
        #'PyShell',
        #'PyCrust',
        #'SplitTree',
        #'TablePrint',
        #'Throbber',
        #'wxCalendar',
        'wxCalendarCtrl',
        #'wxPyColourChooser',
        #'wxDynamicSashWindow',
        #'wxEditableListBox',
        #'wxEditor',
        #'wxHtmlWindow',
        #'wxIEHtmlWin',
        #'wxIntCtrl',
        #'wxLEDNumberCtrl',
        #'wxMimeTypesManager',
        #'wxMaskedNumCtrl',
        #'wxMultiSash',
        #'wxPopupControl',
        #'wxStyledTextCtrl_1',
        #'wxStyledTextCtrl_2',
        #'wxTimeCtrl',
        #'wxTreeListCtrl',
        ]],

    # How to lay out the controls in a frame/dialog
    ['Window Layout', [
    #    'LayoutAnchors',
    #    'Layoutf',
    #    'RowColSizer',
        'Sizers',
        'wxLayoutConstraints',
    #    'wxScrolledPanel',
    #    'wxXmlResource',
    #    'wxXmlResourceHandler',
        ]],

    # ditto
    #['Process and Events', [
    #    'EventManager',
    #   'infoframe',
    #    'OOR',
    #    'PythonEvents',
    #    'Threads',
    #    'wxKeyEvents',
    #    'wxProcess',
    #    'wxTimer',
    #    ]],

    #~ # Clipboard and DnD
    #~ ['Clipboard and DnD', [
        #~ #'CustomDragAndDrop',
        #~ 'DragAndDrop',
        #~ 'URLDragAndDrop',
        #~ ]],

    # Images
    #['Using Images', [
    #    'Throbber',
    #    'wxArtProvider',
    #    'wxDragImage',
    #    'wxImage',
    #    'wxImageFromStream',
    #    'wxMask',
    #    ]],

    # Other stuff
    #['Miscellaneous', [
    #    'ColourDB',
    #    'DialogUnits',
    #    'DrawXXXList',
    #    'FontEnumerator',
    #    'PrintFramework',
    #    'Throbber',
    #    'Unicode',
    #    'wxFileHistory',
    #    'wxJoystick',
    #    'wxOGL',
    #    'wxWave',
    #    ]],

    # need libs not coming with the demo
    #['Objects using an external library', [
    #    'ActiveXWrapper_Acrobat',
    #    'ActiveXWrapper_IE',
    #    'wxGLCanvas',
    #    'wxPlotCanvas',
    #    ]],


    ['Check out the samples dir too', [
        ]],

]

class DemoCodeViewer < Wx::TextCtrl
    def intialize(parent, id)
        super(parent, id, "", Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::TE_MULTILINE | Wx::TE_READONLY | Wx::HSCROLL | 
                                                                        Wx::TE_RICH | Wx::TE_NOHIDESEL)
    end
end

class WxRubyDemo < Wx::Frame
    attr_accessor :otherWin
    
    def initialize(title, pos, size, style=Wx::DEFAULT_FRAME_STYLE)
	    super(nil,-1,title,pos,size,style)
        @demoID = 6000
        @otherWin = nil
        
        icon = Wx::Icon.new("./icons/mondrian.xpm")
        set_icon(icon)
        
        evt_idle {|event| on_idle(event)}
        evt_close {|event| on_close(event)}
        evt_iconize {|event| on_iconize(event)}
        evt_maximize {|event| on_maximize(event)}
        
        centre(Wx::BOTH)
        create_status_bar(1, Wx::ST_SIZEGRIP)
        set_status_text("Welcome to the WxRuby Demo!")
        
        splitter = Wx::SplitterWindow.new(self, -1)
        splitter2 = Wx::SplitterWindow.new(splitter, -1)
        
        # Make a File menu
        
        @mainmenu = Wx::MenuBar.new
        menu = Wx::Menu.new
        menu.append(MENU_EXIT, "E&xit\tALT-X", "Get the heck outta here!")
        evt_menu(MENU_EXIT) {exit}
        @mainmenu.append(menu, "&File")
        
        # Make a Demo menu - thanks to Kevin Smith for figuring the submenus out!
        menu = Wx::Menu.new
        $tree_list.each do |item|
            @submenu = Wx::Menu.new
            item[1].each do |childItem|
                mID = @demoID += 1
                @submenu.append(mID, childItem)
                evt_menu(mID) {|event| on_demo_menu(childItem)}
            end
            menuItem = Wx::MenuItem.new(menu, 500000, item[0], "", Wx::ITEM_NORMAL, @submenu)
            menu.append_item(menuItem)
        end
        @mainmenu.append(menu, "&Demo")
        
        # Make a Help menu
        helpID = @demoID += 1
        findID = @demoID += 1
        findnextID = @demoID += 1
        clearID = @demoID += 1
        menu = Wx::Menu.new
        menu.append(findID, "&Find\tCtrl-F", "Find in the Demo Code")
        menu.append(findnextID, "Find &Next\tF3", "Find Next")
        menu.append_separator
        menu.append(helpID, "&About\tCtrl-H", "wxRuby RULES!!!")
        evt_menu(helpID) {|event| on_help_about(event)}
        evt_menu(findID) {|event| on_help_find(event)}
        evt_menu(findnextID) {|event| on_find_next(event)}
        evt_find(-1) {|event| on_find(event)}
        evt_find_next(-1) {|event| on_find(event)}
        evt_find_close(-1) {|event| on_find_close(event)}
        @mainmenu.append(menu, "&Help")
        set_menu_bar(@mainmenu)
        
        @finddata = Wx::FindReplaceData.new()
        
        @treeMap = {}
        @tree = Wx::TreeCtrl.new(splitter, TREE_ID, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::TR_DEFAULT_STYLE)#, Wx::TR_HAS_BUTTONS | Wx::TR_HAS_VARIABLE_ROW_HEIGHT)
        root = @tree.add_root("wxRuby Overview")
        firstChild = nil
        
        $tree_list.each do |item|
            child = @tree.append_item(root, item[0])
            if not firstChild then firstChild = child end
            item[1].each do |childItem|
                theDemo = @tree.append_item(child, childItem)
                @treeMap[childItem] = theDemo
            end
        end
        @tree.expand(root)
        @tree.expand(firstChild)
        
        evt_tree_item_expanded(TREE_ID) {|event| on_item_expanded(event)}
        evt_tree_item_collapsed(TREE_ID) {|event| on_item_collapsed(event)}
        evt_tree_sel_changed(TREE_ID) {|event| on_tree_sel_changed(event)}
        evt_tree_item_activated(TREE_ID) {|event| on_tree_sel_changed(event)}
        @tree.evt_left_down   {|event| on_tree_left_down(event)}
        
        
        
        # Create a Notebook
        @nb = Wx::Notebook.new(splitter2, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::CLIP_CHILDREN)
        
        @ovr = Wx::TextCtrl.new(@nb, -1, OVR_TEXT, Wx::DEFAULT_POSITION, Wx::Size.new(400,400), Wx::TE_MULTILINE | Wx::TE_READONLY |
                                                                                        Wx::HSCROLL | Wx::TE_RICH | Wx::TE_NOHIDESEL)
        @nb.add_page(@ovr, "Overview")
        
        @txt = Wx::TextCtrl.new(@nb, -1, OVR_TEXT, Wx::DEFAULT_POSITION, Wx::Size.new(400,400), Wx::TE_MULTILINE | Wx::TE_READONLY |
                                                                                        Wx::HSCROLL | Wx::TE_RICH | Wx::TE_NOHIDESEL)
        @txt.set_max_length(0)
        
        @nb.add_page(@txt, "Demo Code")
        get_demo_file("Main.rbw")
        
        @log = Wx::TextCtrl.new(splitter2, -1, "", Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::TE_MULTILINE | Wx::TE_READONLY |
                                                                                                Wx::HSCROLL)
        # For some reason when the number of characters entered is greater than about 10,700, the text control freezes.  I know 
        # someone mentioned this on the list a while ago...calling set_max_length(0) with zero as the argument tells the text
        # control to default limit that the underlying native text control can handle.
        @log.set_max_length(0)
        Wx::Log::set_active_target(Wx::LogTextCtrl.new(@log))
        
        splitter2.split_horizontally(@nb, @log, 0)
        splitter.split_vertically(@tree, splitter2, 190)
        
        splitter.set_minimum_pane_size(20)        
        splitter2.set_minimum_pane_size(20)
        
        @nb.set_selection(0)
        @tree.select_item(root)
        show_tip()
    end
    
    def write_text(text)
        Wx::log_message(text)
    end
    
    def on_idle(event)
        if @otherWin != nil
            @otherWin.raise()
            @window = @otherWin
            @otherWin = nil
        end
    end
    
    def on_close(event)
        destroy()
        exit()
    end
    
    def on_item_expanded(event)
        item = event.get_item()
        Wx::log_message("on_item_expanded: %s" % @tree.get_item_text(item))
    end
    
    def on_item_collapsed(event)
        item = event.get_item()
        Wx::log_message("on_item_collapsed: %s" % @tree.get_item_text(item))
    end
    
    def on_tree_sel_changed(event)
        item = event.get_item()
        itemText = @tree.get_item_text(item)
        run_demo(itemText)
    end
    
    def on_tree_left_down(event)
        pt = Wx::Point.new(event.get_x, event.get_y)
        item = @tree.hit_test(pt)
        if item == @tree.get_selection()
            set_overview(@tree.get_item_text(item) + " Overview", @curOverview)
            Wx::log_message(@tree.get_item_text(item) + " Overview")
        end
        event.skip()
    end
    
    def run_demo(itemText)
        if @nb.get_page_count() == 3
            if @nb.get_selection() == 2
                @nb.set_selection(0)
            end
            if @window != nil
                @window = nil
            end
            @nb.delete_page(2)
        end
        
        if itemText == "wxRuby Overview"
            get_demo_file("Main.rbw")
            set_overview("wxRuby Overview", OVR_TEXT)
            @nb.refresh()
            @window = nil       
        else
            if File.exist?(itemText + ".rbw")
                Wx::log_message("Running Demo: " + itemText + ".rbw")
                get_demo_file(itemText + ".rbw")
                # I use load() here because it allows the user to modify the underlying file for each sample, so that each time
                # They run it any changes made will be reflected without having to restart the demo.
                begin
                    load itemText + ".rbw"
                    set_overview(itemText + " Overview", Demo::overview)
                    @tree.refresh()
                    @nb.refresh()
                    @window = Demo.run(self, @nb, self)
                    if @window.class.ancestors.include?(Wx::Window)
                        # Check to see if the demo returned a Wx::Window, Wx::Panel or a new class inheriting from them
                        # if so, create a new tab in the notebook for them
                        @nb.add_page(@window, "Demo")
                        @nb.set_selection(2)
                        @nb.refresh()
                    end
                rescue Exception => problem
                    dlg = Wx::MessageDialog.new(self, "A problem occurred with the %s demo:\n%s\n%s" % [itemText, problem, problem.backtrace().join("\n").to_s()], 
                                                "Error!!!", Wx::OK | Wx::ICON_ERROR)
                    dlg.show_modal()
                    dlg.destroy()
                end
            else
                @ovr.set_value("")
                @txt.clear()
                @window = nil
            end
        end
        @tree.set_focus()
    end
    
    def get_demo_file(fileName)
        @txt.clear()
        @txt.load_file(fileName)
        @txt.set_insertion_point(0)
        @txt.show_position(0)
    end
    
    def set_overview(name, text)
        @curOverview = text
        @ovr.set_value(text)
        @ovr.set_style(0,text.length,Wx::TextAttr.new(Wx::BLUE, Wx::Colour.new("White"), Wx::Font.new(12, Wx::FONTFAMILY_SWISS, Wx::FONTSTYLE_NORMAL, Wx::FONTWEIGHT_BOLD)))
        @nb.set_page_text(0, name)
    end
    
    # Menu Methods
    
    def on_file_exit(event)
        close()
    end
    
    def on_help_about(event)
        load "About.rbw"
        about = About::MyAboutBox.new(self)
        about.show_modal()
        about.destroy()
    end
    
    def on_help_find(event)
        @nb.set_selection(1)
        @finddlg = Wx::FindReplaceDialog.new(self, @finddata, "Find", Wx::FR_NOUPDOWN | Wx::FR_NOMATCHCASE | Wx::FR_NOWHOLEWORD)
        @finddlg.show()
    end
    
    def on_find(event)
        # Problems
        # 1) For some reason, the control is not properly counting EOL characters - it almost seems to be skipping them
        #    causing the control to incorrectly set the initial insertion point for the the "found" text
        # 2) This also is causing problems with the amount of text that is highlighted - the length of the highlighted string
        #    is less than it should be 
        # 3) After doing an initial "find" operation, using the "find next" operation causes the program to crash - again, I
        #    don't know why this is :(
        # Example - When I try to find "menu", the text that gets highlighted is the newline on the second line and the "ME" of 
        #           MENU_EXIT - a total of only 3 characters, when it should highlight all of "menu".  I don't fully understand
        #           this problem, but it doesn't appear until after you attempt to find text beyond the first line :(
        @nb.set_selection(1)
        myEnd = @txt.get_last_position()
        write_text("Last position = %d" % myEnd)
        textstring = @txt.get_range(0,myEnd).downcase()
        if Wx::RUBY_PLATFORM == "WXMSW"
            textstring.sub!(/\n/, "\r\n")
        end
        #write_text("textstring - %s" % textstring)
        start = @txt.get_insertion_point()
        write_text("insertion point = " + start.to_s())
        findstring = @finddata.get_find_string().downcase()
        write_text("finddata = " + findstring)
        loc = textstring.index(findstring, start)
        write_text("location = " + loc.to_s())
        write_text("findstring.length() = " + findstring.length().to_s())
        if loc == nil and start != 0
            # string not found, start at beginning
            start = 0
            loc = textstring.index(findstring, start)
        end
        
        if loc == nil
            dlg = Wx::MessageDialog.new(self, 'Find String Not Found', 'Find String Not Found in Demo File',
                                          Wx::OK | Wx::ICON_INFORMATION)
            dlg.show_modal()
            dlg.destroy()
        end
        
        if @finddlg
            if loc == nil
                @finddlg.set_focus()
                return
            else
                @finddlg.destroy()
            end
        end
        @txt.show_position(loc)
        @txt.set_selection(loc, loc + findstring.length())
    end
    
    def on_find_next(event)
        if @finddata.get_find_string() != ""
            on_find(event)
        else
            on_help_find(event)
        end
    end
    
    def on_find_close(event)
        event.get_dialog().destroy()
    end
    
    def show_tip()
        tp = Wx::create_file_tip_provider("tips.txt", rand(6))
        Wx::show_tip(self, tp)
    end
    
    def on_demo_menu(childItem)
        # Also, for some reason I haven't figured out yet either, the demo executes two times
        selectedDemo = @treeMap[childItem]
        if selectedDemo
            @tree.select_item(selectedDemo)
            @tree.ensure_visible(selectedDemo)
        end
    end
    
    def on_iconize(event)
        Wx::log_message("on_iconify")
        event.skip
    end
    
    def on_maximize(event)
        Wx::log_message("on_maximize")
        event.skip
    end
end

class SimpleApp < Wx::App
  def on_init
    frame = WxRubyDemo.new("Minimal wxRuby App",Wx::DEFAULT_POSITION, Wx::Size.new(700, 400))

    frame.show(TRUE)

  end
end

Wx::init_all_image_handlers
test = SimpleApp.new
test.main_loop
