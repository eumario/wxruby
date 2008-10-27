// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlListBox
GC_MANAGE_AS_WINDOW(wxHtmlListBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxHtmlListBox);

// This class is pure abstract in wxWidgets, therefore a stub / bridge
// subclass, defined below, is what is wrapped in wxRuby, and director
// methods must be provided for the appropriate methods.
%rename(wxHtmlListBox) wxRubyHtmlListBox;

%{
#include <wx/htmllbox.h>
%}

%{
class wxRubyHtmlListBox : public wxHtmlListBox
{
public:
  wxRubyHtmlListBox(wxWindow* parent, 
                    wxWindowID id = wxID_ANY, 
                    const wxPoint& pos = wxDefaultPosition, 
                    const wxSize& size = wxDefaultSize,
                    long style = 0, 
                    const wxString& name = wxVListBoxNameStr) :
    wxHtmlListBox(parent, id, pos, size, style, name) { }
  wxRubyHtmlListBox() :
    wxHtmlListBox() { };
  // must be over-ridden in Ruby
  virtual wxString OnGetItem(size_t n) const 
    {       
      rb_raise(rb_eNoMethodError, 
               "on_get_item method must be defined for VListBox");
      return wxEmptyString;
    }
  // may be over-ridden in Ruby
  virtual wxString OnGetItemMarkup(size_t n) const
    { return wxHtmlListBox::OnGetItemMarkup(n); }
};
%}

%ignore wxHtmlListBox::GetSelectedTextBgColour;
%ignore wxHtmlListBox::GetSelectedTextColour;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxVScrolledWindow.h"
%import "include/wxVListBox.h"

class wxRubyHtmlListBox : public wxHtmlListBox
{
public:
   wxRubyHtmlListBox(wxWindow* parent, 
                 wxWindowID id = wxID_ANY, 
                 const wxPoint& pos = wxDefaultPosition, 
                 const wxSize& size = wxDefaultSize, 
                 long  style = 0, 
                 const wxString& name = wxVListBoxNameStr);
   wxRubyHtmlListBox();
   virtual ~wxRubyHtmlListBox();
   bool Create(wxWindow* parent, 
               wxWindowID id = wxID_ANY, 
               const wxPoint&  pos = wxDefaultPosition, 
               const wxSize&  size = wxDefaultSize, 
               long style = 0, 
               const wxString& name = wxVListBoxNameStr);
   wxColour GetSelectedTextBgColour(const wxColour& colBg) const;
   wxColour GetSelectedTextColour(const wxColour& colFg) const;
   virtual wxString OnGetItem(size_t n) const;
   virtual wxString OnGetItemMarkup(size_t n) const;
};

