// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextBuffer;
GC_NEVER(wxRichTextBuffer);

%{
#include <wx/richtext/richtextbuffer.h>
%}

%include "../shared/richtext.i"

#define wxRICHTEXT_TYPE_ANY             0
#define wxRICHTEXT_TYPE_TEXT            1
#define wxRICHTEXT_TYPE_XML             2
#define wxRICHTEXT_TYPE_HTML            3
#define wxRICHTEXT_TYPE_RTF             4
#define wxRICHTEXT_TYPE_PDF             5

// Use the RichTextAttr version
%ignore wxRichTextBuffer::SetStyle(const wxRichTextRange& range,
                                   const wxTextAttrEx& style,
                                   int flags);

// Not supported for now
%ignore wxRichTextBuffer::GetBatchedCommand;
%ignore wxRichTextBuffer::GetCommandProcessor;

%apply SWIGTYPE *DISOWN { wxRichTextFileHandler* handler };

%include "include/wxRichTextBuffer.h"
