#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"


%module(directors="1") wxTextCtrl

#
# Doing this to counter a bug in SWIG-1.3.21. To be taken
# out at a later date
#
%ignore wxTextCtrl::wxTextCtrl();

%ignore wxTextCtrl::GetStyle;
%include "include/wxTextCtrl.h"


