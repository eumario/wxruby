# rakemswin.rb
#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project


#############################
# platform-dependent settings
require 'rbconfig'

include Config

$cpp = "cl.exe"
$ld = "link"

$DEBUG = true

# native Windows - requires a static build of wxWindows
$WXDIR=ENV['WXWIN']
$WXVERSION = '24'
if $DEBUG
    $DEBUGPOSTFIX='d'
else
    $DEBUGPOSTFIX=''
end

$WXSRC="#$WXDIR/src/msw"
$WXINC="#$WXDIR/include"
$WXLIBDIR="#$WXDIR/lib"
$INCTEMP="#$WXDIR/lib/msw#{$DEBUGPOSTFIX}"
$WXLIB="#$WXLIBDIR/wxmsw#{$DEBUGPOSTFIX}.lib"

$wx_cppflags = [
    "-I#$WXINC", "/D__WXMSW__", "-D__WXMSW__",
    "-I#$INCTEMP", 
    ].join(' ')
$extra_cppflags = [
    "/GR",
    "/GX",
    "-DSTRICT", 
    "-DWIN32", "-D__WIN32__", 
    "-D_WINDOWS", "/D__WINDOWS__", 
    "-DWINVER=0x0400", "/D__WIN95__", 
    ].join(' ')
if $DEBUG
    $ruby_cppflags.gsub!(/-MD/," /MDd");
    $ruby_cppflags.gsub!(/-O[A-Za-z0-9-]*/, "/Od")
    $extra_cppflags += " -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1 "
else
    $extra_cppflags += " -DNDEBUG "
end

if $DEBUG 
	$wx_ldflags = " /DEBUG /PDB:#$WXLIBDIR/../Debug/vc60.pdb "
else
	$wx_ldflags = ""
end

$wx_libs = [
    "#$WXLIBDIR/png#{$DEBUGPOSTFIX}.lib",
    "#$WXLIBDIR/zlib#{$DEBUGPOSTFIX}.lib",
    "#$WXLIBDIR/jpeg#{$DEBUGPOSTFIX}.lib",
    "#$WXLIBDIR/tiff#{$DEBUGPOSTFIX}.lib",
    $WXLIB,].join(' ')
$extra_libs = [
    "gdi32.lib", "winspool.lib", "comdlg32.lib",
    "shell32.lib", "ole32.lib", "oleaut32.lib", "uuid.lib",
    "odbc32.lib ", "odbccp32.lib", "comctl32.lib", 
    "rpcrt4.lib", "winmm.lib","#{Config::TOPDIR}/lib/msvcrt-ruby18.lib"].join(' ')
$extra_objs = "swig/wx.res"



rule('.res' => '.rc') do | t |
    sh("rc -I#$WXINC #{t.prerequisites}")
end
