// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxProgressDialog_h_)
#define _wxProgressDialog_h_
class wxProgressDialog : public wxFrame
{
public:
  wxProgressDialog(const wxString &title, 
                   wxString const &message, 
                   int maximum = 100, 
                   wxWindow *parent = NULL, 
                   int style = wxPD_APP_MODAL|wxPD_AUTO_HIDE);
  virtual  ~wxProgressDialog();
  void Resume() ;
  virtual bool Pulse(const wxString& newmsg = wxEmptyString, 
                     bool *skip = NULL);
  virtual bool Update(int value, const wxString& newmsg = wxEmptyString, 
                      bool *skip = NULL);
};


#endif
