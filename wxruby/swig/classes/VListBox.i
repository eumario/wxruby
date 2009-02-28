// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxVListBox
GC_MANAGE_AS_WINDOW(wxVListBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxVListBox);

%rename(wxVListBox) wxRubyVListBox;

%{
#include <wx/vlbox.h>
%}

%{
class wxRubyVListBox : public wxVListBox
{
public:
  wxRubyVListBox(wxWindow* parent, 
                 wxWindowID id = wxID_ANY, 
                 const wxPoint& pos = wxDefaultPosition, 
                 const wxSize& size = wxDefaultSize, 
                 long style = 0, 
                 const wxString& name = wxVListBoxNameStr) :
    wxVListBox(parent, id, pos, size, style, name) { }
  wxRubyVListBox() :
    wxVListBox() { };
  // These must be overridden in ruby class
  virtual wxCoord OnMeasureItem(size_t n) const 
    { 
      rb_raise(rb_eNoMethodError, 
               "on_measure_item method must be defined for VListBox");
      return 0; 
    }
  virtual void OnDrawItem(wxDC&  dc, const wxRect& rect, size_t n) const 
    { 
      rb_raise(rb_eNoMethodError, 
               "on_draw_item method must be defined for VListBox"); 
    }
  // This may be overridden in ruby class
  virtual void OnDrawSeparator(wxDC& dc, wxRect& rect, size_t n) const 
    { wxVListBox::OnDrawSeparator(dc, rect, n); };
};
%}

// These methods use the awkward "cookie" style of iterating over the
// selected items in the control. Instead we offer a get_selections
// method, defined below, which returns an array.
%ignore wxVListBox::GetFirstSelected;
%ignore wxVListBox::GetNextSelected;

%extend wxRubyVListBox {
  VALUE get_selections() {
    VALUE rb_sels = rb_ary_new();
    unsigned long cookie;
    int item = $self->GetFirstSelected(cookie);
    while ( item != -1 )
      {
        rb_ary_push(rb_sels, INT2NUM(item));
        item = $self->GetNextSelected(cookie);
      }
    return rb_sels;
  }
};

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxVScrolledWindow.h"


class wxRubyVListBox : public wxVListBox
{
public:
   wxRubyVListBox(wxWindow* parent, 
			  wxWindowID id = wxID_ANY, 
			  const wxPoint& pos = wxDefaultPosition, 
			  const wxSize& size = wxDefaultSize, 
			  long style = 0, 
			  const wxString& name = wxVListBoxNameStr);
   wxRubyVListBox();
   virtual ~wxRubyVListBox();
   void Clear();
   bool Create(wxWindow*  parent, 
			   wxWindowID  id = wxID_ANY, 
			   const wxPoint& pos = wxDefaultPosition, 
			   const wxSize& size = wxDefaultSize, 
			   long  style = 0, 
			   const wxString&  name = wxVListBoxNameStr);
  bool DeselectAll();
  int GetFirstSelected(unsigned long&  cookie ) const;
  size_t GetItemCount() const;
  wxPoint GetMargins() const;
  int GetNextSelected(unsigned long& cookie) const;
  size_t GetSelectedCount() const;
  int GetSelection() const;
  const wxColour& GetSelectionBackground() const;
  bool HasMultipleSelection() const;
  bool IsCurrent(size_t item) const;
  bool IsSelected(size_t item) const;

  virtual void OnDrawItem(wxDC&  dc, const wxRect& rect, size_t n) const = 0;
  virtual void OnDrawSeparator(wxDC& dc, wxRect& rect, size_t n) const;
  virtual wxCoord OnMeasureItem(size_t n) const = 0;

  bool Select(size_t item, bool select = true);
  bool SelectAll();
  bool SelectRange(size_t from, size_t to);
  void SetItemCount(size_t count);
  void SetMargins(const wxPoint& pt);
  void SetMargins(wxCoord x, wxCoord  y);
  void SetSelection(int selection);
  void SetSelectionBackground(const wxColour& col);
  void Toggle(size_t item);
};
