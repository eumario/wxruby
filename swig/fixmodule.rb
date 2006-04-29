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
	found_gcitem_destructor = false
	
	core_name = File.basename(filename, ".cpp")
puts("core_name: #{core_name}")
	wx_name = "wx"+core_name
	this_module = 'mWx' + core_name
	parent_wxklass = $parents[wx_name]
	if (parent_wxklass)
		parent_name = parent_wxklass[2..-1]
puts("      : #{parent_name}")
	end
	
	skip_until_blank_line = false
	skip_entire_method = false
	brace_level = 0
	
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
			
			# Fix 1.3.29's ruby tracking
			if(ENV['SWIGVER'] == 'SWIG Version 1.3.29')

			  if(line.index("static VALUE swig_ruby_trackings"))
					line = "extern VALUE swig_ruby_trackings;"
			  end
				if(line.index("static ID swig_ruby_hash_delete"))
					line = "extern ID swig_ruby_hash_delete;"
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
				
			end

			# instead of defining a new module,
			if(line.index("rb_define_module(\"Wx"))
				# set this module equal to the real main module
				line = "#{this_module} = #{$main_module};"
				found_define_module = true
			end
			
			# at the top of our Init_ function,
			if(line.index("Init_#{wx_name}("))
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
				found_define_class = true
			end
			
			# if this module doesn't have a class,
			if(line.index('//NO_CLASS'))
				# pretend we found one
				found_swig_class = true
				found_define_class = true
			end
			
			# remove the bogus GCItem destructor
			if(line.strip == 'GCItem::~GCItem()')
				found_gcitem_destructor = true
				skip_until_blank_line = true
			end
			
			# remove the UnknownExceptionHandler::handler method
			if(line.index('void UnknownExceptionHandler::handler()'))
				skip_entire_method = true
			end

			
			if(skip_entire_method)
				line = "//#{line}"
				if(line.index('{'))
					brace_level += 1
				end
				if(line.index('}'))
					brace_level -= 1
				end
				if(brace_level == 0)
					skip_entire_method = false
				end
			end
			
			if(skip_until_blank_line)
				if(line.strip.size == 0)
					skip_until_blank_line = false
				else
					line = '// ' + line
				end
			end
			
			out.puts(line)
		end
	end
	
	if(!found_swig_class)
		puts("ERROR! #{__FILE__} Didn't find swig class")
		exit(1)
	end
	
	if(!found_define_module)
		puts("ERROR! #{__FILE__} Didn't find define module")
		exit(1)
	end
	
	if(!found_init)
		puts("ERROR! #{__FILE__} Didn't find init")
		exit(1)
	end
	
	if(!found_define_class)
		puts("ERROR! #{__FILE__} Didn't find define class")
		exit(1)
	end
	
	if(!found_gcitem_destructor)
		puts("NOTE: #{__FILE__} Didn't find gcitem destructor")
	end
	
	File.delete(broken)
end

$main_module = 'mWxruby2'
fixmodule(ARGV[0])
