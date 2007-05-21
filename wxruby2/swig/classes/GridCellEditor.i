// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellEditor
GC_MANAGE(wxGridCellEditor);

%{
#include <wx/grid.h>
%}

%ignore wxGridCellEditor::wxGridCellEditor();
%ignore wxGridCellEditor::~wxGridCellEditor();

#This is to get arround SWIG trying to call a protected destructor
%nodefault wxGridCellEditor;


%include "include/wxGridCellEditor.h"
