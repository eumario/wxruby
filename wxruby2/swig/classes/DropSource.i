// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDropSource
GC_MANAGE_AS_OBJECT(wxDropSource);

%{
#include <wx/dnd.h>
%}

%constant int const DRAG_COPY_ONLY    = wxDrag_CopyOnly;
%constant int const DRAG_ALLOW_MOVE   = wxDrag_AllowMove;
%constant int const DRAG_DEFAULT_MOVE = wxDrag_DefaultMove;

%constant int const DRAG_COPY   = wxDragCopy;
%constant int const DRAG_MOVE   = wxDragMove;
%constant int const DRAG_LINK   = wxDragLink;
%constant int const DRAG_CANCEL = wxDragCancel;
%constant int const DRAG_NONE   = wxDragNone;


// wxWidgets will free the DataObject once it's owned by DropSource
%apply SWIGTYPE *DISOWN { wxDataObject* data };

// Protect the associated DataObject as it's a director and so the ruby
// object must persist
%{
  void mark_wxDropSource(void* ptr) {
    if ( GC_IsWindowDeleted(ptr) ) return;
    
    wxDropSource* drop_src = (wxDropSource*)ptr;
    wxDataObject* data_obj = drop_src->GetDataObject();
    if ( data_obj )
      rb_gc_mark( SWIG_RubyInstanceFor(data_obj) );
  }
%}

%markfunc wxDropSource "mark_wxDropSource";


%include "include/wxDropSource.h"
