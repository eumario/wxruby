// wxButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxButton_h_)
#define _wxButton_h_
class wxButton : public wxControl
{
public:
   wxButton() ;
  wxButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
  virtual  ~wxButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
  wxString GetLabel() const;
  wxSize GetDefaultSize() ;
  void SetDefault() ;
  void SetLabel(const wxString&  label ) ;
};


#endif
