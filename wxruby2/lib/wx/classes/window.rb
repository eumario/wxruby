# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

class Wx::Window
  # Creates a device context which can be used for drawing on the
  # window, and passes it into a block. Note that this method should
  # only be used within an on_paint handler.
  def paint
    yield Wx::PaintDC.new(self)
  end

  # Recursively searches all windows below +self+ and returns the first
  # window which has the id +an_id+. This corresponds to the find_window
  # method method in WxWidgets when called with an integer.
  def find_window_by_id(an_id)
    Wx::Window.find_window_by_id(an_id, self)
  end

  # Searches all windows below +self+ and returns the first window which
  # has the name +a_name+ This corresponds to the find_window method method
  # in WxWidgets when called with an string.
  def find_window_by_name(a_name)
    Wx::Window.find_window_by_name(a_name, self)
  end

  # Searches all windows below +self+ and returns the first window which
  # has the label +a_label+.
  def find_window_by_label(a_label)
    Wx:Window.find_window_by_label(a_label, self)
  end
end
