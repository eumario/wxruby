// wxCloseEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCloseEvent_h_)
#define _wxCloseEvent_h_
class wxCloseEvent : public wxEvent
{
public:
   wxCloseEvent(WXTYPE commandEventType = 0, int id = 0) ;
  bool CanVeto() ;
  bool GetLoggingOff() const;
  bool GetSessionEnding() const;
  bool GetForce() const;
  void SetCanVeto(bool  canVeto ) ;
  void SetForce(bool  force ) const;
  void SetLoggingOff(bool  loggingOff );
  void Veto(bool veto = true) ;
  // the following were missing from the xml
  virtual ~wxCloseEvent();
};


#endif
