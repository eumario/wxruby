# rakewindows.rb
# Copyright 2004-2008 wxRuby development team

# Common settings for compiling on Microsoft Windows with either g++
# (MingW) or Microsoft Visual C++

# Because on Windows wx-config is not available, the path to the
# compiled wxWidgets library has to be specified using an environment
# variable 
$WXDIR = ENV['WXWIN']
if not $WXDIR or $WXDIR.empty?
  raise "Location of wxWidgets library must be specified " +
        "with WXWIN environment variable"
end


# wxRuby must be linked against these system libraries; these are turned
# into linker flags in the relevant compiler rakefile
WINDOWS_SYS_LIBS = %w| gdi32 gdiplus winspool comdlg32
                       shell32 ole32 oleaut32 uuid
                       odbc32 odbccp32 comctl32 
                       rpcrt4 winmm |

