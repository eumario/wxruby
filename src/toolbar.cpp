/**********************************************************************

  toolbar.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "toolbar.h"
#include "size.h"
#include "window.h"

void WxToolBar::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ToolBar", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxToolBar::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxToolBar::init), -1);
	rb_define_method(rubyClass, "add_check_tool", VALUEFUNC(WxToolBar::AddCheckTool), -1);
	rb_define_method(rubyClass, "add_control", VALUEFUNC(WxToolBar::AddControl), 1);
	rb_define_method(rubyClass, "add_radio_tool", VALUEFUNC(WxToolBar::AddRadioTool), -1);
	rb_define_method(rubyClass, "add_separator", VALUEFUNC(WxToolBar::AddSeparator), 0);
	rb_define_method(rubyClass, "add_tool", VALUEFUNC(WxToolBar::AddTool), -1);
	rb_define_method(rubyClass, "delete_tool", VALUEFUNC(WxToolBar::DeleteTool), 1);
	rb_define_method(rubyClass, "delete_tool_by_pos", VALUEFUNC(WxToolBar::DeleteToolByPos), 1);
	rb_define_method(rubyClass, "enable_tool", VALUEFUNC(WxToolBar::EnableTool), 2);
	rb_define_method(rubyClass, "get_margins", VALUEFUNC(WxToolBar::GetMargins), 0);
	rb_define_method(rubyClass, "get_tool_bitmap_size", VALUEFUNC(WxToolBar::GetToolBitmapSize), 0);
	rb_define_method(rubyClass, "get_tool_client_data", VALUEFUNC(WxToolBar::GetToolClientData), 1);
	rb_define_method(rubyClass, "get_tool_enabled", VALUEFUNC(WxToolBar::GetToolEnabled), 1);
	rb_define_method(rubyClass, "get_tool_long_help", VALUEFUNC(WxToolBar::GetToolLongHelp), 1);
	rb_define_method(rubyClass, "get_tool_packing", VALUEFUNC(WxToolBar::GetToolPacking), 0);
	rb_define_method(rubyClass, "get_tool_separation", VALUEFUNC(WxToolBar::GetToolSeparation), 0);
	rb_define_method(rubyClass, "get_tool_short_help", VALUEFUNC(WxToolBar::GetToolShortHelp), 1);
	rb_define_method(rubyClass, "get_tool_size", VALUEFUNC(WxToolBar::GetToolSize), 0);
	rb_define_method(rubyClass, "get_tool_state", VALUEFUNC(WxToolBar::GetToolState), 1);
	rb_define_method(rubyClass, "insert_control", VALUEFUNC(WxToolBar::InsertControl), 2);
	rb_define_method(rubyClass, "insert_separator", VALUEFUNC(WxToolBar::InsertSeparator), 1);
	rb_define_method(rubyClass, "insert_tool", VALUEFUNC(WxToolBar::InsertTool), -1);
	rb_define_method(rubyClass, "realize", VALUEFUNC(WxToolBar::Realize), 0);
	rb_define_method(rubyClass, "remove_tool", VALUEFUNC(WxToolBar::RemoveTool), 1);
	rb_define_method(rubyClass, "set_margins", VALUEFUNC(WxToolBar::SetMargins), 2);
	rb_define_method(rubyClass, "set_tool_bitmap_size", VALUEFUNC(WxToolBar::SetToolBitmapSize), 1);
	rb_define_method(rubyClass, "set_tool_client_data", VALUEFUNC(WxToolBar::SetToolClientData), 2);
	rb_define_method(rubyClass, "set_tool_long_help", VALUEFUNC(WxToolBar::SetToolLongHelp), 2);
	rb_define_method(rubyClass, "set_tool_packing", VALUEFUNC(WxToolBar::SetToolPacking), 1);
	rb_define_method(rubyClass, "set_tool_separation", VALUEFUNC(WxToolBar::SetToolSeparation), 1);
	rb_define_method(rubyClass, "set_tool_short_help", VALUEFUNC(WxToolBar::SetToolShortHelp), 2);
	rb_define_method(rubyClass, "toggle_tool", VALUEFUNC(WxToolBar::ToggleTool), 2);
	rb_define_method(rubyClass, "set_rows", VALUEFUNC(WxToolBar::SetRows), 1);
	rb_define_method(rubyClass, "set_max_rows_cols", VALUEFUNC(WxToolBar::SetMaxRowsCols), 2);
	rb_define_method(rubyClass, "get_max_rows", VALUEFUNC(WxToolBar::GetMaxRows), 0);
	rb_define_method(rubyClass, "get_max_cols", VALUEFUNC(WxToolBar::GetMaxCols), 0);
}

VALUE
WxToolBarToolBase::init0(wxToolBarToolBase *toolbar)
{
    return Qnil;
}

VALUE
WxToolBar::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxToolBar::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxTB_HORIZONTAL | wxNO_BORDER;
    wxString name = wxPanelNameStr;

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

    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr = new wxToolBar(parent,id,pos,size,style,name);
    DATA_PTR(self) = ptr;

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    return self;
}

VALUE
WxToolBar::init0(wxToolBar *toolbar)
{
    if(toolbar==NULL) return Qnil;
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = toolbar;
    return self;
}

VALUE
WxToolBar::AddControl(VALUE self,VALUE vcontrol)
{
    wxControl* control;
    Data_Get_Struct(vcontrol, wxControl, control);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->AddControl(control) ? Qtrue : Qfalse);
}

void
WxToolBar::AddSeparator(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->AddSeparator();
}

VALUE
WxToolBar::AddTool(int argc, VALUE *argv, VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    int toolId = NUM2INT(argv[0]);
    wxString label = StringValuePtr(argv[1]);
    wxBitmap bitmap1;
    if(argc>2) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[2], wxBitmap, bptr);
        bitmap1 = *bptr;
    }
    wxBitmap bitmap2 = wxNullBitmap;
    wxItemKind kind = wxITEM_NORMAL;
    wxString shortHelpString = "";
    wxString longHelpString = "";
    wxObject* clientData = NULL;
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[3], wxBitmap, bptr);
        bitmap1 = *bptr;
        if(argc>4) kind = (wxItemKind)NUM2INT(argv[4]);
        if(argc>5) shortHelpString = StringValuePtr(argv[5]);
        if(argc>6) longHelpString = StringValuePtr(argv[6]);
        if(argc>7) clientData = (wxObject*)argv[7];
        return WxToolBarToolBase::init0(ptr->AddTool(toolId,label,bitmap1,bitmap2,kind,shortHelpString,longHelpString,clientData));
    } else {
        if(argc>3) shortHelpString = StringValuePtr(argv[3]);
        if(argc>4) kind = (wxItemKind)NUM2INT(argv[4]);
        return WxToolBarToolBase::init0(ptr->AddTool(toolId,label,bitmap1,shortHelpString,kind));
    }
}

VALUE
WxToolBar::AddCheckTool(int argc, VALUE *argv, VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    int id = NUM2INT(argv[0]);
    wxString label = StringValuePtr(argv[1]);
    wxBitmap bitmap;
    if(argc>2) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[2], wxBitmap, bptr);
        bitmap = *bptr;
    }
    wxBitmap bmpDisabled = wxNullBitmap;
    if(argc>3) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[3], wxBitmap, bptr);
        bmpDisabled = *bptr;
    }
    wxString shortHelp = "";
    if(argc>4) shortHelp = StringValuePtr(argv[4]);
    wxString longHelp = "";
    if(argc>5) longHelp = StringValuePtr(argv[5]);
    wxObject* clientData = NULL;
    if(argc>6) clientData = (wxObject*)argv[6];

    return WxToolBarToolBase::init0(ptr->AddCheckTool(id,label,bitmap,bmpDisabled,shortHelp,longHelp,clientData));
}

VALUE
WxToolBar::AddRadioTool(int argc, VALUE *argv, VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    int id = NUM2INT(argv[0]);
    wxString label = StringValuePtr(argv[1]);
    wxBitmap bitmap;
    if(argc>2) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[2], wxBitmap, bptr);
        bitmap = *bptr;
    }
    wxBitmap bmpDisabled = wxNullBitmap;
    if(argc>3) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[3], wxBitmap, bptr);
        bmpDisabled = *bptr;
    }
    wxString shortHelp = "";
    if(argc>4) shortHelp = StringValuePtr(argv[4]);
    wxString longHelp = "";
    if(argc>5) longHelp = StringValuePtr(argv[5]);
    wxObject* clientData = NULL;
    if(argc>6) clientData = (wxObject*)argv[6];

    return WxToolBarToolBase::init0(ptr->AddRadioTool(id,label,bitmap,bmpDisabled,shortHelp,longHelp,clientData));
}

VALUE
WxToolBar::DeleteTool(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->DeleteTool(toolId) ? Qtrue : Qfalse);
}

VALUE
WxToolBar::DeleteToolByPos(VALUE self,VALUE vpos)
{
    size_t pos = NUM2INT(vpos);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->DeleteToolByPos(pos) ? Qtrue : Qfalse);
}

void
WxToolBar::EnableTool(VALUE self,VALUE vtoolId,VALUE venable)
{
    int toolId = NUM2INT(vtoolId);
    bool enable = (venable == Qtrue);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->EnableTool(toolId,enable);
}


VALUE
WxToolBar::GetToolSize(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxSize::init0(ptr->GetToolSize());
}

VALUE
WxToolBar::GetToolBitmapSize(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxSize::init0(ptr->GetToolBitmapSize());
}

VALUE
WxToolBar::GetMargins(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxSize::init0(ptr->GetMargins());
}

VALUE
WxToolBar::GetToolClientData(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    wxObject *r = ptr->GetToolClientData(toolId);
    if(r==NULL) return Qnil;
    return (VALUE)r;
}

VALUE
WxToolBar::GetToolEnabled(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->GetToolEnabled(toolId) ? Qtrue : Qfalse);
}

VALUE
WxToolBar::GetToolLongHelp(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return rb_str_new2(ptr->GetToolLongHelp(toolId));
}

VALUE
WxToolBar::GetToolPacking(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return INT2NUM(ptr->GetToolPacking());
}

VALUE
WxToolBar::GetToolSeparation(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return INT2NUM(ptr->GetToolSeparation());
}

VALUE
WxToolBar::GetToolShortHelp(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return rb_str_new2(ptr->GetToolShortHelp(toolId));
}

VALUE
WxToolBar::GetToolState(VALUE self,VALUE vtoolId)
{
    int toolId = NUM2INT(vtoolId);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->GetToolState(toolId) ? Qtrue : Qfalse);
}

VALUE
WxToolBar::InsertControl(VALUE self,VALUE vpos,VALUE vcontrol)
{
    size_t pos = NUM2INT(vpos);
    wxControl *control;
    Data_Get_Struct(vcontrol, wxControl, control);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxToolBarToolBase::init0(ptr->InsertControl(pos,control));
}

VALUE
WxToolBar::InsertSeparator(VALUE self,VALUE vpos)
{
    size_t pos = NUM2INT(vpos);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxToolBarToolBase::init0(ptr->InsertSeparator(pos));
}

VALUE
WxToolBar::InsertTool(int argc, VALUE *argv, VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    size_t pos = NUM2INT(argv[0]);
    int id = NUM2INT(argv[1]);
    wxString label = StringValuePtr(argv[2]);
    wxBitmap bitmap;
    if(argc>3) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[3], wxBitmap, bptr);
        bitmap = *bptr;
    }
    wxBitmap bmpDisabled = wxNullBitmap;
    if(argc>4) {
        wxBitmap *bptr;
        Data_Get_Struct(argv[4], wxBitmap, bptr);
        bmpDisabled = *bptr;
    }
    wxItemKind kind = wxITEM_NORMAL;
    if(argc>5) kind = (wxItemKind)NUM2INT(argv[5]);
    wxString shortHelp = "";
    if(argc>6) shortHelp = StringValuePtr(argv[6]);
    wxString longHelp = "";
    if(argc>7) longHelp = StringValuePtr(argv[7]);
    wxObject* clientData = NULL;
    if(argc>8) clientData = (wxObject*)argv[8];

    return WxToolBarToolBase::init0(ptr->InsertTool(pos,id,label,bitmap,bmpDisabled,kind,shortHelp,longHelp,clientData));
}

VALUE
WxToolBar::Realize(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return (ptr->Realize() ? Qtrue : Qfalse);
}

VALUE
WxToolBar::RemoveTool(VALUE self,VALUE vid)
{
    int id = NUM2INT(vid);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return WxToolBarToolBase::init0(ptr->RemoveTool(id));
}

void
WxToolBar::SetMargins(VALUE self,VALUE vx,VALUE vy)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    ptr->SetMargins(x,y);
}

void
WxToolBar::SetToolBitmapSize(VALUE self,VALUE vsize)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    wxSize *size;
    Data_Get_Struct(vsize, wxSize, size);
    ptr->SetToolBitmapSize(*size);
}

void
WxToolBar::SetToolClientData(VALUE self,VALUE vid,VALUE vclientData)
{
    int id = NUM2INT(vid);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    wxObject* clientData = (wxObject*)vclientData;
    ptr->SetToolClientData(id,clientData);
}

void
WxToolBar::SetToolLongHelp(VALUE self,VALUE vtoolId,VALUE vhelpString)
{
    int toolId = NUM2INT(vtoolId);
    wxString helpString = StringValuePtr(vhelpString);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetToolLongHelp(toolId,helpString);
}

void
WxToolBar::SetToolPacking(VALUE self,VALUE vpacking)
{
    int packing = NUM2INT(vpacking);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetToolPacking(packing);
}

void
WxToolBar::SetToolShortHelp(VALUE self,VALUE vtoolId,VALUE vhelpString)
{
    int toolId = NUM2INT(vtoolId);
    wxString helpString = StringValuePtr(vhelpString);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetToolShortHelp(toolId,helpString);
}

void
WxToolBar::SetToolSeparation(VALUE self,VALUE vseparation)
{
    int separation = NUM2INT(vseparation);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetToolSeparation(separation);
}

void
WxToolBar::ToggleTool(VALUE self,VALUE vtoolId,VALUE vtoggle)
{
    int toolId = NUM2INT(vtoolId);
    bool toggle = (vtoggle == Qtrue);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->ToggleTool(toolId,toggle);
}

void
WxToolBar::SetRows(VALUE self,VALUE vnRows)
{
    int nRows = NUM2INT(vnRows);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetRows(nRows);
}

void
WxToolBar::SetMaxRowsCols(VALUE self,VALUE vrows,VALUE vcols)
{
    int rows = NUM2INT(vrows);
    int cols = NUM2INT(vcols);
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    ptr->SetMaxRowsCols(rows,cols);
}

VALUE
WxToolBar::GetMaxRows(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return INT2NUM(ptr->GetMaxRows());
}

VALUE
WxToolBar::GetMaxCols(VALUE self)
{
    wxToolBar *ptr;
    Data_Get_Struct(self, wxToolBar, ptr);
    return INT2NUM(ptr->GetMaxCols());
}

VALUE WxToolBar::rubyClass;

class ZAutoDefineWxToolBar
{
public:
   ZAutoDefineWxToolBar()
    {
       WxToolBar::DefineClass();
    }
};
static ZAutoDefineWxToolBar x;
