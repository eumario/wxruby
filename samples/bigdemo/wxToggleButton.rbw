require 'wx'

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

