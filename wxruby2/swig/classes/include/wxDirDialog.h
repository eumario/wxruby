// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDirDialog_h_)
#define _wxDirDialog_h_

class wxDirDialog : public wxDialog
{
public:
   wxDirDialog(wxWindow*  parent , const wxString&  message = wxT("Choose"), const wxString&  defaultPath = wxT(""), long  style = 0, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, const wxString&  name = wxT("wxDirCtrl")) ;
  virtual  ~wxDirDialog() ;
  wxString GetPath() const;
  wxString GetMessage() const;
  void SetMessage(const wxString&  message ) ;
  void SetPath(const wxString&  path ) ;
  int ShowModal() ;
};


#endif
