// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxArtProvider_h_)
#define _wxArtProvider_h_

class wxArtProvider : public wxObject
{
public:
  static bool Delete(wxArtProvider* provider);
  static wxBitmap GetBitmap(const wxArtID&  id, 
							const wxArtClient&  client = wxART_OTHER, 
							const wxSize&  size = wxDefaultSize);
  static wxIcon GetIcon(const wxArtID&  id, 
						const wxArtClient&  client = wxART_OTHER, 
						const wxSize&  size = wxDefaultSize);
  static bool Insert(wxArtProvider* provider);
  static bool Pop();
  static void Push(wxArtProvider* provider) ;
  static bool Remove(wxArtProvider* provider) ;
};


#endif
