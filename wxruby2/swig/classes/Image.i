// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxImage
GC_MANAGE_AS_OBJECT(wxImage);

%{
#include <wx/image.h>
%}

// No default ctor
%ignore wxImage::Create();

// These forms of creation, querying, loading and saving are not
// supported in wxRuby; could possibly map Ruby IO.read/IO.write to
// wxWidgets InputStream/OutputStream, but this seems difficult
%ignore wxImage(wxInputStream& stream, 
                long type = wxBITMAP_TYPE_ANY, 
                int index = -1);
%ignore wxImage(wxInputStream& stream, 
                const wxString& mimetype, 
                int index = -1);
%ignore wxImage::GetImageCount(wxInputStream& stream, 
                               long type = wxBITMAP_TYPE_ANY);
%ignore wxImage::LoadFile(wxInputStream& stream, 
                          long type, 
                          int index = -1);
%ignore wxImage::LoadFile(wxInputStream& stream, 
                          const wxString& mimetype, 
                          int index = -1);
%ignore wxImage::SaveFile(wxOutputStream& stream, 
                          int type) const;
%ignore wxImage::SaveFile(wxOutputStream& stream, 
                          const wxString& mimetype) const;

// Handler methods are not supported in wxRuby; all standard handlers
// are loaded at startup, and we don't allow custom image handlers to be
// written in Ruby. Note if these methods are added, corrected freearg
// typemap for input wxString in static methods will be required.
%ignore wxImage::AddHandler;
%ignore wxImage::CleanUpHandlers;
%ignore wxImage::FindHandler;
%ignore wxImage::FindHandlerMime;
%ignore wxImage::GetHandlers;
%ignore wxImage::InitStandardHandlers;
%ignore wxImage::InsertHandler;
%ignore wxImage::RemoveHandler;

// For Image#set_data, Image#set_alpha and Image.new with raw data arg:
// copy raw string data from a Ruby string to a memory block that will be
// managed by wxWidgets
%typemap(in) unsigned char* data, unsigned char* alpha {
  if ( TYPE($input) == T_STRING )
    {
      int data_len = RSTRING_LEN($input);
      $1 = (unsigned char*)malloc(data_len);
      memcpy($1, StringValuePtr($input), data_len);
    }
  else
    SWIG_exception_fail(SWIG_ERROR, 
                        "String required as raw Image data argument");
}

// Image.new(data...) and Image#set_alpha both accept a static_data
// argument to specify whether wxWidgets should delete the data
// pointer. Since in wxRuby we always copy from the Ruby string object
// to the Image, we always want wxWidgets to handle deletion of the copy
%typemap(in, numinputs=0) bool static_data "$1 = false;"


%apply unsigned char *OUTPUT { unsigned char* r, 
                               unsigned char* g, 
                               unsigned char* b }

%import "include/wxObject.h"

%include "include/wxImage.h"
