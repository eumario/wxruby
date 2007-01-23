#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
%}

%module(directors="1") wxListCtrl

%ignore wxListCtrl::wxListCtrl();
//
// Doesn't work on wxMac
//
%ignore wxListCtrl::GetEditControl;

# deprecated:
%ignore wxListCtrl::GetItemSpacing(bool isSmall) const;

// dealt with below
%ignore wxListCtrl::GetItem(wxListItem& info) const;
%ignore wxListCtrl::GetItemData;
%ignore wxListCtrl::SetItemData;

%extend wxListCtrl {
  VALUE get_item(int row, int col = -1)
  {
	VALUE returnVal = Qnil;
	wxListItem *list_item = new wxListItem();
	list_item->SetId(row);
	if ( col != -1 )
	  list_item->SetColumn(col);
	
	bool success = self->GetItem(*list_item);
	if ( success ) 
	  returnVal = SWIG_NewPointerObj(list_item, SWIGTYPE_p_wxListItem, 1);

	return returnVal;
  }

  VALUE get_item_data(int row)
  {
	if ( row < 0 || row >= self->GetItemCount() ) return Qnil;
	long item_data = self->GetItemData(row);
	if ( item_data == 0 ) return Qnil;
	return (VALUE)item_data;
  }

  VALUE set_item_data(int row, VALUE ruby_obj)
  {
	if ( row < 0 || row >= self->GetItemCount() ) 
	  {
		rb_raise(rb_eIndexError, "Uninitialized item");
	  }
	long item_data = (long) ruby_obj;
	bool result = self->SetItemData(row, item_data);
	if ( result )
	  return Qtrue;
	return Qnil;
  }	
}

%markfunc wxListCtrl "mark_wxListCtrl";
%{
  // Prevents Ruby's GC sweeping up items that are stored as item data
  static void mark_wxListCtrl(void* ptr) {
  // Checks whether the C++ object is still around first...
	VALUE rb_obj = SWIG_RubyInstanceFor(ptr);
	if ( rb_ivar_get(rb_obj, rb_intern("@__swig_dead__") ) == Qtrue )
	  return;

	wxListCtrl* wx_lc = (wxListCtrl*) ptr;
	if ( wx_lc->GetWindowStyle() & wxLC_VIRTUAL )
	  return;

	int count = wx_lc->GetItemCount();
	if ( count == 0 ) return;

	for (int i = 0; i < count; ++i)
	  {
		VALUE object = (VALUE) wx_lc->GetItemData(i);
		if ( object != NULL && object != Qnil ) 
		  {
			rb_gc_mark(object);
		  }
	  }
  }
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListCtrl.h"
