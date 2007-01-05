class Wx::Icon
  # Redefine the initialize method so it raises an exception if a
  # bad argument - in particular, a non-existent file - is given to the
  # constructor. It raisees an error if no data has been set to the icon.
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    wx_init.bind(self).call(*args)

    # Zero-argument form allowed, for use with later copy_from_bitmap
    if args.length.nonzero? and not ok
      Kernel.raise ArgumentError, "Invalid icon specified: #{args.inspect}"
    end
  end

end
