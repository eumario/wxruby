module XRC2Ruby::ObjectTypes
  # Represents the settings for a particular Window added to a
  # container's sizer; corresponds to the <object class="sizeritem"> tag
  # in XRC.
  class SizerItem
    attr_reader :flag
    attr_accessor :border, :option, :window, :sizer

    # Create a new sizer item contained within the sizer +sizer+, set up
    # default sizer options
    def initialize(sizer)
      @sizer  = sizer
      @option = 0
      @flag   = 0
      @border = 0
    end

    def flag=(flag)
      @flag = flag.gsub(/wx/, "Wx::")
    end

    # Output a Sizer#add statement, adding +window+ to +sizer+
    def output
      "#{sizer.var_name}.add(#{window.var_name}, #{option}, #{flag}, #{border})\n"
    end
  end

  # Actual sizers
  class Sizer < Object
    BASE_NAME = "sizer"
  end

  class BoxSizer < Sizer
    attr_accessor :orient
    def output
      "#{var_name} = Wx::BoxSizer.new(#{orient.gsub(/^wx/, "Wx::")})\n"
    end
  end

  class StaticBoxSizer < Sizer
    attr_accessor :orient, :label
    def output
      "#{var_name} = Wx::StaticBoxSizer.new(#{orient.gsub(/^wx/, "Wx::")}," +
        " #{parent.var_name}, '#{label}')"
    end
  end

  class FlexGridSizer < Sizer
    attr_accessor :cols, :rows, :vgap, :hgap
    def output
      "#{var_name} = Wx::StaticBoxSizer.new(#{orient.gsub(/^wx/, "Wx::")}," +
        " Wx::ID_ANY, '#{label}')"
    end
  end

  class StdDialogButtonSizer < Sizer
    attr_accessor :cols, :rows, :vgap, :hgap
    def output
      "#{var_name} = Wx::StaticBoxSizer.new(#{orient.gsub(/^wx/, "Wx::")}," +
        " Wx::ID_ANY, '#{label}')"
    end
  end

  # Not a real wxRuby class - this is a button within a
  # StdDialogButtonSizer (do not confuse with Wx::Button)
  class BUTTON
    attr_accessor :flag, :border, 
    def initialize(b_sizer, an_id)
      p an_id
    end
  end
end
