/**********************************************************************

  wx.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_WX_H
#define WXRUBY_WX_H

#include "wx/wx.h"
#include "ruby.h"
#include "version.h"
#include "dynamiccast.h"

#ifdef __cplusplus
#  ifndef RUBY_METHOD_FUNC /* These definitions should work for Ruby 1.4.6 */
#    define VALUEFUNC(f) ((VALUE (*)()) f)
#    define VOIDFUNC(f)  ((void (*)()) f)
#  else
#    ifndef ANYARGS /* These definitions should work for Ruby 1.6 */
#      define VALUEFUNC(f) ((VALUE (*)()) f)
#      define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)
#    else /* These definitions should work for Ruby 1.7 */
#      define VALUEFUNC(f) ((VALUE (*)(ANYARGS)) f)
#      define VOIDFUNC(f)  ((RUBY_DATA_FUNC) f)
#    endif
#  endif
#else
#  define VALUEFUNC(f) (f)
#  define VOIDFUNC(f) (f)
#endif

#if RUBY_VERSION_CODE < 180
#define StringValue(x) do { 				\
    if (TYPE(x) != T_STRING) x = rb_str_to_str(x); 	\
} while (0)
#define StringValuePtr(x) STR2CSTR(x)
#define SafeStringValue(x) Check_SafeStr(x)
#define rb_define_alloc_func(klass,func) rb_define_singleton_method(klass,"allocate",VALUEFUNC(func),0)
#endif

template <class T>
T* GetCpp(VALUE self)
{
    if(TYPE(self) != T_DATA)
        return 0;
    T* p = 0;
    Data_Get_Struct(self, T, p);
    return p;
}

inline bool IsTrue(VALUE value)
{
	if(value == Qnil || value == Qfalse)
		return false;
	
	return true;
}

inline VALUE CppBoolToRubyBool(bool value)
{
	if(value)
		return Qtrue;
	return Qfalse;
}

VALUE new0(VALUE self);
VALUE new1(VALUE self,VALUE arg1);
VALUE new2(VALUE self,VALUE arg1,VALUE arg2);
VALUE new3(VALUE self,VALUE arg1,VALUE arg2,VALUE arg3);
VALUE new4(VALUE self,VALUE arg1,VALUE arg2,VALUE arg3,VALUE arg4);
VALUE new_1(int argc, VALUE *argv, VALUE self);

VALUE WxGetApp(VALUE self);

VALUE GetWxModule();

void MapRubyObjectToCppObject(VALUE rubyObject, void* cppObject);
VALUE GetMappedRubyObjectFromCppObject(void* cppObject);
void UnMapRubyObject(VALUE rubyObject);

#endif
