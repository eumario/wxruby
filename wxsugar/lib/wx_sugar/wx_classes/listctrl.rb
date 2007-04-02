require 'wx_sugar/enumerable_controls'

class Wx::ListCtrl
  include WxSugar::EnumerableControl
  collection :strings, StringsCollection
  collection :data, ItemDataCollection

  alias :get_string :get_item_text
  alias :set_string :set_item_text

  def <<(str)
    insert_item(get_item_count, str)
  end
end
