#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFont
%ignore wxFont::SetNativeFontInfo;

// import the font encoding constants directly from the WxWidgets source
%include <wx/fontenc.h>

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxFont.h"
