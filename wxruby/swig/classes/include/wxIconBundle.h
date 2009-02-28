// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxIconBundle_h_)
#define _wxIconBundle_h_
class wxIconBundle
{
public:
   wxIconBundle() ;
   wxIconBundle(const wxString&  file , long  type ) ;
   wxIconBundle(const wxIcon&  icon ) ;
   wxIconBundle(const wxIconBundle&  ic ) ;
   virtual  ~wxIconBundle() ;
   void AddIcon(const wxString&  file , long  type ) ;
   void AddIcon(const wxIcon&  icon ) ;
   const wxIcon& GetIcon(const wxSize&  size ) const;
   const wxIcon& GetIcon(wxCoord  size = -1) const;
};


#endif
