# Example by Gergely Kontra
# minor modifications by Kevin Smith
require 'wxruby'

class MyTextDropTarget < Wx::TextDropTarget
  def on_drop_text(x,y,text)
    puts "Accepting drop of text: #{text.inspect} at position (#{x},#{y})"
    return true
  end
end

class MyFrame < Wx::Frame
  def initialize(title)
    super(nil, -1, title)
    set_drop_target(MyTextDropTarget.new())
  end
end

class NothingApp < Wx::App
  def on_init
    frame = MyFrame.new("I accept text")
	frame.show
  end
end

a = NothingApp.new
a.main_loop()
