require 'wx'

module Demo
    def Demo.run(frame, nb, log)
        dlg = Wx::DirDialog.new(frame, "Choose a directory:")
        if dlg.show_modal() == Wx::ID_OK
            log.write_text("You selected: " + dlg.get_path())
        end
        dlg.destroy()
    end
    
    def Demo.overview
        return "Welcome to the wxRuby DirDialog demo!"
    end
end
