module WindowTypes
  class Window < Object
    def self.init_args
      @init_args 
    end

    def self.init_arg(arg_name, &block)
      attr_writer arg_name
      define_method(arg_name) do
        if val = instance_variable_get("@#{arg_name}")
          block.call(val)
        end
      end
      @init_args ||= {}
      @init_args[arg_name] = block
    end

    def self.inherited(kls)
      @init_args.each { | arg, proc | kls.init_arg(arg, &proc) }
    end

    init_arg(:size) do | val |
      "Wx::Size.new(#{val})"
      # "[ #{val} ]"
    end

    init_arg(:point) do | val |
      "[ #{val} ]"
    end

    init_arg(:style) do | val |
      val.gsub(/wx/, "Wx::")
    end

    def args
      defined_args = []
      self.class.init_args.keys.each do | arg |
        if arg_val = send(arg)
          defined_args << ":#{arg} => #{arg_val}"
        end
      end
      defined_args.join(",\n")
    end
  end

  class Button < Window
    init_arg(:label) do | val |
      "'#{val}'"
    end
  end
end
