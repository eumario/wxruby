// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObject
GC_MANAGE_AS_OBJECT(wxDataObject)

%include "../shared/data_format.i"
%include "../shared/data_object_common.i"

%include "include/wxDataObject.h"
