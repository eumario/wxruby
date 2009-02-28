// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridSizeEvent_h_)
#define _wxGridSizeEvent_h_
class wxGridSizeEvent : public wxNotifyEvent
{
public:
   wxGridSizeEvent() ;
   wxGridSizeEvent(int  id , wxEventType  type , wxObject*  obj , int  rowOrCol = -1, int  x = -1, int  y = -1, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
  bool AltDown() ;
  bool ControlDown() ;
  wxPoint GetPosition() ;
  int GetRowOrCol() ;
  bool MetaDown() ;
  bool ShiftDown() ;
	bool CmdDown();
	
	virtual wxEvent *Clone() const;
};


#endif
