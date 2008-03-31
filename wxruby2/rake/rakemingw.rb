# rakemingw.rb
# Copyright 2004-2008 wxRuby development team

# This file provides settings for compiling with gcc on Windows (MingW)

# First, common Windows settings
require 'rake/rakewindows'

# 
$cpp = "g++"
$ld  = "g++ -shared" # not ld directly

# Some secondary directories in the wxWidgets layout
$WXINCDIR      = File.join("#$WXDIR", "include")
$WXLIBDIR      = File.join("#$WXDIR", "lib")
$WXSETUPINCDIR = File.join("#$WXDIR", "lib", "wx", "include", 
                            "msw-unicode-release-static-2.8")


WXWIDGETS_SETUP_H  = File.join($WXSETUPINCDIR, 'wx', 'setup.h')

$wx_cppflags = "-I#{$WXINCDIR} -D__WXMSW__ -I#{$WXSETUPINCDIR}"

if $unicode_build
  $wx_cppflags += " -D_UNICODE -DUNICODE"
end

# Variants within wxWidgets directory layout are identified by these tags
$WXVERSION = '2.8'
$DEBUGPOSTFIX   = $debug_build ? 'd' : ''
$UNICODEPOSTFIX = $unicode_build ? 'u' : ''
$POSTFIX = $UNICODEPOSTFIX + $DEBUGPOSTFIX

# wxWidgets libraries that should be linked into wxRuby
# odbc and db_table not required by wxruby
windows_libs = %W|wx_msw#{$POSTFIX}-#{$WXVERSION}
                  wxexpat#{$DEBUGPOSTFIX}-#{$WXVERSION}
                  wxjpeg#{$DEBUGPOSTFIX}-#{$WXVERSION}
                  wxpng#{$DEBUGPOSTFIX}-#{$WXVERSION}
                  wxtiff#{$DEBUGPOSTFIX}-#{$WXVERSION}
                  wxzlib#{$DEBUGPOSTFIX}-#{$WXVERSION}
                  wxregex#{$POSTFIX}-#{$WXVERSION}|

windows_libs.map! { | lib | File.join($WXLIBDIR, "lib#{lib}.a") }

# Windows-specific routines for checking for supported features
# Test for presence of StyledTextCtrl (scintilla) library; link it in if
# present, skip that class if not 
scintilla_lib = File.join( $WXLIBDIR, 
                           "libwx_msw#{$POSTFIX}_stc-#{$WXVERSION}.a" )
if File.exists?(scintilla_lib)
  windows_libs << scintilla_lib 
else
  $excluded_classes += %w|StyledTextCtrl StyledTextEvent|
end

# Test for presence of OpenGL library; link it in if present, skip that
# class if not
gl_lib = File.join( $WXLIBDIR, "libwx_wxmsw#{$POSTFIX}_gl-#{$WXVERSION}.a" )
if File.exists?(gl_lib)
  windows_libs << gl_lib 
else
  $excluded_classes << "GLCanvas"
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

# not currently included with mingw
libs.delete('-lgdiplus')

$extra_libs = "#{libs.join(' ')} " +
  File.join(Config::CONFIG['libdir'], Config::CONFIG['LIBRUBY'])
