require 'wx'
include Wx

DIALOGS_CHOOSE_COLOUR = 1
DIALOGS_CHOOSE_COLOUR_GENERIC = 2
DIALOGS_CHOOSE_FONT = 3
DIALOGS_CHOOSE_FONT_GENERIC = 4
DIALOGS_MESSAGE_BOX = 5
DIALOGS_SINGLE_CHOICE = 6
DIALOGS_MULTI_CHOICE = 7
DIALOGS_TEXT_ENTRY = 8
DIALOGS_PASSWORD_ENTRY = 9
DIALOGS_FILE_OPEN = 10
DIALOGS_FILE_OPEN2 = 11
DIALOGS_FILES_OPEN = 12
DIALOGS_FILE_SAVE = 13
DIALOGS_DIR_CHOOSE = 14
DIALOGS_GENERIC_DIR_CHOOSE = 15
DIALOGS_TIP = 16
DIALOGS_NUM_ENTRY = 17
DIALOGS_LOG_DIALOG = 18
DIALOGS_MODAL = 19
DIALOGS_MODELESS = 20
DIALOGS_MODELESS_BTN = 21
DIALOGS_PROGRESS = 22
DIALOGS_BUSYINFO = 23
DIALOGS_FIND = 24
DIALOGS_REPLACE = 25

$myCanvas = nil

class MyModalDialog < Dialog
  def initialize(parent)
    super(parent, -1, "Modal dialog")

    sizerTop = BoxSizer.new(HORIZONTAL)

    @m_btnFocused = Button.new(self, -1, "Default button")
    @m_btnDelete = Button.new(self, -1, "&Delete button")
    btnOk = Button.new(self, ID_CANCEL, "&Close")
    sizerTop.add(@m_btnFocused, 0, ALIGN_CENTER | ALL, 5)
    sizerTop.add(@m_btnDelete, 0, ALIGN_CENTER | ALL, 5)
    sizerTop.add(btnOk, 0, ALIGN_CENTER | ALL, 5)

    set_auto_layout(TRUE)
    set_sizer(sizerTop)

    sizerTop.set_size_hints(self)
    sizerTop.fit(self)

    @m_btnFocused.set_focus()
    @m_btnFocused.set_default()

    evt_button(-1) {|event| onButton(event) }
  end

  def onButton(event)
    id = event.get_id
    
    if id == @m_btnDelete.get_id
      @m_btnFocused.destroy
      @m_btnFocused = nil

      @m_btnDelete.disable()
    elsif @m_btnFocused && id == @m_btnFocused.get_id
      get_text_from_user("Dummy prompt", "Modal dialog called from dialog",
                         "", self)
    else
      event.skip()
    end
  end
end


class MyModelessDialog < Dialog
  def initialize(parent)
    super(parent, -1, "Modeless dialog")

    sizerTop = BoxSizer.new(VERTICAL)

    btn = Button.new(self, DIALOGS_MODELESS_BTN, "Press me")
    check = CheckBox.new(self, -1, "Should be disabled")
    check.disable()

    sizerTop.add(btn, 1, EXPAND | ALL, 5)
    sizerTop.add(check, 1, EXPAND | ALL, 5)

    set_auto_layout(TRUE)
    set_sizer(sizerTop)

    sizerTop.set_size_hints(self)
    sizerTop.fit(self)

    evt_button(DIALOGS_MODELESS_BTN) {|event| onButton(event) }

    evt_close() {|event| onClose(event) }

  end

  def onButton(event)
    message_box("Button pressed in modeless dialog", "Info",
                OK | ICON_INFORMATION, self)
  end

  def onClose(event)
    if event.can_veto()
      message_box("Use the menu item to close self dialog",
                  "Modeless dialog",
                  OK | ICON_INFORMATION, self)

      event.veto()
    end
  end
end


class MyCanvas < ScrolledWindow
  def initialize(parent)
    super(parent,-1,DEFAULT_POSITION,DEFAULT_SIZE, NO_FULL_REPAINT_ON_RESIZE)
    text = Wx::StaticText.new(self, -1, 
                              'WxRuby common dialog test application',
                              Wx::Point.new(10, 10) )
    # PaintDC currently causing ObjectPreviouslyDeleted (10 Aug 2006)
    # evt_paint() {|event| onPaint(event) }
  end

  def clear

  end

  def onPaint(event)
    # PaintDC currently causing ObjectPreviouslyDeleted (10 Aug 2006)
    paint do | dc |
      p dc
      dc.set_text_foreground( get_app.canvas_text_colour )
      dc.set_font( get_app.canvas_font )
      dc.draw_text("Windows common dialogs test application", 10, 10)
    end
  end
end

class MyFrame < Frame
  def initialize(parent,
                 title,
                 pos,
                 size)
    super(parent, -1, title, pos, size)

    @m_dialog = nil

    @m_dlgFind = nil
    @m_dlgReplace = nil

    @m_findData = FindReplaceData.new

    @s_extDef = ""
    @s_index = -1

    @max = 10

    create_status_bar()

    evt_menu(DIALOGS_CHOOSE_COLOUR) {|event| onChooseColour(event) }
    evt_menu(DIALOGS_CHOOSE_FONT) {|event| onChooseFont(event) }
    evt_menu(DIALOGS_LOG_DIALOG) {|event| onLogDialog(event) }
    evt_menu(DIALOGS_MESSAGE_BOX) {|event| onMessageBox(event) }
    evt_menu(DIALOGS_TEXT_ENTRY) {|event| onTextEntry(event) }
    evt_menu(DIALOGS_PASSWORD_ENTRY) {|event| onPasswordEntry(event) }
    evt_menu(DIALOGS_NUM_ENTRY) {|event| onNumericEntry(event) }
    evt_menu(DIALOGS_SINGLE_CHOICE) {|event| onSingleChoice(event) }
    evt_menu(DIALOGS_MULTI_CHOICE) {|event| onMultiChoice(event) }
    evt_menu(DIALOGS_FILE_OPEN) {|event| onFileOpen(event) }
    evt_menu(DIALOGS_FILE_OPEN2) {|event| onFileOpen2(event) }
    evt_menu(DIALOGS_FILES_OPEN) {|event| onFilesOpen(event) }
    evt_menu(DIALOGS_FILE_SAVE) {|event| onFileSave(event) }
    evt_menu(DIALOGS_DIR_CHOOSE) {|event| onDirChoose(event) }
    evt_menu(DIALOGS_MODAL) {|event| onModalDlg(event) }
    evt_menu(DIALOGS_MODELESS) {|event| onModelessDlg(event) }
    evt_menu(DIALOGS_TIP) {|event| onShowTip(event) }
    evt_menu(DIALOGS_PROGRESS) {|event| onShowProgress(event) }
    evt_menu(DIALOGS_BUSYINFO) {|event| onShowBusyInfo(event) }
    evt_menu(DIALOGS_FIND) {|event| onShowFindDialog(event) }
    evt_menu(DIALOGS_REPLACE) {|event| onShowReplaceDialog(event) }
    evt_find(-1) {|event| onFindDialog(event) }
    evt_find_next(-1) {|event| onFindDialog(event) }
    evt_find_replace(-1) {|event| onFindDialog(event) }
    evt_find_replace_all(-1) {|event| onFindDialog(event) }
    evt_find_close(-1) {|event| onFindDialog(event) }
    evt_menu(ID_EXIT) {|event| onExit(event) }

  end

  def onChooseColour(event)

    col = $myCanvas.get_background_colour()

    data = ColourData.new
    data.set_colour(col)
    data.set_choose_full(TRUE)
    for i in 0 ... 16
      colour = Colour.new(i*16, i*16, i*16)
      data.set_custom_colour(i, colour)
    end

    dialog = ColourDialog.new(self, data)
    dialog.set_title("Choose the background colour (not OS X)")
    if dialog.show_modal() == ID_OK
      retData = dialog.get_colour_data()
      col = retData.get_colour()
      $myCanvas.set_background_colour(col)
      #$myCanvas.clear()
      $myCanvas.refresh()
    end
  end


  def onChooseFont(event)
    data = FontData.new
    data.set_initial_font($app.canvas_font)
    data.set_colour($app.canvas_text_colour)

    dialog = FontDialog.new(self, data)

    if dialog.show_modal() == ID_OK
      retData = dialog.get_font_data()
      # $app.canvas_font = retData.get_chosen_font()
      # $app.canvas_text_colour = retData.get_colour()
      font   = retData.get_chosen_font
      msg = "Font = %s, %i pt" % [ font.get_face_name,
                                   font.get_point_size ]
      dialog2 = MessageDialog.new(self, msg, "Got font")
      dialog2.show_modal()
      # $myCanvas.refresh()
    end
    #else: cancelled by the user, don't change the font
  end


  def onLogDialog(event)

    # calling yield() (as ~BusyCursor does) shouldn't result in messages
    # being flushed -- test it

    BusyCursor.busy() do
      
      log_message("This is some message - everything is ok so far.")
      log_message("Another message...\n... self one is on multiple lines")
      log_warning("And then something went wrong!")
      
      # and if ~BusyCursor doesn't do it, then call it manually
      Wx::yield()
      
      log_error("Intermediary error handler decided to abort.")
      log_error("DEMO: The top level caller detected an unrecoverable error.")
      
      Log::flush_active()
      
      log_message("And this is the same dialog but with only one message.")
	end
  end

  def onMessageBox(event)

    dialog = MessageDialog.new(nil, "This is a message box\nA long, long string to test out the message box properly",
                               "Message box text", NO_DEFAULT|YES_NO|CANCEL|ICON_INFORMATION)

    case dialog.show_modal()
    when ID_YES
      log_status("You pressed \"Yes\"")
    when ID_NO
      log_status("You pressed \"No\"")
    when ID_CANCEL
      log_status("You pressed \"Cancel\"")
    else
      log_error("Unexpected MessageDialog return code!")
    end
  end


  def onNumericEntry(event)

    res = get_number_from_user( "This is some text, actually a lot of text.\n" +
                                                                                "Even two rows of text.",
                               "Enter a number:", "Numeric input test",
                               50, 0, 100, self )

    if res == -1
      msg = "Invalid number entered or dialog cancelled."
      icon = ICON_HAND
    else
      msg = sprintf("You've entered %d", res )
      icon = ICON_INFORMATION
    end

    message_box(msg, "Numeric test result", OK | icon, self)
  end

  def onPasswordEntry(event)

    pwd = get_password_from_user("Enter password:",
                                 "Password entry dialog",
                                 "", self)
    if pwd
      message_box(sprintf("Your password is '%s'", pwd),
                  "Got password", OK | ICON_INFORMATION, self)
    end
  end


  def onTextEntry(event)

    dialog = TextEntryDialog.new(self,
                                 "This is a small sample\n" +
                                                             "A long, long string to test out the text entrybox",
                                 "Please enter a string",
                                 "Default value",
                                 OK | CANCEL)

    if dialog.show_modal() == ID_OK
      dialog2 = MessageDialog.new(self, dialog.get_value(), "Got string")
      dialog2.show_modal()
    end
  end

  def onSingleChoice(event)

    choices = ["One", "Two", "Three", "Four", "Five"]

    dialog = SingleChoiceDialog.new(self,
                                    "This is a small sample\n" +
                                                                "A single-choice convenience dialog",
                                    "Please select a value",
                                    choices, nil, OK | CANCEL)

    dialog.set_selection(2)

    if dialog.show_modal() == ID_OK
      dialog2 = MessageDialog.new(self, dialog.get_string_selection(), "Got string")
      dialog2.show_modal()
    end
  end


  def onMultiChoice(event)

    choices = [
      "One", "Two", "Three", "Four", "Five",
      "Six", "Seven", "Eight", "Nine", "Ten",
      "Eleven", "Twelve", "Seventeen"]

    selections = get_multiple_choices("This is a small sample\n" +
                                                                  "A multi-choice convenience dialog",
                                      "Please select a value",
                                      choices,
                                      self)
    if selections
      msg = sprintf("You selected %d items:\n", selections.length)
      for n in 0 ... selections.length
        msg += sprintf("\t%d: %d (%s)\n", n, selections[n],
                       choices[selections[n]])
      end
      log_message(msg)
    end
    #else: cancelled or nothing selected
  end


  def onFileOpen(event)

    dialog = FileDialog.new(
                             self,
                             "Testing open file dialog",
                             "",
                             "",
                             "C++ files (*.h;*.cpp)|*.h;*.cpp"
                           )

    dialog.set_directory(get_home_dir())

    if dialog.show_modal() == ID_OK
      info = sprintf("Full file name: %s\n" +
                                             "Path: %s\n" +
                                             "Name: %s",
                     dialog.get_path(),
                     dialog.get_directory(),
                     dialog.get_filename())
      dialog2 = MessageDialog.new(self, info, "Selected file")
      dialog2.show_modal()
    end
  end


  # this shows how to take advantage of specifying a default extension in the
  # call to FileSelector: it is remembered after each new call and the next
  # one will use it by default
  def onFileOpen2(event)

    path = file_selector(
                          "Select the file to load",
                          "", "",
                          @s_extDef,
                          "Waveform (*.wav)|*.wav|Plain text (*.txt)|*.txt|All files (*.*)|*.*",
                          CHANGE_DIR,
                          self
                        )

    if path == nil
      return nil
    end

    # it is just a sample, would use SplitPath in real program
    @s_extDef = path[/[^\.]*$/]

    log_message("You selected the file '%s', remembered extension '%s'",
                path, @s_extDef)
  end


  def onFilesOpen(event)

    dialog = FileDialog.new(self, "Testing open multiple file dialog",
                            "", "", FILE_SELECTOR_DEFAULT_WILDCARD_STR,
                            MULTIPLE)

    if dialog.show_modal() == ID_OK

      paths = dialog.get_paths()
      filenames = dialog.get_filenames()

      count = paths.length
      msg = ""
      for n in 0 ... count
        s = sprintf("File %d: %s (%s)\n",
                    n, paths[n], filenames[n])
        msg += s
      end

      dialog2 = MessageDialog.new(self, msg, "Selected files")
      dialog2.show_modal()
    end
  end


  def onFileSave(event)

    dialog = FileDialog.new(self,
                            "Testing save file dialog",
                            "",
                            "myletter.doc",
                            "Text files (*.txt)|*.txt|Document files (*.doc)|*.doc",
                            SAVE|OVERWRITE_PROMPT)

    dialog.set_filter_index(1)

    if dialog.show_modal() == ID_OK

      log_message("%s, filter %d",
                  dialog.get_path(), dialog.get_filter_index())
    end
  end

  def onDirChoose(event)

    # pass some initial dir to DirDialog
    dirHome = get_home_dir()

    dialog = DirDialog.new(self, "Testing directory picker", dirHome)

    if dialog.show_modal() == ID_OK
      log_message("Selected path: %s", dialog.get_path())
    end
  end


  def onModalDlg(event)
    dlg = MyModalDialog.new(self)
    dlg.show_modal()
  end

  def onModelessDlg(event)
    show = get_menu_bar().is_checked(event.get_id())
    if show
      if !@m_dialog
        @m_dialog = MyModelessDialog.new(self)
      end
      @m_dialog.show(TRUE)
    else # hide
      @m_dialog.hide()
    end
  end


  def onShowTip(event)

    if @s_index == -1
      @s_index = rand(5)
    end
    
    tip_src = File.join( File.dirname(__FILE__), 'tips.txt')
    tipProvider = create_file_tip_provider(tip_src, @s_index)

    showAtStartup = show_tip(self, tipProvider)

    if showAtStartup
      message_box("Will show tips on startup", "Tips dialog",
                  OK | ICON_INFORMATION, self)
    end

    @s_index = tipProvider.get_current_tip()

  end

  def onExit(event)
    close(TRUE)
  end


  def onShowProgress(event)

    dialog = ProgressDialog.new("Progress dialog example",
                                "An informative message",
                                @max,    # range
                                self,   # parent
                                PD_CAN_ABORT |
                                              PD_APP_MODAL |
                                              PD_ELAPSED_TIME |
                                              PD_ESTIMATED_TIME |
                                              PD_REMAINING_TIME)

    cont = TRUE
    for i in 0 .. @max

      sleep(1)
      if i == @max
        cont = dialog.update(i, "That's all, folks!")
      elsif i == @max / 2
        cont = dialog.update(i, "Only a half left (very long message)!")
      else
        cont = dialog.update(i)
      end

      if !cont
        if message_box("Do you really want to cancel?",
                       "Progress dialog question",  # caption
                       YES_NO | ICON_QUESTION) == YES
          break
        end
        dialog.resume()
      end
    end


    if !cont
      log_status("Progress dialog aborted!")
    else
      log_status("Countdown from %d finished", @max)
    end
  end

  def onShowBusyInfo(event)
    WindowDisabler.disable(self) do
      info = BusyInfo.busy("Working, please wait...", self) do
        
        for i in 0 ... 18
          $app.yield()
        end
        sleep(2)
      end
	end
  end

  def onShowReplaceDialog(event)

    if @m_dlgReplace
      #@m_dlgReplace.destroy
      @m_dlgReplace = nil
    else
      @m_dlgReplace = FindReplaceDialog.new(
                                             self,
                                             @m_findData,
                                             "Find and replace dialog",
                                             FR_REPLACEDIALOG
                                           )

      @m_dlgReplace.show(TRUE)
    end
  end

  def onShowFindDialog(event)

    if @m_dlgFind
      @m_dlgFind.destroy
      @m_dlgFind = nil
    else
      @m_dlgFind = FindReplaceDialog.new(
                                          self,
                                          @m_findData,
                                          "Find dialog",  # just for testing
                                          FR_NOWHOLEWORD
                                        )

      @m_dlgFind.show(TRUE)
    end
  end

  def DecodeFindDialogEventFlags(flags)
    str = ""
    str << ((flags & FR_DOWN) != 0 ? "down" : "up") << ", "  \
    << ((flags & FR_WHOLEWORD) != 0 ? "whole words only, " : "") \
    << ((flags & FR_MATCHCASE) != 0 ? "" : "not ")   \
    << "case sensitive"

    return str
  end

  def onFindDialog(event)

    type = event.get_event_type()

    if type == EVT_COMMAND_FIND || type == EVT_COMMAND_FIND_NEXT
      log_message("Find %s'%s' (flags: %s)",
                  type == EVT_COMMAND_FIND_NEXT ? "next " : "",
                  event.get_find_string(),
                  DecodeFindDialogEventFlags(event.get_flags()))
    elsif type == EVT_COMMAND_FIND_REPLACE || type == EVT_COMMAND_FIND_REPLACE_ALL
      log_message("Replace %s'%s' with '%s' (flags: %s)",
                  type == EVT_COMMAND_FIND_REPLACE_ALL ? "all " : "",
                  event.get_find_string(),
                  event.get_replace_string(),
                  DecodeFindDialogEventFlags(event.get_flags()))
    elsif type == EVT_COMMAND_FIND_CLOSE
      dlg = event.get_dialog()
      if dlg == @m_dlgFind
        txt = "Find"
        idMenu = DIALOGS_FIND
        @m_dlgFind = nil
      elsif dlg == @m_dlgReplace
        txt = "Replace"
        idMenu = DIALOGS_REPLACE
        @m_dlgReplace = nil
      else
        txt = "Unknown"
        idMenu = -1
        log_error("unexpected event")
      end

      log_message("%s dialog is being closed.", txt)

      if idMenu != -1
        get_menu_bar().check(idMenu, FALSE)
      end

      dlg.destroy()
    else
      log_error("Unknown find dialog event!")
    end
  end

end


class MyApp < App
  attr_accessor :canvas_text_colour, :canvas_font
  
  def on_init()
    self.canvas_text_colour = Wx::Colour.new("BLACK")
    self.canvas_font        = Wx::NORMAL_FONT
    # Create the main frame window
    frame = MyFrame.new(nil, "Windows dialogs example", 
                        Point.new(20, 20), Size.new(400, 300))

    # Make a menubar
    file_menu = Menu.new

    file_menu.append(DIALOGS_CHOOSE_COLOUR, "&Choose colour")
    file_menu.append_separator()
    file_menu.append(DIALOGS_CHOOSE_FONT, "Choose &font")
    file_menu.append_separator()
    file_menu.append(DIALOGS_LOG_DIALOG, "&Log dialog\tCtrl-L")
    file_menu.append(DIALOGS_MESSAGE_BOX, "&Message box\tCtrl-M")
    file_menu.append(DIALOGS_TEXT_ENTRY,  "Text &entry\tCtrl-E")
    file_menu.append(DIALOGS_PASSWORD_ENTRY,  "&Password entry\tCtrl-P")
    file_menu.append(DIALOGS_NUM_ENTRY, "&Numeric entry\tCtrl-N")
    file_menu.append(DIALOGS_SINGLE_CHOICE,  "&Single choice\tCtrl-C")
    file_menu.append(DIALOGS_MULTI_CHOICE,  "M&ultiple choice\tCtrl-U")
    file_menu.append_separator()
    file_menu.append(DIALOGS_TIP,  "&Tip of the day\tCtrl-T")
    file_menu.append_separator()
    file_menu.append(DIALOGS_FILE_OPEN,  "&Open file\tCtrl-O")
    file_menu.append(DIALOGS_FILE_OPEN2,  "&Second open file\tCtrl-2")
    file_menu.append(DIALOGS_FILES_OPEN,  "Open &files\tShift-Ctrl-O")
    file_menu.append(DIALOGS_FILE_SAVE,  "Sa&ve file\tCtrl-S")
    file_menu.append(DIALOGS_DIR_CHOOSE,  "&Choose a directory\tCtrl-D")
    file_menu.append(DIALOGS_PROGRESS, "Pro&gress dialog\tCtrl-G")
    file_menu.append(DIALOGS_BUSYINFO, "&Busy info dialog\tCtrl-B")
    file_menu.append(DIALOGS_FIND, "&Find dialog\tCtrl-F", "", ITEM_CHECK)
    file_menu.append(DIALOGS_REPLACE, "Find and &replace dialog\tShift-Ctrl-F", "", ITEM_CHECK)
    file_menu.append_separator()
    file_menu.append(DIALOGS_MODAL, "Mo&dal dialog\tCtrl-W")
    file_menu.append(DIALOGS_MODELESS, "Modeless &dialog\tCtrl-Z", "", ITEM_CHECK)
    file_menu.append_separator()
    file_menu.append(ID_EXIT, "E&xit\tAlt-X")
    menu_bar = MenuBar.new
    menu_bar.append(file_menu, "&File")
    frame.set_menu_bar(menu_bar)

    $myCanvas = MyCanvas.new(frame)
    $myCanvas.set_background_colour(WHITE)

    frame.centre(BOTH)

    # Show the frame
    frame.show()
  end
end

$app = MyApp.new()
$app.main_loop()

