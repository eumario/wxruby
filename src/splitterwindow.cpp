/**********************************************************************

  splitterwindow.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/
#include "wx.h"
#include "splitterwindow.h"
#include "window.h"

/*********** NOTE: special handling of wxSplitterWindow::Initialize(window) *******/

void WxSplitterWindow::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"SplitterWindow", WxWindow::rubyClass);
    rb_define_alloc_func(rubyClass,WxSplitterWindow::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(wrapNew), -1);
    rb_define_method(rubyClass, "initialize",VALUEFUNC(WxSplitterWindow::init),-1);
    rb_define_method(rubyClass, "get_minimum_pane_size",VALUEFUNC(WxSplitterWindow::GetMinimumPaneSize),0);
    rb_define_method(rubyClass, "get_sash_position",VALUEFUNC(WxSplitterWindow::GetSashPosition),0);
    rb_define_method(rubyClass, "get_split_mode",VALUEFUNC(WxSplitterWindow::GetSplitMode),0);
    rb_define_method(rubyClass, "get_window1",VALUEFUNC(WxSplitterWindow::GetWindow1),0);
    rb_define_method(rubyClass, "get_window2",VALUEFUNC(WxSplitterWindow::GetWindow2),0);
    rb_define_method(rubyClass, "initialize_one_pane",VALUEFUNC(WxSplitterWindow::Initialize),1);
    rb_define_method(rubyClass, "is_split",VALUEFUNC(WxSplitterWindow::IsSplit),0);
    rb_define_method(rubyClass, "replace_window",VALUEFUNC(WxSplitterWindow::ReplaceWindow),2);
    rb_define_method(rubyClass, "set_minimum_pane_size",VALUEFUNC(WxSplitterWindow::SetMinimumPaneSize),1);
    rb_define_method(rubyClass, "set_sash_position",VALUEFUNC(WxSplitterWindow::SetSashPosition),-1);
    rb_define_method(rubyClass, "set_split_mode",VALUEFUNC(WxSplitterWindow::SetSplitMode),1);
    rb_define_method(rubyClass, "split_horizontally",VALUEFUNC(WxSplitterWindow::SplitHorizontally),-1);
    rb_define_method(rubyClass, "split_vertically",VALUEFUNC(WxSplitterWindow::SplitVertically),-1);
    rb_define_method(rubyClass, "unsplit",VALUEFUNC(WxSplitterWindow::Unsplit),-1);
}

VALUE
WxSplitterWindow::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxSplitterWindow::wrapNew(int argc, VALUE *argv, VALUE self)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, argc, argv);
    return res;
}

VALUE
WxSplitterWindow::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    if(argv[0]!=Qnil)
        Data_Get_Struct(argv[0], wxWindow, parent);
    wxWindowID id = NUM2INT(argv[1]);
    wxPoint pos = wxDefaultPosition;
    if(argc>2) {
        wxPoint *ptr;
        Data_Get_Struct(argv[2], wxPoint, ptr);
        pos = *ptr;
    }
    wxSize size = wxDefaultSize;
    if(argc>3) {
        wxSize *ptr;
        Data_Get_Struct(argv[3], wxSize, ptr);
        size = *ptr;
    }
    long style=wxSP_3D;
    if(argc>4) style = NUM2INT(argv[4]);
    wxString name = "splitterWindow";
    if(argc>5) name = StringValuePtr(argv[5]);

    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    ptr = new wxSplitterWindow(parent,id,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxSplitterWindow::GetMinimumPaneSize(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return INT2NUM(ptr->GetMinimumPaneSize());
}

VALUE
WxSplitterWindow::GetSashPosition(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return INT2NUM(ptr->GetSashPosition());
}

VALUE
WxSplitterWindow::GetSplitMode(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return INT2NUM(ptr->GetSplitMode());
}

VALUE
WxSplitterWindow::GetWindow1(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return WxWindow::init0(ptr->GetWindow1());
}

VALUE
WxSplitterWindow::GetWindow2(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return WxWindow::init0(ptr->GetWindow2());
}

void
WxSplitterWindow::Initialize(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    ptr->Initialize(window);
}

VALUE
WxSplitterWindow::IsSplit(VALUE self)
{
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return (ptr->IsSplit() ? Qtrue : Qfalse);
}

VALUE
WxSplitterWindow::ReplaceWindow(VALUE self,VALUE vwinOld,VALUE vwinNew)
{
    wxWindow* winOld;
    Data_Get_Struct(vwinOld, wxWindow, winOld);
    wxWindow* winNew;
    Data_Get_Struct(vwinNew, wxWindow, winNew);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return (ptr->ReplaceWindow(winOld,winNew) ? Qtrue : Qfalse);
}

void
WxSplitterWindow::SetSashPosition(int argc, VALUE *argv, VALUE self)
{
    int position = NUM2INT(argv[0]);
    bool redraw = TRUE;
    if(argc>1 && argv[1]==Qfalse) redraw = FALSE;
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    ptr->SetSashPosition(position,redraw);
}

void
WxSplitterWindow::SetMinimumPaneSize(VALUE self,VALUE vpaneSize)
{
    int paneSize = NUM2INT(vpaneSize);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    ptr->SetMinimumPaneSize(paneSize);
}

void
WxSplitterWindow::SetSplitMode(VALUE self,VALUE vmode)
{
    int mode = NUM2INT(vmode);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    ptr->SetSplitMode(mode);
}

VALUE
WxSplitterWindow::SplitHorizontally(int argc, VALUE *argv, VALUE self)
{
    wxWindow* window1;
    Data_Get_Struct(argv[0], wxWindow, window1);
    wxWindow* window2;
    Data_Get_Struct(argv[1], wxWindow, window2);
    int sashPosition = 0;
    if(argc>2) sashPosition = NUM2INT(argv[2]);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return (ptr->SplitHorizontally(window1,window2,sashPosition) ? Qtrue : Qfalse);
}

VALUE
WxSplitterWindow::SplitVertically(int argc, VALUE *argv, VALUE self)
{
    wxWindow* window1;
    Data_Get_Struct(argv[0], wxWindow, window1);
    wxWindow* window2;
    Data_Get_Struct(argv[1], wxWindow, window2);
    int sashPosition = 0;
    if(argc>2) sashPosition = NUM2INT(argv[2]);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return (ptr->SplitVertically(window1,window2,sashPosition) ? Qtrue : Qfalse);
}

VALUE
WxSplitterWindow::Unsplit(int argc, VALUE *argv, VALUE self)
{
    wxWindow* toRemove = NULL;
    if(argc>0)
        Data_Get_Struct(argv[0], wxWindow, toRemove);
    wxSplitterWindow *ptr;
    Data_Get_Struct(self, wxSplitterWindow, ptr);
    return (ptr->Unsplit(toRemove) ? Qtrue : Qfalse);
}

VALUE WxSplitterWindow::rubyClass;

class ZAutoDefineWxSplitterWindow
{
public:
   ZAutoDefineWxSplitterWindow()
    {
       WxSplitterWindow::DefineClass();
    }
};
static ZAutoDefineWxSplitterWindow x;
