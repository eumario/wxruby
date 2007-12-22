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
end
