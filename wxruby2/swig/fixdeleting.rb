# fixdeleting.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

#   This script post-processes the SWIG output
#   to prevent ruby from trying to delete C++
#   objects that wxWidgets has already deleted
#   I know it's ugly :-(

broken = ARGV[0]+".old"
File.rename(ARGV[0], broken)

this_module = File.basename(ARGV[0])


File.open(ARGV[0], "w") do | out |
    File.foreach(broken) do | line |
    
        #
        # HACK! Added to implement wxGetApp
        #
        if(line.index('_wrap_new_App(int argc, VALUE *argv, VALUE self)'))
        		lines = [line]
        		lines << "wxRubyApp::app_ptr = self;"
        		line = lines.join("\n")
        end
        if(line.index("SwigDirector_") == 0)
            matches = Regexp.new('_(\w+)').match(line)
            $class_name = matches[1]
            #puts("-----------------#{$class_name}")
        end
        
        if(line.index("#define SWIG_name"))
            lines = [line]
            lines << "static VALUE alive = Qnil;"
            line = lines.join("\n")
        end
        
        if(line.index("Director(VALUE self,"))
            lines = [line]
	    			lines << '    printf("' + this_module + '" " new Director %p\n", this);'
	    			lines << '    fflush(stdout);'
	    			lines << '    GcMapPtrToValue(this,self);'
            line = lines.join("\n")    
        end
        
        if(line.index("~Director()"))
            lines = [line]
            lines << '    printf("' + this_module + '" " ~Director %p\n", this);'
	    			lines << '    fflush(stdout);'
	    			#lines << '    rb_hash_aset(alive, INT2NUM((int)this), Qnil);'
	    			lines << '    GcMarkDeleted(this);'

            line = lines.join("\n")
        end
        
        if($class_name && line.index("delete arg1"))
            lines = []
            lines << "    Swig::Director* director = (Swig::Director*)(SwigDirector_#{$class_name}*)arg1;"
            lines << '    printf("' + this_module + '" " Checking %p\n", director);'
	    			lines << "    if (GcIsDeleted(director))"
            lines << "    {"
            lines << "        printf(\"%p is already dead!\\n\", director);"
            lines << "        return;"
            lines << "    }"
            lines << "    printf(\"deleting %p\\n\", director);"
	    			lines << "    fflush(stdout);"
            lines << "    delete arg1;"
            line = lines.join("\n")
	#
	# HACK! If we don't have the latest version of SWIG, 
	# classes with no virtual methods will not be wrapped.
	# For now, since we can't protect those classes, don't
	# let the GC delete them either
	#
	elsif (line.index(/delete arg1/))
		line = "    //delete arg1;"
        end
        
        # replace dynamic_cast with 
        if(line.index("Swig::Director *director = dynamic_cast<Swig::Director *>(arg1);"))
            line = 'Swig::Director *director = (Swig::Director*)(arg1);'
        end
        
        out.puts(line)
    end
end

File.delete(broken)
