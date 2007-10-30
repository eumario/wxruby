# Common code for platforms that use wx-config (basically, everything
# not MSW)

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


$wx_version = wx_config("--version")
$wx_cppflags = wx_config("--cppflags")
$wx_libs = wx_config("--libs std,stc,gl")
$cpp = wx_config("--cxx")
$ld = wx_config("--ld")
  
# Check for some optional components in wxWidgets: STC (Scintilla) and
# OpenGL; don't try and compile those classes if not present

libs_str = "--libs std"
stc_lib = $wx_libs[/\S+libwx\S+_stc\S+/]
gl_lib = $wx_libs[/\S+libwx\S+_gl\S+/]

# StyledTextCtrl (Scintilla)
if stc_lib.nil? or not File.exists?(stc_lib)
  $excluded_classes << 'StyledTextCtrl'
else
  libs_str << ',stc'
end

# OpenGL
if gl_lib.nil? or not File.exists?(gl_lib)
  $excluded_classes << 'GLCanvas'
else
  libs_str << ',gl'
end  

$wx_libs = wx_config(libs_str)



