# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

require 'wx'

# This sample shows off the features of the TreeCtrl widget. The actual
# features vary somewhat across platforms; for example, the button
# styles and connecting lines between items are not available on OS X.
# Also, some items remain to be implemented - for example, setting item
# icons and item data.

# Just some event ids for the numerous menu items
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
TreeTest_Unselect = (0..39).to_a
TreeTest_Ctrl = 1000

TreeCtrlIcon_File,
TreeCtrlIcon_FileSelected,
TreeCtrlIcon_Folder,
TreeCtrlIcon_FolderSelected,
TreeCtrlIcon_FolderOpened = 0,1,2,3,4

class MyTreeCtrl < Wx::TreeCtrl
  def initialize(parent, id,pos, size,style)
    super(parent, id, pos, size, style)

    @reverse_sort = false

    create_image_list()

    # add some items to the tree
    add_test_items_to_tree(5, 2)

    # TreeCtrl supports a large number of different events...
    evt_tree_begin_drag(TreeTest_Ctrl) { | e | on_begin_drag(e) }
    evt_tree_begin_rdrag(TreeTest_Ctrl) { | e | on_begin_rdrag(e) }
    evt_tree_end_drag(TreeTest_Ctrl) { | e | on_end_drag(e) }
    evt_tree_begin_label_edit(TreeTest_Ctrl) { | e | on_begin_label_edit(e) }
    evt_tree_end_label_edit(TreeTest_Ctrl) { | e | on_end_label_edit(e) }
    evt_tree_delete_item(TreeTest_Ctrl) { | e | on_delete_item(e) }
    evt_tree_set_info(TreeTest_Ctrl) { | e | on_set_info(e) }
    evt_tree_item_expanded(TreeTest_Ctrl) { | e | on_item_expanded(e) }
    evt_tree_item_expanding(TreeTest_Ctrl) { | e | on_item_expanding(e) }
    evt_tree_item_collapsed(TreeTest_Ctrl) { | e | on_item_collapsed(e) }
    evt_tree_item_collapsing(TreeTest_Ctrl) { | e | on_item_collapsing(e) }
    evt_tree_item_right_click(TreeTest_Ctrl) { | e | on_item_right_click(e) }

    evt_right_up { | e | on_rmouse_up(e) }
    evt_tree_sel_changed(TreeTest_Ctrl) { | e | on_sel_changed(e) }
    evt_tree_sel_changing(TreeTest_Ctrl) { | e | on_sel_changing(e) }
    evt_tree_key_down(TreeTest_Ctrl) { | e | on_tree_key_down(e) }
    evt_tree_item_activated(TreeTest_Ctrl) { | e | on_item_activated(e) }
    evt_right_dclick { | e | on_rmouse_dclick(event) }

  end

  def show_info(id)
    Wx::log_message("Item '%s': %sselected, %sexpanded, %sbold,\n" +
                "%d children (%d immediately under selected item).",
                get_item_text( id ),
                bool_to_str( is_selected( id ) ),
                bool_to_str( is_expanded( id ) ),
                bool_to_str( is_bold( id ) ),
                get_children_count( id ),
                get_children_count(id, false) )
  end

  def bool_to_str(bool)
    bool ? " " : "not "
  end

  def do_sort_children(item, reverse = false)
    @reverse_sort = reverse
    sort_children(item)
  end

  def do_ensure_visible()
    ensure_visible(@last_item)
  end

  def image_size()
    return @image_size
  end

  def is_test_item(item)
    # the test item is the first child folder
    return get_item_parent(item) == get_root_item() && !get_prev_sibling(item)
  end

  # TEMPORARILY DISABLED
  def set_item_image(*args)
  end

  # TEMPORARILY DISABLED
  def create_image_list(size = 16)
    return false
    if size == -1
      set_image_list(nil)
      return nil
    end
    if size == 0
      size = @imageSize
    else
      @imageSize = size
    end

    # Make an image list containing small icons
    images = Wx::ImageList.new(size, size, true)

    # should correspond to TreeCtrlIcon_xxx enum
    Wx::BusyCursor.busy do |x|
      icons = [
        Wx::Icon.new("icon1.xpm"),
        Wx::Icon.new("icon2.xpm"),
        Wx::Icon.new("icon3.xpm"),
        Wx::Icon.new("icon4.xpm"),
        Wx::Icon.new("icon5.xpm")]
      
      orig_size = icons[0].get_width()
      for i in 0 ... icons.length
        if size == orig_size
          images.add(icons[i])
        else
          images.add(icons[i])
        end
      end
      
      assign_image_list(images)
    end
  end

  def create_buttons_image_list(size = 11)
    if size == -1
      set_buttons_image_list(nil)
      return nil
    end

    # Make an image list containing small icons
    images = Wx::ImageList.new(size, size, true)

    # should correspond to TreeCtrlIcon_xxx enum
    Wx::BusyCursor.busy do |x|
      icons = [
        Wx::Icon.new("icon3.xpm"),   # closed
        Wx::Icon.new("icon3.xpm"),   # closed, selected
        Wx::Icon.new("icon5.xpm"),   # open
        Wx::Icon.new("icon5.xpm")]   # open, selected
      
      for i in 0 ... icons.length
        orig_size = icons[i].get_width()
        if size == orig_size
          images.add(icons[i])
        else
          resized = icons[i].convert_to_image().rescale(size, size)
          images.add( Wx::Bitmap.new(resized) )
        end
      end
      
      assign_buttons_image_list(images)
    end
  end

  def on_compare_items(item1,item2)
    if @reverse_sort
      # just exchange 1st and 2nd items
      return super(item2, item1)
    else
      return super(item1, item2)
    end
  end

  def add_items_recursively(parent_id, num_children, depth, folder)
    if depth > 0
      has_children = depth > 1

      for n in 0 ... num_children
        # at depth 1 elements won't have any more children
        if has_children
          str = sprintf("%s child %d", "Folder", n + 1)
        else
          str = sprintf("%s child %d.%d", "File", folder, n + 1)
        end
        # here we pass to append_item() normal and selected item images (we
        # suppose that selected image follows the normal one in the enum)
        if Wx::get_app.show_images()
          image = depth == 1 ? TreeCtrlIcon_File : TreeCtrlIcon_Folder
          imageSel = image + 1
        else
          image = imageSel = -1
        end
        id = append_item(parent_id, str, image, imageSel)

        # and now we also set the expanded one (only for the folders)
        if has_children && Wx::get_app.show_images()
          set_item_image(id, TreeCtrlIcon_FolderOpened,
                         Wx::TREE_ITEM_ICON_EXPANDED)
        end

        # remember the last child for OnEnsureVisible()
        if ! has_children && n == num_children - 1
          @last_item = id
        end

        add_items_recursively(id, num_children, depth - 1, n + 1)
      end
    end
  end

  def add_test_items_to_tree(num_children,depth)
    image = Wx::get_app.show_images() ? TreeCtrlIcon_Folder : -1
    root_id = add_root("Root",image, image)
    if image != -1
      set_item_image(root_id, TreeCtrlIcon_FolderOpened, 
                     Wx::TREE_ITEM_ICON_EXPANDED)
    end

    add_items_recursively(root_id, num_children, depth, 0)

    # set some colours/fonts for testing
    set_item_font(root_id, Wx::ITALIC_FONT)

    id,cookie = get_first_child(root_id)
    set_item_text_colour(id, Wx::BLUE)

    id,cookie = get_next_child(root_id,cookie)
    id,cookie = get_next_child(root_id,cookie)
    set_item_text_colour(id, Wx::RED)
    # Not supported on OS X
    set_item_background_colour(id, Wx::LIGHT_GREY)
  end

  def get_items_recursively(parent_id, cookie)
    if cookie == -1
      id, cookie = get_first_child(parent_id)
    else
      id, cookie = get_next_child(parent_id, cookie)
    end
    if not id.is_ok
      return nil
    end

    text = get_item_text(id)
    Wx::log_message(text)

    if item_has_children(id)
      get_items_recursively(id,-1)
    end
    get_items_recursively(parent_id, cookie)
  end

  def do_toggle_icon(item)
    old_img = get_item_image(item)
    if old_img == TreeCtrlIcon_Folder
      new_img = TreeCtrlIcon_File
    else
      new_img = TreeCtrlIcon_Folder
    end

    set_item_image(item, new_img)
  end

  def on_begin_rdrag(event)
    Wx::log_message("OnBeginRDrag")
    event.skip()
  end

  def on_delete_item(event)
    Wx::log_message("OnDeleteItem")
    event.skip()
  end

  def on_get_info(event)
    Wx::log_message("OnGetInfo")
    event.skip()
  end

  def on_set_info(event)
    Wx::log_message("OnSetInfo")
    event.skip()
  end

  def on_item_expanded(event)
    Wx::log_message("OnItemExpanded")
    event.skip()
  end

  def on_item_expanding(event)
    Wx::log_message("OnItemExpanding")
    event.skip()
  end

  def on_item_collapsed(event)
    Wx::log_message("OnItemCollapsed")
    event.skip()
  end

  def on_sel_changed(event)
    Wx::log_message("OnSelChanged")
    event.skip()
  end

  def on_sel_changing(event)
    Wx::log_message("OnSelChanging")
    event.skip()
  end

  def log_key_event(name,event)
    keycode = event.get_key_code()

    case keycode
    when Wx::K_BACK
      key = "BACK"
    when Wx::K_TAB
      key = "TAB"
    when Wx::K_RETURN
      key = "RETURN"
    when Wx::K_ESCAPE
      key = "ESCAPE"
    when Wx::K_SPACE
      key = "SPACE"
    when Wx::K_DELETE
      key = "DELETE"
    when Wx::K_START
      key = "START"
    when Wx::K_LBUTTON
      key = "LBUTTON"
    when Wx::K_RBUTTON
      key = "RBUTTON"
    when Wx::K_CANCEL
      key = "CANCEL"
    when Wx::K_MBUTTON
      key = "MBUTTON"
    when Wx::K_CLEAR
      key = "CLEAR"
    when Wx::K_SHIFT
      key = "SHIFT"
    when Wx::K_ALT
      key = "ALT"
    when Wx::K_CONTROL
      key = "CONTROL"
    when Wx::K_MENU
      key = "MENU"
    when Wx::K_PAUSE
      key = "PAUSE"
    when Wx::K_CAPITAL
      key = "CAPITAL"
    when Wx::K_PRIOR
      key = "PRIOR"
    when Wx::K_NEXT
      key = "NEXT"
    when Wx::K_END
      key = "END"
    when Wx::K_HOME
      key = "HOME"
    when Wx::K_LEFT
      key = "LEFT"
    when Wx::K_UP
      key = "UP"
    when Wx::K_RIGHT
      key = "RIGHT"
    when Wx::K_DOWN
      key = "DOWN"
    when Wx::K_SELECT
      key = "SELECT"
    when Wx::K_PRINT
      key = "PRINT"
    when Wx::K_EXECUTE
      key = "EXECUTE"
    when Wx::K_SNAPSHOT
      key = "SNAPSHOT"
    when Wx::K_INSERT
      key = "INSERT"
    when Wx::K_HELP
      key = "HELP"
    when Wx::K_NUMPAD0
      key = "NUMPAD0"
    when Wx::K_NUMPAD1
      key = "NUMPAD1"
    when Wx::K_NUMPAD2
      key = "NUMPAD2"
    when Wx::K_NUMPAD3
      key = "NUMPAD3"
    when Wx::K_NUMPAD4
      key = "NUMPAD4"
    when Wx::K_NUMPAD5
      key = "NUMPAD5"
    when Wx::K_NUMPAD6
      key = "NUMPAD6"
    when Wx::K_NUMPAD7
      key = "NUMPAD7"
    when Wx::K_NUMPAD8
      key = "NUMPAD8"
    when Wx::K_NUMPAD9
      key = "NUMPAD9"
    when Wx::K_MULTIPLY
      key = "MULTIPLY"
    when Wx::K_ADD
      key = "ADD"
    when Wx::K_SEPARATOR
      key = "SEPARATOR"
    when Wx::K_SUBTRACT
      key = "SUBTRACT"
    when Wx::K_DECIMAL
      key = "DECIMAL"
    when Wx::K_DIVIDE
      key = "DIVIDE"
    when Wx::K_F1
      key = "F1"
    when Wx::K_F2
      key = "F2"
    when Wx::K_F3
      key = "F3"
    when Wx::K_F4
      key = "F4"
    when Wx::K_F5
      key = "F5"
    when Wx::K_F6
      key = "F6"
    when Wx::K_F7
      key = "F7"
    when Wx::K_F8
      key = "F8"
    when Wx::K_F9
      key = "F9"
    when Wx::K_F10
      key = "F10"
    when Wx::K_F11
      key = "F11"
    when Wx::K_F12
      key = "F12"
    when Wx::K_F13
      key = "F13"
    when Wx::K_F14
      key = "F14"
    when Wx::K_F15
      key = "F15"
    when Wx::K_F16
      key = "F16"
    when Wx::K_F17
      key = "F17"
    when Wx::K_F18
      key = "F18"
    when Wx::K_F19
      key = "F19"
    when Wx::K_F20
      key = "F20"
    when Wx::K_F21
      key = "F21"
    when Wx::K_F22
      key = "F22"
    when Wx::K_F23
      key = "F23"
    when Wx::K_F24
      key = "F24"
    when Wx::K_NUMLOCK
      key = "NUMLOCK"
    when Wx::K_SCROLL
      key = "SCROLL"
    when Wx::K_PAGEUP
      key = "PAGEUP"
    when Wx::K_PAGEDOWN
      key = "PAGEDOWN"
    when Wx::K_NUMPAD_SPACE
      key = "NUMPAD_SPACE"
    when Wx::K_NUMPAD_TAB
      key = "NUMPAD_TAB"
    when Wx::K_NUMPAD_ENTER
      key = "NUMPAD_ENTER"
    when Wx::K_NUMPAD_F1
      key = "NUMPAD_F1"
    when Wx::K_NUMPAD_F2
      key = "NUMPAD_F2"
    when Wx::K_NUMPAD_F3
      key = "NUMPAD_F3"
    when Wx::K_NUMPAD_F4
      key = "NUMPAD_F4"
    when Wx::K_NUMPAD_HOME
      key = "NUMPAD_HOME"
    when Wx::K_NUMPAD_LEFT
      key = "NUMPAD_LEFT"
    when Wx::K_NUMPAD_UP
      key = "NUMPAD_UP"
    when Wx::K_NUMPAD_RIGHT
      key = "NUMPAD_RIGHT"
    when Wx::K_NUMPAD_DOWN
      key = "NUMPAD_DOWN"
    when Wx::K_NUMPAD_PRIOR
      key = "NUMPAD_PRIOR"
    when Wx::K_NUMPAD_PAGEUP
      key = "NUMPAD_PAGEUP"
    when Wx::K_NUMPAD_PAGEDOWN
      key = "NUMPAD_PAGEDOWN"
    when Wx::K_NUMPAD_END
      key = "NUMPAD_END"
    when Wx::K_NUMPAD_BEGIN
      key = "NUMPAD_BEGIN"
    when Wx::K_NUMPAD_INSERT
      key = "NUMPAD_INSERT"
    when Wx::K_NUMPAD_DELETE
      key = "NUMPAD_DELETE"
    when Wx::K_NUMPAD_EQUAL
      key = "NUMPAD_EQUAL"
    when Wx::K_NUMPAD_MULTIPLY
      key = "NUMPAD_MULTIPLY"
    when Wx::K_NUMPAD_ADD
      key = "NUMPAD_ADD"
    when Wx::K_NUMPAD_SEPARATOR
      key = "NUMPAD_SEPARATOR"
    when Wx::K_NUMPAD_SUBTRACT
      key = "NUMPAD_SUBTRACT"
    when Wx::K_NUMPAD_DECIMAL
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

    Wx::log_message( "%s event: %s (flags = %s%s%s%s)",
                name, key,
                event.control_down() ? 'C' : '-',
                event.alt_down() ? 'A' : '-',
                event.shift_down() ? 'S' : '-',
                event.meta_down() ? 'M' : '-')
  end

  def on_tree_key_down(event)
    log_key_event("Tree key down ", event.get_key_event())

    event.skip()
  end

  def on_begin_drag(event)
    # need to explicitly allow drag
    if event.get_item() != get_root_item()
      @dragged_item = event.get_item()
      Wx::log_message("OnBeginDrag: started dragging %s",
                  get_item_text(@dragged_item))
      event.allow()
    else
      Wx::log_message("OnBeginDrag: selected item can't be dragged.")
    end
  end

  def on_end_drag(event)
    src_item = @dragged_item
    dest_item = event.get_item()
    @dragged_item = 0

    if dest_item.is_ok && ! item_has_children(dest_item)
      # copy to the parent then
      dest_item = get_item_parent(dest_item)
    end

    unless dest_item.is_ok()
      Wx::log_message("OnEndDrag: can't drop here.")
      return nil
    end

    text = get_item_text(src_item)
    Wx::log_message("OnEndDrag: '%s' copied to '%s'.",
                text, get_item_text(dest_item))

    # just do append here - we could also insert it just before/after the item
    # on which it was dropped, but self requires slightly more work... we also
    # completely ignore the client data and icon of the old item but could
    # copy them as well.
    #
    # Finally, we only copy one item here but we might copy the entire tree if
    # we were dragging a folder.
    image = Wx::get_app().show_images() ? TreeCtrlIcon_File : -1
    append_item(dest_item, text, image)
  end

  def on_begin_label_edit(event)
    Wx::log_message("OnBeginLabelEdit")

    # for testing, prevent self item's label editing
    item_id = event.get_item()
    if is_test_item(item_id)
      message_box("The demo prevents you editing this item.")
      event.veto()
    end
  end

  def on_end_label_edit(event)
    Wx::log_message("OnEndLabelEdit")
    if event.is_edit_cancelled
      Wx::log_message("Label edit was cancelled by user")
      return
    end

    # For a demo, don't allow anything except letters in the labels
    if event.get_label =~ /[^\w.]/
      msg = "Only letters, numbers and full stops are allowed in the label."
      message_box(msg)
      Wx::log_message("Label edit was cancelled by demo")
      event.veto()
    end
  end

  def on_item_collapsing(event)
    Wx::log_message("OnItemCollapsing")

    # for testing, prevent the user from collapsing the first child folder
    item_id = event.get_item()
    if is_test_item(item_id)
      message_box("You can't collapse self item.")

      event.veto()
    end
  end

  # show some info about activated item
  def on_item_activated(event)
    if item_id  = event.get_item()
      show_info(item_id)
    end
    Wx::log_message("OnItemActivated")
  end

  def on_item_right_click(event)
    show_popup_menu(event.get_item(), event.get_point())
  end

  def on_rmouse_up(event)
    pos  = event.get_position()
    item = hit_test(pos)
    show_popup_menu(item, pos)
  end

  def show_popup_menu(id, pos)
    title = ""
    if id.is_ok
      title << "Menu for " << get_item_text(id)
    else
      title = "Menu for no particular item"
    end

    menu = Wx::Menu.new(title)
    menu.append(Wx::ID_ABOUT, "&About...")
    menu.append(TreeTest_Dump, "&Dump")
    popup_menu(menu, pos)
  end

  def on_rmouse_dclick(event)
    id = hit_test(event.get_position())
    if not id
      Wx::log_message("No item under mouse")
    else
      item = get_item_text(id)
      if item
        Wx::log_message("Item '%s' under mouse", item)
      end
    end
  end
end


class MyFrame < Wx::Frame
  def initialize(title, x, y, w, h)
    super(nil, -1, title, Wx::Point.new(x, y), Wx::Size.new(w, h))
    @treectrl = nil
    @textctrl = nil
    @s_num = 0

    # This reduces flicker effects - even better would be to define
    # OnEraseBackground to do nothing. When the tree control's scrollbars are
    # show or hidden, the frame is sent a background erase event.
    set_background_colour(Wx::Colour.new(255, 255, 255))

    # Make a menubar
    file_menu  = Wx::Menu.new
    style_menu = Wx::Menu.new
    tree_menu  = Wx::Menu.new
    item_menu  = Wx::Menu.new

    file_menu.append(Wx::ID_ABOUT, "&About...")
    file_menu.append_separator()
    file_menu.append(Wx::ID_EXIT, "E&xit\tAlt-X")

    style_menu.append(TreeTest_TogButtons, 
                      "Toggle &normal buttons", "",  Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogTwist, 
                      "Toggle &twister buttons", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_ToggleButtons, 
                      "Toggle image &buttons", "", Wx::ITEM_CHECK)
    style_menu.append_separator()
    style_menu.append(TreeTest_TogLines, 
                      "Toggle &connecting lines", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogRootLines, 
                      "Toggle &lines at root", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogHideRoot, 
                      "Toggle &hidden root", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogBorder, 
                      "Toggle &item border", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogFullHighlight, 
                      "Toggle &full row highlight", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_TogEdit, 
                      "Toggle &editing allowed", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_ToggleSel, 
                      "Toggle multiple &selection", "",  Wx::ITEM_CHECK)
    style_menu.append(TreeTest_ToggleImages, 
                      "Toggle show ima&ges", "", Wx::ITEM_CHECK)
    style_menu.append(TreeTest_SetImageSize, "Set image si&ze...")
    style_menu.append_separator()
    style_menu.append(TreeTest_SetFgColour, "Set &foreground colour...")
    style_menu.append(TreeTest_SetBgColour, "Set &background colour...")
    style_menu.append_separator()
    style_menu.append(TreeTest_ResetStyle, "&Reset to default\tF10")

    tree_menu.append(TreeTest_Recreate, "&Recreate the tree")
    tree_menu.append(TreeTest_CollapseAndReset, "C&ollapse and reset")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_AddItem, "Append a &new item")
    tree_menu.append(TreeTest_InsertItem, "&Insert a new item")
    tree_menu.append(TreeTest_Delete, "&Delete selected  item")
    tree_menu.append(TreeTest_DeleteChildren, "Delete &children")
    tree_menu.append(TreeTest_DeleteAll, "Delete &all items")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_Count, "Count children of current item")
    tree_menu.append(TreeTest_CountRec, "Recursively count children of current item")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_Sort, "Sort children")
    tree_menu.append(TreeTest_SortRev, "Reverse sort children")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_EnsureVisible, "Make the last item &visible")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_IncIndent, "Increase indentation\tAlt-I")
    tree_menu.append(TreeTest_DecIndent, "Reduce indentation\tAlt-R")
    tree_menu.append_separator()
    tree_menu.append(TreeTest_IncSpacing, "Increase spacing\tCtrl-I")
    tree_menu.append(TreeTest_DecSpacing, "Reduce spacing\tCtrl-R")

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

    menu_bar = Wx::MenuBar.new
    menu_bar.append(file_menu, "&File")
    menu_bar.append(style_menu, "&Style")
    menu_bar.append(tree_menu, "&Tree")
    menu_bar.append(item_menu, "&Item")
    set_menu_bar(menu_bar)


    # create the controls
    @textctrl = Wx::TextCtrl.new(self, -1, "",
                             Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
                             Wx::TE_MULTILINE|Wx::SUNKEN_BORDER)

    create_tree_with_default_style()

    menu_bar.check(TreeTest_ToggleImages, true)

    # create a status bar with 3 panes
    create_status_bar(3)
    set_status_text("", 0)

    # set our text control as the log target
    logWindow = Wx::LogTextCtrl.new(@textctrl)
    Wx::Log::set_active_target(logWindow)

    evt_size {|event| on_size(event) }

    evt_menu(Wx::ID_EXIT) {|event| on_quit(event) }
    evt_menu(Wx::ID_ABOUT) {|event| on_about(event) }

    evt_menu(TreeTest_TogButtons) {|event| on_tog_buttons(event) }
    evt_menu(TreeTest_TogTwist) {|event| on_tog_twist(event) }
    evt_menu(TreeTest_TogLines) {|event| on_tog_lines(event) }
    evt_menu(TreeTest_TogEdit) {|event| on_tog_edit(event) }
    evt_menu(TreeTest_TogHideRoot) {|event| on_tog_hide_root(event) }
    evt_menu(TreeTest_TogRootLines) {|event| on_tog_root_lines(event) }
    evt_menu(TreeTest_TogBorder) {|event| on_tog_border(event) }
    evt_menu(TreeTest_TogFullHighlight) {|event| on_tog_full_highlight(event) }
    evt_menu(TreeTest_SetFgColour) {|event| on_set_fg_colour(event) }
    evt_menu(TreeTest_SetBgColour) {|event| on_set_bg_colour(event) }
    evt_menu(TreeTest_ResetStyle) {|event| on_reset_style(event) }

    evt_menu(TreeTest_Dump) {|event| on_dump(event) }
    evt_menu(TreeTest_DumpSelected) {|event| on_dump_selected(event) }
    evt_menu(TreeTest_Select) {|event| on_select(event) }
    evt_menu(TreeTest_Unselect) {|event| on_unselect(event) }
    evt_menu(TreeTest_ToggleSel) {|event| on_toggle_sel(event) }
    evt_menu(TreeTest_Rename) {|event| on_rename(event) }
    evt_menu(TreeTest_Count) {|event| on_count(event) }
    evt_menu(TreeTest_CountRec) {|event| on_count_rec(event) }
    evt_menu(TreeTest_Sort) {|event| on_sort(event) }
    evt_menu(TreeTest_SortRev) {|event| on_sort_rev(event) }
    evt_menu(TreeTest_SetBold) {|event| on_set_bold(event) }
    evt_menu(TreeTest_ClearBold) {|event| on_clear_bold(event) }
    evt_menu(TreeTest_Delete) {|event| on_delete(event) }
    evt_menu(TreeTest_DeleteChildren) {|event| on_delete_children(event) }
    evt_menu(TreeTest_DeleteAll) {|event| on_delete_all(event) }
    evt_menu(TreeTest_Recreate) {|event| on_recreate(event) }
    evt_menu(TreeTest_ToggleImages) {|event| on_toggle_images(event) }
    evt_menu(TreeTest_ToggleButtons) {|event| on_toggle_buttons(event) }
    evt_menu(TreeTest_SetImageSize) {|event| on_set_image_size(event) }
    evt_menu(TreeTest_CollapseAndReset) {|event| on_collapse_and_reset(event) }
    evt_menu(TreeTest_EnsureVisible) {|event| on_ensure_visible(event) }
    evt_menu(TreeTest_AddItem) {|event| on_add_item(event) }
    evt_menu(TreeTest_InsertItem) {|event| on_insert_item(event) }
    evt_menu(TreeTest_IncIndent) {|event| on_inc_indent(event) }
    evt_menu(TreeTest_DecIndent) {|event| on_dec_indent(event) }
    evt_menu(TreeTest_IncSpacing) {|event| on_inc_spacing(event) }
    evt_menu(TreeTest_DecSpacing) {|event| on_dec_spacing(event) }
    evt_menu(TreeTest_ToggleIcon) {|event| on_toggle_icon(event) }

    evt_close {|event| on_close(event) }
  end

  def create_tree_with_default_style()

    style = Wx::TR_DEFAULT_STYLE|Wx::TR_EDIT_LABELS|
            Wx::TR_TWIST_BUTTONS|Wx::TR_ROW_LINES|Wx::TR_FULL_ROW_HIGHLIGHT

    create_tree(style|Wx::SUNKEN_BORDER)

    # as we don't know what Wx::TR_DEFAULT_STYLE could contain, test for
    # everything
    mbar = get_menu_bar()
    mbar.check(TreeTest_TogButtons, (style & Wx::TR_HAS_BUTTONS) != 0)
    mbar.check(TreeTest_TogButtons, (style & Wx::TR_TWIST_BUTTONS) != 0)
    mbar.check(TreeTest_TogLines, (style & Wx::TR_NO_LINES) == 0)
    mbar.check(TreeTest_TogRootLines, (style & Wx::TR_LINES_AT_ROOT) != 0)
    mbar.check(TreeTest_TogHideRoot, (style & Wx::TR_HIDE_ROOT) != 0)
    mbar.check(TreeTest_TogEdit, (style & Wx::TR_EDIT_LABELS) != 0)
    mbar.check(TreeTest_TogBorder, (style & Wx::TR_ROW_LINES) != 0)
    mbar.check(TreeTest_TogFullHighlight, (style & Wx::TR_FULL_ROW_HIGHLIGHT) != 0)
  end

  def create_tree(style)
    @treectrl = MyTreeCtrl.new(self, TreeTest_Ctrl,
                               Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
                               style)
    resize()
  end

  def tog_style(id,flag)

    style = @treectrl.get_window_style_flag() ^ flag

    # most treectrl styles can't be changed on the fly using the native
    # control and the tree must be recreated
    @treectrl.destroy
    create_tree(style)
    get_menu_bar().check(id, (style & flag) != 0)
  end

  def on_tog_buttons(event)
    tog_style(event.get_id(), Wx::TR_HAS_BUTTONS)
  end

  def on_tog_twist(event)
    tog_style(event.get_id(), Wx::TR_TWIST_BUTTONS)
  end

  def on_tog_lines(event)
    tog_style(event.get_id(), Wx::TR_NO_LINES)
  end

  def on_tog_edit(event)
    tog_style(event.get_id(), Wx::TR_EDIT_LABELS)
  end

  def on_tog_hide_root(event)
    tog_style(event.get_id(), Wx::TR_HIDE_ROOT)
  end

  def on_tog_root_lines(event)
    tog_style(event.get_id(), Wx::TR_LINES_AT_ROOT)
  end

  def on_tog_border(event)
    tog_style(event.get_id(), Wx::TR_ROW_LINES)
  end

  def on_tog_full_highlight(event)
    tog_style(event.get_id(), Wx::TR_FULL_ROW_HIGHLIGHT)
  end

  def on_reset_style(event)
    create_tree_with_default_style()
  end

  def on_set_bold(event)
    do_set_bold(true)
  end

  def on_clear_bold(event)
    do_set_bold(false)
  end

  def on_sort(event)
    do_sort()
  end

  def on_sort_rev(event)
    do_sort(true)
  end

  def on_size(event)
    if @treectrl && @textctrl
      resize()
    end

    event.skip()
  end

  def resize()
    my_size = get_client_size()
    tree_size = Wx::Size.new(my_size.x, 2*my_size.y/3)
    @treectrl.set_size( tree_size )
    @textctrl.set_dimensions(0, 2*my_size.y/3, my_size.x, my_size.y/3)
  end

  def on_close(event)
    Wx::Log::set_active_target(nil)
    destroy()
  end

  def on_quit(event)
    close(true)
  end

  def on_about(event)
    message_box("Tree test sample\n" +
                                      "(c) Julian Smart 1997, Vadim Zeitlin 1998",
                "About tree test",
                Wx::OK|Wx::ICON_INFORMATION, self)
  end

  def check_item(item)
    unless item.is_ok
      message_box("Please select some item first!",
                  "Tree sample error",
                  Wx::OK|Wx::ICON_EXCLAMATION, self)
      return false
    end
    true
  end

  def on_rename(event)
    item = @treectrl.get_selection()

    return nil unless check_item( item )

    # TODO demonstrate creating a custom edit control...
    @treectrl.edit_label(item)
  end

  def on_count(event)
    item = @treectrl.get_selection()

    return nil unless check_item( item )

    i = @treectrl.get_children_count( item, false )

    Wx::log_message("%d children", i)
  end

  def on_count_rec(event)
    item = @treectrl.get_selection()
    return nil unless check_item( item )
    Wx::log_message("%d children", @treectrl.get_children_count( item ))
  end

  def do_sort(reverse = false)
    item = @treectrl.get_selection()
    return nil unless check_item( item )
    @treectrl.do_sort_children(item, reverse)
  end

  def on_dump(event)
    root = @treectrl.get_selection()

    return nil unless check_item( root )

    @treectrl.get_items_recursively(root, -1)
  end

  def on_toggle_sel(event)
    tog_style(event.get_id(), Wx::TR_MULTIPLE)
  end

  def on_dump_selected(event)
    if ( @treectrl.get_window_style & Wx::TR_MULTIPLE ) == 0
      item_id = @treectrl.get_selection
      if item_id.is_ok
        Wx::log_message("<TreeItem '%s'>", 
                        @treectrl.get_item_text(item_id))
      else
        Wx::log_message("No tree item selected")
      end
    else
      Wx::log_message("NOT IMPLEMENTED: Multiple selections not available")
      # Requires Wx::List - Ruby Array typemap, pointer handling, 29/08/2006
      # Currently raises incorrect number of args, 1 for 0
      # selected = @treectrl.get_selections()
      # selected_items.each do | item_id |
      #   Wx::log_message("\t%s", @treectrl.get_item_text(item_id))
      # end
    end
  end

  def on_select(event)
    @treectrl.select_item(@treectrl.get_selection())
  end

  def on_unselect(event)
    @treectrl.unselect_all()
  end

  def do_set_bold(bold = true)
    item = @treectrl.get_selection()

    return nil unless check_item( item )

    @treectrl.set_item_bold(item, bold)
  end

  def on_delete(event)
    item = @treectrl.get_selection()

    return nil unless check_item( item )

    @treectrl.delete(item)
  end

  def on_delete_children(event)
    item = @treectrl.get_selection()

    return nil unless check_item( item )

    @treectrl.delete_children(item)
  end

  def on_delete_all(event)
    @treectrl.delete_all_items()
  end

  def on_recreate(event)
    on_delete_all(event)
    @treectrl.add_test_items_to_tree(5, 2)
  end

  def on_set_image_size(event)
    size = get_number_from_user("Enter the size for the images to use",
                                "Size: ",
                                "TreeCtrl sample",
                                @treectrl.image_size())
    if size == -1
      return nil
    end

    @treectrl.create_image_list(size)
    Wx::get_app.show_images = true
  end

  def on_toggle_images(event)
    if Wx::get_app.show_images()
      @treectrl.create_image_list(-1)
      Wx::get_app.show_images = false
    else
      @treectrl.create_image_list(0)
      Wx::get_app.show_images = true
    end
  end

  def on_toggle_buttons(event)
  end

  def on_collapse_and_reset(event)
    @treectrl.collapse_and_reset(@treectrl.get_root_item())
  end

  def on_ensure_visible(event)
    @treectrl.do_ensure_visible()
  end

  def on_insert_item(event)
    image = Wx::get_app.show_images() ? TreeCtrlIcon_File : -1
    @treectrl.insert_item(@treectrl.get_root_item(), image, "2nd item")
  end

  def on_add_item(event)
    @s_num += 1
    text = sprintf("Item #%d", @s_num)
    @treectrl.append_item(@treectrl.get_root_item(), text)
  end

  def on_inc_indent(event)
    indent = @treectrl.get_indent()
    if indent < 100
      @treectrl.set_indent( indent+5 )
    end
  end

  def on_dec_indent(event)
    indent = @treectrl.get_indent()
    if indent > 10
      @treectrl.set_indent( indent-5 )
    end
  end

  def on_inc_spacing(event)
    indent = @treectrl.get_spacing()
    if indent < 100
      @treectrl.set_spacing( indent+5 )
    end
  end

  def on_dec_spacing(event)
    indent = @treectrl.get_spacing()
    if indent > 10
      @treectrl.set_spacing( indent-5 )
    end
  end

  def on_toggle_icon(event)
    item = @treectrl.get_selection()
    return nil unless check_item( item )
    @treectrl.do_toggle_icon(item)
  end

  # TODO
  def on_set_fg_colour(event)
    Wx::log_message('NOT IMPLEMENTED')
    return
    col = Wx::get_colour_from_user(self, @treectrl.get_foreground_colour())
    if col.ok()
      @treectrl.set_foreground_colour(col)
    end
  end

  # TODO
  def on_set_bg_colour(event)
    Wx::log_message('NOT IMPLEMENTED')
    return
    col = Wx::get_colour_from_user(self, @treectrl.get_background_colour())
    if col.ok()
      @treectrl.set_background_colour(col)
    end
  end

end

class MyApp < Wx::App
  attr_accessor :show_images, :show_buttons
  def initialize
    self.show_images = true
    self.show_buttons = false
    super
  end
  
  def on_init
    # Create the main frame window
    frame = MyFrame.new("TreeCtrl Test", 50, 50, 450, 600)

    # show the frame
    frame.show(true)
    # set_top_window(frame)

  end
end

a = MyApp.new
a.main_loop()
