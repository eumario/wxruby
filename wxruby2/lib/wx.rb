# rakewx.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

require 'wxruby2'

# This wrapper serves two functions:
# 1. It allows apps to require 'wx' but still have the binary 
#    library properly named wxruby2.so or wxruby2.dll
# 2. Later, we can add wrapper classes and methods here that can 
#    expose a friendlier API than the C++ code provides

Wx = Wxruby2
