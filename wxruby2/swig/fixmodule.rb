# fixmodule.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

#   This script post-processes the SWIG output
#   to allow a single Ruby module to be defined 
#   across multiple SWIG modules
#   I know it's ugly :-(

require 'swig/classes/include/parents'

def fixmodule(filename)
	broken = filename+".old"
	File.rename(filename, broken)
	
	found_swig_class = false
	found_define_module = false
	found_init = false
	found_define_class = false
	
	core_name = File.basename(filename, ".cpp")
puts("core_name: #{core_name}")
	wx_name = "wx"+core_name
	this_module = 'mWx' + core_name
	parent_wxklass = $parents[wx_name]
	if (parent_wxklass)
		parent_name = parent_wxklass[2..-1]
puts("      : #{parent_name}")
	end
	
	skip_until_close_brace = false
	
	File.open(filename, "w") do | out |
	
		File.foreach(broken) do | line |
		
			# if we find the definition of our class variable,
			if (line.index('swig_class c') and not line.index("extern"))
puts("class #{wx_name}")
				# declare our (primary) base class so we can use it as our parent
				result = []
				if (parent_wxklass)
					result << "extern swig_class cWx#{parent_name};"
				end
				result << line
				line = result.join("\n")
				found_swig_class = true
			end
			
			# comment out swig_up because it is defined global in every module
			if(line.index("bool Swig::Director::swig_up"))
				line = "//" + line
			end
			
			# instead of defining a new module,
			if(line.index("rb_define_module(\"Wx"))
				# set this module equal to the real main module
				line = "#{this_module} = #{$main_module};"
				found_define_module = true
			end
			
			# at the top of our Init_ function,
			if(line.index("SWIGEXPORT void Init_"))
				# make sure we only initialize ourselves once
				line += "static bool initialized;\n"
				line += "if(initialized) return;\n"
				line += "initialized = true;\n"
				found_init = true
			end
	 
	 		# if we are defining ourselves as a subclass,
			if(line.index("rb_define_class_under(mWx#{core_name}"))
				  result = []
				  if(parent_wxklass)
				  	  #initialize our primary parent
					  result << "    extern void Init_wx#{parent_name}();"
					  result << "    Init_wx#{parent_name}();"
					  result << "    //extern swig_class cWx#{parent_name};"
					  parent_klass = "cWx#{parent_name}.klass"
					  # define us under our parent instead of under ruby's Object
					  line = line.gsub(/rb_cObject/, parent_klass)
				  end
				result << line
				line = result.join("\n")
puts(line)
				found_define_class = true
			end
			
			# if this module doesn't have a class,
			if(line.index('//NO_CLASS'))
				# pretend we found one
				found_swig_class = true
				found_define_class = true
			end

			# this was to avoid compiler warnings, 
			# but I turned off that warning
			# it's still here as an example of how to use skip_until_close_brace
#			if(line.index("SWIG_AsVal"))
#				skip_until_close_brace = true
#			end
			
			if(skip_until_close_brace)
				if(line.index("}"))
					skip_until_close_brace = false
				end
				line = "//#{line}"
			end
			
			
			out.puts(line)
		end
	end
	
	if(!found_swig_class)
		puts("ERROR! Didn't find swig class")
		exit(1)
	end
	
	if(!found_define_module)
		puts("ERROR! Didn't find define module")
		exit(1)
	end
	
	if(!found_init)
		puts("ERROR! Didn't find init")
		exit(1)
	end
	
	if(!found_define_class)
		puts("ERROR! Didn't find define class")
		exit(1)
	end
	
	File.delete(broken)
end

$main_module = 'mWxruby2'
fixmodule(ARGV[0])
