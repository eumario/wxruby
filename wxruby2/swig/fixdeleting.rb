# fixdeleting.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

#   This script post-processes the SWIG output
#   to prevent ruby from trying to delete C++
#   objects that wxWidgets has already deleted
#   I know it's ugly :-(

filename = ARGV[0]
broken = filename+".old"
File.rename(filename, broken)

this_module = File.basename(filename)


File.open(filename, "w") do | out |
	core_name = File.basename(filename, ".cpp")
puts("core_name: #{core_name}")
	wx_name = "wx"+core_name
	
	if(core_name == "App")
		found_app_constructor = false
	else
		found_app_constructor = true
	end
	found_director_constructor = false
	found_director_destructor = false
	found_deleter = false
	skip_deleter_fix = false
	
	director_class = nil

	File.foreach(broken) do | line |
    
		# if we found our director class constructor,
		if(line.index('SwigDirector_') == 0)
			# memorize its class name
			director_class = line.split(/\:/)[0]
		end
		
		# in the App class constructor,
        if(line.index('_wrap_new_App(int argc, VALUE *argv, VALUE self)'))
			# set the global app_ptr so wxGetApp can work
			lines = [line]
			lines << "wxRubyApp::app_ptr = self;"
			line = lines.join("\n")
			found_app_constructor = true
        end
		
		# in the Director constructor, 
        if(line.index("Director(VALUE self"))
			# make a note of this object
			lines = [line]
			lines << '#ifdef wxDEBUG'
			lines << '    printf("' + this_module + '" " new Director %p\n", this);'
			lines << '    fflush(stdout);'
			lines << '#endif'
			lines << '    GcMapPtrToValue(this,self);'
			line = lines.join("\n")    
			found_director_constructor = true
		end

		# in the Director destructor,
        if(line.index("~Director()"))
			# make a note that this object has been deleted
			lines = [line]
			lines << '#ifdef wxDEBUG'
			lines << '    printf("' + this_module + '" " ~Director %p\n", this);'
			lines << '    fflush(stdout);'
			lines << '#endif'
			lines << '    GcMarkDeleted(this);'
			line = lines.join("\n")
			found_director_destructor = true
        end
    
		# where the C++ object was being deleted,    
        if(line.index("delete arg1") && !skip_deleter_fix && director_class)
			lines = []
			lines << "    Swig::Director* director = (Swig::Director*)(#{director_class}*)arg1;"
			lines << '#ifdef wxDEBUG'
			lines << '    printf("' + this_module + '" " Checking %p\n", director);'
			lines << '#endif'
			lines << "    if (GcIsDeleted(director))"
			lines << "    {"
			lines << '#ifdef wxDEBUG'
			lines << "        printf(\"%p is already dead!\\n\", director);"
			lines << '#endif'
			lines << "        return;"
			lines << "    }"
			lines << '#ifdef wxDEBUG'
			lines << "    printf(\"deleting %p\\n\", director);"
			lines << "    fflush(stdout);"
			lines << '#endif'
			lines << "    delete arg1;"
			line = lines.join("\n")
			found_deleter = true
		#
		# HACK! If we don't have the latest version of SWIG, 
		# classes with no virtual methods will not be wrapped.
		# For now, since we can't protect those classes, don't
		# let the GC delete them either
		#
#		elsif (line.index(/delete arg1/))
#			line = "    //delete arg1;"
#			end
#			
#			# replace dynamic_cast with 
#			if(line.index("Swig::Director *director = dynamic_cast<Swig::Director *>(arg1);"))
#				line = 'Swig::Director *director = (Swig::Director*)(arg1);'
#			end
#			if (line.index('resultdirector = dynamic_cast<Swig::Director *>(result);'))
#				lines = []
#				lines << 'try {'
#				lines << 'resultdirector = dynamic_cast<Swig::Director *>(result);'    
#				lines << '} catch (...) {'
#				lines << '    resultdirector = NULL;'
#				lines << '}'
#				line = lines.join("\n")
#			end
			
		end
		
		# if we have no director,
		if(line.index('//NO_DIRECTOR'))
			# don't apply the delete fix
			skip_deleter_fix = true
		end

		# if this module doesn't have a class or has no director,
		if(line.index('//NO_CLASS') || line.index('//NO_DIRECTOR'))
			# pretend we found everything
			found_director_constructor = true
			found_director_destructor = true
			found_deleter = true
		end


		out.puts(line)
	end
	
	if(!found_app_constructor)
		puts("ERROR: Didn't find found_app_constructor")
		exit(1)
	end

	if(!found_director_constructor)
		puts("WARNING: Didn't find found_director_constructor")
	end

	if(!found_director_destructor)
		puts("WARNING: Didn't find found_director_destructor")
	end

	if(director_class && !found_deleter)
		puts("ERROR: Didn't find found_deleter")
		exit(1)
	end
end

File.delete(broken)
