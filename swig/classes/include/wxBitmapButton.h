// wxBitmapButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmapButton_h_)
#define _wxBitmapButton_h_
class wxBitmapButton : public wxButton
{
public:
   wxBitmapButton() ;
   wxBitmapButton(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxBU_AUTODRAW, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button") ;
  virtual  ~wxBitmapButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
  const wxBitmap& GetBitmapDisabled() const;
  const wxBitmap& GetBitmapFocus() const;
  const wxBitmap& GetBitmapLabel() const;
  const wxBitmap& GetBitmapSelected() const;
  void SetBitmapDisabled(const wxBitmap&  bitmap ) ;
  void SetBitmapFocus(const wxBitmap&  bitmap ) ;
  void SetBitmapLabel(const wxBitmap&  bitmap ) ;
  void SetBitmapSelected(const wxBitmap&  bitmap ) ;
  // the following were missing from the xml
  wxBitmap& GetBitmapDisabled();
  wxBitmap& GetBitmapFocus();
  wxBitmap& GetBitmapLabel();
  wxBitmap& GetBitmapSelected();
};


#endif
