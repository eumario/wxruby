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

$wildcard = "Ruby Source (*.rb)|*.rb|RubyW Source (*.rbw)|*.rbw|SPAM files (*.spam)|*.spam|Egg file (*.egg)|*.egg|All Files (*.*)|*.*"

module Demo
    def Demo.run(frame, nb, log)
        log.write_text("CWD: " + Dir.getwd())
        dlg = Wx::FileDialog.new(frame, "Save file as...", Dir.getwd(), "", $wildcard, Wx::SAVE)
        dlg.set_filter_index(2)
        if dlg.show_modal() == Wx::ID_OK
            path = dlg.get_path()
            log.write_text("You selected " + path)
        log.write_text("CWD: " + Dir.getwd())
        dlg.destroy()
        end
    end
    
    def Demo.overview
        return "Welcome to the wxRuby FileDialog_Save demo!"
    end
end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
