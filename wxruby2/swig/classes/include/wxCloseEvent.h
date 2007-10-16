// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxCloseEvent_h_)
#define _wxCloseEvent_h_
class wxCloseEvent : public wxEvent
{
public:
   wxCloseEvent(WXTYPE commandEventType = 0, int id = 0) ;
  virtual ~wxCloseEvent();
  bool CanVeto() ;
  bool GetLoggingOff() const;
  bool GetSessionEnding() const;
  bool GetForce() const;
  void SetCanVeto(bool  canVeto ) ;
  void SetForce(bool  force ) const;
  void SetLoggingOff(bool  loggingOff );
  void Veto(bool veto = true) ;

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;
};


#endif
