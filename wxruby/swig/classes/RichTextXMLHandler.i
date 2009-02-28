// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextXMLHandler;
GC_MANAGE_AS_OBJECT(wxRichTextXMLHandler);

%{
#include <wx/richtext/richtextxml.h>
%}

%include "../shared/richtext.i"

%ignore wxRichTextXMLHandler::CreateStyle;
%ignore wxRichTextXMLHandler::GetNodeContent;
%ignore wxRichTextXMLHandler::GetParamNode;
%ignore wxRichTextXMLHandler::GetParamValue;
%ignore wxRichTextXMLHandler::GetStyle;
%ignore wxRichTextXMLHandler::GetText;
%ignore wxRichTextXMLHandler::HasParam;
%ignore wxRichTextXMLHandler::ImportXML;

// Avoid crashes with the string constructor params
%typemap(freearg) wxString & "if ( argc > $argnum - 1 ) delete $1;"
%typemap(freearg) wxString* "if ( argc > $argnum - 1 ) delete $1;"

%import "include/wxObject.h"
%import "include/wxRichTextFileHandler.h"
%include "include/wxRichTextXMLHandler.h"
