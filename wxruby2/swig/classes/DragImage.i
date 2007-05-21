// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxDragImage
GC_MANAGE_AS_OBJECT(wxDragImage);

%{
#include <wx/dragimag.h>
%}
%ignore wxDragImage::wxDragImage(const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0, 0) );
%import "include/wxObject.h"

%include "include/wxDragImage.h"
