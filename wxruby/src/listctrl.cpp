/**********************************************************************

  listctrl.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "listctrl.h"
#include "textctrl.h"
#include "list.h"
#include "point.h"
#include "rect.h"
#include "colour.h"
#include "font.h"
#include "window.h"

void WxListCtrl::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ListCtrl", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxListCtrl::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxListCtrl::init), -1);
	rb_define_method(rubyClass, "arrange", VALUEFUNC(WxListCtrl::Arrange), -1);
	rb_define_method(rubyClass, "assign_image_list", VALUEFUNC(WxListCtrl::AssignImageList), 2);
	rb_define_method(rubyClass, "clear_all", VALUEFUNC(WxListCtrl::ClearAll), 0);
	rb_define_method(rubyClass, "delete_all_items", VALUEFUNC(WxListCtrl::DeleteAllItems), 0);
	rb_define_method(rubyClass, "delete_column", VALUEFUNC(WxListCtrl::DeleteColumn), 1);
	rb_define_method(rubyClass, "delete_item", VALUEFUNC(WxListCtrl::DeleteItem), 1);
	rb_define_method(rubyClass, "edit_label", VALUEFUNC(WxListCtrl::EditLabel), 1);
	rb_define_method(rubyClass, "ensure_visible", VALUEFUNC(WxListCtrl::EnsureVisible), 1);
	rb_define_method(rubyClass, "find_item", VALUEFUNC(WxListCtrl::FindItem), -1);
	rb_define_method(rubyClass, "get_column", VALUEFUNC(WxListCtrl::GetColumn), 2);
	rb_define_method(rubyClass, "get_column_count", VALUEFUNC(WxListCtrl::GetColumnCount), 0);
	rb_define_method(rubyClass, "get_column_width", VALUEFUNC(WxListCtrl::GetColumnWidth), 1);
	rb_define_method(rubyClass, "get_count_per_page", VALUEFUNC(WxListCtrl::GetCountPerPage), 0);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "get_edit_control", VALUEFUNC(WxListCtrl::GetEditControl), 0);
#endif
	rb_define_method(rubyClass, "get_image_list", VALUEFUNC(WxListCtrl::GetImageList), 1);
	rb_define_method(rubyClass, "get_item_count", VALUEFUNC(WxListCtrl::GetItemCount), 0);
	rb_define_method(rubyClass, "get_item", VALUEFUNC(WxListCtrl::GetItem), -1);
	rb_define_method(rubyClass, "get_item_data", VALUEFUNC(WxListCtrl::GetItemData), 1);
	rb_define_method(rubyClass, "get_item_position", VALUEFUNC(WxListCtrl::GetItemPosition), 1);
	rb_define_method(rubyClass, "get_item_rect", VALUEFUNC(WxListCtrl::GetItemRect), -1);
	rb_define_method(rubyClass, "get_item_spacing", VALUEFUNC(WxListCtrl::GetItemSpacing), 1);
	rb_define_method(rubyClass, "get_item_state", VALUEFUNC(WxListCtrl::GetItemState), 2);
	rb_define_method(rubyClass, "get_item_text", VALUEFUNC(WxListCtrl::GetItemText), -1);
	rb_define_method(rubyClass, "get_selected_item_count", VALUEFUNC(WxListCtrl::GetSelectedItemCount), 0);
	rb_define_method(rubyClass, "get_text_colour", VALUEFUNC(WxListCtrl::GetTextColour), 0);
	rb_define_method(rubyClass, "get_top_item", VALUEFUNC(WxListCtrl::GetTopItem), 0);
	rb_define_method(rubyClass, "hit_test", VALUEFUNC(WxListCtrl::HitTest), 1);
	rb_define_method(rubyClass, "insert_column", VALUEFUNC(WxListCtrl::InsertColumn), -1);
	rb_define_method(rubyClass, "insert_item", VALUEFUNC(WxListCtrl::InsertItem), -1);
	rb_define_method(rubyClass, "scroll_list", VALUEFUNC(WxListCtrl::ScrollList), 2);
	rb_define_method(rubyClass, "set_background_colour", VALUEFUNC(WxListCtrl::SetBackgroundColour), 1);
	rb_define_method(rubyClass, "set_column", VALUEFUNC(WxListCtrl::SetColumn), 2);
	rb_define_method(rubyClass, "set_column_width", VALUEFUNC(WxListCtrl::SetColumnWidth), 2);
	rb_define_method(rubyClass, "set_image_list", VALUEFUNC(WxListCtrl::SetImageList), 2);
	rb_define_method(rubyClass, "set_item", VALUEFUNC(WxListCtrl::SetItem), -1);
	rb_define_method(rubyClass, "set_item_count", VALUEFUNC(WxListCtrl::SetItemCount), 1);
	rb_define_method(rubyClass, "set_item_data", VALUEFUNC(WxListCtrl::SetItemData), 2);
	rb_define_method(rubyClass, "set_item_image", VALUEFUNC(WxListCtrl::SetItemImage), 3);
	rb_define_method(rubyClass, "set_item_position", VALUEFUNC(WxListCtrl::SetItemPosition), 2);
	rb_define_method(rubyClass, "set_item_state", VALUEFUNC(WxListCtrl::SetItemState), 3);
	rb_define_method(rubyClass, "set_item_text", VALUEFUNC(WxListCtrl::SetItemText), 2);
	rb_define_method(rubyClass, "set_single_style", VALUEFUNC(WxListCtrl::SetSingleStyle), -1);
	rb_define_method(rubyClass, "set_text_colour", VALUEFUNC(WxListCtrl::SetTextColour), 1);
	rb_define_method(rubyClass, "set_window_style_flag", VALUEFUNC(WxListCtrl::SetWindowStyleFlag), 1);
	rb_define_method(rubyClass, "get_next_item", VALUEFUNC(WxListCtrl::GetNextItem), -1);
	rb_define_method(rubyClass, "sort_items", VALUEFUNC(WxListCtrl::SortItems), 2);
	rb_define_method(rubyClass, "is_virtual", VALUEFUNC(WxListCtrl::IsVirtual), 0);
	rb_define_method(rubyClass, "refresh_item", VALUEFUNC(WxListCtrl::RefreshItem), 1);
	rb_define_method(rubyClass, "refresh_items", VALUEFUNC(WxListCtrl::RefreshItems), 2);
}

VALUE
WxListCtrl::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxListCtrl::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxLC_ICON;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "listCtrl";

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

    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr = new wxRbListCtrl(parent,id,pos,size,style);
    ptr->m_self = self;

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxListCtrl::Arrange(int argc, VALUE *argv, VALUE self)
{
    int flag = wxLIST_ALIGN_DEFAULT;
    if(argc==1) flag = NUM2INT(argv[0]);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->Arrange(flag) ? Qtrue : Qfalse);

}

void
WxListCtrl::AssignImageList(VALUE self,VALUE vimageList,VALUE vwhich)
{
    wxImageList* imageList;
    Data_Get_Struct(vimageList, wxImageList, imageList);
    int which = NUM2INT(vwhich);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->AssignImageList(imageList,which);
}

void
WxListCtrl::ClearAll(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->ClearAll();
}

VALUE
WxListCtrl::DeleteAllItems(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->DeleteAllItems() ? Qtrue : Qfalse);

}

VALUE
WxListCtrl::DeleteColumn(VALUE self,VALUE vcol)
{
    int col = NUM2INT(vcol);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->DeleteColumn(col) ? Qtrue : Qfalse);

}

VALUE
WxListCtrl::DeleteItem(VALUE self,VALUE vitem)
{
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->DeleteItem(item) ? Qtrue : Qfalse);

}

void
WxListCtrl::EditLabel(VALUE self,VALUE vitem)
{
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->EditLabel(item);

}

VALUE
WxListCtrl::EnsureVisible(VALUE self,VALUE vitem)
{
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->EnsureVisible(item) ? Qtrue : Qfalse);

}

VALUE
WxListCtrl::FindItem(int argc, VALUE *argv, VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    long start = NUM2INT(argv[0]);
    if(TYPE(argv[1])==T_STRING) {
      wxString str = StringValuePtr(argv[1]);
      bool partial = FALSE;
      if(argc>2 && argv[2]==Qtrue) partial = TRUE;
      return INT2NUM(ptr->FindItem(start,str,partial));
    } else if(TYPE(argv[1])==T_FIXNUM) {
      long data = NUM2INT(argv[1]);
      return INT2NUM(ptr->FindItem(start,data));
    } else {
      wxPoint *pt;
      Data_Get_Struct(argv[1], wxPoint, pt);
      int direction = NUM2INT(argv[2]);
      return INT2NUM(ptr->FindItem(start,*pt,direction));
    }
}

VALUE
WxListCtrl::GetColumn(VALUE self,VALUE vcol,VALUE vitem)
{
    int col = NUM2INT(vcol);
    wxListItem *item;
    Data_Get_Struct(vitem, wxListItem, item);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->GetColumn(col,*item) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::GetColumnCount(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetColumnCount());
}

VALUE
WxListCtrl::GetColumnWidth(VALUE self,VALUE vcol)
{
    int col = NUM2INT(vcol);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetColumnWidth(col));
}

VALUE
WxListCtrl::GetCountPerPage(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetCountPerPage());
}

#ifdef __WXMSW__
VALUE
WxListCtrl::GetEditControl(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return WxTextCtrl::init0(ptr->GetEditControl());
}
#endif

VALUE
WxListCtrl::GetImageList(VALUE self,VALUE vwhich)
{
    int which = NUM2INT(vwhich);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return WxImageList::init0(ptr->GetImageList(which));
}


VALUE
WxListCtrl::GetItem(int argc, VALUE *argv, VALUE self)
{
    VALUE listItem = rb_funcall(WxListItem::rubyClass, rb_intern("new"), 0);
    VALUE id = Qnil;
    VALUE col = Qnil;
    rb_scan_args(argc, argv, "11", &id, &col);
    WxListItem::SetId(listItem, id);
    if(argc > 1)
        WxListItem::SetColumn(listItem, col);

    wxListItem *info;
    Data_Get_Struct(listItem, wxListItem, info);
    info->m_mask = 0xFFFF;  // we want all info to be valid
    
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    if(!ptr->GetItem(*info))
        return Qnil;
    
    return listItem;
}

VALUE
WxListCtrl::GetItemCount(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetItemCount());
}

VALUE
WxListCtrl::GetItemData(VALUE self,VALUE vitem)
{
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetItemData(item));
}

VALUE
WxListCtrl::GetItemPosition(VALUE self,VALUE vitem)
{
    wxPoint pos;
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->GetItemPosition(item,pos);
    return WxPoint::init0(pos);
}

VALUE
WxListCtrl::GetItemRect(int argc, VALUE *argv, VALUE self)
{
    wxRect rect;
    long item = NUM2INT(argv[0]);
    int code = wxLIST_RECT_BOUNDS;
    if(argc==2) code = NUM2INT(argv[1]);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->GetItemRect(item,rect,code);
    return WxRect::init0(rect);
}

VALUE
WxListCtrl::GetItemSpacing(VALUE self,VALUE visSmall)
{
    bool isSmall = (visSmall==Qtrue);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetItemSpacing(isSmall));

}

VALUE
WxListCtrl::GetItemState(VALUE self,VALUE vitem,VALUE vstateMask)
{
    long item = NUM2INT(vitem);
    long stateMask = NUM2INT(vstateMask);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetItemState(item,stateMask));

}

VALUE
WxListCtrl::GetItemText(int argc, VALUE *argv, VALUE self)
{
    long item = NUM2INT(argv[0]);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return rb_str_new2(ptr->GetItemText(item));
}

VALUE
WxListCtrl::GetSelectedItemCount(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetSelectedItemCount());
}

VALUE
WxListCtrl::GetTextColour(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return WxColour::init0(ptr->GetTextColour());
}

VALUE
WxListCtrl::GetTopItem(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetTopItem());
}

VALUE
WxListCtrl::HitTest(VALUE self,VALUE vpoint)
{
    wxPoint *point;
    Data_Get_Struct(vpoint, wxPoint, point);
    int flags;
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    long result = ptr->HitTest(*point,flags);
    return rb_ary_new3(2,INT2NUM(result),INT2NUM(flags));
}

VALUE
WxListCtrl::InsertColumn(int argc, VALUE *argv, VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    long col = NUM2INT(argv[0]);
    if(TYPE(argv[1])==T_STRING) {
      wxString heading = StringValuePtr(argv[1]);
      int format = wxLIST_FORMAT_LEFT;
      if(argc>2) format = NUM2INT(argv[2]);
      int width = -1;
      if(argc>3) width = NUM2INT(argv[3]);
      return INT2NUM(ptr->InsertColumn(col,heading,format,width));
    } else {
      wxListItem *info;
      Data_Get_Struct(argv[1], wxListItem, info);
      return INT2NUM(ptr->InsertColumn(col,*info));
    }
}

VALUE
WxListCtrl::InsertItem(int argc, VALUE *argv, VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    if(TYPE(argv[0])==T_FIXNUM) {
      long index = NUM2INT(argv[0]);
      wxString label;
      int imageIndex;
      if(TYPE(argv[1])==T_STRING) {
        label = StringValuePtr(argv[1]);
        if(argc>2) {
          imageIndex = NUM2INT(argv[2]);
          return INT2NUM(ptr->InsertItem(index,label,imageIndex));
        }
        else {
          return INT2NUM(ptr->InsertItem(index,label));
        }
      }
      else {
        imageIndex = NUM2INT(argv[1]);
        return INT2NUM(ptr->InsertItem(index,imageIndex));
      }
    } else {
      wxListItem *info;
      Data_Get_Struct(argv[0], wxListItem, info);
      return INT2NUM(ptr->InsertItem(*info));
    }
}

VALUE
WxListCtrl::ScrollList(VALUE self,VALUE vdx,VALUE vdy)
{
    int dx = NUM2INT(vdx);
    int dy = NUM2INT(vdy);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->ScrollList(dx,dy) ? Qtrue : Qfalse);
}

void
WxListCtrl::SetBackgroundColour(VALUE self,VALUE vcol)
{
    wxColour *col;
    Data_Get_Struct(vcol, wxColour, col);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetBackgroundColour(*col);
}

VALUE
WxListCtrl::SetColumn(VALUE self,VALUE vcol,VALUE vitem)
{
    int col = NUM2INT(vcol);
    wxListItem *item;
    Data_Get_Struct(vitem, wxListItem, item);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetColumn(col,*item) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::SetColumnWidth(VALUE self,VALUE vcol,VALUE vwidth)
{
    int col = NUM2INT(vcol);
    int width = NUM2INT(vwidth);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetColumnWidth(col,width) ? Qtrue : Qfalse);
}

void
WxListCtrl::SetImageList(VALUE self,VALUE vimageList,VALUE vwhich)
{
    wxImageList* imageList;
    int which = NUM2INT(vwhich);
    Data_Get_Struct(vimageList, wxImageList, imageList);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetImageList(imageList,which);
}


VALUE
WxListCtrl::SetItem(int argc, VALUE *argv, VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    if(TYPE(argv[0])==T_DATA) {
    	wxListItem *info;
    	Data_Get_Struct(argv[0], wxListItem, info);
        return (ptr->SetItem(*info) ? Qtrue : Qfalse);
    } else {
    	long index = NUM2INT(argv[0]);
    	int col = NUM2INT(argv[1]);
    	wxString label = StringValuePtr(argv[2]);
    	int imageId = -1;
    	if(argc>3) imageId = NUM2INT(argv[3]);
    	return INT2NUM(ptr->SetItem(index,col,label,imageId));
    }

}

void
WxListCtrl::SetItemCount(VALUE self,VALUE vcount)
{
    long count = NUM2INT(vcount);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetItemCount(count);
}

VALUE
WxListCtrl::SetItemData(VALUE self,VALUE vitem,VALUE vdata)
{
    long item = NUM2INT(vitem);
    long data = (long)vdata;
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetItemData(item,data) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::SetItemImage(VALUE self,VALUE vitem,VALUE vimage,VALUE vselImage)
{
    long item = NUM2INT(vitem);
    int image = NUM2INT(vimage);
    int selImage = NUM2INT(vselImage);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetItemImage(item,image,selImage) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::SetItemPosition(VALUE self,VALUE vitem,VALUE vpos)
{
    long item = NUM2INT(vitem);
    wxPoint *pos;
    Data_Get_Struct(vpos, wxPoint, pos);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetItemPosition(item,*pos) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::SetItemState(VALUE self,VALUE vitem,VALUE vstate,VALUE vstateMask)
{
    long item = NUM2INT(vitem);
    long state = NUM2INT(vstate);
    long stateMask = NUM2INT(vstateMask);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SetItemState(item,state,stateMask) ? Qtrue : Qfalse);
}

void
WxListCtrl::SetItemText(VALUE self,VALUE vitem,VALUE vtext)
{
    long item = NUM2INT(vitem);
    wxString text = StringValuePtr(vtext);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetItemText(item,text);
}

void
WxListCtrl::SetSingleStyle(int argc, VALUE *argv, VALUE self)
{
    long style = NUM2INT(argv[0]);
    bool add = TRUE;
    if(argc>1 && argv[1]==Qfalse) add = FALSE;
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetSingleStyle(style,add);
}

void
WxListCtrl::SetTextColour(VALUE self,VALUE vcol)
{
    wxColour *col;
    Data_Get_Struct(vcol, wxColour, col);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetTextColour(*col);
}

void
WxListCtrl::SetWindowStyleFlag(VALUE self,VALUE vstyle)
{
    long style = NUM2INT(vstyle);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->SetWindowStyleFlag(style);
}

VALUE
WxListCtrl::GetNextItem(int argc, VALUE *argv, VALUE self)
{
    long item = NUM2INT(argv[0]);
    int geometry = wxLIST_NEXT_ALL;
    if(argc>1) geometry = NUM2INT(argv[1]);
    int state = wxLIST_STATE_DONTCARE;
    if(argc>2) state = NUM2INT(argv[2]);

    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return INT2NUM(ptr->GetNextItem(item,geometry,state));
}

static int
wxCALLBACK wxListCompareFunction(long item1, long item2, long sortData)
{
    VALUE data = (VALUE)sortData;
    VALUE self = RARRAY(data)->ptr[0];
    char *func = StringValuePtr(RARRAY(data)->ptr[1]);
    return NUM2INT(rb_funcall(self,rb_intern(func),2,INT2NUM(item1),INT2NUM(item2)));
}

VALUE
WxListCtrl::SortItems(VALUE self,VALUE klass,VALUE vfunc)
{
    //wxListCtrlCompare fnSortCallBack;
    long data = (long)rb_ary_new3(2,klass,vfunc);

    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->SortItems(wxListCompareFunction,data) ? Qtrue : Qfalse);
}

VALUE
WxListCtrl::IsVirtual(VALUE self)
{
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    return (ptr->IsVirtual() ? Qtrue : Qfalse);
}

void
WxListCtrl::RefreshItem(VALUE self,VALUE vitem)
{
    long item = NUM2INT(vitem);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->RefreshItem(item);
}

void
WxListCtrl::RefreshItems(VALUE self,VALUE vitem,VALUE vitemTo)
{
    long item = NUM2INT(vitem);
    long itemTo = NUM2INT(vitemTo);
    wxRbListCtrl *ptr;
    Data_Get_Struct(self, wxRbListCtrl, ptr);
    ptr->RefreshItems(item,itemTo);
}

VALUE WxListCtrl::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxListCtrl::DefineClass();
    }
};
static ZAutoDefine x;

//-----------------------------------------------------------------------------------
wxListItemAttr *
wxRbListCtrl::OnGetItemAttr(long item) const
{
    VALUE self = m_self;
    if(!rb_respond_to(self, rb_intern("on_get_item_attr")))
        return wxListCtrl::OnGetItemAttr(item);

    VALUE vattr = rb_funcall(self,rb_intern("on_get_item_attr"),1,INT2NUM(item));
    if(vattr==Qnil) return (wxListItemAttr *)NULL;
    wxListItemAttr *ptr;
    Data_Get_Struct(vattr, wxListItemAttr, ptr);
    return ptr;
}

int
wxRbListCtrl::OnGetItemImage(long item) const
{
    VALUE self = m_self;
    return NUM2INT(rb_funcall(self,rb_intern("on_get_item_image"),1,INT2NUM(item)));
}

wxString
wxRbListCtrl::OnGetItemText(long item, long column) const
{
    VALUE self = m_self;
    VALUE value = rb_funcall(self,rb_intern("on_get_item_text"),2,INT2NUM(item),INT2NUM(column));
    wxString str = StringValuePtr(value);
    return str;
}

//-------------------------------------------------------------------------------------
void WxListItemAttr::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ListItemAttr", rb_cObject);
	rb_define_alloc_func(rubyClass,WxListItemAttr::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxListItemAttr::init), -1);
	rb_define_method(rubyClass, "get_background_colour", VALUEFUNC(WxListItemAttr::GetBackgroundColour), 0);
	rb_define_method(rubyClass, "get_font", VALUEFUNC(WxListItemAttr::GetFont), 0);
	rb_define_method(rubyClass, "get_text_colour", VALUEFUNC(WxListItemAttr::GetTextColour), 0);
	rb_define_method(rubyClass, "has_background_colour", VALUEFUNC(WxListItemAttr::HasBackgroundColour), 0);
	rb_define_method(rubyClass, "has_font", VALUEFUNC(WxListItemAttr::HasFont), 0);
	rb_define_method(rubyClass, "has_text_colour", VALUEFUNC(WxListItemAttr::HasTextColour), 0);
	rb_define_method(rubyClass, "set_background_colour", VALUEFUNC(WxListItemAttr::SetBackgroundColour), 1);
	rb_define_method(rubyClass, "set_font", VALUEFUNC(WxListItemAttr::SetFont), 1);
	rb_define_method(rubyClass, "set_text_colour", VALUEFUNC(WxListItemAttr::SetTextColour), 1);
}

VALUE
WxListItemAttr::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxListItemAttr::init(int argc, VALUE *argv, VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    if(argc==0) {
        ptr = new wxListItemAttr();
    }
    else {
        wxColour *colText;
        Data_Get_Struct(argv[0], wxColour, colText);
        wxColour *colBack;
        Data_Get_Struct(argv[1], wxColour, colBack);
        wxFont *font;
        Data_Get_Struct(argv[2], wxFont, font);
    	ptr = new wxListItemAttr(*colText,*colBack,*font);
    }
    DATA_PTR(self) = ptr;

    return self;
}

void
WxListItemAttr::SetTextColour(VALUE self,VALUE vcolText)
{
    wxColour *colText;
    Data_Get_Struct(vcolText, wxColour, colText);
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    ptr->SetTextColour(*colText);
}

void
WxListItemAttr::SetBackgroundColour(VALUE self,VALUE vcolBack)
{
    wxColour *colBack;
    Data_Get_Struct(vcolBack, wxColour, colBack);
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    ptr->SetBackgroundColour(*colBack);
}

void
WxListItemAttr::SetFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    ptr->SetFont(*font);
}

VALUE
WxListItemAttr::HasTextColour(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return (ptr->HasTextColour() ? Qtrue : Qfalse);
}

VALUE
WxListItemAttr::HasBackgroundColour(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return (ptr->HasBackgroundColour() ? Qtrue : Qfalse);
}

VALUE
WxListItemAttr::HasFont(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return (ptr->HasFont() ? Qtrue : Qfalse);
}

VALUE
WxListItemAttr::GetTextColour(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return WxColour::init0(ptr->GetTextColour());
}

VALUE
WxListItemAttr::GetBackgroundColour(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return WxColour::init0(ptr->GetBackgroundColour());
}

VALUE
WxListItemAttr::GetFont(VALUE self)
{
    wxListItemAttr *ptr;
    Data_Get_Struct(self, wxListItemAttr, ptr);
    return WxFont::init0(ptr->GetFont());
}

VALUE
WxListItemAttr::init0(wxListItemAttr *list)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    if(list==NULL) return Qnil;
    DATA_PTR(self) = (void*)list;
    return self;
}

VALUE WxListItemAttr::rubyClass;

class ZAutoDefineWxListItemAttr
{
public:
   ZAutoDefineWxListItemAttr()
    {
       WxListItemAttr::DefineClass();
    }
};
static ZAutoDefineWxListItemAttr x3;

//-------------------------------------------------------------------------------------
void WxListItem::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ListItem", rb_cObject);
	rb_define_alloc_func(rubyClass,WxListItem::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxListItem::init), 0);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxListItem::free), 0);
	rb_define_method(rubyClass, "clear", VALUEFUNC(WxListItem::Clear), 0);
	rb_define_method(rubyClass, "get_align", VALUEFUNC(WxListItem::GetAlign), 0);
	rb_define_method(rubyClass, "get_background_colour", VALUEFUNC(WxListItem::GetBackgroundColour), 0);
	rb_define_method(rubyClass, "get_column", VALUEFUNC(WxListItem::GetColumn), 0);
	rb_define_method(rubyClass, "get_data", VALUEFUNC(WxListItem::GetData), 0);
	rb_define_method(rubyClass, "get_font", VALUEFUNC(WxListItem::GetFont), 0);
	rb_define_method(rubyClass, "get_id", VALUEFUNC(WxListItem::GetId), 0);
	rb_define_method(rubyClass, "get_image", VALUEFUNC(WxListItem::GetImage), 0);
	rb_define_method(rubyClass, "get_mask", VALUEFUNC(WxListItem::GetMask), 0);
	rb_define_method(rubyClass, "get_state", VALUEFUNC(WxListItem::GetState), 0);
	rb_define_method(rubyClass, "get_text", VALUEFUNC(WxListItem::GetText), 0);
	rb_define_method(rubyClass, "get_text_colour", VALUEFUNC(WxListItem::GetTextColour), 0);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxListItem::GetWidth), 0);
	rb_define_method(rubyClass, "set_align", VALUEFUNC(WxListItem::SetAlign), 1);
	rb_define_method(rubyClass, "set_background_colour", VALUEFUNC(WxListItem::SetBackgroundColour), 1);
	rb_define_method(rubyClass, "set_column", VALUEFUNC(WxListItem::SetColumn), 1);
	rb_define_method(rubyClass, "set_background_colour", VALUEFUNC(WxListItem::SetBackgroundColour), 1);
	rb_define_method(rubyClass, "set_data", VALUEFUNC(WxListItem::SetData), 1);
	rb_define_method(rubyClass, "set_font", VALUEFUNC(WxListItem::SetFont), 1);
	rb_define_method(rubyClass, "set_id", VALUEFUNC(WxListItem::SetId), 1);
	rb_define_method(rubyClass, "set_image", VALUEFUNC(WxListItem::SetImage), 1);
	rb_define_method(rubyClass, "set_mask", VALUEFUNC(WxListItem::SetMask), 1);
	rb_define_method(rubyClass, "set_state", VALUEFUNC(WxListItem::SetState), 1);
	rb_define_method(rubyClass, "set_state_mask", VALUEFUNC(WxListItem::SetStateMask), 1);
	rb_define_method(rubyClass, "set_text", VALUEFUNC(WxListItem::SetText), 1);
	rb_define_method(rubyClass, "set_text_colour", VALUEFUNC(WxListItem::SetTextColour), 1);
	rb_define_method(rubyClass, "set_width", VALUEFUNC(WxListItem::SetWidth), 1);
	rb_define_method(rubyClass, "get_attributes", VALUEFUNC(WxListItem::GetAttributes), 0);
}

VALUE
WxListItem::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxListItem::init(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr = new wxListItem();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxListItem::init0(wxListItem *list)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)list;
    return self;
}

void
WxListItem::Clear(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->Clear();
}

VALUE
WxListItem::GetAlign(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetAlign());
}

VALUE
WxListItem::GetBackgroundColour(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return WxColour::init0(ptr->GetBackgroundColour());
}

VALUE
WxListItem::GetColumn(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetColumn());
}

VALUE
WxListItem::GetData(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetData());
}

VALUE
WxListItem::GetFont(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return WxFont::init0(ptr->GetFont());
}

VALUE
WxListItem::GetId(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetId());
}

VALUE
WxListItem::GetImage(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetImage());
}

VALUE
WxListItem::GetMask(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetMask());
}

VALUE
WxListItem::GetState(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetState());
}

VALUE
WxListItem::GetText(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return rb_str_new2(ptr->GetText());
}

VALUE
WxListItem::GetTextColour(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return WxColour::init0(ptr->GetTextColour());
}

VALUE
WxListItem::GetWidth(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return INT2NUM(ptr->GetWidth());
}

void
WxListItem::SetAlign(VALUE self,VALUE valign)
{
    wxListColumnFormat align = (wxListColumnFormat)NUM2INT(valign);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetAlign(align);
}

void
WxListItem::SetBackgroundColour(VALUE self,VALUE vcolBack)
{
    wxColour *colBack;
    Data_Get_Struct(vcolBack, wxColour, colBack);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetBackgroundColour(*colBack);
}

void
WxListItem::SetColumn(VALUE self,VALUE vcol)
{
    int col = NUM2INT(vcol);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetColumn(col);
}

void
WxListItem::SetData(VALUE self,VALUE vdata)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    if(TYPE(vdata)==T_FIXNUM) {
        long data = NUM2INT(vdata);
        ptr->SetData(data);
    } else {
        void* data = (void*)(vdata);
        ptr->SetData(data);
    }
}

void
WxListItem::SetFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetFont(*font);
}

void
WxListItem::SetId(VALUE self,VALUE vid)
{
    long id = NUM2INT(vid);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetId(id);
}

void
WxListItem::SetImage(VALUE self,VALUE vimage)
{
    int image = NUM2INT(vimage);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetImage(image);
}

void
WxListItem::SetMask(VALUE self,VALUE vmask)
{
    long mask = NUM2INT(vmask);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetMask(mask);
}

void
WxListItem::SetState(VALUE self,VALUE vstate)
{
    long state = NUM2INT(vstate);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetState(state);
}

void
WxListItem::SetStateMask(VALUE self,VALUE vstateMask)
{
    long stateMask = NUM2INT(vstateMask);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetStateMask(stateMask);
}

void
WxListItem::SetText(VALUE self,VALUE vtext)
{
    wxString text = StringValuePtr(vtext);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetText(text);
}

void
WxListItem::SetTextColour(VALUE self,VALUE vcolText)
{
    wxColour *colText;
    Data_Get_Struct(vcolText, wxColour, colText);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetTextColour(*colText);
}

void
WxListItem::SetWidth(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    ptr->SetWidth(width);
}

VALUE
WxListItem::GetAttributes(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    return WxListItemAttr::init0(ptr->GetAttributes());
}

void
WxListItem::free(VALUE self)
{
    wxListItem *ptr;
    Data_Get_Struct(self, wxListItem, ptr);
    delete ptr;
}

VALUE WxListItem::rubyClass;

class ZAutoDefineWxListItem
{
public:
   ZAutoDefineWxListItem()
    {
       WxListItem::DefineClass();
    }
};
static ZAutoDefineWxListItem x4;
