class Wx::Colour
  # Standard colours, corresponding to WxWidgets stock colours.
  Wx::WHITE = new('White')
  Wx::BLACK = new('Black')

  Wx::RED   = new('Red')
  Wx::GREEN = new('Green')
  Wx::BLUE  = new('Blue')

  Wx::YELLOW  = new('Yellow')
  Wx::CYAN    = new('Cyan')
  Wx::MAGENTA = new('Magenta')

  Wx::LIGHT_GREY = new('Light Grey')

  # Redefine the initialize method so it raises an exception if an
  # invalid colour value is given. This might be an unknown colour
  # string (eg 'dark blue') or out-of-bounds integer values (<0 or >255)
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    begin
      wx_init.bind(self).call(*args)
    # Invalid integer values raise SWIG 'no matching func'
    rescue ArgumentError 
      Kernel.raise ArgumentError, "Invalid colour values #{args.inspect}"
    end

    if not ok
      Kernel.raise ArgumentError, "Invalid colour values #{args.inspect}"
    end
  end

  # Colours are equal to one another if they have the same red, green
  # and blue intensity.
  def ==(other)
    if not other.is_a?(self.class)
      raise ArgumentError, "No comparison of #{self} to #{other}"
    end
    [ red, green, blue ] == [ other.red, other.green, other.blue ]
  end

  # More informative output for inspect etc
  def to_s
    "#<Wx::Colour: (#{red}, #{green}, #{blue})>"
  end
end
