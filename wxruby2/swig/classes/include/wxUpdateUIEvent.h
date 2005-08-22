//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxUpdateUIEvent_h_)
#define _wxUpdateUIEvent_h_
class wxUpdateUIEvent : public wxCommandEvent
{
public:
   wxUpdateUIEvent(wxWindowID  commandId = 0) ;
  virtual ~wxUpdateUIEvent();
  void Check(bool  check ) ;
  void Enable(bool  enable ) ;
  bool GetChecked() const;
  bool GetEnabled() const;
  bool GetSetChecked() const;
  bool GetSetEnabled() const;
  bool GetSetText() const;
  wxString GetText() const;
  void SetText(const wxString&  text ) ;
};


#endif
