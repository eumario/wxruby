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
        lst = %w(apple pear banana coconut orange etc etc.. etc...)
        choices = Wx::get_multiple_choices("Pick some from\n this list\nblah blah...", "m.s.d.", lst)
        if choices
            log.write_text("You selected " + choices.length().to_s() + " items:")
            choices.each_index {|i| log.write_text("\t" + choices[i].to_s() + " => " + lst[choices[i]])}
        end
    end

    def Demo.overview
        return ""
    end
end
    

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
