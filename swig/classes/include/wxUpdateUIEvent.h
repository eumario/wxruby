// wxUpdateUIEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxUpdateUIEvent_h_)
#define _wxUpdateUIEvent_h_
class wxUpdateUIEvent : public wxCommandEvent
{
public:
   wxUpdateUIEvent(wxWindowID  commandId = 0) ;
  void Check(bool  check ) ;
  void Enable(bool  enable ) ;
  bool GetChecked() const;
  bool GetEnabled() const;
  bool GetSetChecked() const;
  bool GetSetEnabled() const;
  bool GetSetText() const;
  wxString GetText() const;
  void SetText(const wxString&  text ) ;
  // the following were missing from the xml
  virtual ~wxUpdateUIEvent();
};


#endif
