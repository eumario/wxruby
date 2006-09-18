require 'wx'

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::NO_FULL_REPAINT_ON_RESIZE)
        @log = log
        
        winids = []

        # Create some layout windows
        # A window like a toolbar
        @topwin = Wx::SashLayoutWindow.new(
            self, -1, Wx::DEFAULT_POSITION, Wx::Size.new(200, 30), 
            Wx::NO_BORDER|Wx::SW_3D
            )

        @topwin.set_default_size(Wx::Size.new(1000, 30))
        @topwin.set_orientation(Wx::LAYOUT_HORIZONTAL)
        @topwin.set_alignment(Wx::LAYOUT_TOP)
        @topwin.set_background_colour(Wx::Colour.new(255, 0, 0))
        @topwin.set_sash_visible(Wx::SASH_BOTTOM, true)

        winids << @topwin.get_id

        # A window like a statusbar
        @bottomwin = Wx::SashLayoutWindow.new(
                self, -1, Wx::DEFAULT_POSITION, Wx::Size.new(200, 30), 
                Wx::NO_BORDER|Wx::SW_3D
                )

        @bottomwin.set_default_size(Wx::Size.new(1000, 30))
        @bottomwin.set_orientation(Wx::LAYOUT_HORIZONTAL)
        @bottomwin.set_alignment(Wx::LAYOUT_BOTTOM)
        @bottomwin.set_background_colour(Wx::Colour.new(0, 0, 255))
        @bottomwin.set_sash_visible(Wx::SASH_TOP, true)

        winids << @bottomwin.get_id

        # A window to the left of the client window
        @leftwin1 =  Wx::SashLayoutWindow.new(
                self, -1, Wx::DEFAULT_POSITION, Wx::Size.new(200, 30), 
                Wx::NO_BORDER|Wx::SW_3D
                )

      @leftwin1.set_default_size(Wx::Size.new(120, 1000))
        @leftwin1.set_orientation(Wx::LAYOUT_VERTICAL)
        @leftwin1.set_alignment(Wx::LAYOUT_LEFT)
        @leftwin1.set_background_colour(Wx::Colour.new(0, 255, 0))
        @leftwin1.set_sash_visible(Wx::SASH_RIGHT, true)
        @leftwin1.set_extra_border_size(10)
        text_window = Wx::TextCtrl.new(
                        @leftwin1, -1, "", Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, 
                        Wx::TE_MULTILINE|Wx::SUNKEN_BORDER
                        )

        text_window.set_value("A sub window")

        winids << @leftwin1.get_id

        # Another window to the left of the client window
        @leftwin2 = Wx::SashLayoutWindow.new(
                self, -1, Wx::DEFAULT_POSITION, Wx::Size.new(200, 30), 
                Wx::NO_BORDER|Wx::SW_3D
                )

        @leftwin2.set_default_size(Wx::Size.new(120, 1000))
        @leftwin2.set_orientation(Wx::LAYOUT_VERTICAL)
        @leftwin2.set_alignment(Wx::LAYOUT_LEFT)
        @leftwin2.set_background_colour(Wx::Colour.new(0, 255, 255))
        @leftwin2.set_sash_visible(Wx::SASH_RIGHT, true)

        winids << @leftwin2.get_id

        # will occupy the space not used by the Layout Algorithm
        @remaining_space = Wx::Panel.new(self, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SUNKEN_BORDER)

        evt_sash_dragged_range(winids.min, winids.max) {|event| on_sash_drag(event) }
        evt_size {|event| on_size(event) }
    end


    def on_sash_drag(event)
        if event.get_drag_status == Wx::SASH_STATUS_OUT_OF_RANGE:
            @log.write_text('drag == out of range')
            return
        end

        eobj = event.get_event_object()
      p eobj
        if eobj == @topwin
            @log.write_text('topwin received drag event')
            @topwin.set_default_size(Wx::Size.new(1000, event.get_drag_rect.height))

        elsif eobj == @leftwin1
            @log.write_text('leftwin1 received drag event')
            @leftwin1.set_default_size(Wx::Size.new(event.get_drag_rect.width, 1000))


        elsif eobj == @leftwin2
            @log.write_text('leftwin2 received drag event')
            @leftwin2.set_default_size(Wx::Size.new(event.get_drag_rect.width, 1000))

        elsif eobj == @bottomwindow
            @log.write_text('bottomwin received drag event')
            @bottomwin.set_default_size(Wx::Size.new(1000, event.get_drag_rect.height))
        end

        Wx::LayoutAlgorithm.new.layout_window(self, @remaining_space)
        @remaining_space.refresh
    end

    def on_size(event)
        Wx::LayoutAlgorithm.new.layout_window(self, @remaining_space)
    end

end

module Demo

  def Demo.run(frame, nb, log)
    TestPanel.new(nb, log)
  end
    
  def Demo.overview
    return <<EOS
Wx::SashLayoutWindow responds to OnCalculateLayout events generated by 
wxLayoutAlgorithm. It allows the application to use simple accessors to 
specify how the window should be laid out, rather than having to respond 
to events. The fact that the class derives from Wx::SashWindow allows sashes 
to be used if required, to allow the windows to be user-resizable.

The documentation for Wx::LayoutAlgorithm explains the purpose of this class 
in more detail.
EOS
  end

end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
