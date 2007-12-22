module XRC2Ruby::ObjectTypes
  # Module used by all Windows which can contain other windows,
  # optionally arranging those windows with a Sizer
  module Parent 
    attr_reader :children, :sizer_items, :main_sizer

    def add_child(child)
      @children ||= []
      @children << child
      if child.kind_of?(Sizer) and not main_sizer
        @main_sizer = child
      end
    end

    # Associates a sizer_item with this parent; keep a map of which
    # settings apply to which child
    def size_child(sizer_item)
      @sizers ||= {}
      @sizers[sizer_item.window] = sizer_item
    end
    
    def output
      super + child_output
    end

    # Returns a string containing the ruby code needed to instantiate
    # all the child windows of this container, as well as arranging them
    # in any sizer.
    def child_output
      output = ''
      if children
        children.each_with_index do | child, i |
          output += child.output + "\n"
          if @sizers and ( sizer_item = @sizers[child] )
            output += sizer_item.output
          end
        end
      end

      if self.main_sizer
        output << "#{var_name}.sizer = #{main_sizer.var_name}"
      end
      output
    end

    # Collects all the contained windows (recursively) that have
    # user-defined names that should be exposed externally. Used by
    # top-level windows to create a list of attribute readers to access
    # named controls within the window.
    def named_windows
      return [] unless children
      children.inject([]) do | names, child |
        names << child.name if child.name
        names += child.named_windows if child.kind_of?(Parent)
        names
      end
    end
  end
end
