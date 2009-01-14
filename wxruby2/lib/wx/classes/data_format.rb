# Make this easier to use for multi-typed data objects
class Wx::DataFormat
  def ==(other)
    if self.type > Wx::DF_INVALID
      self.type == other.type
    else
      self.id == other.id
    end
  end
end
