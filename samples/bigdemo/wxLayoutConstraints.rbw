require 'wx'

class TestLayoutConstraints < Wx::Panel
    def initialize(parent)
        super(parent, -1)
        set_auto_layout(true)
        evt_button(100) {|event| on_button(event)}
        
        set_background_colour(Wx::Colour.new("MEDIUM ORCHID"))
        
        @panelA = Wx::Window.new(self, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SIMPLE_BORDER)
        @panelA.set_background_colour(Wx::BLUE)
        txt = Wx::StaticText.new(@panelA, -1, "Resize the window and see\nwhat happens...  Notice that\nthere is no OnSize handler.",
                                    Wx::Point.new(5,5), Wx::Size.new(-1,50))
        txt.set_background_colour(Wx::BLUE)
        txt.set_foreground_colour(Wx::WHITE)
        
        lc = Wx::LayoutConstraints.new()
        lc.top.same_as(self, Wx::LAYOUT_TOP, 10)
        lc.left.same_as(self, Wx::LAYOUT_LEFT, 10)
        lc.bottom.same_as(self, Wx::LAYOUT_BOTTOM, 10)
        lc.right.percent_of(self, Wx::LAYOUT_RIGHT, 50)
        @panelA.set_constraints(lc)
        
        @panelB = Wx::Window.new(self, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SIMPLE_BORDER)
        @panelB.set_background_colour(Wx::RED)
        lc = Wx::LayoutConstraints.new()
        lc.top.same_as(self, Wx::LAYOUT_TOP, 10)
        lc.right.same_as(self, Wx::LAYOUT_RIGHT, 10)
        lc.bottom.percent_of(self, Wx::LAYOUT_BOTTOM, 30)
        lc.left.right_of(@panelA, 10)
        @panelB.set_constraints(lc)

        @panelC = Wx::Window.new(self, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
                               Wx::SIMPLE_BORDER)
        @panelC.set_background_colour(Wx::WHITE)
        lc = Wx::LayoutConstraints.new()
        lc.top.below(@panelB, 10)
        lc.right.same_as(self, Wx::LAYOUT_RIGHT, 10)
        lc.bottom.same_as(self, Wx::LAYOUT_BOTTOM, 10)
        lc.left.right_of(@panelA, 10)
        @panelC.set_constraints(lc)

        b = Wx::Button.new(@panelA, 100, ' Panel A ')
        lc = Wx::LayoutConstraints.new()
        lc.centre_x.same_as(@panelA, Wx::LAYOUT_CENTRE_X)
        lc.centre_y.same_as(@panelA, Wx::LAYOUT_CENTRE_Y)
        lc.height.as_is()
        lc.width.percent_of(@panelA, Wx::LAYOUT_WIDTH, 50)
        b.set_constraints(lc)

        b = Wx::Button.new(@panelB, 100, ' Panel B ')
        lc = Wx::LayoutConstraints.new()
        lc.top.same_as(@panelB, Wx::LAYOUT_TOP, 2)
        lc.right.same_as(@panelB, Wx::LAYOUT_RIGHT, 4)
        lc.height.as_is()
        lc.width.as_is()
        b.set_constraints(lc)

        @panelD = Wx::Window.new(@panelC, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE,
                            Wx::SIMPLE_BORDER)
        @panelD.set_background_colour(Wx::GREEN)
        Wx::StaticText.new(@panelD, -1, "Panel D", Wx::Point.new(4, 4)).set_background_colour(Wx::GREEN)

        b = Wx::Button.new(@panelC, 100, ' Panel C ')
        lc = Wx::LayoutConstraints.new()
        lc.top.below(@panelD)
        lc.left.right_of(@panelD)
        lc.height.as_is()
        lc.width.as_is()
        b.set_constraints(lc)

        lc = Wx::LayoutConstraints.new()
        lc.bottom.percent_of(@panelC, Wx::LAYOUT_HEIGHT, 50)
        lc.right.percent_of(@panelC, Wx::LAYOUT_WIDTH, 50)
        lc.height.same_as(b, Wx::LAYOUT_HEIGHT)
        lc.width.same_as(b, Wx::LAYOUT_WIDTH)
        @panelD.set_constraints(lc)

    end

    def on_button(event)
        
    end
end

module Demo
    def Demo.run(frame, nb, log)
        win = TestLayoutConstraints.new(nb)
        return win
    end

    def Demo.overview
        return ""
    end
end
    

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
