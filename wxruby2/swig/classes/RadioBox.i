#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxRadioBox
%{
#include <wx/wx.h>
#include <wx/radiobox.h>
%}

%ignore wxRadioBox::wxRadioBox();
%ignore wxRadioBox::GetLabel;
%ignore wxRadioBox::SetLabel;
GC_NEVER(wxRadioBox);
%include "include/wxRadioBox.h"

