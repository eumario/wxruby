// wxCommandEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommandEvent_h_)
#define _wxCommandEvent_h_
class wxCommandEvent : public wxEvent
{
public:
   wxCommandEvent(WXTYPE commandEventType = 0, int id = 0) ;
  bool Checked() const;
  void* GetClientData() ;
  long GetExtraLong() ;
  int GetInt() ;
  int GetSelection() ;
  wxString GetString() ;
  bool IsChecked() const;
  bool IsSelection() ;
  void SetClientData(void*  clientData ) ;
  void SetExtraLong(int  extraLong ) ;
  void SetInt(int  intCommand ) ;
  void SetString(const wxString&  string ) ;
  // the following were missing from the xml
  virtual ~wxCommandEvent();
};


#endif
