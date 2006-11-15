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

%ignore wxListCtrl::GetItem(wxListItem& info) const;

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
}



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListCtrl.h"
