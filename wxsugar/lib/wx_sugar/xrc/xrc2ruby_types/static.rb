module XRC2Ruby::ObjectTypes
  class StaticText < Window
    translatable_string_init_arg(:label)
  end

  class StaticBox < Window
    translatable_string_init_arg(:label)
  end

  class StaticBitmap < Window
    init_arg(:label) { | val | "Wx::Bitmap.new('#{val}')" }
  end

  # No extra args needed
  class StaticLine < Window; end

  class Gauge < Window
    attr_accessor :value
    init_arg(:range) { | val | val }
    def setup
      value ? "#{var_name}.value = #{value}\n" : ""
    end
  end
end
