/**********************************************************************

  validator.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "window.h"
#include "validator.h"

wxRbValidator::wxRbValidator(const wxRbValidator& original)
{
    printf("wxRbValidator copy constructor called\n");
}

wxObject *
wxRbValidator::Clone() const
{
    wxRbValidator *ptr = NULL;
    VALUE klass = rb_funcall(self,rb_intern("copy"),0);
    Data_Get_Struct(klass, wxRbValidator, ptr);
    ptr->SetWindow(GetWindow());
    return (wxObject*)ptr;
}

bool
wxRbValidator::TransferFromWindow()
{
  bool value = FALSE;
  if(rb_respond_to(self, rb_intern("transfer_from_window"))) {
    value = (rb_funcall(self,rb_intern("transfer_from_window"),0) == Qtrue);
  }
  return value;
}

bool
wxRbValidator::TransferToWindow()
{
  bool value = FALSE;
  if(rb_respond_to(self, rb_intern("transfer_to_window"))) {
    value = (rb_funcall(self,rb_intern("transfer_to_window"),0) == Qtrue);
  }
  return value;
}


bool
wxRbValidator::Validate(wxWindow* parent)
{
  bool value = FALSE;
  VALUE ptr = WxWindow::init0(parent);
  if(rb_respond_to(self, rb_intern("validate"))) {
    value = (rb_funcall(self,rb_intern("validate"),1,ptr) == Qtrue);
  }
  return value;
}


//----------------------------------------------------------------------------------------
void WxValidator::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Validator", rb_cObject);
	rb_define_alloc_func(rubyClass,WxValidator::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(wrapNew), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxValidator::init), 0);
	rb_define_method(rubyClass, "get_window", VALUEFUNC(WxValidator::GetWindow), 0);
	rb_define_method(rubyClass, "set_bell_on_error", VALUEFUNC(WxValidator::SetBellOnError), -1);
}

VALUE
WxValidator::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxValidator::wrapNew(int argc, VALUE *argv, VALUE self)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, argc, argv);
    return res;
}


VALUE
WxValidator::init(VALUE self)
{
    wxRbValidator *ptr;
    Data_Get_Struct(self, wxRbValidator, ptr);
    ptr = new wxRbValidator(self);
    DATA_PTR(self) = ptr;

  	MapRubyObjectToCppObject(self, ptr);

    return self;
}

VALUE
WxValidator::GetWindow(VALUE self)
{
    wxRbValidator *ptr;
    Data_Get_Struct(self, wxRbValidator, ptr);
    wxWindow* window = ptr->GetWindow();
    return WxRbTypeTable::ConvertCppObject(window);
}

void
WxValidator::SetBellOnError(int argc, VALUE *argv, VALUE self)
{
    bool doIt = TRUE;
    if(argc>0 && argv[0]==Qfalse) doIt = FALSE;
    wxRbValidator *ptr;
    Data_Get_Struct(self, wxRbValidator, ptr);
    ptr->SetBellOnError(doIt);
}

VALUE
WxValidator::init0(wxValidator *validator)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = validator;
    return self;
}

VALUE WxValidator::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxValidator::DefineClass();
    }
};
static ZAutoDefine x;
