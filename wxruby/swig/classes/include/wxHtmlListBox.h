// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxHtmlListBox_h_)
#define _wxHtmlListBox_h_
class wxHtmlListBox : public wxVListBox
{
public:
   wxHtmlListBox(wxWindow* parent, 
                 wxWindowID id = wxID_ANY, 
                 const wxPoint& pos = wxDefaultPosition, 
                 const wxSize& size = wxDefaultSize, 
                 long  style = 0, 
                 const wxString& name = wxVListBoxNameStr);
   wxHtmlListBox();
   virtual ~wxHtmlListBox();
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


#endif
