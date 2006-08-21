#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeCtrl

%{
#include <wx/treectrl.h>
%}

// not sure why these aren't working
#%ignore wxTreeCtrl::SetStateImageList;


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
