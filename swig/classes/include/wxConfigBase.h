// wxConfigBase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxConfigBase_h_)
#define _wxConfigBase_h_
class wxConfigBase
{
public:
  wxConfigBase(const wxString&  appName = wxEmptyString, const wxString&  vendorName = wxEmptyString);
  virtual  ~wxConfigBase() ;
  static wxConfigBase * Create() ;
  void DontCreateOnDemand() ;
  bool DeleteAll() ;
  bool DeleteEntry(const wxString&   key , bool bDeleteGroupIfEmpty = true) ;
  bool DeleteGroup(const wxString&   key ) ;
  bool Exists(wxString&  strName ) const;
  bool Flush(bool  bCurrentOnly = false) ;
  static wxConfigBase * Get(bool  CreateOnDemand = true) ;
  wxString GetAppName() const;
  enum wxConfigBase::EntryType GetEntryType(const wxString&  name ) const;
  bool GetFirstGroup(wxString&  str , long&  index ) const;
  bool GetFirstEntry(wxString&  str , long&  index ) const;
  bool GetNextGroup(wxString&  str , long&  index ) const;
  bool GetNextEntry(wxString&  str , long&  index ) const;
  int  GetNumberOfEntries(bool  bRecursive = false) const;
  int GetNumberOfGroups(bool  bRecursive = false) const;
  wxString GetPath() const;
  wxString GetVendorName() const;
  bool HasEntry(wxString&  strName ) const;
  bool HasGroup(const wxString&  strName ) const;
  bool IsExpandingEnvVars() const;
  bool IsRecordingDefaults() const;
  bool Read(const wxString&  key , wxString*  str ) const;
  bool Read(const wxString&  key , wxString*  str , const wxString&  defaultVal ) const;
  wxString Read(const wxString&  key , const wxString&  defaultVal ) const;
  bool Read(const wxString&   key , long*  l ) const;
  bool Read(const wxString&   key , long*  l , long  defaultVal ) const;
  long  Read(const wxString&  key , long  defaultVal ) const;
  bool Read(const wxString&   key , double*  d ) const;
  bool Read(const wxString&   key , double*  d , double  defaultVal ) const;
  bool Read(const wxString&   key , bool*  b ) const;
  bool Read(const wxString&   key , bool*  d , bool  defaultVal ) const;
  bool RenameEntry(const wxString&   oldName , const wxString&   newName ) ;
  bool RenameGroup(const wxString&   oldName , const wxString&   newName ) ;
  static wxConfigBase * Set(wxConfigBase * pConfig ) ;
  void SetExpandEnvVars(bool  bDoIt = true) ;
  void SetPath(const wxString&  strPath ) ;
  void SetRecordDefaults(bool  bDoIt = true) ;
  void SetUmask(int  mode ) ;
  bool Write(const wxString&   key , const wxString&   value ) ;
  bool Write(const wxString&   key , long  value ) ;
  bool Write(const wxString&   key , double  value ) ;
  bool Write(const wxString&   key , bool  value ) ;
};


#endif
