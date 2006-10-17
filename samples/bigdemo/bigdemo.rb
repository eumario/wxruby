#!/usr/bin/env ruby
# Demo created by Robert Carlin, 
#  based on the wxPython demo by Robin Dunn
#  Modified a bit by Kevin Smith and Roy Sutton

#  TODO:
#    Finish Scintilla integration
#    Fix 'Find Next'
#    Refactor editor pane
#    More samples
#    Finish 'rubification' of source
#    Fix non-scintilla code viewer

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems'
    require 'wx'
  rescue LoadError
    raise no_wx_err
  end
end

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
        'wxMiniFrame',
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
        'wxBitmapButton',
        'wxButton',
        'wxCheckBox',
        'wxCheckListBox',
        'wxChoice',
        'wxChoicebook',
        'wxComboBox',
        'wxGauge',
        'wxGenericDirCtrl',
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
        'wxSashWindow',
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
    ['Using Images', [
    #    'Throbber',
        'wxArtProvider',
        'wxCursor',
        'wxDragImage',
    #    'wxImage',
    #    'wxImageFromStream',
    #    'wxMask',
        ]],

    # Other stuff
    ['Miscellaneous', [
    #    'ColourDB',
    #    'DialogUnits',
    #    'DrawXXXList',
    #    'FontEnumerator',
    #    'PrintFramework',
         'ShapedWindow',
    #    'Throbber',
    #    'Unicode',
    #    'wxFileHistory',
    #    'wxJoystick',
    #    'wxOGL',
    #    'wxWave',
        ]],

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
        super(parent, id, OVR_TEXT, Wx::DEFAULT_POSITION, Wx::Size.new(400, 400), 
              Wx::TE_MULTILINE|Wx::TE_READONLY|Wx::HSCROLL|
              Wx::TE_RICH|Wx::TE_NOHIDESEL)
    end
end

class WxRubyDemo < Wx::Frame
    attr_accessor :otherWin
    
    def initialize(title, pos, size, style=Wx::DEFAULT_FRAME_STYLE)
	    super(nil,-1,title,pos,size,style)
        @demoID = 6000
        @otherWin = nil
        
        icon_file = File.join(File.dirname(__FILE__), 'icons', 'mondrian.xpm')
        icon = Wx::Icon.new(icon_file, Wx::BITMAP_TYPE_XPM)
        set_icon(icon)

        @tbicon = DemoTaskBarIcon.new(self)
        
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
        
        @ovr = Wx::TextCtrl.new(@nb, -1, OVR_TEXT, Wx::DEFAULT_POSITION, 
                                Wx::Size.new(400,400), 
                                Wx::TE_MULTILINE|Wx::TE_READONLY|
                                Wx::TE_RICH|Wx::TE_NOHIDESEL)
        @nb.add_page(@ovr, "Overview")
        
        if Wx.const_defined?(:Scintilla)
          panel, @txt = setup_editor(@nb)
          @nb.add_page(panel, "Demo Code")
        else
          # FIXME: Should use DemoCodeViewer, but when we do (on Windows) it
          #         puts all text on one line!  Can remove instance_eval
          #         once that's resolved
          @txt = Wx::TextCtrl.new(@nb, -1, OVR_TEXT, Wx::DEFAULT_POSITION, 
                                  Wx::Size.new(400,400), 
                                  Wx::TE_MULTILINE|Wx::TE_READONLY|
                                  Wx::HSCROLL|Wx::TE_RICH|Wx::TE_NOHIDESEL)
          @txt.instance_eval { alias clear_all clear }
          @txt.set_max_length(0)
          @nb.add_page(@txt, "Demo Code")
        end
        
        get_demo_file(__FILE__)
        
        @log = Wx::TextCtrl.new(splitter2, -1, "", Wx::DEFAULT_POSITION, 
                                Wx::DEFAULT_SIZE, 
                                Wx::TE_MULTILINE|Wx::TE_READONLY|Wx::HSCROLL)
        # For some reason when the number of characters entered is
        # greater than about 10,700, the text control freezes.  I know  
        # someone mentioned this on the list a while ago...calling
        # set_max_length(0) with zero as the argument tells the text 
        # control to default limit that the underlying native text
        # control can handle. 
        @log.set_max_length(0)
        Wx::Log::set_active_target(Wx::LogTextCtrl.new(@log))
        
        splitter2.split_horizontally(@nb, @log, 350)
        splitter.split_vertically(@tree, splitter2, 190)
        
        splitter.set_minimum_pane_size(20)        
        splitter2.set_minimum_pane_size(100)
        
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
        @tbicon.remove_icon
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
        if item.is_ok
          itemText = @tree.get_item_text(item)
          run_demo(itemText)
        end
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
            get_demo_file(__FILE__)
            set_overview("wxRuby Overview", OVR_TEXT)
            @nb.refresh()
            @window = nil       
        else
          demo_file = File.join( File.dirname(__FILE__), itemText + '.rbw')
            if File.exist?(demo_file)
                Wx::log_message("Running Demo: " + itemText + ".rbw")
                get_demo_file(demo_file)
                # I use load() here because it allows the user to modify
                # the underlying file for each sample, so that each time 
                # They run it any changes made will be reflected without
                # having to restart the demo. 
                begin
                    load demo_file
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
                @txt.clear_all
                @window = nil
            end
        end
        @tree.set_focus()
    end
    
    def get_demo_file(fileName)
        @filename = fileName
        @txt.clear()
        @txt.load_file(fileName)
        if @txt.is_a?(Wx::TextCtrl)
          @txt.set_insertion_point(0)
          @txt.show_position(0)
        end
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
        # FIXME: These problems are probably resolved now
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
        if @txt.is_a?(Wx::TextCtrl)
          @nb.set_selection(1)
          myEnd = @txt.get_last_position()
          write_text("Last position = %d" % myEnd)
          textstring = @txt.get_range(0,myEnd).downcase()
          if Wx::PLATFORM == "WXMSW"
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
        else # Scintilla
          # FIXME: Take into account search direction
          @txt.set_target_start(@txt.get_target_end)
          @txt.set_target_end(@txt.get_length - 1)
          # FIXME: get flags from find dialog
          @txt.set_search_flags(0)
          loc = @txt.search_in_target(event.get_find_string)
          if loc == -1
            dlg = Wx::MessageDialog.new(self, 'Find String Not Found', 'Find String Not Found in Demo File',
                                          Wx::OK | Wx::ICON_INFORMATION)
            dlg.show_modal()
            dlg.destroy()
          end

          if @finddlg
            if loc == -1
              @finddlg.set_focus()
              return
            end
          end
          @txt.ensure_caret_visible
          @txt.set_selection(loc, loc + event.get_find_string.length)
        end
    end
    
    def on_find_next(event)
        # FIXME: Saving an event is probably a bad idea
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
      tips_file = File.join(File.dirname(__FILE__), 'tips.txt')
      tp = Wx::create_file_tip_provider( tips_file, rand(6) )
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

    # FIXME: Refactor into a class
    def setup_editor(parent)
      panel = Wx::Panel.new(parent)
      panel.hide
      sci = setup_scintilla(panel)
      @save_button = Wx::Button.new(panel, -1, 'Save Changes')
      @delete_button = Wx::Button.new(panel, -1, 'Delete Modified')
      @save_button.enable(false);
      panel.evt_button(@save_button.get_id) { on_save }
      panel.evt_button(@delete_button.get_id) { on_delete }
      panel.evt_sci_modified { on_modified }

      radio_buttons = {:original => Wx::RadioButton.new(panel, -1, "Original", Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::RB_GROUP),
                       :modified => Wx::RadioButton.new(panel, -1, "Modified")}
      
      @control_box = Wx::BoxSizer.new(Wx::HORIZONTAL)
      @control_box.add(Wx::StaticText.new(panel, -1, 'Active Version:'), 0, Wx::RIGHT | Wx::LEFT | Wx::ALIGN_CENTER_VERTICAL, 5)
      radio_buttons.each_pair { |id, button|
        @control_box.add(button, 0, Wx::EXPAND | Wx::RIGHT, 5)
        evt_radiobutton(button.get_id) { |event| on_radio_button(event) }
      }
      @control_box.add(@save_button, 0, Wx::RIGHT, 5)
      @control_box.add(@delete_button, 0)

      @box = Wx::BoxSizer.new(Wx::VERTICAL)
      @box.add(@control_box, 0, Wx::EXPAND)
      @box.add(Wx::StaticLine.new(panel), 0, Wx::EXPAND)
      
      @box.add(sci, 1, Wx::EXPAND)
      @box.fit(panel)
      panel.set_sizer(@box)
      [panel, sci]
    end

    def setup_scintilla(parent)
      sci = Wx::Scintilla.new(parent)
      font = Wx::Font.new(10, Wx::TELETYPE, Wx::NORMAL, Wx::NORMAL)
      sci.style_set_font(Wx::SCI_STYLE_DEFAULT, font);
      sci.set_edge_mode(Wx::SCI_EDGE_LINE)
      line_num_margin = sci.text_width(Wx::SCI_STYLE_LINENUMBER, "_99999")
      sci.set_margin_width(0, line_num_margin)

      sci.style_set_foreground(Wx::SCI_STYLE_DEFAULT, Wx::BLACK);
      sci.style_set_background(Wx::SCI_STYLE_DEFAULT, Wx::WHITE);
      sci.style_set_foreground(Wx::SCI_STYLE_LINENUMBER, Wx::LIGHT_GREY);
      sci.style_set_background(Wx::SCI_STYLE_LINENUMBER, Wx::WHITE);
      sci.style_set_foreground(Wx::SCI_STYLE_INDENTGUIDE, Wx::LIGHT_GREY);

      sci.set_tab_width(2)
      sci.set_use_tabs(false)
      sci.set_tab_indents(true)
      sci.set_back_space_un_indents(true)
      sci.set_indent(2)
      sci.set_edge_column(80)

      sci.set_lexer(Wx::SCI_LEX_RUBY)
      sci.style_clear_all
      sci.style_set_foreground(2, Wx::RED)
      sci.style_set_foreground(3, Wx::GREEN)
      sci.style_set_foreground(5, Wx::BLUE)
      sci.style_set_foreground(6, Wx::BLUE)
      sci.style_set_foreground(7, Wx::BLUE)
      sci.set_key_words(0, "begin break elsif module retry unless end case next return until class ensure nil self when def false not super while alias defined? for or then yield and do if redo true else in rescue undef")

      sci.set_property("fold","1")
      sci.set_property("fold.compact", "0")
      sci.set_property("fold.comment", "1")
      sci.set_property("fold.preprocessor", "1")

      sci.set_margin_width(1, 0)
      sci.set_margin_type(1, Wx::SCI_MARGIN_SYMBOL)
      sci.set_margin_mask(1, Wx::SCI_MASK_FOLDERS)
      sci.set_margin_width(1, 20)

      sci.marker_define(Wx::SCI_MARKNUM_FOLDER, Wx::SCI_MARK_PLUS)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDEROPEN, Wx::SCI_MARK_MINUS)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDEREND, Wx::SCI_MARK_EMPTY)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDERMIDTAIL, Wx::SCI_MARK_EMPTY)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDEROPENMID, Wx::SCI_MARK_EMPTY)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDERSUB, Wx::SCI_MARK_EMPTY)
      sci.marker_define(Wx::SCI_MARKNUM_FOLDERTAIL, Wx::SCI_MARK_EMPTY)
      sci.set_fold_flags(16)

      sci.set_margin_sensitive(1,1)
      sci
    end

    def on_save
      if not FileTest.directory?(File.dirname(modified_filename))
        if not Dir.mkdir(File.dirname(modified_filename))
          Wx::log_message("Unable to create directory 'modified'")
          return
        end
      end
      File.open(modified_filename, "w") { |file|
        file.write(@txt.get_text)
      }
      # FIXME: Reload module we just saved
    end

    def on_delete
      if File.exists?(modified_filename)
        File.unlink(modified_filename)
      end
      # FIXME: Update state
    end

    def on_modified
      @save_button.enable(@txt.get_modify)
    end

    def on_radio_button(event)
      # FIXME: Can't do anything here yet
    end

    def modified_filename
      File.join(File.dirname(@filename), "modified", File.basename(@filename))
    end
end

class DemoTaskBarIcon < Wx::TaskBarIcon
  # TODO: Need a new_id function like wxPython has
  TBMENU_RESTORE = 6000
  TBMENU_CLOSE = 6001
  TBMENU_CHANGE = 6002
  TBMENU_REMOVE = 6003

  def initialize(frame)
    super()

    @frame = frame

    # starting image
    icon = make_icon('ruby.png')
    set_icon(icon, 'wxRuby Demo')
    @image_index = 1

    # events
    evt_taskbar_left_dclick  {|evt| on_taskbar_activate(evt) }
    
    evt_menu(TBMENU_RESTORE) {|evt| on_taskbar_activate(evt) }
    evt_menu(TBMENU_CLOSE)   { @frame.close }
    evt_menu(TBMENU_CHANGE)  {|evt| on_taskbar_change(evt) }
    evt_menu(TBMENU_REMOVE)  { remove_icon }
  end

  def create_popup_menu
    # Called by the base class when it needs to popup the menu
    #  (the default evt_right_down event).  Create and return
    #  the menu to display.
    menu = Wx::Menu.new
    menu.append(TBMENU_RESTORE, "Restore wxRuby Demo")
    menu.append(TBMENU_CLOSE,   "Close wxRuby Demo")
    menu.append_separator
    menu.append(TBMENU_CHANGE,  "Change the TB Icon")
    menu.append(TBMENU_REMOVE,  "Remove the TB Icon")
    return menu
  end

  def make_icon(imgname)
    # Different platforms have different requirements for the
    #  taskbar icon size
    filename = File.join( File.dirname(__FILE__), 'icons', imgname )
    img = Wx::Image.new(filename)
    if Wx::PLATFORM == "WXMSW"
      img = img.scale(16, 16)
    elsif Wx::PLATFORM == "WXGTK"
      img = img.scale(22, 22)
    end
    # WXMAC can be any size up to 128x128, so don't scale
    icon = Wx::Icon.new
    icon.copy_from_bitmap(Wx::Bitmap.new(img))
    return icon
  end

  def on_taskbar_activate(evt)
    if @frame.is_iconized
      @frame.iconize(false)
    end
    if not @frame.is_shown
      @frame.show(true)
    end
    @frame.raise
  end

  def on_taskbar_change(evt)
    names = [ "ruby.png", "wxwin16x16.xpm", "smiles.xpm", "mondrian.xpm" ]
    name = names[@image_index]
    @image_index += 1
    if @image_index >= names.length
      @image_index = 0
    end

    icon = make_icon(name)
    set_icon(icon, 'This is a new icon: ' + name)
  end

end

class DemoApp < Wx::App
  def on_init
    frame = WxRubyDemo.new("WxRuby BIG combined demo",
                           Wx::DEFAULT_POSITION, 
                           Wx::Size.new(750, 550))

    frame.show(true)
  end
end

demo = DemoApp.new
demo.main_loop
