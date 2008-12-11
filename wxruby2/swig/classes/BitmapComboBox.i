// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxBitmapComboBox
GC_MANAGE_AS_WINDOW(wxBitmapComboBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxBitmapComboBox);

%{
#include <wx/bmpcbox.h>
%}

// start client_data fixes
%include "../shared/control_with_items.i"
CLIENT_DATA_FEATURES(wxBitmapComboBox);

// Avoids perpetual loop
%feature("nodirector") wxBitmapComboBox::GetCount;
// Deal with below
%feature("nodirector") wxBitmapComboBox::IsEmpty;
%feature("nodirector") wxBitmapComboBox::Select;
%feature("nodirector") wxBitmapComboBox::SetSelection;

%{
void mark_wxBitmapComboBox(void* ptr) {
  if ( GC_IsWindowDeleted(ptr) )
	return;

  GC_mark_wxWindow(ptr);

  wxBitmapComboBox* wx_cwi = (wxBitmapComboBox*) ptr;
  int count = wx_cwi->GetCount();
  if ( count == 0 )
	return; // Empty control
  if ( ! wx_cwi->HasClientObjectData() && ! wx_cwi->HasClientUntypedData() )
	return; // Control containing only strings
  
  for (int i = 0; i < count; ++i)
	{
	  VALUE object = (VALUE) wx_cwi->GetClientData(i);
	  if ( object && object != Qnil ) 
		rb_gc_mark(object);
	}
}
%}
%markfunc wxBitmapComboBox "mark_wxBitmapComboBox";

%extend wxBitmapComboBox {
  // Make sure the call is routed to the right class - not ComboCtrl,
  // which expects a string arg, which will crash
  VALUE set_selection(VALUE sel)
  {
    int n = NUM2INT(sel);
    $self->SetSelection(n);
    return Qnil;
  }
  // The same as above
  VALUE select(VALUE sel)
  {
    int n = NUM2INT(sel);
    $self->SetSelection(n);
    return Qnil;
  }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxControlWithItems.h"
%import "include/wxComboBox.h"

%include "include/wxBitmapComboBox.h"
