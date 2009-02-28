// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxStaticBitmap_h_)
#define _wxStaticBitmap_h_
class wxStaticBitmap : public wxControl
{
public:
   wxStaticBitmap() ;
   wxStaticBitmap(wxWindow*  parent, 
				  wxWindowID  id, 
				  const wxBitmap&  label, 
				  const wxPoint&  pos = wxDefaultPosition, 
				  const wxSize&  size = wxDefaultSize, 
				  long style = 0, 
				  const wxString&  name = wxT("staticBitmap"));
   bool Create(wxWindow*  parent , 
			   wxWindowID  id, 
			   const wxBitmap&  label, 
			   const wxPoint&  pos = wxDefaultPosition, 
			   const wxSize&  size = wxDefaultSize, 
			   long style = 0, 
			   const wxString&  name = wxT("staticBitmap"));
  wxBitmap GetBitmap() const;
  wxIcon GetIcon() const;
  virtual void SetBitmap(const wxBitmap& label);
  virtual void SetIcon(const wxIcon& label);
};


#endif
