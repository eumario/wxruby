/**********************************************************************

  droptarget.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DropTarget
//$$ NO_CLIENT_DATA 

//$$ METHODS_BEGIN
wxDropTarget(wxDataObject *data=NULL);

virtual void GetData();
virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def);
virtual bool OnDrop(wxCoord x, wxCoord y);
virtual wxDragResult OnEnter(wxCoord x, wxCoord y, wxDragResult def);
virtual wxDragResult OnDragOver(wxCoord x, wxCoord y, wxDragResult def);
virtual void OnLeave();
void SetDataObject(wxDataObject* data);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
