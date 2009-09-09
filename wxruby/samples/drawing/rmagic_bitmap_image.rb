#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'
require 'RMagick'

# RMagick sample (written by Chauk-Mean Proum)

# This sample demonstrates how to convert directly a RMagick image to
# a wxRuby image (without saving and loading the image file).
# See the magick_to_wx method.

class ImageFrame < Wx::Frame
  def initialize
    super(nil, :title => 'RMagick sample', :size => [600, 600])

    # Create the magick image from an image file
    img_file = File.join( File.dirname(__FILE__)+"/../../art",
      'wxruby-256x256.png')
    @magick_image = Magick::ImageList.new(img_file)
    
    # Create some magick images with special effects
    @magick_image1 = @magick_image.sketch
    @magick_image2 = @magick_image.oil_paint(4)
    @magick_image3 = @magick_image.shade

    # Convert the magick images to wxRuby images
    @image1 = magick_to_wx(@magick_image1)
    @image2 = magick_to_wx(@magick_image2)
    @image3 = magick_to_wx(@magick_image3)

    # Create the corresponding bitmaps
    compute_bitmaps

    # Set up event handling
    evt_size :on_size
    evt_idle :on_idle
    evt_paint :on_paint
  end
  
  
  # Convert the RMagick image to a WxRuby image
  def magick_to_wx magick_img
    wx_img = Wx::Image.new(magick_img.columns, magick_img.rows)

    # Set the image data
    wx_img.rgb_data = magick_img.to_blob { self.format = "RGB" }

    # Set the alpha (transparency) if any
    if magick_img.alpha?
      wx_img.alpha_data = magick_img.to_blob { self.format = "A" }
    end

    wx_img
  end

  # Create a bitmap for the specified image and size
  def compute_bitmap image, width, height
    rescaled_image = Wx::Image.new(image).rescale(width, height)
    rescaled_image.to_bitmap
  end

  # Create the bitmaps corresponding to the images and with half the size of the frame
  def compute_bitmaps
    width = client_size.x / 2
    height = client_size.y / 2
    @bitmap1 = compute_bitmap(@image1, width, height)
    @bitmap2 = compute_bitmap(@image2, width, height)
    @bitmap3 = compute_bitmap(@image3, width, height)
    @done = true
  end

  # Note to recompute the bitmaps on a resize
  def on_size(event)
    @done = false
    event.skip
  end

  # Recompute the bitmaps if needed, then do a refresh
  def on_idle
    if not @done
      compute_bitmaps
      refresh
    end
  end

  # Paint the frame with the bitmaps
  def on_paint
    paint do | dc |

      if @done
        offset_x = client_size.x / 4
        offset_y = client_size.y / 4
        dc.draw_bitmap(@bitmap1, 0, 0, true)
        dc.draw_bitmap(@bitmap2, offset_x, offset_y, true)
        dc.draw_bitmap(@bitmap3, offset_x*2, offset_y*2, true)
      end

    end
  end
end

Wx::App.run do
  ImageFrame.new.show
end

