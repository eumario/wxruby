/**********************************************************************

  wx.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "rubysig.h"

#ifdef __WXMSW__
#include "wx/msw/private.h"
#endif

#define ruby_debug 	1

static FILE *f;
#define DUMP1(ARG1) if (ruby_debug) { f=fopen("test.dmp","a+");fprintf(f, "wxruby: %s\n", ARG1);fclose(f);}
#define DUMP2(ARG1, ARG2) if (ruby_debug) { f=fopen("test.dmp","a+");fprintf(f, "wxruby: ");\
fprintf(f, ARG1, ARG2); fprintf(f, "\n"); fclose(f); }

#ifdef __WXGTK__
int  wxEntryStart(int& argc, char**argv);
#else
int  wxEntryStart(int argc, char**argv);
#endif

void wxEntryCleanup();
void SetConstants();
void DefineModuleMethods();


VALUE mWx;


#ifdef __WXMSW__
extern "C"
BOOL WINAPI DllMain( HANDLE hModule, DWORD fdwReason, LPVOID lpReserved )
{
    if( fdwReason == DLL_PROCESS_ATTACH )
        wxSetInstance( (HINSTANCE)hModule );
    return TRUE;
}
#endif

VALUE new0(VALUE self)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, 0, 0);
    return res;
}

VALUE new1(VALUE self,VALUE arg1)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, 1, &arg1);
    return res;
}

VALUE new2(VALUE self,VALUE arg1,VALUE arg2)
{
    VALUE argv[2];
    argv[0] = arg1;
    argv[1] = arg2;
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, 2, argv);
    return res;
}

VALUE new3(VALUE self,VALUE arg1,VALUE arg2,VALUE arg3)
{
    VALUE argv[3];
    argv[0] = arg1;
    argv[1] = arg2;
    argv[2] = arg3;
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, 3, argv);
    return res;
}

VALUE new4(VALUE self,VALUE arg1,VALUE arg2,VALUE arg3,VALUE arg4)
{
    VALUE argv[4];
    argv[0] = arg1;
    argv[1] = arg2;
    argv[2] = arg3;
    argv[3] = arg4;
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, 4, argv);
    return res;
}

VALUE new_1(int argc, VALUE *argv, VALUE self)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, argc, argv);
    return res;
}

VALUE GetWxModule()
{
    if(!mWx)
        mWx = rb_define_module("Wx");
    return mWx;
}

VALUE objectMap;

void CreateObjectMap()
{
	objectMap = rb_hash_new();
	rb_global_variable(&objectMap);
}

void MapRubyObjectToCppObject(VALUE rubyObject, void* cppObject)
{
	VALUE cppPointer = INT2NUM((long)cppObject);
	rb_hash_aset(objectMap, cppPointer, rubyObject);
}

VALUE GetMappedRubyObjectFromCppObject(void* cppObject)
{
	VALUE cppPointer = INT2NUM((long)cppObject);
	return rb_hash_aref(objectMap, cppPointer);
}

void UnMapRubyObject(VALUE rubyObject)
{
	rb_funcall(objectMap, rb_intern("delete"), 1, rubyObject);
}

extern "C"
void Init_wxruby()
{
	CreateObjectMap();
    DefineModuleMethods();

    int argc = 1;
    char *argv = "wxruby";
    wxEntryStart(argc,&argv);

    SetConstants();
}
