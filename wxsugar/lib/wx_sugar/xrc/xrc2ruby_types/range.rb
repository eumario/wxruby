module XRC2Ruby::ObjectTypes

  class ScrollBar < Window
    attr_accessor :value, :range, :thumbsize, :pagesize
    def setup
      "#{var_name}.set_scrollbar(#{value}, #{thumbsize}, #{range}, #{pagesize})"
    end
  end
  class SpinCtrl < Window
    init_arg(:min) { | val | val }
    init_arg(:max) { | val | val }
    # This is called "value" in XRC but "initial" as a constructor
    # keyword arg
    init_arg(:initial) { | val | val }
    alias :value :initial
    alias :value= :initial=
  end

  class Slider < Window
    # These are called "xxx_value" as keyword constructor arguments, but
    # simply min/max in XRC
    init_arg(:min_value) { | val | val }
    alias :min :min_value
    alias :min= :min_value=
    init_arg(:max_value) { | val | val }
    alias :max :max_value
    alias :max= :max_value=

    init_arg(:value) { | val | val }
  end
end

