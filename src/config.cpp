/**********************************************************************

  config.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "config.h"

void WxConfigBase::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ConfigBase", rb_cObject);
	rb_define_alloc_func(rubyClass,WxConfigBase::alloc);
//    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxConfigBase::init), -1);
	rb_define_singleton_method(rubyClass, "get", VALUEFUNC(WxConfigBase::Get), -1);
	rb_define_singleton_method(rubyClass, "set", VALUEFUNC(WxConfigBase::Set), 1);
	rb_define_singleton_method(rubyClass, "create", VALUEFUNC(WxConfigBase::Create), 0);
	rb_define_singleton_method(rubyClass, "dont_create_on_demand", VALUEFUNC(WxConfigBase::DontCreateOnDemand), 0);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxConfigBase::free), 0);
	rb_define_method(rubyClass, "read", VALUEFUNC(WxConfigBase::Read), -1);
	rb_define_method(rubyClass, "read_int", VALUEFUNC(WxConfigBase::ReadInt), -1);
	rb_define_method(rubyClass, "read_bool", VALUEFUNC(WxConfigBase::ReadBool), -1);
	rb_define_method(rubyClass, "read_float", VALUEFUNC(WxConfigBase::ReadFloat), -1);
	rb_define_method(rubyClass, "set_expand_env_vars", VALUEFUNC(WxConfigBase::SetExpandEnvVars), -1);
	rb_define_method(rubyClass, "set_path", VALUEFUNC(WxConfigBase::SetPath), 1);
	rb_define_method(rubyClass, "set_record_defaults", VALUEFUNC(WxConfigBase::SetRecordDefaults), -1);
	rb_define_method(rubyClass, "write", VALUEFUNC(WxConfigBase::Write), 2);
	rb_define_method(rubyClass, "delete_all", VALUEFUNC(WxConfigBase::DeleteAll), 0);
}

VALUE
WxConfigBase::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

void
WxConfigBase::free(VALUE self)
{
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    if(ptr)
        delete ptr;
}

VALUE
WxConfigBase::Set(VALUE self,VALUE vpConfig)
{
    wxConfigBase *pConfig = NULL;
    if(vpConfig!=Qnil)
        Data_Get_Struct(vpConfig, wxConfigBase, pConfig);
    return WxConfigBase::init0(wxConfigBase::Set(pConfig));
}

VALUE
WxConfigBase::Get(int argc, VALUE *argv, VALUE self)
{
    bool CreateOnDemand = TRUE;
    if(argc>0 && argv[0]==Qfalse) CreateOnDemand = FALSE;
    return WxConfigBase::init0(wxConfigBase::Get(CreateOnDemand));
}

VALUE
WxConfigBase::Create(VALUE self)
{
    return WxConfigBase::init0(wxConfigBase::Create());
}

void
WxConfigBase::DontCreateOnDemand(VALUE self)
{
    wxConfigBase::DontCreateOnDemand();
}

void
WxConfigBase::SetRecordDefaults(int argc, VALUE *argv, VALUE self)
{
    bool bDoIt = TRUE;
    if(argc>0 && argv[0]==Qfalse) bDoIt = FALSE;
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    ptr->SetRecordDefaults(bDoIt);
}

void
WxConfigBase::SetExpandEnvVars(int argc, VALUE *argv, VALUE self)
{
    bool bDoIt = TRUE;
    if(argc>0 && argv[0]==Qfalse) bDoIt = FALSE;
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    ptr->SetExpandEnvVars(bDoIt);
}

void
WxConfigBase::SetPath(VALUE self,VALUE vstrPath)
{
    wxString strPath = StringValuePtr(vstrPath);
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    ptr->SetPath(strPath);
}

/*
void
WxConfigBase::SetUmask(VALUE self,VALUE vmode)
{
    int mode = NUM2INT(vmode);
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    ptr->SetUmask(mode);
}
*/

void
WxConfigBase::Write(VALUE self,VALUE vkey,VALUE vvalue)
{
    wxString key = StringValuePtr(vkey);
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    if(TYPE(vvalue)==T_STRING) {
        wxString value = StringValuePtr(vvalue);
        ptr->Write(key,value);
    } else if(TYPE(vvalue)==T_FIXNUM) {
        long value = NUM2INT(vvalue);
        ptr->Write(key,value);
    } else if(TYPE(vvalue)==T_FLOAT) {
        double value = (RFLOAT(vvalue)->value);
        ptr->Write(key,value);
    } else {
        bool value = (vvalue == Qtrue);
        ptr->Write(key,value);
    }
}

VALUE
WxConfigBase::Read(int argc, VALUE *argv, VALUE self)
{
    wxString key = StringValuePtr(argv[0]);
    wxString defaultVal = "";
    if(argc>1) defaultVal = StringValuePtr(argv[1]);
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    return rb_str_new2(ptr->Read(key,defaultVal));
}

VALUE
WxConfigBase::ReadInt(int argc, VALUE *argv, VALUE self)
{
    wxString key = StringValuePtr(argv[0]);
    long l;
    long defaultVal = 0;
    if(argc>1) defaultVal = NUM2INT(argv[1]);
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    if(!ptr->Read(key,&l,defaultVal)) l = defaultVal;
    return INT2NUM(l);
}

VALUE
WxConfigBase::ReadFloat(int argc, VALUE *argv, VALUE self)
{
    wxString key = StringValuePtr(argv[0]);
    double d;
    double defaultVal = 0;
    if(argc>1) defaultVal = RFLOAT(argv[1])->value;
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    if(!ptr->Read(key,&d,defaultVal)) d = defaultVal;
    return rb_float_new(d);
}

VALUE
WxConfigBase::ReadBool(int argc, VALUE *argv, VALUE self)
{
    wxString key = StringValuePtr(argv[0]);
    bool b;
    bool defaultVal = FALSE;
    if(argc>1 && argv[1]==Qtrue) defaultVal = TRUE;
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    if(!ptr->Read(key,&b,defaultVal)) b = defaultVal;
    return (b ? Qtrue : Qfalse);
}


VALUE
WxConfigBase::init0(wxConfigBase *configbase)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    if(configbase==NULL) return Qnil;
    DATA_PTR(self) = configbase;
    return self;
}

void
WxConfigBase::DeleteAll(VALUE self)
{
    wxConfigBase *ptr;
    Data_Get_Struct(self, wxConfigBase, ptr);
    ptr->DeleteAll();
}

VALUE WxConfigBase::rubyClass;

class ZAutoDefineWxConfigBase
{
public:
   ZAutoDefineWxConfigBase()
    {
       WxConfigBase::DefineClass();
    }
};
static ZAutoDefineWxConfigBase x;

//-----------------------------------------------------------------------------------------
void WxConfig::DefineClass()
{
	if(rubyClass)
		return;
	WxConfigBase::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Config", WxConfigBase::rubyClass);
	rb_define_alloc_func(rubyClass,WxConfig::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxConfig::init), -1);
}

VALUE
WxConfig::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxConfig::init(int argc, VALUE *argv, VALUE self)
{
    wxString appName = wxEmptyString;
    if(argc>0) appName = StringValuePtr(argv[0]);
    wxString vendorName = wxEmptyString;
    if(argc>1) vendorName = StringValuePtr(argv[1]);
    wxString localFilename = wxEmptyString;
    if(argc>2) localFilename = StringValuePtr(argv[2]);
    wxString globalFilename = wxEmptyString;
    if(argc>3) globalFilename = StringValuePtr(argv[3]);
    long style = 0;
    if(argc>4) style = NUM2INT(argv[4]);

    wxConfig *ptr;
    Data_Get_Struct(self, wxConfig, ptr);
    ptr = new wxConfig(appName,vendorName,localFilename,globalFilename,style);
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxConfig::rubyClass;

class ZAutoDefineWxConfig
{
public:
   ZAutoDefineWxConfig()
    {
       WxConfig::DefineClass();
    }
};
static ZAutoDefineWxConfig x2;
