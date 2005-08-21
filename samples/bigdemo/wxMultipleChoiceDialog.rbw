require 'wx'

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
    
