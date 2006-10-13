#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxDragImage

%{
#include <wx/dragimag.h>
%}
%ignore wxDragImage::wxDragImage(const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0, 0) );
%import "include/wxObject.h"

%include "include/wxDragImage.h"
