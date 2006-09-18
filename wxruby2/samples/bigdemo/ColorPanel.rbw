require 'wx'

class ColoredPanel < Wx::Window
    def initialize(parent, color)
        super(parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SIMPLE_BORDER)
        set_background_colour(color)
    end
end

if __FILE__ == $0
  run_solo_lib = File.join( File.dirname(__FILE__), 'run.rb')
  load run_solo_lib
  run File.basename($0)
end
