// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%module(directors="1") wxXmlResource

%include "../common.i"

%{
#include <wx/xrc/xmlres.h>
%}

%rename(LoadDialogSubclass) wxXmlResource::LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString &name);

%rename(LoadPanelSubclass) wxXmlResource::LoadPanel(wxPanel *pan, wxWindow *parent, wxString &name);

%rename(LoadFrameSubclass) wxXmlResource::LoadFrame(wxFrame *frame, wxWindow *parent, const wxString &name);


%import "include/wxObject.h"

%include "include/wxXmlResource.h"
