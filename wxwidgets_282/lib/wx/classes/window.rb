# Copyright 2004-2007 by Kevin Smith
# released under the MIT-style wxruby2 license

class Wx::Window
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

  alias :__old_evt_paint :evt_paint
  # This modified version of evt_paint sets a variable indicating that a
  # paint event is being handled just before running the event
  # handler. This ensures that any call to Window#paint within the
  # handler will supply a Wx::PaintDC (see swig/Window.i).
  def evt_paint(&block)
    wrapped_block = proc do
      instance_variable_set("@__painting__", true)
      block.call
      remove_instance_variable("@__painting__")
    end
    __old_evt_paint(&wrapped_block)
  end
end
