require 'wx'

module Demo
    def Demo.run(frame, nb, log)
        dlg = Wx::TextEntryDialog.new(frame, "What is your favorite programming language?", "Duh??", "Ruby")
        dlg.set_value("Ruby is the best!")
        if dlg.show_modal() == Wx::ID_OK
            log.write_text("You entered: " + dlg.get_value().to_s + "\n")
        end     
        dlg.destroy()
        return nil
    end
    
    def Demo.overview
        return "This dialog allows the user to input text"
    end
end
