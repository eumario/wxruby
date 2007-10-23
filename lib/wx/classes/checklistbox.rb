# A ListBox, where each item has a checkbox next to it
class Wx::CheckListBox
  # wxRuby redefinitions of core methods to add item data support (not
  # available in wxWidgets). Plus convenience get_checked_items method.
  wx_init = self.instance_method(:initialize)
  define_method(:initialize) do | *args |
    @__wx_item_data = []
    wx_init.bind(self).call(*args)
  end
  
  # Call method in ControlWithItems, then sync item data
  def append(item, data = nil)
    super(item)
    @__wx_item_data << data
  end

  # Call method in ControlWithItems, then sync item data
  def clear
    super
    @__wx_item_data.clear
  end

  # delete is defined in Wx::CheckListBox, so must be called in this class
  wx_delete = self.instance_method(:delete)
  define_method(:delete) do | n |
    wx_delete.bind(self).call(n)
    @__wx_item_data.delete_at(n)
  end

  # Returns an array of indices of items that are currently checked.
  def get_checked_items
    find_all { | i | is_checked(i) }    
  end
  
  # Wholly redefined here
  def get_item_data(n)
    @__wx_item_data[n]
  end

  # Wholly redefined here
  def set_item_data(n, data)
    @__wx_item_data[n] = data
  end
end
