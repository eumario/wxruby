// wxAccessible.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAccessible_h_)
#define _wxAccessible_h_
class wxAccessible : public wxObject
{
public:
   wxAccessible(wxWindow*  win = NULL) ;
  virtual  ~wxAccessible() ;
  virtual wxAccStatus DoDefaultAction(int  childId ) ;
  virtual wxAccStatus GetChild(int  childId , wxAccessible**  child ) ;
  virtual wxAccStatus GetChildCount(int*  childCount ) ;
  virtual wxAccStatus GetDefaultAction(int  childId , wxString*  actionName ) ;
  virtual wxAccStatus GetDescription(int  childId , wxString*  description ) ;
  virtual wxAccStatus GetFocus(int*  childId , wxAccessible**  child ) ;
  virtual wxAccStatus GetHelpText(int  childId , wxString*  helpText ) ;
  virtual wxAccStatus GetKeyboardShortcut(int  childId , wxString*  shortcut ) ;
  virtual wxAccStatus GetLocation(wxRect&  rect , int  elementId ) ;
  virtual wxAccStatus GetName(int  childId , wxString*  name ) ;
  virtual wxAccStatus GetParent(wxAccessible**  parent ) ;
  virtual wxAccStatus GetRole(int  childId , wxAccRole*  role ) ;
  virtual wxAccStatus GetSelections(wxVariant*  selections ) ;
  virtual wxAccStatus GetState(int  childId , long*  state ) ;
  virtual wxAccStatus GetValue(int  childId , wxString*  strValue ) ;
  wxWindow* GetWindow() ;
  virtual wxAccStatus HitTest(const wxPoint&  pt , int*  childId , wxAccessible**  childObject ) ;
  virtual wxAccStatus Navigate(wxNavDir  navDir , int  fromId , int*  toId , wxAccessible**  toObject ) ;
  virtual static void NotifyEvent(int  eventType , wxWindow*  window , wxAccObjectt  objectType , int  objectType ) ;
  virtual wxAccStatus Select(int  childId , wxAccSelectionFlags  selectFlags ) ;
  void SetWindow(wxWindow*  window ) ;
};


#endif
