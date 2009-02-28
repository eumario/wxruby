// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGridRangeSelectEvent_h_)
#define _wxGridRangeSelectEvent_h_
class wxGridRangeSelectEvent : public wxNotifyEvent
{
public:
   wxGridRangeSelectEvent() ;
   wxGridRangeSelectEvent(int  id , wxEventType  type , wxObject*  obj , const wxGridCellCoords&  topLeft , const wxGridCellCoords&  bottomRight , bool  sel = true, bool  control = false, bool  shift = false, bool  alt = false, bool  meta = false) ;
  bool AltDown() ;
  bool ControlDown() ;
  wxGridCellCoords GetBottomRightCoords() ;
  int GetBottomRow() ;
  int GetLeftCol() ;
  int GetRightCol() ;
  wxGridCellCoords GetTopLeftCoords() ;
  int GetTopRow() ;
  bool MetaDown() ;
  bool Selecting() ;
  bool ShiftDown() ;
	bool CmdDown();
	
	virtual wxEvent *Clone() const;
};


#endif
