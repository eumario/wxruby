/**********************************************************************

  dialog.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_DIALOG_H
#define WXRUBY_DIALOG_H

#include "wx/progdlg.h"
#include "wx/busyinfo.h"
#include "wx/tipdlg.h"
#include "wx/fdrepdlg.h"

class WxDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE ShowModal(VALUE self);
    static VALUE EndModal(VALUE self, VALUE retCode);
    static VALUE init0(wxDialog *);
    static void DefineClass();
	static VALUE rubyClass;
};

class WxProgressDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Update(int argc, VALUE *argv, VALUE self);
    static void Resume(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxFindReplaceData {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetFindString(VALUE self);
    static VALUE GetFlags(VALUE self);
    static VALUE GetReplaceString(VALUE self);
    static void SetFindString(VALUE self,VALUE vstr);
    static void SetFlags(VALUE self,VALUE vflags);
    static void SetReplaceString(VALUE self,VALUE vstr);
    static VALUE init0(wxFindReplaceData *data);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxTextEntryDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetValue(VALUE self,VALUE vval);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSingleChoiceDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void SetSelection(VALUE self,VALUE vsel);
    static VALUE GetSelection(VALUE self);
    static VALUE GetStringSelection(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxTipProvider {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetTip(VALUE self);
    static VALUE PreprocessTip(VALUE self,VALUE vtip);
    static VALUE GetCurrentTip(VALUE self);
    static VALUE init0(wxTipProvider *tipProvider);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxWindowDisabler {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void free(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxBusyInfo {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void free(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxFindReplaceDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetData(VALUE self);
    static void SetData(VALUE self,VALUE vdata);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
