# Hierarchical control with items
class Wx::TreeCtrl
  # Make these ruby enumerables so find, find_all, map etc are available
  include Enumerable
  # Iterate over all items
  alias :each :traverse
end
