/**********************************************************************

  treectrl.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "treectrl.h"
#include "textctrl.h"
#include "point.h"
#include "rect.h"
#include "colour.h"
#include "font.h"
#include "list.h"
#include "window.h"

#if USE_GENERIC_TREECTRL
IMPLEMENT_DYNAMIC_CLASS(wxRbTreeCtrl, wxGenericTreeCtrl)
#else
IMPLEMENT_DYNAMIC_CLASS(wxRbTreeCtrl, wxTreeCtrl)
#endif

int wxRbTreeCtrl::OnCompareItems(const wxTreeItemId& i1, const wxTreeItemId& i2)
{
    VALUE self = m_self;
    VALUE value = rb_funcall(self,rb_intern("on_compare_items"),2,INT2NUM(i1.m_pItem),INT2NUM(i2.m_pItem));
    return NUM2INT(value);
}


//-----------------------------------------------------------------------------------------------
void WxTreeItemData::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"TreeItemData", rb_cObject);
	rb_define_alloc_func(rubyClass,WxTreeItemData::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxTreeItemData::init), 0);
	rb_define_method(rubyClass, "get_id", VALUEFUNC(WxTreeItemData::GetId), 0);
	rb_define_method(rubyClass, "set_id", VALUEFUNC(WxTreeItemData::SetId), 1);
}

VALUE
WxTreeItemData::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxTreeItemData::init(VALUE self)
{
    wxRbTreeItemData *ptr;
    Data_Get_Struct(self, wxRbTreeItemData, ptr);
    ptr = new wxRbTreeItemData();
    DATA_PTR(self) = ptr;

    ptr->m_self = self;

    return self;
}

VALUE
WxTreeItemData::init0(wxRbTreeItemData *data)
{
    return data->m_self;
}

VALUE
WxTreeItemData::GetId(VALUE self)
{
    wxRbTreeItemData *ptr;
    Data_Get_Struct(self, wxRbTreeItemData, ptr);
    return INT2NUM(ptr->GetId().m_pItem);
}

void
WxTreeItemData::SetId(VALUE self,VALUE vid)
{
    wxTreeItemId id = wxTreeItemId(NUM2INT(vid));
    wxRbTreeItemData *ptr;
    Data_Get_Struct(self, wxRbTreeItemData, ptr);
    ptr->SetId(id);
}

VALUE WxTreeItemData::rubyClass;


class ZAutoDefineWxTreeItemData
{
public:
   ZAutoDefineWxTreeItemData()
    {
       WxTreeItemData::DefineClass();
    }
};
static ZAutoDefineWxTreeItemData x;

//----------------------------------------------------------------------------------
void WxTreeCtrl::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"TreeCtrl", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxTreeCtrl::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxTreeCtrl::init), -1);
	rb_define_method(rubyClass, "add_root", VALUEFUNC(WxTreeCtrl::AddRoot),-1);
	rb_define_method(rubyClass, "append_item", VALUEFUNC(WxTreeCtrl::AppendItem),-1);
//    rb_define_method(rubyClass, "assign_buttons_image_list", VALUEFUNC(WxTreeCtrl::AssignButtonsImageList),1);
	rb_define_method(rubyClass, "assign_image_list", VALUEFUNC(WxTreeCtrl::AssignImageList),1);
	rb_define_method(rubyClass, "assign_state_image_list", VALUEFUNC(WxTreeCtrl::AssignStateImageList),1);
	rb_define_method(rubyClass, "collapse", VALUEFUNC(WxTreeCtrl::Collapse),1);
	rb_define_method(rubyClass, "collapse_and_reset", VALUEFUNC(WxTreeCtrl::CollapseAndReset),1);
	rb_define_method(rubyClass, "delete", VALUEFUNC(WxTreeCtrl::Delete),1);
	rb_define_method(rubyClass, "delete_all_items", VALUEFUNC(WxTreeCtrl::DeleteAllItems),0);
	rb_define_method(rubyClass, "delete_children", VALUEFUNC(WxTreeCtrl::DeleteChildren),1);
	rb_define_method(rubyClass, "edit_label", VALUEFUNC(WxTreeCtrl::EditLabel),1);
	rb_define_method(rubyClass, "ensure_visible", VALUEFUNC(WxTreeCtrl::EnsureVisible),1);
	rb_define_method(rubyClass, "expand", VALUEFUNC(WxTreeCtrl::Expand),1);
	rb_define_method(rubyClass, "get_bounding_rect", VALUEFUNC(WxTreeCtrl::GetBoundingRect),-1);
//    rb_define_method(rubyClass, "get_buttons_image_list", VALUEFUNC(WxTreeCtrl::GetButtonsImageList),0);
	rb_define_method(rubyClass, "get_children_count", VALUEFUNC(WxTreeCtrl::GetChildrenCount),-1);
	rb_define_method(rubyClass, "get_count", VALUEFUNC(WxTreeCtrl::GetCount),0);
	rb_define_method(rubyClass, "get_edit_control", VALUEFUNC(WxTreeCtrl::GetEditControl),0);
	rb_define_method(rubyClass, "get_first_child", VALUEFUNC(WxTreeCtrl::GetFirstChild),1);
	rb_define_method(rubyClass, "get_first_visible_item", VALUEFUNC(WxTreeCtrl::GetFirstVisibleItem),0);
	rb_define_method(rubyClass, "get_image_list", VALUEFUNC(WxTreeCtrl::GetImageList),0);
	rb_define_method(rubyClass, "get_indent", VALUEFUNC(WxTreeCtrl::GetIndent),0);
	rb_define_method(rubyClass, "get_spacing", VALUEFUNC(WxTreeCtrl::GetSpacing),0);
	rb_define_method(rubyClass, "get_item_background_colour", VALUEFUNC(WxTreeCtrl::GetItemBackgroundColour),1);
	rb_define_method(rubyClass, "get_item_data", VALUEFUNC(WxTreeCtrl::GetItemData),1);
	rb_define_method(rubyClass, "get_item_font", VALUEFUNC(WxTreeCtrl::GetItemFont),1);
	rb_define_method(rubyClass, "get_item_image", VALUEFUNC(WxTreeCtrl::GetItemImage),-1);
	rb_define_method(rubyClass, "get_item_parent", VALUEFUNC(WxTreeCtrl::GetItemParent),1);
	rb_define_method(rubyClass, "get_item_selected_image", VALUEFUNC(WxTreeCtrl::GetItemSelectedImage),1);
	rb_define_method(rubyClass, "get_item_text", VALUEFUNC(WxTreeCtrl::GetItemText),1);
	rb_define_method(rubyClass, "get_item_text_colour", VALUEFUNC(WxTreeCtrl::GetItemTextColour),1);
	rb_define_method(rubyClass, "get_last_child", VALUEFUNC(WxTreeCtrl::GetLastChild),1);
	rb_define_method(rubyClass, "get_next_child", VALUEFUNC(WxTreeCtrl::GetNextChild),2);
	rb_define_method(rubyClass, "get_next_sibling", VALUEFUNC(WxTreeCtrl::GetNextSibling),1);
	rb_define_method(rubyClass, "get_next_visible", VALUEFUNC(WxTreeCtrl::GetNextVisible),1);
	rb_define_method(rubyClass, "get_prev_sibling", VALUEFUNC(WxTreeCtrl::GetPrevSibling),1);
	rb_define_method(rubyClass, "get_prev_visible", VALUEFUNC(WxTreeCtrl::GetPrevVisible),1);
	rb_define_method(rubyClass, "get_root_item", VALUEFUNC(WxTreeCtrl::GetRootItem),0);
	rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxTreeCtrl::GetSelection),0);
	rb_define_method(rubyClass, "get_selections", VALUEFUNC(WxTreeCtrl::GetSelections),0);
	rb_define_method(rubyClass, "get_state_image_list", VALUEFUNC(WxTreeCtrl::GetStateImageList),0);
	rb_define_method(rubyClass, "hit_test", VALUEFUNC(WxTreeCtrl::HitTest),1);
	rb_define_method(rubyClass, "insert_item", VALUEFUNC(WxTreeCtrl::InsertItem),-1);
	rb_define_method(rubyClass, "insert_item_before", VALUEFUNC(WxTreeCtrl::InsertItemBefore),-1);
	rb_define_method(rubyClass, "is_bold", VALUEFUNC(WxTreeCtrl::IsBold),1);
	rb_define_method(rubyClass, "is_expanded", VALUEFUNC(WxTreeCtrl::IsExpanded),1);
	rb_define_method(rubyClass, "is_selected", VALUEFUNC(WxTreeCtrl::IsSelected),1);
	rb_define_method(rubyClass, "is_visible", VALUEFUNC(WxTreeCtrl::IsVisible),1);
	rb_define_method(rubyClass, "item_has_children", VALUEFUNC(WxTreeCtrl::ItemHasChildren),1);
	rb_define_method(rubyClass, "prepend_item", VALUEFUNC(WxTreeCtrl::PrependItem),-1);
	rb_define_method(rubyClass, "scroll_to", VALUEFUNC(WxTreeCtrl::ScrollTo),1);
	rb_define_method(rubyClass, "select_item", VALUEFUNC(WxTreeCtrl::SelectItem),1);
//    rb_define_method(rubyClass, "set_buttons_image_list", VALUEFUNC(WxTreeCtrl::SetButtonsImageList),1);
	rb_define_method(rubyClass, "set_image_list", VALUEFUNC(WxTreeCtrl::SetImageList),1);
	rb_define_method(rubyClass, "set_indent", VALUEFUNC(WxTreeCtrl::SetIndent),1);
	rb_define_method(rubyClass, "set_spacing", VALUEFUNC(WxTreeCtrl::SetSpacing),1);
	rb_define_method(rubyClass, "set_item_background_colour", VALUEFUNC(WxTreeCtrl::SetItemBackgroundColour),2);
	rb_define_method(rubyClass, "set_item_image", VALUEFUNC(WxTreeCtrl::SetItemImage),-1);
	rb_define_method(rubyClass, "set_item_bold", VALUEFUNC(WxTreeCtrl::SetItemBold),-1);
	rb_define_method(rubyClass, "set_item_data", VALUEFUNC(WxTreeCtrl::SetItemData),2);
	rb_define_method(rubyClass, "set_item_font", VALUEFUNC(WxTreeCtrl::SetItemFont),2);
	rb_define_method(rubyClass, "set_item_has_children", VALUEFUNC(WxTreeCtrl::SetItemHasChildren),-1);
	rb_define_method(rubyClass, "set_item_selected_image", VALUEFUNC(WxTreeCtrl::SetItemSelectedImage),2);
	rb_define_method(rubyClass, "set_item_text", VALUEFUNC(WxTreeCtrl::SetItemText),2);
	rb_define_method(rubyClass, "set_item_text_colour", VALUEFUNC(WxTreeCtrl::SetItemTextColour),2);
	rb_define_method(rubyClass, "set_state_image_list", VALUEFUNC(WxTreeCtrl::SetStateImageList),1);
	rb_define_method(rubyClass, "sort_children", VALUEFUNC(WxTreeCtrl::SortChildren),1);
	rb_define_method(rubyClass, "toggle", VALUEFUNC(WxTreeCtrl::Toggle),1);
	rb_define_method(rubyClass, "unselect", VALUEFUNC(WxTreeCtrl::Unselect),0);
	rb_define_method(rubyClass, "unselect_all", VALUEFUNC(WxTreeCtrl::UnselectAll),0);
	rb_define_method(rubyClass, "on_compare_items", VALUEFUNC(WxTreeCtrl::OnCompareItems),2);
}

VALUE
WxTreeCtrl::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxTreeCtrl::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxTR_DEFAULT_STYLE;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = wxTreeCtrlNameStr;

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	    Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
        id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_DATA) {
        wxPoint *ptr;
	    Data_Get_Struct(argv[2], wxPoint, ptr);
	    pos = *ptr;
    }
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxSize *ptr;
	    Data_Get_Struct(argv[3], wxSize, ptr);
	    size = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_FIXNUM)
        style = NUM2INT(argv[4]);

    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr = new wxRbTreeCtrl(parent,id,pos,size,style);
    ptr->m_self = self;

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxTreeCtrl::AddRoot(int argc, VALUE *argv, VALUE self)
{
    wxString text = StringValuePtr(argv[0]);
    int image = -1;
    if(argc>1) image = NUM2INT(argv[1]);
    int selImage = -1;
    if(argc>2) selImage = NUM2INT(argv[2]);
    wxRbTreeItemData* data = NULL;
    if(argc>3 && TYPE(argv[3])==T_DATA)
        Data_Get_Struct(argv[3], wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->AddRoot(text,image,selImage,data));
}

VALUE
WxTreeCtrl::AppendItem(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId parent = wxTreeItemId(NUM2INT(argv[0]));
    wxString text = StringValuePtr(argv[1]);
    int image = -1;
    if(argc>2) image = NUM2INT(argv[2]);
    int selImage = -1;
    if(argc>3) selImage = NUM2INT(argv[3]);
    wxRbTreeItemData* data = NULL;
    if(argc>4 && TYPE(argv[4])==T_DATA)
        Data_Get_Struct(argv[4], wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->AppendItem(parent,text,image,selImage,data));
}

/*
void
WxTreeCtrl::AssignButtonsImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->AssignButtonsImageList(imageList);
}
*/

void
WxTreeCtrl::AssignImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->AssignImageList(imageList);
}

void
WxTreeCtrl::AssignStateImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->AssignStateImageList(imageList);
}

void
WxTreeCtrl::Collapse(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->Collapse(item);
}

void
WxTreeCtrl::CollapseAndReset(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->CollapseAndReset(item);
}

void
WxTreeCtrl::Delete(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->Delete(item);
}

void
WxTreeCtrl::DeleteAllItems(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->DeleteAllItems();
}

void
WxTreeCtrl::DeleteChildren(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->DeleteChildren(item);
}

void
WxTreeCtrl::EditLabel(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->EditLabel(item);
}

void
WxTreeCtrl::EnsureVisible(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->EnsureVisible(item);
}

void
WxTreeCtrl::Expand(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->Expand(item);
}

VALUE
WxTreeCtrl::GetBoundingRect(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    wxRect *rect;
    Data_Get_Struct(argv[1], wxRect, rect);
    bool textOnly = FALSE;
    if(argc>2 && argv[2]==Qtrue) textOnly = TRUE;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->GetBoundingRect(item,*rect,textOnly) ? Qtrue : Qfalse);
}

/*
VALUE
WxTreeCtrl::GetButtonsImageList(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxImageList::init0(ptr->GetButtonsImageList());
}
*/

VALUE
WxTreeCtrl::GetChildrenCount(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    bool recursively = TRUE;
    if(argc>1 && argv[1]==Qfalse) recursively = FALSE;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetChildrenCount(item,recursively));
}

VALUE
WxTreeCtrl::GetCount(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetCount());
}

VALUE
WxTreeCtrl::GetEditControl(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxTextCtrl::init0(ptr->GetEditControl());
}

VALUE
WxTreeCtrl::GetFirstChild(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    long cookie;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    wxTreeItemId r= ptr->GetFirstChild(item,cookie);
    return rb_ary_new3(2,INT2NUM(r.m_pItem),INT2NUM(cookie));
}

VALUE
WxTreeCtrl::GetFirstVisibleItem(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetFirstVisibleItem());
}

VALUE
WxTreeCtrl::GetImageList(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxImageList::init0(ptr->GetImageList());
}

VALUE
WxTreeCtrl::GetIndent(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetIndent());
}

VALUE
WxTreeCtrl::GetSpacing(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetSpacing());
}

VALUE
WxTreeCtrl::GetItemBackgroundColour(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxColour::init0(ptr->GetItemBackgroundColour(item));
}

VALUE
WxTreeCtrl::GetItemData(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxTreeItemData::init0((wxRbTreeItemData*)ptr->GetItemData(item));
}

VALUE
WxTreeCtrl::GetItemFont(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxFont::init0(ptr->GetItemFont(item));
}

VALUE
WxTreeCtrl::GetItemImage(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    wxTreeItemIcon which = wxTreeItemIcon_Normal;
    if(argc>1) which = (wxTreeItemIcon)NUM2INT(argv[1]);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetItemImage(item,which));
}

VALUE
WxTreeCtrl::GetItemText(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return rb_str_new2(ptr->GetItemText(item));
}

VALUE
WxTreeCtrl::GetItemTextColour(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxColour::init0(ptr->GetItemTextColour(item));
}

VALUE
WxTreeCtrl::GetLastChild(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetLastChild(item));
}

VALUE
WxTreeCtrl::GetNextChild(VALUE self,VALUE vitem,VALUE vcookie)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    long cookie = NUM2INT(vcookie);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    wxTreeItemId r= ptr->GetNextChild(item,cookie);
    return rb_ary_new3(2,INT2NUM(r.m_pItem),INT2NUM(cookie));
}

VALUE
WxTreeCtrl::GetNextSibling(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetNextSibling(item));
}

VALUE
WxTreeCtrl::GetNextVisible(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetNextVisible(item));
}

VALUE
WxTreeCtrl::GetItemParent(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetItemParent(item));
}

VALUE
WxTreeCtrl::GetPrevSibling(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetPrevSibling(item));
}

VALUE
WxTreeCtrl::GetPrevVisible(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetPrevVisible(item));
}

VALUE
WxTreeCtrl::GetRootItem(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetRootItem());
}

VALUE
WxTreeCtrl::GetItemSelectedImage(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetItemSelectedImage(item));
}

VALUE
WxTreeCtrl::GetSelection(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->GetSelection());
}

VALUE
WxTreeCtrl::GetSelections(VALUE self)
{
    wxArrayTreeItemIds selection;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    size_t r = ptr->GetSelections(selection);
    VALUE ary = rb_ary_new();
    for(size_t i=0;i<r;i++) {
        rb_ary_push(ary,INT2NUM(selection[i].m_pItem));
    }
    return ary;
}

VALUE
WxTreeCtrl::GetStateImageList(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return WxImageList::init0(ptr->GetStateImageList());
}

VALUE
WxTreeCtrl::HitTest(VALUE self,VALUE vpoint)
{
    wxPoint *point;
    Data_Get_Struct(vpoint, wxPoint, point);
    int flags;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    wxTreeItemId r = ptr->HitTest(*point,flags);
    return rb_ary_new3(2,INT2NUM(r.m_pItem),INT2NUM(flags));
}

VALUE
WxTreeCtrl::InsertItem(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId parent = wxTreeItemId(NUM2INT(argv[0]));
    wxTreeItemId previous = wxTreeItemId(NUM2INT(argv[1]));
    wxString text = StringValuePtr(argv[2]);
    int image = -1;
    if(argc>3) image = NUM2INT(argv[3]);
    int selImage = -1;
    if(argc>4) selImage = NUM2INT(argv[4]);
    wxRbTreeItemData* data = NULL;
    if(argc>5 && TYPE(argv[5])==T_DATA)
        Data_Get_Struct(argv[5], wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->InsertItem(parent,previous,text,image,selImage,data));
}

VALUE
WxTreeCtrl::InsertItemBefore(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId parent = wxTreeItemId(NUM2INT(argv[0]));
    size_t before = NUM2INT(argv[1]);
    wxString text = StringValuePtr(argv[2]);
    int image = -1;
    if(argc>3) image = NUM2INT(argv[3]);
    int selImage = -1;
    if(argc>4) selImage = NUM2INT(argv[4]);
    wxRbTreeItemData* data = NULL;
    if(argc>5 && TYPE(argv[5])==T_DATA)
        Data_Get_Struct(argv[5], wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->InsertItem(parent,before,text,image,selImage,data));
}

VALUE
WxTreeCtrl::IsBold(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->IsBold(item) ? Qtrue : Qfalse);
}

VALUE
WxTreeCtrl::IsExpanded(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->IsExpanded(item) ? Qtrue : Qfalse);
}

VALUE
WxTreeCtrl::IsSelected(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->IsSelected(item) ? Qtrue : Qfalse);
}

VALUE
WxTreeCtrl::IsVisible(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->IsVisible(item) ? Qtrue : Qfalse);
}

VALUE
WxTreeCtrl::ItemHasChildren(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return (ptr->ItemHasChildren(item) ? Qtrue : Qfalse);
}

VALUE
WxTreeCtrl::PrependItem(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId parent = wxTreeItemId(NUM2INT(argv[0]));
    wxString text = StringValuePtr(argv[1]);
    int image = -1;
    if(argc>2) image = NUM2INT(argv[2]);
    int selImage = -1;
    if(argc>3) selImage = NUM2INT(argv[3]);
    wxRbTreeItemData* data = NULL;
    if(argc>4 && TYPE(argv[4])==T_DATA)
        Data_Get_Struct(argv[4], wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    return INT2NUM(ptr->PrependItem(parent,text,image,selImage,data));
}

void
WxTreeCtrl::ScrollTo(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->ScrollTo(item);
}

void
WxTreeCtrl::SelectItem(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SelectItem(item);
}

/*
void
WxTreeCtrl::SetButtonsImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetButtonsImageList(imageList);
}
*/

void
WxTreeCtrl::SetIndent(VALUE self,VALUE vindent)
{
    int indent = NUM2INT(vindent);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetIndent(indent);
}

void
WxTreeCtrl::SetSpacing(VALUE self,VALUE vindent)
{
    int indent = NUM2INT(vindent);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetSpacing(indent);
}

void
WxTreeCtrl::SetImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetImageList(imageList);
}

void
WxTreeCtrl::SetItemBackgroundColour(VALUE self,VALUE vitem,VALUE vcol)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxColour *col;
    Data_Get_Struct(vcol, wxColour, col);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemBackgroundColour(item,*col);
}

void
WxTreeCtrl::SetItemBold(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    bool bold = TRUE;
    if(argc>1 && argv[1]==Qfalse) bold = FALSE;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemBold(item,bold);
}

void
WxTreeCtrl::SetItemData(VALUE self,VALUE vitem,VALUE vdata)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeItemData* data;
    Data_Get_Struct(vdata, wxRbTreeItemData, data);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemData(item,data);
}

void
WxTreeCtrl::SetItemFont(VALUE self,VALUE vitem,VALUE vfont)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemFont(item,*font);
}

void
WxTreeCtrl::SetItemHasChildren(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    bool hasChildren = TRUE;
    if(argc>1 && argv[1]==Qfalse) hasChildren = FALSE;
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemHasChildren(item,hasChildren);
}

void
WxTreeCtrl::SetItemImage(int argc, VALUE *argv, VALUE self)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(argv[0]));
    int image = NUM2INT(argv[1]);
    wxTreeItemIcon which = wxTreeItemIcon_Normal;
    if(argc>2) which = (wxTreeItemIcon)NUM2INT(argv[2]);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemImage(item,image,which);
}

void
WxTreeCtrl::SetItemSelectedImage(VALUE self,VALUE vitem,VALUE vselImage)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    int selImage = NUM2INT(vselImage);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemSelectedImage(item,selImage);
}

void
WxTreeCtrl::SetItemText(VALUE self,VALUE vitem,VALUE vtext)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxString text = StringValuePtr(vtext);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemText(item,text);
}

void
WxTreeCtrl::SetItemTextColour(VALUE self,VALUE vitem,VALUE vcol)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxColour *col;
    Data_Get_Struct(vcol, wxColour, col);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetItemTextColour(item,*col);
}

void
WxTreeCtrl::SetStateImageList(VALUE self,VALUE vimageList)
{
    wxImageList* imageList = NULL;
    if(vimageList!=Qnil)
        Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SetStateImageList(imageList);
}

void
WxTreeCtrl::SortChildren(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->SortChildren(item);
}

void
WxTreeCtrl::Toggle(VALUE self,VALUE vitem)
{
    wxTreeItemId item = wxTreeItemId(NUM2INT(vitem));
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->Toggle(item);
}

void
WxTreeCtrl::Unselect(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->Unselect();
}

void
WxTreeCtrl::UnselectAll(VALUE self)
{
    wxRbTreeCtrl *ptr;
    Data_Get_Struct(self, wxRbTreeCtrl, ptr);
    ptr->UnselectAll();
}

VALUE
WxTreeCtrl::OnCompareItems(VALUE self,VALUE vi1,VALUE vi2)
{
    wxTreeItemId i1 = wxTreeItemId(NUM2INT(vi1));
    wxTreeItemId i2 = wxTreeItemId(NUM2INT(vi2));
    wxTreeCtrl *ptr;
    Data_Get_Struct(self, wxTreeCtrl, ptr);
    return INT2NUM(ptr->wxTreeCtrl::OnCompareItems(i1,i2));
}

VALUE WxTreeCtrl::rubyClass;

class ZAutoDefineWxTreeCtrl
{
public:
   ZAutoDefineWxTreeCtrl()
    {
       WxTreeCtrl::DefineClass();
    }
};
static ZAutoDefineWxTreeCtrl x2;
