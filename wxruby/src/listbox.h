/**********************************************************************

  listbox.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_LISTBOX_H
#define WXRUBY_LISTBOX_H

class WxListBox {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void Append(VALUE self,VALUE vitem);
    static void SetSelection(int argc, VALUE *argv, VALUE self);
    static VALUE GetString(VALUE self,VALUE vn);
    static VALUE GetStringSelection(VALUE self);
#ifdef __WXMSW__
    static VALUE GetItem(VALUE self,VALUE vn);
#endif
    static void Deselect(VALUE self,VALUE vn);
    static void Delete(VALUE self,VALUE vn);
    static void DeselectAll(int argc, VALUE *argv, VALUE self);
    static VALUE IsSelected(VALUE self,VALUE vn);
    static void Select(VALUE self,VALUE vn);
    static VALUE GetSelection(VALUE self);
    static VALUE GetSelections(VALUE self);
    static VALUE GetCount(VALUE self);
    static void InsertItems(VALUE self,VALUE vitems,VALUE vpos);
//    static void SetClientData(VALUE self,VALUE vn,VALUE vdata);
    static void SetClientObject(VALUE self,VALUE vn,VALUE vdata);
//    static VALUE GetClientData(VALUE self,VALUE vn);
    static VALUE GetClientObject(VALUE self,VALUE vn);
    static void SetString(VALUE self,VALUE vn,VALUE vstring);
    static void SetStringSelection(int argc, VALUE *argv, VALUE self);
    static void Clear(VALUE self);
    
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
