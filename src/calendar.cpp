/**********************************************************************

  calendar.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "calendar.h"
#include "colour.h"
#include "window.h"
#include "date.h"
#ifdef __WXMAC__
#include "sys/time.h"
#endif

extern "C" {
struct timeval rb_time_timeval(VALUE);
}

void WxCalendarDateAttr::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"CalendarDateAttr", rb_cObject);
	rb_define_alloc_func(rubyClass,WxCalendarDateAttr::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxCalendarDateAttr::init), -1);
	rb_define_method(rubyClass, "get_background_colour", VALUEFUNC(WxCalendarDateAttr::GetBackgroundColour), 0);

}

VALUE
WxCalendarDateAttr::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxCalendarDateAttr::init(int argc, VALUE *argv, VALUE self)
{
    wxColour *cptr;
    wxFont *fptr;
    wxColour colText;
    wxColour colBack = wxNullColour;
    wxColour colBorder = wxNullColour;
    wxFont font = wxNullFont;
    wxCalendarDateBorder border = wxCAL_BORDER_NONE;

    wxCalendarDateAttr *ptr;
    Data_Get_Struct(self, wxCalendarDateAttr, ptr);
    if(argc==0) ptr = new wxCalendarDateAttr();
    if(argc>0 && TYPE(argv[0])==T_FIXNUM) {
      border = (wxCalendarDateBorder)NUM2INT(argv[0]);
      if(argc>1) {
        Data_Get_Struct(argv[1], wxColour, cptr);
        colBorder = *cptr;
      }
      ptr = new wxCalendarDateAttr(border,colBorder);
    } else {
      Data_Get_Struct(argv[0], wxColour, cptr);
      colText = *cptr;
      if(argc>1) {
        Data_Get_Struct(argv[1], wxColour, cptr);
        colBack = *cptr;
      }
      if(argc>2) {
        Data_Get_Struct(argv[2], wxColour, cptr);
        colBorder = *cptr;
      }
      if(argc>3) {
        Data_Get_Struct(argv[3], wxFont, fptr);
        font = *fptr;
      }
      if(argc>4) border = (wxCalendarDateBorder)NUM2INT(argv[4]);
      ptr = new wxCalendarDateAttr(colText,colBack,colBorder,font,border);
    }

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxCalendarDateAttr::init0(wxCalendarDateAttr *attr)
{
    if(attr == NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = attr;
    return self;
}

VALUE
WxCalendarDateAttr::GetBackgroundColour(VALUE self)
{
    wxCalendarDateAttr *ptr;
    Data_Get_Struct(self, wxCalendarDateAttr, ptr);
    return WxColour::init0(ptr->GetBackgroundColour());
}
VALUE WxCalendarDateAttr::rubyClass;

class ZAutoDefineWxDateAttr
{
public:
   ZAutoDefineWxDateAttr()
    {
       WxCalendarDateAttr::DefineClass();
    }
};
static ZAutoDefineWxDateAttr x;

//---------------------------------------------

void WxCalendarCtrl::DefineClass()
{
    if(rubyClass)
        return;
    WxWindow::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"CalendarCtrl", WxWindow::rubyClass);
    rb_define_alloc_func(rubyClass,WxCalendarCtrl::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxCalendarCtrl::init), -1);
    rb_define_method(rubyClass, "set_attr", VALUEFUNC(WxCalendarCtrl::SetAttr), 2);
    rb_define_method(rubyClass, "get_attr", VALUEFUNC(WxCalendarCtrl::GetAttr), 1);
    rb_define_method(rubyClass, "reset_attr", VALUEFUNC(WxCalendarCtrl::ResetAttr), 1);
    rb_define_method(rubyClass, "enable_holiday_display", VALUEFUNC(WxCalendarCtrl::EnableHolidayDisplay), -1);
    rb_define_method(rubyClass, "enable_year_change", VALUEFUNC(WxCalendarCtrl::EnableYearChange), -1);
    rb_define_method(rubyClass, "enable_month_change", VALUEFUNC(WxCalendarCtrl::EnableMonthChange), -1);
    rb_define_method(rubyClass, "get_date", VALUEFUNC(WxCalendarCtrl::GetDate), 0);
    rb_define_method(rubyClass, "set_date", VALUEFUNC(WxCalendarCtrl::SetDate), 1);
}

VALUE
WxCalendarCtrl::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxCalendarCtrl::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxWindowID id = -1;
    wxDateTime date = wxDefaultDateTime;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxCAL_SHOW_HOLIDAYS;
    wxString name = wxCalendarNameStr;

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_DATA) {
        wxDateTime *ptr;
	Data_Get_Struct(argv[2], wxDateTime, ptr);
	date = *ptr;
    }
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[3], wxPoint, ptr);
	pos = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_DATA) {
        wxSize *ptr;
	Data_Get_Struct(argv[4], wxSize, ptr);
	size = *ptr;
    }
    if(argc>5 && TYPE(argv[5])==T_FIXNUM)
      style = NUM2INT(argv[5]);

    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr = new wxCalendarCtrl(parent,id,date,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxCalendarCtrl::SetAttr(VALUE self,VALUE vday,VALUE vattr)
{
    size_t day = (size_t)NUM2INT(vday);
    wxCalendarDateAttr *attr;
    Data_Get_Struct(vattr, wxCalendarDateAttr, attr);

    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr->SetAttr(day,attr);
}

VALUE
WxCalendarCtrl::GetAttr(VALUE self,VALUE vday)
{
    size_t day = (size_t)NUM2INT(vday);
    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    return WxCalendarDateAttr::init0(ptr->GetAttr(day));
}

void
WxCalendarCtrl::ResetAttr(VALUE self,VALUE vday)
{
    size_t day = (size_t)NUM2INT(vday);
    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr->ResetAttr(day);
}

void
WxCalendarCtrl::EnableHolidayDisplay(int argc, VALUE *argv, VALUE self)
{
    bool display = TRUE;
    if(argc>0 && argv[0]==Qfalse) display = FALSE;
    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr->EnableHolidayDisplay(display);
}

void
WxCalendarCtrl::EnableMonthChange(int argc, VALUE *argv, VALUE self)
{
    bool display = TRUE;
    if(argc>0 && argv[0]==Qfalse) display = FALSE;
    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr->EnableMonthChange(display);
}

void
WxCalendarCtrl::EnableYearChange(int argc, VALUE *argv, VALUE self)
{
    bool display = TRUE;
    if(argc>0 && argv[0]==Qfalse) display = FALSE;
    wxCalendarCtrl *ptr;
    Data_Get_Struct(self, wxCalendarCtrl, ptr);
    ptr->EnableYearChange(display);
}

VALUE WxCalendarCtrl::SetDate(VALUE self, VALUE date)
{
    wxCalendarCtrl *ptr;
    wxDateTime *dptr;
    
    Data_Get_Struct(self, wxCalendarCtrl, ptr);

    if (CLASS_OF(date) == WxDateTime::rubyClass)
    {
    	Data_Get_Struct(date, wxDateTime, dptr);
    	ptr->SetDate(*dptr);
    }
    else if (CLASS_OF(date) == rb_cTime)
    {
    	struct timeval tm = rb_time_timeval(date);
    	wxDateTime dt((time_t)tm.tv_sec);
    	ptr->SetDate(dt);
    }
    else rb_raise(rb_eTypeError, "Must pass Time or DateTime");
    	
    
    return Qnil;
}

VALUE WxCalendarCtrl::GetDate(VALUE self)
{
    wxCalendarCtrl *ptr;
    wxDateTime dt;
    
    Data_Get_Struct(self, wxCalendarCtrl, ptr);

    dt = ptr->GetDate();
    
    return WxDateTime::init0(dt);
    
}

VALUE WxCalendarCtrl::rubyClass;

class ZAutoDefineWxCalendarCtrl
{
public:
   ZAutoDefineWxCalendarCtrl()
    {
       WxCalendarCtrl::DefineClass();
    }
};
static ZAutoDefineWxCalendarCtrl x2;
