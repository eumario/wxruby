// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxStandardPaths
GC_NEVER(wxStandardPaths);

%header %{
#include <wx/stdpaths.h>
%}

typedef wxStandardPaths wxStandardPathsBase;

%include "include/wxStandardPaths.h"
