#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxImage

%{
#include <wx/image.h>
%}

%apply char * { unsigned char * }
%apply char { unsigned char }

%ignore wxImage::Create();
%ignore wxImage::AddHandler(const wxString&  filename );

%import "include/wxObject.h"

%include "include/wxImage.h"
