/**********************************************************************

  button.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Button : Control
//$$ NEEDS_WRAPPING_CONSTRUCTOR

//$$ METHODS_BEGIN
  wxButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = ``button");

#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = ``button");
  wxString GetLabel();
  wxSize GetDefaultSize();
  void SetDefault();
  void SetLabel(const wxString& label);
//$$ METHODS_END

//(1) not needed because we don't support the empty constructor
#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = ``button");




//$$ CLASS BitmapButton : Button

//$$ METHODS_BEGIN
  wxBitmapButton(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxBU_AUTODRAW, const wxValidator& validator = wxDefaultValidator, const wxString& name = ``button");

#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& = wxDefaultValidatorvalidator, const wxString& name = ``button");
  wxBitmap& GetBitmapDisabled();
  wxBitmap& GetBitmapFocus();
  wxBitmap& GetBitmapLabel();
  wxBitmap& GetBitmapSelected();
  void SetBitmapDisabled(const wxBitmap& bitmap);
  void SetBitmapFocus(const wxBitmap& bitmap);
  void SetBitmapLabel(const wxBitmap& bitmap);
  void SetBitmapSelected(const wxBitmap& bitmap);
//$$ METHODS_END

//(1) not needed because we don't support the empty constructor
#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxBitmap& bitmap, const wxPoint& pos, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = = wxDefaultValidator, const wxString& name = ``button");


#################################################################################
//$$ BEGIN_H_FILE

//$$ RB_DECLARE_CLASS WxButton
//$$ RB_DECLARE_CLASS WxBitmapButton

//$$ END_H_FILE

#################################################################################

//$$ BEGIN_CPP_FILE
#include "size.h"
#include "bitmap.h"
#include "window.h"


//*****************************************************************
//$$ RB_IMPLEMENT_CLASS WxButton


//*****************************************************************
//$$ RB_IMPLEMENT_CLASS WxBitmapButton


//$$ END_CPP_FILE
