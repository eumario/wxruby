/**********************************************************************

  ownerdrawn.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifdef __WXMSW__
#include "wx.h"
#include "ownerdrawn.h"
#include "font.h"
#include "colour.h"
#include "bitmap.h"

#ifdef __WXMSW__
#include "wx/msw/private.h"
#endif

void WxOwnerDrawn::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"OwnerDrawn", rb_cObject);
	rb_define_alloc_func(rubyClass,WxOwnerDrawn::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxOwnerDrawn::init), -1);
	rb_define_method(rubyClass, "get_background_colour", VALUEFUNC(WxOwnerDrawn::GetBackgroundColour), 0);
	rb_define_method(rubyClass, "get_bitmap", VALUEFUNC(WxOwnerDrawn::GetBitmap), -1);
	rb_define_method(rubyClass, "get_default_margin_width", VALUEFUNC(WxOwnerDrawn::GetDefaultMarginWidth), 0);
	rb_define_method(rubyClass, "get_font", VALUEFUNC(WxOwnerDrawn::GetFont), 0);
	rb_define_method(rubyClass, "get_margin_width", VALUEFUNC(WxOwnerDrawn::GetMarginWidth), 0);
	rb_define_method(rubyClass, "get_name", VALUEFUNC(WxOwnerDrawn::GetName), 0);
	rb_define_method(rubyClass, "get_text_colour", VALUEFUNC(WxOwnerDrawn::GetTextColour), 0);
	rb_define_method(rubyClass, "is_checkable", VALUEFUNC(WxOwnerDrawn::IsCheckable), 0);
	rb_define_method(rubyClass, "is_owner_drawn", VALUEFUNC(WxOwnerDrawn::IsOwnerDrawn), 0);
	rb_define_method(rubyClass, "reset_owner_drawn", VALUEFUNC(WxOwnerDrawn::ResetOwnerDrawn), 0);
	rb_define_method(rubyClass, "set_accel_string", VALUEFUNC(WxOwnerDrawn::SetAccelString), 1);
	rb_define_method(rubyClass, "set_background_colour", VALUEFUNC(WxOwnerDrawn::SetBackgroundColour), 1);
	rb_define_method(rubyClass, "set_bitmap", VALUEFUNC(WxOwnerDrawn::SetBitmap), 1);
	rb_define_method(rubyClass, "set_bitmaps", VALUEFUNC(WxOwnerDrawn::SetBitmaps), -1);
	rb_define_method(rubyClass, "set_checkable", VALUEFUNC(WxOwnerDrawn::SetCheckable), 1);
	rb_define_method(rubyClass, "set_font", VALUEFUNC(WxOwnerDrawn::SetFont), 1);
	rb_define_method(rubyClass, "set_margin_width", VALUEFUNC(WxOwnerDrawn::SetMarginWidth), 1);
	rb_define_method(rubyClass, "set_name", VALUEFUNC(WxOwnerDrawn::SetName), 1);
	rb_define_method(rubyClass, "set_text_colour", VALUEFUNC(WxOwnerDrawn::SetTextColour), 1);
}

VALUE
WxOwnerDrawn::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxOwnerDrawn::init(int argc, VALUE *argv, VALUE self)
{
    wxString str = wxEmptyString;
    if(argc>0) str = StringValuePtr(argv[0]);
    bool bCheckable = FALSE;
    if(argc>1 && argv[1]==Qtrue) bCheckable = TRUE;
    bool bMenuItem = FALSE;
    if(argc>2 && argv[2]==Qtrue) bMenuItem = TRUE;

    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr = new wxOwnerDrawn(str,bCheckable,bMenuItem);
    DATA_PTR(self) = ptr;
    return self;
}


VALUE
WxOwnerDrawn::init0(wxOwnerDrawn *ownerdrawn)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = ownerdrawn;
    return self;
}

void
WxOwnerDrawn::SetFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetFont(*font);
}

VALUE
WxOwnerDrawn::GetFont(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return WxFont::init0(ptr->GetFont());
}

void
WxOwnerDrawn::SetTextColour(VALUE self,VALUE vcolText)
{
    wxColour *colText;
    Data_Get_Struct(vcolText, wxColour, colText);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetTextColour(*colText);
}

VALUE
WxOwnerDrawn::GetTextColour(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return WxColour::init0(ptr->GetTextColour());
}

void
WxOwnerDrawn::SetBackgroundColour(VALUE self,VALUE vcolBack)
{
    wxColour *colBack;
    Data_Get_Struct(vcolBack, wxColour, colBack);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetBackgroundColour(*colBack);
}

VALUE
WxOwnerDrawn::GetBackgroundColour(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return WxColour::init0(ptr->GetBackgroundColour());
}

void
WxOwnerDrawn::SetBitmaps(int argc, VALUE *argv, VALUE self)
{
    wxBitmap *bmpChecked;
    Data_Get_Struct(argv[0], wxBitmap, bmpChecked);
    wxBitmap *bmpUnchecked = &wxNullBitmap;
    if(argc>1) {
        Data_Get_Struct(argv[1], wxBitmap, bmpUnchecked);
    }
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetBitmaps(*bmpChecked,*bmpUnchecked);
}

void
WxOwnerDrawn::SetBitmap(VALUE self,VALUE vbmpChecked)
{
    wxBitmap *bmpChecked;
    Data_Get_Struct(vbmpChecked, wxBitmap, bmpChecked);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetBitmap(*bmpChecked);
}

VALUE
WxOwnerDrawn::GetBitmap(int argc, VALUE *argv, VALUE self)
{
    bool bChecked = TRUE;
    if(argc>0 && argv[0]==Qfalse) bChecked = FALSE;
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return WxBitmap::init0(ptr->GetBitmap(bChecked));
}

void
WxOwnerDrawn::SetMarginWidth(VALUE self,VALUE vnWidth)
{
    int nWidth = NUM2INT(vnWidth);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetMarginWidth(nWidth);
}

VALUE
WxOwnerDrawn::GetMarginWidth(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return INT2NUM(ptr->GetMarginWidth());
}

VALUE
WxOwnerDrawn::GetDefaultMarginWidth(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return INT2NUM(ptr->GetDefaultMarginWidth());
}

void
WxOwnerDrawn::SetName(VALUE self,VALUE vstrName)
{
    wxString strName = StringValuePtr(vstrName);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetName(strName);
}

VALUE
WxOwnerDrawn::GetName(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return rb_str_new2(ptr->GetName());
}

void
WxOwnerDrawn::SetCheckable(VALUE self,VALUE vcheckable)
{
    bool checkable = (vcheckable == Qtrue);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetCheckable(checkable);
}

VALUE
WxOwnerDrawn::IsCheckable(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return (ptr->IsCheckable() ? Qtrue : Qfalse);
}

void
WxOwnerDrawn::SetAccelString(VALUE self,VALUE vstrAccel)
{
    wxString strAccel= StringValuePtr(vstrAccel);
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->SetAccelString(strAccel);
}

VALUE
WxOwnerDrawn::IsOwnerDrawn(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    return (ptr->IsOwnerDrawn() ? Qtrue : Qfalse);
}

void
WxOwnerDrawn::ResetOwnerDrawn(VALUE self)
{
    wxOwnerDrawn *ptr;
    Data_Get_Struct(self, wxOwnerDrawn, ptr);
    ptr->ResetOwnerDrawn();
}

VALUE WxOwnerDrawn::rubyClass;

class ZAutoDefineWxOwnerDrawn
{
public:
   ZAutoDefineWxOwnerDrawn()
    {
       WxOwnerDrawn::DefineClass();
    }
};
static ZAutoDefineWxOwnerDrawn x;

#endif
