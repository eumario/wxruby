/**********************************************************************

  htmleasyprinting.t -

  $Author$
  $Date$
  created at: 2004-08-03 18:10

  Copyright (C) 2004  Tobias Gruetzmacher

**********************************************************************/

//$$ CLASS HtmlEasyPrinting
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  wxHtmlEasyPrinting(const wxString& name = "Printing", wxFrame *parent_frame = NULL)

  bool PreviewFile(const wxString &htmlfile);
  bool PreviewText(const wxString &htmltext, const wxString& basepath = wxEmptyString);
  bool PrintFile(const wxString &htmlfile);
  bool PrintText(const wxString &htmltext, const wxString& basepath = wxEmptyString);
  void PrinterSetup();
  void PageSetup();
  void SetHeader(const wxString& header, int pg = wxPAGE_ALL);
  void SetFooter(const wxString& footer, int pg = wxPAGE_ALL);
#(1)  wxPrintData *GetPrintData();
#(1)  wxPageSetupDialogData *GetPageSetupData();

//$$ METHODS_END

#(1) Other class not implemented in wxRuby

//$$ BEGIN_H_FILE
#include "wx/html/htmprint.h"
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "frame.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
