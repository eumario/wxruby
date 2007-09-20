# Multi-item control with numerous possible view styles
class Wx::ListCtrl
  # Make these ruby enumerables so find, find_all, map are available 
  include Enumerable
  # Passes each valid item index into the passed block
  def each
    0.upto(item_count - 1) { | i | yield i }
  end
end
