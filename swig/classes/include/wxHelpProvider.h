// wxHelpProvider.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpProvider_h_)
#define _wxHelpProvider_h_
class wxHelpProvider
{
public:
  virtual  ~wxHelpProvider() ;
  wxHelpProvider* Set(wxHelpProvider*  helpProvider ) ;
  wxHelpProvider* Get() ;
  wxString GetHelp(const wxWindowBase*  window ) ;
  bool ShowHelp(wxWindowBase*  window ) ;
  void AddHelp(wxWindowBase*  window , const wxString&  text ) ;
  void AddHelp(wxWindowID  id , const wxString&  text ) ;
  void RemoveHelp(wxWindowBase*  window ) ;
};


#endif
