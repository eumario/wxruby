// wxRadioButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRadioButton_h_)
#define _wxRadioButton_h_
class wxRadioButton : public wxControl
{
public:
   wxRadioButton() ;
   wxRadioButton(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioButton") ;
  virtual  ~wxRadioButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioButton") ;
  bool GetValue() const;
  void SetValue(const bool  value ) ;
};


#endif
