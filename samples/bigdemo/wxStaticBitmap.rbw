require 'wx'

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1)
        
        Wx::StaticText.new(self, -1, "This is a wxStaticBitmap.", Wx::Point.new(45,5))
        
        Wx::StaticBitmap.new(self, -1, Wx::Bitmap.new("./icons/test2.xpm", Wx::BITMAP_TYPE_XPM), Wx::Point.new(80,25)) 
                                
        Wx::StaticBitmap.new(self, -1, Wx::Bitmap.new("./icons/robert.xpm", Wx::BITMAP_TYPE_XPM), Wx::Point.new(0, 100))
        Wx::StaticText.new(self, -1, "Hey, if Ousterhout (and Dunn) can do it, so can I.", Wx::Point.new(100, 125))
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
