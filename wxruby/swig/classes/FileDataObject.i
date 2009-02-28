// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFileDataObject
GC_MANAGE_AS_OBJECT(wxFileDataObject);


%include "../shared/data_object_common.i"
%include "../shared/data_object_final_class.i"

%import "include/wxDataObjectSimple.h"
%import "include/wxDataObject.h"

%include "include/wxFileDataObject.h"
