class Wx::TreeCtrl
  # Recurses over the tree item +start_item+ and its descendants,
  # yielding each Wx::TreeItemId in turn into the passed block. This
  # TreeItemId can be used as an argument to many other methods within
  # TreeCtrl (for example, get_item_text).
  #
  # If +start_item+ is not specified, this method will recurse over
  # every item within the tree, starting with the root item.
  def traverse(start_item = self.get_root_item, &block)
    block.call(start_item)
    if has_children(start_item)
      child, cookie = get_first_child(start_item)
      while child.is_ok
        traverse(child, &block)
        child = get_next_sibling(child)
      end
    end
  end
end
