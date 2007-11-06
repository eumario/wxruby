// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObjectSimple
GC_MANAGE_AS_OBJECT(wxDataObjectSimple);

%include "../shared/data_format_typemap.i"

%ignore SetData(size_t len, const void *buf);
%feature("nodirector") SetData;
%ignore GetDataSize();
%feature("nodirector") GetDataSize;

%import "include/wxDataObject.h"

%include "include/wxDataObjectSimple.h"

