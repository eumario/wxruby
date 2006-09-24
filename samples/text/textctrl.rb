# wxRuby2 Sample Code. Copyright (c) 2004-2006 Kevin B. Smith
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

require 'wx'

class InformativeTextCtrl < Wx::TextCtrl
  NEWLINE_CORRECTION_FACTOR = 0
  
  # These text controls are multiline, and may have rich (coloured,
  # styled) text in them
  STYLE = Wx::TE_MULTILINE|Wx::TE_RICH|Wx::TE_RICH2
  def initialize(parent, text)
    super(parent, -1, text, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, STYLE)
  end

  # more ruby-ish
  alias :<< :append_text

  # run through a few useful methods of textctrl and report the results
  # as a string
  def report()
    report = ''
    report << 'Insertion Point: ' << get_insertion_point.to_s() << "\n"
    report << 'First Line Text: ' << get_line_text(0) << "\n"
    report << 'Final Position: ' << get_last_position().to_s() << "\n"
    report << 'Selection: ' << get_selection().inspect() << "\n"
    report << 'String Selection: ' << get_string_selection().inspect << "\n"
    report << 'Position to X, Y: ' << 
               position_to_xy( get_insertion_point ).inspect
    return report
  end
end

# A read-only text ctrl useful for displaying output
class LogTextCtrl < Wx::TextCtrl
  STYLE = Wx::TE_READONLY|Wx::TE_MULTILINE
  def initialize(parent)
    super(parent, -1, '', Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, STYLE)
  end
end

class TextCtrlFrame < Wx::Frame
  def initialize(title, pos, size)
    super(nil, -1, title, pos, size)
    sizer = Wx::BoxSizer.new(Wx::VERTICAL)

    @textctrl = InformativeTextCtrl.new(self, '')
    populate_textctrl()
    sizer.add(@textctrl, 2, Wx::GROW|Wx::ALL, 2)

    button = Wx::Button.new(self, -1, 'Get Info')
    sizer.add(button, 0, Wx::ADJUST_MINSIZE|Wx::ALL, 2 )
    evt_button(button.get_id) { | e | on_click(e) }

    @log = LogTextCtrl.new(self)
    sizer.add(@log, 1, Wx::GROW|Wx::ALL, 2)

    self.set_sizer( sizer )
  end

  def populate_textctrl()
    @textctrl << "This is some plain text\n"
    @textctrl << "Text with green letters and yellow background\n"
    @textctrl << "This is some more plain text"
    # create a new rich text style
    attr = Wx::TextAttr.new(Wx::GREEN, Wx::Colour.new(255, 255, 0) )
    # apply the style from character 26 to character 76
    @textctrl.set_style(24, 69, attr)
  end

  def construct_menus()
    menu_bar = Wx::MenuBar.new()

    menu_file = Wx::Menu.new()
    menu_file.append(Wx::ID_EXIT, "E&xit\tAlt-X", "Quit this program")
    menu_bar.append(menu_file, "&File")
    evt_menu(Wx::ID_EXIT) { on_quit() }

    menu_help = Wx::Menu.new()
    menu_help.append(Wx::ID_ABOUT, "&About...\tF1", "Show about dialog")
    evt_menu(Wx::ID_ABOUT) { on_about() }
    menu_bar.append(menu_help, "&Help")

    set_menu_bar(menu_bar)
  end

  def on_click(e)
    @log.set_value( @textctrl.report() )
  end

  def on_quit()
    close(TRUE)
  end

  def on_about()
    msg =  sprintf("This is the About dialog of the textctrl sample.\n" \
                    "Welcome to %s", Wx::VERSION_STRING)
    message_box(msg, "About Minimal", Wx::OK|Wx::ICON_INFORMATION, self)
  end
end

class RbApp < Wx::App
  def on_init()
    frame = TextCtrlFrame.new("TextCtrl demonstration",
                              Wx::Point.new(50, 50),
                              Wx::Size.new(450, 340) )

    frame.show(true)
  end
end

RbApp.new().main_loop()
