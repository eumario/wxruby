# Display a listbox with a checkbox for each item
class Wx::CheckListBox < Wx::ListBox

  # According to the wxWidgets documentation: "wxCheckListBox uses
  # client data in its implementation, and therefore this is not
  # available to the application."   
  #
  # So, rather than crashing, raise an Exception if this is attempted
  def append(*args)
    if args.length == 2 
      Kernel.raise "Cannot use item data with Wx::CheckListBox"
    else 
      super
    end
  end

  # As above
  def insert(*args)
    if args.length == 3
      Kernel.raise "Cannot use item data with Wx::CheckListBox"
    else 
      super
    end
  end

  # As above
  def set_item_data(index, data)
    Kernel.raise "Cannot use item data with Wx::CheckListBox"
  end
end
