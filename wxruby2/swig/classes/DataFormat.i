// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxDataFormat
GC_MANAGE_AS_OBJECT(wxDataFormat);

%{
#include <wx/dataobj.h>
%}

%typemap("in") const wxChar* format {
  $1 = (wxChar*)wxString(StringValuePtr($input), wxConvUTF8).c_str();
}

enum wxDataFormatId
{
    wxDF_INVALID =          0,
    wxDF_TEXT =             1,  /* CF_TEXT */
    wxDF_BITMAP =           2,  /* CF_BITMAP */
    wxDF_METAFILE =         3,  /* CF_METAFILEPICT */
    wxDF_SYLK =             4,
    wxDF_DIF =              5,
    wxDF_TIFF =             6,
    wxDF_OEMTEXT =          7,  /* CF_OEMTEXT */
    wxDF_DIB =              8,  /* CF_DIB */
    wxDF_PALETTE =          9,
    wxDF_PENDATA =          10,
    wxDF_RIFF =             11,
    wxDF_WAVE =             12,
    wxDF_UNICODETEXT =      13,
    wxDF_ENHMETAFILE =      14,
    wxDF_FILENAME =         15, /* CF_HDROP */
    wxDF_LOCALE =           16,
    wxDF_PRIVATE =          20,
    wxDF_HTML =             30, /* Note: does not correspond to CF_ constant */
    wxDF_MAX
};

%include "include/wxDataFormat.h" 
