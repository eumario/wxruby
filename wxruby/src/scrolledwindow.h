/**********************************************************************

  scrolledwindow.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SCROLLEDWINDOW_H
#define WXRUBY_SCROLLEDWINDOW_H

class wxRbScrolledWindow : public wxScrolledWindow {
public:
    wxRbScrolledWindow(wxWindow* parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize, long style = wxHSCROLL | wxVSCROLL, const wxString& name = "scrolledWindow")
        :   wxScrolledWindow(parent,id,pos,size,style,name) { }
    virtual void OnDraw(wxDC& dc);
};

class WxScrolledWindow {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE CalcScrolledPosition(VALUE self,VALUE vx,VALUE vy);
    static VALUE CalcUnscrolledPosition(VALUE self,VALUE vx,VALUE vy);
    static void EnableScrolling(VALUE self,VALUE vxScrolling,VALUE vyScrolling);
    static VALUE GetScrollPixelsPerUnit(VALUE self);
    static VALUE GetViewStart(VALUE self);
    static VALUE GetVirtualSize(VALUE self);
    static VALUE IsRetained(VALUE self);
    static void PrepareDC(VALUE self,VALUE vdc);
    static void Scroll(VALUE self,VALUE vx,VALUE vy);
    static void SetScrollRate(VALUE self,VALUE vxstep,VALUE vystep);
    static void SetScrollbars(int argc, VALUE *argv, VALUE self);
    static void SetTargetWindow(VALUE self,VALUE vwindow);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
