#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFont

%feature("nodirector") wxFont;

%ignore wxFont::SetNativeFontInfo;
%include "include/wxFont.h"
