// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/imaglist.h>
%}

%module(directors="1") wxImageList
GC_MANAGE_AS_OBJECT(wxImageList);

%ignore wxImageList::Replace(int, const wxBitmap&, const wxBitmap&);

%rename(AddIcon) wxImageList::Add(const wxIcon&  icon ) ;

%import "include/wxObject.h"

%include "include/wxImageList.h"
