// wxProgressDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProgressDialog_h_)
#define _wxProgressDialog_h_
class wxProgressDialog : public wxFrame
{
public:
   wxProgressDialog(const wxString&  title , const wxString&  message , int  maximum = 100, wxWindow *  parent = NULL, int  style = wxPD_AUTO_HIDE) ;
  virtual  ~wxProgressDialog() ;
  void Resume() ;
  bool Update(int  value , const wxString&  newmsg = "") ;
};


#endif
