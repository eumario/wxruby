// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxHtmlWindow_h_)
#define _wxHtmlWindow_h_
class wxHtmlWindow : public wxScrolledWindow,public wxHtmlWindowMouseHelper
{
public:
   wxHtmlWindow() ;
   wxHtmlWindow(wxWindow  *parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxHW_SCROLLBAR_AUTO, const wxString&  name = wxT("htmlWindow")) ;
  static void AddFilter(wxHtmlFilter  *filter ) ;
  bool AppendToPage(const wxString&  source ) ;
  wxHtmlContainerCell* GetInternalRepresentation() const;
  wxString GetOpenedAnchor() ;
  wxString GetOpenedPage() ;
  wxString GetOpenedPageTitle() ;
  wxFrame* GetRelatedFrame() const;
  bool HistoryBack() ;
  bool HistoryCanBack() ;
  bool HistoryCanForward() ;
  void HistoryClear() ;
  bool HistoryForward() ;
  virtual bool LoadFile(const wxFileName&  filename ) ;
  virtual bool LoadPage(const wxString&  location ) ;
  virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType  type , const wxString&  url , wxString * redirect ) const;
  virtual void OnSetTitle(const wxString&  title ) ;
  virtual void ReadCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
  void SelectAll();
  wxString SelectionToText();
  void SelectLine(const wxPoint& pos);
  void SelectWord(const wxPoint& pos);
  void SetBorders(int b);
  void SetFonts(wxString& normal_face, wxString& fixed_face, const int *sizes = NULL) ;
  bool SetPage(const wxString&  source ) ;
  void SetRelatedFrame(wxFrame*  frame , const wxString&  format ) ;
  void SetRelatedStatusBar(int  bar ) ;
  virtual void WriteCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
};


#endif
