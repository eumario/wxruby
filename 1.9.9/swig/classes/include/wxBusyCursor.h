// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

// Don't add this class, as it's written in ruby instead
// (lib/wx/classes/busycursor.rb). It's easier to ensure that the cursor
// gets restored, and it's such a trivial class it's not worth having a
// whole SWIG class for it.
#if !defined(_wxBusyCursor_h_)
#define _wxBusyCursor_h_
class wxBusyCursor
{
public:
  wxBusyCursor(wxCursor* cursor = wxHOURGLASS_CURSOR) ;
  virtual  ~wxBusyCursor() ;

};


#endif
