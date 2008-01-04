# Common code for platforms that use wx-config (basically, everything
# not MSW)

# Helper function that runs the wx-config command line program from
# wxWidgets to determine suitable builds and build options. Passed an
# option which corresponds to one of the command-line options to
# wx-config, eg '--list' or '--libs'. See --help for that program.
def wx_config(option)
  # 
  if $release_build
    debug_mode = '--debug=no'
  elsif $debug_build
    debug_mode = '--debug=yes'
  else
    debug_mode = '' # go with default
  end

  if $static_build
    static_mode = '--static=yes'
  elsif $dynamic_build
    static_mode = '--static=no'
  else
    static_mode = ''
  end
  
  
  cfg = `wx-config #{debug_mode} #{static_mode} #{option} 2>&1`

  # Check status for errors
  unless $?.exitstatus.zero?
    if cfg =~ /Warning: No config found to match:([^\n]*)/
      raise "No suitable wxWidgets found for specified build options;\n" +
        "(#{$1.strip})"
    else
      raise "wx-config error:\n(#{cfg})"
    end
  end

  return cfg.strip + " "
end

# First, if either debug/release or static/dynamic has been left
# unspecified, find out what default build is available, and set that.
unless $dynamic_build or $static_build
  if wx_config('--list') =~ /\ADefault config is ([\w.-]+)/
    available = $1
    if available =~ /static/
      $static_build  = true
    else
      $dynamic_build = true
    end
  end
end

unless $release_build or $debug_build
  if wx_config('--list') =~ /\ADefault config is ([\w.-]+)/
    available = $1
    if available =~ /debug/
      $debug_build  = true
    else
      $release_build = true
    end
  end
end

# Now actually run the program to fill in some variables
$wx_version  = wx_config("--version")
$wx_cppflags = wx_config("--cppflags")
$wx_libs     = wx_config("--libs std,stc,gl")
$cpp         = wx_config("--cxx")
$ld          = wx_config("--ld")

# Find out where the wxWidgets setup.h file being used is located; this
# will be used later in rakeconfigure.rb
setup_inc_dir = $wx_cppflags[/^-I(\S+)/][2..-1]
WXWIDGETS_SETUP_H  = File.join(setup_inc_dir, 'wx', 'setup.h')

# Check for some optional components in wxWidgets: STC (Scintilla) and
# OpenGL; don't try and compile those classes if not present. Tests
# whether the library file exists. 

# Hold the actual --lib argument to be used for the final flags
libs_str = "--libs std"

# Test for StyledTextCtrl (Scintilla)
stc_lib = $wx_libs[/\S+libwx\S+_stc\S+/]
if stc_lib.nil? or not File.exists?(stc_lib)
  $excluded_classes += %w|StyledTextCtrl StyledTextEvent|
else
  libs_str << ',stc'
end


# Test for OpenGL
gl_lib = $wx_libs[/\S+libwx\S+_gl\S+/]
if gl_lib.nil? or not File.exists?(gl_lib)
  $excluded_classes << 'GLCanvas'
else
  libs_str << ',gl'
end  

# Set the final list of libs to be used
$wx_libs = wx_config(libs_str)



