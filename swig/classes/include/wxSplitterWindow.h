// wxSplitterWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSplitterWindow_h_)
#define _wxSplitterWindow_h_
class wxSplitterWindow : public wxWindow
{
public:
   wxSplitterWindow() ;
   wxSplitterWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_3D, const wxString& name = "splitterWindow") ;
  virtual  ~wxSplitterWindow() ;
  bool Create(wxWindow*  parent , wxWindowID  id , int  x , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_3D, const wxString& name = "splitterWindow") ;
  int GetMinimumPaneSize() const;
  int GetSashPosition() ;
  int GetSplitMode() const;
  wxWindow* GetWindow1() const;
  wxWindow* GetWindow2() const;
  void Initialize(wxWindow*  window ) ;
  bool IsSplit() const;
  virtual void OnDoubleClickSash(int  x , int  y ) ;
  virtual void OnUnsplit(wxWindow*  removed ) ;
  virtual bool OnSashPositionChange(int  newSashPosition ) ;
  bool ReplaceWindow(wxWindow *  winOld , wxWindow *  winNew ) ;
  void SetSashPosition(int  position , const bool redraw = true) ;
  void SetMinimumPaneSize(int  paneSize ) ;
  void SetSplitMode(int  mode ) ;
  bool SplitHorizontally(wxWindow*  window1 , wxWindow*  window2 , int sashPosition = 0) ;
  bool SplitVertically(wxWindow*  window1 , wxWindow*  window2 , int sashPosition = 0) ;
  bool Unsplit(wxWindow*  toRemove = NULL) ;
};


#endif
