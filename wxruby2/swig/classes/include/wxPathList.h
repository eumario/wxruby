// wxPathList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPathList_h_)
#define _wxPathList_h_
class wxPathList : public wxList
{
public:
   wxPathList() ;
  void AddEnvList(const wxString&  env_variable ) ;
  void Add(const wxString&  path ) ;
  void EnsureFileAccessible(const wxString&  filename ) ;
  wxString FindAbsoluteValidPath(const wxString&  file ) ;
  wxString FindValidPath(const wxString&  file ) ;
  bool Member(const wxString&  file ) ;
};


#endif
