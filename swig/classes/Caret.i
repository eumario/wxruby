#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/caret.h>
%}

%module(directors="1") wxCaret
%ignore  wxCaret::wxCaret() ;
%ignore  wxCaret::wxCaret(wxWindow*  window , int  width , int  height ) ;


%rename(MoveXy) wxCaret::Move(int,int);

%include "include/wxCaret.h"
