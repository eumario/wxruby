// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxClipboard
GC_NEVER(wxClipboard);

%{
#include <wx/clipbrd.h>
%}

// Constructor should not be called directly from Ruby
%ignore wxClipboard();

%include "../shared/data_format.i"
%include "../shared/data_object_common.i"

// After a data object has been set to the clipboard using set_data, it
// becomes owned by the clipboard and shouldn't be freed
%apply SWIGTYPE *DISOWN { wxDataObject* data };

%extend wxClipboard {
  // Provide access to the global clipboard; same clipboard must be used
  // between calls to do data transfer properly.
  static VALUE get_global_clipboard() 
  {
    return SWIG_NewPointerObj(wxTheClipboard, SWIGTYPE_p_wxClipboard, 0);
  }
};

%include "include/wxClipboard.h"

