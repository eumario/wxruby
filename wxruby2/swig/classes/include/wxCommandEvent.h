//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxCommandEvent_h_)
#define _wxCommandEvent_h_
class wxCommandEvent : public wxEvent
{
public:
   wxCommandEvent(WXTYPE commandEventType = 0, int id = 0) ;
  virtual ~wxCommandEvent();

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

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
