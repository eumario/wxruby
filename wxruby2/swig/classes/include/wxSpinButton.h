// wxSpinButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinButton_h_)
#define _wxSpinButton_h_
class wxSpinButton : public wxControl
{
public:
   wxSpinButton() ;
   wxSpinButton(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSP_HORIZONTAL, const wxString&  name = "spinButton") ;
  virtual  ~wxSpinButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSP_HORIZONTAL, const wxString&  name = "spinButton") ;
  int GetMax() const;
  int GetMin() const;
  int GetValue() const;
  void SetRange(int  min , int  max ) ;
  void SetValue(int  value ) ;
};


#endif
