// wxFileName.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileName_h_)
#define _wxFileName_h_
class wxFileName
{
public:
   wxFileName() ;
   wxFileName(const wxFileName&  filename ) ;
   wxFileName(const wxString&  fullpath , wxPathFormat  format = wxPATH_NATIVE) ;
   wxFileName(const wxString&  path , const wxString&  name , wxPathFormat  format = wxPATH_NATIVE) ;
   wxFileName(const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
   wxFileName(const wxString&  volume , const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
  void AppendDir(const wxString&  dir ) ;
  void Assign(const wxFileName&  filepath ) ;
  void Assign(const wxString&  fullpath , wxPathFormat  format = wxPATH_NATIVE) ;
  void Assign(const wxString&  volume , const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
  void Assign(const wxString&  path , const wxString&  name , wxPathFormat  format = wxPATH_NATIVE) ;
  void Assign(const wxString&  path , const wxString&  name , const wxString&  ext , wxPathFormat  format = wxPATH_NATIVE) ;
  void AssignCwd(const wxString&  volume = "") ;
  void AssignDir(const wxString&  dir , wxPathFormat  format = wxPATH_NATIVE) ;
  void AssignHomeDir() ;
  void AssignTempFileName(const wxString&  prefix , wxFile * fileTemp = NULL) ;
  void Clear() ;
  static wxString CreateTempFileName(const wxString&  prefix , wxFile * fileTemp = NULL) ;
  bool DirExists() const;
  static bool DirExists(const wxString&  dir ) ;
  wxFileName DirName(const wxString&  dir ) ;
  bool FileExists() const;
  static bool FileExists(const wxString&  file ) ;
  wxFileName FileName(const wxString&  file ) ;
  wxString GetCwd(const wxString&  volume = "") ;
  size_t GetDirCount() const;
  const wxArrayString& GetDirs() const;
  wxString GetExt() const;
  wxPathFormat GetFormat(wxPathFormat  format = wxPATH_NATIVE) ;
  wxString GetFullName() const;
  wxString GetFullPath(wxPathFormat  format = wxPATH_NATIVE) const;
  wxString GetHomeDir() ;
  wxString GetLongPath() const;
  wxDateTime GetModificationTime() const;
  wxString GetName() const;
  wxString GetPath(int  flags = 0, wxPathFormat  format = wxPATH_NATIVE) const;
  wxChar GetPathSeparator(wxPathFormat  format = wxPATH_NATIVE) ;
  wxString GetPathSeparators(wxPathFormat  format = wxPATH_NATIVE) ;
  wxString GetShortPath() const;
  bool GetTimes(wxDateTime*  dtAccess , wxDateTime*  dtMod , wxDateTime*  dtCreate ) const;
  wxString GetVolume() const;
  wxString GetVolumeSeparator(wxPathFormat  format = wxPATH_NATIVE) ;
  bool HasExt() const;
  bool HasName() const;
  bool HasVolume() const;
  void InsertDir(int  before , const wxString&  dir ) ;
  bool IsAbsolute(wxPathFormat  format = wxPATH_NATIVE) ;
  bool IsCaseSensitive(wxPathFormat  format = wxPATH_NATIVE) ;
  bool IsOk() const;
  bool IsPathSeparator(wxChar  ch , wxPathFormat  format = wxPATH_NATIVE) ;
  bool IsRelative(wxPathFormat  format = wxPATH_NATIVE) ;
  bool IsDir() const;
  bool MakeAbsolute(const wxString&  cwd = wxEmptyString, wxPathFormat  format = wxPATH_NATIVE) ;
  bool MakeRelativeTo(const wxString&  pathBase = "", wxPathFormat  format = wxPATH_NATIVE) ;
  bool Mkdir(int  perm = 0777, int  flags = 0) ;
  static bool Mkdir(const wxString&  dir , int  perm = 0777, int  flags = 0) ;
  bool Normalize(int  flags = wxPATH_NORM_ALL, const wxString&  cwd = wxEmptyString, wxPathFormat  format = wxPATH_NATIVE) ;
  void PrependDir(const wxString&  dir ) ;
  void RemoveDir(int  pos ) ;
  bool Rmdir() ;
  static bool Rmdir(const wxString&  dir ) ;
  bool SameAs(const wxFileName&  filepath , wxPathFormat  format = wxPATH_NATIVE) const;
  bool SetCwd() ;
  static bool SetCwd(const wxString&  cwd ) ;
  void SetExt(const wxString&  ext ) ;
  void SetFullName(const wxString&  fullname ) ;
  void SetName(const wxString&  name ) ;
  bool SetTimes(const wxDateTime*  dtAccess , const wxDateTime*  dtMod , const wxDateTime*  dtCreate ) ;
  void SetVolume(const wxString&  volume ) ;
  static void SplitPath(const wxString&  fullpath , wxString*  volume , wxString*  path , wxString*  name , wxString*  ext , wxPathFormat  format = wxPATH_NATIVE) ;
  static void SplitPath(const wxString&  fullpath , wxString*  path , wxString*  name , wxString*  ext , wxPathFormat  format = wxPATH_NATIVE) ;
  bool Touch() ;
};


#endif
