// wxDir.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDir_h_)
#define _wxDir_h_
class wxDir
{
public:
   wxDir() ;
   wxDir(const wxString&  dir ) ;
  virtual  ~wxDir() ;
  static bool Exists(const wxString&  dir ) ;
  static size_t GetAllFiles(const wxString&  dirname , wxArrayString * files , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) ;
  bool GetFirst(wxString*  filename , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) const;
  wxString GetName() const;
  bool GetNext(wxString*  filename ) const;
  bool HasFiles(const wxString&  filespec = wxEmptyString) ;
  bool HasSubDirs(const wxString&  dirspec = wxEmptyString) ;
  bool IsOpened() const;
  bool Open(const wxString&  dir ) ;
  size_t Traverse(wxDirTraverser&  sink , const wxString&  filespec = wxEmptyString, int  flags = wxDIR_DEFAULT) ;
};


#endif
