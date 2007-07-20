# rakemswin.rb
#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license


#############################
# platform-dependent settings
require 'rbconfig'

include Config

$cpp = "cl.exe"
$ld = "link"
$link_output_flag = "/dll /out:"

# native Windows - requires a static build of wxWindows
$WXDIR=ENV['WXWIN']
$WXVERSION = '28'

if $debug_build
    $DEBUGPOSTFIX='d'
else
    $DEBUGPOSTFIX=''
end

if $unicode_build
    $UNICODEPOSTFIX='u'
else
    $UNICODEPOSTFIX=''
end

$POSTFIX = $UNICODEPOSTFIX + $DEBUGPOSTFIX


$WXSRC=File.join("#$WXDIR","src","msw")
$WXINC=File.join("#$WXDIR","include")
$WXLIBDIR=File.join("#$WXDIR","lib","vc_lib")
$INCTEMP=File.join("#$WXDIR","lib","vc_lib","msw#{$POSTFIX}")

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
                  wxexpat#{$DEBUGPOSTFIX}
                  wxjpeg#{$DEBUGPOSTFIX}
                  wxpng#{$DEBUGPOSTFIX}
                  wxtiff#{$DEBUGPOSTFIX}
                  wxzlib#{$DEBUGPOSTFIX}
                  wxregex#{$POSTFIX}|

windows_libs.map! { | lib | File.join($WXLIBDIR, "#{lib}.lib") }
$wx_libs = windows_libs.join(' ')

$wx_cppflags = [
    "-I#$WXINC", "-D__WXMSW__",
    "-I#$INCTEMP", 
    ].join(' ')
$extra_cppflags = [
    "/GR",
    "/EHsc",
    "-DSTRICT", 
    "-DWIN32", "-D__WIN32__", 
    "-D_WINDOWS", "/D__WINDOWS__", 
    "-DWINVER=0x0400", "/D__WIN95__", 
    ].join(' ')
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

$extra_libs = [
    "gdi32.lib", "winspool.lib", "comdlg32.lib",
    "shell32.lib", "ole32.lib", "oleaut32.lib", "uuid.lib",
    "odbc32.lib ", "odbccp32.lib", "comctl32.lib", 
    "rpcrt4.lib", "winmm.lib","#{Config::TOPDIR}/lib/#{CONFIG['RUBY_SO_NAME']}.lib"].join(' ')
    
$extra_objs = "swig/wx.res"



rule('.res' => '.rc') do | t |
    sh("rc -I#$WXINC #{t.prerequisites}")
end

WXSCINTILLA = ENV['WXSCINTILLA']
if WXSCINTILLA
  $wx_libs += " #{WXSCINTILLA}/lib/wxscintilla#{$POSTFIX}.lib"
  $wx_cppflags += " -I#{WXSCINTILLA}/include -DWXSCINTILLA"
end
