// wxSingleInstanceChecker.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSingleInstanceChecker_h_)
#define _wxSingleInstanceChecker_h_
class wxSingleInstanceChecker
{
public:
   wxSingleInstanceChecker() ;
   wxSingleInstanceChecker(const wxString&  name , const wxString&  path = wxEmptyString) ;
  bool Create(const wxString&  name , const wxString&  path = wxEmptyString) ;
  bool IsAnotherRunning() const;
  virtual  ~wxSingleInstanceChecker() ;
};


#endif
