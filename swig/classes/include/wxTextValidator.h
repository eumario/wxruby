// wxTextValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextValidator_h_)
#define _wxTextValidator_h_
class wxTextValidator : public wxValidator
{
public:
	/**
	 * \brief Copy constructor. 
	 * \param const wxTextValidator&  
	*/

   wxTextValidator(const wxTextValidator&  validator ) ;
	/**
	 * \brief Constructor, taking a style and optional pointer to a wxString variable. 
	 * \param long  
	 * \param wxString*   
	*/

   wxTextValidator(long style = wxFILTER_NONE, wxString*  valPtr = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxTextValidator() ;
	/**
	 * \brief Clones the text validator using the copy constructor. 
	*/

  virtual wxValidator* Clone() const;
	/**
	 * \brief Returns a reference to the exclude list (the list of invalid values). 
	*/

  wxStringList& GetExcludeList() const;
	/**
	 * \brief Returns a reference to the include list (the list of valid values). 
	*/

  wxStringList& GetIncludeList() const;
	/**
	 * \brief Returns the validator style. 
	*/

  long GetStyle() const;
	/**
	 * \brief Receives character input from the window and filters it according to the
current validator style. 
	 * \param wxKeyEvent&  
	*/

  virtual void OnChar(wxKeyEvent&  event ) ;
	/**
	 * \brief Sets the exclude list (invalid values for the user input). 
	 * \param const wxStringList&  
	*/

  void SetExcludeList(const wxStringList&  stringList ) ;
	/**
	 * \brief Sets the include list (valid values for the user input). 
	 * \param const wxStringList&  
	*/

  void SetIncludeList(const wxStringList&  stringList ) ;
	/**
	 * \brief Sets the validator style. 
	 * \param long  
	*/

  void SetStyle(long  style ) ;
	/**
	 * \brief Transfers the string value to the window. 
	*/

  virtual bool TransferFromWindow() ;
	/**
	 * \brief Transfers the window value to the string. 
	*/

  virtual bool TransferToWindow() ;
	/**
	 * \brief Validates the window contents against the include or exclude lists, depending
on the validator style. 
	 * \param wxWindow*  
	*/

  virtual bool Validate(wxWindow*  parent ) ;
};


#endif
