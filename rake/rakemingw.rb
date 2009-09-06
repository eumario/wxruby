# rakemingw.rb
# Copyright 2004-2008 wxRuby development team

# This file provides settings for compiling with gcc on Windows (MingW)

# First, common Windows settings
require './rake/rakewindows'

# The version by which the wxWidgets library files are identified
WXVERSION = '2.8'

$cpp = "g++"
$ld  = "g++ -shared" # not ld directly

# Where the directory containing setup.h with the wxWidgets compile
# options can be found; name depends on whether unicode and whether
# debug or release. For now, only support unicode.
if $debug_build
  setup_dir = "msw-unicode-debug-static-#{WXVERSION}"
else
  setup_dir = "msw-unicode-release-static-#{WXVERSION}"
end
# Some secondary directories in the wxWidgets layout
$WXINCDIR      = File.join("#$WXDIR", "include")

# Test for Windows-style builds (configured and built in root directory
# of unpacked wxWidgets distribution) ...
if File.exists?(File.join($WXDIR,'lib','wx','include', 
                           setup_dir, 'wx','setup.h'))
  $WXLIBDIR      = File.join($WXDIR, "lib")
  $WXSETUPINCDIR = File.join($WXDIR, "lib", "wx", "include", setup_dir)
# ... or Linux-style builds in a build subdirectory
elsif File.exists?(File.join($WXDIR,'build','lib','wx','include',
                              setup_dir, 'wx','setup.h'))
  $WXLIBDIR      = File.join($WXDIR,"build","lib")
  $WXSETUPINCDIR = File.join($WXDIR,"build","lib","wx","include", setup_dir)
else
  raise RuntimeError, 
        "Couldn't find compiled wxWidgets library in #{$WXDIR}"
end

# Define the location of setup.h that we'll be using
WXWIDGETS_SETUP_H  = File.join($WXSETUPINCDIR, 'wx', 'setup.h')

# Flags to be passed to the compiler
$wx_cppflags = "-I#{$WXINCDIR} -D__WXMSW__ -I#{$WXSETUPINCDIR}"

if $unicode_build
  $wx_cppflags += " -D_UNICODE -DUNICODE"
end

if $debug_build
  $wx_cppflags += " -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1 "
end


# Variants within wxWidgets directory layout are identified by these tags
$DEBUGPOSTFIX   = $debug_build ? 'd' : ''
$UNICODEPOSTFIX = $unicode_build ? 'u' : ''
$POSTFIX = $UNICODEPOSTFIX + $DEBUGPOSTFIX

# wxWidgets libraries that should be linked into wxRuby
# odbc and db_table not required by wxruby
windows_libs = %W|wx_msw#{$POSTFIX}-#{WXVERSION}
                  wxexpat#{$DEBUGPOSTFIX}-#{WXVERSION}
                  wxjpeg#{$DEBUGPOSTFIX}-#{WXVERSION}
                  wxpng#{$DEBUGPOSTFIX}-#{WXVERSION}
                  wxtiff#{$DEBUGPOSTFIX}-#{WXVERSION}
                  wxzlib#{$DEBUGPOSTFIX}-#{WXVERSION}
                  wxregex#{$POSTFIX}-#{WXVERSION}|

windows_libs.map! { | lib | File.join($WXLIBDIR, "lib#{lib}.a") }

# Windows-specific routines for checking for supported features
# Test for presence of StyledTextCtrl (scintilla) library; link it in if
# present, skip that class if not 
scintilla_lib = File.join( $WXLIBDIR, 
                           "libwx_msw#{$POSTFIX}_stc-#{WXVERSION}.a" )
if File.exists?(scintilla_lib)
  windows_libs << scintilla_lib 
else
  $excluded_classes += %w|StyledTextCtrl StyledTextEvent|
end

# Test for presence of OpenGL library; link it in if present, skip that
# class if not
gl_lib = File.join( $WXLIBDIR, 
                    "libwx_msw#{$POSTFIX}_gl-#{WXVERSION}.a" )
if File.exists?(gl_lib)
  windows_libs << gl_lib 
  WINDOWS_SYS_LIBS << 'opengl32'
else
  $excluded_classes += %w|GLCanvas GLContext|
end

# If either of the above classes are in use, we need to add the contrib
# include directory so the compiler can find the relevant headers
if File.exists?(scintilla_lib) or File.exists?(gl_lib) 
  wx_contrib_inc_dir = File.join($WXDIR, 'contrib', 'include')
  $wx_cppflags += " -I#{wx_contrib_inc_dir}"
end

# Collect all the Wx libs that will be included in to the final library in
# a an argument to be passed to the linker
$wx_libs = windows_libs.join(' ')

libs = WINDOWS_SYS_LIBS.map! { | lib | "-l#{lib}" }

# Delete use of -lgdiplus if wxUSE_GRAPHICS_CONTEXT is not set to 1.
File.read(WXWIDGETS_SETUP_H).scan(/^#define\s+wxUSE_GRAPHICS_CONTEXT\s+([01])/) do |define|
  if $1.to_i.zero?
    # not currently included with mingw
    libs.delete('-lgdiplus')
  end
end

$extra_libs = "#{libs.join(' ')} " +
  File.join(Config::CONFIG['libdir'], Config::CONFIG['LIBRUBY'])
