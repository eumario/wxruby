// wxStaticBitmap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticBitmap_h_)
#define _wxStaticBitmap_h_
class wxStaticBitmap : public wxControl
{
public:
   wxStaticBitmap() ;
   wxStaticBitmap(wxWindow*  parent , wxWindowID  id , const wxBitmap&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticBitmap") ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticBitmap") ;
  wxBitmap GetBitmap() const;
  virtual void SetBitmap(const wxBitmap&   label ) ;
};


#endif
