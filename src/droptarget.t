/**********************************************************************

  droptarget.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DropTarget
//$$ NO_CLIENT_DATA 
//$$ ABSTRACT

//$$ METHODS_BEGIN
wxDropTarget(wxDataObject *data=NULL);

virtual void GetData();
abstract virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def);
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

wxDropTargetHelper::wxDropTargetHelper(wxDataObject* data) :
    wxDropTarget(data)
{
}

void wxDropTargetHelper::SetSelf(VALUE self)
{
	me = self;
}

wxDragResult wxDropTargetHelper::OnData(wxCoord x, wxCoord y, wxDragResult def)
{
	ID method = rb_intern("on_data");
	
	VALUE ret = rb_funcall(me,method,3,INT2NUM(x),INT2NUM(y),INT2NUM(def));
	
	return (wxDragResult)NUM2INT(ret);
}

//$$ END_CPP_FILE
