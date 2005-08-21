require 'wx'

$wildcard = "Ruby Source (*.rb)|*.rb|RubyW Source (*.rbw)|*.rbw|All files (*.*)|*.*"

module Demo
    def Demo.run(frame, nb, log)
        log.write_text("CWD: " + Dir.getwd() + "\n")
        dlg = Wx::FileDialog.new(frame, "Choose a file", Dir.getwd(), "", $wildcard, Wx::OPEN | Wx::MULTIPLE)
        if dlg.show_modal() == Wx::ID_OK
            paths = dlg.get_paths()
            log.write_text("You selected %d files" % + paths.length)
            paths.each {|path| log.write_text("CWD: " +  path)}
        log.write_text("CWD: " + Dir.getwd())
        end
    end
    
    def Demo.overview
        return "Welcome to the wxFileDialog Demo!"
    end


end
