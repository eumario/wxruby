# Copyright 2004-2006 by Kevin Smith
# released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxHtmlWindow

%{
#include <wx/html/htmlwin.h>
%}

// enums for wxHtmlWindow::OnOpeningURL
enum wxHtmlOpeningStatus
{
    wxHTML_OPEN,
    wxHTML_BLOCK,
    wxHTML_REDIRECT
};

// wxHtmlWindow flags:
#define wxHW_SCROLLBAR_NEVER    0x0002
#define wxHW_SCROLLBAR_AUTO     0x0004
#define wxHW_NO_SELECTION       0x0008
#define wxHW_DEFAULT_STYLE      wxHW_SCROLLBAR_AUTO


// implement in ruby
%ignore wxHtmlWindow::LoadFile;

// OnOpeningURL: for some reason this ignore doesn't actually ignore
// %ignore wxHtmlWindow::OnOpeningURL(wxHtmlURLType  type , const wxString&  url , wxString * redirect ) const;

// TODO: fix typemaps so that on_opening_url will be called in subclass method. 
// The default typemap for WxString. * is not correct for this method, but ignore doesn't seem to be working (SWIG 1.3.29). The typemaps below just stop a compile error
%typemap(in, numinputs=0) wxString * redirect "//*$1 = *$1;";
%typemap(directorargin) wxString * redirect "$1 = obj2;";
%typemap(directorargout, fragment="output_helper") wxString * redirect {
  //VALUE o = rb_str_new2((const char*)$1->mb_str());
  //$result = output_helper($result, o);
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxScrolledWindow.h"

%include "include/wxHtmlWindow.h"
