/**********************************************************************

  filedroptarget.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS FileDropTarget : DropTarget
//$$ ABSTRACT
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
wxFileDropTarget();

virtual void GetData();
#virtual bool OnDrop(wxCoord x, wxCoord y, const void *data, size_t size);
abstract bool OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames);
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS

wxFileDropTargetHelper::wxFileDropTargetHelper(){};

void wxFileDropTargetHelper::SetSelf(VALUE self)
{
	me = self;
}

bool wxFileDropTargetHelper::OnDropFiles(wxCoord x, wxCoord y, const wxArrayString& filenames)
{
	VALUE arr = rb_ary_new();
	int numfiles=filenames.GetCount();
	for(int i = 0; i < numfiles; i++)
		rb_ary_push(arr,rb_str_new2(filenames[i].c_str()));
	ID method = rb_intern("on_drop_files");
	VALUE ret = rb_funcall(me,method,3,INT2NUM(x),INT2NUM(y),arr);
    return IsTrue(ret);
}

//$$ END_CPP_FILE
