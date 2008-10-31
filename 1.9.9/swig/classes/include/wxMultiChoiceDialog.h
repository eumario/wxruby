// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxMultiChoiceDialog_h_)
#define _wxMultiChoiceDialog_h_

#define wxCHOICEDLG_STYLE \
    (wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCANCEL | wxCENTRE)

class wxMultiChoiceDialog : public wxDialog
{
public:
  wxMultiChoiceDialog();

  wxMultiChoiceDialog(wxWindow *parent,
					  const wxString& message,
					  const wxString& caption,
					  int n,
					  const wxString *choices,
					  long style = wxCHOICEDLG_STYLE,
					  const wxPoint& pos = wxDefaultPosition);
  wxMultiChoiceDialog(wxWindow *parent,
					  const wxString& message,
					  const wxString& caption,
					  const wxArrayString& choices,
					  long style = wxCHOICEDLG_STYLE,
					  const wxPoint& pos = wxDefaultPosition);
  bool Create(wxWindow *parent,
			  const wxString& message,
			  const wxString& caption,
			  int n,
			  const wxString *choices,
			  long style = wxCHOICEDLG_STYLE,
			  const wxPoint& pos = wxDefaultPosition);
  bool Create(wxWindow *parent,
			  const wxString& message,
			  const wxString& caption,
			  const wxArrayString& choices,
			  long style = wxCHOICEDLG_STYLE,
			  const wxPoint& pos = wxDefaultPosition);
  
  void SetSelections(const wxArrayInt& selections);
  wxArrayInt GetSelections();

protected:
    wxArrayInt m_selections;
};

#endif
