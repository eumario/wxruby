# extensions to Wx::Window
class Wx::Window
  # Returns the window's current size as a two element array
  def get_size_xy
    size = get_size
    return size.get_width, size.get_height
  end

  # Returns the window's current position as a two-element array.
  def get_position_xy
    pos = get_position
    return pos.x, pos.y
  end
end
