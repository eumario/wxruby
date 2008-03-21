# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

# This wrapper serves three functions:
# 1. It loads the binary library 'wxruby2.so' or 'wxruby.dll', while
#    still allowing applications to just require 'wx'.
# 2. It sets up the version information
# 3. It loads in ruby extensions to the core Wx classes.


# load the binary library
require 'wxruby2'

# alias the module
Wx = Wxruby2

# Load the version information (should be bundled with all released versions)
begin
  require 'wx/version'
rescue LoadError
  Wx::WXRUBY_VERSION = '0.0.0'
end
# Convenience string for WxWidgets version info
Wx::WXWIDGETS_VERSION = '%i.%i.%i' % [ Wx::WXWIDGETS_MAJOR_VERSION,
                                       Wx::WXWIDGETS_MINOR_VERSION,
                                       Wx::WXWIDGETS_RELEASE_NUMBER ]


# Load in all the class extension methods written in ruby
# evthandler must be required first b/c it sets up methods modified elsewhere
require 'wx/classes/evthandler.rb'
class_files = File.join( File.dirname(__FILE__), 'wx', 'classes', '*.rb')
Dir.glob(class_files) do | class_file | 
  require 'wx/classes/' + class_file[/\w+\.rb$/]
end

# Load in syntax sweetner
require 'wx/accessors'
require 'wx/keyword_ctors'
require 'wx/keyword_defs'


