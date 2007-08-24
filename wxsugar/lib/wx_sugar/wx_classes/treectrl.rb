class Wx::TreeCtrl
  # Recurses over the tree item +start_item+ and its descendants,
  # yielding each item in the tree in turn into the block. If
  # +start_item+ is not specified, this method will recurse over every
  # item within the tree, starting with the root item.
  #
  # In its simplest form, the method accepts a block with one parameter,
  # which will be the TreeItemId of the item. This is an opaque integer
  # value which uniquely identifies the tree item. It can be used as an
  # argument to many other methods within TreeCtrl (for example,
  # get_item_text).
  #
  # The block passed to +traverse+ may optionally receive two additional
  # parameters, +text+ and +data+. If these are specified, they will be
  # filled with the text label for the item and any ruby item data
  # associated with the item, respectively.
  def traverse(start_item = self.get_root_item, &block)
    case block.arity
    when 1
      block.call(start_item)
    when 2
      block.call(start_item, 
                 get_item_text(start_item))
    when 3
      block.call(start_item, 
                 get_item_text(start_item), 
                 get_item_data(start_item))
    else
      raise ArgumentError, "Invalid number of block parameters"
    end

    if item_has_children(start_item)
      child, cookie = get_first_child(start_item)
      while child.nonzero?
        traverse(child, &block)
        child = get_next_sibling(child)
      end
    end
  end
end
