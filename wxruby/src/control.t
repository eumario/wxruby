/**********************************************************************

  control.t -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

//$$ CLASS Control : Window

//$$ METHODS_BEGIN
  wxControl(wxWindow* parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& val = wxDefaultValidator, const wxString& name = wxControlNameStr)
  
  void Command(wxCommandEvent& event);
  wxString& GetLabel();
  void SetLabel(const wxString& label);

//$$ METHODS_END



//$$ BEGIN_H_FILE
//$$ RB_DECLARE_CLASS
//$$ END_H_FILE


//$$ BEGIN_CPP_FILE
//$$ RB_IMPLEMENT_CLASS
//$$ END_CPP_FILE
