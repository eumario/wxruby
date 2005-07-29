# fixmodule.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This script post-processes the SWIG output
#   to allow a single Ruby module to be defined 
#   across multiple SWIG modules
#   I know it's ugly :-(

require 'swig/classes/include/parents'

def fixmodule(filename)
	broken = filename+".old"
	File.rename(filename, broken)
	
	this_module = File.basename(filename)
	
	File.open(filename, "w") do | out |
	
		File.foreach(broken) do | line |
			if(line.index("static VALUE mWx"))
				this_module = line.split[2].gsub(';', '')
				#puts("module: " + this_module)
				line += "   extern VALUE #{$main_module};"
			end
			if (line.index('swig_class cWx') and not line.index("extern"))
				re = /cWx.*/
				core_name = re.match(line)[0]
				core_name = "w"+core_name[2..(core_name.length-2)]
				parent_wxklass = $parents[core_name]
				result = []
				if (parent_wxklass)
					parent_wxklass.each do |parent_name|
						result << "extern swig_class cWx#{parent_name[2..(parent_name.length)]};"
					end
				end
				result << line
				line = result.join("\n")
						
			end
			if(line.index("bool Swig::Director::swig_up"))
				line = "//" + line
			end
			if(line.index("rb_define_module(\"Wx"))
				line = "#{this_module} = #{$main_module};"
			end
			
			if(line.index("SWIGEXPORT(void) Init_"))
				line += "static bool initialized;\n"
				line += "if(initialized) return;\n"
				line += "initialized = true;\n"
			end
	 
			if(line.index("rb_define_class_under"))
				re = Regexp.new('\"(.*)\"')
				match = re.match(line)
				if match != nil
				  core_name = match[1]
				  this_wxklass = 'wx' + core_name
				  parent_wxklass = $parents[this_wxklass]
				  result = []
				  if(parent_wxklass)
					  parent_name = parent_wxklass[2..-1]
					  result << "    extern void Init_wx#{parent_name}();"
					  result << "    Init_wx#{parent_name}();"
					  result << "    //extern swig_class cWx#{parent_name};"
					  parent_klass = "cWx#{parent_name}.klass"
					  line = line.gsub(/rb_cObject/, parent_klass)
				  end
				result << line
				line = result.join("\n")
				end
	  
			end
			
			out.puts(line)
		end
	end
	
	File.delete(broken)
end

$main_module = 'mWxruby2'
fixmodule(ARGV[0])
