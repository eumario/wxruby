// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxFont
GC_MANAGE_AS_OBJECT(wxFont);
%ignore wxFont::SetNativeFontInfo;

// import the font encoding constants directly from the WxWidgets source
%include <wx/fontenc.h>

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxFont.h"
