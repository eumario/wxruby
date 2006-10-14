#!/usr/bin/env ruby

begin
  require 'wx'
rescue LoadError => no_wx_err
  begin
    require 'rubygems'
    require 'wx'
  rescue LoadError
    raise no_wx_err
  end
end

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

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
