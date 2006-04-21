//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxArtProvider_h_)
#define _wxArtProvider_h_
class wxArtProvider : public wxObject
{
public:
  static wxBitmap GetBitmap(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static wxIcon GetIcon(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static bool PopProvider() ;
  static void PushProvider(wxArtProvider*  provider ) ;
  static bool RemoveProvider(wxArtProvider*  provider ) ;
};


#endif
