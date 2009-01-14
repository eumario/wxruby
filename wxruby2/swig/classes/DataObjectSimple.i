// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObjectSimple
GC_MANAGE_AS_OBJECT(wxDataObjectSimple);

%include "../shared/data_format.i"
%include "../shared/data_object_common.i"

// SWIG gets confused and doesn't realise that various virtual methods
// from wxDataObject are implemented fully in this subclass, and so,
// believing it to be abstract doesn't provide an allocator for this
// class. This undocumented feature overrides this.
%feature("notabstract") wxDataObjectSimple;

//  Only support the fuller style method signatures inherited from
//  DataObject, not the shortened ones for ~Simple.
%feature("nodirector") wxDataObjectSimple::GetDataHere(void *buf) const;
%ignore wxDataObjectSimple::GetDataHere(void *buf) const;
%feature("nodirector") wxDataObjectSimple::SetData(size_t len, const void *buf);
%ignore wxDataObjectSimple::SetData(size_t len, const void *buf);

// These are implemented in DataObjectSimple and cannot be overridden
%feature("nodirector") wxDataObjectSimple::GetFormatCount;
%feature("nodirector") wxDataObjectSimple::GetPreferredFormat;
%feature("nodirector") wxDataObjectSimple::GetAllFormats;

%import "include/wxDataObject.h"
%include "include/wxDataObjectSimple.h" 
