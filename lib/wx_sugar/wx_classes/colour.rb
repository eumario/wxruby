# extensions to Wx::Colour
class Wx::Colour

  # Create a new Colour from the hex-string +hex_str+, which should be a six-
  # character colour RGB specification. The hash character '#' may optionally
  # be prepended to the string, and will be ignored.
  def self.from_hex(hex_str)
    unless hex_str =~ /\A#?[0-9A-F]{6}\z/i
      raise ArgumentError,
            "Invalid colour string #{hex_str} received, " +
            "should be six-char hexadecimal RGB"
    end
    components = hex_str.scan(/[0-9A-F]{2}/i).map { | x | Integer("0x#{x}") }
    new(*components)
  end

  # Returns the colour as a six character hexadecimal string (as used in 
  # HTML/CSS for example).  
  def to_hex
    [ :red, :green, :blue ].inject('') do | hex_str, component |
      hex_str << sprintf('%02X', send(component) )
    end
  end

  # Create a new colour by mixing +self_parts+ of +self+ with
  # +other_parts+ of other. The new colour is produced by applying the
  # following averaging formula to the red, green and blue components
  # of each colour
  # 
  #   ( colour_1 * conc_1 ) + ( colour_2 * conc_2 )
  #         --------------------------
  #              conc_1 + conc_2
  #
  def mix(other, self_parts = 1, other_parts = 1)
    return self if self_parts.zero? && other_parts.zero?
    rgb = [ :red, :green, :blue ].map do | component |
      mix = self.send(component) * self_parts
      mix += other.send(component) * other_parts 
      mix = mix.to_f
      mix /= self_parts + other_parts
      mix.to_i
    end
    Wx::Colour.new(*rgb)
  end
end
