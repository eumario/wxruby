// wxHtmlHelpController.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpController_h_)
#define _wxHtmlHelpController_h_
class wxHtmlHelpController
{
public:
   wxHtmlHelpController(int  style = wxHF_DEFAULT_STYLE) ;
  bool AddBook(const wxFileName&  book_file , bool  show_wait_msg ) ;
  bool AddBook(const wxString&  book_url , bool  show_wait_msg ) ;
  virtual wxHtmlHelpFrame* CreateHelpFrame(wxHtmlHelpData *  data ) ;
  void Display(const wxString&  x ) ;
  void Display(const int  id ) ;
  void DisplayContents() ;
  void DisplayIndex() ;
  bool KeywordSearch(const wxString&  keyword ) ;
  void ReadCustomization(wxConfigBase*  cfg , wxString  path = wxEmptyString) ;
  void SetTempDir(const wxString&  path ) ;
  void SetTitleFormat(const wxString&  format ) ;
  void UseConfig(wxConfigBase*  config , const wxString&  rootpath = wxEmptyString) ;
  void WriteCustomization(wxConfigBase*  cfg , wxString  path = wxEmptyString) ;
};


#endif
