// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

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
