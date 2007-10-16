// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBitmap
GC_MANAGE_AS_OBJECT(wxBitmap);

%{
#include <wx/bitmap.h>
%}

%ignore   AddHandler(wxBitmapHandler*  handler ) ;
%ignore   CleanUpHandlers() ;
%ignore   FindHandler(const wxString&  name ) ;
%ignore   FindHandler(const wxString&  extension , long  bitmapType ) ;
%ignore   FindHandler(long  bitmapType ) ;
%ignore   GetHandlers() ;
%ignore   InitStandardHandlers() ;
%ignore   InsertHandler(wxBitmapHandler*  handler ) ;
%ignore   RemoveHandler(const wxString&  name ) ;

%ignore  Create(void*  data , int  type , int  width , int  height , int depth = -1) ;
%ignore wxBitmap::SetPalette;

%apply SWIGTYPE *DISOWN { wxMask* mask };

%{
#include <wx/image.h>
%}

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxBitmap.h"
