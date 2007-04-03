# This module enhances the family of GUI controls which display a list
# of labelled items and allow the user to select one or more
# items. Classes of this type include Wx::Choice, Wx::ComboBox and
# Wx::ListBox. This module allows easy iteration over the contents of
# these object using Ruby's +each+ and Enumerable methods.
#
# Note that including this file on its own won't enable this behaviour
# for any classes; you should load it via the class extensions for
# +control_with_items.rb+ and +listctrl.rb+.
module WxSugar::EnumerableControl
  include Enumerable
  module ClassMethods
    # Used internally to define a proxy object for items.
    def collection(name, coll_class)
      define_method(name) { coll_class.new(self) }
    end
  end

  def self.included(klass)
    klass.extend ClassMethods
  end

  # Iterates over the items in the control. In its simplest form, it
  # passes the index of each item into the passed block:
  # 
  #  control.each | i | 
  #    puts "String at #{i} is '#{control.string(i)}'"
  #  end
  #
  # The passed block may have up to three block parameters, +i+,
  # +string+, and +data+. The second parameter, if requested, is filled
  # with the string label of the item within the control. The third
  # parameter is filled with the client data associated with the
  # item. Note that if you don't need the string or client data, it is
  # more efficient to iterate over the indexes only.
  def each(&block)
    last = get_count - 1
    case block.arity
    when 1
      0.upto(last) { | i | yield i }
    when 2
      0.upto(last) { | i | yield i, get_string(i) }
    when 3
      0.upto(last) { | i | yield i, get_string(i), get_item_data(i) }
    else
      raise ArgumentError, "Invalid number of block parameters"
    end
  end

  # Returns the index of the item in the control corresponding to
  # +value+. +value+ may be a string label, or it may be any ruby object
  # set as client data to a list item. Returns +nil+ if nothing matches.
  def index(value)
    # -1 means 'not found' in WxWidgets
    if value.kind_of?(String) && ( i = find_string(value, true) ) && i > -1
      return i
    end
    indices = (0 ... get_count).to_a
    return indices.find { | i | get_item_data(i) == value } 
  end

  # Appends this string to the control
  def <<(str)
    append(str)
  end

  # Deletes any items in the control for which the passed block
  # evaluates to +true+.
  def delete_if
    deletions = []
    each { | i | deletions << i if yield i }
    deletions.reverse.each { | i | delete(i) }
  end

  # These classes provide proxy accessors for items within the control.
  # ItemCollection is an abstract base class.
  class ItemCollection 
    attr_reader :cwi
    def initialize(cwi)
      @cwi = cwi
    end

    # Do a bounds-checked call of some value-fetching method +methdo+
    # for the item +i+
    def [](method, i)
      unless index?(i)
        raise IndexError, "No such item #{i} in #{self.cwi}"
      end
      cwi.send( method, i )
    end

    # Do a bounds-checked call of some value-setting method +methdo+
    # for the item +i+ to value +val+
    def []=(method, i, val)
      unless index?(i)
        raise IndexError, "No such item #{i} in #{self.cwi}"
      end
      cwi.send( method, i, val )
    end

    # over-ridden by some subclasses
    def index?(i)
      i >= 0 and i < cwi.get_count
    end
  end

  # A proxy class for the item_data functions.
  class ItemDataCollection < ItemCollection
    def each 
      cwi.each { | i | yield cwi.get_item_data(i) }
    end

    # Retrieves the item data for item +i+
    def [](i)
      super :get_item_data, i
    end

    # Sets the item data for +i+ to be +obj+
    def []=(i, obj)
      super :set_item_data, i, obj
    end
  end

  # A proxy class for classes that use get/set_string to set labels,
  # inheriting from ControlWithItems.
  class StringsCollection < ItemCollection
    def each 
      cwi.each { | i | yield cwi.get_string(i) }
    end

    # Retrieves the string for item +i+
    def [](i)
      super :get_string, i
    end

    # Sets a string within the control
    def []=(i, str)
      super :set_string, i, str
    end
  end

  # Fetching strings from a ListCtrl
  class ListItemTextCollection < ItemCollection
    def each 
      cwi.each { | i | yield cwi.get_item_text(i) }
    end

    # Retrieves the string for item +i+
    def [](i)
      super :get_item_text, i
    end

    # Sets a string within the control
    def []=(i, str)
      super :set_item_text, i, str
    end

    def index?(i)
      i >= 0 and i < cwi.get_item_count
    end
  end
end
