/**********************************************************************

  textdroptarget.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS TextDropTarget : DropTarget
//$$ ABSTRACT
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxTextDropTarget();

virtual void GetData();
#virtual bool OnDrop(wxCoord x, wxCoord y, const void *data, size_t size)
#virtual bool OnDropText(wxCoord x, wxCoord y, const char* data);
abstract bool OnDropText(int x, int y, const wxString& data);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS

wxTextDropTargetHelper::wxTextDropTargetHelper(){};

void wxTextDropTargetHelper::SetSelf(VALUE self)
{
	me = self;
}

bool wxTextDropTargetHelper::OnDropText(wxCoord x, wxCoord y, const wxString& data)
{
	ID method = rb_intern("on_drop_text");
	
	VALUE ret = rb_funcall(me,method,3,INT2NUM(x),INT2NUM(y),rb_str_new2(data.c_str()));
	
	return (bool)NUM2INT(ret);
}

//$$ END_CPP_FILE
