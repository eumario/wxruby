#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
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
TreeTest_Unselect = (Wx::ID_HIGHEST..Wx::ID_HIGHEST+39).to_a

TreeCtrlIcon_File,
TreeCtrlIcon_FileSelected,
TreeCtrlIcon_Folder,
TreeCtrlIcon_FolderSelected,
TreeCtrlIcon_FolderOpened = 0,1,2,3,4

class MyTreeCtrl < Wx::TreeCtrl
  def initialize(parent, args)
    super

    @reverse_sort = false

    create_image_list

    # add some items to the tree
    add_test_items_to_tree(5, 2)

    # TreeCtrl supports a large number of different events...
    evt_tree_begin_drag self, :on_begin_drag
    evt_tree_begin_rdrag self, :on_begin_rdrag
    evt_tree_end_drag self, :on_end_drag
    evt_tree_begin_label_edit self, :on_begin_label_edit
    evt_tree_end_label_edit self, :on_end_label_edit
    evt_tree_delete_item self, :on_delete_item
    evt_tree_set_info self, :on_set_info
    evt_tree_item_expanded self, :on_item_expanded
    evt_tree_item_expanding self, :on_item_expanding
    evt_tree_item_collapsed self, :on_item_collapsed
    evt_tree_item_collapsing self, :on_item_collapsing
    evt_tree_item_menu self, :on_item_menu
    evt_tree_sel_changed self, :on_sel_changed
    evt_tree_sel_changing self, :on_sel_changing
    evt_tree_key_down self, :on_tree_key_down
    evt_tree_item_activated self, :on_item_activated

    evt_right_dclick :on_rmouse_dclick
    evt_right_up :on_rmouse_up
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
    return item_parent(item) == root_item && ! prev_sibling(item)
  end

  def create_image_list
    @imageSize = 16

    # Make an image list containing small icons
    images = Wx::ImageList.new(32, 32, true)
    # should correspond to TreeCtrlIcon_xxx enum
    Wx::BusyCursor.busy do
      icons = (1 .. 5).map do | i |
        icon_file = File.join(File.dirname(__FILE__), "icon#{i}.xpm")
        Wx::Bitmap.new(icon_file, Wx::BITMAP_TYPE_XPM)
      end
      icons.each { | ic | images.add(ic) }
      self.image_list = images
    end
  end

  def unset_image_list
    self.image_list = nil
  end

  def create_buttons_image_list()
    # Make an image list containing small icons
    images = Wx::ImageList.new(16, 16, true)

    # should correspond to TreeCtrlIcon_xxx enum
    Wx::BusyCursor.busy do |x|
      icons = [
        Wx::Icon.new("icon3.xpm"),   # closed
        Wx::Icon.new("icon3.xpm"),   # closed, selected
        Wx::Icon.new("icon5.xpm"),   # open
        Wx::Icon.new("icon5.xpm") ]   # open, selected
      
      icons.each do | ic |
        orig_size = ic.get_width()
        if size == orig_size
          images.add(ic)
        else
          resized = ic.convert_to_image.rescale(size, size)
          images.add( Wx::Bitmap.new(resized) )
        end
      end
      
      self.buttons_image_list = images
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
        if Wx::THE_APP.show_images
          image = depth == 1 ? TreeCtrlIcon_File : TreeCtrlIcon_Folder
          imageSel = image + 1
        else
          image = imageSel = -1
        end
        id = append_item(parent_id, str, image, imageSel)

        # and now we also set the expanded one (only for the folders)
        if has_children && Wx::get_app.show_images()
          set_item_image( id, TreeCtrlIcon_FolderOpened,
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
    image = Wx::THE_APP.show_images ? TreeCtrlIcon_Folder : -1
    root_id = add_root("Root",image, image)
    if image != -1
      set_item_image( root_id, TreeCtrlIcon_FolderOpened, 
                      Wx::TREE_ITEM_ICON_EXPANDED)
    end

    add_items_recursively(root_id, num_children, depth, 0)

    # set some colours/fonts for testing
    # note that font sizes can also be varied, but only on platforms
    # that use the generic TreeCtrl - OS X and GTK, and only if
    # Wx::TR_HAS_VARIABLE_ROW_HEIGHT style was used in the constructor
    font = get_font
    font.style = Wx::FONTSTYLE_ITALIC
    set_item_font(root_id, font)

    ids = get_children(root_id)

    # make the first item blue
    set_item_text_colour(ids[0], Wx::BLUE)

    # make the third item red on grey
    if Wx::PLATFORM == "WXMSW"
      set_item_text_colour(ids[2], Wx::RED)      
      set_item_background_colour(ids[2], Wx::LIGHT_GREY)
    end
  end

  def get_items_recursively(parent_id, cookie)
    if cookie == -1
      id, cookie = get_first_child(parent_id)
    else
      id, cookie = get_next_child(parent_id, cookie)
    end
    if not id.nonzero?
      return nil
    end

    text = item_text(id)
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
    event.skip
  end

  def on_delete_item(event)
    Wx::log_message("OnDeleteItem")
    event.skip
  end

  def on_get_info(event)
    Wx::log_message("OnGetInfo")
    event.skip
  end

  def on_set_info(event)
    Wx::log_message("OnSetInfo")
    event.skip
  end

  def on_item_expanded(event)
    Wx::log_message("OnItemExpanded")
    event.skip
  end

  def on_item_expanding(event)
    Wx::log_message("OnItemExpanding")
    event.skip
  end

  def on_item_collapsed(event)
    Wx::log_message("OnItemCollapsed")
    event.skip
  end

  def on_sel_changed(event)
    Wx::log_message("OnSelChanged")
    event.skip
  end

  def on_sel_changing(event)
    Wx::log_message("OnSelChanging")
    event.skip
  end

  def log_key_event(name,event)
    keycode = event.key_code

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
    log_key_event("Tree key down ", event.key_event )
    event.skip
  end

  def on_begin_drag(event)
    # need to explicitly allow drag
    if event.item != root_item()
      @dragged_item = event.item
      Wx::log_message( "OnBeginDrag: started dragging %s",
                       item_text(@dragged_item))
      event.allow
    else
      Wx::log_message("OnBeginDrag: selected item can't be dragged.")
    end
  end

  def on_end_drag(event)
    src_item = @dragged_item
    dest_item = event.item
    @dragged_item = 0

    if dest_item.nonzero? && ! item_has_children(dest_item)
      # copy to the parent then
      dest_item = item_parent(dest_item)
    end

    unless dest_item.nonzero?()
      Wx::log_message("OnEndDrag: can't drop here.")
      return nil
    end

    text = item_text(src_item)
    Wx::log_message("OnEndDrag: '%s' copied to '%s'.",
                     text, item_text(dest_item))

    # just do append here - we could also insert it just before/after the item
    # on which it was dropped, but self requires slightly more work... we also
    # completely ignore the client data and icon of the old item but could
    # copy them as well.
    #
    # Finally, we only copy one item here but we might copy the entire tree if
    # we were dragging a folder.
    image = Wx::THE_APP.show_images() ? TreeCtrlIcon_File : -1
    append_item(dest_item, text, image)
  end

  def on_begin_label_edit(event)
    Wx::log_message("OnBeginLabelEdit")

    # for testing, prevent self item's label editing
    if is_test_item(event.item)
      Wx::message_box("The demo prevents you editing this item.")
      event.veto()
    end
  end

  def on_end_label_edit(event)
    Wx::log_message("OnEndLabelEdit")
    if event.edit_cancelled?
      Wx::log_message("Label edit was cancelled by user")
      return
    end

    # For a demo, don't allow anything except letters in the labels
    if event.label =~ /[^\w.]/
      msg = "Only letters, numbers and full stops are allowed in the label."
      Wx::message_box(msg)
      Wx::log_message("Label edit was cancelled by demo")
      event.veto
    end
  end

  def on_item_collapsing(event)
    Wx::log_message("OnItemCollapsing")

    # for testing, prevent the user from collapsing the first child folder
    if is_test_item(event.item)
      Wx::message_box("You can't collapse self item.")
      event.veto
    end
  end

  # show some info about activated item
  def on_item_activated(event)
    if item_id  = event.item
      show_info(item_id)
    end
    Wx::log_message("OnItemActivated")
  end

  def on_item_menu(event)
    show_popup_menu(event.item, event.point)
  end

  def on_rmouse_up(event)
    pos  = event.position
    item = hit_test(pos)
    show_popup_menu(item, pos)
  end

  def show_popup_menu(id, pos)
    title = ""
    if id.nonzero?
      title << "Menu for " << item_text(id)
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
    super( nil, :title => title, :pos => [ x, y ], :size => [ w, h ] )
    @splitter = nil
    @treectrl = nil
    @textctrl = nil
    @s_num = 0

    # This reduces flicker effects - even better would be to define
    # OnEraseBackground to do nothing. When the tree control's scrollbars are
    # show or hidden, the frame is sent a background erase event.
    self.background_colour = Wx::WHITE

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
    self.menu_bar = menu_bar

    @splitter = Wx::SplitterWindow.new(self, :style => Wx::SP_BORDER)
    @splitter.minimum_pane_size = 100

    # create the controls
    @textctrl = Wx::TextCtrl.new( @splitter, 
                                  :text => '', 
                                  :style => Wx::TE_MULTILINE|Wx::SUNKEN_BORDER)

    create_tree_with_default_style()

    menu_bar.check(TreeTest_ToggleImages, true)

    # create a status bar with 3 panes
    create_status_bar(3)
    set_status_text("", 0)

    # set our text control as the log target
    logWindow = Wx::LogTextCtrl.new(@textctrl)
    Wx::Log::active_target = logWindow
    
    @splitter.split_horizontally(@treectrl, @textctrl, 500)

    evt_close :on_close

    evt_menu Wx::ID_EXIT, :on_quit
    evt_menu Wx::ID_ABOUT, :on_about

    evt_menu TreeTest_TogButtons, :on_tog_buttons
    evt_menu TreeTest_TogTwist, :on_tog_twist
    evt_menu TreeTest_TogLines, :on_tog_lines
    evt_menu TreeTest_TogEdit, :on_tog_edit
    evt_menu TreeTest_TogHideRoot, :on_tog_hide_root
    evt_menu TreeTest_TogRootLines, :on_tog_root_lines
    evt_menu TreeTest_TogBorder, :on_tog_border
    evt_menu TreeTest_TogFullHighlight, :on_tog_full_highlight
    evt_menu TreeTest_SetFgColour, :on_set_fg_colour
    evt_menu TreeTest_SetBgColour, :on_set_bg_colour
    evt_menu TreeTest_ResetStyle, :on_reset_style

    evt_menu TreeTest_Dump, :on_dump
    evt_menu TreeTest_DumpSelected, :on_dump_selected
    evt_menu TreeTest_Select, :on_select
    evt_menu TreeTest_Unselect, :on_unselect
    evt_menu TreeTest_ToggleSel, :on_toggle_sel
    evt_menu TreeTest_Rename, :on_rename
    evt_menu TreeTest_Count, :on_count
    evt_menu TreeTest_CountRec, :on_count_rec
    evt_menu TreeTest_Sort, :on_sort
    evt_menu TreeTest_SortRev, :on_sort_rev
    evt_menu TreeTest_SetBold, :on_set_bold
    evt_menu TreeTest_ClearBold, :on_clear_bold
    evt_menu TreeTest_Delete, :on_delete
    evt_menu TreeTest_DeleteChildren, :on_delete_children
    evt_menu TreeTest_DeleteAll, :on_delete_all
    evt_menu TreeTest_Recreate, :on_recreate
    evt_menu TreeTest_ToggleImages, :on_toggle_images
    evt_menu TreeTest_ToggleButtons, :on_toggle_buttons
    evt_menu TreeTest_SetImageSize, :on_set_image_size
    evt_menu TreeTest_CollapseAndReset, :on_collapse_and_reset
    evt_menu TreeTest_EnsureVisible, :on_ensure_visible
    evt_menu TreeTest_AddItem, :on_add_item
    evt_menu TreeTest_InsertItem, :on_insert_item
    evt_menu TreeTest_IncIndent, :on_inc_indent
    evt_menu TreeTest_DecIndent, :on_dec_indent
    evt_menu TreeTest_IncSpacing, :on_inc_spacing
    evt_menu TreeTest_DecSpacing, :on_dec_spacing
    evt_menu TreeTest_ToggleIcon, :on_toggle_icon
  end

  def create_tree_with_default_style()

    style = Wx::TR_DEFAULT_STYLE|Wx::TR_EDIT_LABELS|
            Wx::TR_TWIST_BUTTONS|Wx::TR_ROW_LINES|Wx::TR_FULL_ROW_HIGHLIGHT

    create_tree(style|Wx::SUNKEN_BORDER)

    # as we don't know what Wx::TR_DEFAULT_STYLE could contain, test for
    # everything
    mbar = menu_bar
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
    @treectrl = MyTreeCtrl.new(@splitter, :style => style)
  end

  def tog_style(id,flag)
    style = @treectrl.window_style_flag ^ flag

    # most treectrl styles can't be changed on the fly using the native
    # control and the tree must be recreated
    old_tree = @treectrl
    create_tree(style)
    @splitter.replace_window old_tree, @treectrl
    old_tree.destroy
    menu_bar.check(id, (style & flag) != 0)
  end

  def on_tog_buttons(event)
    tog_style(event.id, Wx::TR_HAS_BUTTONS)
  end

  def on_tog_twist(event)
    tog_style(event.id, Wx::TR_TWIST_BUTTONS)
  end

  def on_tog_lines(event)
    tog_style(event.id, Wx::TR_NO_LINES)
  end

  def on_tog_edit(event)
    tog_style(event.id, Wx::TR_EDIT_LABELS)
  end

  def on_tog_hide_root(event)
    tog_style(event.id, Wx::TR_HIDE_ROOT)
  end

  def on_tog_root_lines(event)
    tog_style(event.id, Wx::TR_LINES_AT_ROOT)
  end

  def on_tog_border(event)
    tog_style(event.id, Wx::TR_ROW_LINES)
  end

  def on_tog_full_highlight(event)
    tog_style(event.id, Wx::TR_FULL_ROW_HIGHLIGHT)
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
    do_sort
  end

  def on_sort_rev(event)
    do_sort(true)
  end

  def on_close(event)
    Wx::Log::active_target = nil
    destroy
  end

  def on_quit(event)
    close(true)
  end

  def on_about(event)
    Wx::message_box( "Tree test sample\n" +
                     "(c) Julian Smart 1997, Vadim Zeitlin 1998",
                     "About tree test",
                     Wx::OK|Wx::ICON_INFORMATION, self)
  end

  def check_item(item)
    unless item.nonzero?
      Wx::message_box("Please select some item first!",
                  "Tree sample error",
                  Wx::OK|Wx::ICON_EXCLAMATION, self)
      return false
    end
    true
  end

  def on_rename(event)
    item = @treectrl.selection
    return nil unless check_item( item )
    # TODO demonstrate creating a custom edit control...
    @treectrl.edit_label(item)
  end

  def on_count(event)
    item = @treectrl.selection
    return nil unless check_item( item )
    i = @treectrl.children_count( item, false )
    Wx::log_message("%d children", i)
  end

  def on_count_rec(event)
    item = @treectrl.selection
    return nil unless check_item( item )
    Wx::log_message("%d children", @treectrl.children_count( item ))
  end

  def do_sort(reverse = false)
    item = @treectrl.selection
    return nil unless check_item( item )
    @treectrl.do_sort_children(item, reverse)
  end

  def on_dump(event)
    root = @treectrl.selection
    return nil unless check_item( root )
    @treectrl.get_items_recursively(root, -1)
  end

  def on_toggle_sel(event)
    tog_style(event.id, Wx::TR_MULTIPLE)
  end

  def on_dump_selected(event)
    if ( @treectrl.window_style & Wx::TR_MULTIPLE ) == 0
      item_id = @treectrl.selection
      if item_id.nonzero?
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
    @treectrl.select_item(@treectrl.selection)
  end

  def on_unselect(event)
    @treectrl.unselect_all()
  end

  def do_set_bold(bold = true)
    item = @treectrl.selection
    return nil unless check_item( item )
    @treectrl.set_item_bold(item, bold)
  end

  def on_delete(event)
    item = @treectrl.selection
    return nil unless check_item( item )
    @treectrl.delete(item)
  end

  def on_delete_children(event)
    item = @treectrl.selection
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
    Wx::THE_APP.show_images = true
  end

  def on_toggle_images(event)
    if Wx::get_app.show_images
      @treectrl.unset_image_list
      Wx::get_app.show_images = false
    else
      @treectrl.create_image_list
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
    image = Wx::THE_APP.show_images() ? TreeCtrlIcon_File : -1
    @treectrl.insert_item(@treectrl.root_item, -1, "2nd item", image)
  end

  def on_add_item(event)
    @s_num += 1
    text = sprintf("Item #%d", @s_num)
    @treectrl.append_item(@treectrl.root_item, text)
  end

  def on_inc_indent(event)
    if @treectrl.indent < 100
      @treectrl.indent += 5
    end
  end

  def on_dec_indent(event)
    if @treectrl.indent > 10
      @treectrl.indent -= 5
    end
  end

  def on_inc_spacing(event)
    if @treectrl.spacing < 100
      @treectrl.spacing += 5
    end
  end

  def on_dec_spacing(event)
    if @treectrl.spacing > 10
      @treectrl.spacing -= 5
    end
  end

  def on_toggle_icon(event)
    item = @treectrl.selection
    return nil unless check_item( item )
    @treectrl.do_toggle_icon(item)
  end

  # TODO
  def on_set_fg_colour(event)
    Wx::log_message('NOT IMPLEMENTED')
    return
    col = Wx::get_colour_from_user(self, @treectrl.foreground_colour)
    if col.ok?
      @treectrl.foreground_colour = col
    end
  end

  # TODO
  def on_set_bg_colour(event)
    Wx::log_message('NOT IMPLEMENTED')
    return
    col = Wx::get_colour_from_user(self, @treectrl.background_colour)
    if col.ok?
      @treectrl.background_colour = col
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

app = MyApp.new
app.main_loop
