# rakewx.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

# This file is required by the main wxRuby rakefile.
# Basically, the messy parts are here, to keep the 
# main rakefile easier to understand

$swig_dir = 'swig'
$src_dir = 'src'
$obj_dir = 'obj'
$dest_dir = 'lib'
$classes_dir = File.join($swig_dir, 'classes')
$original_h_dir = File.join($classes_dir, 'include')

$swig_cmd = "swig"

def wx_config(opt)
    shell = Config::CONFIG["SHELL"]
    return `#{shell} wx-config #{opt}`.strip + " "
end

def use_wx_config
    $wx_cppflags = wx_config("--cppflags")
    $wx_ldflags = wx_config("--ldflags")
    $wx_libs = wx_config("--libs")
    $cpp = wx_config("--cxx")
    $ld = wx_config("--ld")
end

def get_classes
    classes = []
    Dir::foreach($classes_dir) do | filename |
        filespec = File.join($classes_dir, filename)
        #puts("#{filename}: #{File.directory?(filespec)})
        if(filename[0,1] != '.' && !File.directory?(filespec))
            classes << File.basename(filename, '.i')
        end
    end
    #puts classes
    return classes.sort
end

def all_obj_bases
    return get_classes + 
        ["wx", "RubyConstants", "RubyStockObjects", 
            "RubyEventTypes", "Functions"]
end

def special_swig_file(base_name)
    return File.join($swig_dir, "#{base_name}.i")
end

def normal_swig_file(base_name)
    return File.join($classes_dir, "#{base_name}.i")
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

def cpp_file(base_name)
    return File.join($src_dir, "#{base_name}.cpp")
end

def obj_file(base_name)
    return File.join($obj_dir, "#{base_name}.#{$obj_ext}")
end

def normal_cpp_files
    return get_classes.map do | c | cpp_file(c) end
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

def create_extract_task
    xml_file = File.join($swig_dir, "wxclasses-2.4.2.xml")
    extractor = File.join($swig_dir, "extractxml.rb")
    get_classes.each do | c |
        file(original_h_file(c) => [xml_file, extractor]) do
            sh "ruby #{extractor} #{xml_file}"
        end
    end
end

def add_initializers(cpp_file)
    needs_init_list = get_classes
    needs_init_list << "RubyConstants"
    needs_init_list << "Functions"
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
    sh "#{$swig_cmd} #{options} -w401 -w801 -w515 -c++ -ruby " + 
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
        do_swig(swig_file, cpp_file, "-noruntime -noextern")
        post_process(cpp_file, "fixmodule.rb")
    end
    return cpp_file
end

def create_normal_swig_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = normal_swig_file(base_name)
    h_file = original_h_file(base_name)
    
    file(cpp_file => [swig_file, h_file] + shared_swig_files) do |t|
        do_swig(swig_file, cpp_file, "-noruntime -noextern")
        post_process(cpp_file, "fixmodule.rb")
        fixdeleting = File.join($swig_dir, "fixdeleting.rb")
        sh "ruby #{fixdeleting} #{cpp_file}"
    end
end

def create_swig_main_task(base_name)
    cpp_file = cpp_file(base_name)
    swig_file = special_swig_file(base_name)
    
    file(cpp_file => swig_file) do |t|
        do_swig(swig_file, cpp_file, "-runtime")
        post_process(cpp_file, "fixmainmodule.rb")
        add_initializers(cpp_file)
    end
end

def create_swig_tasks
    get_classes.each do | c |
        create_normal_swig_task(c)
    end
    create_swig_helper_task("RubyConstants")
    create_swig_helper_task("RubyStockObjects")
    create_swig_helper_task("RubyEventTypes")
    create_swig_helper_task("Functions")
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
		sh "#{$cpp} -c #{$cppflags} #{out_arg}#{obj_file} #{cpp_file} "
    end
end

def create_obj_tasks
    all_obj_bases.each do | base |
        create_compile_task(base)
    end
end

def create_link_task
    if ($mswin)
      out_arg = "/dll /out:"
    else
      out_arg = "-o "
    end
    file($target_lib => all_obj_files) do |t|
        objs = $extra_objs + " " + all_obj_files.join(' ')
        force_mkdir($dest_dir)
        sh "#{$ld} #{$ldflags} #{objs} #{$libs} #{out_arg}#{t.name}"
    end
end

def create_internal_swig_tasks
    create_extract_task
    create_swig_tasks
end

def create_internal_non_swig_tasks
    create_obj_tasks
    create_link_task
end
