#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFindReplaceData

%{
#include <wx/fdrepdlg.h>
%}

%include "include/wxFindReplaceData.h"
