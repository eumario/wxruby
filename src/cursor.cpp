/**********************************************************************

  cursor.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "cursor.h"
#include "bitmap.h"

void WxCursor::DefineClass()
{
	if(rubyClass)
		return;
	WxBitmap::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Cursor", WxBitmap::rubyClass);
	rb_define_alloc_func(rubyClass,WxCursor::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxCursor::init), -1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxCursor::Ok), 0);
}

VALUE
WxCursor::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxCursor::init(int argc, VALUE *argv, VALUE self)
{
    wxString cursorName;
    long type;
    int hotSpotX = 0;
    int hotSpotY = 0;

    wxCursor *ptr;
    Data_Get_Struct(self, wxCursor, ptr);
    if(argc==0) {
        ptr = new wxCursor();
    }
    else if(argc>0 && TYPE(argv[0])==T_STRING) {
    	cursorName = StringValuePtr(argv[0]);
        type = NUM2INT(argv[1]);
    	if(argc>2 && TYPE(argv[2])==T_FIXNUM)
    	  hotSpotX = NUM2INT(argv[2]);
    	if(argc>3 && TYPE(argv[3])==T_FIXNUM)
    	  hotSpotY = NUM2INT(argv[3]);
        ptr = new wxCursor(cursorName,type,hotSpotX,hotSpotY);
    } 
#if defined(__WXGTK__) || defined(__WXMSW__)
	else if(argc==1 && TYPE(argv[0])==T_DATA) {
        wxImage *image;
        Data_Get_Struct(argv[0], wxImage, image);
      	ptr = new wxCursor(*image);
    } 
#endif
	else {
        int cursorId = NUM2INT(argv[0]);
      	ptr = new wxCursor(cursorId);
    }
    DATA_PTR(self) = ptr;
    return self;
}




VALUE
WxCursor::Ok(VALUE self)
{
    wxCursor *ptr;
    Data_Get_Struct(self, wxCursor, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

VALUE
WxCursor::init0(wxCursor *cursor)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = cursor;
    return self;
}

VALUE WxCursor::rubyClass;

class ZAutoDefineWxCursor
{
public:
   ZAutoDefineWxCursor()
    {
       WxCursor::DefineClass();
    }
};
static ZAutoDefineWxCursor x;

//-----------------------------------------------------------------------------------
void WxBusyCursor::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"BusyCursor", rb_cObject);
	rb_define_alloc_func(rubyClass,WxBusyCursor::alloc);
	//
	// NSK - I'm getting rid of new and free, and replacing them with
	// the more 'rubyesque' busy method
	//
	//rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_singleton_method(rubyClass, "busy",VALUEFUNC(Busy),-1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxBusyCursor::init), -1);
	//rb_define_method(rubyClass, "free", VALUEFUNC(WxBusyCursor::free), 0);
}


VALUE WxBusyCursor::Busy(int argc, VALUE *argv, VALUE self)
{
	if (rb_block_given_p())
	{
		wxBeginBusyCursor();
		rb_yield(Qnil);
		wxEndBusyCursor();
	}
	return Qnil;
}


VALUE
WxBusyCursor::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxBusyCursor::init(int argc, VALUE *argv, VALUE self)
{
    wxCursor* cursor = wxHOURGLASS_CURSOR;
    if(argc>0) {
        Data_Get_Struct(argv[0], wxCursor, cursor);
    }
    wxBusyCursor *ptr;
    Data_Get_Struct(self, wxBusyCursor, ptr);
    ptr = new wxBusyCursor(cursor);
    DATA_PTR(self) = ptr;
    return self;
}

void
WxBusyCursor::free(VALUE self)
{
    wxBusyCursor *ptr;
    Data_Get_Struct(self, wxBusyCursor, ptr);
    delete ptr;
}

VALUE WxBusyCursor::rubyClass;

class ZAutoDefineWxBusyCursor
{
public:
   ZAutoDefineWxBusyCursor()
    {
       WxBusyCursor::DefineClass();
    }
};
static ZAutoDefineWxBusyCursor x2;
