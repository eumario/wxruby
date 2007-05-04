#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxColour

// flags for wxColour -> wxString conversion (see wxColour::GetAsString)
#define wxC2S_NAME              1   // return colour name, when possible
#define wxC2S_CSS_SYNTAX        2   // return colour in rgb(r,g,b) syntax
#define wxC2S_HTML_SYNTAX       4   // return colour in #rrggbb syntax

%import "include/wxObject.h"

%include "include/wxColour.h"
