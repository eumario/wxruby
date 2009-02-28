// wxFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFrame_h_)
#define _wxFrame_h_
class wxFrame : public wxTopLevelWindow
{
public:
   wxFrame() ;
   wxFrame(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
  virtual  ~wxFrame() ;
  void Centre(int direction = wxBOTH) ;
  void Command(int  id ) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
  virtual wxStatusBar* CreateStatusBar(int number = 1, long style = 0, wxWindowID id = -1, const wxString& name = wxT("statusBar")) ;
  virtual wxToolBar* CreateToolBar(long style = wxNO_BORDER, wxWindowID id = -1, const wxString& name = wxT("toolBar")) ;
  wxPoint GetClientAreaOrigin() const;
  wxMenuBar* GetMenuBar() const;
  wxStatusBar* GetStatusBar() const;
  int GetStatusBarPane() ;
  wxString GetTitle() const;
  wxToolBar* GetToolBar() const;
  void Iconize(bool  iconize ) ;
  bool IsFullScreen() ;
  bool IsIconized() const;
  bool IsMaximized() const;
  void Maximize(bool  maximize ) ;
  virtual wxStatusBar* OnCreateStatusBar(int  number , long  style , wxWindowID  id , const wxString&  name ) ;
  virtual wxToolBar* OnCreateToolBar(long  style , wxWindowID  id , const wxString&  name ) ;
  void SendSizeEvent() ;
  void SetIcon(const wxIcon&  icon ) ;
  void SetIcons(const wxIconBundle&  icons ) ;
  void SetMenuBar(wxMenuBar*  menuBar ) ;
  bool SetShape(const wxRegion&  region ) ;
  void SetStatusBar(wxStatusBar*  statusBar ) ;
  void SetStatusBarPane(int  n ) ;
  virtual void SetStatusText(const wxString&   text , int number = 0) ;
  virtual void SetStatusWidths(int  n , int * widths ) ;
  void SetToolBar(wxToolBar*  toolBar ) ;
  virtual void SetTitle(const wxString&   title ) ;
  virtual bool Show(bool show = true);
  bool ShowFullScreen(bool  show , long style = wxFULLSCREEN_ALL) ;
};


#endif
