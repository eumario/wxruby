/**********************************************************************

  combobox.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "combobox.h"
#include "window.h"

void WxComboBox::DefineClass()
{
    if(rubyClass)
        return;
    WxWindow::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"ComboBox", WxWindow::rubyClass);
    rb_define_alloc_func(rubyClass,WxComboBox::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxComboBox::init), -1);
    rb_define_method(rubyClass, "append", VALUEFUNC(WxComboBox::Append), -1);
    rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxComboBox::SetSelection), 1);
    rb_define_method(rubyClass, "set_string_selection", VALUEFUNC(WxComboBox::SetStringSelection), 1);
    rb_define_method(rubyClass, "set_client_data", VALUEFUNC(WxComboBox::SetClientData), 2);
    rb_define_method(rubyClass, "get_client_data", VALUEFUNC(WxComboBox::GetClientData), 1);
    rb_define_method(rubyClass, "get_count", VALUEFUNC(WxComboBox::GetCount), 0);
    rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxComboBox::GetSelection), 0);
    rb_define_method(rubyClass, "get_string", VALUEFUNC(WxComboBox::GetString), 1);
    rb_define_method(rubyClass, "get_string_selection", VALUEFUNC(WxComboBox::GetStringSelection), 0);
    rb_define_method(rubyClass, "delete", VALUEFUNC(WxComboBox::Delete), 1);
    rb_define_method(rubyClass, "clear", VALUEFUNC(WxComboBox::Clear), 0);
}

VALUE
WxComboBox::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxComboBox::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id;
    wxString value = "";
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    int n = 0;
    wxString *choices = NULL;
    long style = 0;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "comboBox";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	    Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_STRING)
      value = wxString(StringValuePtr(argv[2]));
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxPoint *ptr;
	    Data_Get_Struct(argv[3], wxPoint, ptr);
	    pos = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_DATA) {
        wxSize *ptr;
	    Data_Get_Struct(argv[4], wxSize, ptr);
	    size = *ptr;
    }
    if(argc>5 && TYPE(argv[5])==T_ARRAY) {
      n = RARRAY(argv[5])->len;
      choices = new wxString[n];
      for (int i = 0; i < RARRAY(argv[5])->len; i++) {
        choices[i] = wxString(StringValuePtr(RARRAY(argv[5])->ptr[i]));
      }
    }
    if(argc>6 && TYPE(argv[6])==T_FIXNUM)
      style = NUM2INT(argv[6]);

    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    ptr = new wxComboBox(parent,id,value,pos,size,n,choices,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxComboBox::Append(int argc, VALUE *argv, VALUE self)
{
    wxString item = wxString(StringValuePtr(argv[0]));
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
#if defined(__WXGTK__) || defined(__WXMSW__)
    void* clientData;
    if(argc>1) {
        VALUE vdata = rb_hash_new();
        rb_hash_aset(vdata,rb_str_new2("data"),argv[1]);
        clientData = (void*)vdata;
        ptr->Append(item,clientData);
    } else 
#endif
	{
        ptr->Append(item);
    }
}

VALUE
WxComboBox::GetCount(VALUE self)
{
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    return INT2NUM(ptr->GetCount());
}

VALUE
WxComboBox::GetSelection(VALUE self)
{
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    return INT2NUM(ptr->GetSelection());
}

VALUE
WxComboBox::GetString(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    return rb_str_new2(ptr->GetString(n));
}

void
WxComboBox::SetSelection(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    ptr->SetSelection(n);
}


void
WxComboBox::SetStringSelection(VALUE self,VALUE vstring)
{
    wxString string = StringValuePtr(vstring);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    ptr->SetStringSelection(string);
}

void
WxComboBox::SetClientData(VALUE self,VALUE vn,VALUE vcdata)
{
    int n = NUM2INT(vn);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);

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
WxComboBox::GetClientData(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    void *data = ptr->GetClientData(n);
    if(data==NULL)
        return Qnil;
    else
        return rb_hash_aref((VALUE)data, rb_str_new2("data"));
}

VALUE
WxComboBox::GetStringSelection(VALUE self)
{
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    return rb_str_new2(ptr->GetStringSelection());
}

void
WxComboBox::Clear(VALUE self)
{
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    ptr->Clear();
}

void
WxComboBox::Delete(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxComboBox *ptr;
    Data_Get_Struct(self, wxComboBox, ptr);
    ptr->Delete(n);
}

VALUE WxComboBox::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxComboBox::DefineClass();
    }
};
static ZAutoDefine x;
