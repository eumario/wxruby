/**********************************************************************

  frame.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Frame : Window
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ METHODS_BEGIN
  wxFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = "frame")
  
  void Centre(int direction = wxBOTH);
  void Command(int id);
  bool Create(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString& name = ``frame");
  virtual wxStatusBar* CreateStatusBar(int number = 1, long style = 0, wxWindowID id = -1, const wxString& name = "statusBar");
  virtual wxToolBar* CreateToolBar(long style = wxNO_BORDER | wxTB_HORIZONTAL, wxWindowID id = -1, const wxString& name = "toolBar");
  wxPoint GetClientAreaOrigin();
  wxMenuBar* GetMenuBar();
  wxStatusBar* GetStatusBar();
  int GetStatusBarPane();
  wxString GetTitle();
  wxToolBar* GetToolBar();
  void Iconize(bool iconize);
  bool IsFullScreen();
  bool IsIconized();
  bool IsMaximized();
  void Maximize(bool maximize);
  void OnActivate(wxActivateEvent& event);
  virtual wxStatusBar* OnCreateStatusBar(int number, long style, wxWindowID id, const wxString& name);
  virtual wxToolBar* OnCreateToolBar(long style, wxWindowID id, const wxString& name);
  void OnMenuHighlight(wxMenuEvent& event);
  void OnSize(wxSizeEvent& event);
  void SendSizeEvent();
  void SetIcon(const wxIcon& icon);
  void SetIcons(const wxIconBundle& icons);
  void SetMenuBar(wxMenuBar* menuBar);
  void SetStatusBar(wxStatusBar* statusBar);
  void SetStatusBarPane(int n);
  virtual void SetStatusText(const wxString& text, int number = 0);
  virtual void SetStatusWidths(int widths[]);
  void SetToolBar(wxToolBar* toolBar);
  virtual void SetTitle(const wxString& title);
  bool ShowFullScreen(bool show, long style = wxFULLSCREEN_ALL);
//$$ METHODS_END



//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "statusbar.h"
#include "menubar.h"
#include "toolbar.h"
#include "point.h"

//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE
