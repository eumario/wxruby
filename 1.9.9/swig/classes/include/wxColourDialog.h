// wxColourDialog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourDialog_h_)
#define _wxColourDialog_h_
class wxColourDialog : public wxDialog
{
public:
	/**
	 * \brief Constructor. Pass a parent window, and optionally a pointer to a block of colour
data, which will be copied to the colour dialog's colour data. 
	 * \param wxWindow*   
	 * \param wxColourData*   
	*/

   wxColourDialog(wxWindow*  parent , wxColourData*  data = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxColourDialog() ;
	/**
	 * \brief Same as  . 
	 * \param wxWindow*   
	 * \param wxColourData*   
	*/

  bool Create(wxWindow*  parent , wxColourData*  data = NULL) ;
	/**
	 * \brief Returns the   associated with the colour dialog. 
	*/

  wxColourData& GetColourData() ;
	/**
	 * \brief Shows the dialog, returning wxID_OK if the user pressed OK, and wxOK_CANCEL
otherwise. 
	*/

  int ShowModal() ;
};


#endif
