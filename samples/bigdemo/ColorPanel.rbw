require 'wx'

class ColoredPanel < Wx::Window
    def initialize(parent, color)
        super(parent, -1, Wx::DEFAULT_POSITION, Wx::DEFAULT_SIZE, Wx::SIMPLE_BORDER)
        set_background_colour(color)
    end
end
