/**********************************************************************

  textctrl.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS TextCtrl : Control
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  wxTextCtrl(wxWindow* parent, wxWindowID id, const wxString& value = "", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
  
  void AppendText(const wxString& text);
  virtual bool CanCopy();
  virtual bool CanCut();
  virtual bool CanPaste();
  virtual bool CanRedo();
  virtual bool CanUndo();
  virtual void Clear();
  virtual void Copy();
#  bool Create(wxWindow* parent, wxWindowID id, const wxString& value = "", const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
  virtual void Cut();
  void DiscardEdits();
  bool EmulateKeyPress(const wxKeyEvent& event);
#  const wxTextAttr&  GetDefaultStyle();
  virtual long GetInsertionPoint();
  virtual long GetLastPosition();
  int GetLineLength(long lineNo);
  wxString GetLineText(long lineNo);
  int GetNumberOfLines();
  virtual wxString GetRange(long from, long to);
#  virtual void GetSelection(long* from, long* to);
  virtual wxString GetStringSelection();
  wxString GetValue();
  bool IsEditable();
  bool IsModified();
  bool IsMultiLine();
  bool IsSingleLine();
  bool LoadFile(const wxString& filename);
  void OnDropFiles(wxDropFilesEvent& event);
  virtual void Paste();
#  bool PositionToXY(long pos, long * x, long * y);
  virtual void Redo();
  virtual void Remove(long from, long to);
  virtual void Replace(long from, long to, const wxString& value);
  bool SaveFile(const wxString& filename);
  bool SetDefaultStyle(const wxTextAttr& style);
  virtual void SetEditable(const bool editable);
  virtual void SetInsertionPoint(long pos);
  virtual void SetInsertionPointEnd();
  virtual void SetMaxLength(unsigned long len);
  virtual void SetSelection(long from, long to);
  bool SetStyle(long start, long end, const wxTextAttr& style);
  virtual void SetValue(const wxString& value);
  void ShowPosition(long pos);
  virtual void Undo();
  void WriteText(const wxString& text);
  long XYToPosition(long x, long y);
#  wxTextCtrl& operator \cinsert(const wxString& s);
#  wxTextCtrl& operator \cinsert(int i);
#  wxTextCtrl& operator \cinsert(long i);
#  wxTextCtrl& operator \cinsert(float f);
#  wxTextCtrl& operator \cinsert(double d);
#  wxTextCtrl& operator \cinsert(char c);
//$$ METHODS_END




//$$ BEGIN_H_FILE
class WxTextCtrl
{
public:
	//$$ RB_DECLARE

    static VALUE op_append(VALUE self,VALUE value);
	static VALUE PositionToXY(VALUE self, VALUE pos);
};
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "point.h"
#include "size.h"
#include "textattr.h"
#include "window.h"

void WxTextCtrl::DefineClass()
{
	//$$ RB_DEFINE
	
	rb_define_method(rubyClass, "<<", VALUEFUNC(op_append), 1);
	rb_define_method(rubyClass, "position_to_xy", VALUEFUNC(PositionToXY), 1);
}

//$$ RB_IMPLEMENT

VALUE WxTextCtrl::op_append(VALUE self,VALUE value)
{
    wxTextCtrl *ptr;
    Data_Get_Struct(self, wxTextCtrl, ptr);
    if(TYPE(value)==T_STRING)
      *ptr << StringValuePtr(value);
    else if(TYPE(value)==T_FIXNUM)
      *ptr << NUM2INT(value);
    else if(TYPE(value)==T_FLOAT)
      *ptr << (double)(RFLOAT(value)->value);
    return self;
}

VALUE WxTextCtrl::PositionToXY(VALUE self, VALUE rubyPos)
{
    wxTextCtrl *ptr;
    Data_Get_Struct(self, wxTextCtrl, ptr);
	long pos = NUM2LONG(rubyPos);
	long x = 0;
	long y = 0;
	ptr->PositionToXY(pos, &x, &y);
	return WxPoint::init0(wxPoint(x, y));
}


//$$ END_CPP_FILE
