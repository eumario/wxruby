// wxArtProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArtProvider_h_)
#define _wxArtProvider_h_
class wxArtProvider : public wxObject
{
public:
  virtual wxBitmap CreateBitmap(const wxArtID&  id , const wxArtClient&  client , const wxSize&  size ) = 0;
  static wxBitmap GetBitmap(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static wxIcon GetIcon(const wxArtID&  id , const wxArtClient&  client = wxART_OTHER, const wxSize&  size = wxDefaultSize) ;
  static bool PopProvider() ;
  static void PushProvider(wxArtProvider*  provider ) ;
  static bool RemoveProvider(wxArtProvider*  provider ) ;
};


#endif
