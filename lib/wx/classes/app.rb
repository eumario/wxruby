# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

class Wx::App
  def on_assert(file, line, condition, message)
    warn "ASSERT: #{file} #{line}"
    warn condition
    raise message
  end
end
