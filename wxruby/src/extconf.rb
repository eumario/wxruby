require 'mkmf'

$objs = [
"htmlprocessor.o", "htmlwindow.o", "htmleasyprinting.o",
"wx.o","app.o","bitmap.o","button.o","calendar.o","checkbox.o",
"choice.o","colour.o","colourdata.o","colourdialog.o","combobox.o","const.o",
"date.o","dialog.o","dirdialog.o","event.o","evthandler.o","filedialog.o",
"font.o","fontdata.o","fontdialog.o","frame.o","gauge.o","layout.o",
"listbox.o","menu.o","menubar.o","messagedialog.o","point.o","radio.o",
"rect.o","size.o","sizer.o","slider.o","spin.o","statictext.o","textctrl.o",
"timer.o","validator.o","window.o","icon.o","artprovider.o","log.o",
"listctrl.o","list.o","panel.o","scrolledwindow.o","dc.o","brush.o","pen.o",
"caret.o","statusbar.o","ownerdrawn.o","config.o","region.o","cursor.o",
"notebook.o","tooltip.o","mask.o","socket.o","url.o","stream.o","toolbar.o",
"image.o","palette.o","treectrl.o","classinfo.o","splitterwindow.o",
"methods.o","staticbitmap.o","control.o","grid.o",
"menuitem.o","textattr.o","dataformat.o","togglebutton.o",
"dropsource.o","droptarget.o","textdroptarget.o","filedroptarget.o",
"filedataobject.o","textdataobject.o","dataobject.o","dataobjectsimple.o",
"dynamiccast.o", "mdiparentframe.o", "mdiclientwindow.o", "mdichildframe.o",
"scrollbar.o"
]

$use_xrc = true
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
    ["htmlprocessor.o", "htmlwindow.o", "htmleasyprinting.o"].each do |str|
        $objs.delete(str)
    end

elsif /mingw32/ =~ RUBY_PLATFORM

	CONFIG["CC"] = eval("`sh wx-config --cxx`")
	CONFIG["LDSHARED"].gsub!("gcc",eval("`sh wx-config --cxx`").strip)
	$CFLAGS += eval(" `sh wx-config --cxxflags`").strip
	$LDFLAGS += eval(" `sh wx-config --libs`").strip
	$LIBS += " -lwxmsw241"
elsif /powerpc-darwin/ =~ RUBY_PLATFORM

    CONFIG['CC'] = "g++"
    CONFIG['LDSHARED'].gsub!("cc","g++")
    if (!$DEBUG)
      CONFIG['CFLAGS'].gsub!("-g","")
    else
      CONFIG['CFLAGS'].gsub!("-Os","-O0")
    end

    $CFLAGS += " `wx-config --cxxflags` "
    $CPPFLAGS += ' -x objective-c++ '
    $LDFLAGS += " `wx-config --libs` -framework Carbon "
 	$objs.push("macstart.o")
    if ($use_xrc)
        $LDFLAGS += " -lwx_mac_xrc-2.4 "
    end
elsif have_library("kernel32")
    # native Windows - requires a static build of wxWindows
    $DEBUG = false
    $WXDIR=ENV['WXWIN']
    $WXVERSION = '24'
    if $DEBUG
	$DEBUGPOSTFIX='d'
    else
	$DEBUGPOSTFIX=''
    end
    $WXSRC="#$WXDIR/src/msw"
    $WXINC="#$WXDIR/include"
    $WXINC2="#$WXDIR/contrib/include"
    $WXLIBDIR="#$WXDIR/lib"
    $INCTEMP="#$WXDIR/lib/msw#{$DEBUGPOSTFIX}"
    $WXLIB="#$WXLIBDIR/wxmsw#{$DEBUGPOSTFIX}.lib"
    $CFLAGS += " -I#$WXINC -I#$WXINC2 -I#$INCTEMP #$WINFLAGS -DSTRICT -DWIN32 -D__WIN32__"
    $CFLAGS += " -D_WINDOWS -DWINVER=0x0400 /D__WIN95__ /D__WXMSW__ /D__WINDOWS__ -D__WXMSW__"
    $libs += " gdi32.lib winspool.lib comdlg32.lib shell32.lib ole32.lib oleaut32.lib"
    $libs += " uuid.lib odbc32.lib odbccp32.lib comctl32.lib rpcrt4.lib winmm.lib"
    if $DEBUG
	$CFLAGS = $CFLAGS.gsub(/-MD/," /MDd");
	$CFLAGS += " -D_DEBUG -D__WXDEBUG__ -DWXDEBUG=1"
	$libs += " #$WXLIBDIR/pngd.lib #$WXLIBDIR/zlibd.lib #$WXLIBDIR/jpegd.lib"
	$libs += " #$WXLIBDIR/tiffd.lib #$WXLIB"
	if ($use_xrc == true)
	    $libs += " #$WXLIBDIR/wxxrcd.lib"
	end
    else
	$CFLAGS += " -DNDEBUG"
	$libs += " #$WXLIBDIR/png.lib #$WXLIBDIR/zlib.lib #$WXLIBDIR/jpeg.lib"
	$libs += " #$WXLIBDIR/tiff.lib #$WXLIB"
	if ($use_xrc == true)
	    $libs += " #$WXLIBDIR/wxxrc.lib"
	end
    end
    $objs.push("wx.res")

end

SRC_EXT << "t"

create_makefile("wxruby")

File.open("Makefile","ab+") {|f|
	f.puts
    f.puts(".t.cpp:")
	f.puts("\truby wxpp.rb $<")
	f.puts
    f.puts(".t.h:")
	f.puts("\truby wxpp.rb $<")
	}

if $WXDIR
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
