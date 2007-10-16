// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
  bool GetSetShown() const;
  bool GetShown() const;
  static long GetUpdateInterval();
  wxString GetText() const;
  static void ResetUpdateTime();
  static void SetMode(wxUpdateUIMode mode);
  void SetText(const wxString&  text );
  static void SetUpdateInterval(long updateInterval);
  void Show(bool show);
};


#endif
