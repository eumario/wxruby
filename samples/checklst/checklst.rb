require 'wxruby'
include Wx

Menu_About = 100
Menu_Quit = 101
Menu_Selection = 102

Control_First = 1000
Control_Listbox = 1001
Btn_Up = 1002
Btn_Down = 1003

# Define a new frame type
class CheckListBoxFrame < Frame

    def initialize(frame,title,x,y,w,h)
        super(frame, -1, title, Point.new(x, y), Size.new(w, h))

        # create the status line
        widths =  [-1, 60]
        create_status_bar(2)
        set_status_widths(widths)
        log_status(self, "no selection")

        # Make a menubar
        # --------------

        # file submenu
        menuFile = Menu.new
        menuFile.append(Menu_About, "&About...\tF1")
        menuFile.append_separator()
        menuFile.append(Menu_Quit, "E&xit\tAlt-X")

        # listbox submenu
        menuList = Menu.new
        menuList.append_check_item(Menu_Selection, "Multiple selection\tCtrl-M")

        # put it all together
        menu_bar = MenuBar.new
        menu_bar.append(menuFile, "&File")
        menu_bar.append(menuList, "&List")
        set_menu_bar(menu_bar)

        # make a panel with some controls
        @m_panel = Panel.new(self, -1, Point.new(0, 0),
                              Size.new(400, 200), TAB_TRAVERSAL)

        CreateCheckListbox()

        # create buttons for moving the items around
        button1 = Button.new(@m_panel, Btn_Up, "   &Up  ", Point.new(420, 90))
        button2 = Button.new(@m_panel, Btn_Down, "&Down", Point.new(420, 120))


        mainsizer = BoxSizer.new( VERTICAL )

        mainsizer.add( @m_pListBox, 1, GROW|ALL, 10 )

        bottomsizer = BoxSizer.new( HORIZONTAL )

        bottomsizer.add( button1, 0, ALL, 10 )
        bottomsizer.add( button2, 0, ALL, 10 )

        mainsizer.add( bottomsizer, 0, CENTER )

        # tell frame to make use of sizer (or constraints, if any)
        @m_panel.set_auto_layout( TRUE )
        @m_panel.set_sizer( mainsizer )

        # don't allow frame to get smaller than what the sizers tell ye
        mainsizer.set_size_hints( self )

        show(TRUE)

        evt_menu(Menu_About) {onAbout}
        evt_menu(Menu_Quit) {onQuit}

        evt_menu(Menu_Selection) {|event| onToggleSelection(event)}

        evt_listbox(Control_Listbox) {|event| onListboxSelect(event)}
        evt_checklistbox(Control_Listbox) {|event| onCheckboxToggle(event)}
        evt_listbox_dclick(Control_Listbox) {onListboxDblClick}

        evt_button(Btn_Up) {onButtonUp}
        evt_button(Btn_Down) {onButtonDown}

    end

    def CreateCheckListbox(flags = 0)

        # check list box
        aszChoices = [
            "Zeroth",
            "First", "Second", "Third",
            "Fourth", "Fifth", "Sixth",
            "Seventh", "Eighth", "Nineth"]

        @m_pListBox = CheckListBox.new(
             @m_panel,              # parent
             Control_Listbox,       # control id
             Point.new(10, 10),   # listbox poistion
             Size.new(400, 100),  # listbox size
             aszChoices,            # array of strings
             flags
            )

        #@m_pListBox.SetBackgroundColour(GREEN)

        # set grey background for every second entry
        0.step(aszChoices.length-1,2) { |ui|
            adjust_colour(ui)
        }

        @m_pListBox.check(2)
        @m_pListBox.select(3)
    end

    def onQuit
        close(TRUE)
    end

    def onAbout
        message_box("Demo of CheckListBox control\n© Vadim Zeitlin 1998-2002",
                     "About CheckListBox",
                     ICON_INFORMATION, self)
    end

    def onToggleSelection(event)

        sizer = @m_panel.get_sizer()

        sizer.remove(@m_pListBox)
        @m_pListBox.free

        CreateCheckListbox(event.is_checked() ? LB_EXTENDED : 0)

        sizer.insert(0, @m_pListBox, 1, GROW | ALL, 10)

        @m_panel.layout()
    end

    def onListboxSelect(event)
        nSel = event.get_selection()
        log_status(self, "Item %d selected (%schecked)", nSel,
                          @m_pListBox.is_checked(nSel) ? "" : "not ")
    end

    def onListboxDblClick
        strSelection = sprintf("Item %d double clicked", @m_pListBox.get_selection())
        dialog = MessageDialog.new(self, strSelection, "CheckListBox message", ICON_INFORMATION)
        dialog.show_modal()
    end

    def onCheckboxToggle(event)
        nItem = event.get_int()
        log_status(self, "item %d was %schecked", nItem,
                          @m_pListBox.is_checked(nItem) ? "" : "un")
    end

    def onButtonUp
        OnButtonMove(TRUE)
    end

    def onButtonDown
        OnButtonMove(FALSE)
    end

    def OnButtonMove(up)
        selection = @m_pListBox.get_selection()
        if selection != -1
            label = @m_pListBox.get_string(selection)
            positionNew = up ? selection - 1 : selection + 2
            if positionNew < 0 || positionNew > @m_pListBox.get_count()
                log_status(self, "Can't move self item %s", up ? "up" : "down")
            else
                wasChecked = @m_pListBox.is_checked(selection)
                positionOld = up ? selection + 1 : selection

                # insert the item
                @m_pListBox.insert_items([label], positionNew)

                # and delete the old one
                @m_pListBox.delete(positionOld)

                selectionNew = up ? positionNew : positionNew - 1
                @m_pListBox.check(selectionNew, wasChecked)
                @m_pListBox.set_selection(selectionNew)

                adjust_colour(selection)
                adjust_colour(selectionNew)

                log_status(self, "Item moved %s", up ? "up" : "down")
            end
        else
            log_status(self, "Please select an item")
        end
    end

    def adjust_colour(index)
        # not implemented in ports other than (native) MSW yet
        if RUBY_PLATFORM == "WXMSW"
            # even items have grey backround, odd ones - white
            c = (index % 2)!=0 ? 255 : 200
            @m_pListBox.GetItem(index).SetBackgroundColour(Colour.new(c, c, c))
        end
    end
end


# init our app: create windows
class CheckListBoxApp < App
    def on_init()
        pFrame = CheckListBoxFrame.new(
                                     nil,
                                     "Windows Checklistbox Sample",
                                     50, 50, 480, 320
                                    )
        set_top_window(pFrame)
    end
end

a = CheckListBoxApp.new
a.main_loop()
