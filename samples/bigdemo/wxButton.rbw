require 'wx'

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::NO_FULL_REPAINT_ON_RESIZE)
        @log = log
        
        b = Wx::Button.new(self, 10, "Hello", Wx::Point.new(20,20))
        evt_button(10) {|event| on_click(event)}
        b.set_background_colour(Wx::BLUE)
        b.set_foreground_colour(Wx::WHITE)
        b.set_default()
        
        b = Wx::Button.new(self, 20, "HELLO AGAIN!", Wx::Point.new(20,60), Wx::Size.new(120,45))
        evt_button(20) {|event| on_click(event)}
        b.set_tool_tip("This is a Hello button...")
        
        bmp = Wx::Bitmap.new("./icons/test2.bmp", Wx::BITMAP_TYPE_BMP)
        #mask = Wx::MaskColour.new(bmp, Wx::BLUE)
        
        #bmp.set_mask(mask)
        Wx::BitmapButton.new(self, 30, bmp, Wx::Point.new(160, 20), Wx::Size.new(bmp.get_width()+10, bmp.get_height+10))
        evt_button(30) {|event| on_click(event)}
        
    end
    
    def on_click(event)
        @log.write_text("Click! %d" % event.get_id())
    end


end

module Demo

    def Demo.run(frame, nb, log)
        win = TestPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        return "A button is a control that contains a text string or a bitmap and cab be placed on nearly any kind of window."
    end

end
