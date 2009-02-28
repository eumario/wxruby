// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridTableBase
GC_MANAGE_AS_OBJECT(wxGridTableBase);

%{
#include <wx/grid.h>
%}

%typemap(directorin) wxGridCellAttr::wxAttrKind "$input = INT2NUM($1);"

%ignore wxGridTableBase::CanHaveAttributes;
%ignore wxGridTableBase::GetAttrProvider;
%ignore wxGridTableBase::SetAttrProvider;

%import "include/wxObject.h"
%include "include/wxGridTableBase.h"
