require 'wx'

class TestPanel < Wx::Panel
    def initialize(parent, log)
        super(parent, -1)
        @log = log
        
        sampleList = %w(one two three four five six seven eight nine ten eleven twelve thirteen fourteen)
        
        Wx::StaticText.new(self, -1, "This example uses the wxCheckListBox control.", Wx::Size.new(45,15))
        
        lb = Wx::CheckListBox.new(self, 60, Wx::Point.new(80,50), Wx::Size.new(80,120), sampleList)
        evt_listbox(60) {|event| on_evt_listbox(event)}
        evt_listbox_dclick(60) {|event| on_evt_listbox_dclick(event)}
        lb.set_selection(0)
        @lb = lb
        
        pos = lb.get_position().x + lb.get_size().get_width() + 25
        btn = Wx::Button.new(self, -1, "Test SetString", Wx::Point.new(pos,50))
        evt_button(btn.get_id()) {|event| on_test_button(event)}
        
        evt_right_up {|event| on_do_popup(event)}
    end
    
    def on_evt_listbox(event)
        @log.write_text("evt_listbox: " + event.get_string())
    end
    
    def on_evt_listbox_dclick(event)
        @log.write_text("evt_listbox_dclick:")
    end
    
    def on_test_button(event)
        @lb.set_string(4, "FUBAR")
    end
    
    def on_do_popup(event)
        menu = Wx::Menu.new()
        # Make this first item bold
        menu.append(50000, "Normal item &1")
        menu.append(50001, "Normal item &2")
        menu.append(50002, "Normal item &3")
        menu.append(50003, "Normal item &4")
        
        popup_menu(menu, event.get_position())
        menu.destroy()
        event.skip()
    end
end

module Demo
    def Demo.run(frame, nb, log)
        win = TestPanel.new(nb, log)
        return win
    end
    
    def Demo.overview
        return "A checklistbox is like a listbox, but allows items to be checked or unchecked."
    end
end
