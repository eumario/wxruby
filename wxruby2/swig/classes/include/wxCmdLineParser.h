// wxCmdLineParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCmdLineParser_h_)
#define _wxCmdLineParser_h_
class wxCmdLineParser
{
public:
   wxCmdLineParser() ;
   wxCmdLineParser(int  argc , char**  argv ) ;
   wxCmdLineParser(const wxString&  cmdline ) ;
   wxCmdLineParser(const wxCmdLineEntryDesc*  desc ) ;
   wxCmdLineParser(const wxCmdLineEntryDesc*  desc , int  argc , char**  argv ) ;
   wxCmdLineParser(const wxCmdLineEntryDesc*  desc , const wxString&  cmdline ) ;
  static wxArrayString ConvertStringToArgs(const wxChar  *cmdline ) ;
  void SetCmdLine(int  argc , char**  argv ) ;
  void SetCmdLine(const wxString&  cmdline ) ;
  virtual  ~wxCmdLineParser() ;
  void SetSwitchChars(const wxString&  switchChars ) ;
  void EnableLongOptions(bool  enable = true) ;
  void DisableLongOptions() ;
  bool AreLongOptionsEnabled() ;
  void SetLogo(const wxString&  logo ) ;
  void SetDesc(const wxCmdLineEntryDesc*  desc ) ;
  void AddSwitch(const wxString&  name , const wxString&  lng = wxEmptyString, const wxString&  desc = wxEmptyString, int  flags = 0) ;
  void AddOption(const wxString&  name , const wxString&  lng = wxEmptyString, const wxString&  desc = wxEmptyString, wxCmdLineParamType  type = wxCMD_LINE_VAL_STRING, int  flags = 0) ;
  void AddParam(const wxString&  desc = wxEmptyString, wxCmdLineParamType  type = wxCMD_LINE_VAL_STRING, int  flags = 0) ;
  int Parse(bool  giveUsage = true) ;
  void Usage() ;
  bool Found(const wxString&  name ) const;
  bool Found(const wxString&  name , wxString*  value ) const;
  bool Found(const wxString&  name , long*  value ) const;
  bool Found(const wxString&  name , wxDateTime*  value ) const;
  size_t GetParamCount() const;
  wxString GetParam(size_t  n = 0u) const;
};


#endif
