// wxGridEditorCreatedEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridEditorCreatedEvent_h_)
#define _wxGridEditorCreatedEvent_h_
class wxGridEditorCreatedEvent : public wxCommandEvent
{
public:
   wxGridEditorCreatedEvent() ;
   wxGridEditorCreatedEvent(int  id , wxEventType  type , wxObject*  obj , int  row , int  col , wxControl*  ctrl ) ;
  int GetCol() ;
  wxControl* GetControl() ;
  int GetRow() ;
  void SetCol(int  col ) ;
  void SetControl(wxControl*  ctrl ) ;
  void SetRow(int  row ) ;
};


#endif
