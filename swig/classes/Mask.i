// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/bitmap.h>
%}

%module(directors="1") wxMask
GC_MANAGE_AS_OBJECT(wxMask);

%import "include/wxObject.h"

%include "include/wxMask.h"
