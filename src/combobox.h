/**********************************************************************

  combobox.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_COMBOBOX_H
#define WXRUBY_COMBOBOX_H

class WxComboBox {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void Append(int argc,VALUE *argv,VALUE self);
    static void SetSelection(VALUE self,VALUE vn);
    static VALUE GetStringSelection(VALUE self);
    static void SetStringSelection(VALUE self,VALUE vstring);
    static void SetClientData(VALUE self,VALUE vn,VALUE vdata);
    static VALUE GetClientData(VALUE self,VALUE vn);
    static VALUE GetCount(VALUE self);
    static VALUE GetSelection(VALUE self);
    static VALUE GetString(VALUE self,VALUE vn);
    static void Clear(VALUE self);
    static void Delete(VALUE self,VALUE vn);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
