require 'wxruby'

class MyTextCtrl < Wx::TextCtrl
  def initialize(parent)
    super(parent, -1)
    
    evt_char do | e | on_char(e) end
  end
  
  def on_char(e)
    c = e.key_code
    if((?a .. ?z).member?(c) || (?A .. ?Z).member?(c))
      # legal, so pass this event to our parent
      e.skip
      puts("skip")
    else
      # illegal, so beep and consume this event
      Wx::bell
      puts("beep")
    end
  end
end

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
    text = MyTextCtrl.new(self)
    box = Wx::BoxSizer.new(Wx::VERTICAL)
    box.add(Wx::StaticText.new(self, -1, "This box only allows alpha input:"))
    box.add(text)
    set_sizer(box)
    text.set_focus
  end
end

class NothingApp < Wx::App
  def on_init
    frame = MyFrame.new("Event Filter Sample")
	  frame.show
  end
end

a = NothingApp.new
a.main_loop()
