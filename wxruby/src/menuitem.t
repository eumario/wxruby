/**********************************************************************

  menuitem.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS MenuItem
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  wxMenuItem(wxMenu* parentMenu = NULL, int id = wxID_SEPARATOR, const wxString& text = "", const wxString& helpString = "", wxItemKind kind = wxITEM_NORMAL, wxMenu* subMenu = NULL);

  void Check(bool check);
#  void DeleteSubMenu();
  void Enable(bool enable);
#  wxColour& GetBackgroundColour();
  wxBitmap& GetBitmap();
#  wxFont& GetFont();
  wxString GetHelp();
  int GetId();
  wxItemKind GetKind();
  wxString GetLabel();
  static wxString GetLabelFromText(const wxString& text);
#  int GetMarginWidth();
#OBSOLETE  wxString GetName();
  wxString GetText();
#  wxMenu* GetSubMenu();
#  wxColour& GetTextColour();
  bool IsCheckable();
  bool IsChecked();
  bool IsEnabled();
  bool IsSeparator();
#  void SetBackgroundColour(const wxColour& colour);
  void SetBitmap(const wxBitmap& bmp);
#  void SetBitmaps(const wxBitmap& checked, const wxBitmap& unchecked = wxNullBitmap);
#  void SetFont(const wxFont& font);
  void SetHelp(const wxString& helpString);
#  void SetMarginWidth(int width);
  void SetText(const wxString& text);
#  void SetTextColour(const wxColour& colour);

//$$ METHODS_END



//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "wx/menuitem.h"
#include "bitmap.h"
#include "colour.h"
#include "font.h"
#include "menu.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
