// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGenericDirCtrl
GC_MANAGE_AS_WINDOW(wxGenericDirCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxGenericDirCtrl);

%{
#include <wx/dirctrl.h>
%}

enum
{
    // Only allow directory viewing/selection, no files
    wxDIRCTRL_DIR_ONLY       = 0x0010,
    // When setting the default path, select the first file in the directory
    wxDIRCTRL_SELECT_FIRST   = 0x0020,
    // Show the filter list
    wxDIRCTRL_SHOW_FILTERS   = 0x0040,
    // Use 3D borders on internal controls
    wxDIRCTRL_3D_INTERNAL    = 0x0080,
    // Editable labels
    wxDIRCTRL_EDIT_LABELS    = 0x0100
};

// wxTreeItemId conversion to Ruby Integers - GetRootId method needs this
%include "../shared/treeitemid_typemaps.i"

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxGenericDirCtrl.h"
