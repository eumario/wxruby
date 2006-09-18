require 'wx'

class ScrolledMessageDialog < Wx::Dialog
    def initialize(parent, msg, caption, pos = Wx::DEFAULT_POSITION, size = Wx::Size.new(500,300))
        super(parent, -1, caption, pos, size)
        x,y = pos.x, pos.y
        if x == -1 and y == -1
            center_on_screen(Wx::BOTH)
        end
        text = Wx::TextCtrl.new(self, -1, msg, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::TE_MULTILINE | Wx::TE_READONLY)
        ok = Wx::Button.new(self, Wx::ID_OK, "OK")
        lc = Wx::LayoutConstraints.new()
        lc.top.same_as(self, Wx::LAYOUT_TOP, 5)
        lc.bottom.same_as(ok, Wx::LAYOUT_TOP, 5)
        lc.right.same_as(self, Wx::LAYOUT_RIGHT, 5)
        lc.left.same_as(self, Wx::LAYOUT_LEFT, 5)
        
        text.set_constraints(lc)
        
        lc = Wx::LayoutConstraints.new()
        lc.bottom.same_as(self, Wx::LAYOUT_BOTTOM, 5)
        lc.centre_x.percent_of(self, Wx::LAYOUT_WIDTH, 50)
        lc.width.absolute(80)
        lc.height.absolute(25)
        
        ok.set_constraints(lc)
        set_auto_layout(true)
        layout()
    end
end

module Demo
    def Demo.run(frame, nb, log)
        f = open(__FILE__, "r")
        msg = f.read()
        dlg = ScrolledMessageDialog.new(frame, msg, "message test")
        dlg.show_modal()
    end

    def Demo.overview
        return "Ported from wxPython.  Many thanks again to Robin Dunn!"
    end
end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
