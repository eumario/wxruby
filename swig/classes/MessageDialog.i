#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/msgdlg.h>
%}

%module(directors="1") wxMessageDialog

%include "include/wxMessageDialog.h"
