// wxPanel.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPanel_h_)
#define _wxPanel_h_
class wxPanel : public wxWindow
{
public:
  //wxPanel();
   wxPanel(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString&  name = "panel") ;
  virtual  ~wxPanel() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString&  name = "panel") ;
  wxButton* GetDefaultItem() const;
  void InitDialog() ;
  virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
  void SetDefaultItem(wxButton  *btn ) ;
};


#endif
