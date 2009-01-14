# Make this easier to use for multi-typed data objects. Comparison
# doesn't work correctly in the SWIG binding
class Wx::DataFormat
  def ==(other)
    if self.get_type > Wx::DF_INVALID
      self.get_type == other.get_type
    else
      self.id == other.id
    end
  end
end
