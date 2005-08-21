require 'wx'

module Demo
    def Demo.run(frame, nb, log)
        dlg = Wx::ColourDialog.new(frame)
        dlg.get_colour_data().set_choose_full(true)
        if dlg.show_modal() == Wx::ID_OK
            data = dlg.get_colour_data().get_colour()
            log.write_text("You selected: (%d, %d, %d)" % [data.red, data.green, data.blue])
        end
        dlg.destroy()
    end
    
    def Demo.overview
        return "Welcome to the wxRuby ColourDialog demo"
    end
end
