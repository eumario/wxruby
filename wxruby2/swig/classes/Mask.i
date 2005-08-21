#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/bitmap.h>
%}

%module(directors="1") wxMask

%import "include/wxObject.h"

%include "include/wxMask.h"
