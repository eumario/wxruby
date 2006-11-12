# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxHtmlEasyPrinting

%{
#include <wx/html/htmprint.h>
%}


%import "include/wxObject.h"

%include "include/wxHtmlEasyPrinting.h"
