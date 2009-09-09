# rakeconfigure: sets up variables for use in compiling and linking the
# library, including platform specific options. Also determines what
# kind of build to make, and what optional wx classes are supported and
# should be built. Steps, in order:

# 1. Look at environment variables for options
# 2. Read ruby's config for info about how it was built
# 3. Load platform-specific rakefile options
# 4. Summarise main options for user
# 5. Read wxWidgets setup.h header file for supported features
# 6. Prepare the flags to be used by the compiler and linker


# FIRST: get options passed as environment on the command line:
# Force non-unicode build with WXRUBY_NO_UNICODE.  
$release_build = ENV['WXRUBY_RELEASE'] ? true : false
$debug_build   = ENV['WXRUBY_DEBUG'] ? true : false
$verbose_debug = ENV['WXRUBY_VERBOSE'] ? true : false

$dynamic_build = ENV['WXRUBY_DYNAMIC'] ? true : false
$static_build  = ENV['WXRUBY_STATIC'] ? true : false

# Non-unicode (ANSI) build is not tested or supported, but retained in
# case anyone is using it
$unicode_build = ENV['WXRUBY_NO_UNICODE'] ? false : true

# Exclude certian classes from being built, even if they are present
# in the configuration of wxWidgets.
$excluded_classes = ENV['WXRUBY_EXCLUDED'] ? ENV['WXRUBY_EXCLUDED'].split(",") : []

# SECOND: get a series of settings from rbconfig; these may be overridden
# in the platform-specific rakefiles below
# Get ruby's info on how it was built
require "rbconfig"

$ruby_cppflags = Config::CONFIG["CFLAGS"]

# Ruby 1.9.0 changes location of some header files
if RUBY_VERSION >= "1.9.0"
  includes = [ Config::CONFIG["rubyhdrdir"],
               Config::CONFIG["sitehdrdir"],
               Config::CONFIG["vendorhdrdir"],
               File.join(Config::CONFIG["rubyhdrdir"], 
                         Config::CONFIG['arch']) ]
  $ruby_includes = " -I. -I " + includes.join(' -I ')
else
  $ruby_includes = " -I. -I " + Config::CONFIG["archdir"]
end

$ruby_ldflags = Config::CONFIG["LDFLAGS"]
$ruby_libs  = Config::CONFIG["LIBS"]
$extra_cppflags = ""
$extra_ldflags = ""
$extra_objs = ""
$extra_libs = ""
$cpp_out_flag =  "-o "
$link_output_flag = "-o "
OBJ_EXT = Config::CONFIG["OBJEXT"]

# This is now set with the detection of WXRUBY_EXCLUDED
# some classes are not implemented by WxWidgets on all platforms
# $excluded_classes = []

# THIRD: load the platform-specific rakefiles; these can extend or
# override many of the previously set options. These variables are set
# in rake/rakeutil.rb
if    $macosx then require "./rake/rakemacosx"
elsif $mswin  then require "./rake/rakemswin"
elsif $mingw  then require "./rake/rakemingw"
elsif $cygwin then require "./rake/rakecygwin"
elsif $bccwin then require "./rake/rakebccwin"
elsif $netbsd then require "./rake/rakenetbsd"
else               require "./rake/rakelinux"
end

# FOURTH: summarise the main options chosen back for the user
if $dynamic_build and $static_build
  raise "Both STATIC and RELEASE specified; request one or other"
elsif $dynamic_build
  puts "Enabling DYNAMIC build"
elsif $static_build
  puts "Enabling STATIC build"
end

if $release_build and $debug_build
  raise "Both RELEASE and DEBUG specified; request one or other"
elsif $release_build
  puts "Enabling RELEASE build"
elsif $debug_build
  puts "Enabling DEBUG build"
end

if $unicode_build
  puts "Enabling UNICODE build"
else
  puts "Enabling ANSI build; NOT RECOMMENDED"
end

if $verbose_debug
  puts "Enabling VERBOSE debugging output"
  $verbose_flag = ' -DwxDEBUG=1 '
else
  $verbose_flag = ''
end

# FIFTH: Testing the relevant wxWidgets setup.h file to see what
# features are supported. Note that the presence of OpenGL (for
# GLCanvas) and Scintilla (for StyledTextCtrl) is tested for in the
# platform-specific rakefiles.

# The wxWidgets setup.h file contains a series of definitions like
# #define wxUSE_FOO 1. The location of the file should be set
# by the platform-specific rakefile. Parse it into a ruby hash:
WX_FEATURES = {}

File.read(WXWIDGETS_SETUP_H).scan(/^#define\s+(\w+)\s+([01])/) do | define |
  WX_FEATURES[$1] = $2.to_i.zero? ? false : true
end

# MediaCtrl is not always included or easily built, esp on Linux
unless WX_FEATURES['wxUSE_MEDIACTRL']
  $excluded_classes += %w|MediaCtrl MediaEvent|
end

# GraphicsContext is not enabled by default on some platforms
unless WX_FEATURES['wxUSE_GRAPHICS_CONTEXT']
  $excluded_classes += %w|GCDC GraphicsBrush GraphicsContext GraphicsFont
                          GraphicsMatrix GraphicsObject GraphicsPath GraphicsPen|
end

if not $excluded_classes.empty?
  puts "The following wxWidgets features are not available and will be skipped:"
  puts "  " + $excluded_classes.sort.join("\n  ")  
end

# SIXTH: Putting it all together

# Flags to be passed to the C++ compiler
$cppflags = [ $wx_cppflags, $ruby_cppflags, 
              $extra_cppflags, $ruby_includes ].join(' ')

# Flags to be passed to the linker
$ldflags  = [ $ruby_ldflags, $extra_ldflags ].join(' ')

# Libraries that the linker should build
$libs     = [ $wx_libs, $ruby_libs, $extra_libs ].join(' ')

