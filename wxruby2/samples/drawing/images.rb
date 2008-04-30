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
    require 'stringio'
    str = ''
    File.open(img_file, 'rb') { | f | str = f.read }
    
    img_io = StringIO.new(str, 'rb')

    image = Wx::Image.new
    image.load_stream(img_io, Wx::BITMAP_TYPE_PNG)
    @bitmap = image.convert_to_bitmap

    # Set up the drawing to be done when the frame needs re-painting
    evt_paint :on_paint
  end

  def on_paint
    paint do | dc |
      dc.draw_bitmap(@bitmap, 0, 0, false)
      gdc = Wx::GraphicsContext.create(dc)
      trans_blue = Wx::Colour.new(0, 0, 255, 128)
      gdc.pen = Wx::Pen.new(trans_blue, 20)
      gdc.stroke_line(0, 0, 100, 100)
      trans_red = Wx::Colour.new(255, 0, 0, 100)
      gdc.pen = Wx::Pen.new(trans_red, 20)
      gdc.stroke_line(0, 100, 100, 0)
    end
  end
end

Wx::App.run do
  ImageFrame.new.show
end

