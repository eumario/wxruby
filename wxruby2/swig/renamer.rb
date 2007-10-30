# renamer.rb
#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

#   This script post-processes the SWIG output
#   to rename methods to ruby_naming_conventions

camelCaseFile = ARGV[0]+".old"
File.rename(ARGV[0], camelCaseFile)

this_module = File.basename(ARGV[0])

def un_camelcase(func)
    if(func[0,2] == 'wx')
        func = func[2..-1]
    end
    result = ""
    scratch = ""
    func.each_byte do |byte|
        if (?A..?Z).include? byte
            scratch << byte.chr
        else
            if scratch.size==1
                result += "_"+scratch
                scratch = ""
            elsif scratch.size>1
                result += "_"+scratch[0..-2]+"_"+scratch[-1,1]
                scratch = ""
            end
                result += byte.chr
        end
    end
    result += "_"+scratch if scratch!=""
    result = result[1..-1] if result[0,1]=='_'
    result.downcase
end
    

def fix_define_method(line)
    re = Regexp.new('".*"')
    match = re.match(line)
    if(match)
        quoted_method_name = match[0]
        return line if quoted_method_name == '"THE_APP"'
        method_name = quoted_method_name[1..-2]
        new_method_name = '"' + un_camelcase(method_name) + '"'
        line[quoted_method_name] = new_method_name
        #puts(line)
    end
    return line
end

def strip_wx(class_name) 
  return class_name.sub(/^wx_?/i,'')
end

def fix_quoted_wx(line)
    match = /"(.*)"/.match(line)
    if(match)
      #puts("Stripping #{line}")
      quoted_wx_name = match[1]
      wx_name = quoted_wx_name.sub(/^wx_?/i,'')
      line[match[0]] = '"' + wx_name + '"'
      #puts(line)
    end
    return line
end

#
# NSK - SWIG handles some constants the same way as methods.
# Use the case of the value to figure out which naming scheme to use
# (Uppercase ones are constant, Mixed case are methods)
#
def is_constant_or_method(line)
    re = Regexp.new('".*"')
    match = re.match(line)
    if(match)
	#puts("Stripping #{line}")
        quoted_wx_name = match[0]
        wx_name = quoted_wx_name[1..-2]
	swx_name = strip_wx(wx_name)
        if (swx_name == swx_name.upcase)
	    return fix_quoted_wx(line)
	else
            return fix_define_method(line)
	end
        
    end
    return line
end

File.open(ARGV[0], "w") do | out |
    File.foreach(camelCaseFile) do | line |
        if(line.index("rb_define_method") || line.index("rb_intern"))
            line = fix_define_method(line)
        end
        if(line.index("rb_define_class_under"))
            line = fix_quoted_wx(line)
        end
        if(line.index("rb_define_const"))
            line = fix_quoted_wx(line)
        end
        if(line.index("rb_define_singleton_method"))
            line = is_constant_or_method(line)
        end
        if(line.index("rb_define_module_function"))
            line = fix_define_method(line)
        end
        out.puts(line)
    end
end

File.delete(camelCaseFile)
