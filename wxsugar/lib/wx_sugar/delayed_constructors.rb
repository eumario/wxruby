require 'wx_sugar/class_definitions'

win_classes = [ WxSugar::FRAME_CLASSES, 
                WxSugar::DIALOG_CLASSES,
                WxSugar::MISC_WINDOW_CLASSES,
                WxSugar::CONTROL_CLASSES ].flatten

# = Wx Extensions - Delayed Constructors
# 
# Intended mainly for use with the +layout+ extension, adds additional
# class methods to all Window classes that return a proc that can be
# called later to attach a Window created with the specified args to a
# parent.
win_classes.flatten.each do | klass |
  # Returns a Proc object that when called with a single argument,
  # +parent+, will return a new widget constructed according to +args+ 
  def klass.[](*args)
    # Deal with id parameter if none specified
    if self.param_spec[0].name == :id and not args[0].kind_of?(Fixnum)
      args.unshift(-1)
    end
    lambda { | parent | new(parent, *args) }
  end

  # Alias for klass.[]
  def klass.child(*args)
    lambda { | parent | new(parent, *args) }
  end
end
