# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

# This wrapper serves three functions:
# 1. It loads the binary library 'wxruby2.so' or 'wxruby.dll', while
#    still allowing applications to just require 'wx'.
# 2. It sets up the version information
# 3. It loads in ruby extensions to the core Wx classes.

begin
  require 'wxruby2'
rescue LoadError => e
  warn "LoadError: unable to load wxruby2 binary. Searched:"
  warn $LOAD_PATH.inspect
  exit 1
end

Wx = Wxruby2

# Load the version information (should be bundled with all released versions)
begin
  require 'wx/version'
rescue LoadError
  Wx::WXWIDGETS_VERSION = '0.0.0'
  Wx::WXRUBY_VERSION = '0.0.0'
end

# Load in all the class extension methods written in ruby
class_files = File.join( File.dirname(__FILE__), 'wx', 'classes', '*.rb')
Dir.glob(class_files) do | class_file | 
  require 'wx/classes/' + class_file[/\w+\.rb$/]
end
