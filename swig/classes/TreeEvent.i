// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTreeEvent
GC_MANAGE_AS_EVENT(wxTreeEvent);

%{
#include <wx/treectrl.h>
%}

// wxTreeItemId fixes - these typemaps convert them to ruby Integers
%include "../shared/treeitemid_typemaps.i"

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxTreeEvent.h"
