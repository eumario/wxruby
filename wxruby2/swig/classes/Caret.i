#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/caret.h>
%}

%module(directors="1") wxCaret
%ignore  wxCaret::wxCaret() ;
%ignore  wxCaret::wxCaret(wxWindow*  window , int  width , int  height ) ;


%rename(MoveXy) wxCaret::Move(int,int);

%include "include/wxCaret.h"


