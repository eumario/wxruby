// wxHtmlListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlListBox_h_)
#define _wxHtmlListBox_h_
class wxHtmlListBox : public wxVListBox
{
public:
   wxHtmlListBox(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, size_t  countItems = 0, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
   wxHtmlListBox() ;
  virtual  ~wxHtmlListBox() ;
  bool Create(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
  wxColour GetSelectedTextBgColour(const wxColour&  colBg ) const;
  wxColour GetSelectedTextColour(const wxColour&  colFg ) const;
  virtual wxString OnGetItem(size_t  n ) const;
  virtual wxString OnGetItemMarkup(size_t  n ) const;
};


#endif
