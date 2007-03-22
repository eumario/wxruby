class Wx::Position
  # Checks if this equal to Wx::DEFAULT_POSITION (i.e. no explicit
  # co-ordinates set)
  def default?
    x == -1 and y == -1
  end
end
