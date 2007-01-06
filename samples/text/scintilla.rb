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


Minimal_Quit = 1
Minimal_About = ID_ABOUT
Toggle_Whitespace = 5000
Toggle_EOL = 5001

class MyFrame < Frame
  def initialize(title,pos,size,style=DEFAULT_FRAME_STYLE)
    super(nil,-1,title,pos,size,style)

    if Wx::PLATFORM == "WXMSW"
      set_icon(Icon.new("mondrian.ico",BITMAP_TYPE_ICO))
    else
      set_icon(Icon.new("mondrian.xpm",BITMAP_TYPE_XPM))
    end

    menuFile = Menu.new()
    menuFile.append(Minimal_Quit, "E&xit\tAlt-X", "Quit this program")

    menuView = Menu.new()
    menuView.append(Toggle_Whitespace, "Show &Whitespace\tF6", "Show Whitespace", ITEM_CHECK)
    menuView.append(Toggle_EOL, "Show &End of Line\tF7", "Show End of Line characters", ITEM_CHECK)

    menuHelp = Menu.new()
    menuHelp.append(Minimal_About, "&About...\tF1", "Show about dialog")

    menuBar = MenuBar.new()
    menuBar.append(menuFile, "&File")
    menuBar.append(menuView, "&View")
    menuBar.append(menuHelp, "&Help")
    set_menu_bar(menuBar)

    tb = create_tool_bar(Wx::TB_HORIZONTAL | Wx::NO_BORDER | Wx::TB_FLAT | Wx::TB_TEXT)    

    create_status_bar(2)
    set_status_text("Welcome to wxRuby!")

    @sci = Wx::Scintilla.new(self)

    font = Font.new(10, TELETYPE, NORMAL, NORMAL)
    @sci.style_set_font(SCI_STYLE_DEFAULT, font);

    @ws_visible = false
    @eol_visible = false
    @sci.set_edge_mode(SCI_EDGE_LINE)

    line_num_margin = @sci.text_width(SCI_STYLE_LINENUMBER, "_99999")
    @sci.set_margin_width(0, line_num_margin)

    @sci.style_set_foreground(SCI_STYLE_DEFAULT, BLACK);
    @sci.style_set_background(SCI_STYLE_DEFAULT, WHITE);
    @sci.style_set_foreground(SCI_STYLE_LINENUMBER, LIGHT_GREY);
    @sci.style_set_background(SCI_STYLE_LINENUMBER, WHITE);
    @sci.style_set_foreground(SCI_STYLE_INDENTGUIDE, LIGHT_GREY);

    @sci.set_tab_width(4)
    @sci.set_use_tabs(false)
    @sci.set_tab_indents(true)
    @sci.set_back_space_un_indents(true)
    @sci.set_indent(4)
    @sci.set_edge_column(80)

    @sci.set_lexer(SCI_LEX_RUBY)
    @sci.style_clear_all
    @sci.style_set_foreground(2, RED)
    @sci.style_set_foreground(3, GREEN)
    @sci.style_set_foreground(5, BLUE)
    @sci.style_set_foreground(6, BLUE)
    @sci.style_set_foreground(7, BLUE)
    @sci.set_key_words(0, "begin break elsif module retry unless end case next return until class ensure nil self when def false not super while alias defined? for or then yield and do if redo true else in rescue undef")

    @sci.set_property("fold","1")
    @sci.set_property("fold.compact", "0")
    @sci.set_property("fold.comment", "1")
    @sci.set_property("fold.preprocessor", "1")

    @sci.set_margin_width(1, 0)
    @sci.set_margin_type(1, SCI_MARGIN_SYMBOL)
    @sci.set_margin_mask(1, SCI_MASK_FOLDERS)
    @sci.set_margin_width(1, 20)

    @sci.marker_define(SCI_MARKNUM_FOLDER, SCI_MARK_PLUS)
    @sci.marker_define(SCI_MARKNUM_FOLDEROPEN, SCI_MARK_MINUS)
    @sci.marker_define(SCI_MARKNUM_FOLDEREND, SCI_MARK_EMPTY)
    @sci.marker_define(SCI_MARKNUM_FOLDERMIDTAIL, SCI_MARK_EMPTY)
    @sci.marker_define(SCI_MARKNUM_FOLDEROPENMID, SCI_MARK_EMPTY)
    @sci.marker_define(SCI_MARKNUM_FOLDERSUB, SCI_MARK_EMPTY)
    @sci.marker_define(SCI_MARKNUM_FOLDERTAIL, SCI_MARK_EMPTY)
    @sci.set_fold_flags(16)

    @sci.set_margin_sensitive(1,1)

    evt_menu(Minimal_Quit) {onQuit}
    evt_menu(Minimal_About) {onAbout}
    evt_menu(Toggle_Whitespace) {onWhitespace}
    evt_menu(Toggle_EOL) {onEOL}
    evt_sci_charadded {|evt| onCharadded(evt)}
    evt_sci_marginclick {|evt| onMarginClick(evt)}

  end

  def onQuit
    close(TRUE)
  end

  def onAbout
    GC.start
    msg =  sprintf("This is the About dialog of the scintilla sample.\n" \
    		   "Welcome to %s", VERSION_STRING)

    message_box(msg, "About Scintilla", OK | ICON_INFORMATION, self)

  end

  def onWhitespace
    @ws_visible = !@ws_visible
    @sci.set_view_white_space(@ws_visible ? SCI_WS_VISIBLEALWAYS : SCI_WS_INVISIBLE)
  end

  def onEOL
    @eol_visible = !@eol_visible
    @sci.set_view_eol(@eol_visible)
  end

  def onCharadded(evt)
    chr =  evt.get_key
    curr_line = @sci.get_current_line

    if(chr == 13)
        if curr_line > 0
          line_ind = @sci.get_line_indentation(curr_line - 1)
          if line_ind > 0
            @sci.set_line_indentation(curr_line, line_ind)
            @sci.goto_pos(@sci.position_from_line(curr_line)+line_ind)
          end
        end
    end
  end

  def onMarginClick(evt)
    line_num = @sci.line_from_position(evt.get_position)
    margin = evt.get_margin

    if(margin == 1)
      @sci.toggle_fold(line_num)
    end
  end

end

class RbApp < App
  def on_init
    frame = MyFrame.new("wxRuby Scintilla App",Point.new(50, 50), Size.new(450, 340))

    frame.show(TRUE)

  end
end

a = RbApp.new
a.main_loop()
puts("back from main_loop...")
GC.start
puts("survived gc")