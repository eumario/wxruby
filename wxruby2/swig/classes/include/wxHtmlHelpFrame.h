// wxHtmlHelpFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpFrame_h_)
#define _wxHtmlHelpFrame_h_
class wxHtmlHelpFrame : public wxFrame
{
public:
   wxHtmlHelpFrame(wxHtmlHelpData*  data = NULL) ;
   wxHtmlHelpFrame(wxWindow*  parent , int  wxWindowID , const wxString&  title = wxEmptyString, int  style = wxHF_DEFAULT_STYLE, wxHtmlHelpData*  data = NULL) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title = wxEmptyString, int  style = wxHF_DEFAULT_STYLE) ;
  void CreateContents(bool  show_progress = false) ;
  void CreateIndex(bool  show_progress = false) ;
  void CreateSearch() ;
  bool Display(const wxString&  x ) ;
  bool Display(const int  id ) ;
  bool DisplayContents() ;
  bool DisplayIndex() ;
  wxHtmlHelpData* GetData() ;
  bool KeywordSearch(const wxString&  keyword ) ;
  void ReadCustomization(wxConfigBase*  cfg , const wxString&  path = wxEmptyString) ;
  void RefreshLists(bool  show_progress = false) ;
  void SetTitleFormat(const wxString&  format ) ;
  void UseConfig(wxConfigBase*  config , const wxString&  rootpath = wxEmptyString) ;
  void WriteCustomization(wxConfigBase*  cfg , const wxString&  path = wxEmptyString) ;
  virtual void AddToolbarButtons(wxToolBar * toolBar , int  style ) ;
};


#endif
