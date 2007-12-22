module XRC2Ruby::ObjectTypes
  # Several similar control classes have a standard Window constructor
  # with a text label; they can all share the same class
  class Labelled < Window
    translatable_string_init_arg(:label)
  end

  # These are the Wx classes that share the constructor
  class Button < Labelled; end
  class ToggleButton < Labelled; end
  class CheckBox < Labelled; end
  class RadioButton < Labelled; end

  class BitmapButton < Window
    attr_accessor :focus, :selected, :disabled, :hover
    init_arg(:bitmap) do | val | 
      "Wx::Bitmap.new('#{val}')"
    end
    
    # Call extra methods to set up images for alternate states, if these
    # have been defined in the XRC file.
    def setup
      [ :focus, :selected, :disabled, :hover ].inject('') do | out, extra_img |
        if send(extra_img)
          out << "#{var_name}.bitmap_#{extra_img} = "
          out << " Wx::Bitmap.new('#{send(extra_img)}')\n"
        end
        out
      end
    end
  end

  class SpinButton < Window
    attr_accessor :min, :max, :value
    def setup
      "#{var_name}.set_range(#{min}, #{max})\n" +
        "#{var_name}.value = #{value}\n"
    end
  end
end
