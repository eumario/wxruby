/**********************************************************************

  sizer.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SIZER_H
#define WXRUBY_SIZER_H

class WxSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxSizer *sizer);
    static VALUE Add(int argc, VALUE *argv, VALUE self);
    static VALUE Insert(int argc, VALUE *argv, VALUE self);
    static VALUE Fit(VALUE self,VALUE vwindow);
    static VALUE FitInside(VALUE self,VALUE vwindow);
    static VALUE SetSizeHints(VALUE self,VALUE vwindow);
    static VALUE SetVirtualSizeHints(VALUE self,VALUE vwindow);
    static VALUE Remove(VALUE self,VALUE argv);
    static VALUE Show(int argc, VALUE *argv, VALUE self);
    static VALUE Layout(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxGridSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void RecalcSizes(VALUE self);
    static VALUE CalcMin(VALUE self);
    static VALUE GetCols(VALUE self);
    static VALUE GetRows(VALUE self);
    static VALUE GetVGap(VALUE self);
    static VALUE GetHGap(VALUE self);
    static void SetCols(VALUE self,VALUE vcols);
    static void SetRows(VALUE self,VALUE vrows);
    static void SetVGap(VALUE self,VALUE vgap);
    static void SetHGap(VALUE self,VALUE vgap);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxFlexGridSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void RecalcSizes(VALUE self);
    static VALUE CalcMin(VALUE self);
    static void AddGrowableRow(VALUE self,VALUE vidx);
    static void RemoveGrowableRow(VALUE self,VALUE vidx);
    static void AddGrowableCol(VALUE self,VALUE vidx);
    static void RemoveGrowableCol(VALUE self,VALUE vidx);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxBoxSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vorient);
    static void RecalcSizes(VALUE self);
    static VALUE CalcMin(VALUE self);
    static VALUE GetOrientation(VALUE self);
    static void SetOrientation(VALUE self,VALUE vorient);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxStaticBoxSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vbox,VALUE vorient);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxNotebookSizer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vnb);
    static void RecalcSizes(VALUE self);
    static VALUE CalcMin(VALUE self);
    static VALUE GetNotebook(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
