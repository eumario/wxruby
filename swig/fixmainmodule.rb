# fixmainmodule.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This script post-processes the SWIG output
#   to allow a single Ruby module to be defined 
#   across multiple SWIG modules
#   I know it's ugly :-(

broken = ARGV[0]+".old"
File.rename(ARGV[0], broken)

this_module = 'unknown'
File.open(ARGV[0], "w") do | out |
    File.foreach(broken) do | line |
        if(line.index("static VALUE mWx;"))
            line = "VALUE mWx;"
        end
        out.puts(line)
    end

end

File.delete(broken)
