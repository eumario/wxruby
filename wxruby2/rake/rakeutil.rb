# rakeutil.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

# This file is required by the main wxRuby rakefile.
# It contains stuff that I think should be included
# in the standard rake program

require "rbconfig"

$extmk = /extmk\.rb/ =~ $0
$mswin = /mswin/ =~ RUBY_PLATFORM
$bccwin = /bccwin/ =~ RUBY_PLATFORM
$mingw = /mingw/ =~ RUBY_PLATFORM
$cygwin = /cygwin/ =~ RUBY_PLATFORM
$human = /human/ =~ RUBY_PLATFORM
$netbsd = /netbsd/ =~ RUBY_PLATFORM
$os2 = /os2/ =~ RUBY_PLATFORM
$macosx = /powerpc-darwin/ =~ RUBY_PLATFORM

def force_mkdir(dir)
    if(!File.exists?(dir))
        File.mkdir(dir)
    end
end

def force_rmdir(dir)
	if(dir != '.' && dir != '..' && File.directory?(dir))
        rmdir(dir)
    end
end

def force_delete(f)
	if(f != '.' && f != '..' && File.exists?(f))
        rm(f)
    end
end

def delete_files_in(dir)
    Dir[File.join(dir, "*")].each do |f| 
	if !(f =~ /CVS/)
        	force_delete(f) 
	end
    end
end
