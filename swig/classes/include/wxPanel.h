// Copyright 2004-2008 , wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPanel_h_)
#define _wxPanel_h_
class wxPanel : public wxWindow
{
public:
  wxPanel();
  wxPanel(wxWindow* parent, 
          wxWindowID id = -1, 
          const wxPoint& pos = wxDefaultPosition, 
          const wxSize& size = wxDefaultSize, 
          long style = wxTAB_TRAVERSAL|wxNO_BORDER, 
          const wxString& name = wxT("panel")) ;
  virtual  ~wxPanel() ;
  bool Create(wxWindow* parent, 
              wxWindowID id, 
              const wxPoint& pos = wxDefaultPosition, 
              const wxSize& size = wxDefaultSize, 
              long style = wxTAB_TRAVERSAL, 
              const wxString& name = wxT("panel")) ;
  void InitDialog();
  virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
  virtual void SetFocus();
  virtual void SetFocusIgnoringChildren();
};


#endif
