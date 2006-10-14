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
        panel = Wx::Panel.new(self, -1)
        buttons = Wx::BoxSizer.new(Wx::HORIZONTAL)
        "These are toggle buttons".split().each do |word|
            b = Wx::ToggleButton.new(panel, -1, word)
            evt_togglebutton(b.get_id()) {|event| on_toggle(event)}
            buttons.add(b, 0, Wx::ALL, 5)
        end
        panel.set_sizer(buttons)
        buttons.fit(panel)
        panel.move(Wx::Point.new(50,50))
    end
    
    def on_toggle(event)
        @log.write_text("Button " + event.get_id().to_s() + " toggled")
    end
end

module Demo
    def Demo.run(frame,nb,log)
        win = TestPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        "Wx::ToggleButton is a button that stays pressed when clicked by the user. In other words, it is similar to Wx::CheckBox in functionality but looks like a Wx::Button."
    end
end


if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
