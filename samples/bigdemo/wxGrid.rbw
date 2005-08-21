require 'wx'

$buttonDefs = {
    814 => ['GridSimple',      ' Simple wxGrid'] # , catching all events '] ,
    # 815 => ['GridStdEdRend',   ' wxGrid showing Editors and Renderers '],
    # 818 => ['GridHugeTable',   ' A wxGrid with a HUGE table [100 MILLION cells!] '],
    # 817 => ['GridCustTable',   ' wxGrid using a custom Table, with non-string data '],
    # 819 => ['GridEnterHandler',' Remapping keys to behave differently '],
    # 820 => ['GridCustEditor',  ' Shows how to create a custom Cell Editor '],
    # 821 => ['GridDragable',    ' A wxGrid with dragable rows and columns '],
    # 822 => ['GridDragAndDrop', 'Shows how to make a grid a drop target for files'],
    }

class ButtonPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1)
        @log = log
        
        box = Wx::BoxSizer.new(Wx::VERTICAL)
        box.add(20,30)
        keys = $buttonDefs.keys().sort()
        keys.each do |key| 
            text = $buttonDefs[key][1]
            btn = Wx::Button.new(self, key, text)
            box.add(btn, 0, Wx::ALIGN_CENTER | Wx::ALL, 10)
            evt_button(key) {|event| on_button(event)}
        end
        set_sizer(box)
    end
    
    def on_button(event)
        modName = $buttonDefs[event.get_id()][0]
        load modName + ".rbw"
        frame = GridDemo::TestFrame.new(nil, @log)
        frame.show()
    end
end

module Demo
    def Demo.run(frame,nb,log)
        win = ButtonPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        "A simple grid."
    end
end

