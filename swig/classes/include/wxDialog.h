// wxDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDialog_h_)
#define _wxDialog_h_
class wxDialog : public wxWindow
{
public:
   wxDialog() ;
   wxDialog(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = "dialogBox") ;
  virtual  ~wxDialog() ;
  void Centre(int direction = wxBOTH) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = "dialogBox") ;
  void EndModal(int  retCode ) ;
  int GetReturnCode() ;
  wxString GetTitle() const;
  void Iconize(const bool  iconize ) ;
  bool IsIconized() const;
  bool IsModal() const;
  //virtual void OnCharHook(wxKeyEvent&  event );
  virtual void OnApply(wxCommandEvent&  event ) ;
  virtual void OnCancel(wxCommandEvent&  event ) ;
  virtual void OnOK(wxCommandEvent&  event ) ;
  virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
  void SetIcon(const wxIcon&  icon ) ;
  void SetIcons(const wxIconBundle&  icons ) ;
  void SetModal(const bool  flag ) ;
  void SetReturnCode(int  retCode ) ;
  void SetTitle(const wxString&   title ) ;
  bool Show(const bool  show ) ;
  int ShowModal() ;
};


#endif
