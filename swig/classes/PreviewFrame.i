// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPreviewFrame
GC_MANAGE_AS_FRAME(wxPreviewFrame);

%{
#include <wx/print.h>
%}


// Once a PrintPreview is associated with a PreviewFrame, it is deleted
// automatically by wxWidgets - so must avoid calling its destructor
// from Ruby when it is GC'd.
%apply SWIGTYPE *DISOWN {wxPrintPreview* preview};

%rename(init) Initialize;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxFrame.h"

%include "include/wxPreviewFrame.h"
