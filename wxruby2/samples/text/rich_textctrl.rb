#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details

# RichTextCtrl sample by Chauk-Mean P 
#
# RichTextCtrl is a sophisticated styled text editing component. This
# short sample shows the basics, but RichTextCtrl supports numerous
# other text characteristics (font, size, colour, super/subscript), as
# well as paragraph alignment and spacing, and bullets. It permits named
# text styles to be created and organised in stylesheets. It can output
# to HTML and XML, and facilities are provided for printing.
#
# Icons are taken from the Tango Icon Theme.

begin
  require 'rubygems'
rescue LoadError
end
require 'wx'

class RichTextFrame < Wx::Frame

  def initialize
    super( nil, :title => "RichTextCtrl sample", :size => [800, 600] )

    toolbar = create_tool_bar( Wx::TB_HORIZONTAL|Wx::NO_BORDER| 
                               Wx::TB_FLAT|Wx::TB_TEXT )
    toolbar.tool_bitmap_size = [ 32, 32 ]

    bold_bmp = bmp_from_png("format-text-bold.png")
    toolbar.add_check_tool( Wx::ID_BOLD, "Bold", 
                            bold_bmp, bold_bmp, "Apply bold")

    italic_bmp = bmp_from_png("format-text-italic.png")
    toolbar.add_check_tool( Wx::ID_ITALIC, "Italic",
                            italic_bmp, italic_bmp, "Apply italic")
                            
    underline_bmp = bmp_from_png("format-text-underline.png")
    toolbar.add_check_tool( Wx::ID_UNDERLINE, "Underline",
                            underline_bmp, underline_bmp, "Apply underline")
    toolbar.realize

    editor = Wx::RichTextCtrl.new(self, :style => Wx::WANTS_CHARS)
    editor.begin_font_size(18)

    editor.begin_bold
    editor.write_text "Simple RichTextCtrl sample"
    editor.end_bold
    editor.newline
    editor.begin_italic
    editor.write_text "Use the formatting buttons then type some text or "
    editor.write_text "select some text and use the buttons to apply the formatting.\n"
    editor.end_italic

    # Apply / unapply bold to selection
    evt_tool(Wx::ID_BOLD) do
      editor.apply_bold_to_selection
    end

    # Keep the pressed / unpressed state of the button in sync with the
    # current selection in the text ctrl
    evt_update_ui(Wx::ID_BOLD) do |evt|
      evt.check(editor.selection_bold?)
    end

    evt_tool(Wx::ID_ITALIC) do
      editor.apply_italic_to_selection
    end

    evt_update_ui(Wx::ID_ITALIC) do |evt|
      evt.check(editor.selection_italics?)
    end

    evt_tool(Wx::ID_UNDERLINE) do
      editor.apply_underline_to_selection
    end

    evt_update_ui(Wx::ID_UNDERLINE) do |evt|
      evt.check(editor.selection_underlined?)
    end
  end

  # Return a new bitmap corresponding to the specified PNG filename
  def bmp_from_png(filename)
    img_file = File.join( File.dirname(__FILE__), filename)
    Wx::Bitmap.new(img_file, Wx::BITMAP_TYPE_PNG)
  end
end


# The Application
Wx::App.run do 
  self.app_name = 'RichTextCtrl sample'
  frame = RichTextFrame.new
  frame.centre
  frame.show
end
