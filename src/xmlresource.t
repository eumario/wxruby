/**********************************************************************

  xrc.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Nicolas Kral

**********************************************************************/

//$$ CLASS XmlResource

//$$ METHODS_BEGIN
static wxXmlResource *Get();
#static int GetXRCID(const char *temp);
wxDialog *LoadDialog(wxWindow *parent, wxString& name);
bool LoadDialog(wxDialog *dlg, wxWindow *parent, const wxString &name);->LoadDialogSubclass
wxPanel *LoadPanel(wxWindow *parent, const wxString &name);
bool LoadPanel(wxPanel *pan, wxWindow *parent, wxString &name);->LoadPanelSubclass
wxFrame *LoadFrame(wxWindow* parent, const wxString& name);
bool LoadFrame(wxFrame *frame, wxWindow *parent, const wxString &name);->LoadFrameSubclass
long GetVersion();
bool Load(const wxString &filename);
void InitAllHandlers();
//$$ METHODS_END

//$$ BEGIN_H_FILE
#include <wx/xrc/xmlres.h>
#include "panel.h"
#include "dialog.h"
#include "frame.h"



class WxXmlResource {
public:
    //$$ RB_DECLARE
    static VALUE init0(wxXmlResource *);
    static VALUE s_GetXRCID(VALUE cls, VALUE other);
};

//$$ END_H_FILE

//$$ BEGIN_CPP_FILE


void WxXmlResource::DefineClass()
{
    //$$ RB_DEFINE

    rb_define_singleton_method(rubyClass,"get_xrcid",VALUEFUNC(s_GetXRCID),1);
    rb_define_module_function(GetWxModule(),"xrcid",VALUEFUNC(s_GetXRCID),1);
}

//$$ RB_IMPLEMENT


VALUE WxXmlResource::s_GetXRCID(VALUE css, VALUE other)
{
	char *tmp = STR2CSTR(other);
	int ret;
	VALUE retval;

	ret = wxXmlResource::GetXRCID((const wxChar *)tmp);

	retval = INT2NUM(ret);

	return retval;
}
VALUE WxXmlResource::init0(wxXmlResource *cppObject)
{
    if(cppObject==NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = cppObject;
    return self;
}


//$$ END_CPP_FILE
