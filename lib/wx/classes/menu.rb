# A single labelled list within a drop-down menu, or a popup menu
class Wx::Menu

  # In the standard WxWidgets API, the methods append, prepend, insert
  # (and their variants) require a constant integer id as the identifier
  # of the menu item. This is then used in event handling. 
  #
  # In WxRuby the use of explicit ids can be avoided in most cases,
  # being a most unruby-ish practice. So, by analogy with the general
  # use of Wx::Window classes and event handlers, where the id is
  # implicit in the constructor, and the window can be passed direct to
  # the event handler setup method, the below sets up a similar facility
  # for adding items to Wx::Menu.
  #
  # For all these methods, the only required argument is the string name
  # of the menu item; a system-default id will be supplied if no
  # explicit one is given. The return value of these methods in all
  # cases is a Wx::MenuItem object, which can be passed directly as the
  # first argument to an evt_menu handler.
  def self.methods_with_optional_ids(*meth_names)
    class_eval do 
      meth_names.each do | meth |
        old_meth = instance_method(meth)
        define_method(meth) do | *args |
          case args.first
            when Fixnum : old_meth.bind(self).call(*args)
            when String : old_meth.bind(self).call(Wx::ID_ANY, *args)
            when Wx::MenuItem : old_meth.bind(self).call(args.first)
          end
        end
      end
    end
  end

  # Create the optional-id methods
  methods_with_optional_ids :append, :prepend,
                            :append_check_item, :prepend_check_item, 
                            :append_radio_item, :prepend_radio_item

  # This is much the same as above, except for insert and variants,
  # which take an additional first argument, the position at which to
  # insert the new item.
  def self.methods_with_optional_ids_and_pos(*meth_names)
    class_eval do 
      meth_names.each do | meth |
        old_meth = instance_method(meth)
        define_method(meth) do | pos, *args |
          case args.first
            when Fixnum : old_meth.bind(self).call(pos, *args)
            when String : old_meth.bind(self).call(pos, Wx::ID_ANY, *args)
            when Wx::MenuItem : old_meth.bind(self).call(pos, args.first)
          end
        end
      end
    end
  end

  # Create the optional-id methods
  methods_with_optional_ids_and_pos :insert,
                                    :insert_check_item,
                                    :insert_radio_item
end
