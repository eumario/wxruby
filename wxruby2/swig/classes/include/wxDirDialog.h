// wxDirDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDirDialog_h_)
#define _wxDirDialog_h_
class wxDirDialog : public wxDialog
{
public:
   wxDirDialog(wxWindow*  parent , const wxString&  message = "Choose", const wxString&  defaultPath = "", long  style = 0, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, const wxString&  name = "wxDirCtrl") ;
  virtual  ~wxDirDialog() ;
  wxString GetPath() const;
  wxString GetMessage() const;
  long GetStyle() const;
  void SetMessage(const wxString&  message ) ;
  void SetPath(const wxString&  path ) ;
  void SetStyle(long  style ) ;
  int ShowModal() ;
};


#endif
