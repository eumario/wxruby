
require 'wxruby'
include Wx

# IDs for the menu commands
LIST_ABOUT,
LIST_QUIT,

LIST_LIST_VIEW,
LIST_ICON_VIEW,
LIST_ICON_TEXT_VIEW,
LIST_SMALL_ICON_VIEW,
LIST_SMALL_ICON_TEXT_VIEW,
LIST_REPORT_VIEW,
LIST_VIRTUAL_VIEW,

LIST_DESELECT_ALL,
LIST_SELECT_ALL,
LIST_DELETE_ALL,
LIST_DELETE,
LIST_ADD,
LIST_EDIT,
LIST_SORT,
LIST_SET_FG_COL,
LIST_SET_BG_COL,
LIST_TOGGLE_MULTI_SEL,
LIST_TOGGLE_FIRST,
LIST_SHOW_COL_INFO,
LIST_SHOW_SEL_INFO,
LIST_FOCUS_LAST,
LIST_FREEZE,
LIST_THAW = (0 .. 24).to_a

LIST_CTRL = 1000

# number of items in list/report view
NUM_ITEMS = 30

# number of items in icon/small icon view
NUM_ICONS = 9

class MyListCtrl < ListCtrl
    def initialize(parent,id,pos,size,style)
        super(parent, id, pos, size, style)
        @m_attr = ListItemAttr.new(BLUE, LIGHT_GREY, NULL_FONT)

    evt_list_begin_drag(LIST_CTRL) {|event| onBeginDrag(event) }
    evt_list_begin_rdrag(LIST_CTRL) {|event| onBeginRDrag(event) }
    evt_list_begin_label_edit(LIST_CTRL) {|event| onBeginLabelEdit(event) }
    evt_list_end_label_edit(LIST_CTRL) {|event| onEndLabelEdit(event) }
    evt_list_delete_item(LIST_CTRL) {|event| onDeleteItem(event) }
    evt_list_delete_all_items(LIST_CTRL) {|event| onDeleteAllItems(event) }
    evt_list_get_info(LIST_CTRL) {|event| onGetInfo(event) }
    evt_list_set_info(LIST_CTRL) {|event| onSetInfo(event) }
    evt_list_item_selected(LIST_CTRL) {|event| onSelected(event) }
    evt_list_item_deselected(LIST_CTRL) {|event| onDeselected(event) }
    evt_list_key_down(LIST_CTRL) {|event| onListKeyDown(event) }
    evt_list_item_activated(LIST_CTRL) {|event| onActivated(event) }
    evt_list_item_focused(LIST_CTRL) {|event| onFocused(event) }

    evt_list_col_click(LIST_CTRL) {|event| onColClick(event) }
    evt_list_col_right_click(LIST_CTRL) {|event| onColRightClick(event) }
    evt_list_col_begin_drag(LIST_CTRL) {|event| onColBeginDrag(event) }
    evt_list_col_dragging(LIST_CTRL) {|event| onColDragging(event) }
    evt_list_col_end_drag(LIST_CTRL) {|event| onColEndDrag(event) }

    evt_list_cache_hint(LIST_CTRL) {|event| onCacheHint(event) }

    evt_char {|event| onChar(event) }

    end

    def onCacheHint(event)
        log_message( "OnCacheHint: cache items %d..%d",
                      event.get_cache_from(), event.get_cache_to() )
    end

    def SetColumnImage(col,image)
        item = ListItem.new
        item.set_mask(LIST_MASK_IMAGE)
        item.set_image(image)
        set_column(col, item)
    end

    def onColClick(event)
        col = event.get_column()
        SetColumnImage(col, 0)

        log_message( "OnColumnClick at %d.", col )
    end

    def onColRightClick(event)
        col = event.get_column()
        if col != -1
            SetColumnImage(col, -1)
        end

        log_message( "OnColumnRightClick at %d.", event.get_column() )
    end

    def LogColEvent(event,name)
        col = event.get_column()

        log_message("%s: column %d (width = %d or %d).",
                     name,
                     col,
                     event.get_item().get_width(),
                     get_column_width(col))
    end

    def onColBeginDrag(event)
        LogColEvent( event, "OnColBeginDrag" )
    end

    def onColDragging(event)
        LogColEvent( event, "OnColDragging" )
    end

    def onColEndDrag(event)
        LogColEvent( event, "OnColEndDrag" )
    end

    def onBeginDrag(event)
        pt = event.get_point()
        i,flags = hit_test(pt)
        log_message( "OnBeginDrag at (%d, %d), item %d.",
                      pt.x, pt.y, i )
    end

    def onBeginRDrag(event)
        log_message( "OnBeginRDrag at %d,%d.",
                      event.get_point().x, event.get_point().y )
    end

    def onBeginLabelEdit(event)
        log_message( "OnBeginLabelEdit: %s", event.get_text())
    end

    def onEndLabelEdit(event)
        log_message( "OnEndLabelEdit: %s", event.get_text())
    end

    def onDeleteItem(event)
        LogEvent(event, "OnDeleteItem")
    end

    def onDeleteAllItems(event)
        LogEvent(event, "OnDeleteAllItems")
    end

    def onGetInfo(event)
        msg = ""
        msg << "OnGetInfo (" << event.get_item().get_id() << ", " << event.get_item().get_column() << ""
        if (event.GetMask() & LIST_MASK_STATE ) != 0
            msg << " LIST_MASK_STATE"
        end
        if ( event.GetMask() & LIST_MASK_TEXT ) != 0
            msg << " LIST_MASK_TEXT"
        end
        if ( event.GetMask() & LIST_MASK_IMAGE ) != 0
            msg << " LIST_MASK_IMAGE"
        end
        if ( event.GetMask() & LIST_MASK_DATA ) != 0
            msg << " LIST_MASK_DATA"
        end
        if ( event.GetMask() & LIST_SET_ITEM ) != 0
            msg << " LIST_SET_ITEM"
        end
        if ( event.GetMask() & LIST_MASK_WIDTH ) != 0
            msg << " LIST_MASK_WIDTH"
        end
        if ( event.GetMask() & LIST_MASK_FORMAT ) != 0
            msg << " LIST_MASK_WIDTH"
        end

        if ( event.GetMask() & LIST_MASK_TEXT ) != 0
            event.m_item.m_text = "My callback text"
        end

        log_message(msg)
    end

    def onSetInfo(event)
        LogEvent(event, "OnSetInfo")
    end

    def onSelected(event)
        LogEvent(event, "OnSelected")

        if ( get_window_style_flag() & LC_REPORT ) != 0
            info = ListItem.new
            info.set_id(event.get_index())
            info.set_column(1)
            info.set_mask(LIST_MASK_TEXT)
            if get_item(info)
                log_message("Value of the 2nd field of the selected item: %s",
                             info.get_text())
            else
                log_message("ListCtrl::get_item() failed")
            end
            info.free
        end
    end

    def onDeselected(event)
        LogEvent(event, "OnDeselected")
    end

    def onActivated(event)
        LogEvent(event, "OnActivated")
    end

    def onFocused(event)
        LogEvent(event, "OnFocused")

        event.skip()
    end

    def onListKeyDown(event)
        case event.get_key_code()
            when ?c,?C
                    info = ListItem.new
                    info.set_id(event.get_index())
                    get_item(info)

                    attr = info.get_attributes()
                    if !attr || !attr.has_text_colour()
                        info.set_text_colour(CYAN)

                        set_item(info)

                        refresh_item(info.get_id())
                    end
                    info.free
            when ?n,?N
                    item = get_next_item(-1,
                                            LIST_NEXT_ALL, LIST_STATE_FOCUSED)
                    if item == get_item_count() - 1
                        item = 0
                    else
                        item += 1
                    end

                    log_message("Focusing item %d", item)

                    set_item_state(item, LIST_STATE_FOCUSED, LIST_STATE_FOCUSED)
                    ensure_visible(item)

            when K_DELETE
                    item = get_next_item(-1,
                                            LIST_NEXT_ALL, LIST_STATE_SELECTED)
                    while item != -1
                        delete_item(item)

                        log_message("Item %d deleted", item)

                        # -1 because the indices were shifted by delete_item()
                        item = get_next_item(item - 1,
                                           LIST_NEXT_ALL, LIST_STATE_SELECTED)
                    end
            when K_INSERT
                if ( get_window_style_flag() & LC_REPORT ) != 0
                    if ( get_window_style_flag() & LC_VIRTUAL ) != 0
                        set_item_count(get_item_count() + 1)
                    else # !virtual
                        insert_item_in_report_view(event.get_index())
                    end
                end
            else
                LogEvent(event, "OnListKeyDown")
                event.skip()
        end
    end

    def onChar(event)
        log_message("Got char event.")

        case event.get_key_code()
            when ?n,?N,?c,?C
                ;
            else
                event.skip()
        end
    end

    def LogEvent(event,eventName)
        log_message("Item %d: %s (item text = %s, data = %d)",
                     event.get_index(), eventName,
                     event.get_text(), event.get_data())
    end

    def OnGetItemText(item,column)
        return sprintf("Column %d of item %d", column, item)
    end

    def OnGetItemImage(item)
        return 0
    end

    def OnGetItemAttr(item)
        return ((item % 2) != 0 ? nil : @m_attr)
    end

    def insert_item_in_report_view(i)
        buf = sprintf("This is item %d", i)
        tmp = insert_item(i, buf, 0)
        set_item_data(tmp, i)

        buf = sprintf("Col 1, item %d", i)
        set_item(i, 1, buf)

        buf = sprintf("Item %d in column 2", i)
        set_item(i, 2, buf)
    end

end


# Define a new frame type
class MyFrame < Frame

    def initialize(title, x, y, w, h)
        super(nil, -1, title, Point.new(x, y), Size.new(w, h))

        @m_listCtrl = nil
        @m_logWindow = nil

        # Give it an icon
        set_icon( Icon.new("mondrian.xpm") )

        # Make an image list containing large icons
        @m_imageListNormal = ImageList.new(32, 32, TRUE)
        @m_imageListSmall = ImageList.new(16, 16, TRUE)

        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolbrai.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolchar.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/tooldata.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolnote.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/tooltodo.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolchec.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolgame.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/tooltime.xpm" ) )
        @m_imageListNormal.add( Bitmap.new( "bitmaps/toolword.xpm" ) )

        @m_imageListSmall.add( Bitmap.new( "bitmaps/small1.xpm") )

        # Make a menubar
        menuFile = Menu.new
        menuFile.append(LIST_ABOUT, "&About")
        menuFile.append_separator()
        menuFile.append(LIST_QUIT, "E&xit\tAlt-X")

        menuView = Menu.new
        menuView.append(LIST_LIST_VIEW, "&List view\tF1")
        menuView.append(LIST_REPORT_VIEW, "&Report view\tF2")
        menuView.append(LIST_ICON_VIEW, "&Icon view\tF3")
        menuView.append(LIST_ICON_TEXT_VIEW, "Icon view with &text\tF4")
        menuView.append(LIST_SMALL_ICON_VIEW, "&Small icon view\tF5")
        menuView.append(LIST_SMALL_ICON_TEXT_VIEW, "Small icon &view with text\tF6")
        menuView.append(LIST_VIRTUAL_VIEW, "Virtual view\tF7")

        menuList = Menu.new
        menuList.append(LIST_FOCUS_LAST, "&Make last item current\tCtrl-L")
        menuList.append(LIST_TOGGLE_FIRST, "To&ggle first item\tCtrl-G")
        menuList.append(LIST_DESELECT_ALL, "&Deselect All\tCtrl-D")
        menuList.append(LIST_SELECT_ALL, "S&elect All\tCtrl-A")
        menuList.append_separator()
        menuList.append(LIST_SHOW_COL_INFO, "show &column info\tCtrl-C")
        menuList.append(LIST_SHOW_SEL_INFO, "show &selected items\tCtrl-S")
        menuList.append_separator()
        menuList.append(LIST_SORT, "&Sort\tCtrl-S")
        menuList.append_separator()
        menuList.append(LIST_ADD, "&append an item\tCtrl-P")
        menuList.append(LIST_EDIT, "&Edit the item\tCtrl-E")
        menuList.append(LIST_DELETE, "&Delete first item\tCtrl-X")
        menuList.append(LIST_DELETE_ALL, "Delete &all items")
        menuList.append_separator()
        menuList.append(LIST_FREEZE, "Free&ze\tCtrl-Z")
        menuList.append(LIST_THAW, "Tha&w\tCtrl-W")
        menuList.append_separator()
        menuList.append(LIST_TOGGLE_MULTI_SEL, "&Multiple selection\tCtrl-M",
                "Toggle multiple selection", ITEM_CHECK)

        menuCol = Menu.new
        menuCol.append(LIST_SET_FG_COL, "&Foreground colour...")
        menuCol.append(LIST_SET_BG_COL, "&Background colour...")

        menubar = MenuBar.new
        menubar.append(menuFile, "&File")
        menubar.append(menuView, "&View")
        menubar.append(menuList, "&List")
        menubar.append(menuCol, "&Colour")
        set_menu_bar(menubar)

        @m_panel = Panel.new(self, -1)
        @m_logWindow = TextCtrl.new(@m_panel, -1, "",
                                     DEFAULT_POSITION, DEFAULT_SIZE,
                                     TE_MULTILINE | SUNKEN_BORDER)

        @m_logOld = Log::set_active_target(LogTextCtrl.new(@m_logWindow))

        RecreateList(LC_REPORT | LC_SINGLE_SEL)

        create_status_bar(3)

        evt_size() {|event| onSize(event) }

        evt_menu(LIST_QUIT) {|event| onQuit(event) }
        evt_menu(LIST_ABOUT) {|event| onAbout(event) }
        evt_menu(LIST_LIST_VIEW) {|event| onListView(event) }
        evt_menu(LIST_REPORT_VIEW) {|event| onReportView(event) }
        evt_menu(LIST_ICON_VIEW) {|event| onIconView(event) }
        evt_menu(LIST_ICON_TEXT_VIEW) {|event| onIconTextView(event) }
        evt_menu(LIST_SMALL_ICON_VIEW) {|event| onSmallIconView(event) }
        evt_menu(LIST_SMALL_ICON_TEXT_VIEW) {|event| onSmallIconTextView(event) }
        evt_menu(LIST_VIRTUAL_VIEW) {|event| onVirtualView(event) }

        evt_menu(LIST_FOCUS_LAST) {|event| onFocusLast(event) }
        evt_menu(LIST_TOGGLE_FIRST) {|event| onToggleFirstSel(event) }
        evt_menu(LIST_DESELECT_ALL) {|event| onDeselectAll(event) }
        evt_menu(LIST_SELECT_ALL) {|event| onSelectAll(event) }
        evt_menu(LIST_DELETE) {|event| onDelete(event) }
        evt_menu(LIST_ADD) {|event| onAdd(event) }
        evt_menu(LIST_EDIT) {|event| onEdit(event) }
        evt_menu(LIST_DELETE_ALL) {|event| onDeleteAll(event) }
        evt_menu(LIST_SORT) {|event| onSort(event) }
        evt_menu(LIST_SET_FG_COL) {|event| onSetFgColour(event) }
        evt_menu(LIST_SET_BG_COL) {|event| onSetBgColour(event) }
        evt_menu(LIST_TOGGLE_MULTI_SEL) {|event| onToggleMultiSel(event) }
        evt_menu(LIST_SHOW_COL_INFO) {|event| onShowColInfo(event) }
        evt_menu(LIST_SHOW_SEL_INFO) {|event| onShowSelInfo(event) }
        evt_menu(LIST_FREEZE) {|event| onFreeze(event) }
        evt_menu(LIST_THAW) {|event| onThaw(event) }

        evt_update_ui(LIST_SHOW_COL_INFO) {|event| onUpdateShowColInfo(event) }

	evt_close() {|event| onClose(event) }

    end

    def onSize(event=nil)
        if !@m_logWindow
            return Qnil
        end

        size = get_client_size()
        y = (2*size.y)/3
        @m_listCtrl.set_size_xy(size.x, y)
        @m_logWindow.set_dimensions(0, y + 1, size.x, size.y - y)

        event.skip() if event
    end

    def onClose(event)
    	Log::set_active_target(@m_logOld)
        destroy()
    end

    def onQuit(event)
        close(TRUE)
    end

    def onAbout(event)
        dialog = MessageDialog.new(self, "List test sample\nJulian Smart (c) 1997",
                "About list test", OK|CANCEL)

        dialog.show_modal()
    end

    def onFreeze(event)
        log_message("Freezing the control")
        @m_listCtrl.freeze()
    end

    def onThaw(event)
        log_message("Thawing the control")

        @m_listCtrl.thaw()
    end

    def onFocusLast(event)
        index = @m_listCtrl.get_item_count() - 1
        if index == -1
            return Qnil
        end

        @m_listCtrl.set_item_state(index, LIST_STATE_FOCUSED, LIST_STATE_FOCUSED)
        @m_listCtrl.ensure_visible(index)
    end

    def onToggleFirstSel(event)
        @m_listCtrl.set_item_state(0, LIST_STATE_SELECTED, LIST_STATE_SELECTED)
    end

    def onDeselectAll(event)
        n = @m_listCtrl.get_item_count()
        for i in 0 ... n
            @m_listCtrl.set_item_state(i,0,LIST_STATE_SELECTED)
        end
    end

    def onSelectAll(event)
        n = @m_listCtrl.get_item_count()
        for i in 0 ... n
            @m_listCtrl.set_item_state(i,LIST_STATE_SELECTED, LIST_STATE_SELECTED)
        end
    end

    # ----------------------------------------------------------------------------
    # changing listctrl modes
    # ----------------------------------------------------------------------------

    def RecreateList(flags,withText = TRUE)

        # we could avoid recreating it if we don't set/clear the LC_VIRTUAL
        # style, but it is more trouble to do it than not

        @m_listCtrl.free if @m_listCtrl

        @m_listCtrl = MyListCtrl.new(@m_panel, LIST_CTRL,
                                    DEFAULT_POSITION, DEFAULT_SIZE,
                                    flags |
                                    SUNKEN_BORDER | LC_EDIT_LABELS)

        case flags & LC_MASK_TYPE
            when LC_LIST
                InitWithListItems()
            when LC_ICON
                InitWithIconItems(withText)
            when LC_SMALL_ICON
                InitWithIconItems(withText, TRUE)
            when LC_REPORT
                if (flags & LC_VIRTUAL) != 0
                    InitWithVirtualItems()
                else
                    InitWithReportItems()
                end
            else
                log_message( "unknown listctrl mode" )
        end

        onSize(nil)

        @m_logWindow.clear()
    end

    def onListView(event)
        RecreateList(LC_LIST)
    end

    def InitWithListItems()
        for i in 0 ... NUM_ITEMS
            @m_listCtrl.insert_item(i, sprintf("Item %d", i))
        end
    end

    def onReportView(event)
        RecreateList(LC_REPORT)
    end

    def InitWithReportItems()
        @m_listCtrl.set_image_list(@m_imageListSmall, IMAGE_LIST_SMALL)

        # under MSW for set_column_width() to work we need to create the items with
        # images initially
        itemCol = ListItem.new
        itemCol.set_mask(LIST_MASK_TEXT | LIST_MASK_IMAGE)
        itemCol.set_text("Column 1")
        itemCol.set_image(-1)
        @m_listCtrl.insert_column(0, itemCol)
        itemCol.set_text("Column 2")
        @m_listCtrl.insert_column(1, itemCol)
        itemCol.set_text("Column 3")
        @m_listCtrl.insert_column(2, itemCol)

#        m_listCtrl.insert_column(0, "Column 1") # , LIST_FORMAT_LEFT, 140)
#        m_listCtrl.insert_column(1, "Column 2") # , LIST_FORMAT_LEFT, 140)
#        m_listCtrl.insert_column(2, "One More Column (2)") # , LIST_FORMAT_LEFT, 140)

        # to speed up inserting we hide the control temporarily
        @m_listCtrl.hide()

        sw = StopWatch.new

        for i in 0 ... NUM_ITEMS
            @m_listCtrl.insert_item_in_report_view(i)
        end

        @m_logWindow.write_text(sprintf("%d items inserted in %dms\n",
                                                NUM_ITEMS, sw.time()))
        sw.free
        @m_listCtrl.show()

        # we leave all mask fields to 0 and only change the colour
        item = ListItem.new
        item.set_id(0)
        item.set_text_colour(RED)
        @m_listCtrl.set_item( item )

        item.set_id(2)
        item.set_text_colour(GREEN)
        @m_listCtrl.set_item( item )
        item.set_id(4)
        item.set_text_colour(LIGHT_GREY)
        item.set_font(ITALIC_FONT)
        item.set_background_colour(RED)
        @m_listCtrl.set_item( item )

        @m_listCtrl.set_text_colour(BLUE)
        @m_listCtrl.set_background_colour(LIGHT_GREY)

        @m_listCtrl.set_column_width( 0, LIST_AUTOSIZE )
        @m_listCtrl.set_column_width( 1, LIST_AUTOSIZE )
        @m_listCtrl.set_column_width( 2, LIST_AUTOSIZE )
    end

    def InitWithIconItems(withText,sameIcon = FALSE)
        @m_listCtrl.set_image_list(@m_imageListNormal, IMAGE_LIST_NORMAL)
        @m_listCtrl.set_image_list(@m_imageListSmall, IMAGE_LIST_SMALL)

        for i in 0 ... NUM_ICONS
            image = sameIcon ? 0 : i

            if withText
                @m_listCtrl.insert_item(i, sprintf("Label %d", i),
                                       image)
            else
                @m_listCtrl.insert_item(i, image)
            end
        end
    end

    def onIconView(event)
        RecreateList(LC_ICON, FALSE)
    end

    def onIconTextView(event)
        RecreateList(LC_ICON)
    end

    def onSmallIconView(event)
        RecreateList(LC_SMALL_ICON, FALSE)
    end

    def onSmallIconTextView(event)
        RecreateList(LC_SMALL_ICON)
    end

    def onVirtualView(event)
        RecreateList(LC_REPORT | LC_VIRTUAL)
    end

    def InitWithVirtualItems()
        @m_listCtrl.set_image_list(@m_imageListSmall, IMAGE_LIST_SMALL)

        @m_listCtrl.insert_column(0, "First Column")
        @m_listCtrl.insert_column(1, "Second Column")
        @m_listCtrl.set_column_width(0, 150)
        @m_listCtrl.set_column_width(1, 150)

        @m_listCtrl.set_item_count(1000000)
    end

    def MyCompareFunction(item1,item2)

        # inverse the order
        return -1 if item1 < item2
        return 1 if item1 > item2
        return 0
    end

    def onSort(event)
        sw = StopWatch.new
        @m_listCtrl.sort_items(self,"MyCompareFunction")

        @m_logWindow.write_text(sprintf("Sorting %d items took %d ms\n",
                                                @m_listCtrl.get_item_count(),
                                                sw.time()))
        sw.free
    end

    def onShowSelInfo(event)
        selCount = @m_listCtrl.get_selected_item_count()
        log_message("%d items selected:", selCount)

        # don't show too many items
        shownCount = 0

        item = @m_listCtrl.get_next_item(-1, LIST_NEXT_ALL,
                                            LIST_STATE_SELECTED)
        while item != -1
            log_message("\t%d (%s)",
                         item, @m_listCtrl.get_item_text(item))

            shownCount += 1
            if shownCount > 10
                log_message("\t... more selected items snipped...")
                break
            end

            item = @m_listCtrl.get_next_item(item, LIST_NEXT_ALL,
                                           LIST_STATE_SELECTED)
        end
    end

    def onShowColInfo(event)
        count = @m_listCtrl.get_column_count()
        log_message("%d columns:", count)
        for c in 0 ... count
            log_message("\tcolumn %d has width %d", c,
                         @m_listCtrl.get_column_width(c))
        end
    end

    def onUpdateShowColInfo(event)
        event.enable( (@m_listCtrl.get_window_style_flag() & LC_REPORT) != 0 )
    end

    def onToggleMultiSel(event)
        flags = @m_listCtrl.get_window_style_flag()
        if (flags & LC_SINGLE_SEL) != 0
            flags &= ~LC_SINGLE_SEL
        else
            flags |= LC_SINGLE_SEL
        end

        @m_logWindow.write_text(sprintf("Current selection mode: %sle\n",
                               (flags & LC_SINGLE_SEL) != 0 ? "sing" : "multip"))

        RecreateList(flags)
    end

    def onSetFgColour(event)
        @m_listCtrl.set_foreground_colour(get_colour_from_user(self))
        @m_listCtrl.refresh()
    end

    def onSetBgColour(event)
        @m_listCtrl.set_background_colour(get_colour_from_user(self))
        @m_listCtrl.refresh()
    end

    def onAdd(event)
        @m_listCtrl.insert_item(@m_listCtrl.get_item_count(), "Appended item")
    end

    def onEdit(event)
        itemCur = @m_listCtrl.get_next_item(-1, LIST_NEXT_ALL,
                                               LIST_STATE_FOCUSED)

        if itemCur != -1
            @m_listCtrl.edit_label(itemCur)
        else
            @m_logWindow.write_text("No item to edit")
        end
    end

    def onDelete(event)
        if @m_listCtrl.get_item_count() != 0
            @m_listCtrl.delete_item(0)
        else
            @m_logWindow.write_text("Nothing to delete")
        end
    end

    def onDeleteAll(event)
        sw = StopWatch.new

        @m_listCtrl.delete_all_items()

        @m_logWindow.write_text(sprintf("Deleting %d items took %d ms\n",
                                                @m_listCtrl.get_item_count(),
                                                sw.time()))
        sw.free
    end

end


class MyApp < App
    def on_init
        # Create the main frame window
        frame = MyFrame.new("ListCtrl Test", 50, 50, 450, 340)

        # show the frame
        frame.show(TRUE)

        set_top_window(frame)

    end
end


a = MyApp.new
a.main_loop()
