puts("WARNING! wxruby2 extconf.rb is deprecated! Use rake instead.")

require 'mkmf'

$DEBUG_BUILD=false

use_xrc = false
dir_config("xrc");

#
# I'd like to use have_library, but I couldn't get it to work.
#
if ($use_xrc == true)
    $objs += ["xmlresource.o"]
end


if /linux/ =~ RUBY_PLATFORM  or /i386-freebsd/ =~ RUBY_PLATFORM
    CONFIG['CC'] = `wx-config --cxx`
    CONFIG['LDSHARED'].gsub!("gcc",`wx-config --cxx`.strip)
    $CFLAGS += " -I.. `wx-config --cxxflags`"
    $LDFLAGS += " `wx-config --libs` -Wl,--version-script,./version-script "
elsif /mingw32/ =~ RUBY_PLATFORM

	CONFIG["CC"] = eval("`sh wx-config --cxx`") 
	CONFIG["LDSHARED"].gsub!("gcc",eval("`sh wx-config --cxx`").strip)
	$CFLAGS += eval(" `sh wx-config --cxxflags`").strip
	$LDFLAGS += eval(" `sh wx-config --libs`").strip
	$LIBS += " -lwxmsw241"
elsif /powerpc-darwin/ =~ RUBY_PLATFORM

    CONFIG['CC'] = "g++"
    if (!$DEBUG_BUILD)
      $CFLAGS.gsub!("-g","")
    else
      $CFLAGS = $CFLAGS.gsub(/-O[0-9]/,"-O0") + " -DwxDEBUG_BUILD "
    end
    CONFIG['LDSHARED'].gsub!("cc","g++")

    $CFLAGS += " `wx-config --cxxflags` -I.. "
    $CPPFLAGS += ' -x objective-c++ '
    #
    # We can't include -framework Cocoa because ruby doesn't perform
    # any cocoa initialization beforehand. 
    #   http://www.cocoabuilder.com/archive/message/cocoa/2004/1/22/99284
    # Thankfully, we don't *need* cocoa, but wx-config thinks we do. So
    # change it's mind.
    #
    libs = `wx-config --libs`.chomp.gsub(/-framework Cocoa/,"").gsub(/-framework WebKit/,"")
    $LIBS += " #{libs} -lobjc "

# have_library("kernel32") does not work on XP Pro (don't know about other Windows systems)
#elsif have_library("kernel32")
else
    # native Windows - requires a static build of wxWindows
    $WXDIR=ENV['WXWIN']
    $WXVERSION = '26'
    if $DEBUG_BUILD
	    $DEBUG_BUILDPOSTFIX='d'
    else
	    $DEBUG_BUILDPOSTFIX=''
    end
    $WXSRC="#$WXDIR/src/msw"
    $WXINC="#$WXDIR/include"

    $INCTEMP="#$WXDIR/lib/vc_lib/msw#{$DEBUG_BUILDPOSTFIX}"

    $CFLAGS += " -I#$WXINC -I#$INCTEMP #$WXCONTRIBINC #$WINFLAGS -DSTRICT -DWIN32 -D__WIN32__"
    $CFLAGS += " -D_WINDOWS -DWINVER=0x0400 /D__WIN95__ /D__WXMSW__ /D__WINDOWS__ -D__WXMSW__ /EHsc /GR -I.."
    $libs += " gdi32.lib winspool.lib comdlg32.lib shell32.lib ole32.lib oleaut32.lib"
    $libs += " uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib winmm.lib"
    
    $WXLIBDIR="#$WXDIR/lib/vc_lib"
    $WXLIB =  "#$WXLIBDIR/wxbase26#{$DEBUG_BUILDPOSTFIX}.lib"       
    $WXLIB += " #$WXLIBDIR/wxbase26#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxbase26#{$DEBUG_BUILDPOSTFIX}_net.lib"
    $WXLIB += " #$WXLIBDIR/wxbase26#{$DEBUG_BUILDPOSTFIX}_odbc.lib"
    $WXLIB += " #$WXLIBDIR/wxbase26#{$DEBUG_BUILDPOSTFIX}_xml.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_adv.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_core.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_dbgrid.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_html.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_media.lib"
    $WXLIB += " #$WXLIBDIR/wxmsw26#{$DEBUG_BUILDPOSTFIX}_xrc.lib"
    $WXLIB += " #$WXLIBDIR/wxexpat#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxjpeg#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxexpat#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxpng#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxregex#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxtiff#{$DEBUG_BUILDPOSTFIX}.lib"
    $WXLIB += " #$WXLIBDIR/wxzlib#{$DEBUG_BUILDPOSTFIX}.lib"      
    if $DEBUG_BUILD
	    $CFLAGS.gsub!('/MD','/MDd')
	    $CFLAGS += " -D_DEBUG_BUILD -D__WXDEBUG_BUILD__ -DWXDEBUG_BUILD=1"
    else
      $CFLAGS += " -DNDEBUG_BUILD"
    end
    $libs += " #$WXLIB"

end

create_makefile("wx")

if $WXDIR != nil
    File.open("Makefile","ab+") {|f|
        f.print "
wx.res : wx.rc
\trc -I#$WXINC wx.rc
"
    }
end


#### Automatically build tclean target based on existing .t files
template_files = Dir['*.t'].sort
h_files_built_from_templates = template_files.map do |fn| 
    fn.sub('.t','.h')
end
File.open("Makefile","ab+"){|f|
  f.puts
  f.puts("tclean:; @$(RM) "+(h_files_built_from_templates.join(' ')))
  f.puts
}




=begin
# I'm keeping this around to remember how it worked, but it causes 
# compile errors under MSW, and doesn't quite work properly on any
# system. kbs.
	f.puts
	f.puts("SRC := $(wildcard *.cpp)")
	f.puts
	f.puts("depends:")
	f.puts("\t$(CXX) $(CXXFLAGS) $(CPPFLAGS) -MM -MG $(SRC) >depend")
=end

puts("WARNING! wxruby2 extconf.rb is deprecated! Use rake instead.")
