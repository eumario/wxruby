module XRC2Ruby::ObjectTypes
  class MenuBar < Window
    include Parent
    def output
      "#{var_name} = Wx::MenuBar.new\n" +
      child_output +
      "#{parent.var_name}.menu_bar = #{var_name}\n"
    end
  end

  class Menu < Window
    include Parent
    attr_accessor :label

    def output
      if XRC2Ruby.use_gettext
        the_label = "_(" + label.inspect + ")"
      else
        the_label = label.inspect
      end
      # A standard menu attached to menubar; NB - call to append must
      # come after all menu items have been created
      if parent.kind_of?(MenuBar)
        "#{var_name} = Wx::Menu.new\n" +
        child_output +
        "#{parent.var_name}.append(#{var_name}, #{the_label})\n"
      # If a submenu
      elsif parent.kind_of?(Menu)
        output_as_submenu(the_label)
      else
        Kernel.raise("Menu shouldn't be attached to a #{parent.class}")
      end
    end

    def output_as_submenu(label)
      
      menu_item = MenuItem.new(parent, 'wxMenuItem', 'wxMenuItem', '')
      menu_item.label = self.label
      menu_item.submenu = self.var_name
      submenu = "#{var_name} = Wx::Menu.new\n" + child_output + menu_item.output
    end
  end

  class MenuItem < Object
    attr_accessor :label, :checkable, :radio, :checked, :help, :submenu

    def initialize(parent, klass, subclass, name)
      super
      # stock id
      if name.sub!(/^wx/, "Wx::")
        @menu_id = name
      end
    end

    def output
      @help ||= ''

      # What type of menu item?
      if radio
        item_type = "Wx::ITEM_RADIO"
      elsif checkable
        item_type = "Wx::ITEM_CHECK"
      else
        item_type = "Wx::ITEM_NORMAL"
      end

      # Using a stock id
      if @menu_id
        m_i = "#{var_name} = Wx::MenuItem.new(#{parent.var_name}, #{@menu_id})"
      else
        if XRC2Ruby.use_gettext
          the_label = "_(" + label.inspect + ")"
          the_help  = "_(" + help.inspect + ")"
        else
          the_label = label.inspect
          the_help  = help.inspect
        end
        the_submenu = submenu || "nil"
        m_i = "#{var_name} = Wx::MenuItem.new(#{parent.var_name}, Wx::ID_ANY,
                   #{the_label}, #{the_help}, 
                   #{item_type}, #{the_submenu})"
      end
      m_i + "\n" + "#{parent.var_name}.append_item(#{var_name})"
    end
  end
end
