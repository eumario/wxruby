# rakewx.rb
#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

# determine and/or set the version
VERSION_FILE = File.join %w|lib wx version.rb|
if ENV['WXRUBY_VERSION']
  WXRUBY_VERSION = ENV['WXRUBY_VERSION']
  File.open(VERSION_FILE, 'w') do | version_file |
    version_file.puts "module Wx"
    version_file.puts "  WXRUBY_VERSION    = '#{WXRUBY_VERSION}'"
    version_file.puts "  WXWIDGETS_VERSION = '2.6.3'"
    version_file.puts "end"
  end
elsif File.exists?(VERSION_FILE)
  require VERSION_FILE
  WXRUBY_VERSION = Wx::WXRUBY_VERSION
else
  WXRUBY_VERSION = ''
end

# sources and destinations of various intermediate build targets
$swig_dir = 'swig'
$src_dir = 'src'
$obj_dir = 'obj'
$dest_dir = 'lib'
$classes_dir = File.join($swig_dir, 'classes')
$original_h_dir = File.join($classes_dir, 'include')
$optional_dir = File.join($classes_dir, 'optional')
$optional_h_dir = File.join($optional_dir, 'include')

$swig_cmd = "swig"
$swig_minimum_version = '1.3.29'

# force building against either a release build or debug build of
# wxWidgets. Only one should be used; if neither is specified, the
# default wx configuration will be used. Use of these options depends on
# there being an appropriately compiled version of wxWidgets available.
$debug_build = ENV['WXRUBY_DEBUG'] ? true : false
$release_build = ENV['WXRUBY_RELEASE'] ? true : false

# Force non-unicode build with WXRUBY_NO_UNICODE.  Unicode will be
# the default build now
$unicode_build = ENV['WXRUBY_NO_UNICODE'] ? false : true

$verbose_debug = ENV['WXRUBY_VERBOSE'] ? true : false

if $release_build
	puts('Enabling RELEASE build')
elsif $debug_build
	puts('Enabling DEBUG build')
end

if not $unicode_build
        puts('Disabling UNICODE build')
end

if($verbose_debug)
	puts('Enabling VERBOSE debugging output')
	$verbose_flag = ' -DwxDEBUG=1 '
end


def have_good_swig
	begin
		version = `#{$swig_cmd} -version`.strip.split("\n")[0]
	rescue
		return false
	end
    if not version
		return false
	end
        ENV['SWIGVER'] = version
    return version >= "SWIG Version #{$swig_minimum_version}" &&
           version < "SWIG Version 2"
end


def wx_config(opt)
  if $release_build
    debug_mode = '--debug=no'
  elsif $debug_build
    debug_mode = '--debug=yes'
  else
    debug_mode = '' # go with default
  end

  `wx-config #{debug_mode} #{opt}`.strip + " "
end

def use_wx_config
    $wx_version = wx_config("--version")
    $wx_cppflags = wx_config("--cppflags")
    $wx_libs = wx_config("--libs")
    $cpp = wx_config("--cxx")
    $ld = wx_config("--ld")
end

def get_classes
    classes = []
    Dir::foreach($classes_dir) do | filename |
        filespec = File.join($classes_dir, filename)
        #puts("#{filename}: #{File.directory?(filespec)})
        if(File.extname(filename) == '.i')
            classes << File.basename(filename, '.i')
        end
    end
    #puts classes
    return classes.sort
end

def get_optional_classes
    classes = []
    if ENV['WXSCINTILLA']
      classes << "Scintilla"
    end
    return classes.sort
end

def all_obj_bases
    extra_classes = 
        ["wx", "RubyConstants", "RubyStockObjects", 
            "RubyEventTypes", "Functions", "Mac", 
			"Events", ]
    return get_classes + get_optional_classes + extra_classes
end

def special_swig_file(base_name)
    return File.join($swig_dir, "#{base_name}.i")
end

def normal_swig_file(base_name)
    return File.join($classes_dir, "#{base_name}.i")
end

def optional_swig_file(base_name)
    return File.join($optional_dir, "#{base_name}.i")
end

def shared_swig_files
    common_i = File.join($swig_dir, "common.i")
    typedefs_i = File.join($swig_dir, "typedefs.i")
    typemap_i = File.join($swig_dir, "typemap.i")
    return [common_i, typedefs_i, typemap_i]
end

def original_h_file(base_name)
    return File.join($original_h_dir, "wx#{base_name}.h")
end

def optional_h_file(base_name)
    if base_name == 'Scintilla'
        return File.join(ENV['WXSCINTILLA'], "include/wx/wx#{base_name.downcase}.h")
    else
        return File.join($optional_h_dir, "wx#{base_name}.h")
    end
end

def cpp_file(base_name)
    return File.join($src_dir, "#{base_name}.cpp")
end

def obj_file(base_name)
    return File.join($obj_dir, "#{base_name}.#{$obj_ext}")
end

def normal_cpp_files
    return get_classes.map do | c | cpp_file(c) end
end

def all_cpp_files
    return all_obj_bases.map do | c | cpp_file(c) end

end



def to_obj_files(bases)
    return bases.map do | b | obj_file(b) end
end

def normal_obj_files
    return to_obj_files(get_classes)
end

def all_obj_files
    return to_obj_files(all_obj_bases)
end

def add_initializers(cpp_file)
    needs_init_list = get_classes
    needs_init_list += get_optional_classes
    needs_init_list << "Events"
    needs_init_list << "Events2"
    needs_init_list << "Functions"
    needs_init_list << "Mac"
    needs_init_list << "RubyConstants"
    needs_init_list << "RubyEventTypes"
    File.open(cpp_file, "a") do | out |
        out.puts
        out.puts('extern "C" void InitializeOtherModules()')
        out.puts("{")
        needs_init_list.each do | c |
            init = "Init_wx#{c}()"
            out.puts("    extern void #{init};")
            out.puts("    #{init};")
        end
        out.puts("}")
    end
end

def do_swig(swig_file, cpp_file, options)
	if(!$found_good_swig)
		if(!have_good_swig)
	        raise "Couldn't find required SWIG (minimum #{$swig_minimum_version})."
		end
	end
	$found_good_swig = true
	force_mkdir($src_dir)
    sh "#{$swig_cmd} #{options} #{$wx_cppflags} " + 
		"-w401 -w801 -w515 -c++ -ruby " + 
        "-o #{cpp_file} #{swig_file}"
    renamer = File.join($swig_dir, "renamer.rb")
    sh "ruby #{renamer} #{cpp_file}"
end

def post_process(cpp_file, command)
    fixer = File.join($swig_dir, command)
    sh "ruby #{fixer} #{cpp_file}"
end

def create_swig_helper_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = special_swig_file(base_name)
    
    file(cpp_file => swig_file) do |t|
        do_swig(swig_file, cpp_file, $swig_options)
        post_process(cpp_file, "fixmodule.rb")
    end
    return cpp_file
end

def create_normal_swig_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = normal_swig_file(base_name)
    h_file = original_h_file(base_name)
    
    file(cpp_file => [swig_file, h_file] + shared_swig_files) do |t|
        do_swig(swig_file, cpp_file, $swig_options)
        post_process(cpp_file, "fixplatform.rb")
        post_process(cpp_file, "fixmodule.rb")
		post_process(cpp_file, "fixdeleting.rb")
    end
end

def create_optional_swig_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = optional_swig_file(base_name)
    h_file = optional_h_file(base_name)
    
    file(cpp_file => [swig_file, h_file] + shared_swig_files) do |t|
        do_swig(swig_file, cpp_file, $swig_options)
        post_process(cpp_file, "fixplatform.rb")
        post_process(cpp_file, "fixmodule.rb")
	post_process(cpp_file, "fixdeleting.rb")
    end
end

def create_swig_event_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = special_swig_file(base_name)
    events_src = File.join %w|swig classes include events.rb|

    file( cpp_file => [ swig_file, events_src ] ) do | t |
        do_swig(swig_file, cpp_file, $swig_options)
        post_process(cpp_file, "fixmodule.rb")
        post_process(cpp_file, "fixevents.rb")
    end
    return cpp_file
end

def create_swig_main_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = special_swig_file(base_name)
    
    file(cpp_file => swig_file) do |t|
        do_swig(swig_file, cpp_file, "")
        post_process(cpp_file, "fixmainmodule.rb")
        add_initializers(cpp_file)
    end
end

def create_swig_tasks
    get_classes.each do | c |
        create_normal_swig_task(c)
    end
    get_optional_classes.each do | c |
        create_optional_swig_task(c)
    end
    create_swig_helper_task("RubyConstants")
    create_swig_helper_task("RubyStockObjects")
    create_swig_helper_task("RubyEventTypes")
    create_swig_helper_task("Functions")
    create_swig_helper_task("Mac")
    create_swig_event_task("Events")
    create_swig_main_task("wx")
    file(cpp_file("wx") => normal_cpp_files)
end

def create_compile_task(base_name)
    obj_file = obj_file(base_name)
    cpp_file = cpp_file(base_name)
    
    if ($mswin)
      out_arg = "/Fo"
    else
      out_arg = "-o "
    end
    file(obj_file => cpp_file) do |t|
        force_mkdir($obj_dir)
        sh "#{$cpp} -c #{$verbose_flag} #{$cppflags} #{out_arg}#{obj_file} #{cpp_file} "
    end
end

def create_obj_tasks
    all_obj_bases.each do | base |
        create_compile_task(base)
    end
end

def create_link_task
    file($target_lib => all_obj_files) do |t|
        objs = $extra_objs + " " + all_obj_files.join(' ')
        force_mkdir($dest_dir)
        sh "#{$ld} #{$ldflags} #{objs} #{$libs} #{$link_output_flag}#{t.name}"
    end
end

def install_lib(filename)
	if(!File.directory?($install_lib_dir))
		mkdir($install_lib_dir)
	end
	sh "#{$install_prog} lib/#{filename} #{$install_lib_dir}"
end

def create_install_task
    desc "Install the WxRuby library to Ruby's lib directories"
    task :install => [:default] do |t|
	  install_lib("wx.rb")
	  install_lib($dl_lib)
    end    
end

def create_internal_swig_tasks
	create_swig_tasks
    desc "Generate C++ source and header files using SWIG"
	task :swig => all_cpp_files
    desc "Force generate C++ source and header files using SWIG"
	task :reswig => [:clean_src, :swig]
end

def create_internal_non_swig_tasks
    create_obj_tasks
    create_link_task
	create_install_task
end
