# Text editor supporting various formatting, intended for editing
# natural language texts
class Wx::RichTextCtrl
  # These three methods return the styles applicable at certain points
  # in the document. However, the standard wx signature is to accept the
  # value of some kind of TextAttr class that will hold the return as an
  # argument. The return value is a boolean for success/failure. In
  # Ruby, we only support returning the value as a RichTextAttr, and do
  # so as a proper return value, having accepted a single argument
  # specifying where to get the style from. If retrieval is not
  # successful, raise an exception.
  wx_get_style = self.instance_method(:get_style)
  define_method(:get_style) do | pos |
    style = Wx::RichTextAttr.new
    if wx_get_style.bind(self).call(pos, style)
      return style
    else
      Kernel.raise RuntimeError, "Could not retrieve style at position #{pos}"
    end
  end

  wx_get_style_for_range = self.instance_method(:get_style_for_range)
  define_method(:get_style_for_range) do | rng |
    style = Wx::RichTextAttr.new
    if wx_get_style_for_range.bind(self).call(rng, style)
      return style
    else
      Kernel.raise RuntimeError, "Could not retrieve style for range #{rng}"
    end
  end

  wx_get_uncombined_style = self.instance_method(:get_uncombined_style)
  define_method(:get_uncombined_style) do | pos |
    style = Wx::RichTextAttr.new
    if wx_get_uncombined_style.bind(self).call(pos, style)
      return style
    else
      Kernel.raise RuntimeError, "Could not retrieve style at position #{pos}"
    end
  end

  # Fix to accept a single +pos+ argument and return a Wx::Rect
  wx_car_pos_for_index = self.instance_method(:get_caret_position_for_index)
  define_method(:get_caret_position_for_index) do | pos |
    rect = Wx::Rect.new
    if wx_car_pos_for_index.bind(self).call(pos, rect)
      return rect
    else
      Kernel.raise RuntimeError, "Could not rect for position #{pos}"
    end
  end

  # Fix to return a pair of col, row values
  wx_pos_to_xy = self.instance_method(:position_to_xy)
  define_method(:position_to_xy) do | pos |
    success, x, y = wx_pos_to_xy.bind(self).call(pos)
    if success
      return x, y
    else
      Kernel.raise RuntimeError, "Could not convert position #{pos} to x, y"
    end
  end
end
