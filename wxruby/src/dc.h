/**********************************************************************

  dc.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_DC_H
#define WXRUBY_DC_H

class WxDC {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxDC *dc);
    static void free(VALUE self);
    static void BeginDrawing(VALUE self);
    static VALUE Blit(int argc, VALUE *argv, VALUE self);
    static void CalcBoundingBox(VALUE self,VALUE vx,VALUE vy);
    static void Clear(VALUE self);
    static void CrossHair(VALUE self,VALUE vx,VALUE vy);
    static void DestroyClippingRegion(VALUE self);
    static VALUE DeviceToLogicalX(VALUE self,VALUE vx);
    static VALUE DeviceToLogicalXRel(VALUE self,VALUE vx);
    static VALUE DeviceToLogicalY(VALUE self,VALUE vy);
    static VALUE DeviceToLogicalYRel(VALUE self,VALUE vy);
    static void DrawArc(VALUE self,VALUE vx1,VALUE vy1,VALUE vx2,VALUE vy2,VALUE vxc,VALUE vyc);
    static void DrawBitmap(VALUE self,VALUE vbitmap,VALUE vx,VALUE vy,VALUE vtransparent);
    static void DrawCheckMark(int argc, VALUE *argv, VALUE self);
    static void DrawCircle(int argc, VALUE *argv, VALUE self);
    static void DrawEllipse(int argc, VALUE *argv, VALUE self);
    static void DrawEllipticArc(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vvheight,VALUE vstart,VALUE vend);
    static void DrawIcon(VALUE self,VALUE vicon,VALUE vx,VALUE vy);
    static void DrawLines(int argc, VALUE *argv, VALUE self);
    static void DrawPoint(VALUE self,VALUE vx,VALUE vy);
    static void DrawPolygon(int argc, VALUE *argv, VALUE self);
    static void DrawLine(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight);
    static void DrawRectangle(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight);
    static void DrawRotatedText(VALUE self,VALUE vtext,VALUE vx,VALUE vy,VALUE vangle);
    static void DrawSpline(VALUE self,VALUE vpoints);
    static void DrawText(int argc, VALUE *argv, VALUE self);
    static void DrawRoundedRectangle(int argc, VALUE *argv, VALUE self);
    static void EndDoc(VALUE self);
    static void EndDrawing(VALUE self);
    static void EndPage(VALUE self);
    static VALUE FloodFill(int argc, VALUE *argv, VALUE self);
    static VALUE GetBackground(VALUE self);
    static VALUE GetBackgroundMode(VALUE self);
    static VALUE GetBrush(VALUE self);
    static VALUE GetCharHeight(VALUE self);
    static VALUE GetCharWidth(VALUE self);
    static VALUE GetClippingBox(VALUE self);
    static VALUE GetFont(VALUE self);
    static VALUE GetLogicalFunction(VALUE self);
    static VALUE GetMapMode(VALUE self);
    static VALUE GetOptimization(VALUE self);
    static VALUE GetPen(VALUE self);
    static VALUE GetPixel(VALUE self,VALUE vx,VALUE vy);
    static VALUE GetSize(VALUE self);
    static VALUE GetTextBackground(VALUE self);
    static VALUE GetTextExtent(int argc, VALUE *argv, VALUE self);
    static VALUE GetTextForeground(VALUE self);
    static VALUE GetUserScale(VALUE self);
    static VALUE LogicalToDeviceX(VALUE self,VALUE vx);
    static VALUE LogicalToDeviceXRel(VALUE self,VALUE vx);
    static VALUE LogicalToDeviceY(VALUE self,VALUE vy);
    static VALUE LogicalToDeviceYRel(VALUE self,VALUE vy);
    static VALUE MaxX(VALUE self);
    static VALUE MaxY(VALUE self);
    static VALUE MinX(VALUE self);
    static VALUE MinY(VALUE self);
    static VALUE Ok(VALUE self);
    static void ResetBoundingBox(VALUE self);
    static void SetAxisOrientation(VALUE self,VALUE vxLeftRight,VALUE vyBottomUp);
    static void SetBackground(VALUE self,VALUE vbrush);
    static void SetBackgroundMode(VALUE self,VALUE vmode);
    static void SetBrush(VALUE self,VALUE vbrush);
    static void SetClippingRegion(int argc, VALUE *argv, VALUE self);
    static void SetDeviceOrigin(VALUE self,VALUE vx,VALUE vy);
    static void SetFont(VALUE self,VALUE vfont);
    static void SetLogicalFunction(VALUE self,VALUE vfunction);
    static void SetMapMode(VALUE self,VALUE vint);
    static void SetOptimization(VALUE self,VALUE voptimize);
    static void SetPalette(VALUE self,VALUE vpalette);
    static void SetPen(VALUE self,VALUE vpen);
    static void SetTextBackground(VALUE self,VALUE vcolour);
    static void SetTextForeground(VALUE self,VALUE vcolour);
    static void SetUserScale(VALUE self,VALUE vxScale,VALUE vyScale);
    static void StartDoc(VALUE self,VALUE vmessage);
    static void StartPage(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxMemoryDC {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static void SelectObject(VALUE self,VALUE vbitmap);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxWindowDC {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vwindow);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxClientDC {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vwindow);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxPaintDC {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vwindow);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
