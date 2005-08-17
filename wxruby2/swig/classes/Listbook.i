#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxListbook
%feature("nodirector") wxListbook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/listbook.h>
%}


GC_NEVER(wxListbook)

#define wxListbookPage wxWindow

%ignore wxListbook::OnSelChange;

%include "include/wxListbook.h"
