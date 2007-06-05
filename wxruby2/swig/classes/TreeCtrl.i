// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxTreeCtrl
GC_MANAGE_AS_WINDOW(wxTreeCtrl);

%{
#include <wx/treectrl.h>
%}

// wxTreeItemId fixes - these typemaps convert them to ruby Integers
%include "../shared/treeitemid_typemaps.i"

%ignore wxTreeCtrl::AssignImageList;
%ignore wxTreeCtrl::AssignButtonsImageList;
%ignore wxTreeCtrl::AssignStateImageList;

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

  // Called on every tree item to do GC marking of itemdata
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
	if ( rb_iv_get(rb_obj, "@__wx_destroyed__" ) == Qtrue )
	  return;

	wxTreeCtrl* tree_ctrl = (wxTreeCtrl*) ptr;

	wxImageList* img_list;
	// First check if there's ImageLists and mark if found
	img_list = tree_ctrl->GetImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
	img_list = tree_ctrl->GetButtonsImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
	img_list = tree_ctrl->GetStateImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));

	// Now mark the item data
	wxTreeItemId root_id = tree_ctrl->GetRootItem();
	RecurseOverTreeIds(tree_ctrl, root_id, &DoGCMarkItemData);
  }
%}
%markfunc wxTreeCtrl "mark_wxTreeCtrl";

%import "include/wxControl.h"
%import "include/wxWindow.h"
%import "include/wxEvtHandler.h"
%import "include/wxObject.h"
%include "include/wxTreeCtrl.h"

%extend wxTreeCtrl {
	//Change signature so it returns an array of the TreeItemId and the Cookie.
	//This behavior matches that used by wxPython and wxPerl.
	VALUE get_first_child(const wxTreeItemId& item)
	{
		void* cookie = 0;
		wxTreeItemId ret_item = self->GetFirstChild(item, cookie);
		VALUE array = rb_ary_new();			

		rb_ary_push(array,LONG2NUM((long)ret_item.m_pItem)); 
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}
	
	VALUE get_next_child(const wxTreeItemId& item, void* cookie)
	{
		wxTreeItemId ret_item = self->GetNextChild(item, cookie);
		
		VALUE array = rb_ary_new();			

		rb_ary_push(array,LONG2NUM((long)ret_item.m_pItem));	
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}
	
	//Changed this version of insert_item to insert_item_before so SWIG
	//does not get confused between the 2 method signatures
	//This behavior matches that used by wxPython.
	wxTreeItemId insert_item_before(const wxTreeItemId& parent,
                          size_t index,
                          const wxString& text,
                          int image = -1, int selectedImage = -1,
                          wxTreeItemData *data = NULL)
	{
		return self->InsertItem(parent,index,text,image,selectedImage,data);
	}
}

