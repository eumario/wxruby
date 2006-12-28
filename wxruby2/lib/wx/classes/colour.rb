class Wx::Colour

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

  # More informative output for inspect etc
  def to_s
    "#<Wx::Colour: (#{red}, #{green}, #{blue})>"
  end
end
