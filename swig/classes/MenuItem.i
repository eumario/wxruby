// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenuItem
// GC_MANAGE_AS_OBJECT(wxMenuItem);
GC_NEVER(wxMenuItem);

%import "include/wxObject.h"
// TODO: Also OwnerDrawn under MS Windows

%include "include/wxMenuItem.h"
