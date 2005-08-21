require 'wx'

module Demo
    def Demo.run(frame, nb, log)
        dlg = Wx::SingleChoiceDialog.new(frame, "Test Single Choice", "The Caption", 
                                            %w(zero one two three four five six seven eight))
                                            #Wx::CHOICEDLG_STYLE)
        if dlg.show_modal() == Wx::ID_OK
            log.write_text("You selected: " + dlg.get_string_selection() + "\n")
        end
        dlg.destroy()
        return nil
    end
    
    def Demo.overview
        return "This class represents a dialog that shows a list of strings, and allows the user to select one. Double-clicking on a list item is equivalent to single-clicking and then pressing OK."
    end
end
