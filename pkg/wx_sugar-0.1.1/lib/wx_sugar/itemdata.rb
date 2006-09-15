module WxSugar
module ItemData
    # for faked-up item data
    def get_item_data(id)
      data[id]
    end
    alias :get_client_data :get_item_data

    # for faked-up item data
    def set_item_data(id, data_obj)
      data[id] = data_obj
    end
    alias :set_client_data :set_item_data
    
    # returns the key associated with the value +value+
    def value_to_ident(value)
      return nil if value.nil?
      if value.nil?
        return nil
      elsif value.kind_of?(Fixnum)
        the_id = value
      elsif value.respond_to?(:id)
        the_id = value.id
      else
        Kernel.raise "Cannot search for invalid value #{value.inspect}"
      end
      return index(the_id)
    end
    alias :object_to_item :value_to_ident
  end
  
  module ListLikeItemData
    include ItemData
    def data()
      @data_table ||= Array.new()
    end
    
    def delete_item_data(the_data)
      if i = value_to_ident(the_data)
        data.delete_at(i)
      end
    end
    
    def unshift_item_data(the_data)
      delete_item_data(the_data)
      data.unshift(the_data)
    end

    def push_item_data(the_data)
      delete_item_data(the_data)
      data.push(the_data)
    end
    
    def index(the_id)
      data.each_with_index do | val, i |
        return i if val.id == the_id
      end
      return nil
    end
  end

  module HashLikeItemData
    include ItemData
    def data()
      @data_table ||= Hash.new()    
    end

    def delete(the_id)
      data.delete(the_id)
      super(the_id)
    end
    
    def index(the_id)
      data.each do | k, val |
        return k if val.id == the_id
      end
      return nil
    end
  end
end
