# Add on some usefull helper methods to String
class String
  ACRONYMS = /([A-Z0-9_]{2,})(?=[A-Z][a-z])/
  CAPITALS = /([a-z])(?=[A-Z0-9_])/
  NUMBERS  = /(\d+)(?=[A-Za-z_])/

  def un_camelcase(word_sep = '_')
    dup.un_camelcase!(word_sep)
  end

  def un_camelcase!(word_sep = '_')
    gsub!(ACRONYMS) { $1 + word_sep }
    gsub!(CAPITALS) { $1 + word_sep }
    gsub!(NUMBERS)  { $1 + word_sep }
    downcase!
    self
  end

  def camelcase(word_sep = '_')
    dup.camelcase!(word_sep)
  end

  def camelcase!(word_sep = '_')
    gsub!(/(?:\A|#{word_sep})([a-z])/) { $1.upcase }
  end

  # True if +self+ appears to be a camelcased word
  def camelcase?()
    self =~ /^(?:[A-Z][a-z]+){2,}/
  end
end
