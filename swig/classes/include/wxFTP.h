// wxFTP.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFTP_h_)
#define _wxFTP_h_
class wxFTP : public wxProtocol
{
public:
   wxFTP() ;
  virtual  ~wxFTP() ;
  bool Abort() ;
  bool CheckCommand(const wxString&  command , char  ret ) ;
  char SendCommand(const wxString&  command ) ;
  const wxString& GetLastResult() ;
  bool ChDir(const wxString&  dir ) ;
  bool MkDir(const wxString&  dir ) ;
  bool RmDir(const wxString&  dir ) ;
  wxString Pwd() ;
  bool Rename(const wxString&  src , const wxString&  dst ) ;
  bool RmFile(const wxString&  path ) ;
  bool SetAscii() ;
  bool SetBinary() ;
  bool SetTransferMode(TransferMode  mode ) ;
  void SetUser(const wxString&  user ) ;
  void SetPassword(const wxString&  passwd ) ;
  bool FileExists(const wxString&  filename ) ;
  int GetFileSize(const wxString&  filename ) ;
  bool GetDirList(wxArrayString&  files , const wxString& wildcard = "") ;
  bool GetFilesList(wxArrayString&  files , const wxString& wildcard = "") ;
  wxOutputStream * GetOutputStream(const wxString&  file ) ;
  wxInputStream * GetInputStream(const wxString&  path ) ;
};


#endif
