require 'wxruby'

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
  end
end

class NothingApp < Wx::App
  def OnInit
    frame = MyFrame.new("Minimal wxRuby App")
	frame.show
  end
end

a = NothingApp.new
a.main_loop()
