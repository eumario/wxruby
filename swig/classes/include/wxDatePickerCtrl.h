// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDatePickerCtrl_h_)
#define _wxDatePickerCtrl_h_

class wxDatePickerCtrl : public wxControl
{
 public:
  wxDatePickerCtrl();
  wxDatePickerCtrl(wxWindow *parent, 
				   wxWindowID id, 
				   const wxDateTime& dt = wxDefaultDateTime, 
				   const wxPoint& pos = wxDefaultPosition, 
				   const wxSize& size = wxDefaultSize, 
				   long style = wxDP_DEFAULT|wxDP_SHOWCENTURY, 
				   const wxValidator& validator = wxDefaultValidator, 
				   const wxString& name = wxDatePickerCtrlNameStr);

  bool Create(wxWindow *parent,
			  wxWindowID id,
			  const wxDateTime& dt = wxDefaultDateTime,
			  const wxPoint& pos = wxDefaultPosition,
			  const wxSize& size = wxDefaultSize,
			  long style = wxDP_DEFAULT|wxDP_SHOWCENTURY,
			  const wxValidator& validator = wxDefaultValidator,
			  const wxString& name = wxDatePickerCtrlNameStr);
  void SetValue(const wxDateTime& dt);
  wxDateTime GetValue() const;

  void SetRange(const wxDateTime& dt1, const wxDateTime& dt2);
  bool GetRange(wxDateTime *dt1, wxDateTime *dt2) const;
};

#endif
