require 'mkmf'

$objs = [
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
"methods.o", "staticbitmap.o", "control.o","togglebutton.o","grid.o",
"menuitem.o", "textattr.o", "dataformat.o", 
"dropsource.o", "droptarget.o", "textdroptarget.o", "filedroptarget.o",
"filedataobject.o", "textdataobject.o", "dataobject.o", "dataobjectsimple.o",
"dynamiccast.o"
]

$use_xrc = false
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
    CONFIG['LDSHARED'].gsub!("cc","g++")
    $CFLAGS += " `wx-config --cxxflags`"
    $LDFLAGS += " `wx-config --libs` -Wl "
	$objs.delete("fontdialog.o")

elsif have_header("windows.h") and have_library("kernel32")
    $WXDIR=ENV['WXWIN']
    $WXVERSION = '24'
    $WXSRC="#$WXDIR/src/msw"
    $WXINC="#$WXDIR/include"
    $INCTEMP="#$WXDIR/lib/mswdll"
    $WXXML="#$WXDIR/contrib/include/"
    if $DEBUG
    	$DEBUGPOSTFIX='d'
    else
    	$DEBUGPOSTFIX=''
    end
    $WXLIB="#$WXDIR\\lib\\wxmsw#{$WXVERSION}#{$DEBUGPOSTFIX}.lib"
    $WXXMLLIB="#$WXDIR\\lib\\wxxrc#{$DEBUGPOSTFIX}.lib msvcrt#{$DEBUGPOSTFIX}.lib"     
    $CFLAGS += " -I#$WXINC -I#$WXXML -I#$INCTEMP #$WINFLAGS #$EXTRADLLFLAGS -DSTRICT -DWIN32 -D__WIN32__ -D_WINDOWS -DWINVER=0x0400 /D__WIN95__ /D__WXMSW__ /DWXUSINGDLL=1 /D__WINDOWS__ -D__WXMSW__  "
    if $DEBUG
	    $CFLAGS = $CFLAGS.gsub(/-MD/," /MLd");
	    $DLDFLAGS = $DLDFLAGS + " -debug "
	end
	$DLDFLAGS = $DLDFLAGS + " -nodefaultlib "
    $libs += " #$WXLIB #$WXXMLLIB"
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

File.open("Makefile","ab+") {|f|
	f.puts
	f.puts("tclean:; @$(RM) button.h caret.h checkbox.h choice.h " + 
			"colourdialog.h control.h dataformat.h " + 
			"dataobjectsimple.h dropsource.h droptarget.h " + 
			"filedataobject.h filedroptarget.h font.h frame.h " + 
			"grid.h menuitem.h textattr.h textctrl.h " + 
			"textdataobject.h textdroptarget.h " + 
			"togglebutton.h window.h xmlresource.h")
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
