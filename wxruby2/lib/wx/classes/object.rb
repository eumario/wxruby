# The root class for most (not all) WxRuby classes
class Wx::Object
  # massage the output of inspect to show the public module name (Wx)
  def to_s
    super.sub('ruby2', '')
  end
end
