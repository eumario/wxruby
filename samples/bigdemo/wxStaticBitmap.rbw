#!/usr/bin/env ruby
# wxRuby2 Sample Code. Copyright (c) 2004-2008 wxRuby development team
# Freely reusable code: see SAMPLES-LICENSE.TXT for details
begin
  require 'rubygems' 
rescue LoadError
end
require 'wx'



class TestPanel < Wx::Panel
  def initialize(parent, log)
    super(parent, -1)
    
    Wx::StaticText.new( self, -1, "This is a wxStaticBitmap.", 
                        Wx::Point.new(45,5))
    
    bmp_file1 = File.join(File.dirname(__FILE__), 'icons', 'test2.xpm')
    Wx::StaticBitmap.new( self, -1, 
                          Wx::Bitmap.new(bmp_file1, Wx::BITMAP_TYPE_XPM), 
                          Wx::Point.new(80,25)) 
    
    bmp_file2 = File.join(File.dirname(__FILE__), 'icons', 'robert.xpm')
    Wx::StaticBitmap.new( self, -1, 
                          Wx::Bitmap.new(bmp_file2,  Wx::BITMAP_TYPE_XPM), 
                          Wx::Point.new(0, 100))

    Wx::StaticText.new( self, -1, 
                        "Hey, if Ousterhout (and Dunn) can do it, so can I.", 
                        Wx::Point.new(100, 125) )
  end
end

module Demo
  def Demo.run(frame,nb,log)
    win = TestPanel.new(nb, log)
    return win
  end
  
  def Demo.overview
    ""
  end
end


if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
