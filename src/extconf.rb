require 'mkmf'

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
    $CFLAGS += " `wx-config --cxxflags`"
    $LDFLAGS += " `wx-config --libs` -Wl,--version-script,./version-script "
elsif /mingw32/ =~ RUBY_PLATFORM

	CONFIG["CC"] = eval("`sh wx-config --cxx`") 
	CONFIG["LDSHARED"].gsub!("gcc",eval("`sh wx-config --cxx`").strip)
	$CFLAGS += eval(" `sh wx-config --cxxflags`").strip
	$LDFLAGS += eval(" `sh wx-config --libs`").strip
	$LIBS += " -lwxmsw241"
elsif /powerpc-darwin/ =~ RUBY_PLATFORM

    CONFIG['CC'] = "g++"
    if (!$DEBUG)
      CONFIG['CFLAGS'].gsub!("-g","")
    else
      CONFIG['CFLAGS'].gsub!("-Os","-O0")
    end
    CONFIG['LDSHARED'].gsub!("cc","g++")
    if (!$DEBUG)
      CONFIG['CFLAGS'].gsub!("-g","")
    else
      CONFIG['CFLAGS'].gsub!("-Os","-O0")
    end

    $CFLAGS += " `wx-config --cxxflags` -I.. "
    $CPPFLAGS += ' -x objective-c++ '
    $LDFLAGS += " `wx-config --libs` -framework Carbon "
    if ($use_xrc)
      $LDFLAGS += " -lwx_mac_xrc-2.4 "
    end

elsif have_library("kernel32")
    # native Windows - requires a static build of wxWindows
    $DEBUG = true
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
    $CFLAGS += " -I#$WXINC -I#$INCTEMP #$WINFLAGS -DSTRICT -DWIN32 -D__WIN32__"
    $CFLAGS += " -D_WINDOWS -DWINVER=0x0400 /D__WIN95__ /D__WXMSW__ /D__WINDOWS__ -D__WXMSW__ /EHsc /GR -I.."
    $libs += " gdi32.lib winspool.lib comdlg32.lib shell32.lib ole32.lib oleaut32.lib"
    $libs += " uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib winmm.lib"
    if $DEBUG
	$CFLAGS = $CFLAGS.gsub(/-MD/," /MDd");
	$CFLAGS += " -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1"
	$libs += " #$WXLIBDIR/pngd.lib #$WXLIBDIR/zlibd.lib #$WXLIBDIR/jpegd.lib"
	$libs += " #$WXLIBDIR/tiffd.lib #$WXLIB"
    else
	$CFLAGS += " -DNDEBUG"
	$libs += " #$WXLIBDIR/png.lib #$WXLIBDIR/zlib.lib #$WXLIBDIR/jpeg.lib"
	$libs += " #$WXLIBDIR/tiff.lib #$WXLIB"
    end
    #$objs.push("wx.res")

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
