// wxIconBundle.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
