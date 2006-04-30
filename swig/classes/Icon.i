#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxIcon

// redundant since only varies by const-ness
%ignore wxIcon(char **data);
%ignore wxIcon( char **bits, int width=-1, int height=-1 );

%import "include/wxObject.h"
%import "include/wxGDIObject.h"
// the following might eventually be helpful for MSWin?
// %import "include/wxGDIImage.h"
// the following works on GTK but not MS Win
// %import "include/wxBitmap.h"

%include "include/wxIcon.h"
