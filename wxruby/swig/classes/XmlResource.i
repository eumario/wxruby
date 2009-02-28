// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%module(directors="1") wxXmlResource

%include "../common.i"

%{
#include <wx/xrc/xmlres.h>
%}

enum wxXmlResourceFlags
{
    wxXRC_USE_LOCALE     = 1,
    wxXRC_NO_SUBCLASSING = 2,
    wxXRC_NO_RELOADING   = 4
};

// For these three methods, there are in Wx two variants. One loads an
// XRC from scratch and returns an instance of the core Wx class:
// Wx::Dialog, Wx::Frame, or Wx::Panel. The other loads in a layout into
// an already existing instance of one of these classes, which may be a
// custom ruby subclass containing extended methods etc. These two types
// are disambiguated below.
%rename(LoadDialogSubclass) wxXmlResource::LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString &name);

%rename(LoadPanelSubclass) wxXmlResource::LoadPanel(wxPanel *panel, wxWindow *parent, const wxString &name);

%rename(LoadFrameSubclass) wxXmlResource::LoadFrame(wxFrame *frame, wxWindow *parent, const wxString &name);

// Can't write XRC handlers in Ruby
%ignore wxXmlResource::AddHandler;
%ignore wxXmlResource::ClearHandlers;
%ignore wxXmlResource::InsertHandler;

// XmlResource is an exception to the general rule in typemap.i - it has
// methods which accept a 'wxWindow* parent' argument which may be
// null. The standard typemap checks if the parent is NULL, but Dialogs
// and Frames may have NULL (Ruby:nil) parents as created by XmlResource
// LoadDialog and LoadFrame methods. So we disable that part of the
// checking for all methods (including those which would ideally retain
// it - eg LoadPanel - b/c no way to apply a typemap based on method
// name in SWIG?)
%typemap(check) wxWindow* parent {
  if ( ! rb_const_defined(mWxruby2, rb_intern("THE_APP") ) )
	{ rb_raise(rb_eRuntimeError,
			   "Cannot load from XRC before App.main_loop has been called");}
}

%import "include/wxObject.h"

%include "include/wxXmlResource.h"
