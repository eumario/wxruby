class Wx::Bitmap
  # Accepts a block, which will be passed a device context which can be
  # used to draw upon the Bitmap
  def draw
    dc = MemoryDC.new
    dc.select_object(self)
    yield dc
    dc.select_object( NULL_BITMAP )
  end
end
