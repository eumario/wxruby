#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxIcon

%import "include/wxObject.h"
%import "include/wxGDIObject.h"
// the following might eventually be helpful for MSWin?
// %import "include/wxGDIImage.h"
// the following works on GTK but not MS Win
// %import "include/wxBitmap.h"

%include "include/wxIcon.h"
