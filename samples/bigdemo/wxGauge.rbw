require 'wx'

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1)
        @log = log
        @count = 0
        
        Wx::StaticText.new(self, -1, "This example shows the wxGauge control.", Wx::Point.new(45,15))
        
        @g1 = Wx::Gauge.new(self, -1, 50, Wx::Point.new(110,50), Wx::Size.new(250,25))
        @g1.set_bezel_face(3)
        @g1.set_shadow_width(3)
        
        @g2 = Wx::Gauge.new(self, -1, 50, Wx::Point.new(110,95), Wx::Size.new(250,25), Wx::GA_HORIZONTAL | Wx::GA_SMOOTH)
        @g2.set_bezel_face(5)
        @g2.set_shadow_width(5)
        
        @g3 = Wx::Gauge.new(self, -1, 50, Wx::Point.new(110, 140), Wx::Size.new(25,250), Wx::GA_VERTICAL)
        @g3.set_bezel_face(3)
        @g3.set_shadow_width(3)
        
        evt_idle {|event| idle_handler(event)}
    end
    
    def idle_handler(event)
        @count = @count + 1
        if @count > 50
            @count = 0
        end
        @g1.set_value(@count)
        @g2.set_value(@count)
        @g3.set_value(@count)
        
        # Tells wxWindows that more processing is required. This function can be called by an OnIdle handler 
        # for a window or window event handler to indicate that wxApp::OnIdle should forward the OnIdle event 
        # once more to the application windows. If no window calls this function during OnIdle, then the 
        # application will remain in a passive event loop (not calling OnIdle) until a new event is posted to 
        # the application by the windowing system.
        event.request_more()  
    end
end

module Demo
    def Demo.run(frame, nb, log)
        win = TestPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        return "A gauge is a horizontal or vertical bar which shows a quantity (often time). "
    end
end
