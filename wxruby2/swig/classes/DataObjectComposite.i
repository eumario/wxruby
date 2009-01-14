// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDataObjectComposite
GC_MANAGE_AS_OBJECT(wxDataObjectComposite);


%include "../shared/data_object_common.i"
%include "../shared/data_object_final_C.i"


// SWIG gets confused and doesn't realise that various virtual methods
// from wxDataObject are implemented fully in this subclass, and so,
// believing it to be abstract doesn't provide an allocator for this
// class. This undocumented feature overrides this.
%feature("notabstract") wxDataObjectComposite;

// Once a DataObject has been added, it belongs to the composite object,
// and will be freed by it on destruction.
%apply SWIGTYPE *DISOWN { wxDataObjectSimple* dataObject };

%import "include/wxDataObject.h"
%include "include/wxDataObjectComposite.h" 
