#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxClassInfo

%feature("nodirector") wxClassInfo;

%ignore wxClassInfo::wxClassInfo;

# deprecated:
%ignore wxClassInfo::InitializeClasses;



%include "include/wxClassInfo.h"
