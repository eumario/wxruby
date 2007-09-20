// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license


/* 

TODO - Not yet wrapped. This class is tricky for two reasons:

 1) The bigger problem: the design of the C++ class requires that
    several methods are over-ridden in Ruby (eg OnDrawItem). THis is
    fine and possible and director methods calling into ruby are
    correctly generated. However, SWIG also generates a constructor
    option for this class in itself (ie, not as a superclass of a ruby
    class), and this triggers a compile error b/c wxVListBox contains
    pure virtual methods. So we need a way to either: tell SWIG to only
    generate a director constructor, or (as wxPython) create an aliased
    class wxRbVListBox (urgh). This latter doesn't seem worth the effort
    at the moment.

 2) The smaller problem: the compiler gets cross because SWIG wraps some
    methods that are marked "protected" - eg OnMeasureItem

*/

#if !defined(_wxVListBox_h_)
#define _wxVListBox_h_
class wxVListBox : public wxVScrolledWindow
{
public:
   wxVListBox(wxWindow* parent, 
			  wxWindowID id = wxID_ANY, 
			  const wxPoint& pos = wxDefaultPosition, 
			  const wxSize& size = wxDefaultSize, 
			  long style = 0, 
			  const wxString& name = wxVListBoxNameStr);
   wxVListBox();
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

  virtual void OnDrawItem(wxDC&  dc, const wxRect& rect, size_t n) const;
  virtual void OnDrawSeparator(wxDC& dc, wxRect& rect, size_t n) const;
  virtual wxCoord OnMeasureItem(size_t n) const;

  bool Select(size_t item, bool select = true);
  bool SelectAll();
  bool SelectRange(size_t from, size_t to);
  void SetMargins(const wxPoint& pt);
  void SetMargins(wxCoord x, wxCoord  y);
  void SetSelection(int selection);
  void SetSelectionBackground(const wxColour& col);
  void Toggle(size_t item);
};


#endif
