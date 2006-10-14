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

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
