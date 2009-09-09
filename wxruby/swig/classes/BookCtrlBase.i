// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

// NB - we'd expect this to be a Director, but this causes a compile
// error on MingW; it doesn't matter as this class is never instantiated
// anyway
%module(directors="1") wxBookCtrlBase
GC_MANAGE_AS_WINDOW(wxBookCtrlBase);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxBookCtrlBase);

%{
#include <wx/bookctrl.h>
%}

%include "../shared/bookctrls.i"

%ignore wxBookCtrlBase();
%ignore wxBookCtrlBase(wxWindow *parent,
					   wxWindowID winid,
					   const wxPoint& pos,
					   const wxSize& size,
					   long style,
					   const wxString& name);

// wxBookCtrl hit results
enum
{
    wxBK_HITTEST_NOWHERE = 1,   // not on tab
    wxBK_HITTEST_ONICON  = 2,   // on icon
    wxBK_HITTEST_ONLABEL = 4,   // on label
    wxBK_HITTEST_ONITEM  = wxBK_HITTEST_ONICON | wxBK_HITTEST_ONLABEL,
    wxBK_HITTEST_ONPAGE  = 8    // not on tab control, but over the selected page
};

// common BookCtrl flags
#define wxBK_DEFAULT          0x0000
#define wxBK_TOP              0x0010
#define wxBK_BOTTOM           0x0020
#define wxBK_LEFT             0x0040
#define wxBK_RIGHT            0x0080
#define wxBK_ALIGN_MASK       (wxBK_TOP | wxBK_BOTTOM | wxBK_LEFT | wxBK_RIGHT)


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxBookCtrlBase.h"
