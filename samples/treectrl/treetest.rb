
require 'wxruby'
include Wx

TreeTest_Quit,
TreeTest_About,
TreeTest_TogButtons,
TreeTest_TogTwist,
TreeTest_TogLines,
TreeTest_TogEdit,
TreeTest_TogHideRoot,
TreeTest_TogRootLines,
TreeTest_TogBorder,
TreeTest_TogFullHighlight,
TreeTest_SetFgColour,
TreeTest_SetBgColour,
TreeTest_ResetStyle,
TreeTest_Dump,
TreeTest_DumpSelected,
TreeTest_Count,
TreeTest_CountRec,
TreeTest_Sort,
TreeTest_SortRev,
TreeTest_SetBold,
TreeTest_ClearBold,
TreeTest_Rename,
TreeTest_Delete,
TreeTest_DeleteChildren,
TreeTest_DeleteAll,
TreeTest_Recreate,
TreeTest_ToggleImages,
TreeTest_ToggleButtons,
TreeTest_SetImageSize,
TreeTest_ToggleSel,
TreeTest_CollapseAndReset,
TreeTest_EnsureVisible,
TreeTest_AddItem,
TreeTest_InsertItem,
TreeTest_IncIndent,
TreeTest_DecIndent,
TreeTest_IncSpacing,
TreeTest_DecSpacing,
TreeTest_ToggleIcon,
TreeTest_Select,
TreeTest_Unselect = (0..41).to_a
TreeTest_Ctrl = 1000

TreeCtrlIcon_File,
TreeCtrlIcon_FileSelected,
TreeCtrlIcon_Folder,
TreeCtrlIcon_FolderSelected,
TreeCtrlIcon_FolderOpened = 0,1,2,3,4

class MyTreeItemData < TreeItemData
    def initialize(desc)
        super()
        @m_desc = desc
    end

    def Bool2String(b)
        return b ? "" : "not "
    end

    def show_info(tree)
        log_message("Item '%s': %sselected, %sexpanded, %sbold,\n" +
                     "%d children (%d immediately under self item).",
                     @m_desc,
                     Bool2String(tree.is_selected(get_id())),
                     Bool2String(tree.is_expanded(get_id())),
                     Bool2String(tree.is_bold(get_id())),
                     tree.get_children_count(get_id()),
                     tree.get_children_count(get_id(), FALSE))
    end

    def GetDesc()
        @m_desc
    end

end

class MyTreeCtrl < TreeCtrl
    def initialize(parent, id,pos, size,style)
        super(parent, id, pos, size, style)

        @m_reverseSort = FALSE

        create_image_list()

        # add some items to the tree
        AddTestItemsToTree(5, 2)

        evt_tree_begin_drag(TreeTest_Ctrl) {|event| onBeginDrag(event) }
        evt_tree_begin_rdrag(TreeTest_Ctrl) {|event| onBeginRDrag(event) }
        evt_tree_end_drag(TreeTest_Ctrl) {|event| onEndDrag(event) }
        evt_tree_begin_label_edit(TreeTest_Ctrl) {|event| onBeginLabelEdit(event) }
        evt_tree_end_label_edit(TreeTest_Ctrl) {|event| onEndLabelEdit(event) }
        evt_tree_delete_item(TreeTest_Ctrl) {|event| onDeleteItem(event) }
        evt_tree_set_info(TreeTest_Ctrl) {|event| onSetInfo(event) }
        evt_tree_item_expanded(TreeTest_Ctrl) {|event| onItemExpanded(event) }
        evt_tree_item_expanding(TreeTest_Ctrl) {|event| onItemExpanding(event) }
        evt_tree_item_collapsed(TreeTest_Ctrl) {|event| onItemCollapsed(event) }
        evt_tree_item_collapsing(TreeTest_Ctrl) {|event| onItemCollapsing(event) }
        evt_tree_item_right_click(TreeTest_Ctrl) {|event| onItemRightClick(event) }

        evt_right_up {|event| onRMouseUp(event) }
        evt_tree_sel_changed(TreeTest_Ctrl) {|event| onSelChanged(event) }
        evt_tree_sel_changing(TreeTest_Ctrl) {|event| onSelChanging(event) }
        evt_tree_key_down(TreeTest_Ctrl) {|event| onTreeKeyDown(event) }
        evt_tree_item_activated(TreeTest_Ctrl) {|event| onItemActivated(event) }
        evt_right_dclick {|event| RMouseDClick(event) }

    end

    def DoSortChildren(item,reverse = FALSE)
         @m_reverseSort = reverse
         sort_children(item)
    end

    def do_ensure_visible()
        ensure_visible(@m_lastItem)
    end

    def ImageSize()
        return @m_imageSize
    end

    def is_test_item(item)
        # the test item is the first child folder
        return get_item_parent(item) == get_root_item() && !get_prev_sibling(item)
    end

    def create_image_list(size = 16)
        if size == -1
            set_image_list(nil)
            return nil
        end
        if size == 0
            size = @m_imageSize
        else
            @m_imageSize = size
        end

        # Make an image list containing small icons
        images = ImageList.new(size, size, TRUE)

        # should correspond to TreeCtrlIcon_xxx enum
        wait = BusyCursor.new
        icons = [
            Icon.new("icon1.xpm"),
            Icon.new("icon2.xpm"),
            Icon.new("icon3.xpm"),
            Icon.new("icon4.xpm"),
            Icon.new("icon5.xpm")]

        sizeOrig = icons[0].get_width()
        for i in 0 ... icons.length
            if size == sizeOrig
                images.add(icons[i])
            else
                images.add(icons[i])
            end
        end

        assign_image_list(images)
        wait.free
    end

    def CreateButtonsImageList(size = 11)
        if size == -1
            SetButtonsImageList(nil)
            return nil
        end

        # Make an image list containing small icons
        images = ImageList.new(size, size, TRUE)

        # should correspond to TreeCtrlIcon_xxx enum
        wait = BusyCursor.new
        icons = [
            Icon.new("icon3.xpm"),   # closed
            Icon.new("icon3.xpm"),   # closed, selected
            Icon.new("icon5.xpm"),   # open
            Icon.new("icon5.xpm")]   # open, selected

        for i in 0 ... icons.length
            sizeOrig = icons[i].get_width()
            if size == sizeOrig
                images.add(icons[i])
            else
                images.add(Bitmap.new(icons[i].ConvertToImage().Rescale(size, size)))
            end
        end

        AssignButtonsImageList(images)
        wait.free
    end

    def on_compare_items(item1,item2)
        if @m_reverseSort
            # just exchange 1st and 2nd items
            return super(item2, item1)
        else
            return super(item1, item2)
        end
    end

    def AddItemsRecursively(idParent,numChildren,depth,folder)
        if depth > 0
            hasChildren = depth > 1

            for n in 0 ... numChildren
                # at depth 1 elements won't have any more children
                if hasChildren
                    str = sprintf("%s child %d", "Folder", n + 1)
                else
                    str = sprintf("%s child %d.%d", "File", folder, n + 1)
                end
                # here we pass to append_item() normal and selected item images (we
                # suppose that selected image follows the normal one in the enum)
                if get_app().show_images()
                    image = depth == 1 ? TreeCtrlIcon_File : TreeCtrlIcon_Folder
                    imageSel = image + 1
                else
                    image = imageSel = -1
                end
                id = append_item(idParent, str, image, imageSel,MyTreeItemData.new(str))

                # and now we also set the expanded one (only for the folders)
                if hasChildren && get_app().show_images()
                    set_item_image(id, TreeCtrlIcon_FolderOpened,
                                 TREE_ITEM_ICON_EXPANDED)
                end

                # remember the last child for OnEnsureVisible()
                if !hasChildren && n == numChildren - 1
                    @m_lastItem = id
                end

                AddItemsRecursively(id, numChildren, depth - 1, n + 1)
            end
        end
    end

    def AddTestItemsToTree(numChildren,depth)
        image = get_app().show_images() ? TreeCtrlIcon_Folder : -1
        rootId = add_root("Root",image, image,MyTreeItemData.new("Root item"))
        if image != -1
            set_item_image(rootId, TreeCtrlIcon_FolderOpened, TREE_ITEM_ICON_EXPANDED)
        end

        AddItemsRecursively(rootId, numChildren, depth, 0)

        # set some colours/fonts for testing
        set_item_font(rootId, ITALIC_FONT)

        id,cookie = get_first_child(rootId)
        set_item_text_colour(id, BLUE)

        id,cookie = get_next_child(rootId,cookie)
        id,cookie = get_next_child(rootId,cookie)
        set_item_text_colour(id, RED)
        set_item_background_colour(id, LIGHT_GREY)
    end

    def get_items_recursively(idParent,cookie)
        if cookie == -1
            id,cookie = get_first_child(idParent)
        else
            id,cookie = get_next_child(idParent,cookie)
        end
        if id <= 0
            return nil
        end

        text = get_item_text(id)
        log_message(text)

        if item_has_children(id)
            get_items_recursively(id,-1)
        end
        get_items_recursively(idParent, cookie)
    end

    def do_toggle_icon(item)
        image = get_item_image(item) == TreeCtrlIcon_Folder ? TreeCtrlIcon_File : TreeCtrlIcon_Folder

        set_item_image(item, image)
    end

    def onBeginRDrag(event)
        log_message("OnBeginRDrag")
        event.skip()
    end

    def onDeleteItem(event)
        log_message("OnDeleteItem")
        event.skip()
    end

    def onGetInfo(event)
        log_message("OnGetInfo")
        event.skip()
    end

    def onSetInfo(event)
        log_message("OnSetInfo")
        event.skip()
    end

    def onItemExpanded(event)
        log_message("OnItemExpanded")
        event.skip()
    end

    def onItemExpanding(event)
        log_message("OnItemExpanding")
        event.skip()
    end

    def onItemCollapsed(event)
        log_message("OnItemCollapsed")
        event.skip()
    end

    def onSelChanged(event)
        log_message("OnSelChanged")
        event.skip()
    end

    def onSelChanging(event)
        log_message("OnSelChanging")
        event.skip()
    end

    def LogKeyEvent(name,event)
        keycode = event.get_key_code()

        case keycode
            when K_BACK
                key = "BACK"
            when K_TAB
                key = "TAB"
            when K_RETURN
                key = "RETURN"
            when K_ESCAPE
                key = "ESCAPE"
            when K_SPACE
                key = "SPACE"
            when K_DELETE
                key = "DELETE"
            when K_START
                key = "START"
            when K_LBUTTON
                key = "LBUTTON"
            when K_RBUTTON
                key = "RBUTTON"
            when K_CANCEL
                key = "CANCEL"
            when K_MBUTTON
                key = "MBUTTON"
            when K_CLEAR
                key = "CLEAR"
            when K_SHIFT
                key = "SHIFT"
            when K_ALT
                key = "ALT"
            when K_CONTROL
                key = "CONTROL"
            when K_MENU
                key = "MENU"
            when K_PAUSE
                key = "PAUSE"
            when K_CAPITAL
                key = "CAPITAL"
            when K_PRIOR
                key = "PRIOR"
            when K_NEXT
                key = "NEXT"
            when K_END
                key = "END"
            when K_HOME
                key = "HOME"
            when K_LEFT
                key = "LEFT"
            when K_UP
                key = "UP"
            when K_RIGHT
                key = "RIGHT"
            when K_DOWN
                key = "DOWN"
            when K_SELECT
                key = "SELECT"
            when K_PRINT
                key = "PRINT"
            when K_EXECUTE
                key = "EXECUTE"
            when K_SNAPSHOT
                key = "SNAPSHOT"
            when K_INSERT
                key = "INSERT"
            when K_HELP
                key = "HELP"
            when K_NUMPAD0
                key = "NUMPAD0"
            when K_NUMPAD1
                key = "NUMPAD1"
            when K_NUMPAD2
                key = "NUMPAD2"
            when K_NUMPAD3
                key = "NUMPAD3"
            when K_NUMPAD4
                key = "NUMPAD4"
            when K_NUMPAD5
                key = "NUMPAD5"
            when K_NUMPAD6
                key = "NUMPAD6"
            when K_NUMPAD7
                key = "NUMPAD7"
            when K_NUMPAD8
                key = "NUMPAD8"
            when K_NUMPAD9
                key = "NUMPAD9"
            when K_MULTIPLY
                key = "MULTIPLY"
            when K_ADD
                key = "ADD"
            when K_SEPARATOR
                key = "SEPARATOR"
            when K_SUBTRACT
                key = "SUBTRACT"
            when K_DECIMAL
                key = "DECIMAL"
            when K_DIVIDE
                key = "DIVIDE"
            when K_F1
                key = "F1"
            when K_F2
                key = "F2"
            when K_F3
                key = "F3"
            when K_F4
                key = "F4"
            when K_F5
                key = "F5"
            when K_F6
                key = "F6"
            when K_F7
                key = "F7"
            when K_F8
                key = "F8"
            when K_F9
                key = "F9"
            when K_F10
                key = "F10"
            when K_F11
                key = "F11"
            when K_F12
                key = "F12"
            when K_F13
                key = "F13"
            when K_F14
                key = "F14"
            when K_F15
                key = "F15"
            when K_F16
                key = "F16"
            when K_F17
                key = "F17"
            when K_F18
                key = "F18"
            when K_F19
                key = "F19"
            when K_F20
                key = "F20"
            when K_F21
                key = "F21"
            when K_F22
                key = "F22"
            when K_F23
                key = "F23"
            when K_F24
                key = "F24"
            when K_NUMLOCK
                key = "NUMLOCK"
            when K_SCROLL
                key = "SCROLL"
            when K_PAGEUP
                key = "PAGEUP"
            when K_PAGEDOWN
                key = "PAGEDOWN"
            when K_NUMPAD_SPACE
                key = "NUMPAD_SPACE"
            when K_NUMPAD_TAB
                key = "NUMPAD_TAB"
            when K_NUMPAD_ENTER
                key = "NUMPAD_ENTER"
            when K_NUMPAD_F1
                key = "NUMPAD_F1"
            when K_NUMPAD_F2
                key = "NUMPAD_F2"
            when K_NUMPAD_F3
                key = "NUMPAD_F3"
            when K_NUMPAD_F4
                key = "NUMPAD_F4"
            when K_NUMPAD_HOME
                key = "NUMPAD_HOME"
            when K_NUMPAD_LEFT
                key = "NUMPAD_LEFT"
            when K_NUMPAD_UP
                key = "NUMPAD_UP"
            when K_NUMPAD_RIGHT
                key = "NUMPAD_RIGHT"
            when K_NUMPAD_DOWN
                key = "NUMPAD_DOWN"
            when K_NUMPAD_PRIOR
                key = "NUMPAD_PRIOR"
            when K_NUMPAD_PAGEUP
                key = "NUMPAD_PAGEUP"
            when K_NUMPAD_PAGEDOWN
                key = "NUMPAD_PAGEDOWN"
            when K_NUMPAD_END
                key = "NUMPAD_END"
            when K_NUMPAD_BEGIN
                key = "NUMPAD_BEGIN"
            when K_NUMPAD_INSERT
                key = "NUMPAD_INSERT"
            when K_NUMPAD_DELETE
                key = "NUMPAD_DELETE"
            when K_NUMPAD_EQUAL
                key = "NUMPAD_EQUAL"
            when K_NUMPAD_MULTIPLY
                key = "NUMPAD_MULTIPLY"
            when K_NUMPAD_ADD
                key = "NUMPAD_ADD"
            when K_NUMPAD_SEPARATOR
                key = "NUMPAD_SEPARATOR"
            when K_NUMPAD_SUBTRACT
                key = "NUMPAD_SUBTRACT"
            when K_NUMPAD_DECIMAL
                key = "NUMPAD_DECIMAL"
            else
                   if keycode >= 32 && keycode <127
                       key = sprintf("'%s'", keycode.chr)
                   elsif keycode > 0 && keycode < 27
                       key = sprintf("Ctrl-%c", ?A + keycode - 1)
                   else
                       key = sprintf("unknown (%d)", keycode)
                   end
        end

        log_message( "%s event: %s (flags = %s%s%s%s)",
                      name,
                      key,
                      event.control_down() ? 'C' : '-',
                      event.alt_down() ? 'A' : '-',
                      event.shift_down() ? 'S' : '-',
                      event.meta_down() ? 'M' : '-')
    end

    def onTreeKeyDown(event)
        LogKeyEvent("Tree key down ", event.get_key_event())

        event.skip()
    end

    def onBeginDrag(event)
        # need to explicitly allow drag
        if event.get_item() != get_root_item()

            @m_draggedItem = event.get_item()

            log_message("OnBeginDrag: started dragging %s",
                         get_item_text(@m_draggedItem))

            event.allow()
        else
            log_message("OnBeginDrag: self item can't be dragged.")
        end
    end

    def onEndDrag(event)

### NOT SUPPORTED YET
return nil
        itemSrc = @m_draggedItem
        itemDstId = event.get_item()
		itemDst = get_item_data(itemDstId)
        @m_draggedItem = 0

        # where to copy the item?
        if itemDstId.is_ok() && !item_has_children(itemDst)
            # copy to the parent then
            itemDst = get_item_parent(itemDstId)
        end

        if !itemDstId.is_ok()
            log_message("OnEndDrag: can't drop here.")

            return nil
        end

        text = get_item_text(itemSrc)
        log_message("OnEndDrag: '%s' copied to '%s'.",
                     text, get_item_text(itemDst))

        # just do append here - we could also insert it just before/after the item
        # on which it was dropped, but self requires slightly more work... we also
        # completely ignore the client data and icon of the old item but could
        # copy them as well.
        #
        # Finally, we only copy one item here but we might copy the entire tree if
        # we were dragging a folder.
        image = get_app().show_images() ? TreeCtrlIcon_File : -1
        append_item(itemDst, text, image)
    end

    def onBeginLabelEdit(event)
        log_message("OnBeginLabelEdit")

        # for testing, prevent self item's label editing
        itemId = event.get_item()
        if is_test_item(itemId)
            message_box("You can't edit self item.")

            event.veto()
        end
    end

    def onEndLabelEdit(event)
        log_message("OnEndLabelEdit")

        # don't allow anything except letters in the labels
        if event.get_label() !~ /[0-9a-zA-Z.]+/
            message_box("The new label should be a single word.")

            event.veto()
        end
    end

    def onItemCollapsing(event)
        log_message("OnItemCollapsing")

        # for testing, prevent the user from collapsing the first child folder
        itemId = event.get_item()
        if is_test_item(itemId)
            message_box("You can't collapse self item.")

            event.veto()
        end
    end

    def onItemActivated(event)
        # show some info about self item
        itemId = event.get_item()
        item = get_item_data(itemId)

        if item != nil
            item.show_info(self)
        end

        log_message("OnItemActivated")
    end

    def onItemRightClick(event)
        ShowMenu(event.get_item(), event.get_point())
    end

    def onRMouseUp(event)
        pt = event.get_position()
        ShowMenu(hit_test(pt), pt)
    end

    def ShowMenu(id,pt)
        title = ""
        if id>=0
            title << "Menu for " << get_item_text(id)
        else
            title = "Menu for no particular item"
        end

        menu = Menu.new(title)
        menu.append(TreeTest_About, "&About...")
        menu.append(TreeTest_Dump, "&Dump")

        popup_menu(menu, pt)
    end

    def onRMouseDClick(event)
        id = hit_test(event.get_position())
        if !id
            log_message("No item under mouse")
        else
            item = get_item_data(id)
            if item
                log_message("Item '%s' under mouse", item.GetDesc())
            end
        end
    end

end


class MyFrame < Frame
    def initialize(title, x, y, w, h)
        super(nil, -1, title, Point.new(x, y), Size.new(w, h))
        @m_treeCtrl = nil
        @m_textCtrl = nil
        @s_num = 0

        # This reduces flicker effects - even better would be to define
        # OnEraseBackground to do nothing. When the tree control's scrollbars are
        # show or hidden, the frame is sent a background erase event.
        set_background_colour(Colour.new(255, 255, 255))

        # Give it an icon
        set_icon(Icon.new("mondrian.xpm"))

        # Make a menubar
        file_menu = Menu.new
        style_menu = Menu.new
        tree_menu = Menu.new
        item_menu = Menu.new

        file_menu.append(TreeTest_About, "&About...")
        file_menu.append_separator()
        file_menu.append(TreeTest_Quit, "E&xit\tAlt-X")

        style_menu.append(TreeTest_TogButtons, "Toggle &normal buttons", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogTwist, "Toggle &twister buttons", "", ITEM_CHECK)
        style_menu.append(TreeTest_ToggleButtons, "Toggle image &buttons", "", ITEM_CHECK)
        style_menu.append_separator()
        style_menu.append(TreeTest_TogLines, "Toggle &connecting lines", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogRootLines, "Toggle &lines at root", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogHideRoot, "Toggle &hidden root", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogBorder, "Toggle &item border", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogFullHighlight, "Toggle &full row highlight", "", ITEM_CHECK)
        style_menu.append(TreeTest_TogEdit, "Toggle &edit mode", "", ITEM_CHECK)
        style_menu.append(TreeTest_ToggleSel, "Toggle &selection mode", "", ITEM_CHECK)
        style_menu.append(TreeTest_ToggleImages, "Toggle show ima&ges", "", ITEM_CHECK)
        style_menu.append(TreeTest_SetImageSize, "Set image si&ze...")
        style_menu.append_separator()
        style_menu.append(TreeTest_SetFgColour, "Set &foreground colour...")
        style_menu.append(TreeTest_SetBgColour, "Set &background colour...")
        style_menu.append_separator()
        style_menu.append(TreeTest_ResetStyle, "&Reset to default\tF10")

        tree_menu.append(TreeTest_Recreate, "&Recreate the tree")
        tree_menu.append(TreeTest_CollapseAndReset, "C&ollapse and reset")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_AddItem, "append a &new item")
        tree_menu.append(TreeTest_InsertItem, "&Insert a new item")
        tree_menu.append(TreeTest_Delete, "&delete self item")
        tree_menu.append(TreeTest_DeleteChildren, "delete &children")
        tree_menu.append(TreeTest_DeleteAll, "delete &all items")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_Count, "Count children of current item")
        tree_menu.append(TreeTest_CountRec, "Recursively count children of current item")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_Sort, "Sort children of current item")
        tree_menu.append(TreeTest_SortRev, "Sort in reversed order")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_EnsureVisible, "Make the last item &visible")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_IncIndent, "add 5 points to indentation\tAlt-I")
        tree_menu.append(TreeTest_DecIndent, "Reduce indentation by 5 points\tAlt-R")
        tree_menu.append_separator()
        tree_menu.append(TreeTest_IncSpacing, "add 5 points to spacing\tCtrl-I")
        tree_menu.append(TreeTest_DecSpacing, "Reduce spacing by 5 points\tCtrl-R")

        item_menu.append(TreeTest_Dump, "&Dump item children")
        item_menu.append(TreeTest_Rename, "&Rename item...")

        item_menu.append_separator()
        item_menu.append(TreeTest_SetBold, "Make item &bold")
        item_menu.append(TreeTest_ClearBold, "Make item &not bold")
        item_menu.append_separator()
        item_menu.append(TreeTest_ToggleIcon, "Toggle the item's &icon")

        item_menu.append_separator()
        item_menu.append(TreeTest_DumpSelected, "Dump selected items\tAlt-D")
        item_menu.append(TreeTest_Select, "Select current item\tAlt-S")
        item_menu.append(TreeTest_Unselect, "Unselect everything\tAlt-U")

        menu_bar = MenuBar.new
        menu_bar.append(file_menu, "&File")
        menu_bar.append(style_menu, "&Style")
        menu_bar.append(tree_menu, "&Tree")
        menu_bar.append(item_menu, "&Item")
        set_menu_bar(menu_bar)


        # create the controls
        @m_textCtrl = TextCtrl.new(self, -1, "",
                                    DEFAULT_POSITION, DEFAULT_SIZE,
                                    TE_MULTILINE | SUNKEN_BORDER)

        CreateTreeWithDefStyle()

        menu_bar.check(TreeTest_ToggleImages, TRUE)

        # create a status bar with 3 panes
        create_status_bar(3)
        set_status_text("", 0)

        # set our text control as the log target
        logWindow = LogTextCtrl.new(@m_textCtrl)
        Log::set_active_target(logWindow)

        evt_size {|event| onSize(event) }

        evt_menu(TreeTest_Quit) {|event| onQuit(event) }
        evt_menu(TreeTest_About) {|event| onAbout(event) }

        evt_menu(TreeTest_TogButtons) {|event| onTogButtons(event) }
        evt_menu(TreeTest_TogTwist) {|event| onTogTwist(event) }
        evt_menu(TreeTest_TogLines) {|event| onTogLines(event) }
        evt_menu(TreeTest_TogEdit) {|event| onTogEdit(event) }
        evt_menu(TreeTest_TogHideRoot) {|event| onTogHideRoot(event) }
        evt_menu(TreeTest_TogRootLines) {|event| onTogRootLines(event) }
        evt_menu(TreeTest_TogBorder) {|event| onTogBorder(event) }
        evt_menu(TreeTest_TogFullHighlight) {|event| onTogFullHighlight(event) }
        evt_menu(TreeTest_SetFgColour) {|event| onSetFgColour(event) }
        evt_menu(TreeTest_SetBgColour) {|event| onSetBgColour(event) }
        evt_menu(TreeTest_ResetStyle) {|event| onResetStyle(event) }

        evt_menu(TreeTest_Dump) {|event| onDump(event) }
        evt_menu(TreeTest_DumpSelected) {|event| onDumpSelected(event) }
        evt_menu(TreeTest_Select) {|event| onSelect(event) }
        evt_menu(TreeTest_Unselect) {|event| onUnselect(event) }
        evt_menu(TreeTest_ToggleSel) {|event| onToggleSel(event) }
        evt_menu(TreeTest_Rename) {|event| onRename(event) }
        evt_menu(TreeTest_Count) {|event| onCount(event) }
        evt_menu(TreeTest_CountRec) {|event| onCountRec(event) }
        evt_menu(TreeTest_Sort) {|event| onSort(event) }
        evt_menu(TreeTest_SortRev) {|event| onSortRev(event) }
        evt_menu(TreeTest_SetBold) {|event| onSetBold(event) }
        evt_menu(TreeTest_ClearBold) {|event| onClearBold(event) }
        evt_menu(TreeTest_Delete) {|event| onDelete(event) }
        evt_menu(TreeTest_DeleteChildren) {|event| onDeleteChildren(event) }
        evt_menu(TreeTest_DeleteAll) {|event| onDeleteAll(event) }
        evt_menu(TreeTest_Recreate) {|event| onRecreate(event) }
        evt_menu(TreeTest_ToggleImages) {|event| onToggleImages(event) }
        evt_menu(TreeTest_ToggleButtons) {|event| onToggleButtons(event) }
        evt_menu(TreeTest_SetImageSize) {|event| onSetImageSize(event) }
        evt_menu(TreeTest_CollapseAndReset) {|event| onCollapseAndReset(event) }
        evt_menu(TreeTest_EnsureVisible) {|event| onEnsureVisible(event) }
        evt_menu(TreeTest_AddItem) {|event| onAddItem(event) }
        evt_menu(TreeTest_InsertItem) {|event| onInsertItem(event) }
        evt_menu(TreeTest_IncIndent) {|event| onIncIndent(event) }
        evt_menu(TreeTest_DecIndent) {|event| onDecIndent(event) }
        evt_menu(TreeTest_IncSpacing) {|event| onIncSpacing(event) }
        evt_menu(TreeTest_DecSpacing) {|event| onDecSpacing(event) }
        evt_menu(TreeTest_ToggleIcon) {|event| onToggleIcon(event) }

        evt_close {|event| onClose(event) }
    end

    def CreateTreeWithDefStyle()

        style = TR_DEFAULT_STYLE |
                     TR_EDIT_LABELS

        CreateTree(style | SUNKEN_BORDER)

        # as we don't know what TR_DEFAULT_STYLE could contain, test for
        # everything
        mbar = get_menu_bar()
        mbar.check(TreeTest_TogButtons, (style & TR_HAS_BUTTONS) != 0)
        mbar.check(TreeTest_TogButtons, (style & TR_TWIST_BUTTONS) != 0)
        mbar.check(TreeTest_TogLines, (style & TR_NO_LINES) == 0)
        mbar.check(TreeTest_TogRootLines, (style & TR_LINES_AT_ROOT) != 0)
        mbar.check(TreeTest_TogHideRoot, (style & TR_HIDE_ROOT) != 0)
        mbar.check(TreeTest_TogEdit, (style & TR_EDIT_LABELS) != 0)
        mbar.check(TreeTest_TogBorder, (style & TR_ROW_LINES) != 0)
        mbar.check(TreeTest_TogFullHighlight, (style & TR_FULL_ROW_HIGHLIGHT) != 0)
    end

    def CreateTree(style)

        @m_treeCtrl = MyTreeCtrl.new(self, TreeTest_Ctrl,
                                    DEFAULT_POSITION, DEFAULT_SIZE,
                                    style)
        resize()
    end

    def TogStyle(id,flag)

        style = @m_treeCtrl.get_window_style_flag() ^ flag

        # most treectrl styles can't be changed on the fly using the native
        # control and the tree must be recreated
        if RUBY_PLATFORM != "WXMSW"
            @m_treeCtrl.set_window_style_flag(style)
        else
            @m_treeCtrl.free
            CreateTree(style)
        end

        get_menu_bar().check(id, (style & flag) != 0)
    end

    def onTogButtons(event)
         TogStyle(event.get_id(), TR_HAS_BUTTONS)
    end

    def onTogTwist(event)
         TogStyle(event.get_id(), TR_TWIST_BUTTONS)
    end

    def onTogLines(event)
         TogStyle(event.get_id(), TR_NO_LINES)
    end

    def onTogEdit(event)
         TogStyle(event.get_id(), TR_EDIT_LABELS)
    end

    def onTogHideRoot(event)
         TogStyle(event.get_id(), TR_HIDE_ROOT)
    end

    def onTogRootLines(event)
         TogStyle(event.get_id(), TR_LINES_AT_ROOT)
    end

    def onTogBorder(event)
         TogStyle(event.get_id(), TR_ROW_LINES)
    end

    def onTogFullHighlight(event)
         TogStyle(event.get_id(), TR_FULL_ROW_HIGHLIGHT)
    end

    def onResetStyle(event)
         CreateTreeWithDefStyle()
    end

    def onSetBold(event)
        DoSetBold(TRUE)
    end

    def onClearBold(event)
        DoSetBold(FALSE)
    end

    def onSort(event)
        DoSort()
    end

    def onSortRev(event)
        DoSort(TRUE)
    end

    def onSize(event)
        if @m_treeCtrl && @m_textCtrl
            resize()
        end

        event.skip()
    end

    def resize()
        size = get_client_size()
        @m_treeCtrl.set_size_xy(size.x, 2*size.y/3)
        @m_textCtrl.set_dimensions(0, 2*size.y/3, size.x, size.y/3)
    end

    def onClose(event)
        Log::set_active_target(nil)
        destroy()
    end

    def onQuit(event)
        close(TRUE)
    end

    def onAbout(event)
        message_box("Tree test sample\n" +
                     "(c) Julian Smart 1997, Vadim Zeitlin 1998",
                     "About tree test",
                     OK | ICON_INFORMATION, self)
    end

    def CHECK_ITEM(item)
        if item<0
            message_box("Please select some item first!",
                      "Tree sample error",
                      OK | ICON_EXCLAMATION,
                      self)
        end
        item >= 0
    end

    def onRename(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        # TODO demonstrate creating a custom edit control...
        @m_treeCtrl.edit_label(item)
    end

    def onCount(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        i = @m_treeCtrl.get_children_count( item, FALSE )

        log_message("%d children", i)
    end

    def onCountRec(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        i = @m_treeCtrl.get_children_count( item )

        log_message("%d children", i)
    end

    def DoSort(reverse = FALSE)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        @m_treeCtrl.DoSortChildren(item, reverse)
    end

    def onDump(event)
        root = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( root )

        @m_treeCtrl.get_items_recursively(root, -1)
    end

    def onToggleSel(event)
        TogStyle(event.get_id(), TR_MULTIPLE)
    end

    def onDumpSelected(event)
        array = @m_treeCtrl.get_selections()
        count = array.length
        log_message("%u items selected", count)

        for n in 0 ... count
            log_message("\t%s", @m_treeCtrl.get_item_text(array[n]))
        end
    end

    def onSelect(event)
        @m_treeCtrl.select_item(@m_treeCtrl.get_selection())
    end

    def onUnselect(event)
        @m_treeCtrl.unselect_all()
    end


    def DoSetBold(bold = TRUE)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        @m_treeCtrl.set_item_bold(item, bold)
    end

    def onDelete(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        @m_treeCtrl.delete(item)
    end

    def onDeleteChildren(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        @m_treeCtrl.delete_children(item)
    end

    def onDeleteAll(event)
        @m_treeCtrl.delete_all_items()
    end

    def onRecreate(event)
        onDeleteAll(event)
        @m_treeCtrl.AddTestItemsToTree(5, 2)
    end

    def onSetImageSize(event)
        size = get_number_from_user("Enter the size for the images to use",
                                        "Size: ",
                                        "TreeCtrl sample",
                                        @m_treeCtrl.ImageSize())
        if size == -1
            return nil
        end

        @m_treeCtrl.create_image_list(size)
        get_app().set_show_images(TRUE)
    end

    def onToggleImages(event)
        if get_app().show_images()
            @m_treeCtrl.create_image_list(-1)
            get_app().set_show_images(FALSE)
        else
            @m_treeCtrl.create_image_list(0)
            get_app().set_show_images(TRUE)
        end
    end

    def onToggleButtons(event)
    end

    def onCollapseAndReset(event)
        @m_treeCtrl.collapse_and_reset(@m_treeCtrl.get_root_item())
    end

    def onEnsureVisible(event)
        @m_treeCtrl.do_ensure_visible()
    end

    def onInsertItem(event)
        image = get_app().show_images() ? TreeCtrlIcon_File : -1
        @m_treeCtrl.insert_item(@m_treeCtrl.get_root_item(), image, "2nd item")
    end

    def onAddItem(event)
        @s_num += 1
        text = sprintf("Item #%d", @s_num)

        @m_treeCtrl.append_item(@m_treeCtrl.get_root_item(),
                               text)
    end

    def onIncIndent(event)
        indent = @m_treeCtrl.get_indent()
        if indent < 100
            @m_treeCtrl.set_indent( indent+5 )
        end
    end

    def onDecIndent(event)
        indent = @m_treeCtrl.get_indent()
        if indent > 10
            @m_treeCtrl.set_indent( indent-5 )
        end
    end

    def onIncSpacing(event)
        indent = @m_treeCtrl.get_spacing()
        if indent < 100
            @m_treeCtrl.set_spacing( indent+5 )
        end
    end

    def onDecSpacing(event)
        indent = @m_treeCtrl.get_spacing()
        if indent > 10
            @m_treeCtrl.set_spacing( indent-5 )
        end
    end

    def onToggleIcon(event)
        item = @m_treeCtrl.get_selection()

        return nil unless CHECK_ITEM( item )

        @m_treeCtrl.do_toggle_icon(item)
    end

    def onSetFgColour(event)
        col = get_colour_from_user(self, @m_treeCtrl.get_foreground_colour())
        if col.ok()
            @m_treeCtrl.set_foreground_colour(col)
        end
    end

    def onSetBgColour(event)
        col = get_colour_from_user(self, @m_treeCtrl.get_background_colour())
        if col.ok()
            @m_treeCtrl.set_background_colour(col)
        end
    end

end

class MyApp < App
    def initialize
        @m_showImages = TRUE
        @m_showButtons = FALSE
        super
    end
    
    def OnInit
        # Create the main frame window
        frame = MyFrame.new("TreeCtrl Test", 50, 50, 450, 600)

        # show the frame
        frame.show(TRUE)
        set_top_window(frame)

    end

    def set_show_images(show)
        @m_showImages = show
    end

    def show_images()
        @m_showImages
    end

    def SetShowButtons(show)
        @m_showButtons = show
    end

    def ShowButtons()
        @m_showButtons
    end
    
end


a = MyApp.new
a.main_loop()
