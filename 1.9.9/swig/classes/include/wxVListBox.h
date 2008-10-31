// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

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
  void SetItemCount(size_t count);
  void SetMargins(const wxPoint& pt);
  void SetMargins(wxCoord x, wxCoord  y);
  void SetSelection(int selection);
  void SetSelectionBackground(const wxColour& col);
  void Toggle(size_t item);
};


#endif
