// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSashWindow
GC_MANAGE_AS_WINDOW(wxSashWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxSashWindow);

%{
#include <wx/sashwin.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxSashWindow.h"

#define wxSASH_DRAG_NONE       0
#define wxSASH_DRAG_DRAGGING   1
#define wxSASH_DRAG_LEFT_DOWN  2

#define wxSW_NOBORDER         0x0000
//#define wxSW_3D               0x0010
#define wxSW_BORDER           0x0020
#define wxSW_3DSASH           0x0040
#define wxSW_3DBORDER         0x0080
#define wxSW_3D (wxSW_3DSASH | wxSW_3DBORDER)

enum wxSashEdgePosition {
    wxSASH_TOP = 0,
    wxSASH_RIGHT,
    wxSASH_BOTTOM,
    wxSASH_LEFT,
    wxSASH_NONE = 100
};
