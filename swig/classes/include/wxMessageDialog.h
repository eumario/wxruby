// wxMessageDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMessageDialog_h_)
#define _wxMessageDialog_h_
class wxMessageDialog : public wxDialog
{
public:
   wxMessageDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption = "Message", long  style = wxOK, const wxPoint&  pos = wxDefaultPosition) ;
  virtual  ~wxMessageDialog() ;
  int ShowModal() ;
};


#endif
