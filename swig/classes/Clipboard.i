// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxClipboard
GC_NEVER(wxClipboard);

%{
#include <wx/clipbrd.h>
%}

// After a data object has been set to the clipboard using set_data, it
// becomes owned by the clipboard and shouldn't be freed
%apply SWIGTYPE *DISOWN {wxDataObject* data};

%include "../shared/data_object_common.i"

%include "include/wxClipboard.h"

