/**********************************************************************

  filedialog.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "filedialog.h"
#include "dialog.h"

void WxFileDialog::DefineClass()
{
	if(rubyClass)
		return;
	WxDialog::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"FileDialog", WxDialog::rubyClass);
	rb_define_alloc_func(rubyClass,WxFileDialog::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFileDialog::init), -1);
	rb_define_method(rubyClass, "get_directory", VALUEFUNC(WxFileDialog::GetDirectory), 0);
	rb_define_method(rubyClass, "get_filename", VALUEFUNC(WxFileDialog::GetFilename), 0);
	rb_define_method(rubyClass, "get_filenames", VALUEFUNC(WxFileDialog::GetFilenames), 0);
	rb_define_method(rubyClass, "get_filter_index", VALUEFUNC(WxFileDialog::GetFilterIndex), 0);
	rb_define_method(rubyClass, "get_message", VALUEFUNC(WxFileDialog::GetMessage), 0);
	rb_define_method(rubyClass, "get_path", VALUEFUNC(WxFileDialog::GetPath), 0);
	rb_define_method(rubyClass, "get_paths", VALUEFUNC(WxFileDialog::GetPaths), 0);
	rb_define_method(rubyClass, "get_style", VALUEFUNC(WxFileDialog::GetStyle), 0);
	rb_define_method(rubyClass, "get_wildcard", VALUEFUNC(WxFileDialog::GetWildcard), 0);
	rb_define_method(rubyClass, "set_directory", VALUEFUNC(WxFileDialog::SetDirectory), 1);
	rb_define_method(rubyClass, "set_filename", VALUEFUNC(WxFileDialog::SetFilename), 1);
	rb_define_method(rubyClass, "set_filter_index", VALUEFUNC(WxFileDialog::SetFilterIndex), 1);
	rb_define_method(rubyClass, "set_message", VALUEFUNC(WxFileDialog::SetMessage), 1);
	rb_define_method(rubyClass, "set_path", VALUEFUNC(WxFileDialog::SetPath), 1);
	rb_define_method(rubyClass, "set_style", VALUEFUNC(WxFileDialog::SetStyle), 1);
	rb_define_method(rubyClass, "set_wildcard", VALUEFUNC(WxFileDialog::SetWildcard), 1);
}

VALUE
WxFileDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFileDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxString message = "Choose a file";
    wxString defaultDir = "";
    wxString defaultFile = "";
    wxString wildcard = "*.*";
    long style = 0;
    wxPoint pos = wxDefaultPosition;

    if(argc>0 && TYPE(argv[0])==T_DATA) {
      Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_STRING)
      message = wxString(StringValuePtr(argv[1]));
    if(argc>2 && TYPE(argv[2])==T_STRING)
      defaultDir = wxString(StringValuePtr(argv[2]));
    if(argc>3 && TYPE(argv[3])==T_STRING)
      defaultFile = wxString(StringValuePtr(argv[3]));
    if(argc>4 && TYPE(argv[4])==T_STRING)
      wildcard = wxString(StringValuePtr(argv[4]));
    if(argc>5 && TYPE(argv[5])==T_FIXNUM)
      style = NUM2INT(argv[5]);
    if(argc>6 && TYPE(argv[6])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[6], wxPoint, ptr);
	pos = *ptr;
    }

    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr = new wxFileDialog(parent,message,defaultDir,defaultFile,wildcard,style,pos);
    DATA_PTR(self) = ptr;

    return self;
}


VALUE
WxFileDialog::GetMessage(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return rb_str_new2(ptr->GetMessage());
}

VALUE
WxFileDialog::GetFilename(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return rb_str_new2(ptr->GetFilename());
}

VALUE
WxFileDialog::GetPath(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return rb_str_new2(ptr->GetPath());
}

VALUE
WxFileDialog::GetDirectory(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return rb_str_new2(ptr->GetDirectory());
}

VALUE
WxFileDialog::GetWildcard(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return rb_str_new2(ptr->GetWildcard());
}

VALUE
WxFileDialog::GetStyle(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return INT2NUM(ptr->GetStyle());
}

VALUE
WxFileDialog::GetFilterIndex(VALUE self)
{
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    return INT2NUM(ptr->GetFilterIndex());
}

VALUE
WxFileDialog::GetPaths(VALUE self)
{
    wxArrayString paths;
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->GetPaths(paths);
    int r = paths.Count();
    VALUE ary = rb_ary_new();
    for(int i=0;i<r;i++) {
        rb_ary_push(ary,rb_str_new2(paths[i]));
    }

    return ary;
}

VALUE
WxFileDialog::GetFilenames(VALUE self)
{
    wxArrayString files;
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->GetFilenames(files);
    int r = files.Count();
    VALUE ary = rb_ary_new();
    for(int i=0;i<r;i++) {
        rb_ary_push(ary,rb_str_new2(files[i]));
    }

    return ary;
}

void
WxFileDialog::SetMessage(VALUE self,VALUE vmessage)
{
    wxString message = StringValuePtr(vmessage);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetMessage(message);
}

void
WxFileDialog::SetPath(VALUE self,VALUE vpath)
{
    wxString path = StringValuePtr(vpath);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetPath(path);
}

void
WxFileDialog::SetDirectory(VALUE self,VALUE vdir)
{
    wxString dir = StringValuePtr(vdir);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetDirectory(dir);
}

void
WxFileDialog::SetFilename(VALUE self,VALUE vname)
{
    wxString name = StringValuePtr(vname);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetFilename(name);
}

void
WxFileDialog::SetWildcard(VALUE self,VALUE vwildCard)
{
    wxString wildCard = StringValuePtr(vwildCard);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetWildcard(wildCard);
}

void
WxFileDialog::SetStyle(VALUE self,VALUE vstyle)
{
    long style = NUM2INT(vstyle);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetStyle(style);
}

void
WxFileDialog::SetFilterIndex(VALUE self,VALUE vfilterIndex)
{
    int filterIndex = NUM2INT(vfilterIndex);
    wxFileDialog *ptr;
    Data_Get_Struct(self, wxFileDialog, ptr);
    ptr->SetFilterIndex(filterIndex);
}

VALUE WxFileDialog::rubyClass;

class ZAutoDefineWxFileDialog
{
public:
   ZAutoDefineWxFileDialog()
    {
       WxFileDialog::DefineClass();
    }
};
static ZAutoDefineWxFileDialog x;
