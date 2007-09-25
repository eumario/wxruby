# A single labelled list within a drop-down menu, or a popup menu
class Wx::Menu
  # Allow an event handler to be tacked onto append
  alias :__wx_append :append
  def append(*args, &block)
    menu_item = case args.first
      when Fixnum : __wx_append(*args)
      when String : __wx_append(Wx::ID_ANY, *args)
      when Wx::MenuItem : __wx_append(args.first)
    end
    # set up an event handler, if requested
    if block
      evt_menu menu_item, block
    end
    menu_item
  end

  # Allow an event handler to be tacked onto insert
  alias :__wx_insert__ :insert
  def insert(pos, *args, &block)
    menu_item = case args.first
      when Fixnum : __wx_insert(pos, *args)
      when String : __wx_insert(pos, Wx::ID_ANY, *args)
      when Wx::MenuItem : __wx_insert(args.first)
    end
    # set up an event handler, if requested
    if block
      evt_menu menu_item, block
    end
    menu_item
  end

  # Allow an event handler to be tacked onto append
  alias :__wx_preend :prepend
  def prepend(*args, &block)
    menu_item = case args.first
      when Fixnum : __wx_prepend(*args)
      when String : __wx_prepend(Wx::ID_ANY, *args)
      when Wx::MenuItem : __wx_prepend(args.first)
    end
    # set up an event handler, if requested
    if block
      evt_menu menu_item, block
    end
    menu_item
  end
end
