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

if(!Wx.constants.index("Notebook"))
	module Wx
		class ToggleButton < Panel
			def initialize(parent, id, label, position)
				super(parent, id)
				puts("ToggleButton class missing, so faking it")
			end
		end
	end
end
