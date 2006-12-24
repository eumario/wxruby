class Wx::TreeItemId
  # Fix equality here because TreeCtrl methods don't return identical
  # TreeItemIds for repeated calls referring to the same item.
  def ==(other)
    return false unless other.is_a?(self.class)
    return self.to_i == other.to_i
  end
end
