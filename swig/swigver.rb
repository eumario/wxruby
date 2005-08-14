require 'tempfile'

$key = 'ThisIsOurSwigVersion'

def get_version_line(file)
	input = file.open
	c = input.readlines
	input.close

	c.each do | line |
		if(line.index($key))
			return line
		end
	end
	return nil
end

def create_swig_file
	swig_file = Tempfile.new("swigversion.i")
	swig_file.puts("%module Test")
	swig_file.puts("#define #{$key} SWIG_VERSION")
	swig_file.close
	return swig_file
end

def do_swig(swig_file)
	c_file = Tempfile.new("swigversion.c")
	c_file.close
	result = `swig -ruby -o #{c_file.path} #{swig_file.path}`
	return c_file
end

def extract_version(line)
	re = Regexp.new(/0x(\d\d)(\d\d)(\d\d)/)
	match = re.match(line)
	major_version = match[1].to_i
	minor_version = match[2].to_i
	revision = match[3].to_i
	return "SWIG Version #{major_version}.#{minor_version}.#{revision}"
end

swig_file = create_swig_file
c_file = do_swig(swig_file)
line = get_version_line(c_file)
version = extract_version(line)

puts(version)
