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
    wxRbTreeItemData(VALUE obj = Qnil) {
        m_obj = obj;
    }

    VALUE GetRubyObject() {
	    return m_obj;
    }

    void SetRubyObject(VALUE obj) {
	    m_obj = obj;
    }

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

// GC handling for item data objects
%{
  static void RecursivelyGCMarkFrom(wxTreeCtrl *tree_ctrl, wxTreeItemId base_id )
  {
	
	// check if there's item data, and mark it
	wxRbTreeItemData* ruby_item_data = (wxRbTreeItemData *)tree_ctrl->GetItemData(base_id);
	if ( ruby_item_data != NULL )
	  {
		VALUE ruby_obj = ruby_item_data->GetRubyObject();
		rb_gc_mark(ruby_obj);
	  }

	// recurse through children
	if ( tree_ctrl->ItemHasChildren(base_id) )
	  {
		wxTreeItemIdValue cookie;
		wxTreeItemId child = tree_ctrl->GetFirstChild(base_id, cookie);
		while ( child.IsOk() )
		  {
			RecursivelyGCMarkFrom(tree_ctrl, child);
			child = tree_ctrl->GetNextSibling(child);
		  }
	  }
  }

  static void mark_wxTreeCtrl(void *ptr)
  {
	VALUE rb_obj = SWIG_RubyInstanceFor(ptr);
	if ( rb_ivar_get(rb_obj, rb_intern("@__swig_dead__") ) == Qtrue )
	  return;

	wxTreeCtrl* tree_ctrl = (wxTreeCtrl*) ptr;
	wxTreeItemId root_id = tree_ctrl->GetRootItem();
	RecursivelyGCMarkFrom(tree_ctrl, root_id);
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

