/**********************************************************************

  config.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_CONFIG_H
#define WXRUBY_CONFIG_H

#include "wx/config.h"

class WxConfigBase {
public:
    static VALUE alloc(VALUE self);
    static void free(VALUE self);
//    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxConfigBase *configbase);
    static VALUE Get(int argc, VALUE *argv, VALUE self);
    static VALUE Set(VALUE self,VALUE vpConfig);
    static VALUE Create(VALUE self);
    static void DontCreateOnDemand(VALUE self);
    static VALUE Read(int argc, VALUE *argv, VALUE self);
    static VALUE ReadBool(int argc, VALUE *argv, VALUE self);
    static VALUE ReadFloat(int argc, VALUE *argv, VALUE self);
    static VALUE ReadInt(int argc, VALUE *argv, VALUE self);
    static void SetExpandEnvVars(int argc, VALUE *argv, VALUE self);
    static void SetPath(VALUE self,VALUE vstrPath);
    static void SetRecordDefaults(int argc, VALUE *argv, VALUE self);
    static void Write(VALUE self,VALUE vkey,VALUE vvalue);
    static void DeleteAll(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxConfig {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
