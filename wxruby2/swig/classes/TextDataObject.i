// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTextDataObject
GC_MANAGE_AS_OBJECT(wxTextDataObject);

%{
#include <wx/dataobj.h>
%}

%ignore GetAllFormats;
%feature("nodirector") GetAllFormats;

%ignore GetDataSize;
%feature("nodirector") GetDataSize;

%ignore GetDataHere;
%feature("nodirector") GetDataHere;

%ignore GetDataHere;
%feature("nodirector") GetDataHere;

%ignore GetFormatCount;
%feature("nodirector") GetFormatCount;

%ignore GetPreferredFormat;
%feature("nodirector") GetPreferredFormat;

%ignore SetData;
%feature("nodirector") SetData;

%include "../shared/data_object.i"

%import "include/wxDataObjectSimple.h"
%import "include/wxDataObject.h"


%include "include/wxTextDataObject.h"
