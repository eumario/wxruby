# dragdrop.rb sample by Kevin Smith

require 'wxruby'

class DragListBox < Wx::ListCtrl
    def initialize(parent)
        super(parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, 
                Wx::LC_REPORT | Wx::LC_SINGLE_SEL)
                
        insert_column(0, 'Fruits')
        
        evt_list_begin_drag(get_id) do | e | on_drag(e) end
    end
    
    def append(text)
        row = get_item_count
        insert_item(row, text)
        set_item_text(row, text)
    end
    
	def get_selected_row
		return get_next_item(-1, Wx::LIST_NEXT_ALL, Wx::LIST_STATE_SELECTED)
	end
	
    def on_drag(event)
        selected_row = get_selected_row
        if(selected_row < 0)
            puts("nothing to drag")
            return
        end
        data = Wx::TextDataObject.new(get_item_text(selected_row))
        dragSource = Wx::DropSource.new(self);
        dragSource.set_data(data);
        result = dragSource.do_drag_drop(Wx::DRAG_ALLOW_MOVE)
        case result
            when Wx::DRAG_NONE:
                puts("Drop was rejected")
            when Wx::DRAG_CANCEL:
                puts("Drag canceled by user")
            when Wx::DRAG_COPY:
                puts("Copied")
            when Wx::DRAG_MOVE:
                puts("Moved")
                delete_item(selected_row)
            else
                puts("ERROR or Unknown result!")
        end
    end
end

class MyDropTarget < Wx::TextDropTarget
    def initialize(owner)
        super()
        @owner = owner
        @owner.set_drop_target(self)
    end
    
    def on_drop_text(x, y, text)
        puts("Accepting drop of #{text} at #{x}, #{y}")
        @owner.handle_drop(text)
        return true
    end
end

class DropListBox < Wx::ListBox
    def initialize(parent)
        super(parent, -1)
        
        target = MyDropTarget.new(self)
    end
    
    def handle_drop(text)
        append(text)
    end
end

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
    list1 = DragListBox.new(self)
    list1.append('Apple')
    list1.append('Banana')
    list1.append('Cranberry')
    list2 = DropListBox.new(self)
    
    lists = Wx::BoxSizer.new(Wx::HORIZONTAL)
    lists.add(list1, 1, Wx::EXPAND)
    lists.add(list2, 1, Wx::EXPAND)
    
    instructions = Wx::StaticText.new(self, -1, 
        "You can drag items from the left list to the right\n" +
        "(or to any window in your system that accepts text drops.\n" +
        "If you hold down shift while releasing, the item \n" + 
        "will be MOVED instead of COPIED\n")

    main_sizer = Wx::BoxSizer.new(Wx::VERTICAL)
    main_sizer.add(instructions, 0, Wx::EXPAND)
    main_sizer.add(lists, 1, Wx::EXPAND)
    set_sizer(main_sizer)
    
  end
end

class DragDropApp < Wx::App
  def on_init
    frame = MyFrame.new("wxRuby Drag and Drop App")
	frame.show
  end
end

a = DragDropApp.new
a.main_loop()
