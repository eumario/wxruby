# extensions to Wx::Window
class Wx::Window
  # Returns an array containing this window and all windows descended
  # from it.
  def get_descendants
    get_children.inject([ self ]) do | desc, child |
      desc + child.get_descendants
    end
  end

  # Passed a block, returns the first window within self's window
  # hierarchy for which the block evaluates to true. A class name may
  # optionally be passed to restrict the search to windows of that class
  # (or its subclasses) only - this can be useful if the search
  # specification calls methods that are only defined for certain
  # classes.
  #
  #  # Example - find a StaticText with a label matching /foo/
  #  a_frame.find_window(Wx::StaticText) { | tx | tx.label =~ /foo/ }
  def find_window(a_class = Wx::Window, &block)
    get_descendants.grep(a_class).detect(&block)
  end

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

  # Tests if the GUI object has the given window style +style+. Returns
  # +style+ if it has been applied, or +nil+ if the window does not have
  # that style.
  # 
  #  combobox.has_style?(Wx::CB_READONLY)
  #  textctrl.has_style?(Wx::TE_MULTILINE)
  # 
  # Note that you should at least know that the constant +style+ is
  # applicable to self. You may get false positives if testing a widget
  # for a style belonging to an irrelevant class, e.g. testing a
  # Wx::TextCtrl for the WX::CB_READONLY style.
  def has_style?(style)
    ( get_window_style & style ).nonzero?
  end
end
