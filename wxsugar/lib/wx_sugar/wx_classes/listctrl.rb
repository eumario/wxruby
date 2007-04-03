require 'wx_sugar/enumerable_controls'

class Wx::ListCtrl
  include WxSugar::EnumerableControl
  collection :strings, ListItemTextCollection
  collection :data, ItemDataCollection

  alias :get_string :get_item_text
  alias :set_string :set_item_text
  alias :get_count :get_item_count

  # Appends 
  def <<(str)
    insert_item(get_item_count, str)
  end

  # Emulate the ControlWithItems find_string method. Like the cognate
  # method, it returns -1 if the string was not found.
  def find_string(str, case_sensitive = false)
    if case_sensitive
      find_string_sensitively(str)
    else
      find_item(-1, str)
    end
  end

  private
  # Implement a case-sensitive search for ListCtrl (default find_item
  # with string is always case-insensitive)
  def find_string_sensitively(str)
    start = -1
    until found = find_item(start, str) and get_item_text(found) == str
      break if found == -1 # Not found at all
      start = found + 1
    end
    return found
  end
end
