module XRC2Ruby::ObjectTypes
  # Several similar classes with list of strings
  class ControlWithItems < Window
    attr_accessor :selection

    init_arg(:choices) do | val |
      if XRC2Ruby.use_gettext
        items = val.map { | c | "_(" + c.inspect + ")" }
      else
        items = val.map { | c | c.inspect }
      end
      "[ " + items.join(", ") + " ]"
    end

    def initialize(*args)
      super
      @choices = []
    end

    def item=(item)
      @choices << item
    end

    def setup
      self.selection ? "#{var_name}.selection = #{selection}" : ""
    end
  end
  # The actual Wx classes of this type
  class ListBox < ControlWithItems; end
  class CheckListBox < ControlWithItems; end
  class Choice < ControlWithItems; end
  class ComboBox < ControlWithItems; end
  class BitmapComboBox < ControlWithItems; end
  class ListCtrl < Window; end


  class RadioBox < ControlWithItems
    translatable_string_init_arg(:label)
    # The XRC element is called "dimension" but the wxRuby arg is called
    # "major_dimension" - so make interchangeable
    init_arg(:major_dimension) { | val | val }
    alias :dimension :major_dimension
    alias :dimension= :major_dimension=
  end
end
