// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTextDataObject
GC_MANAGE_AS_OBJECT(wxTextDataObject);

%{
#include <wx/dataobj.h>
%}

%include "../shared/data_format_typemap.i"

%include "../shared/data_object_final_class.i"
%import "include/wxDataObjectSimple.h"
%import "include/wxDataObject.h"


%include "include/wxTextDataObject.h"
