module XRC2Ruby::ObjectTypes
  # Module used to manage keyword arguments 
  module InitArgs
    def init_args
      @init_args 
    end

    # Method for defining an element called +arg_name+ which is passed
    # as part of the wxRuby constructor for a class
    def init_arg(arg_name, &block)
      attr_writer arg_name
      define_method(arg_name) do
        if val = instance_variable_get("@#{arg_name}")
          block.call(val)
        end
      end
      @init_args ||= {}
      @init_args[arg_name] = block
    end

    # Method for defining a string ctor arg that can be translated using
    # ruby-gettext, if that option is in use. For example - mneu items,
    # button labels.
    def translatable_string_init_arg(arg_name)
      if XRC2Ruby.use_gettext
        init_arg(arg_name) { | val | "_(" + val.inspect + ")" }
      else
        init_arg(arg_name) { | val | val.inspect }
      end
    end

    def inherited(kls)
      @init_args.each { | arg, proc | kls.init_arg(arg, &proc) }
    end
  end

  class Window < Object
    BASE_NAME = "window"
    self.extend InitArgs

    # Standard constructor arguments
    init_arg(:size) { | val | "Wx::Size.new(#{val})" }
    init_arg(:point) { | val | "Wx::Point.new(#{val})" }
    init_arg(:style) { | val | val.gsub(/wx/, "Wx::") }

    # Tooltip and help text, applicable to all windows
    attr_accessor :tooltip, :help, :hidden, :enabled, :fg, :bg, :exstyle
    
    def output
      # The base constructor
      if parent
        base = "#{var_name} = #{win_class}.new(#{parent.var_name}"
        base << ( args.empty? ? ")" : ",\n#{args})" )
      else
        base = "#{var_name} = #{win_class}.new(nil" 
        base << ( args.empty? ? ")" : ",\n#{args})" )
      end
      # Re-indent the keyword arguments
      indent = base.index("(") + 1
      base.gsub!(/\n:/, "\n" + (" " * indent ) + ":") || base
      base << "\n"

      # If help text is defined
      if self.help
        base << "#{var_name}.help_text = '#{self.help}'\n"
      end

      # If a tooltip is defined
      if self.tooltip
        base << "#{var_name}.tool_tip = '#{self.tooltip}'\n"
      end

      # If foreground colour is specified, convert hex->int and set
      if self.fg
        colour = self.bg.scan(/[0-9a-fA-F]{2}/).map { | e | e.to_i(16) }
        base << "#{var_name}.background_colour = "
        base << "Wx::Colour.new(#{colour.join(', ')})\n"
      end

      # If background colour is specified, convert hex->int and set
      if self.bg
        colour = self.bg.scan(/[0-9a-fA-F]{2}/).map { | e | e.to_i(16) }
        base << "#{var_name}.foreground_colour = "
        base << "Wx::Colour.new(#{colour.join(', ')})\n"
      end

      # If extra style set
      if self.exstyle
        base << "#{var_name}.extra_style = #{exstyle.gsub(/^wx/, "Wx::")}"
      end
      
      # If explicitly disabled or enabled
      if self.enabled 
        if self.enabled.to_i.zero?
          base << "#{var_name}.disable\n"
        else
          base << "#{var_name}.enable\n"
        end
      end

      # If explicitly shown or hidden
      if self.hidden 
        if self.hidden.to_i.zero?
          base << "#{var_name}.hide\n"
        else
          base << "#{var_name}.show\n"
        end
      end

      base << setup
      base
    end

    # Returns the constructor arguments as a Ruby string
    def args
      defined_args = []
      self.class.init_args.keys.each do | arg |
        if arg_val = send(arg)
          defined_args << ":#{arg} => #{arg_val}"
        end
      end
      defined_args.join(",\n")
    end

    # Some classes define XRC property elements that are set in
    # wxWidgets by method calls rather than passed as part of the
    # constructor. This method can be overridden in subclasses to return
    # a string with those arguments.
    def setup
      ''
    end
  end
end
