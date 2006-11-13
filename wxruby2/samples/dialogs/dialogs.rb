#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

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

$my_canvas = nil

class MyModalDialog < Dialog
  def initialize(parent)
    super(parent, -1, "Modal dialog")

    sizer_top = BoxSizer.new(HORIZONTAL)

    @btn_focused = Button.new(self, -1, "Default button")
    @btn_delete = Button.new(self, -1, "&Delete button")
    btn_ok = Button.new(self, ID_CANCEL, "&Close")
    sizer_top.add(@btn_focused, 0, ALIGN_CENTER | ALL, 5)
    sizer_top.add(@btn_delete, 0, ALIGN_CENTER | ALL, 5)
    sizer_top.add(btn_ok, 0, ALIGN_CENTER | ALL, 5)

    set_auto_layout(true)
    set_sizer(sizer_top)

    sizer_top.set_size_hints(self)
    sizer_top.fit(self)

    @btn_focused.set_focus()
    @btn_focused.set_default()

    evt_button(-1) {|event| on_button(event) }
  end

  def on_button(event)
    id = event.get_id
    
    if id == @btn_delete.get_id
      @btn_focused.destroy
      @btn_focused = nil

      @btn_delete.disable()
    elsif @btn_focused && id == @btn_focused.get_id
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

    sizer_top = BoxSizer.new(VERTICAL)

    btn = Button.new(self, DIALOGS_MODELESS_BTN, "Press me")
    check = CheckBox.new(self, -1, "Should be disabled")
    check.disable()

    sizer_top.add(btn, 1, EXPAND | ALL, 5)
    sizer_top.add(check, 1, EXPAND | ALL, 5)

    set_auto_layout(true)
    set_sizer(sizer_top)

    sizer_top.set_size_hints(self)
    sizer_top.fit(self)

    evt_button(DIALOGS_MODELESS_BTN) {|event| on_button(event) }

    evt_close() {|event| on_close(event) }

  end

  def on_button(event)
    message_box("Button pressed in modeless dialog", "Info",
                OK | ICON_INFORMATION, self)
  end

  def on_close(event)
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
    evt_paint { |event| on_paint(event) }
  end

  def clear

  end

  def on_paint(event)
    dc = PaintDC.new(self)
    dc.set_text_foreground( get_app.canvas_text_colour )
    dc.set_font( get_app.canvas_font )
    dc.draw_text("Windows common dialogs test application", 10, 10)
  end
end

class MyFrame < Frame
  def initialize(parent,
                 title,
                 pos,
                 size)
    super(parent, -1, title, pos, size)

    @dialog = nil

    @dlg_find = nil
    @dlg_replace = nil

    @find_data = FindReplaceData.new

    @ext_def = ""
    @index = -1

    @max = 10

    create_status_bar()

    evt_menu(DIALOGS_CHOOSE_COLOUR) {|event| on_choose_colour(event) }
    evt_menu(DIALOGS_CHOOSE_FONT) {|event| on_choose_font(event) }
    evt_menu(DIALOGS_LOG_DIALOG) {|event| on_log_dialog(event) }
    evt_menu(DIALOGS_MESSAGE_BOX) {|event| on_message_box(event) }
    evt_menu(DIALOGS_TEXT_ENTRY) {|event| on_text_entry(event) }
    evt_menu(DIALOGS_PASSWORD_ENTRY) {|event| on_password_entry(event) }
    evt_menu(DIALOGS_NUM_ENTRY) {|event| on_numeric_entry(event) }
    evt_menu(DIALOGS_SINGLE_CHOICE) {|event| on_single_choice(event) }
    evt_menu(DIALOGS_MULTI_CHOICE) {|event| on_multi_choice(event) }
    evt_menu(DIALOGS_FILE_OPEN) {|event| on_file_open(event) }
    evt_menu(DIALOGS_FILE_OPEN2) {|event| on_file_open2(event) }
    evt_menu(DIALOGS_FILES_OPEN) {|event| on_files_open(event) }
    evt_menu(DIALOGS_FILE_SAVE) {|event| on_file_save(event) }
    evt_menu(DIALOGS_DIR_CHOOSE) {|event| on_dir_choose(event) }
    evt_menu(DIALOGS_MODAL) {|event| on_modal_dlg(event) }
    evt_menu(DIALOGS_MODELESS) {|event| on_modeless_dlg(event) }
    evt_menu(DIALOGS_TIP) {|event| on_show_tip(event) }
    evt_menu(DIALOGS_PROGRESS) {|event| on_show_progress(event) }
    evt_menu(DIALOGS_BUSYINFO) {|event| on_show_busy_info(event) }
    evt_menu(DIALOGS_FIND) {|event| on_show_find_dialog(event) }
    evt_menu(DIALOGS_REPLACE) {|event| on_show_replace_dialog(event) }
    evt_find(-1) {|event| on_find_dialog(event) }
    evt_find_next(-1) {|event| on_find_dialog(event) }
    evt_find_replace(-1) {|event| on_find_dialog(event) }
    evt_find_replace_all(-1) {|event| on_find_dialog(event) }
    evt_find_close(-1) {|event| on_find_dialog(event) }
    evt_menu(ID_EXIT) {|event| on_exit(event) }

  end

  def on_choose_colour(event)

    col = $my_canvas.get_background_colour()

    data = ColourData.new
    data.set_colour(col)
    data.set_choose_full(true)
    for i in 0 ... 16
      colour = Colour.new(i*16, i*16, i*16)
      data.set_custom_colour(i, colour)
    end

    dialog = ColourDialog.new(self, data)
    dialog.set_title("Choose the background colour (not OS X)")
    if dialog.show_modal() == ID_OK
      retData = dialog.get_colour_data()
      col = retData.get_colour()
      $my_canvas.set_background_colour(col)
      #$my_canvas.clear()
      $my_canvas.refresh()
    end
  end


  def on_choose_font(event)
    data = FontData.new
    data.set_initial_font(Wx::get_app.canvas_font)
    data.set_colour(Wx::get_app.canvas_text_colour)

    dialog = FontDialog.new(self, data)

    if dialog.show_modal() == ID_OK
      ret_data = dialog.get_font_data()
      Wx::get_app.canvas_font = ret_data.get_chosen_font()
      Wx::get_app.canvas_text_colour = ret_data.get_colour()
      font   = ret_data.get_chosen_font
      msg = "Font = %s, %i pt" % [ font.get_face_name,
                                   font.get_point_size ]
      dialog2 = MessageDialog.new(self, msg, "Got font")
      dialog2.show_modal()
      # $my_canvas.refresh()
    end
    #else: cancelled by the user, don't change the font
  end


  def on_log_dialog(event)

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

  def on_message_box(event)

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


  def on_numeric_entry(event)

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

  def on_password_entry(event)

    pwd = get_password_from_user("Enter password:",
                                 "Password entry dialog",
                                 "", self)
    if pwd
      message_box(sprintf("Your password is '%s'", pwd),
                  "Got password", OK | ICON_INFORMATION, self)
    end
  end


  def on_text_entry(event)

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

  def on_single_choice(event)

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


  def on_multi_choice(event)

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


  def on_file_open(event)

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
  def on_file_open2(event)

    path = file_selector(
                          "Select the file to load",
                          "", "",
                          @ext_def,
                          "Waveform (*.wav)|*.wav|Plain text (*.txt)|*.txt|All files (*.*)|*.*",
                          CHANGE_DIR,
                          self
                        )

    if path == nil
      return nil
    end

    # it is just a sample, would use SplitPath in real program
    @ext_def = path[/[^\.]*$/]

    log_message("You selected the file '%s', remembered extension '%s'",
                path, @ext_def)
  end


  def on_files_open(event)

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


  def on_file_save(event)

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

  def on_dir_choose(event)

    # pass some initial dir to DirDialog
    dir_home = get_home_dir()

    dialog = DirDialog.new(self, "Testing directory picker", dir_home)

    if dialog.show_modal() == ID_OK
      log_message("Selected path: %s", dialog.get_path())
    end
  end


  def on_modal_dlg(event)
    dlg = MyModalDialog.new(self)
    dlg.show_modal()
  end

  def on_modeless_dlg(event)
    show = get_menu_bar().is_checked(event.get_id())
    if show
      if !@dialog
        @dialog = MyModelessDialog.new(self)
      end
      @dialog.show(true)
    else # hide
      @dialog.hide()
    end
  end


  def on_show_tip(event)

    if @index == -1
      @index = rand(5)
    end
    
    tip_src = File.join( File.dirname(__FILE__), 'tips.txt')
    tip_provider = create_file_tip_provider(tip_src, @index)

    show_at_startup = show_tip(self, tip_provider)

    if show_at_startup
      message_box("Will show tips on startup", "Tips dialog",
                  OK | ICON_INFORMATION, self)
    end

    @index = tip_provider.get_current_tip()

  end

  def on_exit(event)
    close(true)
  end


  def on_show_progress(event)

    dialog = ProgressDialog.new("Progress dialog example",
                                "An informative message",
                                @max,    # range
                                self,   # parent
                                PD_CAN_ABORT|PD_APP_MODAL|
                                PD_ELAPSED_TIME|PD_ESTIMATED_TIME|
                                PD_REMAINING_TIME)

    cont = true
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
          dialog.end_modal(ID_CANCEL)
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

  def on_show_busy_info(event)
    WindowDisabler.disable(self) do
      info = BusyInfo.busy("Working, please wait...", self) do
        
        for i in 0 ... 18
          Wx::get_app.yield()
        end
        sleep(2)
      end
	end
  end

  def on_show_replace_dialog(event)

    if @dlg_replace
      #@dlg_replace.destroy
      @dlg_replace = nil
    else
      @dlg_replace = FindReplaceDialog.new(
                                             self,
                                             @find_data,
                                             "Find and replace dialog",
                                             FR_REPLACEDIALOG
                                           )

      @dlg_replace.show(true)
    end
  end

  def on_show_find_dialog(event)

    if @dlg_find
      @dlg_find.destroy
      @dlg_find = nil
    else
      @dlg_find = FindReplaceDialog.new(
                                          self,
                                          @find_data,
                                          "Find dialog",  # just for testing
                                          FR_NOWHOLEWORD
                                        )

      @dlg_find.show(true)
    end
  end

  def decode_find_dialog_event_flags(flags)
    str = ""
    str << ((flags & FR_DOWN) != 0 ? "down" : "up") << ", "  \
    << ((flags & FR_WHOLEWORD) != 0 ? "whole words only, " : "") \
    << ((flags & FR_MATCHCASE) != 0 ? "" : "not ")   \
    << "case sensitive"

    return str
  end

  def on_find_dialog(event)

    type = event.get_event_type()

    if type == EVT_COMMAND_FIND || type == EVT_COMMAND_FIND_NEXT
      log_message("Find %s'%s' (flags: %s)",
                  type == EVT_COMMAND_FIND_NEXT ? "next " : "",
                  event.get_find_string(),
                  decode_find_dialog_event_flags(event.get_flags()))
    elsif type == EVT_COMMAND_FIND_REPLACE || type == EVT_COMMAND_FIND_REPLACE_ALL
      log_message("Replace %s'%s' with '%s' (flags: %s)",
                  type == EVT_COMMAND_FIND_REPLACE_ALL ? "all " : "",
                  event.get_find_string(),
                  event.get_replace_string(),
                  decode_find_dialog_event_flags(event.get_flags()))
    elsif type == EVT_COMMAND_FIND_CLOSE
      dlg = event.get_dialog()
      if dlg == @dlg_find
        txt = "Find"
        id_menu = DIALOGS_FIND
        @dlg_find = nil
      elsif dlg == @dlg_replace
        txt = "Replace"
        id_menu = DIALOGS_REPLACE
        @dlg_replace = nil
      else
        txt = "Unknown"
        id_menu = -1
        log_error("unexpected event")
      end

      log_message("%s dialog is being closed.", txt)

      if id_menu != -1
        get_menu_bar().check(id_menu, false)
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

    $my_canvas = MyCanvas.new(frame)
    $my_canvas.set_background_colour(WHITE)

    frame.centre(BOTH)

    # Show the frame
    frame.show()
  end
end

app = MyApp.new()
app.main_loop()

