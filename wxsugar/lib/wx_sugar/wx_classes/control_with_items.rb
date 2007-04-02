require 'wx_sugar/enumerable_controls'

# Uses WxSugar::EnumerableControl to provide methods for iterating over
# the items within the control. 
# 
# Instances of all ControlWithItems classes then have an +each+ and an
# +index+ method, plus all the methods supplied by Enumerable, such as
# +collect+, +find+ and +any?+.
#
# They also have a +strings+ method which can be used as an array-like
# accessor to the labels of the string:
# 
#  choice = Wx::Choice.new(parent, :choices => %w|foo bar|)
#  choice.strings[1] # bar
#  choice.strings[0] = 'quux' # set the first item in the control
#
# Similarly, there is a +data+ method to access the item data associated
# with the control by numeric index.
class Wx::ControlWithItems
  include WxSugar::EnumerableControl
  collection :strings, StringsCollection
  collection :data, ItemDataCollection
end
