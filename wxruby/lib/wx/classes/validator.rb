class Wx::Validator
  # Default implementation of clone, may need to be over-ridden in
  # custom subclasses should state variables need to be copied
  def clone
    self.class.new
  end
end
