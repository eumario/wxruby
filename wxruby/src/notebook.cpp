/**********************************************************************

  notebook.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "notebook.h"
#include "list.h"
#include "button.h"
#include "window.h"

void WxNotebook::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Notebook", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxNotebook::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxNotebook::init), -1);
	rb_define_method(rubyClass, "add_page", VALUEFUNC(WxNotebook::AddPage), -1);
	rb_define_method(rubyClass, "advance_selection", VALUEFUNC(WxNotebook::AdvanceSelection), -1);
	rb_define_method(rubyClass, "assign_image_list", VALUEFUNC(WxNotebook::AssignImageList), 1);
	rb_define_method(rubyClass, "delete_all_pages", VALUEFUNC(WxNotebook::DeleteAllPages), 0);
	rb_define_method(rubyClass, "delete_page", VALUEFUNC(WxNotebook::DeletePage), 1);
	rb_define_method(rubyClass, "get_image_list", VALUEFUNC(WxNotebook::GetImageList), 0);
	rb_define_method(rubyClass, "get_page", VALUEFUNC(WxNotebook::GetPage), 1);
	rb_define_method(rubyClass, "get_page_count", VALUEFUNC(WxNotebook::GetPageCount), 0);
	rb_define_method(rubyClass, "get_page_image", VALUEFUNC(WxNotebook::GetPageImage), 1);
	rb_define_method(rubyClass, "get_page_text", VALUEFUNC(WxNotebook::GetPageText), 1);
	rb_define_method(rubyClass, "get_row_count", VALUEFUNC(WxNotebook::GetRowCount), 0);
	rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxNotebook::GetSelection), 0);
	rb_define_method(rubyClass, "insert_page", VALUEFUNC(WxNotebook::InsertPage), -1);
	rb_define_method(rubyClass, "remove_page", VALUEFUNC(WxNotebook::RemovePage), 1);
	rb_define_method(rubyClass, "set_image_list", VALUEFUNC(WxNotebook::SetImageList), 1);
	rb_define_method(rubyClass, "set_padding", VALUEFUNC(WxNotebook::SetPadding), 1);
	rb_define_method(rubyClass, "set_image_list", VALUEFUNC(WxNotebook::SetImageList), 1);
	rb_define_method(rubyClass, "set_page_image", VALUEFUNC(WxNotebook::SetPageImage), 1);
	rb_define_method(rubyClass, "set_page_size", VALUEFUNC(WxNotebook::SetPageSize), 1);
	rb_define_method(rubyClass, "set_page_text", VALUEFUNC(WxNotebook::SetPageText), 2);
	rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxNotebook::SetSelection), 1);
}

VALUE
WxNotebook::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxNotebook::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = 0;
    wxString name = "notebook";

    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);


    if(argc==0) {
        ptr = new wxNotebook();
    } else {
        if(argv[0] != Qnil)
	        Data_Get_Struct(argv[0], wxWindow, parent);
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
        ptr = new wxNotebook(parent,id,pos,size,style,name);
    }

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}


VALUE
WxNotebook::AddPage(int argc, VALUE *argv, VALUE self)
{
    wxNotebookPage* page;
    Data_Get_Struct(argv[0], wxNotebookPage, page);
    wxString text = StringValuePtr(argv[1]);
    bool select = FALSE;
    if(argc>2 && argv[2]==Qtrue) select = TRUE;
    int imageId = -1;
    if(argc>3) imageId = NUM2INT(argv[3]);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->AddPage(page,text,select,imageId) ? Qtrue : Qfalse);
}

void
WxNotebook::AdvanceSelection(int argc, VALUE *argv, VALUE self)
{
    bool forward = TRUE;
    if(argc>0 && argv[0]==Qfalse) forward = FALSE;
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    ptr->AdvanceSelection(forward);
}

void
WxNotebook::AssignImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList;
    Data_Get_Struct(vimageList, wxImageList, imageList);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    ptr->AssignImageList(imageList);
}

VALUE
WxNotebook::DeleteAllPages(VALUE self)
{
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->DeleteAllPages() ? Qtrue : Qfalse);
}

VALUE
WxNotebook::DeletePage(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->DeletePage(page) ? Qtrue : Qfalse);
}

VALUE
WxNotebook::GetImageList(VALUE self)
{
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return WxImageList::init0(ptr->GetImageList());
}

VALUE
WxNotebook::GetPage(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return WxNotebookPage::init0(ptr->GetPage(page));
}

VALUE
WxNotebook::GetPageCount(VALUE self)
{
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->GetPageCount());
}

VALUE
WxNotebook::GetPageImage(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->GetPageImage(page));
}

VALUE
WxNotebook::GetPageText(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return rb_str_new2(ptr->GetPageText(page));
}

VALUE
WxNotebook::GetRowCount(VALUE self)
{
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->GetRowCount());
}

VALUE
WxNotebook::GetSelection(VALUE self)
{
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->GetSelection());
}


VALUE
WxNotebook::InsertPage(int argc, VALUE *argv, VALUE self)
{
    int index = NUM2INT(argv[0]);
    wxNotebookPage* page;
    Data_Get_Struct(argv[1], wxNotebookPage, page);
    wxString text = StringValuePtr(argv[2]);
    bool select = FALSE;
    if(argc>3 && argv[3]==Qtrue) select = TRUE;
    int imageId = -1;
    if(argc>4) imageId = NUM2INT(argv[4]);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->InsertPage(index,page,text,select,imageId) ? Qtrue : Qfalse);
}

VALUE
WxNotebook::RemovePage(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->RemovePage(page));
}

void
WxNotebook::SetImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList;
    Data_Get_Struct(vimageList, wxImageList, imageList);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    ptr->SetImageList(imageList);
}

void
WxNotebook::SetPadding(VALUE self,VALUE vpadding)
{
    wxSize* padding;
    Data_Get_Struct(vpadding, wxSize, padding);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    ptr->SetPadding(*padding);
}

void
WxNotebook::SetPageSize(VALUE self,VALUE vsize)
{
    wxSize* size;
    Data_Get_Struct(vsize, wxSize, size);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    ptr->SetPageSize(*size);
}

VALUE
WxNotebook::SetPageImage(VALUE self,VALUE vpage,VALUE vimage)
{
    int page = NUM2INT(vpage);
    int image = NUM2INT(vimage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->SetPageImage(page,image) ? Qtrue : Qfalse);
}

VALUE
WxNotebook::SetPageText(VALUE self,VALUE vpage,VALUE vtext)
{
    int page = NUM2INT(vpage);
    wxString text = StringValuePtr(vtext);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return (ptr->SetPageText(page,text) ? Qtrue : Qfalse);
}

VALUE
WxNotebook::SetSelection(VALUE self,VALUE vpage)
{
    int page = NUM2INT(vpage);
    wxNotebook *ptr;
    Data_Get_Struct(self, wxNotebook, ptr);
    return INT2NUM(ptr->SetSelection(page));
}

VALUE
WxNotebook::init0(wxNotebook *window)
{
    if(window==NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = window;
    return self;
}

VALUE WxNotebook::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxNotebook::DefineClass();
    }
};
static ZAutoDefine x;
