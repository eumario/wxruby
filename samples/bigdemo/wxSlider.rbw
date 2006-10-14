#!/usr/bin/env ruby

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

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1)
        @log = log
        @count = 0
        
        Wx::StaticText.new(self, -1, "This is a Wx::Slider", Wx::Point.new(45,15))
        
        slider = Wx::Slider.new(self, 100, 25, 1, 100, Wx::Point.new(30,60), Wx::Size.new(250,-1),
                                    Wx::SL_HORIZONTAL | Wx::SL_AUTOTICKS | Wx::SL_LABELS)
        slider.set_tick_freq(5,1)
    end
end

module Demo
    def Demo.run(frame,nb,log)
        win = TestPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        "A slider is a control with a handle which can be pulled back and forth to change the value."
    end
end


if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
