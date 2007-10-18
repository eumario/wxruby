# Hierarchical control with items
class Wx::TreeCtrl
  # Make these ruby enumerables so find, find_all, map etc are available
  include Enumerable
  # Iterate over all items
  alias :each :traverse

  # Return the children of +parent+ as an array of TreeItemIDs.
  def get_children(parent)
    kids = [ get_first_child(parent) ]
    return [] if kids[0].zero?

    while kid = get_next_sibling(kids.last) and not kid.zero?
      kids << kid
    end
    kids
  end
end
