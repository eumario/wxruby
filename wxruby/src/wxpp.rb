# wxpp.rb
# template expander for wxruby
# Copyright 2003 Kevin Smith
# Licensed under the wxWindows license 3

def rubyClassNameFromCppClassName(className)
	return className[0,1].upcase + className[1..-1]
end

def getWxName(name)
    return "Wx" + name
end

def isStringClass(className)
    return (className == 'wxString' || className == 'wxString&')
end

def isWxClass(className)
	if(className == 'wxWindowID' || className == 'wxCoord' || 
        className == 'wxDragResult')
		return false
	end
	return (className.index('wx') == 0 && !className.index('*'))
end

def isReference(className)
    #puts(className)
    if(isStringClass(className))
        return false
    end
    return (className.index('&'))
end

def isPointer(className)
    return (className.index('*'))
end

def convertReferenceToPointer(className)
    if(isReference(className))
        return className.gsub(/[&]/, '*')
    end
    return className
end

def convertPointerToBaseClass(className)
    return className.gsub(/[*]/, '')
end

def convertReferenceToBaseClass(className)
    return className.gsub(/[&]/, '')
end

def getRubyToCppConversionMethod(parameter)
    className = convertReferenceToPointer(parameter.cppClass)
    if(className == 'long' || className == 'wxCoord')
        method = "NUM2LONG"
    elsif(className == 'int' || className == 'unsigned' || className == 'size_t' || 
                className == 'NativeFormat')
        method = "NUM2INT"
    elsif(className == 'bool')
        method = "IsTrue"
    elsif(isStringClass(className))
        method = "STR2CSTR"
    elsif(className == 'wxWindowID')
        method = "NUM2INT"
    elsif(className == 'wxItemKind' || className == 'wxDragResult' || 
                className == 'wxDataObject::Direction')
        method = "(#{className})NUM2INT"
    elsif(isPointer(className))
        method = "GetCpp<#{convertPointerToBaseClass(className)}>"
    else
        puts("****** RubyToCpp error: #{parameter.cppClass} -> #{className}")
        raise
    end
    return method
end

def getCppToRubyConversionMethod(className)
	#puts(className)
    if(className == 'int' || className == 'long' || className == 'wxCoord' || className == 'size_t' || className == 'NativeFormat')
        method = "INT2NUM"
	elsif(className == 'wxWindowID')
		method = "INT2NUM"
	elsif(className == 'wxItemKind' || className == 'wxDragResult' || className == 'wxDataObject::Direction')
		method = "INT2NUM"
	elsif(className == 'bool')
		method = "CppBoolToRubyBool"
	elsif(className == 'wxString' || className == 'wxString&')
		method = "rb_str_new2"
	elsif(className == 'void*')
		return ["\treturn INT2NUM((long)cppResult);"]
    elsif(isWxClass(className))
		wxName = rubyClassNameFromCppClassName(className)
		type = convertReferenceToBaseClass(wxName)
		return ["\treturn #{type}::init0(cppResult);"]
	else
        puts("****** CppToRuby error: #{className}")
        raise
    end
	lines = []
	lines << "\tVALUE rubyResult = #{method}(cppResult);"
	lines << "\treturn rubyResult;"
    return lines
end

def declareRubyParameterVariable(rubyName)
    result = []
    result << "\tVALUE #{rubyName} = Qnil;"
    return result
end

def getWrapperClassName(wrappedClassName)
    return wrappedClassName[0,1].upcase + wrappedClassName[1..-1]
end

def stripAwayUnusedPortions(line)
    body = line.slice!(/[{].*[}]/)
    line.gsub!(/virtual/, '')
    line.gsub!(/inline/, '')
    line.gsub!(/[;]/, ' ')
    line.gsub!(/ [*]/, '* ')
    line.gsub!(/ [&]/, '& ')
    line.gsub!(/  /, ' ')
    line.strip!
    return line
end

#################################################################
class Parameter
    def initialize(parmString)
        #puts(parmString)
        @isArray = parmString.index('[')
		variableAndDefault = parmString.split('=')
		if(variableAndDefault.size > 1)
	        @isOptional = true
			@defaultValue = variableAndDefault[1].strip.gsub(/``/, '"')
		end
		variable = variableAndDefault[0].gsub(/  /, ' ')
        words = variable.split(' ')
        @cppClass = words[0]
    end
	
	def declareCppVariable(cppName)
		result = []
		type = convertReferenceToPointer(cppClass)
		if(isStringClass(type))
			type = 'wxString'
		end
		cppDeclaration = "    #{type}"
		if(isArray)
			cppDeclaration += '*'
		end
		cppDeclaration += " #{cppName}"
		if(defaultValue)
			value = defaultValue
			if(isPointer(type) && value != "NULL")
				value = "(#{type})&" + value
			end
			cppDeclaration += "=#{value}"
        elsif(type == 'wxDragResult')
            # NOTE: this may go away when we optimize required parameters
            # to not have separate declaration and value setting!
            cppDeclaration += '=wxDragNone'
		elsif(!isWxClass(type))
			cppDeclaration += "=0"
		end
		cppDeclaration += ";"
		result << cppDeclaration
		if(isArray)
			result << "\tint #{cppName}_size = 0;"
		end
		return result
	end
	
    attr_reader :cppClass
    attr_reader :isOptional
	attr_reader :defaultValue
    attr_reader :isArray
end

#################################################################
class Parameters
    def initialize(parmListString)
        @original = parmListString.clone
        @parameters = getParameters(parmListString)
    end

    def getParameters(parmListString)
        result = []
        parmListString.gsub!(/[()]/, '')
        parmListString.gsub!(/const/, '')
        parms = parmListString.split(',')
		inOptionals = false
        parms.each do | parmString |
			thisParameter = Parameter.new(parmString)
            result << thisParameter
			if(thisParameter.isOptional)
				inOptionals = true
			elsif(inOptionals)
				puts parmListString
				raise "ERROR: Non-optional variable after optional!"
			end
        end
        return result
    end
    
    def size
        return parameters.size
    end
    
    def getOptionalCount
        optionalCount = 0
        parameters.each do | parameter |
            if(parameter.isOptional)
                optionalCount += 1
            end
        end
        return optionalCount
    end

	def declareRubyVariables
        lines = []
        parameters.each_index do | index |
            lines += declareRubyParameterVariable(getRubyParm(index))
        end
        return lines
	end
	
    def scanVariables
        optionalCount = getOptionalCount
        requiredCount = size - optionalCount
		scan = "\t"
		if(size > 0)
	        scan += "int got="
		end
		scan += "rb_scan_args(argc, argv, " 
        scan += '"' + requiredCount.to_s + optionalCount.to_s + '"'
        parameters.each_index do | index |
            className = parameters[index].cppClass
            scan += ", &#{getRubyParm(index)}"
        end
        scan += ");"
        return [scan, ""]
    end
	
    def convertVariables
        lines = []
        parameters.each_index do | index |
            parameter = parameters[index]
            cppName = getCppParm(index)
			lines += parameter.declareCppVariable(cppName)

			converter = getRubyToCppConversionMethod(parameter)
            lines << "\tif(got > #{index})"
            rubyName = getRubyParm(index)
            cppClass = parameter.cppClass
            if(parameter.isArray)
                arraySizeVariable = cppName + "_size"
                lines << "\t{"
                lines << "\t\t#{arraySizeVariable} = NUM2INT(rb_funcall" + 
                            "(#{rubyName}, rb_intern(\"size\"), 0));"
                lines << "\t\t#{cppName} = " +
                            "new #{cppClass}[#{arraySizeVariable}];"
                lines << "\t\tfor(int i = 0; i < #{arraySizeVariable}; i++)"
				lines << "\t\t\t#{cppName}[i] = #{converter}(rb_ary_entry(#{rubyName}, i));"
                lines << "\t}"
            else
                convert = "#{cppName} = #{converter}(#{rubyName});"
                lines << "\t\t" + convert
            end
        end
        lines << ""
        return lines
    end

    def getCppParametersForCall(parameterCount)
        list = ""
        parameterCount.times do | parameter_number |
            if(parameter_number > 0)
                list += ", "
            end
            parameter = parameters[parameter_number]
            cppName = getCppParm(parameter_number)
            if(parameter.isArray)
                list += cppName + "_size, "
            end
            className = parameter.cppClass
            if(isReference(className))
                list += '*'
            end
            list += "#{cppName}"
        end
        return list
    end

    def delegateCallTo(method, returnType)
        lines = []
		if(returnType == 'void')
			result = ""
		elsif(returnType == 'void*')
			result = "long cppResult = (long)"
		else
		    variableType = convertReferenceToBaseClass(returnType)
			result = "#{variableType} cppResult = "
		end
		call = "#{method}(#{getCppParametersForCall(size)});"
		lines << "    #{result}#{call}"
        return lines
    end

    def callDelete
        lines = []
        parameters.each_index do | i |
            if(parameters[i].isArray)
                lines << "\tdelete[] #{getCppParm(i)};"
            end
        end
        return lines
    end
    
    def getCppParm(index)
        return "cppParm#{index}"
    end
    
    def getRubyParm(index)
        return "rubyParm#{index}"
    end

    attr_reader :parameters
    attr_reader :original
end


#################################################################
class MethodPrototype
    def initialize(line)
		if(line.include?('static'))
			static = true
			line = line.gsub(/static/, '')
		end
        if(line.include?('abstract'))
            @isAbstract = true
            line = line.gsub(/abstract/, '')
        end
        line = stripAwayUnusedPortions(line)
        parmString = line.slice!(/[(].*[)]/)
        line.gsub!(/const /, '')
        @returnType, @delegateMethod = line.split(' ')
        @parameters = Parameters.new(parmString)
		constString, @cppMethod = line.split(/->/)
        if(constString.index('const'))
            @isConstMethod = true
        end
		if(@cppMethod)
			@cppMethod.strip!
		else
			@cppMethod = @delegateMethod
		end
		if(!@cppMethod)
			puts(parmString)
			raise "Error: no method name, possibly wrong class name in .t file"
		end
		@rubyMethod = un_camelcase(cppMethod)
		if(static)
			@cppMethod = 's_' + @cppMethod
		end
    end

	def un_camelcase(func)
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
    
    def declareAbstractHelper
        constString = ''
        if(isConstMethod)
            constString = ' const'
        end
        return "\tvirtual #{@returnType} " + 
                "#{@cppMethod}#{parameters.original}" + 
                constString + ";"
    end

    def delegateCall
        lines = parameters.delegateCallTo("pCpp->#{@delegateMethod}", returnType)
        return lines
    end

    def delegateStaticCall(cls)
        lines = parameters.delegateCallTo("#{cls}::#{@delegateMethod}", returnType)
        return lines
    end

    attr_reader :returnType
    attr_reader :cppMethod
	attr_reader :rubyMethod
    attr_reader :parameters
    attr_reader :isAbstract
    attr_reader :isConstMethod
end

#################################################################
class ConstructorPrototype
    def initialize(line)
        line = stripAwayUnusedPortions(line)
        parmString = line.slice!(/[(].*[)]/)
        @parameters = Parameters.new(parmString)
	end
	
	attr_reader :parameters
end

#################################################################
class ClassHandler
    def initialize(words)
        @name = words[0]
        @parent = words[1]
		@constructors = []
        @methods = []
		@staticMethods = []
    end
	
	def subclass
		@isSubclass = false
	end
    
    def abstract
        @isAbstract = true
    end
    
	def needsWrappingConstructor
		@needsWrappingConstructor = true
	end
	
	def noClientData
		@noClientData = true
	end

    def wxName
        return getWxName(name)
    end
    
    def parentWxName
        return getWxName(parent)
    end
	
	def exposedRubyName
		return name
	end
    
    def cppBaseClassName
        if(isAbstract)
            return cppClassName + 'Helper'
        end
        return cppClassName
    end
    
    def cppClassName
        return "wx" + name
    end
    
    def cppParentName
        return "wx" + parent
    end
    
	def rubyClassValue
		return "rubyClass"
	end

    def parentClassValue
        if(!parent)
            return 'rb_cObject'
        end
        return parentWxName + "::rubyClass"
    end
    
    def addMethod(line)
		realLine = line.strip
        if(realLine.size == 0 || realLine.index('#') == 0 || realLine.index("//") == 0)
			return nil
		end
		if(line.index(cppClassName + "("))
			@constructors << ConstructorPrototype.new(line)
		elsif(realLine.include?('static'))
	        @staticMethods << MethodPrototype.new(line)
		else
	        @methods << MethodPrototype.new(line)
		end
        return nil
    end
	
    def declareConstructors
        result = []
        result << "\tstatic VALUE alloc(VALUE self);"
        result << "\tstatic VALUE wrapNew(int argc, VALUE *argv, VALUE self);"
        result << "\tstatic VALUE init(int argc, VALUE *argv, VALUE self);"
        result << "\tstatic void validateCppObject(#{cppClassName}* pCpp);"
		if(@needsWrappingConstructor)
			result << "\tstatic VALUE init0(#{cppClassName}* cppObject);"
		end
		@constructors.each_index do | i |
			constructor = @constructors[i]
			result << "\tstatic bool constructor#{i}(int argc, VALUE *argv, VALUE self);"
		end
		result << ''
		if(isSubclass)
			@constructors.each_index do | i |
				constructor = @constructors[i]
				parameters = constructor.parameters
			end
		end
        return result
    end
    
    def declareMethods(methodArray)
        result = []
        methodArray.each do | method |
            line = "\tstatic VALUE #{method.cppMethod}(int argc, VALUE* argv, VALUE self);"
            result << line
        end
		result << ''
        return result
    end
	
	def declareMemberMethods
		return declareMethods(methods)
	end

    def declareStaticMethods
		return declareMethods(staticMethods)
    end
    
    def declareAbstractMethods
        lines = []
        methods.each do | m | 
            if(m.isAbstract)
                lines << m.declareAbstractHelper
            end
        end
        return lines
    end
    
    def declareHelperConstructor
        lines = []
        @constructors.each do | c |
            lines << "\t#{cppBaseClassName}#{c.parameters.original};"
        end
        return lines
    end
	
	def declareVariables
		result = []
		result << "\tstatic VALUE rubyClass;"
		result << "\tVALUE rubyObject;"
		result << ""
		return result
	end
	
    def defineConstructors
        result = []
        result << "\tif(rubyClass)"
        result << "\t\treturn;"
        if(parent)
            result << "\t#{parentWxName}::DefineClass();"
        end
        result << "\t#{rubyClassValue} = rb_define_class_under" + 
                "(GetWxModule(),\"#{exposedRubyName}\", #{parentClassValue});"
        result << "\trb_define_alloc_func(#{rubyClassValue},alloc);"
        result << "\trb_define_singleton_method(#{rubyClassValue}, \"new\", VALUEFUNC(wrapNew), -1);"
        result << "\trb_define_method(#{rubyClassValue}, \"initialize\", VALUEFUNC(init), -1);"
		result << ''
        return result
    end
    
    def defineMemberMethods
        result = []
        methods.each do | method |
            line = "\trb_define_method("
            line += "#{rubyClassValue}, "
            line += "\"#{method.rubyMethod}\", "
            line +=  "VALUEFUNC(#{method.cppMethod}), "
            line += "-1);"
            result << line
        end
		result << ''
        return result
    end
    
    def defineStaticMethods
        result = []
        staticMethods.each do | method |
            line = "\trb_define_singleton_method("
            line += "rubyClass, "
            line += "\"#{method.rubyMethod}\", "
            line +=  "VALUEFUNC(#{method.cppMethod}), "
            line += "-1);"
            result << line
        end
		result << ''
        return result
    end
    
	def implementVariables
		lines = []
		lines << "VALUE #{wxName}::rubyClass;"
		lines << ""
		return lines
	end

    def implementConstructors
        result = []
        result << "VALUE #{wxName}::alloc(VALUE self)"
        result << "{"
        result << "\treturn Data_Wrap_Struct(self, 0, 0, 0);"
        result << "}"
        result << ""
        result << "VALUE #{wxName}::wrapNew(int argc, VALUE *argv, VALUE cls)"
        result << "{"
        result << "    VALUE self = rb_funcall2(cls, rb_intern(\"allocate\"), 0, 0);"
        result << "    rb_obj_call_init(self, argc, argv);"
		result += convertSelf
		result += protectionAgainstNoInitialize
        result << "    return self;"
        result << "}"
        result << ""
        result << "void #{wxName}::validateCppObject(#{cppClassName}* pCpp)"
        result << "{"
		result << "    if(!pCpp)"
		result << '        rb_fatal("A subclass of ' + wxName + ' defined initialize that did not invoke super");'
        result << "}"
        result << ""
		if(@needsWrappingConstructor)
			result << "VALUE #{wxName}::init0(#{cppClassName}* cppObject)"
			result << "{"
			result << "    if(cppObject==NULL) return Qnil;"
			result << "    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);"
			result << "    DATA_PTR(self) = cppObject;"
			result << "    return self;"
			result << "}"
			result << ""
		end
        result += implementInit
		@constructors.each_index do | i |
			name = "constructor#{i}"
			parameters = @constructors[i].parameters
			result += implementConstructor(name, parameters)
		end
        return result
    end
	
	def implementInit
		result = []
		result << "VALUE #{wxName}::init(int argc, VALUE* argv, VALUE self)"
		result << "{"
		@constructors.each_index do | i |
			result << "\tif(constructor#{i}(argc, argv, self))"
			result << "\t\treturn self;"
		end
		result << "\trb_fatal(\"No matching constructor found\");"
		result << "\treturn Qnil;"
		result << "}"
		result << ""
		return result
	end
    
    def implementStaticMethods
        result = []
        staticMethods.each do | method |
#puts(method.cppMethod)
            returnType = method.returnType
            parameters = method.parameters

            lines = []
            lines += startImplementMethod(method.cppMethod, returnType, "cls")
            lines += parameters.declareRubyVariables
            lines += parameters.scanVariables
            lines += parameters.convertVariables
            lines += method.delegateStaticCall(cppClassName)
            lines += endImplementMethod(parameters, returnType)
            
            result += lines
        end
        return result
    end
	
	def protectionAgainstNoInitialize
		result = []
        result << "    validateCppObject(pCpp);"
		result << ""
		return result
	end
	
    def implementMemberMethods
        result = []
        methods.each do | method |
#puts(method.cppMethod)
            returnType = method.returnType
            parameters = method.parameters

            lines = []
            lines += startImplementMethod(method.cppMethod, returnType, "self")
            lines += convertSelf
			lines += protectionAgainstNoInitialize
            lines += parameters.declareRubyVariables
            lines += parameters.scanVariables
            lines += parameters.convertVariables
            lines += method.delegateCall
            lines += endImplementMethod(parameters, returnType)
            
            result += lines
        end
        return result
    end
	
    def startImplementMethod(cppMethod, returnType, firstParmName)
        lines = [
            "VALUE #{wxName}::#{cppMethod}" + 
                    "(int argc, VALUE* argv, VALUE #{firstParmName})", 
            "{",
            ]
        return lines
    end
    
    def endImplementMethod(parameters, returnType)
        lines = [""]
        lines += parameters.callDelete
        if(returnType == 'void')
            lines << "\treturn Qnil;"
		elsif(isPointer(returnType) && returnType != 'void*')
			realReturnType = getWrapperClassName(returnType)
			realReturnType = convertPointerToBaseClass(realReturnType)
            lines << "\tVALUE rubyResult = GetMappedRubyObjectFromCppObject(cppResult);"
			lines << "\tif(rubyResult == Qnil)"
			lines << "\t\trubyResult = #{realReturnType}::init0(cppResult);"
            lines << "\treturn rubyResult;"
        else
            lines += getCppToRubyConversionMethod(returnType)
        end
        lines << "}"
        lines << ""
        return lines
    end

    def implementAutoDefine
        return [
            "class ZAutoDefine#{wxName}",
            "{",
            "public:",
            "   ZAutoDefine#{wxName}()",
            "    {",
            "       #{wxName}::DefineClass();",
            "    }",
            "};",
            "static ZAutoDefine#{wxName} auto#{wxName};",
            "",
        ]
    end
    
    def convertSelf
        line = "\t#{cppClassName}* pCpp = "
        line += "GetCpp<#{cppClassName}>(self);"
        return [line]
    end
    
    def implementConstructor(name, parameters)
        result = []
		result << "bool #{wxName}::#{name}(int argc, VALUE* argv, VALUE self)"
		result << "{"
		total = parameters.size
		required = total - parameters.getOptionalCount
		result << "\tif(argc < #{required} || argc > #{total})"
		result << "\t\treturn false;"
		result << ""
        result += parameters.declareRubyVariables
        result += parameters.scanVariables
        result += parameters.convertVariables
		if(isSubclass)
        	result += parameters.delegateCallTo("new #{wxName}", wxName)
		else
        	result += parameters.delegateCallTo("new #{cppBaseClassName}", cppClassName + "*")
		end
        result += endImplementConstructor
        return result
    end
    
    def endImplementConstructor
        lines = []
		if(!@noClientData)
			lines << "\tVALUE vdata = rb_hash_new();"
			lines << "\trb_hash_aset(vdata,rb_str_new2(\"self\"),self);"
			lines << "\tcppResult->SetClientData((void*)vdata);"
		end
        lines << "\tDATA_PTR(self) = cppResult;"
		lines << "\tMapRubyObjectToCppObject(self, cppResult);"
        lines << "\treturn true;"
        lines << "}"
        lines << ""
        return lines
    end
    
    def delegateConstructor(parameters)
        lines = []
        call = "\tpCppSelf = new #{cppClassName}("
        call += parameters.getCppParametersForCall(0)
        call += ");"
        lines << call
    end

    attr_reader :name
    attr_reader :parent
    attr_reader :methods
	attr_reader :isSubclass
    attr_reader :isAbstract
	attr_reader :staticMethods
end

#################################################################
class Parser
	def initialize
		@classes = {}
	end

    def parse(filename)
        @outputLines = []
        File.foreach(filename) do | line |
            line.chomp!
            begin
                if(line.strip.index('//$$') == 0)
                        result = command(line)
                elsif(in_methods)
                    currentClass.addMethod(line)
                    result = nil
                else
                    result = [line]
                end
                output(result)
            rescue
                puts("on line: #{line}")
                raise
            end
        end
    end
    
    def output(lines)
        if(in_file && lines)
            @outputLines += lines
        end
    end
    
    def command(body)
        body.gsub!(/[:<]/, ' ')
        body.gsub!(/  /, '')
        words = body.split(' ')
        comment = words.shift
        command = words.shift
        case command
            when 'CLASS'
                @currentClass = ClassHandler.new(words)
				@classes[@currentClass.wxName] = @currentClass
                return nil
            when 'ABSTRACT'
                @currentClass.abstract
                return nil
			when 'AS_SUBCLASS'
				@currentClass.subclass
				return nil
            when 'METHODS_BEGIN'
                @in_methods = true
                return nil
            when 'METHODS_END'
                @in_methods = false
                return nil
			when 'NEEDS_WRAPPING_CONSTRUCTOR'
				@currentClass.needsWrappingConstructor
				return nil
			when 'NO_CLIENT_DATA'
				@currentClass.noClientData
				return nil
            when 'BEGIN_H_FILE'
                return handleBeginHeader(words)
            when 'END_H_FILE'
                return handleEndHeader(words)
            when 'BEGIN_CPP_FILE'
                return handleBeginCppFile(words)
            when 'END_CPP_FILE'
                return handleEndCppFile(words)
            when 'RB_DEFINE'
                return handleDefine(words)
            when 'RB_DECLARE'
                return handleDeclare(words)
            when 'RB_IMPLEMENT'
                return handleImplement(words)
			when 'RB_DECLARE_CLASS'
				return handleDeclareClass(words)
            when 'RB_IMPLEMENT_CLASS'
                return handleImplementClass(words)
        end
        puts("Unknown command #{command} in line #{body}")
        exit(1)
    end

    def handleBeginHeader(words)
		thisClass = getSpecifiedClass(words)
        @outputFile = "#{thisClass.name.downcase}.h"
        @in_file = true
        protection = "WXRUBY_#{thisClass.name.upcase}_H"
        return [
            "/*",
            "",
            "    This file was auto-generated. Do not edit this file.",
            "",
            "*/",
            "#ifndef #{protection}",
            "#define #{protection}",
            "",
        ]
    end
    
    def handleEndHeader(words)
		thisClass = getSpecifiedClass(words)
        lines = [
            "",
            "#endif",
        ]
        output(lines)
        flushOutput
        return nil
    end
    
    def handleBeginCppFile(words)
		thisClass = getSpecifiedClass(words)
        @outputFile = "#{thisClass.name.downcase}.cpp"
        @in_file = true
        lines = [
            "/*",
            "",
            "    This file was auto-generated. Do not edit this file.",
            "",
            "*/",
            "#include \"wx.h\"",
            "#include \"#{thisClass.name.downcase}.h\"",
        ]
        if(thisClass.parent)
            lines << "#include \"#{thisClass.parent.downcase}.h\""
        end
        lines << ""
        return lines
    end
    
    def handleEndCppFile(words)
		thisClass = getSpecifiedClass(words)
        flushOutput
        return nil
    end
    
    def handleDefine(words)
		thisClass = getSpecifiedClass(words)
        result = ['//-----------BEGIN AUTO DEFINE METHODS-----------']
        result += thisClass.defineConstructors
        result += thisClass.defineStaticMethods
        result += thisClass.defineMemberMethods
        result << '//-----------END AUTO DEFINE METHODS-----------'
        return result
    end
	
	def handleDeclareClass(words)
		thisClass = getSpecifiedClass(words)
		result = []
        if(thisClass.isAbstract)
            result << "class #{thisClass.cppBaseClassName} : public #{thisClass.cppClassName}"
            result << "{"
            result << "public:"
            result += thisClass.declareHelperConstructor
            result += thisClass.declareAbstractMethods
            result << "};"
            result << ""
            inherit = ""
        elsif(thisClass.isSubclass)
			inherit = " : public #{thisClass.cppClassName}"
		else
			inherit = ""
		end
		result << "class #{thisClass.wxName}#{inherit}"
		result << "{"
		result << "public:"
		result += handleDeclare(words)
		result << "};"
		result << ""
		return result
	end
    
    def handleDeclare(words)
		thisClass = getSpecifiedClass(words)
        result = ['//-----------BEGIN AUTO DECLARE-----------']
        result << "\tstatic void DefineClass();"
		result << ""
        result += thisClass.declareConstructors
		result += thisClass.declareStaticMethods
        result += thisClass.declareMemberMethods
		result += thisClass.declareVariables
        result << '//-----------END AUTO DECLARE-----------'
        return result
    end
	
	def handleImplementClass(words)
		thisClass = getSpecifiedClass(words)
		result = []
		result << "void #{thisClass.wxName}::DefineClass()"
		result << "{"
		result += handleDefine(words)
		result << "}"
		result += handleImplement(words)
		result << ""
		return result
	end
    
    def handleImplement(words)
		thisClass = getSpecifiedClass(words)
        result = ['//-----------BEGIN AUTO IMPLEMENT METHODS-----------']
        result += thisClass.implementConstructors
        result += thisClass.implementStaticMethods
        result += thisClass.implementMemberMethods
		result += thisClass.implementVariables
        result += thisClass.implementAutoDefine
        result << '//-----------END AUTO IMPLEMENT METHODS-----------'
        return result
    end
    
    def flushOutput
        @in_file = false
        File.open(outputFile, "w") do | outFile |
            outFile.puts(@outputLines.join("\n"))
        end
        @outputLines = []
    end
	
	def getSpecifiedClass(words)
		className = words[0]
		if(!className)
			className = @classes.keys[0]
		end
		return @classes[className]
	end

    attr_reader :outputFile
    attr_reader :in_file
    attr_reader :in_methods
	attr_reader :in_constructors
    attr_reader :currentClass
end


#################################################################

parser = Parser.new
parser.parse(ARGV[0])
