/**********************************************************************

  htmlwindow.t -

  $Author$
  $Date$
  created at: 2004-08-03 15:50

  Copyright (C) 2004  Tobias Gruetzmacher

**********************************************************************/

//$$ CLASS HtmlWindow : ScrolledWindow
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  wxHtmlWindow(wxWindow *parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxHW_SCROLLBAR_AUTO, const wxString& name = "htmlWindow")

  bool SetPage(const wxString& source);
  bool AppendToPage(const wxString& source);
  virtual bool LoadPage(const wxString& location);
#(1)  bool LoadFile(const wxFileName& filename);
  wxString GetOpenedPage();
  wxString GetOpenedAnchor();
  wxString GetOpenedPageTitle();
  void SetRelatedFrame(wxFrame* frame, const wxString& format);
  wxFrame* GetRelatedFrame();
  void SetRelatedStatusBar(int bar);
  void SetFonts(wxString normal_face, wxString fixed_face, const int *sizes = NULL);
  void SetBorders(int b);
  virtual void ReadCustomization(wxConfigBase *cfg, wxString path = wxEmptyString);
  virtual void WriteCustomization(wxConfigBase *cfg, wxString path = wxEmptyString);
  bool HistoryBack();
  bool HistoryForward();
  bool HistoryCanBack();
  bool HistoryCanForward();
  void HistoryClear();
#(1)  wxHtmlContainerCell* GetInternalRepresentation();
  static void AddFilter(wxHtmlFilter *filter);
#(1)  wxHtmlWinParser *GetParser();
  void AddProcessor(wxHtmlProcessor *processor);
  static void AddGlobalProcessor(wxHtmlProcessor *processor);
  virtual bool AcceptsFocusFromKeyboard();
  virtual void OnSetTitle(const wxString& title);
#(1)  virtual void OnCellMouseHover(wxHtmlCell *cell, wxCoord x, wxCoord y);
#(1)  virtual void OnCellClicked(wxHtmlCell *cell, wxCoord x, wxCoord y, const wxMouseEvent& event);
#(1)  virtual void OnLinkClicked(const wxHtmlLinkInfo& link);
#(1)  virtual wxHtmlOpeningStatus OnOpeningURL(wxHtmlURLType WXUNUSED(type), const wxString& WXUNUSED(url), wxString *WXUNUSED(redirect));

//$$ METHODS_END

#(1) Other class not implemented in wxRuby

//$$ BEGIN_H_FILE
#include "wx/html/htmlwin.h"
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "frame.h"
#include "htmlprocessor.h"
#include "point.h"
#include "size.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
