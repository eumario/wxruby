// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRadioBox
GC_MANAGE_AS_WINDOW(wxRadioBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxRadioBox);
%{
#include <wx/wx.h>
#include <wx/radiobox.h>
%}

%ignore wxRadioBox::Number; // Obsolete

%ignore wxRadioBox::Show(int item, const bool show = true);


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
