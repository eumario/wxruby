#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeCtrl

%{
#include <wx/treectrl.h>
%}

 // ITEM DATA fixes - This is done so the API user never sees a
// TreeItemData object - where in Wx C++ such an object
// would be passed or returned by a method, any Ruby object may be used.
%{
class wxRbTreeItemData : public wxTreeItemData {
public:
    wxRbTreeItemData(VALUE obj = Qnil) { m_obj = obj; }
    VALUE GetRubyObject() { return m_obj; }
    void SetRubyObject(VALUE obj) { m_obj = obj; }
protected:
    VALUE m_obj;
};
%}


// typemaps for setting and getting ruby objects as itemdata.
%typemap(in) wxTreeItemData* "$1 = new wxRbTreeItemData($input);"

%typemap(directorin) wxTreeItemData* {
  wxRbTreeItemData* ruby_item_data = (wxRbTreeItemData *)$1;
  $input = ruby_item_data->GetRubyObject();
}

%typemap(out) wxTreeItemData* {
  if ( $1 == NULL )
	{
	  $result = Qnil;
	}
  else
  	{
	  wxRbTreeItemData* ruby_item_data = (wxRbTreeItemData *)$1;
	  $result = ruby_item_data->GetRubyObject();
	}
}
// End item data fixes


// GC handling for item data objects
%{
  // general recursion over a treectrl, starting from a base_id
  // the function rec_func will be called in turn for each tree item, 
  // rec_func should be a funtion that receives a treectrl pointer and an ItemId
  static void RecurseOverTreeIds(wxTreeCtrl *tree_ctrl, const wxTreeItemId& base_id, void(*rec_func)(void *, const wxTreeItemId&) )
  {
	rec_func(tree_ctrl, base_id);
	// recurse through children
	if ( tree_ctrl->ItemHasChildren(base_id) )
	  {
		wxTreeItemIdValue cookie;
		wxTreeItemId child = tree_ctrl->GetFirstChild(base_id, cookie);
		while ( child.IsOk() )
		  {
			RecurseOverTreeIds(tree_ctrl, child, *rec_func);
			child = tree_ctrl->GetNextChild(base_id, cookie);
		  }
	  }
  }

  static void DoGCMarkItemData(void *ptr, const wxTreeItemId& item_id)
  {
	wxTreeCtrl* tree_ctrl = (wxTreeCtrl*) ptr;
	// check if there's item data, and mark it
	wxRbTreeItemData* ruby_item_data = (wxRbTreeItemData *)tree_ctrl->GetItemData(item_id);
	if ( ruby_item_data != NULL )
	  {
		VALUE ruby_obj = ruby_item_data->GetRubyObject();
		rb_gc_mark(ruby_obj);
	  }
  }

  // SWIG's entry point function for GC mark
  static void mark_wxTreeCtrl(void *ptr)
  {
	VALUE rb_obj = SWIG_RubyInstanceFor(ptr);
	if ( rb_ivar_get(rb_obj, rb_intern("@__swig_dead__") ) == Qtrue )
	  return;

	wxTreeCtrl* tree_ctrl = (wxTreeCtrl*) ptr;
	wxTreeItemId root_id = tree_ctrl->GetRootItem();
	RecurseOverTreeIds(tree_ctrl, root_id, &DoGCMarkItemData);
  }

  // function for internal implementation of TreeCtrl#traverse 
  static void DoTreeCtrlYielding(void *ptr, const wxTreeItemId& item_id)
  {
	// create a copy to wrap and give to ruby
	wxTreeItemId *copy_id = new wxTreeItemId(item_id.m_pItem);
	VALUE rb_item_id = SWIG_NewPointerObj(copy_id, SWIGTYPE_p_wxTreeItemId, SWIG_POINTER_OWN);
	rb_yield(rb_item_id);
  }
%}
%markfunc wxTreeCtrl "mark_wxTreeCtrl";

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

#if defined(__WXMSW__)
%import "include/wxControl.h"
#else
%import "include/wxScrolledWindow.h"
#endif

%include "include/wxTreeCtrl.h"


%extend wxTreeCtrl {

  VALUE traverse(const wxTreeItemId& item_id = wxTreeItemId() )
  {
	wxTreeItemId base_id;

	if ( item_id.IsOk() ) 
	  {
		base_id = item_id;
	  }
	else
	  {
		base_id = self->GetRootItem();
	  }

	RecurseOverTreeIds(self, base_id, &DoTreeCtrlYielding);
	return Qnil;
  }

	//Change signature so it returns an array of the TreeItemId and the Cookie.
	//This behavior matches that used by wxPython and wxPerl.
	VALUE get_first_child(const wxTreeItemId& item)
	{
		void* cookie = 0;
		wxTreeItemId ret_item = self->GetFirstChild(item, cookie);
		
		VALUE array = rb_ary_new();			
		VALUE ret_item_ruby = SWIG_NewPointerObj((new wxTreeItemId(static_cast< const wxTreeItemId& >(ret_item))), SWIGTYPE_p_wxTreeItemId, SWIG_POINTER_OWN |  0 );									
		rb_ary_push(array,ret_item_ruby);	
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}
	
	VALUE get_next_child(const wxTreeItemId& item, void* cookie)
	{
		wxTreeItemId ret_item = self->GetNextChild(item, cookie);
		
		VALUE array = rb_ary_new();			
		VALUE ret_item_ruby = SWIG_NewPointerObj((new wxTreeItemId(static_cast< const wxTreeItemId& >(ret_item))), SWIGTYPE_p_wxTreeItemId, SWIG_POINTER_OWN |  0 );									
		rb_ary_push(array,ret_item_ruby);	
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}
}

