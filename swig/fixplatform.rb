# fixmodule.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This script post-processes the SWIG output
#   to allow a class to not be defined on certain 
#   platforms.
#   I know it's ugly :-(

require 'swig/classes/include/parents'

broken = ARGV[0]+".old"
File.rename(ARGV[0], broken)

this_module = File.basename(ARGV[0],".cpp")

File.open(ARGV[0], "w") do | out |
    add_footer = false
    File.foreach(broken) do | line |
        if (line.index("//@@"))
            line.gsub!(/\/\/@@/,"#")    
            add_footer = true
        end       
        out.puts(line)
    end

    if (add_footer)
        out.puts <<-FOOTER
            #else
            #ifdef __cplusplus
            extern "C"
            #endif
            SWIGEXPORT(void) Init_wx#{this_module}(void) {
            }
            #endif    
        FOOTER
    end
end

File.delete(broken)
