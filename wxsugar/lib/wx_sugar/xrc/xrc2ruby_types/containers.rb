module XRC2Ruby::ObjectTypes
  class Container < Window
    include Parent
  end
  # These don't need any special setup
  class Panel < Container; end
  class SashWindow < Container; end
  class SashLayoutWindow < Container; end

  class ScrolledWindow < Container
    attr_accessor :ppux, :ppuy, :unitsx, :unitsy
    def setup
      "#{var_name}.set_scrollbars(#{ppux}, #{ppuy}, #{unitsx}, #{unitsy})"
    end
  end

  # This has several options
  class SplitterWindow < Container
    attr_accessor :orientation, :sashpos, :minsize, :gravity

    def output 
      # Fiddly - we have to have created the child windows before we can
      # split them in the 
      base = super 

      unless children
        Kernel.raise "SplitterWindow must have children to split"
      end
      child_wins = children.grep(Window)
      if child_wins.length != 2
        Kernel.raise "SplitterWindow must have exactly two children"
      end

      child_args = "#{child_wins[0].var_name}, #{child_wins[1].var_name}"
      if orientation == 'vertical'
        base << "#{var_name}.split_vertically(#{child_args})\n"
      else
        base << "#{var_name}.split_horizontally(#{child_args})\n"
      end
      base
    end

    def setup 
      setup = ""
      if minsize
        setup << "#{var_name}.minimum_pane_size = #{minsize}\n"
      end
      if sashpos
        setup << "#{var_name}.sash_position = #{sashpos}\n"
      end
      if gravity
        setup << "#{var_name}.sash_gravity = #{gravity}\n"
      end

      setup
    end
  end
  
  class CollapsiblePane < Container
    translatable_string_init_arg(:label)
    attr_accessor :collapsed
    def setup
      if collapsed.to_i.zero?
        "#{var_name}.expand"
      else
        "#{var_name}.collapse"
      end
    end
    
    def pane=(pane)
      @children = [pane]
    end
  end

  # Special class for the interior pane of a CollapsiblePane; not
  # represented by a "real" Window in wxRuby, instead accessed via
  # CollapsiblePane#get_pane
  class PANEWINDOW < Container
    attr_reader :coll_pane
    def initialize(coll_pane, an_id = nil)
      @coll_pane = coll_pane
      @coll_pane.pane = self
    end

    def var_name 
      "#{coll_pane.var_name}.pane"
    end

    def output
      "\n" + child_output
    end
  end

  class StatusBar < Container
    attr_accessor :fields, :widths
    def setup
      setup = "#{var_name}.fields_count = #{fields}"
      if widths
        setup << "\n#{var_name}.status_widths = [ #{widths} ]"
      end
      setup << "\n#{parent.var_name}.status_bar = #{var_name}"
      setup
    end
  end
end
