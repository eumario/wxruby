#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxBitmap
%feature("nodirector") wxBitmap;

%{
//NO_DIRECTOR

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

%{
#include <wx/image.h>
%}

%include "include/wxBitmap.h"
