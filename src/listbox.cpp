/**********************************************************************

  listbox.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "listbox.h"
#include "ownerdrawn.h"
#include "window.h"

void WxListBox::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ListBox", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxListBox::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxListBox::init), -1);
	rb_define_method(rubyClass, "append", VALUEFUNC(WxListBox::Append), 1);
	rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxListBox::SetSelection), -1);
	rb_define_method(rubyClass, "get_string", VALUEFUNC(WxListBox::GetString), 1);
	rb_define_method(rubyClass, "get_string_selection", VALUEFUNC(WxListBox::GetStringSelection), 0);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "get_item", VALUEFUNC(WxListBox::GetItem), 1);
#endif
	rb_define_method(rubyClass, "deselect", VALUEFUNC(WxListBox::Deselect), 1);
	rb_define_method(rubyClass, "delete", VALUEFUNC(WxListBox::Delete), 1);
	rb_define_method(rubyClass, "deselect_all", VALUEFUNC(WxListBox::DeselectAll), -1);
	rb_define_method(rubyClass, "is_selected", VALUEFUNC(WxListBox::IsSelected), 1);
	rb_define_method(rubyClass, "select", VALUEFUNC(WxListBox::Select), 1);
	rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxListBox::GetSelection), 0);
	rb_define_method(rubyClass, "get_selections", VALUEFUNC(WxListBox::GetSelections), 0);
	rb_define_method(rubyClass, "get_count", VALUEFUNC(WxListBox::GetCount), 0);
	rb_define_method(rubyClass, "insert_items", VALUEFUNC(WxListBox::InsertItems), 2);
	rb_define_method(rubyClass, "set_client_data", VALUEFUNC(WxListBox::SetClientData), 2);
	rb_define_method(rubyClass, "get_client_data",VALUEFUNC(WxListBox::GetClientData),1);
	rb_define_method(rubyClass, "set_string", VALUEFUNC(WxListBox::SetString), 2);
	rb_define_method(rubyClass, "set_string_selection", VALUEFUNC(WxListBox::SetStringSelection), -1);
	rb_define_method(rubyClass, "clear", VALUEFUNC(WxListBox::Clear), 0);
}

VALUE
WxListBox::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxListBox::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    int n = 0;
    wxString *choices = NULL;
    long style = 0;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "listBox";

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
    if(argc>4 && TYPE(argv[4])==T_ARRAY) {
        n = RARRAY(argv[4])->len;
        choices = new wxString[n];
        for (int i = 0; i < n; i++) {
            choices[i] = StringValuePtr(RARRAY(argv[4])->ptr[i]);
        }
    }
    if(argc>5 && TYPE(argv[5])==T_FIXNUM)
        style = NUM2INT(argv[5]);

    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr = new wxListBox(parent,id,pos,size,n,choices,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxListBox::Append(VALUE self,VALUE vitem)
{
    wxString item = wxString(StringValuePtr(vitem));
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->Append(item);
}

void
WxListBox::SetSelection(int argc, VALUE *argv, VALUE self)
{
    int n = NUM2INT(argv[0]);
    bool select = TRUE;
    if(argc>1 && argv[1]==Qfalse) select = FALSE;
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->SetSelection(n,select);
}

VALUE
WxListBox::GetString(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return rb_str_new2(ptr->GetString(n));
}

VALUE
WxListBox::GetStringSelection(VALUE self)
{
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return rb_str_new2(ptr->GetStringSelection());
}

void
WxListBox::SetString(VALUE self,VALUE vn,VALUE vstring)
{
    int n = NUM2INT(vn);
    wxString string = StringValuePtr(vstring);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->SetString(n,string);
}

void
WxListBox::SetStringSelection(int argc, VALUE *argv, VALUE self)
{
    wxString string = StringValuePtr(argv[0]);
    bool select = TRUE;
    if(argc>1 && argv[1]==Qfalse) select = FALSE;
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->SetStringSelection(string,select);
}

#ifdef __WXMSW__
VALUE
WxListBox::GetItem(VALUE self,VALUE vn)
{
    size_t n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return WxOwnerDrawn::init0(ptr->GetItem(n));
}
#endif

VALUE
WxListBox::IsSelected(VALUE self,VALUE vn)
{
    size_t n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return (ptr->IsSelected(n) ? Qtrue : Qfalse);
}

void
WxListBox::Select(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->Select(n);
}

void
WxListBox::Deselect(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->Deselect(n);
}

void
WxListBox::DeselectAll(int argc, VALUE *argv, VALUE self)
{
    int itemToLeaveSelected = -1;
    if(argc>0) itemToLeaveSelected = NUM2INT(argv[0]);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->DeselectAll(itemToLeaveSelected);
}

VALUE
WxListBox::GetSelection(VALUE self)
{
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return INT2NUM(ptr->GetSelection());
}

VALUE
WxListBox::GetSelections(VALUE self)
{
    wxArrayInt selections;
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->GetSelections(selections);
    int n = selections.Count();
    if(n==0) return Qnil;
    VALUE *elmts = new VALUE[n];
    for(int i = 0;i<n;i++) {
        elmts[i] = INT2NUM(selections[i]);
    }
    return rb_ary_new4(n,elmts);
}

VALUE
WxListBox::GetCount(VALUE self)
{
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    return INT2NUM(ptr->GetCount());
}

void
WxListBox::InsertItems(VALUE self,VALUE vitems,VALUE vpos)
{
    int nItems = RARRAY(vitems)->len;
    wxString *items = new wxString[nItems];
    for (int i = 0; i < nItems; i++) {
        items[i] = StringValuePtr(RARRAY(vitems)->ptr[i]);
    }
    int pos = NUM2INT(vpos);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->InsertItems(nItems,items,pos);
}


void
WxListBox::Delete(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->Delete(n);
}


void
WxListBox::SetClientData(VALUE self,VALUE vn,VALUE vcdata)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);

    void *data = ptr->GetClientData(n);
    VALUE vdata;
    if(data==NULL)
        vdata = rb_hash_new();
    else
        vdata = (VALUE)data;
    rb_hash_aset(vdata,rb_str_new2("data"),vcdata);
    data = (void*)vdata;

    ptr->SetClientData(n,data);
}

VALUE
WxListBox::GetClientData(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    void *data = ptr->GetClientData(n);
    if(data==NULL)
        return Qnil;
    else
        return rb_hash_aref((VALUE)data, rb_str_new2("data"));
}

void
WxListBox::Clear(VALUE self)
{
    wxListBox *ptr;
    Data_Get_Struct(self, wxListBox, ptr);
    ptr->Clear();
}

VALUE WxListBox::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxListBox::DefineClass();
    }
};
static ZAutoDefine x;
