/**********************************************************************

  Dynamiccast.cpp

  $Author$
  $Date$

  Copyright (C) 2003  Kevin Smith,NSK

**********************************************************************/



#include "wx.h"

#include"bitmap.h"
#include"brush.h"
#include"button.h"
#include"calendar.h"
#include"caret.h"
#include"classinfo.h"
#include"colour.h"
#include"colourdata.h"
#include"config.h"
#include"cursor.h"
#include"date.h"
#include"dc.h"
#include"dialog.h"
#include"event.h"
#include"evthandler.h"
#include"font.h"
#include"fontdata.h"
#include"frame.h"
#include"icon.h"
#include"image.h"
#include"layout.h"
#include"list.h"
#include"listbox.h"
#include"listctrl.h"
#include"log.h"
#include"mask.h"
#include"menubar.h"
#include"notebook.h"
#include"ownerdrawn.h"
#include"palette.h"
#include"panel.h"
#include"pen.h"
#include"point.h"
#include"radio.h"
#include"rect.h"
#include"region.h"
#include"size.h"
#include"sizer.h"
#include"socket.h"
#include"statusbar.h"
#include"stream.h"
#include"textattr.h"
#include"textctrl.h"
#include"toolbar.h"
#include"tooltip.h"
#include"treectrl.h"
#include"validator.h"
#include"window.h"


#include "dynamiccast.h"

wxHashTable WxRbTypeTable::table(wxKEY_STRING);


void WxRbTypeTable::AddTypeConverter(WxTypeConverter *tc)
{
	table.Put(tc->GetName(),tc);
}

VALUE WxRbTypeTable::ConvertCppObject(wxObject *obj)
{
	wxString className;
	
	//
	// First lets find this guys name
	//
	className = obj->GetClassInfo()->GetClassName();

	//
	// Pull its converter out of a hat
	//
	WxTypeConverter *conv =(WxTypeConverter *) table.Get(className);

	if (conv == NULL)
		return Qnil;

	else return conv->ToValue(obj);
}

void WxRbTypeTable::Init()
{
	WXRB_ADD_TYPE_CONV(WxBitmap,"wxBitmap");
	WXRB_ADD_TYPE_CONV(WxBrush,"wxBrush");
	WXRB_ADD_TYPE_CONV(WxButton,"wxButton");
	WXRB_ADD_TYPE_CONV(WxCalendarCtrl,"wxCalendarCtrl");
	WXRB_ADD_TYPE_CONV(WxColour,"wxColour");
	WXRB_ADD_TYPE_CONV(WxColourData,"wxColourData");
	WXRB_ADD_TYPE_CONV(WxCursor,"wxCursor");
	WXRB_ADD_TYPE_CONV(WxDC,"wxDC");
	WXRB_ADD_TYPE_CONV(WxDialog,"wxDialog");
	WXRB_ADD_TYPE_CONV(WxEvent,"wxEvent");
	WXRB_ADD_TYPE_CONV(WxEvtHandler,"wxEvtHandler");
	WXRB_ADD_TYPE_CONV(WxFont,"wxFont");
	WXRB_ADD_TYPE_CONV(WxFontData,"wxFontData");
	WXRB_ADD_TYPE_CONV(WxFrame,"wxFrame");
	WXRB_ADD_TYPE_CONV(WxIcon,"wxIcon");
	WXRB_ADD_TYPE_CONV(WxImage,"wxImage");
	WXRB_ADD_TYPE_CONV(WxIndividualLayoutConstraint,"wxIndividualLayoutConstraint");
	WXRB_ADD_TYPE_CONV(WxLayoutConstraints,"wxLayoutConstraints");
	WXRB_ADD_TYPE_CONV(WxList,"wxList");
	WXRB_ADD_TYPE_CONV(WxMask,"wxMask");
	WXRB_ADD_TYPE_CONV(WxMenuBar,"wxMenuBar");
	WXRB_ADD_TYPE_CONV(WxNotebook,"wxNotebook");
	WXRB_ADD_TYPE_CONV(WxPalette,"wxPalette");
	WXRB_ADD_TYPE_CONV(WxPanel,"wxPanel");
	WXRB_ADD_TYPE_CONV(WxPen,"wxPen");
	WXRB_ADD_TYPE_CONV(WxRegion,"wxRegion");
	WXRB_ADD_TYPE_CONV(WxSizer,"wxSizer");
	WXRB_ADD_TYPE_CONV(WxStatusBar,"wxStatusBar");
	WXRB_ADD_TYPE_CONV(WxTextCtrl,"wxTextCtrl");
	WXRB_ADD_TYPE_CONV(WxToolBar,"wxToolBar");
	WXRB_ADD_TYPE_CONV(WxToolTip,"wxToolTip");
	WXRB_ADD_TYPE_CONV(WxValidator,"wxValidator");
	WXRB_ADD_TYPE_CONV(WxWindow,"wxWindow");
	WXRB_ADD_TYPE_CONV(WxListCtrl,"wxListCtrl");
	WXRB_ADD_TYPE_CONV(WxListBox,"wxListBox");
	WXRB_ADD_TYPE_CONV(WxTreeCtrl,"wxTreeCtrl");
	WXRB_ADD_TYPE_CONV(WxCalendarCtrl,"wxCalendarCtrl");
	WXRB_ADD_TYPE_CONV(WxRadioBox,"wxRadioBox");
	WXRB_ADD_TYPE_CONV(WxRadioButton,"wxRadioButton");
}
