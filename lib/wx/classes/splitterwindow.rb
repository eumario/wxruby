# Class with movable sash to separate two windows
class Wx::SplitterWindow
  # These were released in wxRuby 2.0 with names slightly out of kilter
  # with the documentation. The correct ones have an underscore before
  # the digit.
  #
  # FIXME - the old names :get_window1 should be deleted in future versions.
  alias :get_window_1 :get_window1
  alias :get_window_2 :get_window2
end
