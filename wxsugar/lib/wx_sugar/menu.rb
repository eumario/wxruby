module Wx::Extensions
  module EasyMenuName
    def clean_name(str)
      str.gsub(/\&/, '')
    end
    
    def internal_name(str)
       str.gsub(/\s+/, "_").gsub(/\W/, "").downcase
    end
  end
  
  module EasyMenuBar
    include EasyMenuName
    attr_accessor :target, :source
    def connect(source, target = source)
      self.source = source
      # source.set_menu_bar(self)
      self.target = target
    end
    
    def add_menu(title)
      menu = Wx::Menu.new()
      menu.target  = self.target
      menu.source  = self.source
      yield menu
      append(menu, title)
      # these are here because wxruby 0.6.0 doesn't 
      # support get_menu and find_menue
      menu_labels << internal_name(title)
      menu_menus << menu
      menu
    end

    def menu_menus()
      @menu_menus||= []
    end
    
    def menu_labels()
      @menu_labels ||= []
    end
    
    def get_menu(idx)
      menu_menus[idx]
    end
    
    # only used if find_menu is not available in WxRuby
    def find_menu(str)
      menu_labels.index( internal_name(str) ) || Wx::NOT_FOUND
    end
    
    # Return the Menu item corresponding to +menu_id+. This can be a zero-based
    # integer specifying the menu's offset within the MenuBar, or a string
    # title, with or without accelerator key.
    def [](menu_id)
      case menu_id
      when Integer
        index = menu_id
      when String
        # a_MenuBar.find_menu missing in wxruby 0.6.0
        index = find_menu(menu_id)
        raise RuntimeError, "No menu called #{menu_id}" if index == Wx::NOT_FOUND
      else
        raise ArgumentError, "Bad menu specifier #{menu_id.inspect}"       
      end
      get_menu(index)
    end
  end
  
  module EasyMenu
    include EasyMenuName
    @base_id = 1000
    def self.next_id()
      @base_id = @base_id ? @base_id + 1 : 2000
    end

    # The target window for menu events from this source
    attr_accessor :target, :source
    def menu_ids(*args)
      @menu_ids ||= {}
    end
    
    def next_id()
      EasyMenu.next_id()
    end
    
    def [](ident)
      case ident
      when String, Symbol
        menu_id = menu_ids[internal_name(ident)] or
          raise RuntimeError, "Not found #{ident} #{menu_ids.inspect}"
      when Fixnum
        menu_id = ident
      end
      # find_item(menu_id)
    end
    
    # adds the item +command_str+ to the menu, with the optional
    # shortcut key +command_key+, and sets it to run the associated
    # block when the menu item is chosen. The menu item can later be
    # referred to by the symbol with the commands name with special
    # characters removed andspaces turned to underscores. For
    # example, "Save Project" becomes :save_project
    # 
    # The handler event can be specified in a number of ways:
    # 1. Passing a block, which can optionally receive an event parameter
    # 2. Passing a :handler option, which can be a method name in the target,
    #    or a Proc or BoundMethod object.
    # 3. Simply defining a method in the +target+ called on_xxxx, where xxxx
    #    is the lower-case name of the menu item with special characters removed.
    #
    # So, if creating a menu item called 'Save Project', simply define a method
    # called +on_save_project+ in the event target.
    def add(command_str, options = {}, &block)
      ident = internal_name(command_str)
      const = options[:sys_id] || self.next_id()
      menu_ids[ident] = const
      
      # Find out how the handler is defined:
      # Using an explicit block?
      if block
        handler = block
      # Specifying a :handler in the options hash
      elsif meth = options[:handler]
        # .. a method object?
        if meth.respond_to?(:call)
          handler = meth
        # .. or a method name?
        else
          handler = target.method(meth)
        end
      # or else try guessing name from among target's methods
      else
        handler = target.method('on_' << ident)
      end
      
      if options[:checked]
        itemtype = Wx::ITEM_CHECK
      elsif options[:radio]
        itemtype = Wx::ITEM_RADIO
      else
        itemtype = Wx::ITEM_NORMAL
      end
      
      command_key = options[:shortcut] || ''
      append(const, "#{command_str}\t#{command_key}", "", itemtype)
      # define the WxWidgets handler, passing a event object if required
      if handler.arity == 1
        source.evt_menu(const) { | e | handler.call(e) }
      else
        source.evt_menu(const) { handler.call() }
      end
      return ident
    end

    def add_separator
      append_separator
    end
    
    # pass a series of symbol idents eg :save_project, :close
    def enable_items(*idents)
      idents.each { | ident | self.enable( self[ident], true ) }
    end
    alias :enable_item :enable_items

    def disable_items(*idents)
      idents.each { | ident | self.enable( self[ident], false ) }
    end
    alias :disable_item :disable_items

    def check_items(*idents)
      idents.each { | ident | self.check( self[ident], true ) }
    end
    alias :check_item :check_items

    def uncheck_items(*idents)
      idents.each { | ident | self.check( self[ident], false ) }
    end
    alias :uncheck_item :uncheck_items
  end
  class Wx::MenuBar
    include EasyMenuBar
  end
  class Wx::Menu
    include EasyMenu
  end 
end
