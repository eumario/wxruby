require 'wxruby'
include Wx


# IDs for the controls and the menu commands
ID_Quit = ID_HIGHEST
ID_Logs = ID_HIGHEST + 1
ID_Browser = ID_HIGHEST + 2
ID_PlugProvider = ID_HIGHEST + 3

$clients = 
{
    ART_OTHER => "ART_OTHER",
    ART_TOOLBAR => "ART_TOOLBAR",
    ART_MENU => "ART_MENU",
    ART_FRAME_ICON => "ART_FRAME_ICON",
    ART_CMN_DIALOG => "ART_CMN_DIALOG",
    ART_HELP_BROWSER => "ART_HELP_BROWSER",
    ART_MESSAGE_BOX => "ART_MESSAGE_BOX",
}

def FillClients(choice)
    $clients.each_key do | key |
        choice.append($clients[key],key)
    end
end

def FillBitmaps(images,list,index,client,size)
    icon = ArtProvider::get_icon(ART_ERROR, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_ERROR",ind)
    list.set_item_data(index,ART_ERROR)
    index += 1

    icon = ArtProvider::get_icon(ART_QUESTION, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_QUESTION",ind)
    list.set_item_data(index,ART_QUESTION)
    index += 1

    icon = ArtProvider::get_icon(ART_WARNING, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_WARNING",ind)
    list.set_item_data(index,ART_WARNING)
    index += 1

    icon = ArtProvider::get_icon(ART_INFORMATION, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_INFORMATION",ind)
    list.set_item_data(index,ART_INFORMATION)
    index += 1

    icon = ArtProvider::get_icon(ART_ADD_BOOKMARK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_ADD_BOOKMARK",ind)
    list.set_item_data(index,ART_ADD_BOOKMARK)
    index += 1

    icon = ArtProvider::get_icon(ART_DEL_BOOKMARK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_DEL_BOOKMARK",ind)
    list.set_item_data(index,ART_DEL_BOOKMARK)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP_SIDE_PANEL, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP_SIDE_PANEL",ind)
    list.set_item_data(index,ART_HELP_SIDE_PANEL)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP_SETTINGS, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP_SETTINGS",ind)
    list.set_item_data(index,ART_HELP_SETTINGS)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP_BOOK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP_BOOK",ind)
    list.set_item_data(index,ART_HELP_BOOK)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP_FOLDER, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP_FOLDER",ind)
    list.set_item_data(index,ART_HELP_FOLDER)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP_PAGE, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP_PAGE",ind)
    list.set_item_data(index,ART_HELP_PAGE)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_BACK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_BACK",ind)
    list.set_item_data(index,ART_GO_BACK)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_FORWARD, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_FORWARD",ind)
    list.set_item_data(index,ART_GO_FORWARD)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_UP, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_UP",ind)
    list.set_item_data(index,ART_GO_UP)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_DOWN, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_DOWN",ind)
    list.set_item_data(index,ART_GO_DOWN)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_TO_PARENT, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_TO_PARENT",ind)
    list.set_item_data(index,ART_GO_TO_PARENT)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_HOME, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_HOME",ind)
    list.set_item_data(index,ART_GO_HOME)
    index += 1

    icon = ArtProvider::get_icon(ART_FILE_OPEN, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_FILE_OPEN",ind)
    list.set_item_data(index,ART_FILE_OPEN)
    index += 1

    icon = ArtProvider::get_icon(ART_PRINT, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_PRINT",ind)
    list.set_item_data(index,ART_PRINT)
    index += 1

    icon = ArtProvider::get_icon(ART_HELP, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_HELP",ind)
    list.set_item_data(index,ART_HELP)
    index += 1

    icon = ArtProvider::get_icon(ART_TIP, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_TIP",ind)
    list.set_item_data(index,ART_TIP)
    index += 1

    icon = ArtProvider::get_icon(ART_REPORT_VIEW, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_REPORT_VIEW",ind)
    list.set_item_data(index,ART_REPORT_VIEW)
    index += 1

    icon = ArtProvider::get_icon(ART_LIST_VIEW, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_LIST_VIEW",ind)
    list.set_item_data(index,ART_LIST_VIEW)
    index += 1

    icon = ArtProvider::get_icon(ART_NEW_DIR, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_NEW_DIR",ind)
    list.set_item_data(index,ART_NEW_DIR)
    index += 1

    icon = ArtProvider::get_icon(ART_FOLDER, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_FOLDER",ind)
    list.set_item_data(index,ART_FOLDER)
    index += 1

    icon = ArtProvider::get_icon(ART_GO_DIR_UP, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_GO_DIR_UP",ind)
    list.set_item_data(index,ART_GO_DIR_UP)
    index += 1

    icon = ArtProvider::get_icon(ART_EXECUTABLE_FILE, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_EXECUTABLE_FILE",ind)
    list.set_item_data(index,ART_EXECUTABLE_FILE)
    index += 1

    icon = ArtProvider::get_icon(ART_NORMAL_FILE, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_NORMAL_FILE",ind)
    list.set_item_data(index,ART_NORMAL_FILE)
    index += 1

    icon = ArtProvider::get_icon(ART_TICK_MARK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_TICK_MARK",ind)
    list.set_item_data(index,ART_TICK_MARK)
    index += 1

    icon = ArtProvider::get_icon(ART_CROSS_MARK, client, size)
    ind = icon.ok ? images.add_icon(icon) : 0
    list.insert_item(index,"ART_CROSS_MARK",ind)
    list.set_item_data(index,ART_CROSS_MARK)
    index += 1

end

class ArtBrowserDialog < Dialog

  def initialize(parent)
    super(parent, -1, "Art resources browser",
               DEFAULT_POSITION, DEFAULT_SIZE,
               DEFAULT_DIALOG_STYLE|RESIZE_BORDER)
    sizer = BoxSizer.new(VERTICAL)

    choice = Choice.new(self, -1)
    FillClients(choice)

    subsizer = BoxSizer.new(HORIZONTAL)
    subsizer.add(StaticText.new(self, -1, "Client:"), 0, ALIGN_CENTER_VERTICAL)
    subsizer.add(choice, 1, WEST, 5)
    sizer.add(subsizer, 0, ALL | EXPAND, 10)

    subsizer = BoxSizer.new(HORIZONTAL)

    @m_list = ListCtrl.new(self, -1, DEFAULT_POSITION, Size.new(250, 300),
                            LC_REPORT | SUNKEN_BORDER)
    @m_list.insert_column(0, "ArtID")
    subsizer.add(@m_list, 1, EXPAND | WEST, 10)

    subsub = BoxSizer.new(VERTICAL)
    @m_canvas = StaticBitmap.new(self, -1, Bitmap.new("null.xpm"))
    subsub.add(@m_canvas)
    subsub.add(100, 100)
    subsizer.add(subsub)

    sizer.add(subsizer, 1, EXPAND | ALIGN_LEFT | EAST, 10)

    ok = Button.new(self, ID_OK, "Close")
    ok.set_default
    sizer.add(ok, 0, ALIGN_RIGHT | ALL, 10)

    set_sizer(sizer)
    set_auto_layout(TRUE)
    sizer.fit(self)

    choice.set_selection(6)
    SetArtClient(ART_MESSAGE_BOX)

    evt_list_item_selected(-1) {|event| onSelectItem(event)}
    evt_choice(-1) {|event| onChooseClient(event)}

  end

  def SetArtClient(client)
    img = ImageList.new(16, 16)
    img.add_icon(Icon.new("null.xpm"))
    index = 0

    @m_list.delete_all_items
    FillBitmaps(img, @m_list, index, client, Size.new(16, 16))
    @m_list.assign_image_list(img, IMAGE_LIST_SMALL)
    @m_list.set_column_width(0, LIST_AUTOSIZE)

    @m_client = client

  end

  def onSelectItem(event)
    data = event.get_data
    bmp = ArtProvider::get_bitmap(data, @m_client)
    @m_canvas.set_bitmap(bmp)
#    @m_canvas.set_size(bmp.get_width, bmp.get_height)
  end

  def onChooseClient(event)
    item = event.get_selection
    client_id = $clients.keys[item]
    SetArtClient(client_id)
  end

end

class MyApp < App
  def on_init()
    # create the main application window
    frame = MyFrame.new("ArtProvider sample",
                                 Point.new(50, 50), Size.new(450, 340))
    frame.show(TRUE)
  end
end

class MyFrame < Frame
  def initialize(title,pos,size,style = DEFAULT_FRAME_STYLE)
    super(nil, -1, title, pos, size, style)

    if RUBY_PLATFORM == "WXMSW"
      set_icon(Icon.new("mondrian.ico",BITMAP_TYPE_ICO))
    else
      set_icon(Icon.new("mondrian.xpm",BITMAP_TYPE_XPM))
    end

    # create a menu bar
    menuFile = Menu.new

    # the "About" item should be in the help menu
    helpMenu = Menu.new
    helpMenu.append(ID_ABOUT, "&About...\tF1", "Show about dialog")

    menuFile.append_check_item(ID_PlugProvider, "&Plug-in art provider", "Enable custom art provider")
    menuFile.append_separator

    menuFile.append(ID_Logs, "&Logging test", "Show some logging output")
    menuFile.append(ID_Browser, "&Resources browser", "Browse all available icons")
    menuFile.append_separator

    menuFile.append(ID_Quit, "E&xit\tAlt-X", "Quit this program")

    # now append the freshly created menu to the menu bar...
    menuBar = MenuBar.new
    menuBar.append(menuFile, "&File")
    menuBar.append(helpMenu, "&Help")

    # ... and attach this menu bar to the frame
    set_menu_bar(menuBar);

    evt_menu(ID_Quit) {onQuit}
    evt_menu(ID_Logs) {onLogs}
    evt_menu(ID_ABOUT) {onAbout}
    evt_menu(ID_Browser) {onBrowser}
    evt_menu(ID_PlugProvider) {|event| onPlugProvider(event)}
  end

  # event handlers (these functions should _not_ be virtual)
  def onQuit
    # TRUE is to force the frame to close
    close(TRUE)
  end

  def onAbout
    msg = sprintf( "This is the about dialog of ArtProvider sample.\n" \
                "Welcome to %s", VERSION_STRING)

    message_box(msg, "About ArtProvider sample",
        OK | ICON_INFORMATION, self)
  end

  def onLogs
    log_message("Some information.")
    log_error("This is an error.")
    log_warning("A warning.")
    log_error("Yet another error.")
    Log::get_active_target().flush
    log_message("Check/uncheck 'File/Plug-in art provider' and try again.")
  end

  def onBrowser
    dlg = ArtBrowserDialog.new(self)
    dlg.show_modal
  end

  def onPlugProvider(event)
    if event.is_checked
        ArtProvider::push_provider(MyArtProvider.new)
    else
        ArtProvider::pop_provider()
    end
  end

end

class MyArtProvider < ArtProvider
  def create_bitmap(id,client,size)
    if client == ART_MESSAGE_BOX
        if id == ART_INFORMATION
            return Bitmap.new("info.xpm")
        end
        if id == ART_ERROR
            return Bitmap.new("error.xpm")
        end
        if id == ART_WARNING
            return Bitmap.new("warning.xpm")
        end
        if id == ART_QUESTION
            return Bitmap.new("question.xpm")
        end
    end
    return NULL_BITMAP
  end
end

a = MyApp.new
a.main_loop
