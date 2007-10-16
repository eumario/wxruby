// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/bitmap.h>
%}

%module(directors="1") wxMask
GC_MANAGE_AS_OBJECT(wxMask);

%import "include/wxObject.h"

%include "include/wxMask.h"
