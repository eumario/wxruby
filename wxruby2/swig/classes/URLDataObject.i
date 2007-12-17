// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxURLDataObject
GC_MANAGE_AS_OBJECT(wxURLDataObject);

%{
#include <wx/dataobj.h>
%}

%include "../shared/data_format_typemap.i"
%include "../shared/data_object_final_class.i"

%import "include/wxDataObject.h"

// inheritance tree varies across platforms
#ifdef __WXMSW__
%import "include/wxDataObjectComposite.h"
#else
%import "include/wxDataObjectSimple.h"
%import "include/wxTextDataObject.h"
#endif

%include "include/wxURLDataObject.h"
