module XRC2Ruby::ObjectTypes
  class ToolBar < Window
    include Parent
    attr_accessor :dontattachtoframe
    def initialize(*args)
      super
      @tools = []
    end

    def add_tool(tool)
      @tools << tool
    end

    def setup
      @tools.inject('') { | str, tool | str + tool.output }
    end
  end

  # Not a real wxRuby class; individual tools are created by calls to
  # add_tool and friends.
  class TOOL
    attr_reader :toolbar, :var_name
    attr_accessor :bitmap, :bitmap2, :label,
                  :radio, :toggle,
                  :help, :longhelp, :tooltip

    def initialize(toolbar, an_id)
      @toolbar  = toolbar
        @var_name = an_id.downcase
      if an_id.sub!(/^wx/, "Wx::")
        @stock_id = an_id
      end
      @toolbar.add_tool(self)
    end

    def output
      @label ||= ''
      @help ||= ''
      @longhelp  ||= ''

      # Normal bitmap
      if bitmap
        bmp1 = "Wx::Bitmap.new(#{self.bitmap.inspect}, Wx::BITMAP_TYPE_PNG)"
      else
        bmp1 = "Wx::NULL_BITMAP"
      end

      # Disabled bitmap
      if bitmap2
        bmp2 = "Wx::Bitmap.new(#{self.bitmap2.inspect}, Wx::BITMAP_TYPE_PNG)"
      else
        bmp2 = "Wx::NULL_BITMAP"
      end

      # What type of tool?
      if radio
        tooltype = "Wx::ITEM_RADIO"
      elsif toggle
        tooltype = "Wx::ITEM_CHECK"
      else
        tooltype = "Wx::ITEM_NORMAL"
      end
      if @stock_id
        the_id = @stock_id
      else
        the_id = "Wx::ID_ANY"
      end
      # This is the most general form of add_tool 
      "#{var_name} = #{toolbar.var_name}.add_tool(#{the_id},
                                                  #{label.inspect},
                                                  #{bmp1},
                                                  #{bmp2},
                                                  #{tooltype},
                                                  #{help.inspect},
                                                  #{longhelp.inspect})\n"

    end
  end

  class SEPARATOR
    attr_reader :toolbar
    def initialize(toolbar_or_menu, an_id = nil)
      @toolbar = toolbar_or_menu
    end
  end
end
