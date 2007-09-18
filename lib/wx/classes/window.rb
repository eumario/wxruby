# Copyright 2004-2007 by Kevin Smith
# released under the MIT-style wxruby2 license

# The base class for all things displayed on screen
class Wx::Window

  # Ruby's Object#id is deprecated and will be removed in 1.9; therefore
  # for classes inheriting from Wx::Window, the id method returns the
  # wxRuby Window id
  alias :id :get_id
  # In case a more explicit option is preferred.
  alias :wx_id :get_id


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
  def evt_paint(meth = nil, &block)
    paint_proc = acquire_handler(meth, block)
    wrapped_block = proc do | event |
      instance_variable_set("@__painting__", true)
      paint_proc.call(event)
      remove_instance_variable("@__painting__")
    end
    __old_evt_paint(&wrapped_block)
  end
end
