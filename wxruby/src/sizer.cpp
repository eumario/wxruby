/**********************************************************************

  sizer.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "size.h"
#include "sizer.h"
#include "notebook.h"

void WxSizer::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Sizer", rb_cObject);
	rb_define_alloc_func(rubyClass,WxSizer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSizer::init), 0);
	rb_define_method(rubyClass, "add", VALUEFUNC(WxSizer::Add), -1);
	rb_define_method(rubyClass, "insert", VALUEFUNC(WxSizer::Insert), -1);
	rb_define_method(rubyClass, "fit", VALUEFUNC(WxSizer::Fit), 1);
	rb_define_method(rubyClass, "fit_inside", VALUEFUNC(WxSizer::FitInside), 1);
	rb_define_method(rubyClass, "set_size_hints", VALUEFUNC(WxSizer::SetSizeHints), 1);
	rb_define_method(rubyClass, "set_virtual_size_hints", VALUEFUNC(WxSizer::SetVirtualSizeHints), 1);
	rb_define_method(rubyClass, "remove", VALUEFUNC(WxSizer::Remove), 1);
	rb_define_method(rubyClass, "show", VALUEFUNC(WxSizer::Show), -1);
	rb_define_method(rubyClass, "layout", VALUEFUNC(WxSizer::Layout), 0);
}

VALUE
WxSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSizer::init(VALUE self)
{
    return self;
}

VALUE
WxSizer::init0(wxSizer *sizer)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = sizer;
    return self;
}

VALUE
WxSizer::Add(int argc, VALUE *argv, VALUE self)
{
    int width = 0;
    int height = 0;
    int option = 0;
    int flag = 0;
    int border = 0;
    wxObject* userData = NULL;

    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    if(TYPE(argv[0])==T_DATA) {
      if(argc>1 && TYPE(argv[1])==T_FIXNUM)
        option = NUM2INT(argv[1]);
      if(argc>2 && TYPE(argv[2])==T_FIXNUM)
        flag = NUM2INT(argv[2]);
      if(argc>3 && TYPE(argv[3])==T_FIXNUM)
        border = NUM2INT(argv[3]);

//      if(strstr(rb_class2name(CLASS_OF(argv[0])),"Sizer")) {
      if(rb_obj_is_kind_of(argv[0], WxSizer::rubyClass) == Qtrue) {
	    wxSizer *sizer;
        Data_Get_Struct(argv[0], wxSizer, sizer);
        ptr->Add(sizer,option,flag,border,userData);
      } else if(rb_obj_is_kind_of(argv[0], WxWindow::rubyClass) == Qtrue) {
    	wxWindow *window;
        Data_Get_Struct(argv[0], wxWindow, window);
        ptr->Add(window,option,flag,border,userData);
      }
	  else {
		  printf("Sizer::Add called with unknown object type\n");
	  }
    } else {
      if(argc>0 && TYPE(argv[0])==T_FIXNUM)
        width = NUM2INT(argv[0]);
      if(argc>1 && TYPE(argv[1])==T_FIXNUM)
        height = NUM2INT(argv[1]);
      if(argc>2 && TYPE(argv[2])==T_FIXNUM)
        option = NUM2INT(argv[2]);
      if(argc>3 && TYPE(argv[3])==T_FIXNUM)
        flag = NUM2INT(argv[3]);
      if(argc>4 && TYPE(argv[4])==T_FIXNUM)
        border = NUM2INT(argv[4]);

      ptr->Add(width,height,option,flag,border,userData);
    }
	return Qnil;
}

VALUE
WxSizer::Fit(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    return WxSize::init0(ptr->Fit(window));
}

VALUE
WxSizer::FitInside(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    ptr->FitInside(window);
	return Qnil;
}

VALUE
WxSizer::SetSizeHints(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    ptr->SetSizeHints(window);
	return Qnil;
}

VALUE
WxSizer::SetVirtualSizeHints(VALUE self,VALUE vwindow)
{
    wxWindow* window;
    Data_Get_Struct(vwindow, wxWindow, window);
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    ptr->SetVirtualSizeHints(window);
	return Qnil;
}

VALUE
WxSizer::Remove(VALUE self,VALUE argv)
{
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    if(TYPE(argv)==T_FIXNUM) {
        int nth = NUM2INT(argv);
        ptr->Remove(nth);
    }
    else if(strstr(rb_class2name(CLASS_OF(argv)),"Sizer")) {
        wxSizer* sizer;
        Data_Get_Struct(argv, wxSizer, sizer);
        ptr->Remove(sizer);
    } else {
        wxWindow* window;
        Data_Get_Struct(argv, wxWindow, window);
        ptr->Remove(window);
    }
	return Qnil;
}

VALUE
WxSizer::Insert(int argc, VALUE *argv, VALUE self)
{
    int before = NUM2INT(argv[0]);
    wxWindow *window;
    wxSizer *sizer;
    int width = 0;
    int height = 0;
    int option = 0;
    int flag = 0;
    int border = 0;
    wxObject* userData = NULL;

    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    if(TYPE(argv[1])==T_DATA) {
      if(argc>2 && TYPE(argv[2])==T_FIXNUM)
        option = NUM2INT(argv[2]);
      if(argc>3 && TYPE(argv[3])==T_FIXNUM)
        flag = NUM2INT(argv[3]);
      if(argc>4 && TYPE(argv[4])==T_FIXNUM)
        border = NUM2INT(argv[4]);

      if(strstr(rb_class2name(CLASS_OF(argv[1])),"Sizer")) {
        Data_Get_Struct(argv[1], wxSizer, sizer);
        ptr->Insert(before,sizer,option,flag,border,userData);
      } else {
        Data_Get_Struct(argv[1], wxWindow, window);
        ptr->Insert(before,window,option,flag,border,userData);
      }
    } else {
      if(argc>1 && TYPE(argv[1])==T_FIXNUM)
        width = NUM2INT(argv[1]);
      if(argc>2 && TYPE(argv[2])==T_FIXNUM)
        height = NUM2INT(argv[2]);
      if(argc>3 && TYPE(argv[3])==T_FIXNUM)
        option = NUM2INT(argv[3]);
      if(argc>4 && TYPE(argv[4])==T_FIXNUM)
        flag = NUM2INT(argv[4]);
      if(argc>5 && TYPE(argv[5])==T_FIXNUM)
        border = NUM2INT(argv[5]);

      ptr->Insert(before,width,height,option,flag,border,userData);
    }
	return Qnil;
}

VALUE
WxSizer::Show(int argc, VALUE *argv, VALUE self)
{
    wxWindow *window;
    wxSizer *sizer;
    bool show = TRUE;
    if(argc>1 && argv[1]==Qfalse) show = FALSE;

    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);

    if(strstr(rb_class2name(CLASS_OF(argv[0])),"Sizer")) {
        Data_Get_Struct(argv[0], wxSizer, sizer);
        ptr->Show(sizer,show);
    } else {
        Data_Get_Struct(argv[0], wxWindow, window);
        ptr->Show(window,show);
    }
	return Qnil;
}

VALUE
WxSizer::Layout(VALUE self)
{
    wxSizer *ptr;
    Data_Get_Struct(self, wxSizer, ptr);
    ptr->Layout();
	return Qnil;
}

VALUE WxSizer::rubyClass;

class ZAutoDefineWxSizer
{
public:
   ZAutoDefineWxSizer()
    {
       WxSizer::DefineClass();
    }
};
static ZAutoDefineWxSizer x;

//--------------------------------------------------------------------------------
void WxGridSizer::DefineClass()
{
	if(rubyClass)
		return;
	WxSizer::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"GridSizer", WxSizer::rubyClass);
	rb_define_alloc_func(rubyClass,WxGridSizer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxGridSizer::init), -1);
	rb_define_method(rubyClass, "recalc_sizes", VALUEFUNC(WxGridSizer::RecalcSizes), 0);
	rb_define_method(rubyClass, "calc_min", VALUEFUNC(WxGridSizer::CalcMin), 0);
	rb_define_method(rubyClass, "get_cols", VALUEFUNC(WxGridSizer::GetCols), 0);
	rb_define_method(rubyClass, "get_rows", VALUEFUNC(WxGridSizer::GetRows), 0);
	rb_define_method(rubyClass, "get_v_gap", VALUEFUNC(WxGridSizer::GetVGap), 0);
	rb_define_method(rubyClass, "get_h_gap", VALUEFUNC(WxGridSizer::GetHGap), 0);
	rb_define_method(rubyClass, "set_cols", VALUEFUNC(WxGridSizer::SetCols), 1);
	rb_define_method(rubyClass, "set_rows", VALUEFUNC(WxGridSizer::SetRows), 1);
	rb_define_method(rubyClass, "set_v_gap", VALUEFUNC(WxGridSizer::SetVGap), 1);
	rb_define_method(rubyClass, "set_h_gap", VALUEFUNC(WxGridSizer::SetHGap), 1);
}


VALUE
WxGridSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxGridSizer::init(int argc, VALUE *argv, VALUE self)
{
    int rows;
    int cols;
    int vgap = 0;
    int hgap = 0;
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    if(argc==4) {
      rows = NUM2INT(argv[0]);
      cols = NUM2INT(argv[1]);
      vgap = NUM2INT(argv[2]);
      hgap = NUM2INT(argv[3]);
      ptr = new wxGridSizer(rows,cols,vgap,hgap);
    } else {
      cols = NUM2INT(argv[0]);
      if(argc>1) vgap = NUM2INT(argv[1]);
      if(argc>2) hgap = NUM2INT(argv[2]);
      ptr = new wxGridSizer(cols,vgap,hgap);
    }
    DATA_PTR(self) = ptr;

    return self;
}

void
WxGridSizer::RecalcSizes(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    ptr->RecalcSizes();
}

VALUE
WxGridSizer::CalcMin(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    return WxSize::init0(ptr->CalcMin());
}

void
WxGridSizer::SetCols(VALUE self,VALUE vcols)
{
    int cols = NUM2INT(vcols);

    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    ptr->SetCols(cols);
}
void
WxGridSizer::SetRows(VALUE self,VALUE vrows)
{
    int rows = NUM2INT(vrows);

    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    ptr->SetRows(rows);
}
void
WxGridSizer::SetVGap(VALUE self,VALUE vgap)
{
    int gap = NUM2INT(vgap);

    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    ptr->SetVGap(gap);
}
void
WxGridSizer::SetHGap(VALUE self,VALUE vgap)
{
    int gap = NUM2INT(vgap);

    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    ptr->SetHGap(gap);
}

VALUE
WxGridSizer::GetCols(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    return NUM2INT(ptr->GetCols());
}

VALUE
WxGridSizer::GetRows(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    return NUM2INT(ptr->GetRows());
}
VALUE
WxGridSizer::GetVGap(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    return NUM2INT(ptr->GetVGap());
}
VALUE
WxGridSizer::GetHGap(VALUE self)
{
    wxGridSizer *ptr;
    Data_Get_Struct(self, wxGridSizer, ptr);
    return NUM2INT(ptr->GetHGap());
}

VALUE WxGridSizer::rubyClass;

class ZAutoDefineWxGridSizer
{
public:
   ZAutoDefineWxGridSizer()
    {
       WxGridSizer::DefineClass();
    }
};
static ZAutoDefineWxGridSizer x5;

//--------------------------------------------------------------------------------
void WxFlexGridSizer::DefineClass()
{
	if(rubyClass)
		return;
	WxSizer::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"FlexGridSizer", WxSizer::rubyClass);
	rb_define_alloc_func(rubyClass,alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(init), -1);
	rb_define_method(rubyClass, "recalc_sizes", VALUEFUNC(RecalcSizes), 0);
	rb_define_method(rubyClass, "calc_min", VALUEFUNC(CalcMin), 0);
	rb_define_method(rubyClass, "add_growable_col", VALUEFUNC(AddGrowableCol), 1);
	rb_define_method(rubyClass, "add_growable_row", VALUEFUNC(AddGrowableRow), 1);
	rb_define_method(rubyClass, "remove_growable_col", VALUEFUNC(RemoveGrowableCol), 1);
	rb_define_method(rubyClass, "remove_growable_row", VALUEFUNC(RemoveGrowableRow), 1);
}


VALUE
WxFlexGridSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFlexGridSizer::init(int argc, VALUE *argv, VALUE self)
{
    int rows;
    int cols;
    int vgap = 0;
    int hgap = 0;
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    if(argc==4) {
      rows = NUM2INT(argv[0]);
      cols = NUM2INT(argv[1]);
      vgap = NUM2INT(argv[2]);
      hgap = NUM2INT(argv[3]);
      ptr = new wxFlexGridSizer(rows,cols,vgap,hgap);
    } else {
      cols = NUM2INT(argv[0]);
      if(argc>1) vgap = NUM2INT(argv[1]);
      if(argc>2) hgap = NUM2INT(argv[2]);
      ptr = new wxFlexGridSizer(cols,vgap,hgap);
    }
    DATA_PTR(self) = ptr;

    return self;
}

void
WxFlexGridSizer::RecalcSizes(VALUE self)
{
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    ptr->RecalcSizes();
}

VALUE
WxFlexGridSizer::CalcMin(VALUE self)
{
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    return WxSize::init0(ptr->CalcMin());
}

void
WxFlexGridSizer::AddGrowableRow(VALUE self,VALUE vidx)
{
    size_t idx = (size_t)NUM2INT(vidx);
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    ptr->AddGrowableRow(idx);
}

void
WxFlexGridSizer::RemoveGrowableRow(VALUE self,VALUE vidx)
{
    size_t idx = (size_t)NUM2INT(vidx);
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    ptr->RemoveGrowableRow(idx);
}

void
WxFlexGridSizer::AddGrowableCol(VALUE self,VALUE vidx)
{
    size_t idx = (size_t)NUM2INT(vidx);
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    ptr->AddGrowableCol(idx);
}

void
WxFlexGridSizer::RemoveGrowableCol(VALUE self,VALUE vidx)
{
    size_t idx = (size_t)NUM2INT(vidx);
    wxFlexGridSizer *ptr;
    Data_Get_Struct(self, wxFlexGridSizer, ptr);
    ptr->RemoveGrowableCol(idx);
}

VALUE WxFlexGridSizer::rubyClass;

class ZAutoDefineWxFlexGridSizer
{
public:
   ZAutoDefineWxFlexGridSizer()
    {
       WxFlexGridSizer::DefineClass();
    }
};
static ZAutoDefineWxFlexGridSizer x6;

//--------------------------------------------------------------------------------
void WxBoxSizer::DefineClass()
{
	if(rubyClass)
		return;
	WxSizer::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"BoxSizer", WxSizer::rubyClass);
	rb_define_alloc_func(rubyClass,WxBoxSizer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxBoxSizer::init), 1);
	rb_define_method(rubyClass, "recalc_sizes", VALUEFUNC(WxBoxSizer::RecalcSizes), 0);
	rb_define_method(rubyClass, "calc_min", VALUEFUNC(WxBoxSizer::CalcMin), 0);
	rb_define_method(rubyClass, "get_orientation", VALUEFUNC(WxBoxSizer::GetOrientation), 0);
	rb_define_method(rubyClass, "set_orientation", VALUEFUNC(WxBoxSizer::SetOrientation), 1);
}


VALUE
WxBoxSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxBoxSizer::init(VALUE self,VALUE vorient)
{
    int orient = NUM2INT(vorient);

    wxBoxSizer *ptr;
    Data_Get_Struct(self, wxBoxSizer, ptr);
    ptr = new wxBoxSizer(orient);
    DATA_PTR(self) = ptr;

    return self;
}

void
WxBoxSizer::RecalcSizes(VALUE self)
{
    wxBoxSizer *ptr;
    Data_Get_Struct(self, wxBoxSizer, ptr);
    ptr->RecalcSizes();
}


void
WxBoxSizer::SetOrientation(VALUE self,VALUE vorient)
{
    int orient = NUM2INT(vorient);

    wxBoxSizer *ptr;
    Data_Get_Struct(self, wxBoxSizer, ptr);
    ptr->SetOrientation(orient);
}

VALUE
WxBoxSizer::GetOrientation(VALUE self)
{
    wxBoxSizer *ptr;
    Data_Get_Struct(self, wxBoxSizer, ptr);
    return INT2NUM(ptr->GetOrientation());
}

VALUE
WxBoxSizer::CalcMin(VALUE self)
{
    wxBoxSizer *ptr;
    Data_Get_Struct(self, wxBoxSizer, ptr);
    return WxSize::init0(ptr->CalcMin());
}

VALUE WxBoxSizer::rubyClass;

class ZAutoDefineWxBoxSizer
{
public:
   ZAutoDefineWxBoxSizer()
    {
       WxBoxSizer::DefineClass();
    }
};
static ZAutoDefineWxBoxSizer x7;

//--------------------------------------------------------------------------------
void WxStaticBoxSizer::DefineClass()
{
	if(rubyClass)
		return;
	WxBoxSizer::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"StaticBoxSizer", WxBoxSizer::rubyClass);
	rb_define_alloc_func(rubyClass,WxStaticBoxSizer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new2), 2);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStaticBoxSizer::init), 2);
}


VALUE
WxStaticBoxSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStaticBoxSizer::init(VALUE self,VALUE vbox,VALUE vorient)
{
    wxStaticBox* box;
    Data_Get_Struct(vbox, wxStaticBox, box);
    int orient = NUM2INT(vorient);

    wxStaticBoxSizer *ptr;
    Data_Get_Struct(self, wxStaticBoxSizer, ptr);
    ptr = new wxStaticBoxSizer(box,orient);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE WxStaticBoxSizer::rubyClass;

class ZAutoDefineWxStaticBoxSizer
{
public:
   ZAutoDefineWxStaticBoxSizer()
    {
       WxStaticBoxSizer::DefineClass();
    }
};
static ZAutoDefineWxStaticBoxSizer x8;

//-----------------------------------------------------------------------------------
void WxNotebookSizer::DefineClass()
{
	if(rubyClass)
		return;
	WxSizer::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"NotebookSizer", WxSizer::rubyClass);
	rb_define_alloc_func(rubyClass,WxNotebookSizer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxNotebookSizer::init), 1);
	rb_define_method(rubyClass, "recalc_sizes", VALUEFUNC(WxNotebookSizer::RecalcSizes), 0);
	rb_define_method(rubyClass, "calc_min", VALUEFUNC(WxNotebookSizer::CalcMin), 0);
	rb_define_method(rubyClass, "get_notebook", VALUEFUNC(WxNotebookSizer::GetNotebook), 0);
}


VALUE
WxNotebookSizer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxNotebookSizer::init(VALUE self,VALUE vnb)
{
    wxNotebook *nb;
    Data_Get_Struct(vnb, wxNotebook, nb);
    wxNotebookSizer *ptr;
    Data_Get_Struct(self, wxNotebookSizer, ptr);
    ptr = new wxNotebookSizer(nb);
    DATA_PTR(self) = ptr;

    return self;
}

void
WxNotebookSizer::RecalcSizes(VALUE self)
{
    wxNotebookSizer *ptr;
    Data_Get_Struct(self, wxNotebookSizer, ptr);
    ptr->RecalcSizes();
}

VALUE
WxNotebookSizer::CalcMin(VALUE self)
{
    wxNotebookSizer *ptr;
    Data_Get_Struct(self, wxNotebookSizer, ptr);
    return WxSize::init0(ptr->CalcMin());
}

VALUE
WxNotebookSizer::GetNotebook(VALUE self)
{
    wxNotebookSizer *ptr;
    Data_Get_Struct(self, wxNotebookSizer, ptr);
    return WxNotebook::init0(ptr->GetNotebook());
}

VALUE WxNotebookSizer::rubyClass;

class ZAutoDefineWxNotebookSizer
{
public:
   ZAutoDefineWxNotebookSizer()
    {
       WxNotebookSizer::DefineClass();
    }
};
static ZAutoDefineWxNotebookSizer x9;
