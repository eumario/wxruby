// wxStaticText.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticText_h_)
#define _wxStaticText_h_
class wxStaticText : public wxControl
{
public:
   wxStaticText() ;
   wxStaticText(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticText") ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticText") ;
  wxString GetLabel() const;
  virtual void SetLabel(const wxString&   label ) ;
  // the following were missing from the xml
  virtual ~wxStaticText();
};


#endif
