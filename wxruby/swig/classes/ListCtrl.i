// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListCtrl
GC_MANAGE_AS_WINDOW(wxListCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxListCtrl);

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
#include <wx/imaglist.h>
%}

// Ruby handles memory management - always use SetImageList
%ignore wxListCtrl::AssignImageList;

// Doesn't work on wxMac
%ignore wxListCtrl::GetEditControl;

// deprecated:
%ignore wxListCtrl::GetItemSpacing(bool isSmall) const;

// dealt with below
%ignore wxListCtrl::GetItem(wxListItem& info) const;
%ignore wxListCtrl::GetItemData;
%ignore wxListCtrl::SetItemData;

// dealt with specially below
%ignore wxListCtrl::SortItems;

// Not described in the docs as being Windows-only, but doesn't seem to
// appear in GTK wx headers, so causes a compile error
#if !defined(__WXMSW__)
%ignore wxListCtrl::GetSubItemRect;
#endif

// required for GetItemRect and GetSubItemRect
%typemap(in, numinputs=0) (wxRect &rect) {
  $1 = new wxRect();
}
%typemap(argout) ( wxRect &rect ) {
  $result = SWIG_NewPointerObj($1, SWIGTYPE_p_wxRect, 1);
}

// required for hit_test, return flags as second part of array return value
%apply int *OUTPUT { int& flags }

// Helper code for SortItems - yields the two items being compared into
// the associated block, and get an integer return value
%{
  int wxCALLBACK wxListCtrl_SortByYielding(long item1, long item2, long data)
  {
    VALUE items = rb_ary_new();
    rb_ary_push(items, (VALUE)item1);
    rb_ary_push(items, (VALUE)item2);
    VALUE the_order = rb_yield(items);
    return NUM2INT(the_order);
  }
%}



%extend wxListCtrl {
  VALUE get_item(int row, int col = -1)
  {
	VALUE returnVal = Qnil;
	wxListItem *list_item = new wxListItem();
	list_item->SetId(row);
	if ( col != -1 )
	  list_item->SetColumn(col);
	// We don't know what fields the ruby user might wish to access, so
	// we fetch them all
	list_item->SetMask(wxLIST_MASK_DATA|wxLIST_MASK_FORMAT|wxLIST_MASK_IMAGE|wxLIST_MASK_STATE|wxLIST_MASK_TEXT|wxLIST_MASK_WIDTH);

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
  
  void sort_items()
  {
    self->SortItems(wxListCtrl_SortByYielding, 0);
  }
}

%markfunc wxListCtrl "mark_wxListCtrl";
%{
  // Prevents Ruby's GC sweeping up items that are stored as item data
  static void mark_wxListCtrl(void* ptr) {
	if ( GC_IsWindowDeleted(ptr) )
	  return;

    // Do standard marking routines as for all wxWindows
    GC_mark_wxWindow(ptr);

	wxListCtrl* wx_lc = (wxListCtrl*) ptr;

	// First check if there's ImageLists and mark if found
	wxImageList* img_list;
	img_list= wx_lc->GetImageList(wxIMAGE_LIST_NORMAL);
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
	img_list= wx_lc->GetImageList(wxIMAGE_LIST_SMALL);
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
	img_list= wx_lc->GetImageList(wxIMAGE_LIST_STATE);
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));

	// Don't try to mark item data for VIRTUAL listctrls
	if ( wx_lc->GetWindowStyle() & wxLC_VIRTUAL )
	  return;

	int count = wx_lc->GetItemCount();
	if ( count == 0 ) return;

	for (int i = 0; i < count; ++i)
	  {
		VALUE object = (VALUE) wx_lc->GetItemData(i);
		if ( object && object != Qnil ) 
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
