# = WxSugar - Layout
# 
# The *Layout* extension provides an easier interface to WxWidgets
# Sizers, in order to create GUI widget layouts that adapt as windows
# are resized and widgets added and deleted.
# 
# == Introduction
#
# In most GUI applications, rather than specifying the size and position
# of widgets in fixed pixels, it's desirable to specify their *relative*
# position and size and let the GUI adapt the actual display to reflect:
#
# * The varying size of standard window chrome (title and status bars,
#   standard buttons etc) across different OSes and themes
# * User resizing of application windows
# * Event-driven GUI updates (showing, altering or removing widgets)
# 
# It is possible but very laborious to handle all of these
# manually. Fortunately, WxWidgets and WxRuby include the flexible and
# powerful _Sizer_ classes. Unfortunately, getting the desired effect
# with Sizers can be a tricky matter of trial and error. The +Arranger+
# module aims to simplify the use of sizer-based layouts.
# 
# == Overview
# 
# A limited number of WxWidgets windows can contain other controls;
# these include Wx::Panel, Wx::Frame (and descendants) and Wx::Dialog
# (and descendants). To create flexible, resizeable layouts of controls
# within these windows involves a few simple steps when this module is
# in effect.
# 
# 1. Create the container window as normal
# 2. Declare the layout strategy desired for that window by calling one
#    of its +arrange_+ methods
# 3. Add child widgets to the container using its +add+ method, passing
#    any hints about how the child widget should be resized.
#
# Here's a simple example that lays out three checkboxes side-by-side,
# with some padding space around them
#
#  require 'wx_extensions/layout'
#  ...
#  panel = Wx::Panel.new(parent, -1) # create the container
#  panel.arrange_horizontally(:padding => 4) # specify layout strategy
#  panel.add( Wx::CheckBox.new(panel, -1, 'item A') ) # add item,
#  panel.add( Wx::CheckBox.new(panel, -1, 'item B') ) # another,
#  panel.add( Wx::CheckBox.new(panel, -1, 'item C') ) # and another

require 'wx_sugar/class_definitions'

module WxSugar
module Arranger
  def self.included(klass)
    old_meths = klass.instance_methods
    # Needs to be correct for both ruby 1.8 and ruby 1.9
    unless old_meths.include?('add') or old_meths.include?(:add)
      # don't over-write methods in sizer
      klass.module_eval { alias_method :add, :nest }
    end
  end
  
  attr_accessor :padding
  
  # Returns the underlying sizer currently being used by this
  # container. User code should not normally need to call this method.
  def current_sizer()
    if @current_sizer
      return @current_sizer 
    else
      begin 
        if @current_sizer = self.get_sizer
          return @current_sizer
        end
      rescue RuntimeError # Some wxRuby versions would error on get_sizer
      end
    end
    
    @current_sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    self.set_sizer(@current_sizer)
    @current_sizer
  end
  
  # Set the main or current sizer of this container window to be
  # +a_sizer+. If no block is given, then +a_sizer+ is used as the main
  # default sizer for this window. Note that this form should only be
  # called once, *before* any child widgets have been added to the
  # container.
  #
  # If a block is passed, then the +a_sizer+ is nested within the
  # container window's main default sizer. For the duration of the block
  # Widgets added to the container will be added to the nested sizer. If
  # the nested form is called, +layout+ may contain a layout hint
  # hash. This can contain the key +:proportion+, which should specify
  # the integer resizing proportion for this nested sizer within the
  # container's main arrangement.
  def arrange(a_sizer, layout = {})
    # run as a subordinate block
    if block_given? and @current_sizer
      if layout[:padding]
        old_padding = @padding
        @padding = layout[:padding] 
      end

      superior_sizer, @current_sizer = @current_sizer, a_sizer
      yield(a_sizer)
      @current_sizer = superior_sizer
      proportion = layout[:proportion] || 0
      this_padding = padding || 0
      superior_sizer.add( a_sizer, proportion, 
                          Wx::EXPAND|Wx::ALL|Wx::ADJUST_MINSIZE,
                         this_padding)

      if layout[:padding]
        @padding = old_padding
      end
    # set as main sizer            
    else
      if @current_sizer
        warn "Sizer already specified, redefining layout for #{self}"
      end        
      @padding = layout[:padding] if layout[:padding]
      @current_sizer = a_sizer
      yield(a_sizer) if block_given?
      self.set_sizer(a_sizer)
    end
  end

  # Add +child+ to the container window's layout, sizing and placing it
  # according to +layout_hints+
  #
  # Layout hints may contain the keys
  #  :proportion
  #  :minsize
  def nest(child, layout_hints = {})
    child  = build_child(child)
    layout = hints_to_constants(layout_hints)
    proportion = layout_hints[:proportion] || 0
    siz = self.current_sizer
    padding = layout_hints[:padding] || @padding

    siz.add(child, proportion, layout, padding || 0)
    siz.layout()
    
    yield child if block_given?
    return child
  end

  
  def arrange_vertically( layout = { }, &block )
    arrange_linear( layout.merge( :direction => :vertical ), &block )
  end

  def arrange_horizontally( layout = { }, &block )
    arrange_linear( layout.merge( :direction => :horizontal ), &block )
  end
  
  def arrange_linear( layout = { }, &block)
    if layout[:direction].to_s.downcase == 'horizontal'
      direction = Wx::HORIZONTAL
    elsif layout[:direction].to_s.downcase == 'vertical'
      direction = Wx::VERTICAL
    else
      Kernel.raise ArgumentError, 
                   "Unknown direction '#{layout[:direction].inspect}'"
    end
    
    if layout[:label]
      sb = Wx::StaticBox.new( self, -1, layout[:label] )
      sizer = Wx::StaticBoxSizer.new( sb, direction )
    elsif layout[:box]
      sb = Wx::StaticBox.new( self, -1, '' )
      sizer = Wx::StaticBoxSizer.new( sb, direction )
    else
      sizer = Wx::BoxSizer.new(direction)
    end
    arrange(sizer, layout, &block)
  end
  
  # takes hash arguments +layout+
  # 
  #  :rows - integer, number of rows (mandatory, see below)
  #  :cols - integer, number of columns (mandatory, see below)
  #  :vgap - integer, extra vertical space between each child (optional)
  #  :hgap - integer, extra horizontal space between each child (optional)
  #
  # At least one of +:rows+ and +:cols+ must be specified. If one is not
  # specified, the other will be calculated dynamically based on the
  # total number of child widgets added.
  # 
  def arrange_grid(layout, &block)
    unless layout[:rows] or layout[:cols]
      Kernel.raise ArgumentError,
                   "At least one of :rows or :cols must be specified"
    end

    if layout[:padding]
      layout[:vgap] = layout[:hgap] = layout[:padding]
    end

    # wxruby wants them in this order, and with nought if null
    args = [ :rows, :cols, :vgap, :hgap ].map { | arg | layout[arg] or 0 }
    sizer = Wx::FlexGridSizer.new(*args)
    arrange( sizer, layout, &block )
  end
  
  # Construct a WxWidget as specified by +child+ to add to my arrangement 
  def build_child(child)
    case child
    when Proc # delayed constructor
      child = child.call(self)
    when Class # bare class
      child = child.new(self)
    when Wx::Window, Wx::Sizer # ready-to-go widget
      child = child
    else
      Kernel.raise ArgumentError,
                   "Cannot add #{child.inspect} to #{self}"
    end
  end

  # Convert a hash of layout hints to WxWidgets Sizer constants
  
  def hints_to_constants(layout_hints)
    if layout_hints[:pad]
      layout = layout_hints[:pad].split(',').inject(0) do | l, edge |
        l | Wx::const_get(edge.upcase)
      end
    else
      layout = Wx::ALL
    end

    if layout_hints[:minsize]
      layout = layout | Wx::ADJUST_MINSIZE|Wx::EXPAND
    end
    if layout_hints[:proportion]
      layout = layout | Wx::EXPAND
    end

    
    if align = layout_hints[:align]
      begin
        align_const = Wx::const_get('ALIGN_' << align.to_s.upcase)
        layout = layout | align_const
      rescue NameError
        Kernel.raise ArgumentError,
                     "Invalid align argument #{layout_hints[:align]}"
      end
    end
    layout
  end
end
end

win_classes = [ WxSugar::FRAME_CLASSES, 
                WxSugar::DIALOG_CLASSES,
                WxSugar::SIZER_CLASSES,
                WxSugar::MISC_WINDOW_CLASSES ].flatten

win_classes.each do | klass |
  klass.class_eval { include WxSugar::Arranger }
end                
