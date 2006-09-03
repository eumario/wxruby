# rakewx.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

begin
	require 'wxruby2'
rescue LoadError => e
	puts("Unable to load wxruby. Searched:")
	puts($LOAD_PATH)
	exit(1)
end

# This wrapper serves two functions:
# 1. It allows apps to require 'wx' but still have the binary 
#    library properly named wxruby2.so or wxruby2.dll
# 2. Later, we can add wrapper classes and methods here that can 
#    expose a friendlier API than the C++ code provides

Wx = Wxruby2

Wx::WXRUBY_VERSION    = '0.0.35'
Wx::WXWIDGETS_VERSION = '2.6.3'

class Wx::App
	def on_assert(file, line, condition, message)
		puts("ASSERT: #{file} #{line}")
		puts(condition)
		puts(message)
		raise
	end
end
