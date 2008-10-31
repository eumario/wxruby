// wxGenericValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGenericValidator_h_)
#define _wxGenericValidator_h_
class wxGenericValidator : public wxValidator
{
public:
	/**
	 * \brief Copy constructor. 
	 * \param const wxGenericValidator&  
	*/

   wxGenericValidator(const wxGenericValidator&  validator ) ;
	/**
	 * \brief Constructor taking a bool pointer. This will be used for wxCheckBox and wxRadioButton. 
	 * \param bool*  
	*/

   wxGenericValidator(bool*  valPtr ) ;
	/**
	 * \brief Constructor taking a wxString pointer. This will be used for wxButton, wxComboBox, wxStaticText,
wxTextCtrl. 
	 * \param wxString*  
	*/

   wxGenericValidator(wxString*  valPtr ) ;
	/**
	 * \brief Constructor taking an integer pointer. This will be used for wxGauge, wxScrollBar, wxRadioBox, wxSpinButton,
wxChoice. 
	 * \param int*  
	*/

   wxGenericValidator(int*  valPtr ) ;
	/**
	 * \brief Constructor taking a wxArrayInt pointer. This will be used for wxListBox, wxCheckListBox. 
	 * \param wxArrayInt*  
	*/

   wxGenericValidator(wxArrayInt*  valPtr ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxGenericValidator() ;
	/**
	 * \brief Clones the generic validator using the copy constructor. 
	*/

  virtual wxValidator* Clone() const;
	/**
	 * \brief Transfers the value from the window to the appropriate data type. 
	*/

  virtual bool TransferFromWindow() ;
	/**
	 * \brief Transfers the value to the window. 
	*/

  virtual bool TransferToWindow() ;
};


#endif
