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
            lines << '    if(alive == Qnil)'
            lines << '    {'
            lines << '        rb_global_variable(&alive);'
            lines << '        alive = rb_hash_new();'
            lines << '    }'
            lines << '    rb_hash_aset(alive, INT2NUM((int)this), self);'
            line = lines.join("\n")    
        end
        
        if(line.index("~Director()"))
            lines = [line]
            lines << '    printf("' + this_module + '" " ~Director %p\n", this);'
	    #lines << '    rb_hash_aset(alive, INT2NUM((int)this), Qnil);'
	    lines << '    GcMarkDeleted(this);'
            line = lines.join("\n")
        end
        
        if($class_name && line.index("delete arg1"))
            lines = []
            lines << "    Swig::Director* director = (Swig::Director*)(SwigDirector_#{$class_name}*)arg1;"
            lines << '    printf("' + this_module + '" " Checking %p\n", director);'
            #lines << "    VALUE self = rb_hash_aref(alive, INT2NUM((int)director));"
	    #lines << "    if(self == Qnil)"
	    lines << "    if (GcIsDeleted(director))"
            lines << "    {"
            lines << "        printf(\"%p is already dead!\\n\", director);"
            lines << "        return;"
            lines << "    }"
            lines << "    printf(\"deleting %p\\n\", director);"
            lines << "    delete arg1;"
            line = lines.join("\n")
        end
        
        out.puts(line)
    end
end

File.delete(broken)
