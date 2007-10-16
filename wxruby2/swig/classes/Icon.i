// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxIcon
GC_MANAGE_AS_OBJECT(wxIcon);

// redundant since only varies by const-ness
%ignore wxIcon(char **data);
%ignore wxIcon( char **bits, int width=-1, int height=-1 );

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

// inheritance pattern is slightly different across platforms
// GTK: Icon < Bitmap < GDIOBject 
// OS X: Icon < GDIObject
// Windows: Icon < GDIImage < GDIObject (no public class GDIImage)
#if defined(__WXGTK__)
%import "include/wxBitmap.h"
#endif

// #if defined(__WXMSW__)
// %import "include/wxGDIImage.h"
// #endif

%include "include/wxIcon.h"
