/**********************************************************************

  listctrl.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_LISTCTRL_H
#define WXRUBY_LISTCTRL_H

#include "wx/listctrl.h"

class wxRbListCtrl : public wxListCtrl {
public:
    wxRbListCtrl(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxLC_ICON,
            const wxValidator& validator = wxDefaultValidator, const wxString& name = "listCtrl")
        :   wxListCtrl(parent,id,pos,size,style,validator,name) { }
private:
    virtual wxString OnGetItemText(long item, long column) const;
    virtual int OnGetItemImage(long item) const;
    virtual wxListItemAttr *OnGetItemAttr(long item) const;
};

class WxListCtrl {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Arrange(int argc, VALUE *argv, VALUE self);
    static void AssignImageList(VALUE self,VALUE vimageList,VALUE vwhich);
    static void ClearAll(VALUE self);
    static VALUE DeleteAllItems(VALUE self);
    static VALUE DeleteColumn(VALUE self,VALUE vcol);
    static VALUE DeleteItem(VALUE self,VALUE vitem);
    static void EditLabel(VALUE self,VALUE vitem);
    static VALUE EnsureVisible(VALUE self,VALUE vitem);
    static VALUE FindItem(int argc, VALUE *argv, VALUE self);
    static VALUE GetColumn(VALUE self,VALUE vcol,VALUE vitem);
    static VALUE GetColumnCount(VALUE self);
    static VALUE GetColumnWidth(VALUE self,VALUE vcol);
    static VALUE GetCountPerPage(VALUE self);
#ifdef __WXMSW__
    static VALUE GetEditControl(VALUE self);
#endif
    static VALUE GetImageList(VALUE self,VALUE vwhich);
    static VALUE GetItemCount(VALUE self);
    static VALUE GetItem(int argc, VALUE *argv, VALUE self);
    static VALUE GetItemData(VALUE self,VALUE vitem);
    static VALUE GetItemPosition(VALUE self,VALUE vitem);
    static VALUE GetItemRect(int argc, VALUE *argv, VALUE self);
    static VALUE GetItemSpacing(VALUE self,VALUE visSmall);
    static VALUE GetItemState(VALUE self,VALUE vitem,VALUE vstateMask);
    static VALUE GetItemText(int argc, VALUE *argv, VALUE self);
    static VALUE GetSelectedItemCount(VALUE self);
    static VALUE GetTextColour(VALUE self);
    static VALUE GetTopItem(VALUE self);
    static VALUE HitTest(VALUE self,VALUE vpoint);
    static VALUE InsertColumn(int argc, VALUE *argv, VALUE self);
    static VALUE InsertItem(int argc, VALUE *argv, VALUE self);
    static VALUE ScrollList(VALUE self,VALUE vdx,VALUE vdy);
    static void SetBackgroundColour(VALUE self,VALUE vcol);
    static VALUE SetColumn(VALUE self,VALUE vcol,VALUE vitem);
    static VALUE SetColumnWidth(VALUE self,VALUE vcol,VALUE vwidth);
    static void SetImageList(VALUE self,VALUE vimageList,VALUE vwhich);
    static VALUE SetItem(int argc, VALUE *argv, VALUE self);
    static void SetItemCount(VALUE self,VALUE vcount);
    static VALUE SetItemData(VALUE self,VALUE vitem,VALUE vdata);
    static VALUE SetItemImage(VALUE self,VALUE vitem,VALUE vimage,VALUE vselImage);
    static VALUE SetItemPosition(VALUE self,VALUE vitem,VALUE vpos);
    static VALUE SetItemState(VALUE self,VALUE vitem,VALUE vstate,VALUE vstateMask);
    static void SetItemText(VALUE self,VALUE vitem,VALUE vtext);
    static void SetSingleStyle(int argc, VALUE *argv, VALUE self);
    static void SetTextColour(VALUE self,VALUE vcol);
    static void SetWindowStyleFlag(VALUE self,VALUE vstyle);
    static VALUE GetNextItem(int argc, VALUE *argv, VALUE self);
    static VALUE SortItems(VALUE self,VALUE klass,VALUE vfunc);
    static VALUE IsVirtual(VALUE self);
    static void RefreshItem(VALUE self,VALUE vitem);
    static void RefreshItems(VALUE self,VALUE vitem,VALUE vitemTo);
    
    static void DefineClass();
	static VALUE rubyClass;
};

class WxListItemAttr {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxListItemAttr *list);
    static VALUE GetBackgroundColour(VALUE self);
    static VALUE GetFont(VALUE self);
    static VALUE GetTextColour(VALUE self);
    static VALUE HasBackgroundColour(VALUE self);
    static VALUE HasFont(VALUE self);
    static VALUE HasTextColour(VALUE self);
    static void SetBackgroundColour(VALUE self,VALUE vcolBack);
    static void SetFont(VALUE self,VALUE vfont);
    static void SetTextColour(VALUE self,VALUE vcolText);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxListItem {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static void free(VALUE self);
    static VALUE init0(wxListItem *list);
    static void Clear(VALUE self);
    static VALUE GetAlign(VALUE self);
    static VALUE GetBackgroundColour(VALUE self);
    static VALUE GetColumn(VALUE self);
    static VALUE GetData(VALUE self);
    static VALUE GetFont(VALUE self);
    static VALUE GetId(VALUE self);
    static VALUE GetImage(VALUE self);
    static VALUE GetMask(VALUE self);
    static VALUE GetState(VALUE self);
    static VALUE GetText(VALUE self);
    static VALUE GetTextColour(VALUE self);
    static VALUE GetWidth(VALUE self);
    static void SetAlign(VALUE self,VALUE valign);
    static void SetBackgroundColour(VALUE self,VALUE vcolBack);
    static void SetColumn(VALUE self,VALUE vcol);
    static void SetData(VALUE self,VALUE vdata);
    static void SetFont(VALUE self,VALUE vfont);
    static void SetId(VALUE self,VALUE vid);
    static void SetImage(VALUE self,VALUE vimage);
    static void SetMask(VALUE self,VALUE vmask);
    static void SetState(VALUE self,VALUE vstate);
    static void SetStateMask(VALUE self,VALUE vstateMask);
    static void SetText(VALUE self,VALUE vtext);
    static void SetTextColour(VALUE self,VALUE vcolText);
    static void SetWidth(VALUE self,VALUE vwidth);
    static VALUE GetAttributes(VALUE self);
    
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
