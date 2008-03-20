// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBitmap
GC_MANAGE_AS_OBJECT(wxBitmap);

%{
#include <wx/bitmap.h>
#include <wx/image.h>
%}

// Handler functions are not needed in wxRuby - all standard handlers
// are loaded at startup, and we don't allow custom image handlers to be
// written in Ruby. Should someone want to add these methods, it will
// also require fixing freearg typemap for wxString to free correctly in
// static methods
%ignore AddHandler(wxBitmapHandler*  handler);
%ignore CleanUpHandlers();
%ignore FindHandler(const wxString& name );
%ignore FindHandler(const wxString& extension, long bitmapType);
%ignore FindHandler(long bitmapType);
%ignore GetHandlers();
%ignore InitStandardHandlers();
%ignore InsertHandler(wxBitmapHandler* handler);
%ignore RemoveHandler(const wxString& name ) ;

// FIXME - wrapping to create image from raw data
%ignore Create(void* data, int type, int width, int height, int depth = -1);

// wxPalette not supported in wxRuby
%ignore wxBitmap::SetPalette;

%apply SWIGTYPE *DISOWN { wxMask* mask };

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxBitmap.h"
