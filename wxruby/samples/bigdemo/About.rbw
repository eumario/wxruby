module About

class MyAboutBox < Wx::Dialog
    def initialize(parent)
        super(parent, -1, "About the WxRuby Demo.")
        sizer = Wx::BoxSizer.new(Wx::HORIZONTAL)
        set_size(Wx::Size.new(510,310))
        headerFont = Wx::Font.new(36, Wx::SWISS, Wx::NORMAL, Wx::NORMAL)
        bodyFont = Wx::Font.new(12, Wx::SWISS, Wx::NORMAL, Wx::NORMAL)
        title = Wx::StaticText.new(self, -1, "WxRuby Demo!", Wx::Point.new(20, 20))
        title.set_font(headerFont)
        
        rVersion = Wx::StaticText.new(self, -1, "Running on Ruby version " + RUBY_VERSION + " on " + RUBY_PLATFORM, Wx::Point.new(20,100))
        rVersion.set_font(bodyFont)
        rVersion.set_foreground_colour(Wx::RED)
        
        wxVersion = Wx::StaticText.new(self, -1, Wx::VERSION_STRING, Wx::Point.new(20,120))
        wxVersion.set_font(bodyFont)
        wxVersion.set_foreground_colour(Wx::BLUE)
        
        str = "Welcome to the WxRuby Demo!  This demo has been ported from the \nwxPython demo created by ROBIN DUNN (http://www.wxpython.org).\nGo ahead and click on each demo via the tree or the demo menu.\nLook at the source code - it is an excellent way to learn WxRuby!\n\nPorted by Robert Paul Carlin"
        body = Wx::StaticText.new(self, -1, str, Wx::Point.new(20, 160))
        body.set_font(bodyFont)
        
        self.centre_on_parent(Wx::BOTH)
        
        
    end
    
    
end

end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
