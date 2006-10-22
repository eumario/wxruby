# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

class Wx::Window
  # create a DC for drawing on the window, run the block passing in the DC
  def paint
    yield Wx::PaintDC.new(self)
  end
end
