#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/imaglist.h>
%}

%module(directors="1") wxImageList

#ifdef __WXMAC__
%ignore wxImageList::Replace(int, const wxBitmap&, const wxBitmap&);
#endif
   
%rename(AddIcon) wxImageList::Add(const wxIcon&  icon ) ;

%include "include/wxImageList.h"
