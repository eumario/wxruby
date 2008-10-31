// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxCommandEvent_h_)
#define _wxCommandEvent_h_
class wxCommandEvent : public wxEvent
{
public:
   wxCommandEvent(WXTYPE commandEventType = 0, int id = 0) ;
  wxCommandEvent(const wxCommandEvent& event) ;
   
  virtual ~wxCommandEvent();

  bool Checked() const;
  void* GetClientData() ;
  long GetExtraLong() const;
  int GetInt() const;
  int GetSelection() const;
  wxString GetString() const;
  bool IsChecked() const;
  bool IsSelection() const;
  void SetClientData(void*  clientData ) ;
  void SetExtraLong(int  extraLong ) ;
  void SetInt(int  intCommand ) ;
  void SetString(const wxString&  string ) ;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
