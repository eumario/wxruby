/**********************************************************************

  pen.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "pen.h"
#include "bitmap.h"
#include "colour.h"

void WxPen::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Pen", rb_cObject);
	rb_define_alloc_func(rubyClass,WxPen::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxPen::init), -1);
	rb_define_method(rubyClass, "get_cap", VALUEFUNC(WxPen::GetCap), 0);
	rb_define_method(rubyClass, "get_colour", VALUEFUNC(WxPen::GetColour), 0);
	rb_define_method(rubyClass, "get_dashes", VALUEFUNC(WxPen::GetDashes), 0);
	rb_define_method(rubyClass, "get_join", VALUEFUNC(WxPen::GetJoin), 0);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "get_stipple", VALUEFUNC(WxPen::GetStipple), 0);
#endif
	rb_define_method(rubyClass, "get_style", VALUEFUNC(WxPen::GetStyle), 0);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxPen::GetWidth), 0);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxPen::Ok), 0);
	rb_define_method(rubyClass, "set_cap", VALUEFUNC(WxPen::SetCap), 1);
	rb_define_method(rubyClass, "set_colour", VALUEFUNC(WxPen::SetColour), -1);
	rb_define_method(rubyClass, "set_dashes", VALUEFUNC(WxPen::SetDashes), 1);
	rb_define_method(rubyClass, "set_join", VALUEFUNC(WxPen::SetJoin), 1);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "set_stipple", VALUEFUNC(WxPen::SetStipple), 1);
#endif
	rb_define_method(rubyClass, "set_style", VALUEFUNC(WxPen::SetStyle), 1);
	rb_define_method(rubyClass, "set_width", VALUEFUNC(WxPen::SetWidth), 1);
}

VALUE
WxPen::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxPen::init(int argc, VALUE *argv, VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    if(argc==0) {
        ptr = new wxPen();
#ifdef __WXMSW__
    } else if(argc==2) {
        wxBitmap *stippleBitmap;
        Data_Get_Struct(argv[0], wxBitmap, stippleBitmap);
        int width = NUM2INT(argv[1]);
        ptr = new wxPen(*stippleBitmap,width);
#endif
    } else if(argc==3) {
        int width = NUM2INT(argv[1]);
        int style = NUM2INT(argv[2]);
        if(TYPE(argv[0])==T_STRING) {
            wxString colourName = StringValuePtr(argv[0]);
            ptr = new wxPen(colourName,width,style);
        }
        else {
            wxColour *colour;
            Data_Get_Struct(argv[0], wxColour, colour);
            ptr = new wxPen(*colour,width,style);
        }
    }
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxPen::init0(wxPen *pen)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)pen;
    return self;
}

VALUE
WxPen::GetCap(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return INT2NUM(ptr->GetCap());
}


VALUE
WxPen::GetColour(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return WxColour::init0(ptr->GetColour());
}

VALUE
WxPen::GetDashes(VALUE self)
{
    wxDash *dashes;
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    long n = ptr->GetDashes(&dashes);
    VALUE *elts = new VALUE[n];
    for(int i=0;i<n;i++) {
        elts[i] = INT2NUM(dashes[i]);
    }
    return rb_ary_new4(n,elts);
}

VALUE
WxPen::GetJoin(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return INT2NUM(ptr->GetJoin());
}

#ifdef __WXMSW__
VALUE
WxPen::GetStipple(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return WxBitmap::init0(*ptr->GetStipple());
}
#endif

VALUE
WxPen::GetStyle(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return INT2NUM(ptr->GetStyle());
}

VALUE
WxPen::GetWidth(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return INT2NUM(ptr->GetWidth());
}

VALUE
WxPen::Ok(VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxPen::SetCap(VALUE self,VALUE vcapStyle)
{
    int capStyle = NUM2INT(vcapStyle);
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    ptr->SetCap(capStyle);
}

void
WxPen::SetColour(int argc, VALUE *argv, VALUE self)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    if(argc==1) {
        if(TYPE(argv[0])==T_STRING) {
            wxString colourName = StringValuePtr(argv[0]);
            ptr->SetColour(colourName);
        }
        else {
            wxColour *colour;
            Data_Get_Struct(argv[0], wxColour, colour);
            ptr->SetColour(*colour);
        }
    } else if(argc==3) {
        unsigned char red = NUM2INT(argv[0]);
        unsigned char green = NUM2INT(argv[1]);
        unsigned char blue = NUM2INT(argv[2]);
        ptr->SetColour(red,green,blue);
    }
}

void
WxPen::SetDashes(VALUE self,VALUE vdashes)
{
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    if(vdashes==Qnil || RARRAY(vdashes)->len==0) {
        ptr->SetDashes(0,NULL);
    } else {
        int n = RARRAY(vdashes)->len;
        wxDash *dashes = new wxDash[n];
        for(int i=0;i<n;i++)
            dashes[i] = NUM2INT(RARRAY(vdashes)->ptr[i]);
        ptr->SetDashes(n,dashes);
    }
}

void
WxPen::SetJoin(VALUE self,VALUE vjoin_style)
{
    int join_style = NUM2INT(vjoin_style);
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    ptr->SetJoin(join_style);
}

#ifdef __WXMSW__
void
WxPen::SetStipple(VALUE self,VALUE vstipple)
{
    wxBitmap *stipple;
    Data_Get_Struct(vstipple, wxBitmap, stipple);
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    ptr->SetStipple(*stipple);
}
#endif

void
WxPen::SetStyle(VALUE self,VALUE vstyle)
{
    int style = NUM2INT(vstyle);
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    ptr->SetStyle(style);
}

void
WxPen::SetWidth(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxPen *ptr;
    Data_Get_Struct(self, wxPen, ptr);
    ptr->SetWidth(width);
}

VALUE WxPen::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxPen::DefineClass();
    }
};
static ZAutoDefine x;
