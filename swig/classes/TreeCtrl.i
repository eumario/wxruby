// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTreeCtrl
GC_MANAGE_AS_WINDOW(wxTreeCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxTreeCtrl);

%{
#include <wx/treectrl.h>
#include <wx/dirctrl.h>
%}

// wxTreeItemId fixes - these typemaps convert them to ruby Integers
%include "../shared/treeitemid_typemaps.i"

// These only differ from SetXXXList in the way memory ownership is
// transferred. So only support the version that won't leak on wxRuby.
%ignore wxTreeCtrl::AssignImageList;
%ignore wxTreeCtrl::AssignButtonsImageList;
%ignore wxTreeCtrl::AssignStateImageList;

// Dealt with below
%ignore wxTreeCtrl::GetSelections;

// Only support the version that returns more info in flags
%ignore wxTreeCtrl::HitTest(const wxPoint& point);

// Typemap to return the flags in hit_test
%apply int *OUTPUT { int& flags }

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


// GC handling for item data objects. These are static because it avoids
// having to wrap a complete subclass
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

  // Only really useful for HIDDEN_ROOT style; manually detect the first
  // root-like item.
  static wxTreeItemId FindFirstRoot(wxTreeCtrl *tree_ctrl) {
	wxTreeItemId base_id = tree_ctrl->GetFirstVisibleItem();
	wxTreeItemId prev_id = tree_ctrl->GetItemParent(base_id);
	wxTreeItemId root_id = tree_ctrl->GetRootItem();
	while ( prev_id.IsOk() && prev_id != root_id )
	  {
		base_id = prev_id;
		prev_id = tree_ctrl->GetItemParent(base_id);
	  }
	prev_id = tree_ctrl->GetPrevSibling(base_id);
	while ( prev_id.IsOk()  )
	  {
		base_id = prev_id;
		prev_id = tree_ctrl->GetPrevSibling(base_id);
	  }
	return base_id;
  }

  // Safe version of recursion from base across all contained items that
  // works whether or not the TreeCtrl has the TR_HIDE_ROOT
  // style. Required to ensure that marking of item data is done
  // correctly for hidden-root treectrls.
  static void RecurseFromRoot(wxTreeCtrl *tree_ctrl, 
							  void(*rec_func)(void *, const wxTreeItemId&) )
	{
	  // straightforward
	  if ( ! ( tree_ctrl->GetWindowStyle() & wxTR_HIDE_ROOT ) )
		{
		  RecurseOverTreeIds(tree_ctrl, tree_ctrl->GetRootItem(), *rec_func);
		  return;
		}
	  // Find the top-left most item, then recurse over it and siblings
	  else
		{
		  wxTreeItemId base_id = FindFirstRoot(tree_ctrl);
		  // now do recursion
		  RecurseOverTreeIds(tree_ctrl, base_id, *rec_func);
		  while ( ( base_id = tree_ctrl->GetNextSibling(base_id) ) &&
				  base_id.IsOk() )
			RecurseOverTreeIds(tree_ctrl, base_id, *rec_func);
		  return;
		}
	}

  // Recursively-called function to implement of TreeCtrl#traverse
  static void DoTreeCtrlYielding(void *ptr, const wxTreeItemId& item_id)
  {
	// create a copy to wrap and give to ruby
	VALUE rb_item_id = LONG2NUM((size_t)item_id.m_pItem);
	rb_yield(rb_item_id);
  }

  // Recursively-called function to do GC marking of itemdata for every
  // tree item
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
	if ( GC_IsWindowDeleted(ptr) )
	  return;

    // Do standard marking routines as for all wxWindows
    GC_mark_wxWindow(ptr);

	wxTreeCtrl* tree_ctrl = (wxTreeCtrl*) ptr;

	wxImageList* img_list;
	// First check if there's ImageLists and mark if found
	img_list = tree_ctrl->GetImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
#if !defined(__WXMSW__)
	img_list = tree_ctrl->GetButtonsImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));
#endif
	img_list = tree_ctrl->GetStateImageList();
	if ( img_list ) rb_gc_mark(SWIG_RubyInstanceFor(img_list));

    // Stop here if it's a TreeCtrl belonging to a GenericDirCtrl, as
    // the item data aren't ruby objects
    wxWindow* parent = tree_ctrl->GetParent();
    if ( parent->IsKindOf( CLASSINFO(wxGenericDirCtrl) ) )
      return;

	// Otherwise proceed and GC mark the item data objects associated
	// with the TreeCtrl
	wxTreeItemId root_id = tree_ctrl->GetRootItem();
	RecurseFromRoot(tree_ctrl, &DoGCMarkItemData);
  }
%}
%markfunc wxTreeCtrl "mark_wxTreeCtrl";

%import "include/wxControl.h"
%import "include/wxWindow.h"
%import "include/wxEvtHandler.h"
%import "include/wxObject.h"
%include "include/wxTreeCtrl.h"

%extend wxTreeCtrl {
  // The C++ interface uses a "cookie" to enable iteration over the
  // children. This is clumsy, unrubyish and broken as of wxRuby 1.9.1
  // so just return the first child TreeItemId. Iteration should then be
  // possibel using get_next_sibling, as needed
    VALUE get_first_child(const wxTreeItemId& item)
    {
      void* cookie = 0;
      wxTreeItemId ret_item = self->GetFirstChild(item, cookie);
      return TREEID2RUBY(ret_item);
    }

  	// Change signature so it returns an array of the TreeItemId and the
	// cookie, as Ruby Fixnums. This behaviour matches that used by
	// wxPython.
	VALUE get_first_child_and_cookie(const wxTreeItemId& item)
	{
        rb_warn("TreeCtrl#get_first_child_and_cookie is deprecated");
		void* cookie = 0;
		wxTreeItemId ret_item = self->GetFirstChild(item, cookie);
		VALUE array = rb_ary_new();			

		rb_ary_push(array, TREEID2RUBY(ret_item) );
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}
	
	VALUE get_next_child(const wxTreeItemId& item, void* cookie)
	{
        rb_warn("TreeCtrl#get_next_child is deprecated");
		wxTreeItemId ret_item = self->GetNextChild(item, cookie);
		
		VALUE array = rb_ary_new();			

		rb_ary_push(array, TREEID2RUBY(ret_item) );
		rb_ary_push(array,LONG2NUM((long)cookie));
			
		return array;		
	}

	// Return an array of root items; mainly useful for TR_HIDE_ROOT
	// style where there are multiple root-like items, and GetItemRoot
	// doesn't work properly
    VALUE get_root_items()
    {
      VALUE rb_tree_ids = rb_ary_new();
	  if ( self->GetWindowStyle() & wxTR_HIDE_ROOT )	  
		{
		  wxTreeItemId base_id = FindFirstRoot(self);

		  // now do recursion
		  if ( base_id.IsOk() ) 
			{
			  rb_ary_push(rb_tree_ids, TREEID2RUBY(base_id));
			  
			  while ( ( base_id = self->GetNextSibling(base_id) ) &&
					    base_id.IsOk() )
				rb_ary_push(rb_tree_ids, TREEID2RUBY(base_id));
			}
		}
	  // Standard single-root TreeCtrl
	  else
		{
		  rb_ary_push(rb_tree_ids, 
					  TREEID2RUBY( self->GetRootItem() ));
        }
	  return rb_tree_ids;
    }

	// Just return a simple array in ruby
    VALUE get_selections()
    {
      VALUE rb_tree_ids = rb_ary_new();
      wxArrayTreeItemIds tree_ids = wxArrayTreeItemIds();
      size_t sel_count = self->GetSelections(tree_ids);
      for ( size_t i = 0; i < sel_count; i++ )
        {
          rb_ary_push(rb_tree_ids, TREEID2RUBY(tree_ids.Item(i)));
        }
      return rb_tree_ids;
    }
    
	// Changed this version of insert_item to insert_item_before so SWIG
	// does not get confused between the 2 method signatures
	// This behaviour matches that used by wxPython.
	wxTreeItemId insert_item_before(const wxTreeItemId& parent,
									size_t index,
									const wxString& text,
									int image = -1, int selectedImage = -1,
									wxTreeItemData *data = NULL) {
		return self->InsertItem(parent,index,text,image,selectedImage,data);
	}

	// Loop over the items in the TreeCtrl, starting from the item
	// identified by start_id, passing the id of each item into the
	// passed ruby block. Starts from root and covers all if no arg.
	VALUE traverse(	VALUE start_id = Qnil )
	{
	  wxTreeItemId base_id;
	  if ( start_id == Qnil )
		RecurseFromRoot(self, &DoTreeCtrlYielding);
	  else
		{
		  base_id = wxTreeItemId( (void *)NUM2LONG(start_id) );
		  if ( ! base_id.IsOk() ) 
			rb_raise(rb_eArgError, "Invalid tree identifier");
		  else
			RecurseOverTreeIds(self, base_id, &DoTreeCtrlYielding);
		}
	  return Qnil;
	}
}

