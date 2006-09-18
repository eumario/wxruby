require 'wx'
include Wx

BUTTON_CLOSE = 1003

class MyFrame < Frame
    def initialize
        super(nil, -1, "Wx::Frame demonstration", DEFAULT_POSITION, Size.new(350,200), DEFAULT_FRAME_STYLE)
        panel = Panel.new(self, -1)
        
        button = Button.new(panel, BUTTON_CLOSE, "Close me", Point.new(15,15))
        
        
        evt_button(BUTTON_CLOSE) {onCloseMe}
        evt_close {onCloseWindow}
        
    end
    
    def onCloseMe
        close(true)
    end
    
    def onCloseWindow
        destroy
    end
    
end

module Demo
    def Demo.run(frame, nb, log)
        win = MyFrame.new
        frame.otherWin = win
        win.show(true)
    end
    
    def Demo.overview
        return "This is the wxFrame Overview!"
    
    end
end


if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
