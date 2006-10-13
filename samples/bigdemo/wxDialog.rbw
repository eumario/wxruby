require 'wx'

class TestDialog < Wx::Dialog
    def initialize(parent, id, title)
        super(parent, id, title)
        sizer = Wx::BoxSizer.new(Wx::VERTICAL)
        
        label = Wx::StaticText.new(self, -1, "This is a wxDialog")
        #label.set_help_text("This is the help text for the label")
        sizer.add(label, 0, Wx::ALIGN_CENTER | Wx::ALL, 5)
        
        box = Wx::BoxSizer.new(Wx::HORIZONTAL)
        
        label = Wx::StaticText.new(self, -1, "Field #1")
        #label.set_help_text("This is the help text for the label")
        box.add(label, 0, Wx::ALIGN_CENTER | Wx::ALL, 5)
        
        text = Wx::TextCtrl.new(self, -1, "", 
                                Wx::DEFAULT_POSITION, Wx::Size.new(80,-1))
        #text.set_help_text("Here's some help text for field #1")
        box.add(text, 1, Wx::ALIGN_CENTER | Wx::ALL, 5)
        
        sizer.add(box, 0, Wx::GROW | Wx::ALIGN_CENTER_VERTICAL | Wx::ALL, 5)
        
        box = Wx::BoxSizer.new(Wx::HORIZONTAL)
        
        label = Wx::StaticText.new(self, -1, "Field #2")
        #label.set_help_text("This is the help text for the label")
        box.add(label, 0, Wx::ALIGN_CENTER | Wx::ALL, 5)
        
        text = Wx::TextCtrl.new(self, -1, "", Wx::DEFAULT_POSITION, Wx::Size.new(80,-1))
        #text.set_help_text("Here's some help text for field #2")
        box.add(text, 1, Wx::ALIGN_CENTER | Wx::ALL, 5)
        
        sizer.add(box, 0, Wx::GROW | Wx::ALIGN_CENTER_VERTICAL | Wx::ALL, 5)
        
        line = Wx::StaticLine.new(self, -1, Wx::DEFAULT_POSITION, 
                                  Wx::Size.new(20,-1), Wx::LI_HORIZONTAL)
        sizer.add(line, 0, Wx::ALIGN_BOTTOM | Wx::GROW , 5)
        
        # The StdDialogButtonSizer arranges the contained buttons with
        # platform-standard spacing, ordering and labelling.
        button_sizer = Wx::StdDialogButtonSizer.new()
        btn = Wx::Button.new(self, Wx::ID_OK, 'OK')
        btn.set_default()
        #btn.set_help_text("The Ok button completes the dialog")
        button_sizer.add_button(btn)
        
        btn = Wx::Button.new(self, Wx::ID_CANCEL, 'Cancel')
        #btn.set_help_text("The Cancel button cancels the dialog. (Duh!)")
        button_sizer.add_button(btn)
        button_sizer.realize
        sizer.add(button_sizer, 0, Wx::ALIGN_CENTER_VERTICAL|Wx::ALL, 5)
        
        set_sizer(sizer)
        sizer.fit(self)
    end
end

module Demo
    def Demo.run(frame, nb, log)
        win = TestDialog.new(nil, -1, "This is a wxDialog")
        win.center_on_screen(Wx::BOTH)
        val = win.show_modal()
        if val == Wx::ID_OK
            log.write_text("You pressed OK")
        else
            log.write_text("You pressed Cancel")
        end
    end
    
    def Demo.overview
        return "Welcome to the wxRuby Dialog Demo!"
    end
end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
