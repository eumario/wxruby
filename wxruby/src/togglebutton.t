/**********************************************************************

  togglebutton.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS ToggleButton : Button

//$$ METHODS_BEGIN
  wxToggleButton(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val = wxDefaultValidator, const wxString& name = ``checkBox");

#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& = valwxDefaultValidator, const wxString& name = ``checkBox");
  bool GetValue();
  void SetValue(const bool state);
//$$ METHODS_END

//(1) not needed because we don't support the empty constructor
#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val = = wxDefaultValidator, const wxString& name = ``checkBox");


#################################################################################
//$$ BEGIN_H_FILE

#include "wx/tglbtn.h"

#if defined(__WXMSW__) || defined(__WXGTK__)
//$$ RB_DECLARE_CLASS WxToggleButton
#endif

//$$ END_H_FILE

#################################################################################

//$$ BEGIN_CPP_FILE
#if defined(__WXMSW__) || defined(__WXGTK__)
#include "size.h"
#include "window.h"

//$$ RB_IMPLEMENT_CLASS WxToggleButton
#endif

//$$ END_CPP_FILE
