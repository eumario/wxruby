/**********************************************************************

  caret.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Caret
//$$ NEEDS_WRAPPING_CONSTRUCTOR
//$$ NO_CLIENT_DATA

//$$ METHODS_BEGIN
  wxCaret(wxWindowBase* window, const wxSize& size);

#(1)  bool Create(wxWindowBase* window, int width, int height);
#(1)  bool Create(wxWindowBase* window, const wxSize& size);
  static int GetBlinkTime();
#(2)  void GetPosition(int* x, int* y);
  wxPoint GetPosition();
#(2)  void GetSize(int* width, int* height);
  wxSize GetSize();
  wxWindow* GetWindow();
  void Hide();
  bool IsOk();
  bool IsVisible();
  void Move(int x, int y); -> MoveXY
  void Move(const wxPoint& pt);
  static void SetBlinkTime(int milliseconds);
  void SetSize(int width, int height); -> SetSizeXY
  void SetSize(const wxSize& size);
  void Show(bool show = TRUE);
//$$ METHODS_END

//(1) Not needed because we don't support the empty constructor
#(1)  bool Create(wxWindowBase* window, int width, int height);
#(1)  bool Create(wxWindowBase* window, const wxSize& size);

//(2) Redundant and a poor interface
#(2)  void GetPosition(int* x, int* y);
#(2)  void GetSize(int* width, int* height);



//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "wx/caret.h"
#include "point.h"
#include "size.h"
#include "window.h"

//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
