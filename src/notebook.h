/**********************************************************************

  notebook.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_NOTEBOOK_H
#define WXRUBY_NOTEBOOK_H

#include "wx/notebook.h"
#include "window.h"

typedef WxWindow    WxNotebookPage;

class WxNotebook {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxNotebook *nb);
    static VALUE AddPage(int argc, VALUE *argv, VALUE self);
    static void AdvanceSelection(int argc, VALUE *argv, VALUE self);
    static void AssignImageList(VALUE self,VALUE vimageList);
    static VALUE DeleteAllPages(VALUE self);
    static VALUE DeletePage(VALUE self,VALUE vpage);
    static VALUE GetImageList(VALUE self);
    static VALUE GetPage(VALUE self,VALUE vpage);
    static VALUE GetPageCount(VALUE self);
    static VALUE GetPageImage(VALUE self,VALUE vpage);
    static VALUE GetPageText(VALUE self,VALUE vpage);
    static VALUE GetRowCount(VALUE self);
    static VALUE GetSelection(VALUE self);
    static VALUE InsertPage(int argc, VALUE *argv, VALUE self);
    static VALUE RemovePage(VALUE self,VALUE vpage);
    static void SetImageList(VALUE self,VALUE vimageList);
    static void SetPadding(VALUE self,VALUE vpadding);
    static VALUE SetPageImage(VALUE self,VALUE vpage,VALUE vimage);
    static void SetPageSize(VALUE self,VALUE vsize);
    static VALUE SetPageText(VALUE self,VALUE vpage,VALUE vtext);
    static VALUE SetSelection(VALUE self,VALUE vpage);
    
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
