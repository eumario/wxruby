#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
%}

%module(directors="1") wxListCtrl

%ignore wxListCtrl::wxListCtrl();

#ifdef __WXMAC__
%ignore wxListCtrl::GetEditControl;
#endif

%include "include/wxListCtrl.h"

//
// There is no record of this class in the XML file
//
class wxListItemAttr : public wxObject
{
public:
	wxListItemAttr(wxColour &, wxColour &, wxFont &);
	wxColour GetBackgroundColour();
	wxFont GetFont();
	wxColour GetTextColour();
	bool HasBackgroundColour();
	bool HasFont();
	bool HasTextColour();
	void SetBackgroundColour(wxColour &c);
	void SetFont(wxFont &);
	void SetTextColour(wxColour &);
};

