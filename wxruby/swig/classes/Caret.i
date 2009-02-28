// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%{
#include <wx/caret.h>
%}

%module(directors="1") wxCaret
GC_MANAGE_AS_OBJECT(wxCaret);

%ignore wxCaret::wxCaret(wxWindow* window, int width, int height);

// only support the variants that return an object
%ignore GetPosition(int* x, int* y) const;
%ignore GetSize(int* width, int* height) const;

%rename(MoveXy) wxCaret::Move(int, int);

%include "include/wxCaret.h"
