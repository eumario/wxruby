# rakemswin.rb
# Copyright 2004-2008 by wxRuby development team
# Released under the MIT-style wxruby2 license

# Compiling on Windows with Microsoft compiler - this is currently set
# up to support VS2005 (version 8.0 of the runtime)

# First, common Windows settings (shared with MingW)
require './rake/rakewindows'

# The name of the compiler and linker
$cpp  = "cl.exe"
$ld   = "link"
$cpp_out_flag     = "/Fo"
$link_output_flag = "/dll /out:"

# Only static build is currently allowed on Windows; TODO
if $dynamic_build 
  raise "Dynamically-linked build is not allowed on Windows, use static"
else
  $static_build = true
end

# Variants within wxWidgets directory layout are identified by these tags
$WXVERSION = '28'
$DEBUGPOSTFIX   = $debug_build ? 'd' : ''
$UNICODEPOSTFIX = $unicode_build ? 'u' : ''
$POSTFIX = $UNICODEPOSTFIX + $DEBUGPOSTFIX

# Some secondary directories in the wxWidgets layout
$WXINCDIR      = File.join("#$WXDIR", "include")
$WXLIBDIR      = File.join("#$WXDIR", "lib", "vc_lib")
$WXSETUPINCDIR = File.join("#$WXDIR", "lib", "vc_lib", "msw#{$POSTFIX}")

WXWIDGETS_SETUP_H  = File.join($WXSETUPINCDIR, 'wx', 'setup.h')


# wxWidgets libraries that should be linked into wxRuby
# odbc and db_table not required by wxruby
windows_libs = %W|wxbase#{$WXVERSION}#{$POSTFIX}
                  wxbase#{$WXVERSION}#{$POSTFIX}_net 
                  wxbase#{$WXVERSION}#{$POSTFIX}_xml
                  wxmsw#{$WXVERSION}#{$POSTFIX}_adv
                  wxmsw#{$WXVERSION}#{$POSTFIX}_core
                  wxmsw#{$WXVERSION}#{$POSTFIX}_html
                  wxmsw#{$WXVERSION}#{$POSTFIX}_media
                  wxmsw#{$WXVERSION}#{$POSTFIX}_xrc
                  wxmsw#{$WXVERSION}#{$POSTFIX}_aui
                  wxmsw#{$WXVERSION}#{$POSTFIX}_richtext
                  wxexpat#{$DEBUGPOSTFIX}
                  wxjpeg#{$DEBUGPOSTFIX}
                  wxpng#{$DEBUGPOSTFIX}
                  wxtiff#{$DEBUGPOSTFIX}
                  wxzlib#{$DEBUGPOSTFIX}
                  wxregex#{$POSTFIX}|

windows_libs.map! { | lib | File.join($WXLIBDIR, "#{lib}.lib") }

# Windows-specific routines for checking for supported features
# Test for presence of StyledTextCtrl (scintilla) library; link it in if
# present, skip that class if not 
scintilla_lib = File.join( $WXLIBDIR, 
                           "wxmsw#{$WXVERSION}#{$POSTFIX}_stc.lib" )
if File.exists?(scintilla_lib)
  windows_libs << scintilla_lib 
else
  $excluded_classes += %w|StyledTextCtrl StyledTextEvent|
end

# Test for presence of OpenGL library; link it in if
# present, skip that class if not 
gl_lib = File.join( $WXLIBDIR, "wxmsw#{$WXVERSION}#{$POSTFIX}_gl.lib" )
if File.exists?(gl_lib)
  windows_libs << gl_lib 
else
  $excluded_classes += %w|GLCanvas GLContext|
end

# Glue them all together into an argument passed to the linker
$wx_libs = windows_libs.join(' ')

$wx_cppflags = "-I#{$WXINCDIR} -D__WXMSW__ -I#{$WXSETUPINCDIR}"
$extra_cppflags = %W[ /GR /EHsc -DSTRICT -DWIN32 -D__WIN32__ -DWINVER=0x0400
                      -D_WINDOWS /D__WINDOWS__  /D__WIN95__].join(' ')

if $debug_build
  $ruby_cppflags.gsub!(/-MD/," /MDd");
  $ruby_cppflags.gsub!(/-O[A-Za-z0-9-]*/, "/Od")
  $ruby_cppflags += " -Zi -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1 "
  $extra_ldflags += "/DEBUG"
else
  $ruby_cppflags += " -DNDEBUG "
end

if $unicode_build
  $wx_cppflags += " -D_UNICODE -DUNICODE"
end

# Extra files for the linker - WINDOWS_SYS_LIBS are common in rakewindows.rb
lib_ruby =   File.join(Config::CONFIG['libdir'], Config::CONFIG['LIBRUBY'])
$extra_libs = WINDOWS_SYS_LIBS.map { | lib | "#{lib}.lib" }.join(" ")
$extra_libs << " #{lib_ruby}"


    
$extra_objs = "swig/wx.res"

rule('.res' => '.rc') do | t |
    sh("rc -I#$WXINC #{t.prerequisites}")
end

def find_in_path(basename)
  ENV['PATH'].split(';').each do | path |
    maybe = File.join(path, basename)
    return maybe if File.exists?(maybe)
  end
  raise "Cannot find #{basename} in PATH"
end

# Redistribute and install VC8 runtime - not recommended
directory 'temp'
file 'temp' do
  cp 'lib/wxruby2.so.manifest', 'temp'
  cp find_in_path('msvcp80.dll'), 'temp'
  cp find_in_path('msvcr80.dll'), 'temp'
  File.open('temp/Rakefile', 'w') do | f |
    f.puts <<TEMP_RAKEFILE
# This is a temporary rakefile to install the Microsoft v8 runtime
require 'rbconfig'
task :default do
  mv 'msvcp80.dll', Config::CONFIG['bindir']
  mv 'msvcr80.dll', Config::CONFIG['bindir']
  ruby_manifest = File.join(Config::CONFIG['bindir'], 'ruby.exe.manifest')
  if File.exists? ruby_manifest 
    mv ruby_manifest, ruby_manifest + ".old"
  end
  cp 'wxruby2.so.manifest', ruby_manifest
  rubyw_manifest = File.join(Config::CONFIG['bindir'], 'rubyw.exe.manifest')
  if File.exists? rubyw_manifest 
    mv rubyw_manifest, rubyw_manifest + ".old"
  end
  cp 'wxruby2.so.manifest', rubyw_manifest
end
TEMP_RAKEFILE
  end
end
