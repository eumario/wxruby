# = WxRuby Extensions - Keyword Constructors
# 
# The *Keyword Constructors* extension allows the use of Ruby hash-style
# keyword arguments in constructors of common WxWidgets Windows, Frame,
# Dialog and Control classes.
# 
# == Introduction
#
# Building a GUI in WxWidgets involves lots of calls to +new+, but
# these methods often have long parameter lists. Often the default
# values for many of these parameters are correct. For example, if
# you're using a sizer-based layout, you usually don't want to specify a
# size for widgets, but you still have to type
#  
#  Wx::TreeCtrl.new( parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, 
#                    Wx::NO_BUTTONS )
#  
# just to create a standard TreeCtrl with the 'no buttons' style. If you
# want to specify the 'NO BUTTONS' style, you can't avoid all the typing
# of DEFAULT_POSITION etc.
#
# == Basic Keyword Constructors
# 
# With keyword_constructors, you could write the above as
# 
#  TreeCtrl.new(parent, :style => Wx::NO_BUTTONS)
# 
# And it will assume you want the default id (-1), and the default size
# and position. If you want to specify an explicit size, you can do so:
#
#  TreeCtrl.new(parent, :size => Wx::Size.new(100, 300))
# 
# For brevity, this module also allows you to specify positions and
# sizes using a a two-element array:
#  
#  TreeCtrl.new(parent, :size => [100, 300])
#
# Similarly with position:
#
#  TreeCtrl.new(parent, :pos => Wx::Point.new(5, 25))
#
#  TreeCtrl.new(parent, :pos => [5, 25])
#
# You can have multiple keyword arguments:
#
#  TreeCtrl.new(parent, :pos => [5, 25], :size => [100, 300] )
#
# == No ID required
# 
# As with position and size, you usually don't want to deal with
# assigning unique ids to every widget and frame you create - it's a C++
# hangover that often seems clunky in Ruby. The *Event Connectors*
# extension allows you to set up event handling without having to use
# ids, and if no :id argument is supplied to a constructor, the default
# (-1) will be passed.
#
# There are occasions when a specific ID does need to be used - for
# example, to tell WxWidgets that a button is a 'stock' item, so that it
# can be displayed using platform-standard text and icon. To do this,
# simply pass an :id argument to the constructor - here, the system's
# standard 'preview' button
#
#  Wx::Button.new(parent, :id => Wx::ID_PREVIEW) 
#
# == Class-specific arguments
# 
# The arguments :size, :pos and :style are common to many WxWidgets
# window classes. The +new+ methods of these classes also have
# parameters that are specific to those classes; for example, the text
# label on a button, or the initial value of a text control.
# 
#  Wx::Button.new(parent, :label => 'press me')
#  Wx::TextCtrl.new(parent, :value => 'type some text here')
#
# The keyword names of these arguments can be found by looking at the
# WxRuby documentation, in the relevant class's +new+ method. You can
# also get a string description of the class's +new+ method parameters
# within Ruby by doing:
# 
#  puts Wx::TextCtrl.describe_constructor()
# 
# This will print a list of the argument names expected by the class's
# +new+ method, and the correct type for them.
#
# == Mixing positional and keyword arguments
#
# To support existing code, and to avoid forcing the use of more verbose
# keyword-style arguments where they're not desired, you can mix
# positional and keyword arguments, omitting or including +id+s as
# desired.
#
#  Wx::Button.new(parent, 'press me', :style => Wx::BU_RIGHT)

module Wx
  module KeywordConstructor
    module ClassMethods

      # Common Wx constructor argument keywords, with their default values.
      STANDARD_DEFAULTS = {
        :id        => -1,
        :size      => Wx::DEFAULT_SIZE,
        :pos       => Wx::DEFAULT_POSITION,
        :style     => 0,
        :validator => Wx::DEFAULT_VALIDATOR,
        :choices   => [] # for Choice, ComboBox etc
      }

      
      # A named parameter in a Wx constructor parameter list
      Parameter = Struct.new( :name, :default )

      attr_writer :param_spec
      def param_spec
        @param_spec ||= []
      end

      attr_writer :param_flags
      def param_flags
        @param_flags ||= {}
      end

      
      # Adds a list of named parameters *params* to the parameter
      # specification for this Wx class's constructor. Each parameter
      # should be specified as a either a common known symbol, such as
      # +:size+ or +:pos:+ or +:style:+ (corresponding to the common
      # constructor arguments in WxWidgets API), or a single-key with the
      # key the name of the argument, and the value a default value.
      # 
      # Parameters should be specified in the order they occur in the Wx
      # API constructor
      def wx_ctor_params(*params)
        self.param_spec += params.map do | param |
          param.kind_of?(Hash) ? Parameter[*param.to_a.flatten] : 
            Parameter[param, STANDARD_DEFAULTS[param] ]
        end
      end

      def args_as_list(*mixed_args)
        # get keyword arguments from mixed args if supplied, else empty
        kwa = mixed_args.last.kind_of?(Hash) ? mixed_args.pop : {}
        out_args = []
        param_spec.zip(mixed_args) do | param, arg |
          if arg # use the supplied list arg 
            out_args << arg
          elsif kwa.key?(param.name) # use the keyword arg
            out_args << kwa[param.name]
          else # use the default argument
            out_args << param.default
          end
        end
        out_args
      rescue
        Kernel.raise ArgumentError, 
                     "Bad arg composition of #{mixed_args.inspect}"
      end

      def args_as_hash(*mixed_args)
        kwa = mixed_args.last.kind_of?(Hash) ? mixed_args.pop : {}
        param_spec.zip(mixed_args) do | param, arg |
          kwa[param.name] = arg if arg
        end
        kwa 
      end
      
      def describe_constructor()
        param_spec.inject("") do | desc, param |
          desc << "#{param.name} (#{param.default.class.name})\n"
        end
      end
    end

    def self.included(klass)
      klass.extend ClassMethods
      klass.module_eval do

        alias :pre_wx_kwctor_init :initialize

        def initialize(parent = :default_ctor, *mixed_args)
          # allow zero-args ctor for use with XRC
          if parent == :default_ctor
            pre_wx_kwctor_init()
            return
          end

          # Allow classes to ignore :id argument in positional args
          unless self.class < Wx::Dialog
            if not mixed_args[0].kind_of?(Fixnum)
              mixed_args.unshift(-1) 
            end
          end

          real_args = [ parent ] + self.class.args_as_list(*mixed_args)
          begin
            pre_wx_kwctor_init(*real_args)
          rescue
            msg = "Error initializing #{self.inspect} \n" +
                  "Sent parameters: #{real_args.inspect}\n" +
                   "Correct parameters are:\n" + 
                   self.class.describe_constructor()
            Kernel.raise ArgumentError, msg
          end
          
          yield self if block_given?
        end
      end
      
      # Any class inheriting from a class including this module must have
      # its own copy of the param_spec
      def klass.inherited(sub_klass)
        sub_klass.instance_variable_set(:@param_spec, 
                                        instance_variable_get(:@param_spec) )
        sub_klass.instance_variable_set(:@param_flags, 
                                        instance_variable_get(:@param_flags) )
      end
    end
  end
end

