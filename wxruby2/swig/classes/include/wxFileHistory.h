// wxFileHistory.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileHistory_h_)
#define _wxFileHistory_h_
class wxFileHistory : public wxObject
{
public:
   wxFileHistory(size_t maxFiles = 9, wxWindowID idBase = wxID_FILE1) ;
  virtual  ~wxFileHistory() ;
  void AddFileToHistory(const wxString&  filename ) ;
  void AddFilesToMenu() ;
  void AddFilesToMenu(wxMenu*  menu ) ;
  wxString GetHistoryFile(size_t  index ) const;
  size_t GetMaxFiles() const;
  size_t GetNoHistoryFiles() const;
  void Load(wxConfigBase&  config ) ;
  void RemoveMenu(wxMenu*  menu ) ;
  void Save(wxConfigBase&  config ) ;
  void UseMenu(wxMenu*  menu ) ;
};


#endif
