/**********************************************************************

  dropsource.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DropSource
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxDropSource(wxWindow* win = NULL);

void SetData(wxDataObject &data);
virtual wxDragResult DoDragDrop(int flags = wxDrag_CopyOnly);
//$$ METHODS_END 

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE
 

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS

//$$ END_CPP_FILE 

