// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxListItem
GC_MANAGE_AS_OBJECT(wxListItem);

%{
#include <wx/listctrl.h>
%}

// These need to be dealt with below,
%ignore wxListItem::GetData() const;
// Only allow the void* version
%ignore wxListItem::SetData(long data);

// get_data needs to explicitly convert the return value to VALUE, not long
%extend wxListItem {
  VALUE get_data() {
	VALUE rb_obj;
	long data = self->GetData();
	if ( data )
	  { rb_obj = (VALUE)data; }
	else
	  { rb_obj = Qnil; }
	return rb_obj;
  }
}


%import "include/wxObject.h"

%include "include/wxListItem.h"
