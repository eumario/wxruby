/**********************************************************************

  region.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "region.h"

void WxRegion::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Region", rb_cObject);
	rb_define_alloc_func(rubyClass,WxRegion::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxRegion::init), -1);
	rb_define_method(rubyClass, "clear", VALUEFUNC(WxRegion::Clear), 0);
	rb_define_method(rubyClass, "contains", VALUEFUNC(WxRegion::Contains), -1);
	rb_define_method(rubyClass, "get_box", VALUEFUNC(WxRegion::GetBox), 0);
	rb_define_method(rubyClass, "intersect", VALUEFUNC(WxRegion::Intersect), -1);
	rb_define_method(rubyClass, "is_empty", VALUEFUNC(WxRegion::IsEmpty), 0);
#if defined(__WXGTK__) || defined(__WXMSW__)
	rb_define_method(rubyClass, "offset", VALUEFUNC(WxRegion::Offset), 2);
#endif
	rb_define_method(rubyClass, "subtract", VALUEFUNC(WxRegion::Subtract), 1);
	rb_define_method(rubyClass, "union", VALUEFUNC(WxRegion::Union), -1);
	rb_define_method(rubyClass, "xor", VALUEFUNC(WxRegion::Xor), -1);
}


VALUE
WxRegion::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxRegion::init(int argc, VALUE *argv, VALUE self)
{
    wxString name;

    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(argc==0) {
        ptr = new wxRegion();
    } else if(argc==1 && TYPE(argv[0])==T_DATA) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
      	ptr = new wxRegion(*rect);
    } else if(argc==2 && TYPE(argv[0])==T_DATA) {
        wxPoint *topLeft;
        Data_Get_Struct(argv[0], wxPoint, topLeft);
        wxPoint *bottomRight;
        Data_Get_Struct(argv[1], wxPoint, bottomRight);
      	ptr = new wxRegion(*topLeft,*bottomRight);
    } else if(argc==4) {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
      	ptr = new wxRegion(x,y,width,height);
    } 
#if defined(__WXGTK__) || defined(__WXMSW__)
	else {
        size_t n = NUM2INT(argv[0]);
        wxPoint *points;
        Data_Get_Struct(argv[1], wxPoint, points);
        int fillStyle = wxWINDING_RULE;
        if(argc>2) fillStyle = NUM2INT(argv[2]);
        ptr = new wxRegion(n,points,fillStyle);
    }
#endif
    DATA_PTR(self) = ptr;
    return self;
}

void
WxRegion::Clear(VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    ptr->Clear();
}

VALUE
WxRegion::Contains(int argc, VALUE *argv, VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(argc==1 && strstr(rb_class2name(CLASS_OF(argv[0])),"Rect")) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        return INT2NUM(ptr->Contains(*rect));
    } else if(argc==1) {
        wxPoint *pt;
        Data_Get_Struct(argv[0], wxPoint, pt);
        return INT2NUM(ptr->Contains(*pt));
    } else if(argc==2) {
        long x = NUM2INT(argv[0]);
        long y = NUM2INT(argv[1]);
        return INT2NUM(ptr->Contains(x,y));
    } else {
        long x = NUM2INT(argv[0]);
        long y = NUM2INT(argv[1]);
        long width = NUM2INT(argv[2]);
        long height = NUM2INT(argv[3]);
        return INT2NUM(ptr->Contains(x,y,width,height));
    }
}

VALUE
WxRegion::GetBox(VALUE self)
{
    wxCoord x;
    wxCoord y;
    wxCoord width;
    wxCoord height;
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    ptr->GetBox(x,y,width,height);
    return rb_ary_new3(4,INT2NUM(x),INT2NUM(y),INT2NUM(width),INT2NUM(height));
}

VALUE
WxRegion::Intersect(int argc, VALUE *argv, VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(argc==1 && strstr(rb_class2name(CLASS_OF(argv[0])),"Rect")) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        return (ptr->Intersect(*rect) ? Qtrue : Qfalse);
    } else if(argc==1) {
        wxRegion *region;
        Data_Get_Struct(argv[0], wxRegion, region);
        return (ptr->Intersect(*region) ? Qtrue : Qfalse);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        return (ptr->Intersect(x,y,width,height) ? Qtrue : Qfalse);
    }
}

VALUE
WxRegion::IsEmpty(VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    return (ptr->IsEmpty() ? Qtrue : Qfalse);
}

VALUE
WxRegion::Subtract(VALUE self,VALUE argv)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(strstr(rb_class2name(CLASS_OF(argv)),"Rect")) {
        wxRect *rect;
        Data_Get_Struct(argv, wxRect, rect);
        return (ptr->Subtract(*rect) ? Qtrue : Qfalse);
    } else {
        wxRegion *region;
        Data_Get_Struct(argv, wxRegion, region);
        return (ptr->Subtract(*region) ? Qtrue : Qfalse);
    }
}

#if defined(__WXGTK__) || defined(__WXMSW__)
VALUE
WxRegion::Offset(VALUE self,VALUE vx,VALUE vy)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    return (ptr->Offset(x,y) ? Qtrue : Qfalse);
}
#endif

VALUE
WxRegion::Union(int argc, VALUE *argv, VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(argc==1 && strstr(rb_class2name(CLASS_OF(argv[0])),"Rect")) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        return (ptr->Union(*rect) ? Qtrue : Qfalse);
    } else if(argc==1) {
        wxRegion *region;
        Data_Get_Struct(argv[0], wxRegion, region);
        return (ptr->Union(*region) ? Qtrue : Qfalse);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        return (ptr->Union(x,y,width,height) ? Qtrue : Qfalse);
    }
}

VALUE
WxRegion::Xor(int argc, VALUE *argv, VALUE self)
{
    wxRegion *ptr;
    Data_Get_Struct(self, wxRegion, ptr);
    if(argc==1 && strstr(rb_class2name(CLASS_OF(argv[0])),"Rect")) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        return (ptr->Xor(*rect) ? Qtrue : Qfalse);
    } else if(argc==1) {
        wxRegion *region;
        Data_Get_Struct(argv[0], wxRegion, region);
        return (ptr->Xor(*region) ? Qtrue : Qfalse);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        return (ptr->Xor(x,y,width,height) ? Qtrue : Qfalse);
    }
}

VALUE
WxRegion::init0(const wxRegion &region)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxRegion(region);
    return self;
}

VALUE WxRegion::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxRegion::DefineClass();
    }
};
static ZAutoDefine x;
