/**********************************************************************

  dc.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "dc.h"
#include "font.h"
#include "colour.h"
#include "pen.h"
#include "brush.h"

void WxDC::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"DC", rb_cObject);
	rb_define_alloc_func(rubyClass,WxDC::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxDC::init), 0);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxDC::free), 0);
	rb_define_method(rubyClass, "begin_drawing", VALUEFUNC(WxDC::BeginDrawing), 0);
	rb_define_method(rubyClass, "blit", VALUEFUNC(WxDC::Blit), -1);
	rb_define_method(rubyClass, "calc_bounding_box", VALUEFUNC(WxDC::CalcBoundingBox), 2);
	rb_define_method(rubyClass, "clear", VALUEFUNC(WxDC::Clear), 0);
	rb_define_method(rubyClass, "cross_hair", VALUEFUNC(WxDC::CrossHair), 2);
	rb_define_method(rubyClass, "destroy_clipping_region", VALUEFUNC(WxDC::DestroyClippingRegion), 0);
	rb_define_method(rubyClass, "device_to_logical_x", VALUEFUNC(WxDC::DeviceToLogicalX), 1);
	rb_define_method(rubyClass, "device_to_logical_x_rel", VALUEFUNC(WxDC::DeviceToLogicalXRel), 1);
	rb_define_method(rubyClass, "device_to_logical_y", VALUEFUNC(WxDC::DeviceToLogicalY), 1);
	rb_define_method(rubyClass, "device_to_logical_y_rel", VALUEFUNC(WxDC::DeviceToLogicalYRel), 1);
	rb_define_method(rubyClass, "draw_arc", VALUEFUNC(WxDC::DrawArc), 6);
	rb_define_method(rubyClass, "draw_bitmap", VALUEFUNC(WxDC::DrawBitmap), 4);
	rb_define_method(rubyClass, "draw_check_mark", VALUEFUNC(WxDC::DrawCheckMark), -1);
	rb_define_method(rubyClass, "draw_circle", VALUEFUNC(WxDC::DrawCircle), -1);
	rb_define_method(rubyClass, "draw_ellipse", VALUEFUNC(WxDC::DrawEllipse), -1);
	rb_define_method(rubyClass, "draw_elliptic_arc", VALUEFUNC(WxDC::DrawEllipticArc), 6);
	rb_define_method(rubyClass, "draw_icon", VALUEFUNC(WxDC::DrawIcon), 3);
	rb_define_method(rubyClass, "draw_line", VALUEFUNC(WxDC::DrawLine), 4);
	rb_define_method(rubyClass, "draw_lines", VALUEFUNC(WxDC::DrawLines), -1);
	rb_define_method(rubyClass, "draw_point", VALUEFUNC(WxDC::DrawPoint), 2);
	rb_define_method(rubyClass, "draw_polygon", VALUEFUNC(WxDC::DrawPolygon), -1);
	rb_define_method(rubyClass, "draw_rectangle", VALUEFUNC(WxDC::DrawRectangle), 4);
	rb_define_method(rubyClass, "draw_rotated_text", VALUEFUNC(WxDC::DrawRotatedText), 4);
	rb_define_method(rubyClass, "draw_spline", VALUEFUNC(WxDC::DrawSpline), 1);
	rb_define_method(rubyClass, "draw_text", VALUEFUNC(WxDC::DrawText), -1);
	rb_define_method(rubyClass, "draw_rounded_rectangle", VALUEFUNC(WxDC::DrawRoundedRectangle), -1);
	rb_define_method(rubyClass, "end_doc", VALUEFUNC(WxDC::EndDoc), 0);
	rb_define_method(rubyClass, "end_drawing", VALUEFUNC(WxDC::EndDrawing), 0);
	rb_define_method(rubyClass, "end_page", VALUEFUNC(WxDC::EndPage), 0);
	rb_define_method(rubyClass, "flood_fill", VALUEFUNC(WxDC::FloodFill), -1);
	rb_define_method(rubyClass, "get_background", VALUEFUNC(WxDC::GetBackground), 0);
	rb_define_method(rubyClass, "get_background_mode", VALUEFUNC(WxDC::GetBackgroundMode), 0);
	rb_define_method(rubyClass, "get_brush", VALUEFUNC(WxDC::GetBrush), 0);
	rb_define_method(rubyClass, "get_char_height", VALUEFUNC(WxDC::GetCharHeight), 0);
	rb_define_method(rubyClass, "get_char_width", VALUEFUNC(WxDC::GetCharWidth), 0);
	rb_define_method(rubyClass, "get_clipping_box", VALUEFUNC(WxDC::GetClippingBox), 0);
	rb_define_method(rubyClass, "get_font", VALUEFUNC(WxDC::GetFont), 0);
	rb_define_method(rubyClass, "get_logical_function", VALUEFUNC(WxDC::GetLogicalFunction), 0);
	rb_define_method(rubyClass, "get_map_mode", VALUEFUNC(WxDC::GetMapMode), 0);
	rb_define_method(rubyClass, "get_optimization", VALUEFUNC(WxDC::GetOptimization), 0);
	rb_define_method(rubyClass, "get_pen", VALUEFUNC(WxDC::GetPen), 0);
	rb_define_method(rubyClass, "get_pixel", VALUEFUNC(WxDC::GetPixel), 2);
	rb_define_method(rubyClass, "get_size", VALUEFUNC(WxDC::GetSize), 0);
	rb_define_method(rubyClass, "get_text_background", VALUEFUNC(WxDC::GetTextBackground), 0);
	rb_define_method(rubyClass, "get_text_extent", VALUEFUNC(WxDC::GetTextExtent), -1);
	rb_define_method(rubyClass, "get_text_foreground", VALUEFUNC(WxDC::GetTextForeground), 0);
	rb_define_method(rubyClass, "get_user_scale", VALUEFUNC(WxDC::GetUserScale), 0);
	rb_define_method(rubyClass, "logical_to_device_x", VALUEFUNC(WxDC::LogicalToDeviceX), 1);
	rb_define_method(rubyClass, "logical_to_device_x_rel", VALUEFUNC(WxDC::LogicalToDeviceXRel), 1);
	rb_define_method(rubyClass, "logical_to_device_y", VALUEFUNC(WxDC::LogicalToDeviceY), 1);
	rb_define_method(rubyClass, "logical_to_device_y_rel", VALUEFUNC(WxDC::LogicalToDeviceYRel), 1);
	rb_define_method(rubyClass, "max_x", VALUEFUNC(WxDC::MaxX), 0);
	rb_define_method(rubyClass, "max_y", VALUEFUNC(WxDC::MaxY), 0);
	rb_define_method(rubyClass, "min_x", VALUEFUNC(WxDC::MinX), 0);
	rb_define_method(rubyClass, "min_y", VALUEFUNC(WxDC::MinY), 0);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxDC::Ok), 0);
	rb_define_method(rubyClass, "reset_bounding_box", VALUEFUNC(WxDC::ResetBoundingBox), 0);
	rb_define_method(rubyClass, "set_axis_orientation", VALUEFUNC(WxDC::SetAxisOrientation), 2);
	rb_define_method(rubyClass, "set_background", VALUEFUNC(WxDC::SetBackground), 1);
	rb_define_method(rubyClass, "set_background_mode", VALUEFUNC(WxDC::SetBackgroundMode), 1);
	rb_define_method(rubyClass, "set_brush", VALUEFUNC(WxDC::SetBrush), 1);
	rb_define_method(rubyClass, "set_clipping_region", VALUEFUNC(WxDC::SetClippingRegion), -1);
	rb_define_method(rubyClass, "set_device_origin", VALUEFUNC(WxDC::SetDeviceOrigin), 2);
	rb_define_method(rubyClass, "set_font", VALUEFUNC(WxDC::SetFont), 1);
	rb_define_method(rubyClass, "set_logical_function", VALUEFUNC(WxDC::SetLogicalFunction),12);
	rb_define_method(rubyClass, "set_map_mode", VALUEFUNC(WxDC::SetMapMode), 1);
	rb_define_method(rubyClass, "set_optimization", VALUEFUNC(WxDC::SetOptimization), 1);
	rb_define_method(rubyClass, "set_palette", VALUEFUNC(WxDC::SetPalette), 1);
	rb_define_method(rubyClass, "set_pen", VALUEFUNC(WxDC::SetPen), 1);
	rb_define_method(rubyClass, "set_text_background", VALUEFUNC(WxDC::SetTextBackground), 1);
	rb_define_method(rubyClass, "set_text_foreground", VALUEFUNC(WxDC::SetTextForeground), 1);
	rb_define_method(rubyClass, "set_user_scale", VALUEFUNC(WxDC::SetUserScale), 2);
	rb_define_method(rubyClass, "start_doc", VALUEFUNC(WxDC::StartDoc), 1);
	rb_define_method(rubyClass, "start_page", VALUEFUNC(WxDC::StartPage), 0);
}

VALUE
WxDC::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxDC::init(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr = NULL;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxDC::init0(wxDC *dc)
{
    if(dc==NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = dc;
    return self;
}

void
WxDC::free(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    delete ptr;
}

void
WxDC::BeginDrawing(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->BeginDrawing();
}

VALUE
WxDC::Blit(int argc, VALUE *argv, VALUE self)
{
    wxCoord xdest = NUM2INT(argv[0]);
    wxCoord ydest = NUM2INT(argv[1]);
    wxCoord width = NUM2INT(argv[2]);
    wxCoord height = NUM2INT(argv[3]);
    wxDC* source;
    Data_Get_Struct(argv[4], wxDC, source);
    wxCoord xsrc = NUM2INT(argv[5]);
    wxCoord ysrc = NUM2INT(argv[6]);
    int logicalFunc = wxCOPY;
    if(argc>7) logicalFunc = NUM2INT(argv[7]);
    bool useMask = FALSE;
    if(argc>8 && argv[8]==Qtrue) useMask = TRUE;
    wxCoord xsrcMask = -1;
    if(argc>9) xsrcMask = NUM2INT(argv[9]);
    wxCoord ysrcMask = -1;
    if(argc>10) ysrcMask = NUM2INT(argv[10]);

    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return (ptr->Blit(xdest,ydest,width,height,source,xsrc,ysrc,logicalFunc,useMask,xsrcMask = -1,ysrcMask) ? Qtrue : Qfalse);
}

void
WxDC::CalcBoundingBox(VALUE self,VALUE vx,VALUE vy)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->CalcBoundingBox(x,y);
}

void
WxDC::Clear(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->Clear();
}

void
WxDC::CrossHair(VALUE self,VALUE vx,VALUE vy)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->CrossHair(x,y);
}

void
WxDC::DestroyClippingRegion(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DestroyClippingRegion();
}

VALUE
WxDC::DeviceToLogicalX(VALUE self,VALUE vx)
{
    wxCoord x = NUM2INT(vx);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->DeviceToLogicalX(x));
}

VALUE
WxDC::DeviceToLogicalXRel(VALUE self,VALUE vx)
{
    wxCoord x = NUM2INT(vx);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->DeviceToLogicalXRel(x));
}

VALUE
WxDC::DeviceToLogicalY(VALUE self,VALUE vy)
{
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->DeviceToLogicalY(y));
}

VALUE
WxDC::DeviceToLogicalYRel(VALUE self,VALUE vy)
{
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->DeviceToLogicalYRel(y));
}

void
WxDC::DrawArc(VALUE self,VALUE vx1,VALUE vy1,VALUE vx2,VALUE vy2,VALUE vxc,VALUE vyc)
{
    wxCoord x1 = NUM2INT(vx1);
    wxCoord y1 = NUM2INT(vy1);
    wxCoord x2 = NUM2INT(vx2);
    wxCoord y2 = NUM2INT(vy2);
    wxCoord xc = NUM2INT(vxc);
    wxCoord yc = NUM2INT(vyc);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawArc(x1,y1,x2,y2,xc,yc);
}

void
WxDC::DrawBitmap(VALUE self,VALUE vbitmap,VALUE vx,VALUE vy,VALUE vtransparent)
{
    wxBitmap *bitmap;
    Data_Get_Struct(vbitmap, wxBitmap, bitmap);
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    bool transparent = (vtransparent == Qtrue);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawBitmap(*bitmap,x,y,transparent);
}

void
WxDC::DrawCheckMark(int argc, VALUE *argv, VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    if(argc==1 && TYPE(argv[0])==T_DATA) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        ptr->DrawCheckMark(*rect);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        ptr->DrawCheckMark(x,y,width,height);
    }
}

void
WxDC::DrawCircle(int argc, VALUE *argv, VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    if(argc==2 && TYPE(argv[0])==T_DATA) {
        wxPoint *pt;
        wxCoord radius = NUM2INT(argv[1]);
        Data_Get_Struct(argv[0], wxPoint, pt);
        ptr->DrawCircle(*pt,radius);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord radius = NUM2INT(argv[2]);
        ptr->DrawCircle(x,y,radius);
    }
}

void
WxDC::DrawEllipse(int argc, VALUE *argv, VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    if(argc==1 && TYPE(argv[0])==T_DATA) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        ptr->DrawEllipse(*rect);
    } else if(argc==2 && TYPE(argv[0])==T_DATA) {
        wxPoint *pt;
        wxSize *size;
        Data_Get_Struct(argv[0], wxPoint, pt);
        Data_Get_Struct(argv[1], wxSize, size);
        ptr->DrawEllipse(*pt,*size);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        ptr->DrawEllipse(x,y,width,height);
    }
}

void
WxDC::DrawEllipticArc(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight,VALUE vstart,VALUE vend)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxCoord width = NUM2INT(vwidth);
    wxCoord height = NUM2INT(vheight);
    double start;
    if(TYPE(vstart)==T_FIXNUM)
        start = NUM2INT(vstart);
    else
        start = (double)(RFLOAT(vstart)->value);
    double end;
    if(TYPE(vend)==T_FIXNUM)
        end = NUM2INT(vend);
    else
        end = (double)(RFLOAT(vend)->value);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawEllipticArc(x,y,width,height,start,end);
}

void
WxDC::DrawIcon(VALUE self,VALUE vicon,VALUE vx,VALUE vy)
{
    wxIcon *icon;
    Data_Get_Struct(vicon, wxIcon, icon);
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawIcon(*icon,x,y);
}

void
WxDC::DrawLines(int argc, VALUE *argv, VALUE self)
{
    int n = RARRAY(argv[0])->len;
    wxPoint *points = new wxPoint[n];
    for (int i = 0; i < n; i++) {
        wxPoint *ptr;
        Data_Get_Struct(RARRAY(argv[0])->ptr[i], wxPoint, ptr);
        points[i] = *ptr;
    }
    wxCoord xoffset = 0;
    if(argc>1) xoffset = NUM2INT(argv[1]);
    wxCoord yoffset = 0;
    if(argc>2) yoffset = NUM2INT(argv[2]);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawLines(n,points,xoffset,yoffset);
}

void
WxDC::DrawPolygon(int argc, VALUE *argv, VALUE self)
{
    int n = RARRAY(argv[0])->len;
    wxPoint *points = new wxPoint[n];
    for (int i = 0; i < RARRAY(argv[0])->len; i++) {
        wxPoint *ptr;
        Data_Get_Struct(RARRAY(argv[0])->ptr[i], wxPoint, ptr);
        points[i] = *ptr;
    }
    wxCoord xoffset = 0;
    if(argc>1) xoffset = NUM2INT(argv[1]);
    wxCoord yoffset = 0;
    if(argc>2) yoffset = NUM2INT(argv[2]);
    int fill_style = wxODDEVEN_RULE;
    if(argc>3) fill_style = NUM2INT(argv[3]);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawPolygon(n,points,xoffset,yoffset,fill_style);
}

void
WxDC::DrawPoint(VALUE self,VALUE vx,VALUE vy)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawPoint(x,y);
}

void
WxDC::DrawLine(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxCoord width = NUM2INT(vwidth);
    wxCoord height = NUM2INT(vheight);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawLine(x,y,width,height);
}

void
WxDC::DrawRectangle(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxCoord width = NUM2INT(vwidth);
    wxCoord height = NUM2INT(vheight);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawRectangle(x,y,width,height);
}

void
WxDC::DrawRotatedText(VALUE self,VALUE vtext,VALUE vx,VALUE vy,VALUE vangle)
{
    wxString text = StringValuePtr(vtext);
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    double angle;
    if(TYPE(vangle)==T_FIXNUM)
        angle = NUM2INT(vangle);
    else
        angle = (double)(RFLOAT(vangle)->value);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawRotatedText(text,x,y,angle);
}


void
WxDC::DrawSpline(VALUE self,VALUE vpoints)
{
    wxList points;
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    int n = RARRAY(vpoints)->len;
    for (int i = 0; i < n; i++) {
        wxPoint *ptr;
        Data_Get_Struct(RARRAY(vpoints)->ptr[i], wxPoint, ptr);
        points.Append((wxObject*)ptr);
    }
    ptr->DrawSpline(&points);
}

void
WxDC::DrawText(int argc, VALUE *argv, VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    wxString text = StringValuePtr(argv[0]);
    if(argc==3) {
        wxCoord x = NUM2INT(argv[1]);
        wxCoord y = NUM2INT(argv[2]);
        ptr->DrawText(text,x,y);
    } else {
        wxPoint *pt;
        Data_Get_Struct(argv[1], wxPoint, pt);
        ptr->DrawText(text,*pt);
    }
}

void
WxDC::DrawRoundedRectangle(int argc, VALUE *argv, VALUE self)
{
    wxCoord x = NUM2INT(argv[0]);
    wxCoord y = NUM2INT(argv[1]);
    wxCoord width = NUM2INT(argv[2]);
    wxCoord height = NUM2INT(argv[3]);
    double radius = 20;
    if(argc>4) {
        if(TYPE(argv[4])==T_FIXNUM)
            radius = NUM2INT(argv[4]);
        else
            radius = (double)(RFLOAT(argv[4])->value);
    }
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->DrawRoundedRectangle(x,y,width,height,radius);
}

// void DrawSpline(wxList *points)

void
WxDC::EndDoc(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->EndDoc();
}

void
WxDC::EndDrawing(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->EndDrawing();
}

void
WxDC::EndPage(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->EndPage();
}

VALUE
WxDC::FloodFill(int argc, VALUE *argv, VALUE self)
{
    wxCoord x = NUM2INT(argv[0]);
    wxCoord y = NUM2INT(argv[1]);
    wxColour *colour;
    Data_Get_Struct(argv[2], wxColour, colour);
    int style = wxFLOOD_SURFACE;
    if(argc>3) style = NUM2INT(argv[3]);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return (ptr->FloodFill(x,y,*colour,style) ? Qtrue : Qfalse);
}

VALUE
WxDC::GetBackground(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxBrush::init0(ptr->GetBackground());
}

VALUE
WxDC::GetBackgroundMode(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->GetBackgroundMode());
}

VALUE
WxDC::GetBrush(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxBrush::init0(ptr->GetBrush());
}

VALUE
WxDC::GetCharHeight(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->GetCharHeight());
}

VALUE
WxDC::GetCharWidth(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->GetCharWidth());
}

VALUE
WxDC::GetClippingBox(VALUE self)
{
    wxCoord x;
    wxCoord y;
    wxCoord width;
    wxCoord height;
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->GetClippingBox(&x,&y,&width,&height);
    return rb_ary_new3(4,INT2NUM(x),INT2NUM(y),INT2NUM(width),INT2NUM(height));
}

VALUE
WxDC::GetFont(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxFont::init0(ptr->GetFont());
}

VALUE
WxDC::GetLogicalFunction(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->GetLogicalFunction());
}

VALUE
WxDC::GetMapMode(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->GetMapMode());
}

VALUE
WxDC::GetOptimization(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return (ptr->GetOptimization() ? Qtrue : Qfalse);
}

VALUE
WxDC::GetPen(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxPen::init0(&ptr->GetPen());
}

VALUE
WxDC::GetPixel(VALUE self,VALUE vx,VALUE vy)
{
    wxCoord x = NUM2INT(vx);
    wxCoord y = NUM2INT(vy);
    wxColour colour;
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->GetPixel(x,y,&colour);
    return WxColour::init0(colour);
}

VALUE
WxDC::GetSize(VALUE self)
{
    wxCoord width;
    wxCoord height;
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->GetSize(&width,&height);
    return rb_ary_new3(2,INT2NUM(width),INT2NUM(height));
}

VALUE
WxDC::GetTextBackground(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxColour::init0(ptr->GetTextBackground());
}

VALUE
WxDC::GetTextExtent(int argc, VALUE *argv, VALUE self)
{
    wxString string = StringValuePtr(argv[0]);
    wxCoord w;
    wxCoord h;
    wxCoord descent;
    wxCoord externalLeading;
    wxFont *font = NULL;
    if(argc>1) {
        Data_Get_Struct(argv[1], wxFont, font);
    }
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->GetTextExtent(string,&w,&h,&descent,&externalLeading,font);
    return rb_ary_new3(4,INT2NUM(w),INT2NUM(h),INT2NUM(descent),INT2NUM(externalLeading));
}

VALUE
WxDC::GetTextForeground(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return WxColour::init0(ptr->GetTextForeground());
}

VALUE
WxDC::GetUserScale(VALUE self)
{
    double x;
    double y;
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->GetUserScale(&x,&y);
    return rb_ary_new3(2,rb_float_new(x),rb_float_new(y));
}

VALUE
WxDC::LogicalToDeviceX(VALUE self,VALUE vx)
{
    wxCoord x = NUM2INT(vx);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->LogicalToDeviceX(x));
}

VALUE
WxDC::LogicalToDeviceXRel(VALUE self,VALUE vx)
{
    wxCoord x = NUM2INT(vx);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->LogicalToDeviceXRel(x));
}

VALUE
WxDC::LogicalToDeviceY(VALUE self,VALUE vy)
{
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->LogicalToDeviceY(y));
}

VALUE
WxDC::LogicalToDeviceYRel(VALUE self,VALUE vy)
{
    wxCoord y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->LogicalToDeviceYRel(y));
}

VALUE
WxDC::MaxX(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->MaxX());
}

VALUE
WxDC::MaxY(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->MaxY());
}

VALUE
WxDC::MinX(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->MinX());
}

VALUE
WxDC::MinY(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return INT2NUM(ptr->MinY());
}

VALUE
WxDC::Ok(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxDC::ResetBoundingBox(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->ResetBoundingBox();
}

void
WxDC::SetAxisOrientation(VALUE self,VALUE vxLeftRight,VALUE vyBottomUp)
{
    bool xLeftRight = NUM2INT(vxLeftRight);
    bool yBottomUp = NUM2INT(vyBottomUp);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetAxisOrientation(xLeftRight,yBottomUp);
}

void
WxDC::SetDeviceOrigin(VALUE self,VALUE vx,VALUE vy)
{
    bool x = NUM2INT(vx);
    bool y = NUM2INT(vy);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetDeviceOrigin(x,y);
}

void
WxDC::SetBackground(VALUE self,VALUE vbrush)
{
    wxBrush *brush;
    Data_Get_Struct(vbrush, wxBrush, brush);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetBackground(*brush);
}

void
WxDC::SetBackgroundMode(VALUE self,VALUE vmode)
{
    int mode = NUM2INT(vmode);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetBackgroundMode(mode);
}

void
WxDC::SetClippingRegion(int argc, VALUE *argv, VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    if(argc==1) {
        wxRect *rect;
        Data_Get_Struct(argv[0], wxRect, rect);
        ptr->SetClippingRegion(*rect);
    } else if(argc==2) {
        wxPoint *pt;
        wxSize *sz;
        Data_Get_Struct(argv[0], wxPoint, pt);
        Data_Get_Struct(argv[1], wxSize, sz);
        ptr->SetClippingRegion(*pt,*sz);
    } else {
        wxCoord x = NUM2INT(argv[0]);
        wxCoord y = NUM2INT(argv[1]);
        wxCoord width = NUM2INT(argv[2]);
        wxCoord height = NUM2INT(argv[3]);
        ptr->SetClippingRegion(x,y,width,height);
    }
}

void
WxDC::SetPalette(VALUE self,VALUE vpalette)
{
    wxPalette *palette;
    Data_Get_Struct(vpalette, wxPalette, palette);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetPalette(*palette);
}

void
WxDC::SetBrush(VALUE self,VALUE vbrush)
{
    wxBrush *brush;
    Data_Get_Struct(vbrush, wxBrush, brush);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetBrush(*brush);
}

void
WxDC::SetFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetFont(*font);
}

void
WxDC::SetLogicalFunction(VALUE self,VALUE vfunction)
{
    int function = NUM2INT(vfunction);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetLogicalFunction(function);
}

void
WxDC::SetMapMode(VALUE self,VALUE vint)
{
    int mode = NUM2INT(vint);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetMapMode(mode);
}

void
WxDC::SetOptimization(VALUE self,VALUE voptimize)
{
    bool optimize = (voptimize == Qtrue);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetOptimization(optimize);
}

void
WxDC::SetPen(VALUE self,VALUE vpen)
{
    wxPen *pen;
    Data_Get_Struct(vpen, wxPen, pen);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetPen(*pen);
}

void
WxDC::SetTextBackground(VALUE self,VALUE vcolour)
{
    wxColour *colour;
    Data_Get_Struct(vcolour, wxColour, colour);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetTextBackground(*colour);
}

void
WxDC::SetTextForeground(VALUE self,VALUE vcolour)
{
    wxColour *colour;
    Data_Get_Struct(vcolour, wxColour, colour);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetTextForeground(*colour);
}

void
WxDC::SetUserScale(VALUE self,VALUE vxScale,VALUE vyScale)
{
    double xScale = (double)(RFLOAT(vxScale)->value);
    double yScale = (double)(RFLOAT(vyScale)->value);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->SetUserScale(xScale,yScale);
}

void
WxDC::StartDoc(VALUE self,VALUE vmessage)
{
    wxString message = StringValuePtr(vmessage);
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->StartDoc(message);
}

void
WxDC::StartPage(VALUE self)
{
    wxDC *ptr;
    Data_Get_Struct(self, wxDC, ptr);
    ptr->StartPage();
}

VALUE WxDC::rubyClass;

class ZAutoDefineWxDC
{
public:
   ZAutoDefineWxDC()
    {
       WxDC::DefineClass();
    }
};
static ZAutoDefineWxDC x;

//-------------------------------------------------------------------------------
void WxMemoryDC::DefineClass()
{
	if(rubyClass)
		return;
	WxDC::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"MemoryDC", WxDC::rubyClass);
	rb_define_alloc_func(rubyClass,WxMemoryDC::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxMemoryDC::init), 0);
	rb_define_method(rubyClass, "select_object", VALUEFUNC(WxMemoryDC::SelectObject), 1);
}

VALUE
WxMemoryDC::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxMemoryDC::init(VALUE self)
{
    wxMemoryDC *ptr;
    Data_Get_Struct(self, wxMemoryDC, ptr);
    ptr = new wxMemoryDC();
    DATA_PTR(self) = ptr;
    return self;
}

void
WxMemoryDC::SelectObject(VALUE self,VALUE vbitmap)
{
    wxBitmap *bitmap;
    Data_Get_Struct(vbitmap, wxBitmap, bitmap);
    wxMemoryDC *ptr;
    Data_Get_Struct(self, wxMemoryDC, ptr);
    ptr->SelectObject(*bitmap);
}

VALUE WxMemoryDC::rubyClass;

class ZAutoDefineWxMemoryDC
{
public:
   ZAutoDefineWxMemoryDC()
    {
       WxMemoryDC::DefineClass();
    }
};
static ZAutoDefineWxMemoryDC x2;

//-------------------------------------------------------------------------------
void WxWindowDC::DefineClass()
{
	if(rubyClass)
		return;
	WxDC::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"WindowDC", WxDC::rubyClass);
	rb_define_alloc_func(rubyClass,WxWindowDC::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxWindowDC::init), 1);
}

VALUE
WxWindowDC::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxWindowDC::init(VALUE self,VALUE vwindow)
{
    wxWindow *window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxWindowDC *ptr;
    Data_Get_Struct(self, wxWindowDC, ptr);
    ptr = new wxWindowDC(window);
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxWindowDC::rubyClass;

class ZAutoDefineWxWindowDC
{
public:
   ZAutoDefineWxWindowDC()
    {
       WxWindowDC::DefineClass();
    }
};
static ZAutoDefineWxWindowDC x3;

//-------------------------------------------------------------------------------
void WxClientDC::DefineClass()
{
	if(rubyClass)
		return;
	WxWindowDC::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ClientDC", WxWindowDC::rubyClass);
	rb_define_alloc_func(rubyClass,WxClientDC::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxClientDC::init), 1);
}

VALUE
WxClientDC::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxClientDC::init(VALUE self,VALUE vwindow)
{
    wxWindow *window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxClientDC *ptr;
    Data_Get_Struct(self, wxClientDC, ptr);
    ptr = new wxClientDC(window);
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxClientDC::rubyClass;

class ZAutoDefineWxClientDC
{
public:
   ZAutoDefineWxClientDC()
    {
       WxClientDC::DefineClass();
    }
};
static ZAutoDefineWxClientDC x4;

//-------------------------------------------------------------------------------
void WxPaintDC::DefineClass()
{
	if(rubyClass)
		return;
	WxWindowDC::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"PaintDC", WxWindowDC::rubyClass);
	rb_define_alloc_func(rubyClass,WxPaintDC::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxPaintDC::init), 1);
}

VALUE
WxPaintDC::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxPaintDC::init(VALUE self,VALUE vwindow)
{
    wxWindow *window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxPaintDC *ptr;
    Data_Get_Struct(self, wxPaintDC, ptr);
    ptr = new wxPaintDC(window);
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxPaintDC::rubyClass;

class ZAutoDefineWxWxPaintDC
{
public:
   ZAutoDefineWxWxPaintDC()
    {
       WxPaintDC::DefineClass();
    }
};
static ZAutoDefineWxWxPaintDC x5;
