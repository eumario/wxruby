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

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
