// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxControl_h_)
#define _wxControl_h_
class wxControl : public wxWindow
{
public:
  wxControl();
  virtual ~wxControl();
  void Command(wxCommandEvent&  event ) ;
  virtual wxString GetLabel() const;
  virtual void SetLabel(const wxString&  label ) ;
};


#endif
