#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxFontDialog
%{
#include <wx/wx.h>
#include <wx/fontdlg.h>
%}

//
// Hey cool - conditional compilation!
//
#ifdef __WXMAC__
%feature("nodirector") wxFontDialog;
%ignore wxFontDialog::wxFontDialog(wxWindow *);
#endif

#
# Workaround for SWIG 1.3.22
#
%feature("nodirector") wxFontDialog;
%ignore wxFontDialog::Create();
%ignore wxFontDialog::wxFontDialog();
%nodirector wxFontDialog::wxFontDialog();

%include "include/wxFontDialog.h"
