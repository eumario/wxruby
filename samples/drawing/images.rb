#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'


# This sample demonstrates how to draw an image from a file onto a
# window. This one uses a small PNG file, but other formats such as JPEG
# are supported - see documentation for more details.

class ImageFrame < Wx::Frame
  def initialize
    super(nil, :title => 'Simple image demo')

    # Load a PNG bitmap from a file for drawing
    img_file = File.join( File.dirname(__FILE__), 'paperclip.png')
    @bitmap = Wx::Bitmap.new(img_file, Wx::BITMAP_TYPE_PNG)

    # Set up the drawing to be done when the frame needs re-painting
    evt_paint :on_paint
  end

  def on_paint
    paint do | dc |
      dc.draw_bitmap(@bitmap, 0, 0, false)
    end
  end
end

Wx::App.run do
  ImageFrame.new.show
end

