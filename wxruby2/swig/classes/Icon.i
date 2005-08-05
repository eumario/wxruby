#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxIcon

%ignore wxIcon::wxIcon();
%ignore wxIcon::wxIcon(const wxIcon& icon);
%ignore wxIcon::wxIcon(void* data, wxBitmapType type, int width, int height, int depth = -1);
%ignore wxIcon::wxIcon(const char bits[], int width, int height, int depth = 1);
%ignore wxIcon::wxIcon(int width, int height, int depth = -1);
%ignore wxIcon::wxIcon(char** bits);
%ignore wxIcon::wxIcon(const char** bits);
%ignore wxIcon::wxIcon(const wxIconLocation&  loc );
%ignore wxIcon::SaveFile(const wxString&  name , wxBitmapType  type , wxPalette*  palette = NULL);
%ignore wxIcon::SetOk;

%include "include/wxIcon.h"
