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

# This sample demonstrates how to draw an image from a file onto a
# window. This one uses a small PNG file, but other formats such as JPEG
# are supported - see documentation for more details.

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
    evt_paint { on_paint }
    
    img_file = File.join( File.dirname(__FILE__), 'paperclip.png')
    # first load the image into an Image object
    image = Wx::Image.new(img_file)
    # then create a Bitmap suitable for drawing
    @bitmap = Wx::Bitmap.new(image)
  end

  def on_paint
    paint do | dc |
      dc.clear
      dc.draw_bitmap(@bitmap, 0, 0, false)
    end
  end
end

class ImagesApp < Wx::App
  def on_init
    frame = MyFrame.new("Simple Image Demo")
	frame.show
  end
end

a = ImagesApp.new
a.main_loop()
