/**********************************************************************

  splitterwindow.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/
#ifndef WXRUBY_SPLITTERWINDOW_H
#define WXRUBY_SPLITTERWINDOW_H

#include "wx/splitter.h"

class WxSplitterWindow {
public:
    static VALUE alloc(VALUE self);
	static VALUE wrapNew(int argc, VALUE *argv, VALUE self);
	static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetMinimumPaneSize(VALUE self);
    static VALUE GetSashPosition(VALUE self);
    static VALUE GetSplitMode(VALUE self);
    static VALUE GetWindow1(VALUE self);
    static VALUE GetWindow2(VALUE self);
    static void Initialize(VALUE self,VALUE vwindow);
    static VALUE IsSplit(VALUE self);
    static VALUE ReplaceWindow(VALUE self,VALUE vwinOld,VALUE vwinNew);
    static void SetMinimumPaneSize(VALUE self,VALUE vpaneSize);
    static void SetSashPosition(int argc, VALUE *argv, VALUE self);
    static void SetSplitMode(VALUE self,VALUE vmode);
    static VALUE SplitHorizontally(int argc, VALUE *argv, VALUE self);
    static VALUE SplitVertically(int argc, VALUE *argv, VALUE self);
    static VALUE Unsplit(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
