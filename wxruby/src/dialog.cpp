/**********************************************************************

  dialog.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "dialog.h"
#include "window.h"

void WxDialog::DefineClass()
{
    if(rubyClass)
        return;
    WxWindow::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"Dialog", WxWindow::rubyClass);
    rb_define_alloc_func(rubyClass,WxDialog::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxDialog::init), -1);
    rb_define_method(rubyClass, "show_modal", VALUEFUNC(WxDialog::ShowModal), 0);
    rb_define_method(rubyClass, "end_modal", VALUEFUNC(WxDialog::EndModal), 1);
}

VALUE
WxDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxDialog::init0(wxDialog* cppObject)
{
    if(cppObject==NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = cppObject;
    return self;
}

VALUE
WxDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxString title;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxDEFAULT_DIALOG_STYLE;
    wxString name = "dialogBox";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
      Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_STRING)
      title = wxString(StringValuePtr(argv[2]));
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
    if(argc>5 && TYPE(argv[5])==T_FIXNUM)
      style = NUM2INT(argv[5]);
    if(argc>6 && TYPE(argv[6])==T_STRING)
      name = wxString(StringValuePtr(argv[6]));

    wxDialog *ptr;
    Data_Get_Struct(self, wxDialog, ptr);
    ptr = new wxDialog(parent,id,title,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxDialog::ShowModal(VALUE self)
{
    wxDialog *ptr;
    Data_Get_Struct(self, wxDialog, ptr);
    return INT2NUM(ptr->ShowModal());
}

VALUE
WxDialog::EndModal(VALUE self, VALUE retCode)
{
    wxDialog *ptr;
    Data_Get_Struct(self, wxDialog, ptr);
    ptr->EndModal(NUM2INT(retCode));
	return Qnil;
}

VALUE WxDialog::rubyClass;

class ZAutoDefineWxDialog
{
public:
   ZAutoDefineWxDialog()
    {
       WxDialog::DefineClass();
    }
};
static ZAutoDefineWxDialog x1;

//-------------------------------------------------------------------------------
void WxProgressDialog::DefineClass()
{
    if(rubyClass)
        return;
    WxDialog::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"ProgressDialog", WxDialog::rubyClass);
    rb_define_alloc_func(rubyClass,WxProgressDialog::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxProgressDialog::init), -1);
    rb_define_method(rubyClass, "update", VALUEFUNC(WxProgressDialog::Update), -1);
    rb_define_method(rubyClass, "resume", VALUEFUNC(WxProgressDialog::Resume), 0);
}

VALUE
WxProgressDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxProgressDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxString title = StringValuePtr(argv[0]);
    wxString message = StringValuePtr(argv[1]);
    int maximum = 100;
    if(argc>2) maximum = NUM2INT(argv[2]);
    wxWindow * parent = NULL;
    if(argc>3) {
        Data_Get_Struct(argv[3], wxWindow, parent);
    }
    int style = wxPD_AUTO_HIDE | wxPD_APP_MODAL;
    if(argc>4)
        style = NUM2INT(argv[4]);

    wxProgressDialog *ptr;
    Data_Get_Struct(self, wxProgressDialog, ptr);
    ptr = new wxProgressDialog(title,message,maximum,parent,style);
    DATA_PTR(self) = ptr;

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    return self;
}


VALUE
WxProgressDialog::Update(int argc, VALUE *argv, VALUE self)
{
    int value = NUM2INT(argv[0]);
    wxString newmsg = "";
    if(argc>1) newmsg = StringValuePtr(argv[1]);
    wxProgressDialog *ptr;
    Data_Get_Struct(self, wxProgressDialog, ptr);
    return (ptr->Update(value,newmsg) ? Qtrue : Qfalse);
}

void
WxProgressDialog::Resume(VALUE self)
{
    wxProgressDialog *ptr;
    Data_Get_Struct(self, wxProgressDialog, ptr);
    ptr->Resume();
}

VALUE WxProgressDialog::rubyClass;

class ZAutoDefineWxProgressDialog
{
public:
   ZAutoDefineWxProgressDialog()
    {
       WxProgressDialog::DefineClass();
    }
};
static ZAutoDefineWxProgressDialog x2;

//-------------------------------------------------------------------------------------
void WxFindReplaceData::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"FindReplaceData", rb_cObject);
	rb_define_alloc_func(rubyClass,WxFindReplaceData::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFindReplaceData::init), -1);
	rb_define_method(rubyClass, "get_find_string", VALUEFUNC(WxFindReplaceData::GetFindString), 0);
	rb_define_method(rubyClass, "get_flags", VALUEFUNC(WxFindReplaceData::GetFlags), 0);
	rb_define_method(rubyClass, "get_replace_string", VALUEFUNC(WxFindReplaceData::GetReplaceString), 0);
	rb_define_method(rubyClass, "set_find_string", VALUEFUNC(WxFindReplaceData::SetFindString), 1);
	rb_define_method(rubyClass, "set_flags", VALUEFUNC(WxFindReplaceData::SetFlags), 1);
	rb_define_method(rubyClass, "set_replace_string", VALUEFUNC(WxFindReplaceData::SetReplaceString), 1);
}

VALUE
WxFindReplaceData::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFindReplaceData::init(int argc, VALUE *argv, VALUE self)
{
    wxUint32 flags = 0;
    if(argc>0) flags = NUM2INT(argv[0]);

    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    ptr = new wxFindReplaceData(flags);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxFindReplaceData::GetFindString(VALUE self)
{
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    return rb_str_new2(ptr->GetFindString());
}

VALUE
WxFindReplaceData::GetReplaceString(VALUE self)
{
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    return rb_str_new2(ptr->GetReplaceString());
}

VALUE
WxFindReplaceData::GetFlags(VALUE self)
{
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    return NUM2INT(ptr->GetFlags());
}

void
WxFindReplaceData::SetFlags(VALUE self,VALUE vflags)
{
    wxUint32 flags = NUM2INT(vflags);
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    ptr->SetFlags(flags);
}

void
WxFindReplaceData::SetFindString(VALUE self,VALUE vstr)
{
    wxString str = StringValuePtr(vstr);
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    ptr->SetFindString(str);
}

void
WxFindReplaceData::SetReplaceString(VALUE self,VALUE vstr)
{
    wxString str = StringValuePtr(vstr);
    wxFindReplaceData *ptr;
    Data_Get_Struct(self, wxFindReplaceData, ptr);
    ptr->SetReplaceString(str);
}

VALUE
WxFindReplaceData::init0(wxFindReplaceData *data)
{
    wxFindReplaceData *ptr;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    ptr = data;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxFindReplaceData::rubyClass;

class ZAutoDefineWxFindReplaceData
{
public:
   ZAutoDefineWxFindReplaceData()
    {
       WxFindReplaceData::DefineClass();
    }
};
static ZAutoDefineWxFindReplaceData x3;

//-------------------------------------------------------------------------------
void WxTextEntryDialog::DefineClass()
{
    if(rubyClass)
        return;
    WxDialog::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"TextEntryDialog", WxDialog::rubyClass);
    rb_define_alloc_func(rubyClass,WxTextEntryDialog::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxTextEntryDialog::init), -1);
    rb_define_method(rubyClass, "get_value", VALUEFUNC(WxTextEntryDialog::GetValue), 0);
    rb_define_method(rubyClass, "set_value", VALUEFUNC(WxTextEntryDialog::SetValue), 1);
}

VALUE
WxTextEntryDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxTextEntryDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = NULL;
    if(argc>0) {
        Data_Get_Struct(argv[0], wxWindow, parent);
    }
    wxString message = StringValuePtr(argv[1]);
    wxString caption = wxGetTextFromUserPromptStr;
    if(argc>2) caption = StringValuePtr(argv[2]);
    wxString value = wxEmptyString;
    if(argc>3) value = StringValuePtr(argv[3]);
    long style = wxTextEntryDialogStyle;
    if(argc>4) style = NUM2INT(argv[4]);
    wxPoint pos = wxDefaultPosition;
    if(argc>5) {
        wxPoint *ptr;
        Data_Get_Struct(argv[5], wxPoint, ptr);
        pos = *ptr;
    }

    wxTextEntryDialog *ptr;
    Data_Get_Struct(self, wxTextEntryDialog, ptr);
    ptr = new wxTextEntryDialog(parent,message,caption,value,style,pos);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxTextEntryDialog::SetValue(VALUE self,VALUE vval)
{
    wxString val = StringValuePtr(vval);
    wxTextEntryDialog *ptr;
    Data_Get_Struct(self, wxTextEntryDialog, ptr);
    ptr->SetValue(val);
}

VALUE
WxTextEntryDialog::GetValue(VALUE self)
{
    wxTextEntryDialog *ptr;
    Data_Get_Struct(self, wxTextEntryDialog, ptr);
    return rb_str_new2(ptr->GetValue());
}

VALUE WxTextEntryDialog::rubyClass;

class ZAutoDefineWxTextEntryDialog
{
public:
   ZAutoDefineWxTextEntryDialog()
    {
       WxTextEntryDialog::DefineClass();
    }
};
static ZAutoDefineWxTextEntryDialog x4;

//-------------------------------------------------------------------------------
void WxSingleChoiceDialog::DefineClass()
{
    if(rubyClass)
        return;
    WxDialog::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"SingleChoiceDialog", WxDialog::rubyClass);
    rb_define_alloc_func(rubyClass,WxSingleChoiceDialog::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSingleChoiceDialog::init), -1);
    rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxSingleChoiceDialog::SetSelection), 1);
    rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxSingleChoiceDialog::GetSelection), 0);
    rb_define_method(rubyClass, "get_string_selection", VALUEFUNC(WxSingleChoiceDialog::GetStringSelection), 0);
}

VALUE
WxSingleChoiceDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSingleChoiceDialog::init(int argc, VALUE *argv, VALUE self)
{

    wxWindow *parent = NULL;
    if(argc>0) {
        Data_Get_Struct(argv[0], wxWindow, parent);
    }
    wxString message = StringValuePtr(argv[1]);
    wxString caption = StringValuePtr(argv[2]);
    int n = 0;
    wxString *choices = 0;
    if(argc>3) {
        n = RARRAY(argv[3])->len;
        choices = new wxString[n];
        for (int i = 0; i < n; i++) {
            choices[i] = StringValuePtr(RARRAY(argv[3])->ptr[i]);
        }
    }
    char **clientData = (char **)NULL;
    long style = wxCHOICEDLG_STYLE;
    if(argc>5) style = NUM2INT(argv[5]);
    wxPoint pos = wxDefaultPosition;
    if(argc>6) {
        wxPoint *ptr;
        Data_Get_Struct(argv[6], wxPoint, ptr);
        pos = *ptr;
    }

    wxSingleChoiceDialog *ptr;
    Data_Get_Struct(self, wxSingleChoiceDialog, ptr);
    ptr = new wxSingleChoiceDialog(parent,message,caption,n,choices,clientData,style,pos);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxSingleChoiceDialog::SetSelection(VALUE self,VALUE vsel)
{
    int sel = NUM2INT(vsel);
    wxSingleChoiceDialog *ptr;
    Data_Get_Struct(self, wxSingleChoiceDialog, ptr);
    ptr->SetSelection(sel);
}

VALUE
WxSingleChoiceDialog::GetSelection(VALUE self)
{
    wxSingleChoiceDialog *ptr;
    Data_Get_Struct(self, wxSingleChoiceDialog, ptr);
    return INT2NUM(ptr->GetSelection());
}

VALUE
WxSingleChoiceDialog::GetStringSelection(VALUE self)
{
    wxSingleChoiceDialog *ptr;
    Data_Get_Struct(self, wxSingleChoiceDialog, ptr);
    return rb_str_new2(ptr->GetStringSelection());
}

VALUE WxSingleChoiceDialog::rubyClass;

class ZAutoDefineWxSingleChoiceDialog
{
public:
   ZAutoDefineWxSingleChoiceDialog()
    {
       WxSingleChoiceDialog::DefineClass();
    }
};
static ZAutoDefineWxSingleChoiceDialog x5;

//---------------------------------------------------------------------------------
void WxTipProvider::DefineClass()
{
	if(rubyClass )
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"TipProvider", rb_cObject);
	rb_define_alloc_func(rubyClass,WxTipProvider::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "get_tip", VALUEFUNC(WxTipProvider::GetTip), 0);
	rb_define_method(rubyClass, "preprocess_tip", VALUEFUNC(WxTipProvider::PreprocessTip), 1);
	rb_define_method(rubyClass, "get_current_tip", VALUEFUNC(WxTipProvider::GetCurrentTip), 0);
}

VALUE
WxTipProvider::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxTipProvider::GetTip(VALUE self)
{
    wxTipProvider *ptr;
    Data_Get_Struct(self, wxTipProvider, ptr);
    return rb_str_new2(ptr->GetTip());
}


VALUE
WxTipProvider::PreprocessTip(VALUE self,VALUE vtip)
{
    wxString tip = StringValuePtr(vtip);
    wxTipProvider *ptr;
    Data_Get_Struct(self, wxTipProvider, ptr);
    return rb_str_new2(ptr->PreprocessTip(tip));
}

VALUE
WxTipProvider::GetCurrentTip(VALUE self)
{
    wxTipProvider *ptr;
    Data_Get_Struct(self, wxTipProvider, ptr);
    return INT2NUM(ptr->GetCurrentTip());
}

VALUE
WxTipProvider::init0(wxTipProvider *tipProvider)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = tipProvider;
    return self;
}

VALUE WxTipProvider::rubyClass;

class ZAutoDefineWxTipProvider
{
public:
   ZAutoDefineWxTipProvider()
    {
       WxTipProvider::DefineClass();
    }
};
static ZAutoDefineWxTipProvider x6;

//-------------------------------------------------------------------------------
void WxWindowDisabler::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"WindowDisabler", rb_cObject);
	rb_define_alloc_func(rubyClass,WxWindowDisabler::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxWindowDisabler::init), -1);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxWindowDisabler::free), 0);
}

VALUE
WxWindowDisabler::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxWindowDisabler::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *winToSkip = (wxWindow *)NULL;
    if(argc>0) {
        Data_Get_Struct(argv[0], wxWindow, winToSkip);
    }

    wxWindowDisabler *ptr;
    Data_Get_Struct(self, wxWindowDisabler, ptr);
    ptr = new wxWindowDisabler(winToSkip);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxWindowDisabler::free(VALUE self)
{
    wxWindowDisabler *ptr;
    Data_Get_Struct(self, wxWindowDisabler, ptr);
    delete ptr;
}

VALUE WxWindowDisabler::rubyClass;

class ZAutoDefineWxWindowDisabler
{
public:
   ZAutoDefineWxWindowDisabler()
    {
       WxWindowDisabler::DefineClass();
    }
};
static ZAutoDefineWxWindowDisabler x7;

//-------------------------------------------------------------------------------
void WxBusyInfo::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"BusyInfo", rb_cObject);
	rb_define_alloc_func(rubyClass,WxBusyInfo::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxBusyInfo::init), -1);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxBusyInfo::free), 0);
}

VALUE
WxBusyInfo::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxBusyInfo::init(int argc, VALUE *argv, VALUE self)
{
    wxString message = StringValuePtr(argv[0]);
    wxWindow *parent = NULL;
    if(argc>1) {
        Data_Get_Struct(argv[1], wxWindow, parent);
    }

    wxBusyInfo *ptr;
    Data_Get_Struct(self, wxBusyInfo, ptr);
    ptr = new wxBusyInfo(message,parent);
    DATA_PTR(self) = ptr;

    return self;
}

void
WxBusyInfo::free(VALUE self)
{
    wxBusyInfo *ptr;
    Data_Get_Struct(self, wxBusyInfo, ptr);
    delete ptr;
}

VALUE WxBusyInfo::rubyClass;

class ZAutoDefineWxBusyInfo
{
public:
   ZAutoDefineWxBusyInfo()
    {
       WxBusyInfo::DefineClass();
    }
};
static ZAutoDefineWxBusyInfo x8;

//-------------------------------------------------------------------------------

void WxFindReplaceDialog::DefineClass()
{
    if(rubyClass)
        return;
    WxDialog::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"FindReplaceDialog", WxDialog::rubyClass);
    rb_define_alloc_func(rubyClass,WxFindReplaceDialog::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFindReplaceDialog::init), -1);
    rb_define_method(rubyClass, "get_data", VALUEFUNC(WxFindReplaceDialog::GetData), 0);
    rb_define_method(rubyClass, "set_data", VALUEFUNC(WxFindReplaceDialog::SetData), 1);
}

VALUE
WxFindReplaceDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFindReplaceDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent;
    Data_Get_Struct(argv[0], wxWindow, parent);
    wxFindReplaceData *data;
    Data_Get_Struct(argv[1], wxFindReplaceData, data);
    wxString title = StringValuePtr(argv[2]);
    int style = 0;
    if(argc>3) style = NUM2INT(argv[3]);

    wxFindReplaceDialog *ptr;
    Data_Get_Struct(self, wxFindReplaceDialog, ptr);
    ptr = new wxFindReplaceDialog(parent,data,title,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxFindReplaceDialog::GetData(VALUE self)
{
    wxFindReplaceDialog *ptr;
    Data_Get_Struct(self, wxFindReplaceDialog, ptr);
    return WxFindReplaceData::init0((wxFindReplaceData*)ptr->GetData());
}

void
WxFindReplaceDialog::SetData(VALUE self,VALUE vdata)
{
    wxFindReplaceData *data;
    Data_Get_Struct(vdata, wxFindReplaceData, data);
    wxFindReplaceDialog *ptr;
    Data_Get_Struct(self, wxFindReplaceDialog, ptr);
    ptr->SetData(data);
}

VALUE WxFindReplaceDialog::rubyClass;

class ZAutoDefineWxFindReplaceDialog
{
public:
   ZAutoDefineWxFindReplaceDialog()
    {
       WxFindReplaceDialog::DefineClass();
    }
};
static ZAutoDefineWxFindReplaceDialog x9;
