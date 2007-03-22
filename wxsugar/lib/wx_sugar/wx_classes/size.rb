class Wx::Size
  # Checks if this equal to Wx::DEFAULT_SIZE (i.e. no explicit
  # dimensions set)
  def default?
    get_width == -1 and get_height == -1
  end
end
