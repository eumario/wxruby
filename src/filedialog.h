/**********************************************************************

  filedialog.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_FILEDIALOG_H
#define WXRUBY_FILEDIALOG_H

class WxFileDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetDirectory(VALUE self);
    static VALUE GetFilename(VALUE self);
    static VALUE GetFilenames(VALUE self);
    static VALUE GetFilterIndex(VALUE self);
    static VALUE GetMessage(VALUE self);
    static VALUE GetPath(VALUE self);
    static VALUE GetPaths(VALUE self);
    static VALUE GetStyle(VALUE self);
    static VALUE GetWildcard(VALUE self);
    static void SetDirectory(VALUE self,VALUE vdir);
    static void SetFilename(VALUE self,VALUE vname);
    static void SetFilterIndex(VALUE self,VALUE vfilterIndex);
    static void SetMessage(VALUE self,VALUE vmessage);
    static void SetPath(VALUE self,VALUE vpath);
    static void SetStyle(VALUE self,VALUE vstyle);
    static void SetWildcard(VALUE self,VALUE vwildCard);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
