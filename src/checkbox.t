/**********************************************************************

  checkbox.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS CheckBox : Control

//$$ METHODS_BEGIN
  wxCheckBox(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val = wxDefaultValidator, const wxString& name = ``checkBox"); //MODIFIED!

#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val, const wxString& name = ``checkBox");
  bool GetValue();
  bool IsChecked();
  void SetValue(const bool state);
//$$ METHODS_END

//(1) Not needed because we don't support the empty constructor
#(1)  bool Create(wxWindow* parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val = wxDefaultValidator, const wxString& name = ``checkBox"); //MODIFIED!


//$$ CLASS CheckListBox : ListBox

//$$ METHODS_BEGIN
  wxCheckListBox(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, const wxString choices[] = NULL, long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = ``listBox"); //MODIFIED!
  
  void Check(int item, bool check = TRUE);
  bool IsChecked(int item);
//$$ METHODS_END




//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS WxCheckBox
//$$ RB_DECLARE_CLASS WxCheckListBox
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
#include "listbox.h"

//##############################################################################
//$$ RB_IMPLEMENT_CLASS WxCheckBox


//##############################################################################
//$$ RB_IMPLEMENT_CLASS WxCheckListBox

//$$ END_CPP_FILE
