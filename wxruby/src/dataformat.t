/**********************************************************************

  dataformat.t -

  $Author$
  $Date$

**********************************************************************/

//$$ CLASS DataFormat
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/dnd.h>
class WxDataFormat
{
public:
//$$ RB_DECLARE
	static VALUE init0(wxDataFormat cppObject);
};
//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS

VALUE WxDataFormat::init0(wxDataFormat cppObject)
{
    wxDataFormat* clone = new wxDataFormat(cppObject);
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = clone;
    return self;
}

//$$ END_CPP_FILE
