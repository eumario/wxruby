// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDialog_h_)
#define _wxDialog_h_

class wxDialog : public wxTopLevelWindow
{
public:
   wxDialog() ;
   wxDialog(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = wxT("dialogBox")) ;
  virtual  ~wxDialog() ;
  void Centre(int direction = wxBOTH) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE, const wxString&  name = wxT("dialogBox")) ;
  wxSizer* CreateButtonSizer(long flags);
  wxSizer* CreateSeparatedButtonSizer(long flags);
  wxStdDialogButtonSizer* CreateStdDialogButtonSizer(long flags);
  virtual void EndModal(int  retCode ) ;
  int GetAffirmativeId() const;
  int GetEscapeId() const;
  int GetReturnCode() ;
  void Iconize(const bool  iconize ) ;
  bool IsIconized() const;
  virtual bool IsModal() const;
  //virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
  void SetAffirmativeId(int id);
  void SetEscapeId(int id);
  void SetIcon(const wxIcon&  icon ) ;
  void SetIcons(const wxIconBundle&  icons ) ;
  void SetReturnCode(int  retCode ) ;
  virtual bool Show(bool show = true ) ;
  virtual int ShowModal() ;
};


#endif
