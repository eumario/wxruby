// wxHtmlWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlWindow_h_)
#define _wxHtmlWindow_h_
class wxHtmlWindow : public wxScrolledWindow
{
public:
   wxHtmlWindow() ;
   wxHtmlWindow(wxWindow  *parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxHW_SCROLLBAR_AUTO, const wxString&  name = "htmlWindow") ;
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
  virtual void OnCellClicked(wxHtmlCell  *cell , wxCoord  x , wxCoord  y , const wxMouseEvent&  event ) ;
  virtual void OnCellMouseHover(wxHtmlCell  *cell , wxCoord  x , wxCoord  y ) ;
  virtual void OnLinkClicked(const wxHtmlLinkInfo&  link ) ;
  virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType  type , const wxString&  url , wxString * redirect ) ;
  virtual void OnSetTitle(const wxString&  title ) ;
  virtual void ReadCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
  void SetBorders(int  b ) ;
  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
  bool SetPage(const wxString&  source ) ;
  void SetRelatedFrame(wxFrame*  frame , const wxString&  format ) ;
  void SetRelatedStatusBar(int  bar ) ;
  virtual void WriteCustomization(wxConfigBase  *cfg , wxString  path = wxEmptyString) ;
};


#endif
