/**********************************************************************

  scrolledwindow.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "dc.h"
#include "scrolledwindow.h"
#include "panel.h"

void WxScrolledWindow::DefineClass()
{
	if(rubyClass)
		return;
	WxPanel::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ScrolledWindow", WxPanel::rubyClass);
	rb_define_alloc_func(rubyClass,WxScrolledWindow::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxScrolledWindow::init), -1);
	rb_define_method(rubyClass, "calc_scrolled_position", VALUEFUNC(WxScrolledWindow::CalcScrolledPosition), 2);
	rb_define_method(rubyClass, "calc_unscrolled_position", VALUEFUNC(WxScrolledWindow::CalcUnscrolledPosition), 2);
	rb_define_method(rubyClass, "enable_scrolling", VALUEFUNC(WxScrolledWindow::EnableScrolling), 2);
	rb_define_method(rubyClass, "get_scroll_pixels_per_unit", VALUEFUNC(WxScrolledWindow::GetScrollPixelsPerUnit), 0);
	rb_define_method(rubyClass, "get_view_start", VALUEFUNC(WxScrolledWindow::GetViewStart), 0);
	rb_define_method(rubyClass, "get_virtual_size", VALUEFUNC(WxScrolledWindow::GetVirtualSize), 0);
	rb_define_method(rubyClass, "is_retained", VALUEFUNC(WxScrolledWindow::IsRetained), 0);
	rb_define_method(rubyClass, "prepare_dc", VALUEFUNC(WxScrolledWindow::PrepareDC), 1);
	rb_define_method(rubyClass, "scroll", VALUEFUNC(WxScrolledWindow::Scroll), 2);
	rb_define_method(rubyClass, "set_scroll_rate", VALUEFUNC(WxScrolledWindow::SetScrollRate), 2);
	rb_define_method(rubyClass, "set_scrollbars", VALUEFUNC(WxScrolledWindow::SetScrollbars), -1);
	rb_define_method(rubyClass, "set_target_window", VALUEFUNC(WxScrolledWindow::SetTargetWindow), 1);
}

VALUE
WxScrolledWindow::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxScrolledWindow::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxHSCROLL | wxVSCROLL;
    wxString name = "scrolledWindow";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_DATA) {
        wxPoint *ptr;
	    Data_Get_Struct(argv[2], wxPoint, ptr);
	    pos = *ptr;
    }
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxSize *ptr;
	    Data_Get_Struct(argv[3], wxSize, ptr);
	    size = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_FIXNUM)
      style = NUM2INT(argv[4]);

    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr = new wxRbScrolledWindow(parent,id,pos,size,style,name);
    DATA_PTR(self) = ptr;

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    return self;
}


VALUE
WxScrolledWindow::CalcScrolledPosition(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    int xx;
    int yy;
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->CalcScrolledPosition(x,y,&xx,&yy);
    return rb_ary_new3(2,INT2NUM(xx),INT2NUM(yy));
}

VALUE
WxScrolledWindow::CalcUnscrolledPosition(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    int xx;
    int yy;
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->CalcUnscrolledPosition(x,y,&xx,&yy);
    return rb_ary_new3(2,INT2NUM(xx),INT2NUM(yy));
}

void
WxScrolledWindow::EnableScrolling(VALUE self,VALUE vxScrolling,VALUE vyScrolling)
{
    bool xScrolling = (vxScrolling == Qtrue);
    bool yScrolling = (vyScrolling == Qtrue);
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->EnableScrolling(xScrolling,yScrolling);
}


VALUE
WxScrolledWindow::GetScrollPixelsPerUnit(VALUE self)
{
    int xUnit;
    int yUnit;
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->GetScrollPixelsPerUnit(&xUnit,&yUnit);
    return rb_ary_new3(2,INT2NUM(xUnit),INT2NUM(yUnit));
}

VALUE
WxScrolledWindow::GetViewStart(VALUE self)
{
    int x;
    int y;
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->GetViewStart(&x,&y);
    return rb_ary_new3(2,INT2NUM(x),INT2NUM(y));
}

VALUE
WxScrolledWindow::GetVirtualSize(VALUE self)
{
    int x;
    int y;
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->GetVirtualSize(&x,&y);
    return rb_ary_new3(2,INT2NUM(x),INT2NUM(y));
}

VALUE
WxScrolledWindow::IsRetained(VALUE self)
{
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    return (ptr->IsRetained() ? Qtrue : Qfalse);
}

void
WxScrolledWindow::PrepareDC(VALUE self,VALUE vdc)
{
    wxDC *dc;
    Data_Get_Struct(vdc, wxDC, dc);
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->PrepareDC(*dc);
}

void
WxScrolledWindow::Scroll(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->Scroll(x,y);
}

void
WxScrolledWindow::SetScrollbars(int argc, VALUE *argv, VALUE self)
{
    int pixelsPerUnitX = NUM2INT(argv[0]);
    int pixelsPerUnitY = NUM2INT(argv[1]);
    int noUnitsX = NUM2INT(argv[2]);
    int noUnitsY = NUM2INT(argv[3]);
    int xPos = 0;
    if(argc>4) xPos = NUM2INT(argv[4]);
    int yPos = 0;
    if(argc>5) yPos = NUM2INT(argv[5]);
    bool noRefresh = FALSE;
    if(argc>6 && argv[6]==Qtrue) noRefresh = TRUE;

    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->SetScrollbars(pixelsPerUnitX,pixelsPerUnitY,noUnitsX,noUnitsY,xPos,yPos,noRefresh);
}

void
WxScrolledWindow::SetScrollRate(VALUE self,VALUE vxstep,VALUE vystep)
{
    int xstep = NUM2INT(vxstep);
    int ystep = NUM2INT(vystep);
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->SetScrollRate(xstep,ystep);
}

void
WxScrolledWindow::SetTargetWindow(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxRbScrolledWindow *ptr;
    Data_Get_Struct(self, wxRbScrolledWindow, ptr);
    ptr->SetTargetWindow(window);
}

VALUE WxScrolledWindow::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxScrolledWindow::DefineClass();
    }
};
static ZAutoDefine x;

//------------------------------------------------
void
wxRbScrolledWindow::OnDraw(wxDC& dc)
{
    void *data = GetClientData();
    VALUE vdc = WxDC::init0(&dc);
    VALUE self = rb_hash_aref((VALUE)data, rb_str_new2("self"));
    rb_funcall(self,rb_intern("OnDraw"),1,vdc);
}
