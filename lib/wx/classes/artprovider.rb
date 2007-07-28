# Class which can supply icons and bitmaps
class Wx::ArtProvider
  # Raise a warning if a user-defined ArtProvider class does not define
  # the required create_bitmap method
  def create_bitmap(*args)
    Kernel.raise "User-defined ArtProvider #{self} must define a create_bitmap method"
  end
end
