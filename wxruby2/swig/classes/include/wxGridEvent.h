//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxGridEvent_h_)
#define _wxGridEvent_h_
class wxGridEvent : public wxNotifyEvent
{
public:
   wxGridEvent() ;
   wxGridEvent(int  id , wxEventType  type , wxObject*  obj , int  row = -1, int  col = -1, int  x = -1, int  y = -1, bool  sel = true, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
  bool AltDown() ;
  bool ControlDown() ;
  virtual int GetCol() ;
  wxPoint GetPosition() ;
  virtual int GetRow() ;
  bool MetaDown() ;
  bool Selecting() ;
  bool ShiftDown() ;
	bool CmdDown();
	
	virtual wxEvent *Clone() const;
};


#endif
