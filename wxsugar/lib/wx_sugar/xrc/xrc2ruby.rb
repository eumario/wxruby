# container module
module XRC2Ruby
  # Whether the ruby code output should include hooks for ruby-gettext,
  # used for internationalisation of applications. 
  def self.use_gettext
    @gettext
  end

  # Sets whether gettext hooks should be included.
  def self.use_gettext=(gettext)
    @gettext = gettext
  end

  # Load definitions that know how to output Ruby code
  requires = %w|object window parent sizers containers toplevelwindows 
                static buttons text lists range books menu toolbar|
  requires.each do | req_file |
    require "wx_sugar/xrc/xrc2ruby_types/#{req_file}"
  end

  # Use REXML stream parsing
  require 'rexml/streamlistener'
  require 'rexml/parsers/baseparser'
  require 'rexml/parsers/streamparser'

  # The parser goes through the XRC file and identifies top-level
  # frames/dialogs and their child windows. Each window is turned into
  # an instance of an ObjectType class; sizers and sizer settings are
  # also stored. Each ObjectType stores the parameters associated with
  # that specific type of window, and then can later output the wxRuby
  # code to create that window.
  class Parser
    include REXML::StreamListener
    include ObjectTypes

    # The stack of all objects found - pushed onto when the tag opens,
    # popped off when the tag closes
    attr_reader :stack

    def initialize
      @stack = []
    end

    # The most recent  parent
    def last_parent
      @stack.reverse.find { | obj | obj.kind_of? Parent }
    end

    # The most recent sizer
    def last_sizer
      @stack.reverse.find { | obj | obj.kind_of? Sizer }
    end

    # Process a tag opening
    def tag_start(tag, attrs)
      case tag
      when 'resource' 
        # Top-level tag, ignore
      when 'object' # Some kind of object
        case attrs['class']
        # A set of sizer settings
        when 'sizeritem'
          stack.push( SizerItem.new(last_sizer) )

        # Some "special" object not corresponding to a standard class
        when 'panewindow', 'tool', 'separator', 'button'
          special = ObjectTypes.const_get(attrs['class'].upcase)
          stack.push( special.new(last_parent, attrs['name']) )
        # An ordinary window
        when /^wx/
          # Look up the correct representation for this object type
          kls = ObjectTypes.const_get(attrs['class'][2..-1])
          # Create and link to parent
          win = kls.new( last_parent,
                         attrs["class"], 
                         attrs["subclass"],
                         attrs["name"])

          if last_parent
            last_parent.add_child(win)
          end

          # Associate this with the containing sizer item, if there is one
          if stack.last.kind_of?(SizerItem)
            stack.last.window = win
          end
          stack.push(win)
        else
          Kernel.raise "Unexpected object of type '#{attrs['class']}' found"
        end
      else # All other tags are type-specific settings for the current tag
        @next_setting = "#{tag}="
      end
    end

    # When text is encountered, if non-empty it should be the value for
    # a setting (eg <label> within a wxButton tag)
    def text(text)
      # Ignore empty
      return if text =~ /\A\s*\z/
      if @next_setting
        @stack.last.send(@next_setting, text)
      end
      @next_setting = nil
    end

    # Process a tag ending
    def tag_end(tag)
      case tag
      when 'object'
        if stack.last.kind_of?(SizerItem)
          last_parent.size_child(@stack.last)
        end
        if stack.length == 1
          puts stack.first.output
        end
        @stack.pop
      end
    end
  end
end
