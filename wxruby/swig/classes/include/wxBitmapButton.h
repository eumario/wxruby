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
   wxBitmapButton(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxBU_AUTODRAW, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("button")) ;
  virtual  ~wxBitmapButton() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("button"));
  const wxBitmap& GetBitmapDisabled() const;
  const wxBitmap& GetBitmapFocus() const;
  const wxBitmap& GetBitmapHover() const;
  const wxBitmap& GetBitmapLabel() const;
  const wxBitmap& GetBitmapSelected() const;

  wxBitmap& GetBitmapDisabled();
  wxBitmap& GetBitmapFocus();
  wxBitmap& GetBitmapHover();
  wxBitmap& GetBitmapLabel();
  wxBitmap& GetBitmapSelected();

  void SetBitmapDisabled(const wxBitmap&  bitmap ) ;
  void SetBitmapFocus(const wxBitmap&  bitmap ) ;
  void SetBitmapHover(const wxBitmap&  bitmap ) ;
  void SetBitmapLabel(const wxBitmap&  bitmap ) ;
  void SetBitmapSelected(const wxBitmap&  bitmap ) ;

};


#endif
