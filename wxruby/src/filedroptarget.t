/**********************************************************************

  filedroptarget.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS FileDropTarget : DropTarget
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxFileDropTarget();

virtual void GetData();
virtual bool OnDrop(wxCoord x, wxCoord y, const void *data, size_t size);
virtual bool OnDropText(wxCoord x, wxCoord y, const wxArrayString& filenames);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
////$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE


