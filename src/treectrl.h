/**********************************************************************

  treectrl.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_TREECTRL_H
#define WXRUBY_TREECTRL_H

#include "wx/treectrl.h"

class wxRbTreeItemData : public wxTreeItemData {
public:
    wxRbTreeItemData() : wxTreeItemData() { }
    VALUE m_self;
};

class wxRbTreeCtrl : public wxTreeCtrl {
public:
    wxRbTreeCtrl(wxWindow* parent=NULL, wxWindowID id=-1, const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxTR_DEFAULT_STYLE,
            const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTreeCtrlNameStr)
        :   wxTreeCtrl(parent,id,pos,size,style,validator,name) { }

    virtual int OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2);
    DECLARE_DYNAMIC_CLASS(wxRbTreeCtrl)
};

class WxTreeItemData {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxRbTreeItemData *data);
    static VALUE GetId(VALUE self);
    static void SetId(VALUE self,VALUE vid);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxTreeCtrl {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE AddRoot(int argc, VALUE *argv, VALUE self);
    static VALUE AppendItem(int argc, VALUE *argv, VALUE self);
//    static void AssignButtonsImageList(VALUE self,VALUE vimageList);
    static void AssignImageList(VALUE self,VALUE vimageList);
    static void AssignStateImageList(VALUE self,VALUE vimageList);
    static void Collapse(VALUE self,VALUE vitem);
    static void CollapseAndReset(VALUE self,VALUE vitem);
    static void Delete(VALUE self,VALUE vitem);
    static void DeleteAllItems(VALUE self);
    static void DeleteChildren(VALUE self,VALUE vitem);
    static void EditLabel(VALUE self,VALUE vitem);
    static void EnsureVisible(VALUE self,VALUE vitem);
    static void Expand(VALUE self,VALUE vitem);
    static VALUE GetBoundingRect(int argc, VALUE *argv, VALUE self);
//    static VALUE GetButtonsImageList(VALUE self);
    static VALUE GetChildrenCount(int argc, VALUE *argv, VALUE self);
    static VALUE GetCount(VALUE self);
    static VALUE GetEditControl(VALUE self);
    static VALUE GetFirstChild(VALUE self,VALUE vitem);
    static VALUE GetFirstVisibleItem(VALUE self);
    static VALUE GetImageList(VALUE self);
    static VALUE GetIndent(VALUE self);
    static VALUE GetSpacing(VALUE self);
    static VALUE GetItemBackgroundColour(VALUE self,VALUE vitem);
    static VALUE GetItemData(VALUE self,VALUE vitem);
    static VALUE GetItemFont(VALUE self,VALUE vitem);
    static VALUE GetItemImage(int argc, VALUE *argv, VALUE self);
    static VALUE GetItemParent(VALUE self,VALUE vitem);
    static VALUE GetItemSelectedImage(VALUE self,VALUE vitem);
    static VALUE GetItemText(VALUE self,VALUE vitem);
    static VALUE GetItemTextColour(VALUE self,VALUE vitem);
    static VALUE GetLastChild(VALUE self,VALUE vitem);
    static VALUE GetNextChild(VALUE self,VALUE vitem,VALUE vcookie);
    static VALUE GetNextSibling(VALUE self,VALUE vitem);
    static VALUE GetNextVisible(VALUE self,VALUE vitem);
    static VALUE GetPrevSibling(VALUE self,VALUE vitem);
    static VALUE GetPrevVisible(VALUE self,VALUE vitem);
    static VALUE GetRootItem(VALUE self);
    static VALUE GetSelection(VALUE self);
    static VALUE GetSelections(VALUE self);
    static VALUE GetStateImageList(VALUE self);
    static VALUE HitTest(VALUE self,VALUE vpoint);
    static VALUE InsertItem(int argc, VALUE *argv, VALUE self);
    static VALUE InsertItemBefore(int argc, VALUE *argv, VALUE self);
    static VALUE IsBold(VALUE self,VALUE vitem);
    static VALUE IsExpanded(VALUE self,VALUE vitem);
    static VALUE IsSelected(VALUE self,VALUE vitem);
    static VALUE IsVisible(VALUE self,VALUE vitem);
    static VALUE ItemHasChildren(VALUE self,VALUE vitem);
    static VALUE PrependItem(int argc, VALUE *argv, VALUE self);
    static void ScrollTo(VALUE self,VALUE vitem);
    static void SelectItem(VALUE self,VALUE vitem);
//    static void SetButtonsImageList(VALUE self,VALUE vimageList);
    static void SetImageList(VALUE self,VALUE vimageList);
    static void SetIndent(VALUE self,VALUE vindent);
    static void SetSpacing(VALUE self,VALUE vindent);
    static void SetItemBackgroundColour(VALUE self,VALUE vitem,VALUE vcol);
    static void SetItemBold(int argc, VALUE *argv, VALUE self);
    static void SetItemData(VALUE self,VALUE vitem,VALUE vdata);
    static void SetItemFont(VALUE self,VALUE vitem,VALUE vfont);
    static void SetItemHasChildren(int argc, VALUE *argv, VALUE self);
    static void SetItemSelectedImage(VALUE self,VALUE vitem,VALUE vselImage);
    static void SetItemImage(int argc, VALUE *argv, VALUE self);
    static void SetItemText(VALUE self,VALUE vitem,VALUE vtext);
    static void SetItemTextColour(VALUE self,VALUE vitem,VALUE vcol);
    static void SetStateImageList(VALUE self,VALUE vimageList);
    static void SortChildren(VALUE self,VALUE vitem);
    static void Toggle(VALUE self,VALUE vitem);
    static void Unselect(VALUE self);
    static void UnselectAll(VALUE self);
    static VALUE OnCompareItems(VALUE self,VALUE vi1,VALUE vi2);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
