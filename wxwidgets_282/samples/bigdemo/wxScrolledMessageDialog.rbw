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

class ScrolledMessageDialog < Wx::Dialog
    def initialize(parent, msg, caption, 
                   pos = Wx::DEFAULT_POSITION, 
                   size = Wx::Size.new(500,300) )
        super(parent, -1, caption, pos, size)
        x,y = pos.x, pos.y
        if x == -1 and y == -1
            center_on_screen(Wx::BOTH)
        end
        sizer = Wx::BoxSizer.new(Wx::VERTICAL)
        text = Wx::TextCtrl.new(self, -1, msg, 
                                 Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, 
                                 Wx::TE_MULTILINE|Wx::TE_READONLY)

        sizer.add(text, 1, Wx::EXPAND|Wx::ALL, 5)

        button_sizer = Wx::StdDialogButtonSizer.new
        button_sizer.add_button( Wx::Button.new(self, Wx::ID_OK, "OK") )
        button_sizer.realize

        sizer.add(button_sizer, 0, Wx::EXPAND|Wx::ALL, 5)

        set_sizer(sizer)
        layout
    end
end

module Demo
    def Demo.run(frame, nb, log)
        f = open(__FILE__, "r")
        msg = f.read()
        dlg = ScrolledMessageDialog.new(frame, msg, "message test")
        dlg.show_modal()
    end

    def Demo.overview
        return "A simple ruby example of a custom dialog displaying a " +
               "long message in a scrolled TextCtrl"
    end
end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
