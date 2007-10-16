// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPrintPreview
GC_MANAGE_AS_OBJECT(wxPrintPreview);

%{
#include <wx/print.h>
%}

%{
  static void mark_wxPrintPreview(void *ptr)
  {
	wxPrintPreview* print_preview = (wxPrintPreview*)ptr;
	wxPrintout* printout = print_preview->GetPrintout();
	rb_gc_mark( SWIG_RubyInstanceFor(printout) );
	wxPrintout* printout_for_printing = print_preview->GetPrintoutForPrinting();
	rb_gc_mark( SWIG_RubyInstanceFor(printout_for_printing) );
  }
%}

%markfunc wxPrintPreview "mark_wxPrintPreview";

%import "include/wxObject.h"

%include "include/wxPrintPreview.h"
