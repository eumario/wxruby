// wxSingleChoiceDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSingleChoiceDialog_h_)
#define _wxSingleChoiceDialog_h_

#define wxCHOICEDLG_STYLE \
    (wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER | wxOK | wxCANCEL | wxCENTRE)

class wxSingleChoiceDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor, taking an array of wxString choices and optional client data. 
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param int   
	 * \param const wxString*   
	 * \param void**  
	 * \param long   
	 * \param const wxPoint&   
	*/

  wxSingleChoiceDialog(wxWindow*  parent , const wxString&  message , const wxString&  caption , const wxArrayString& choices , char** clientData = NULL, long  style = wxCHOICEDLG_STYLE, const wxPoint&  pos = wxDefaultPosition);
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxSingleChoiceDialog() ;
	/**
	 * \brief Returns the index of selected item. 
	*/

  int GetSelection() const;
	/**
	 * \brief Returns the client data associated with the selection. 
	*/

  char* GetSelectionClientData() const;
	/**
	 * \brief Returns the selected string. 
	*/

  wxString GetStringSelection() const;
	/**
	 * \brief Sets the index of the initially selected item. 
	 * \param int  
	*/

  void SetSelection(int  selection ) ;
	/**
	 * \brief Shows the dialog, returning either wxID_OK or wxID_CANCEL. 
	*/

  int ShowModal() ;
};


#endif
