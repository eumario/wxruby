/**********************************************************************

  image.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "image.h"
#include "statusbar.h"
#include "menubar.h"
#include "toolbar.h"
#include "bitmap.h"
#include "palette.h"

void WxImage::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Image", rb_cObject);
	rb_define_alloc_func(rubyClass,WxImage::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxImage::init), -1);
	rb_define_method(rubyClass, "convert_to_bitmap", VALUEFUNC(WxImage::ConvertToBitmap), 0);
	rb_define_method(rubyClass, "convert_to_mono", VALUEFUNC(WxImage::ConvertToMono), 3);
	rb_define_method(rubyClass, "copy", VALUEFUNC(WxImage::Copy), 0);
	rb_define_method(rubyClass, "create", VALUEFUNC(WxImage::Create), 2);
	rb_define_method(rubyClass, "destroy", VALUEFUNC(WxImage::Destroy), 0);
	rb_define_method(rubyClass, "get_blue", VALUEFUNC(WxImage::GetBlue), 2);
	rb_define_method(rubyClass, "get_data", VALUEFUNC(WxImage::GetData), 0);
	rb_define_method(rubyClass, "get_green", VALUEFUNC(WxImage::GetGreen), 2);
	rb_define_method(rubyClass, "get_height", VALUEFUNC(WxImage::GetHeight), 0);
	rb_define_method(rubyClass, "get_image_count", VALUEFUNC(WxImage::GetImageCount), -1);
	rb_define_method(rubyClass, "get_mask_blue", VALUEFUNC(WxImage::GetMaskBlue), 0);
	rb_define_method(rubyClass, "get_mask_green", VALUEFUNC(WxImage::GetMaskGreen), 0);
	rb_define_method(rubyClass, "get_mask_red", VALUEFUNC(WxImage::GetMaskRed), 0);
	rb_define_method(rubyClass, "get_option", VALUEFUNC(WxImage::GetOption), 1);
	rb_define_method(rubyClass, "get_option_int", VALUEFUNC(WxImage::GetOptionInt), 1);
	rb_define_method(rubyClass, "get_palette", VALUEFUNC(WxImage::GetPalette), 0);
	rb_define_method(rubyClass, "get_red", VALUEFUNC(WxImage::GetRed), 2);
	rb_define_method(rubyClass, "has_option", VALUEFUNC(WxImage::HasOption), 1);
	rb_define_method(rubyClass, "get_sub_image", VALUEFUNC(WxImage::GetSubImage), 1);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxImage::GetWidth), 0);
	rb_define_method(rubyClass, "has_mask", VALUEFUNC(WxImage::HasMask), 0);
	rb_define_method(rubyClass, "load_file", VALUEFUNC(WxImage::LoadFile), -1);
	rb_define_method(rubyClass, "mirror", VALUEFUNC(WxImage::Mirror), -1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxImage::Ok), 0);
	rb_define_method(rubyClass, "replace", VALUEFUNC(WxImage::Replace), 6);
	rb_define_method(rubyClass, "rescale", VALUEFUNC(WxImage::Rescale), 2);
	rb_define_method(rubyClass, "rotate", VALUEFUNC(WxImage::Rotate), -1);
	rb_define_method(rubyClass, "rotate90", VALUEFUNC(WxImage::Rotate90), -1);
	rb_define_method(rubyClass, "save_file", VALUEFUNC(WxImage::SaveFile), -1);
	rb_define_method(rubyClass, "scale", VALUEFUNC(WxImage::Scale), 2);
	rb_define_method(rubyClass, "set_data", VALUEFUNC(WxImage::SetData), 1);
	rb_define_method(rubyClass, "set_mask", VALUEFUNC(WxImage::SetMask), -1);
	rb_define_method(rubyClass, "set_mask_colour", VALUEFUNC(WxImage::SetMaskColour), 3);
	rb_define_method(rubyClass, "set_mask_from_image", VALUEFUNC(WxImage::SetMaskFromImage), 4);
	rb_define_method(rubyClass, "set_option", VALUEFUNC(WxImage::SetOption), 2);
	rb_define_method(rubyClass, "set_palette", VALUEFUNC(WxImage::SetPalette), 1);
	rb_define_method(rubyClass, "set_rgb", VALUEFUNC(WxImage::SetRGB), 5);
}

VALUE
WxImage::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxImage::init(int argc, VALUE *argv, VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);

    if(TYPE(argv[0])==T_FIXNUM) {
        int width = NUM2INT(argv[0]);
        int height = NUM2INT(argv[1]);
        unsigned char* data;
        bool static_data=FALSE;
        if(argc>2) {
            data = (unsigned char*)StringValuePtr(argv[2]);
            if(argc>3 && argv[3]==Qtrue)
                static_data=TRUE;
            ptr = new wxImage(width,height,data,static_data);
        } else {
            ptr = new wxImage(width,height);
        }
    } else if(TYPE(argv[0])==T_STRING) {
        wxString name = StringValuePtr(argv[0]);
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        int index = -1;
        if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            ptr = new wxImage(name,mimetype,index);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            ptr = new wxImage(name,type,index);
        }
    } else {
        wxInputStream *stream;
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        int index = -1;
        Data_Get_Struct(argv[0], wxInputStream, stream);
        if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            ptr = new wxImage(*stream,mimetype,index);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            ptr = new wxImage(*stream,type,index);
        }
    }

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxImage::ConvertToBitmap(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return WxBitmap::init0(wxBitmap(*ptr));
}

VALUE
WxImage::ConvertToMono(VALUE self,VALUE vr,VALUE vg,VALUE vb)
{
    unsigned char r = NUM2INT(vr);
    unsigned char g = NUM2INT(vg);
    unsigned char b = NUM2INT(vb);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage mono = ptr->ConvertToMono(r,g,b);
    return WxImage::init0(&mono);
}

VALUE
WxImage::Copy(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage copy = ptr->Copy();
    return WxImage::init0(&copy);
}

void
WxImage::Create(VALUE self,VALUE vwidth,VALUE vheight)
{
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->Create(width,height);
}

void
WxImage::Destroy(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->Destroy();
}

VALUE
WxImage::GetBlue(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetBlue(x,y));
}

VALUE
WxImage::GetData(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return rb_str_new((const char *)ptr->GetData(),ptr->GetWidth() * ptr->GetHeight() * 3);
}

VALUE
WxImage::GetGreen(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetGreen(x,y));
}

VALUE
WxImage::GetImageCount(int argc, VALUE *argv, VALUE self)
{
    long type = wxBITMAP_TYPE_ANY;
    if(argc>1) type = NUM2INT(argv[1]);
    if(TYPE(argv[0])==T_STRING) {
        wxString filename = StringValuePtr(argv[0]);
        return INT2NUM(wxImage::GetImageCount(filename,type));
    } else {
        wxInputStream *stream;
        Data_Get_Struct(argv[0], wxInputStream, stream);
        return INT2NUM(wxImage::GetImageCount(*stream,type));
    }
}

VALUE
WxImage::GetRed(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetRed(x,y));
}

VALUE
WxImage::GetHeight(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetHeight());
}

VALUE
WxImage::GetMaskBlue(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetMaskBlue());
}

VALUE
WxImage::GetMaskGreen(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetMaskGreen());
}

VALUE
WxImage::GetMaskRed(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetMaskRed());
}

VALUE
WxImage::GetPalette(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return WxPalette::init0((wxPalette*)&ptr->GetPalette());
}

VALUE
WxImage::GetSubImage(VALUE self,VALUE vrect)
{
    wxRect *rect;
    Data_Get_Struct(vrect, wxRect, rect);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage subImage = ptr->GetSubImage(*rect);
    return WxImage::init0(&subImage);
}

VALUE
WxImage::GetWidth(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetWidth());
}

VALUE
WxImage::HasMask(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return (ptr->HasMask() ? Qtrue : Qfalse);
}

VALUE
WxImage::GetOption(VALUE self,VALUE vname)
{
    wxString name = StringValuePtr(vname);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return rb_str_new2(ptr->GetOption(name));
}

VALUE
WxImage::GetOptionInt(VALUE self,VALUE vname)
{
    wxString name = StringValuePtr(vname);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return INT2NUM(ptr->GetOptionInt(name));
}

VALUE
WxImage::HasOption(VALUE self,VALUE vname)
{
    wxString name = StringValuePtr(vname);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return (ptr->HasOption(name) ? Qtrue : Qfalse);
}

VALUE
WxImage::LoadFile(int argc, VALUE *argv, VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);

    if(TYPE(argv[0])==T_STRING) {
        wxString name = StringValuePtr(argv[0]);
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        int index = -1;
        if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            return (ptr->LoadFile(name,mimetype,index) ? Qtrue : Qfalse);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            return (ptr->LoadFile(name,type,index) ? Qtrue : Qfalse);
        }
    } else {
        wxInputStream *stream;
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        int index = -1;
        Data_Get_Struct(argv[0], wxInputStream, stream);
        if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            return (ptr->LoadFile(*stream,mimetype,index) ? Qtrue : Qfalse);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            if(argc>2) index = NUM2INT(argv[2]);
            return (ptr->LoadFile(*stream,type,index) ? Qtrue : Qfalse);
        }
    }
}

VALUE
WxImage::Ok(VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

VALUE
WxImage::SaveFile(int argc, VALUE *argv, VALUE self)
{
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);

    if(TYPE(argv[0])==T_STRING) {
        wxString name = StringValuePtr(argv[0]);
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        if(argc==1) {
            return (ptr->SaveFile(name) ? Qtrue : Qfalse);
        }
        else if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            return (ptr->SaveFile(name,mimetype) ? Qtrue : Qfalse);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            return (ptr->SaveFile(name,type) ? Qtrue : Qfalse);
        }
    } else {
        wxOutputStream *stream;
        long type = wxBITMAP_TYPE_ANY;
        wxString mimetype;
        Data_Get_Struct(argv[0], wxOutputStream, stream);
        if(argc>1 && TYPE(argv[1])==T_STRING) {
            mimetype = StringValuePtr(argv[1]);
            return (ptr->SaveFile(*stream,mimetype) ? Qtrue : Qfalse);
        } else {
            if(argc>1) type = NUM2INT(argv[1]);
            return (ptr->SaveFile(*stream,type) ? Qtrue : Qfalse);
        }
    }
}

VALUE
WxImage::Mirror(int argc, VALUE *argv, VALUE self)
{
    bool horizontally = TRUE;
    if(argc>0 && argv[0]==Qfalse) horizontally = FALSE;
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage mirror = ptr->Mirror(horizontally);
    return WxImage::init0(&mirror);
}

void
WxImage::Replace(VALUE self,VALUE vr1,VALUE vg1,VALUE vb1,VALUE vr2,VALUE vg2,VALUE vb2)
{
    unsigned char r1 = NUM2INT(vr1);
    unsigned char g1 = NUM2INT(vg1);
    unsigned char b1 = NUM2INT(vb1);
    unsigned char r2 = NUM2INT(vr2);
    unsigned char g2 = NUM2INT(vg2);
    unsigned char b2 = NUM2INT(vb2);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->Replace(r1,g1,b1,r2,g2,b2);
}

VALUE
WxImage::Rescale(VALUE self,VALUE vwidth,VALUE vheight)
{
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return WxImage::init0(ptr->Rescale(width,height));
}

VALUE
WxImage::Rotate(int argc, VALUE *argv, VALUE self)
{
    double angle = (double)(RFLOAT(argv[0])->value);
    wxPoint *rotationCentre;
    Data_Get_Struct(argv[1], wxPoint, rotationCentre);
    bool interpolating = TRUE;
    if(argc>2 && argv[2]==Qfalse) interpolating = FALSE;
    wxPoint* offsetAfterRotation = NULL;
    if(argc>3)
        Data_Get_Struct(argv[3], wxPoint, offsetAfterRotation);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage rotated = ptr->Rotate(angle,*rotationCentre,interpolating,offsetAfterRotation);
    return WxImage::init0(&rotated);
}

VALUE
WxImage::Rotate90(int argc, VALUE *argv, VALUE self)
{
    bool clockwise = TRUE;
    if(argc>0 && argv[0]==Qfalse) clockwise = FALSE;
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage rotated = ptr->Rotate90(clockwise);
    return WxImage::init0(&rotated);
}

VALUE
WxImage::Scale(VALUE self,VALUE vwidth,VALUE vheight)
{
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
	wxImage scaled = ptr->Scale(width,height);
    return WxImage::init0(&scaled);
}

void
WxImage::SetData(VALUE self,VALUE vdata)
{
    unsigned char *data = (unsigned char *)StringValuePtr(vdata);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->SetData(data);
}

void
WxImage::SetMask(int argc, VALUE *argv, VALUE self)
{
    bool hasMask = TRUE;
    if(argc>0 && argv[0]==Qfalse) hasMask = FALSE;
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->SetMask(hasMask);
}

void
WxImage::SetMaskColour(VALUE self,VALUE vred,VALUE vblue,VALUE vgreen)
{
    unsigned char red = NUM2INT(vred);
    unsigned char blue = NUM2INT(vblue);
    unsigned char green = NUM2INT(vgreen);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->SetMaskColour(red,blue,green);
}

VALUE
WxImage::SetMaskFromImage(VALUE self,VALUE vmask,VALUE vred,VALUE vblue,VALUE vgreen)
{
    wxImage *mask;
    Data_Get_Struct(vmask,wxImage,mask);
    unsigned char red = NUM2INT(vred);
    unsigned char blue = NUM2INT(vblue);
    unsigned char green = NUM2INT(vgreen);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    return (ptr->SetMaskFromImage(*mask,red,blue,green) ? Qtrue : Qfalse);
}

void
WxImage::SetOption(VALUE self,VALUE vname,VALUE vvalue)
{
    wxString name = StringValuePtr(vname);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    if(TYPE(vvalue)==T_STRING) {
        wxString value = StringValuePtr(vvalue);
        ptr->SetOption(name,value);
    } else {
        int value = NUM2INT(vvalue);
        ptr->SetOption(name,value);
    }
}

void
WxImage::SetPalette(VALUE self,VALUE vpalette)
{
    wxPalette *palette;
    Data_Get_Struct(vpalette, wxPalette, palette);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->SetPalette(*palette);
}

void
WxImage::SetRGB(VALUE self,VALUE vx,VALUE vy,VALUE vred,VALUE vblue,VALUE vgreen)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    unsigned char red = NUM2INT(vred);
    unsigned char blue = NUM2INT(vblue);
    unsigned char green = NUM2INT(vgreen);
    wxImage *ptr;
    Data_Get_Struct(self, wxImage, ptr);
    ptr->SetRGB(x,y,red,blue,green);
}

VALUE
WxImage::init0(wxImage image)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxImage(image);
    return self;
}

VALUE WxImage::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxImage::DefineClass();
    }
};
static ZAutoDefine x;
