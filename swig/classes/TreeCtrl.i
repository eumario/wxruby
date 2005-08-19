#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTreeCtrl

%{
#include <wx/treectrl.h>
%}

// deprecated:
%ignore wxTreeCtrl::GetFirstChild;
%ignore wxTreeCtrl::GetItemSelectedImage;
%ignore wxTreeCtrl::SetItemSelectedImage;
%ignore wxTreeCtrl::GetParent;

// not sure why these aren't working
%ignore wxTreeCtrl::SelectItem;
%ignore wxTreeCtrl::SetStateImageList;

%include "include/wxTreeCtrl.h"
