# fixmainmodule.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

#   This script post-processes the SWIG output
#   to allow a single Ruby module to be defined 
#   across multiple SWIG modules
#   I know it's ugly :-(

$main_module = 'mWxruby2'

def fix(file)
	broken = file +".old"
	File.rename(file, broken)

	File.open(ARGV[0], "w") do | out |
    	File.foreach(broken) do | line |
    end

end

File.delete(broken)
end

broken = ARGV[0]+".old"
File.rename(ARGV[0], broken)

this_module = 'unknown'
File.open(ARGV[0], "w") do | out |
    File.foreach(broken) do | line |
        if(line.index("static VALUE #{$main_module};"))
            line = "VALUE #{$main_module};"
        end
        out.puts(line)
    end

end

File.delete(broken)
