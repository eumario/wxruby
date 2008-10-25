// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextFileHandler;
GC_MANAGE(wxRichTextFileHandler);

%{
#include <wx/richtext/richtextbuffer.h>
%}

%include "../shared/richtext.i"
%include "../shared/streams.i"

// This class is pure abstract so don't wrap the constructor
%ignore wxRichTextFileHandler::wxRichTextFileHandler;

%import "include/wxObject.h"
%include "include/wxRichTextFileHandler.h"

