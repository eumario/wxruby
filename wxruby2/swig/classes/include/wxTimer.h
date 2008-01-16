// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTimer_h_)
#define _wxTimer_h_
class wxTimer : public wxEvtHandler
{
public:
  wxTimer();
  wxTimer(wxEvtHandler * owner , int  id = -1);
  virtual  ~wxTimer();
  int GetId() const;
  int GetInterval() const;
  bool IsOneShot() const;
  bool IsRunning() const;
  virtual void Notify();
  void SetOwner(wxEvtHandler * owner, int id = -1);
  bool Start(int milliseconds = -1, bool oneShot = false);
  void Stop();
};


#endif
