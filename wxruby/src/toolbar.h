/**********************************************************************

  toolbar.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_TOOLBAR_H
#define WXRUBY_TOOLBAR_H

#include "wx/toolbar.h"

class WxToolBarToolBase {
public:
    static VALUE init0(wxToolBarToolBase *toolbar);
};

class WxToolBar {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxToolBar *toolbar);
    static VALUE AddCheckTool(int argc, VALUE *argv, VALUE self);
    static VALUE AddControl(VALUE self,VALUE vcontrol);
    static VALUE AddRadioTool(int argc, VALUE *argv, VALUE self);
    static void AddSeparator(VALUE self);
    static VALUE AddTool(int argc, VALUE *argv, VALUE self);
    static VALUE DeleteTool(VALUE self,VALUE vtoolId);
    static VALUE DeleteToolByPos(VALUE self,VALUE vpos);
    static void EnableTool(VALUE self,VALUE vtoolId,VALUE venable);
    static VALUE GetMargins(VALUE self);
    static VALUE GetToolBitmapSize(VALUE self);
    static VALUE GetToolClientData(VALUE self,VALUE vtoolId);
    static VALUE GetToolEnabled(VALUE self,VALUE vtoolId);
    static VALUE GetToolLongHelp(VALUE self,VALUE vtoolId);
    static VALUE GetToolPacking(VALUE self);
    static VALUE GetToolSeparation(VALUE self);
    static VALUE GetToolShortHelp(VALUE self,VALUE vtoolId);
    static VALUE GetToolSize(VALUE self);
    static VALUE GetToolState(VALUE self,VALUE vtoolId);
    static VALUE InsertControl(VALUE self,VALUE vpos,VALUE vcontrol);
    static VALUE InsertSeparator(VALUE self,VALUE vpos);
    static VALUE InsertTool(int argc, VALUE *argv, VALUE self);
    static VALUE Realize(VALUE self);
    static VALUE RemoveTool(VALUE self,VALUE vid);
    static void SetMargins(VALUE self,VALUE vx,VALUE vy);
    static void SetToolBitmapSize(VALUE self,VALUE vsize);
    static void SetToolClientData(VALUE self,VALUE vid,VALUE vclientData);
    static void SetToolLongHelp(VALUE self,VALUE vtoolId,VALUE vhelpString);
    static void SetToolPacking(VALUE self,VALUE vpacking);
    static void SetToolSeparation(VALUE self,VALUE vseparation);
    static void SetToolShortHelp(VALUE self,VALUE vtoolId,VALUE vhelpString);
    static void ToggleTool(VALUE self,VALUE vtoolId,VALUE vtoggle);
    static void SetRows(VALUE self,VALUE vnRows);
    static void SetMaxRowsCols(VALUE self,VALUE vrows,VALUE vcols);
    static VALUE GetMaxRows(VALUE self);
    static VALUE GetMaxCols(VALUE self);
    
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
