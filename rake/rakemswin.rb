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
$WXVERSION = '26'

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



$WXSRC="#$WXDIR/src/msw"
$WXINC="#$WXDIR/include"
$WXLIBDIR="#$WXDIR/lib/vc_lib"
$INCTEMP="#$WXDIR/lib/vc_lib/msw#{$POSTFIX}"

$wx_libs =  "#$WXLIBDIR/wxbase26#{$POSTFIX}.lib"       
$wx_libs += " #$WXLIBDIR/wxbase26#{$POSTFIX}_net.lib"
$wx_libs += " #$WXLIBDIR/wxbase26#{$POSTFIX}_odbc.lib"
$wx_libs += " #$WXLIBDIR/wxbase26#{$POSTFIX}_xml.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_adv.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_core.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_dbgrid.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_html.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_media.lib"
$wx_libs += " #$WXLIBDIR/wxmsw26#{$POSTFIX}_xrc.lib"
$wx_libs += " #$WXLIBDIR/wxexpat#{$DEBUGPOSTFIX}.lib"
$wx_libs += " #$WXLIBDIR/wxjpeg#{$DEBUGPOSTFIX}.lib"
$wx_libs += " #$WXLIBDIR/wxpng#{$DEBUGPOSTFIX}.lib"
$wx_libs += " #$WXLIBDIR/wxregex#{$DEBUGPOSTFIX}.lib"
$wx_libs += " #$WXLIBDIR/wxtiff#{$DEBUGPOSTFIX}.lib"
$wx_libs += " #$WXLIBDIR/wxzlib#{$DEBUGPOSTFIX}.lib"   

$wx_cppflags = [
    "-I#$WXINC", "-D__WXMSW__",
    "-I#$INCTEMP", 
    ].join(' ')
$extra_cppflags = [
    "/GR",
    "/GX",
    "/EHsc",
    "-DSTRICT", 
    "-DWIN32", "-D__WIN32__", 
    "-D_WINDOWS", "/D__WINDOWS__", 
    "-DWINVER=0x0400", "/D__WIN95__", 
    ].join(' ')
if $debug_build
    $ruby_cppflags.gsub!(/-MD/," /MDd");
    $ruby_cppflags.gsub!(/-O[A-Za-z0-9-]*/, "/Od")
    $ruby_cppflags += " -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1 "
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
