/**********************************************************************

  layout.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "layout.h"

void WxIndividualLayoutConstraint::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"IndividualLayoutConstraint", rb_cObject);
	rb_define_alloc_func(rubyClass,WxIndividualLayoutConstraint::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxIndividualLayoutConstraint::init), 0);
	rb_define_method(rubyClass, "same_as", VALUEFUNC(WxIndividualLayoutConstraint::SameAs), -1);
	rb_define_method(rubyClass, "left_of", VALUEFUNC(WxIndividualLayoutConstraint::LeftOf), -1);
	rb_define_method(rubyClass, "right_of", VALUEFUNC(WxIndividualLayoutConstraint::RightOf), -1);
	rb_define_method(rubyClass, "above", VALUEFUNC(WxIndividualLayoutConstraint::Above), -1);
	rb_define_method(rubyClass, "below", VALUEFUNC(WxIndividualLayoutConstraint::Below), -1);
	rb_define_method(rubyClass, "percent_of", VALUEFUNC(WxIndividualLayoutConstraint::PercentOf), 3);
	rb_define_method(rubyClass, "as_is", VALUEFUNC(WxIndividualLayoutConstraint::AsIs), 0);
	rb_define_method(rubyClass, "absolute", VALUEFUNC(WxIndividualLayoutConstraint::Absolute), 1);

}

VALUE
WxIndividualLayoutConstraint::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxIndividualLayoutConstraint::init(VALUE self)
{
    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr = new wxIndividualLayoutConstraint();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxIndividualLayoutConstraint::init0(wxIndividualLayoutConstraint &individualLayoutConstraint)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = &individualLayoutConstraint;
    return self;
}

void
WxIndividualLayoutConstraint::SameAs(int argc, VALUE *argv, VALUE self)
{
    wxWindowBase *otherW;
    wxEdge edge;
    int marg = wxLAYOUT_DEFAULT_MARGIN;

    if(TYPE(argv[0])==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(argv[0], wxWindow, ptr);
	otherW = ptr;
    }
    if(TYPE(argv[1])==T_FIXNUM) {
        edge = (wxEdge)NUM2INT(argv[1]);
    }
    if(argc>2 && TYPE(argv[2])==T_FIXNUM) {
        marg = NUM2INT(argv[2]);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->SameAs(otherW,edge,marg);
}

void
WxIndividualLayoutConstraint::LeftOf(int argc, VALUE *argv, VALUE self)
{
    wxWindowBase *sibling;
    int marg = wxLAYOUT_DEFAULT_MARGIN;

    if(TYPE(argv[0])==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(argv[0], wxWindow, ptr);
	sibling = ptr;
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM) {
        marg = NUM2INT(argv[1]);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->LeftOf(sibling,marg);
}

void
WxIndividualLayoutConstraint::RightOf(int argc, VALUE *argv, VALUE self)
{
    wxWindowBase *sibling;
    int marg = wxLAYOUT_DEFAULT_MARGIN;

    if(TYPE(argv[0])==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(argv[0], wxWindow, ptr);
	sibling = ptr;
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM) {
        marg = NUM2INT(argv[1]);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->RightOf(sibling,marg);
}

void
WxIndividualLayoutConstraint::Above(int argc, VALUE *argv, VALUE self)
{
    wxWindowBase *sibling;
    int marg = wxLAYOUT_DEFAULT_MARGIN;

    if(TYPE(argv[0])==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(argv[0], wxWindow, ptr);
	sibling = ptr;
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM) {
        marg = NUM2INT(argv[1]);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->Above(sibling,marg);
}

void
WxIndividualLayoutConstraint::Below(int argc, VALUE *argv, VALUE self)
{
    wxWindowBase *sibling;
    int marg = wxLAYOUT_DEFAULT_MARGIN;

    if(TYPE(argv[0])==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(argv[0], wxWindow, ptr);
	sibling = ptr;
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM) {
        marg = NUM2INT(argv[1]);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->Below(sibling,marg);
}

void
WxIndividualLayoutConstraint::PercentOf(VALUE self,VALUE votherW,VALUE vwh,VALUE vper)
{
    wxWindowBase *otherW;
    wxEdge wh;
    int per;

    if(TYPE(votherW)==T_DATA) {
        wxWindow *ptr;
	Data_Get_Struct(votherW, wxWindow, ptr);
	otherW = ptr;
    }
    if(TYPE(vwh)==T_FIXNUM) {
        wh = (wxEdge)NUM2INT(vwh);
    }
    if(TYPE(vper)==T_FIXNUM) {
        per = NUM2INT(vper);
    }

    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->PercentOf(otherW,wh,per);
}

void
WxIndividualLayoutConstraint::AsIs(VALUE self)
{
    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->AsIs();
}

void
WxIndividualLayoutConstraint::Absolute(VALUE self,VALUE vvalue)
{
    int value = NUM2INT(vvalue);
    wxIndividualLayoutConstraint *ptr;
    Data_Get_Struct(self, wxIndividualLayoutConstraint, ptr);
    ptr->Absolute(value);
}

VALUE WxIndividualLayoutConstraint::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxIndividualLayoutConstraint::DefineClass();
    }
};
static ZAutoDefine x;

//-----------------------------------------------------------------------------------------
void WxLayoutConstraints::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"LayoutConstraints", rb_cObject);
	rb_define_alloc_func(rubyClass,WxLayoutConstraints::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxLayoutConstraints::init), 0);
	rb_define_method(rubyClass, "left", VALUEFUNC(WxLayoutConstraints::left), 0);
	rb_define_method(rubyClass, "top", VALUEFUNC(WxLayoutConstraints::top), 0);
	rb_define_method(rubyClass, "width", VALUEFUNC(WxLayoutConstraints::width), 0);
	rb_define_method(rubyClass, "height", VALUEFUNC(WxLayoutConstraints::height), 0);
	rb_define_method(rubyClass, "right", VALUEFUNC(WxLayoutConstraints::right), 0);
	rb_define_method(rubyClass, "bottom", VALUEFUNC(WxLayoutConstraints::bottom), 0);
	rb_define_method(rubyClass, "centre_x", VALUEFUNC(WxLayoutConstraints::centreX), 0);
	rb_define_method(rubyClass, "centre_y", VALUEFUNC(WxLayoutConstraints::centreY), 0);
}

VALUE
WxLayoutConstraints::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxLayoutConstraints::init(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    ptr = new wxLayoutConstraints();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxLayoutConstraints::init0(wxLayoutConstraints *layoutConstraint)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = layoutConstraint;
    return self;
}

VALUE
WxLayoutConstraints::left(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->left);
}

VALUE
WxLayoutConstraints::top(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->top);
}
VALUE
WxLayoutConstraints::right(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->right);
}
VALUE
WxLayoutConstraints::bottom(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->bottom);
}
VALUE
WxLayoutConstraints::width(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->width);
}
VALUE
WxLayoutConstraints::height(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->height);
}
VALUE
WxLayoutConstraints::centreX(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->centreX);
}
VALUE
WxLayoutConstraints::centreY(VALUE self)
{
    wxLayoutConstraints *ptr;
    Data_Get_Struct(self, wxLayoutConstraints, ptr);
    return WxIndividualLayoutConstraint::init0(ptr->centreY);
}

VALUE WxLayoutConstraints::rubyClass;

class ZAutoDefineWxLayoutConstraints
{
public:
   ZAutoDefineWxLayoutConstraints()
    {
       WxLayoutConstraints::DefineClass();
    }
};
static ZAutoDefineWxLayoutConstraints x2;
