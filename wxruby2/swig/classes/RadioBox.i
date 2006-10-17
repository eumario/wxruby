#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxRadioBox
%{
#include <wx/wx.h>
#include <wx/radiobox.h>
%}

%ignore wxRadioBox::wxRadioBox();
%ignore wxRadioBox::Number;   # Obsolete

%ignore wxRadioBox::Show(int item, const bool show = true);

GC_NEVER(wxRadioBox);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxRadioBox.h"
%extend wxRadioBox {
	bool ShowItem(int item, const bool show = true)
	{
		return self->Show(item, show);
	}
}
