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
	found_main_module = false
    File.foreach(broken) do | line |
        if(line.index("static VALUE #{$main_module};"))
            line = "VALUE #{$main_module};"
			found_main_module = true
        end

        # Fix 1.3.29's ruby tracking
        # TODO: Should be fixed in (or different with) 1.3.30 but isn't yet
#        if(ENV['SWIGVER'] == 'SWIG Version 1.3.29')
          if(line.index("static VALUE swig_ruby_trackings"))
            line = "VALUE swig_ruby_trackings = 0;"
          end

          if(line.index("static ID swig_ruby_hash_delete"))
            line = "ID swig_ruby_hash_delete = 0;"
          end

          if(line.index("swig_ruby_trackings = rb_hash_new();"))
            line = "  if(swig_ruby_trackings == 0) {\n" +
                   line;
          end
			
          if(line.index("swig_ruby_hash_delete = rb_intern(\"delete\");"))
            line = line + "\n" +
                   "rb_global_variable(&swig_ruby_trackings);\n" +
                   "  }";
          end

          if(line.index("char* type_name = RSTRING(value)->ptr;"))
            line = "        const char* type_name = (value == Qnil) ? \"\" : RSTRING(value)->ptr;\n";
          end
# TODO 1.3.30
#      end

        out.puts(line)
    end
	if(!found_main_module)
		puts("didn't find main module")
		exit(1)
	end
end

File.delete(broken)
