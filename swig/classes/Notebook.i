#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/notebook.h>
%}

%module(directors="1") wxNotebook

GC_NEVER(wxNotebook)

#define wxNotebookPage wxPanel

%ignore wxNotebook::wxNotebook();
%ignore wxNotebook::OnSelChange;
%feature("nodirector") wxNotebook::OnSelChange;



# under GTK, we don't have OnSelChange, 
# and since it is virtual, that means 
# we can't even try to compile the class!
%runtime %{
//@@if defined(__WXMSW__) || defined(__WXMAC__)
%}

%include "include/wxNotebook.h"
 
