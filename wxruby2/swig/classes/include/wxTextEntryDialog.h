// wxTextEntryDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextEntryDialog_h_)
#define _wxTextEntryDialog_h_
class wxTextEntryDialog : public wxDialog
{
public:
   wxTextEntryDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption = "Please, const wxString&  defaultValue = "", long  style = wxOK, const wxPoint&  pos = wxDefaultPosition) ;
  virtual  ~wxTextEntryDialog() ;
  wxString GetValue() const;
  void SetValue(const wxString&  value ) ;
  int ShowModal() ;
};


#endif
