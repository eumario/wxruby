#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxBitmap

%ignore   wxBitmap() ;
%ignore   wxBitmap(const wxBitmap&  bitmap ) ;
%ignore   wxBitmap(void*  data , int  type , int  width , int  height , int depth = -1) ;
%ignore   wxBitmap(const char  bits[] , int  width , int  height , int depth = 1) ;
%ignore   wxBitmap(int  width , int  height , int depth = -1) ;
%ignore   wxBitmap(const char**  bits ) ;
%ignore   wxBitmap(const wxImage&  img , int depth = -1) ;

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
