#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeEvent

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
