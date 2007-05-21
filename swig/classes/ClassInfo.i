// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxClassInfo
GC_MANAGE(wxClassInfo);

%feature("nodirector") wxClassInfo;

%ignore wxClassInfo::wxClassInfo;

# deprecated:
%ignore wxClassInfo::InitializeClasses;



%include "include/wxClassInfo.h"
