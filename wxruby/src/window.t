/**********************************************************************

  window.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Window : EvtHandler
//$$ NEEDS_WRAPPING_CONSTRUCTOR

//$$ METHODS_BEGIN
    wxWindow(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxPanelNameStr)

	virtual void AddChild(wxWindow* child);
	virtual void CaptureMouse();
	void Center(int direction);
	void CenterOnParent(int direction);
	void CenterOnScreen(int direction);
	void Centre(int direction = wxBOTH);
	void CentreOnParent(int direction = wxBOTH);
	void CentreOnScreen(int direction = wxBOTH);
	void Clear();
	virtual wxPoint ClientToScreen(const wxPoint& pt);
# (7)	virtual void ClientToScreen(int* x, int* y);
	virtual bool Close(bool force = FALSE);
	wxPoint ConvertDialogToPixels(const wxPoint& pt); -> ConvertDialogPointToPixels
	wxSize ConvertDialogToPixels(const wxSize& sz); -> ConvertDialogSizeToPixels
	wxPoint ConvertPixelsToDialog(const wxPoint& pt); -> ConvertPixelsPointToDialog
	wxSize ConvertPixelsToDialog(const wxSize& sz); -> ConvertPixelsSizeToDialog
	virtual bool Destroy();
	virtual void DestroyChildren();
	void Disable();
# (8)	virtual void DragAcceptFiles(bool accept);
	virtual bool Enable(bool enable = TRUE);
	static wxWindow* FindFocus();
	static wxWindow* FindWindowById(long id, wxWindow* parent = NULL);
	static wxWindow* FindWindowByName(const wxString& name, wxWindow* parent = NULL);
	static wxWindow* FindWindowByLabel(const wxString& label, wxWindow* parent = NULL);
	wxWindow* FindWindow(long id); -> FindWindowById
	wxWindow* FindWindow(const wxString& name); -> FindWindowByName
	virtual void Fit();
	virtual void FitInside();
	virtual void Freeze();
	wxSize GetAdjustedBestSize();
	virtual wxColour GetBackgroundColour();
	virtual wxSize GetBestSize();
	static wxWindow * GetCapture();
	wxCaret * GetCaret();
	virtual int GetCharHeight();
	virtual int GetCharWidth();
# (2)	wxList& GetChildren();
	virtual wxSize GetClientSize();
# (7)	virtual void GetClientSize(int* width, int* height);
	wxLayoutConstraints* GetConstraints();
	const wxSizer * GetContainingSizer();
# (8)	wxDropTarget* GetDropTarget();
	wxEvtHandler* GetEventHandler();
	long GetExtraStyle();
	wxFont& GetFont();
	virtual wxColour GetForegroundColour();
	wxWindow* GetGrandParent();
	void* GetHandle();
	virtual wxString GetHelpText();
	int GetId();
	virtual wxString  GetLabel();
	virtual wxString  GetName();
	virtual wxWindow* GetParent();
	wxPoint GetPosition();
# (7)	virtual void GetPosition(int* x, int* y);
	virtual wxRect GetRect();
	virtual int GetScrollThumb(int orientation);
	virtual int GetScrollPos(int orientation);
	virtual int GetScrollRange(int orientation);
	virtual wxSize GetSize();
# (7)	virtual void GetSize(int* width, int* height);
	wxSizer * GetSizer();
# (1)	virtual void GetTextExtent(const wxString& string, int* x, int* y, int* descent = NULL, int* externalLeading = NULL, const wxFont* font = NULL, bool use16 = FALSE);
	virtual wxString GetTitle();
	virtual wxRegion GetUpdateRegion();
	wxValidator* GetValidator();
	wxSize GetVirtualSize();
# (7)	void GetVirtualSize(int* width, int* height);
	long GetWindowStyleFlag();
	virtual bool HasCapture();
	bool Hide();
	void InitDialog();
	virtual bool IsEnabled();
	bool IsExposed(int x, int y); -> IsExposedXY
	bool IsExposed(int x, int y, int w, int h);
	bool IsExposed(wxPoint &pt); -> IsExposedPoint
	bool IsExposed(wxRect &rect); -> IsExposedRect
	virtual bool IsRetained();
	virtual bool IsShown();
	bool IsTopLevel();
	void Layout();
# (4)	virtual bool LoadFromResource(wxWindow* parent, const wxString& resourceName, const wxResourceTable* resourceTable = NULL);
	void Lower();
	virtual void MakeModal(bool flag);
	void Move(const wxPoint& pt);
	void Move(int x, int y); -> MoveXY
	wxEvtHandler* PopEventHandler(bool deleteHandler = FALSE);
	bool PopupMenu(wxMenu* menu, const wxPoint& pos);
	bool PopupMenu(wxMenu* menu, int x, int y); -> PopupMenuXY
	void PushEventHandler(wxEvtHandler* handler);
	void Raise();
	virtual void Refresh(bool eraseBackground = TRUE, const wxRect* re = NULL);
# (10)	virtual void Refresh(const wxRect& rect);
	virtual void ReleaseMouse();
	virtual void RemoveChild(wxWindow* child);
	bool RemoveEventHandler(wxEvtHandler * handler);
	virtual bool Reparent(wxWindow* newParent);
	virtual wxPoint ScreenToClient(const wxPoint& pt);
# (7)	virtual void ScreenToClient(int* x, int* y);
	virtual bool ScrollLines(int lines);
	virtual bool ScrollPages(int pages);
	virtual void ScrollWindow(int dx, int dy, const wxRect* rect = NULL);
	virtual void SetAcceleratorTable(const wxAcceleratorTable& accel);
	void SetAutoLayout(bool autoLayout);
	virtual void SetBackgroundColour(const wxColour& colour);
	void SetCaret(wxCaret * caret);
	virtual void SetClientSize(const wxSize& size);
	virtual void SetClientSize(int width, int height); -> SetClientSizeWH
	void SetContainingSizer(wxSizer* sizer);
	virtual void SetCursor(const wxCursor& cursor);
	void SetConstraints(wxLayoutConstraints* constraints);
	void SetDropTarget(wxDropTarget* target);
	void SetEventHandler(wxEvtHandler* handler);
	void SetExtraStyle(long exStyle);
	virtual void SetFocus();
	virtual void SetFocusFromKbd();
	void SetFont(const wxFont& font);
	virtual void SetForegroundColour(const wxColour& colour);
	virtual void SetHelpText(const wxString& helpText);
	void SetId(int id);
	virtual void SetName(const wxString& name);
# (5)	virtual void SetPalette(wxPalette* palette);
	virtual void SetScrollbar(int orientation, int position, int thumbSize, int range, bool refresh = TRUE);
	virtual void SetScrollPos(int orientation, int pos, bool refresh = TRUE);
# (3)	virtual void SetScrollPage(int orientation, int pageSize, bool refresh = TRUE);
# (3)	virtual void SetScrollRange(int orientation, int range, bool refresh = TRUE);
	virtual void SetSize(int x, int y, int width, int height, int sizeFlags = wxSIZE_AUTO); -> SetDimensions
	virtual void SetSize(const wxRect& rect); -> SetSizeRect
	virtual void SetSize(int width, int height); -> SetSizeXY
	virtual void SetSize(const wxSize& size); -> SetSize
	virtual void SetSizeHints(int minW, int minH, int maxW=-1, int maxH=-1, int incW=-1, int incH=-1);  // MODIFIED!
	void SetSizer(wxSizer* sizer, bool deleteOld=TRUE);
	void SetSizerAndFit(wxSizer* sizer, bool deleteOld=TRUE);
	virtual void SetTitle(const wxString& title);
	virtual void SetThemeEnabled(bool enable);
	void SetToolTip(const wxString& tip); -> SetToolTipString
	void SetToolTip(wxToolTip* tip);
	virtual void SetValidator(const wxValidator& validator);
	wxToolTip* GetToolTip();
	void SetVirtualSize(const wxSize& size);
	void SetVirtualSize(int width, int height); -> SetVirtualSizeWH
	virtual void SetVirtualSizeHints(int minW, int minH, int maxW=-1, int maxH=-1);
	void SetWindowStyle(long style);
	virtual void SetWindowStyleFlag(long style);
	virtual bool Show(bool show = TRUE);
	virtual void Thaw();
	virtual bool TransferDataFromWindow();
	virtual bool TransferDataToWindow();
	virtual void Update();
	virtual bool Validate();
	void WarpPointer(int x, int y);
//$$ METHODS_END

// 1. according to wx/window.h, the final bool parameter does not exist
// (also, Python binds it quite differently anyway)
# (1)	virtual void GetTextExtent(const wxString& string, int* x, int* y, int* descent = NULL, int* externalLeading = NULL, const wxFont* font = NULL, bool use16 = FALSE);

// 2. Defined as returning a wxWindowList, which is a weird template/typedef
// somehow related to wxList. Probably should return an array instead??
// Probably needs to be coded by hand.
# (2)	wxList& GetChildren();

// 3. according to the online wx 2.4 and 2.5 help, these do not exist
# (3)	virtual void SetScrollPage(int orientation, int pageSize, bool refresh = TRUE);
# (3)	virtual void SetScrollRange(int orientation, int range, bool refresh = TRUE);

// 4. this is in the 2.4 help, but according to wx/window.h, this method does not exist, 
// the 2.5 docs do not list it
# (4)	virtual bool LoadFromResource(wxWindow* parent, const wxString& resourceName, const wxResourceTable* resourceTable = NULL);

// 5. according to wx/window.h, palette is passed as reference, not pointer,
// the 2.4 docs have it as shown here, but the 2.5 docs say it is obsolete anyway
# (5)	virtual void SetPalette(wxPalette* palette);

// 7. Redundant overload, not critical to implement
# (7)	virtual void ScreenToClient(int* x, int* y);
# (7)	void GetVirtualSize(int* width, int* height);
# (7)	virtual void GetSize(int* width, int* height);
# (7)	virtual void GetPosition(int* x, int* y);
# (7)	virtual void GetClientSize(int* width, int* height);
# (7)	virtual void ClientToScreen(int* x, int* y);

// 8. MSW only
# (8)	virtual void DragAcceptFiles(bool accept);
# (8)	wxDropTarget* GetDropTarget();

// 10. Not in the online docs, seems redundant
# (10)	virtual void Refresh(const wxRect& rect);

//$$ BEGIN_H_FILE
class WxWindow {
public:
    //$$ RB_DECLARE

    static void free(VALUE self);

	// actually belongs in WxObject
    static VALUE GetClassInfo(VALUE self);

	// msw only
#ifdef __WXMSW__
    static void DragAcceptFiles(VALUE self,VALUE vaccept);
    static VALUE GetHWND(VALUE self);
#endif

};

//$$ END_H_FILE

//$$ BEGIN_CPP_FILE
#include "colour.h"
#include "font.h"
#include "size.h"
#include "rect.h"
#include "sizer.h"
#include "caret.h"
#include "window.h"
#include "point.h"
#include "layout.h"
#include "region.h"
#include "validator.h"
#include "cursor.h"
#include "tooltip.h"
#include "classinfo.h"

void WxWindow::DefineClass()
{
    //$$ RB_DEFINE

	rb_define_method(rubyClass,"free",VALUEFUNC(WxWindow::free),0);

	// belongs in WxObject
    rb_define_method(rubyClass,"GetClassInfo",VALUEFUNC(WxWindow::GetClassInfo),0);

	// MSW only
#ifdef __WXMSW__
    rb_define_method(rubyClass,"drag_accept_files",VALUEFUNC(WxWindow::DragAcceptFiles),1);
    rb_define_method(rubyClass,"get_hwnd",VALUEFUNC(WxWindow::GetHWND),0);
#endif
}

//$$ RB_IMPLEMENT

void
WxWindow::free(VALUE self)
{
    wxWindow *ptr;
    Data_Get_Struct(self, wxWindow, ptr);
    delete ptr;
}


// actually belongs in WxObject
VALUE
WxWindow::GetClassInfo(VALUE self)
{
    wxWindow *ptr;
    Data_Get_Struct(self, wxWindow, ptr);
    return WxClassInfo::init0(ptr->GetClassInfo());
}

#ifdef __WXMSW__
void
WxWindow::DragAcceptFiles(VALUE self,VALUE vaccept)
{
    bool accept = (vaccept == Qtrue);
    wxWindow *ptr;
    Data_Get_Struct(self, wxWindow, ptr);
    ptr->DragAcceptFiles(accept);
}

VALUE
WxWindow::GetHWND(VALUE self)
{
    wxWindow *ptr;
    Data_Get_Struct(self, wxWindow, ptr);
    return INT2NUM(ptr->GetHWND());
}
#endif
//$$ END_CPP_FILE
