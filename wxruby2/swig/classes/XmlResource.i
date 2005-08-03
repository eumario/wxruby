#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxXmlResource

%include "../common.i"

%{
#include <wx/xrc/xmlres.h>
%}

%rename(LoadDialogSubclass) wxXmlResource::LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString &name);

%rename(LoadPanelSubclass) wxXmlResource::LoadPanel(wxPanel *pan, wxWindow *parent, wxString &name);

%rename(LoadFrameSubclass) wxXmlResource::LoadFrame(wxFrame *frame, wxWindow *parent, const wxString &name);


%include "include/wxXmlResource.h"
