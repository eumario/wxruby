require 'ftools'
require 'rbconfig'
include Config

if /powerpc-darwin/ =~ RUBY_PLATFORM
	File::install('wxruby.bundle', CONFIG['archdir'], 0755, true)
else
	File::install('wxmsw240.dll', CONFIG['bindir'], 0755, true)
	File::install('wxruby.so', CONFIG['archdir'], 0755, true)
end
