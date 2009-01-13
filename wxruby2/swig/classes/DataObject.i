// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObject
GC_MANAGE_AS_OBJECT(wxDataObject);

%include "../shared/data_object_common.i"

//%typemap(in,numinputs=1) (wxDataFormat *formats, 
//                          wxDataObject::Direction dir = Get) (wxString *arr)
//)

%include "include/wxDataObject.h"
