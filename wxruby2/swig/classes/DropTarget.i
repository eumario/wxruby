// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDropTarget
GC_MANAGE_AS_OBJECT(wxDropTarget);

%{
#include <wx/dnd.h>
%}

// wxWidgets will free the DataObject once it's owned by DropTarget
%apply SWIGTYPE *DISOWN { wxDataObject* data };

// Protect the associated DataObject as it's a director and so the ruby
// object must persist
%{
  void mark_wxDropTarget(void* ptr) {
    if ( GC_IsWindowDeleted(ptr) ) return;
    
    wxDropSource* drop_tgt = (wxDropSource*)ptr;
    wxDataObject* data_obj = drop_tgt->GetDataObject();
    if ( data_obj )
      rb_gc_mark( SWIG_RubyInstanceFor(data_obj) );
  }
%}

%markfunc wxDropTarget "mark_wxDropTarget";

%include "include/wxDropTarget.h"
