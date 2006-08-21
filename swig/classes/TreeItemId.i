#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeItemId

%{
#include <wx/treectrl.h>
%}

%include "include/wxTreeItemId.h"
