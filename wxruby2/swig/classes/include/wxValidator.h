// wxValidator.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxValidator_h_)
#define _wxValidator_h_
class wxValidator : public wxEvtHandler
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxValidator() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxValidator() ;
	/**
	 * \brief All validator classes must implement the   function, which returns
an identical copy of itself. This is because validators are passed to control
constructors as references which must be copied. Unlike objects such as pens
and brushes, it does not make sense to have a reference counting scheme
to do this cloning, because all validators should have separate
data.

This base function returns NULL. 
	*/

  virtual wxObject* Clone() const;
	/**
	 * \brief Returns the window associated with the validator. 
	*/

  wxWindow* GetWindow() const;
	/**
	 * \brief This functions switches on or turns off the error sound produced by the
validators if an invalid key is pressed. 
	 * \param bool  
	*/

  void SetBellOnError(bool doIt = true) ;
	/**
	 * \brief Associates a window with the validator. 
	 * \param wxWindow*  
	*/

  void SetWindow(wxWindow*  window ) ;
	/**
	 * \brief This overridable function is called when the value in the window must be
transferred to the validator. Return false if there is a problem. 
	*/

  virtual bool TransferFromWindow() ;
	/**
	 * \brief This overridable function is called when the value associated with the validator must be
transferred to the window. Return false if there is a problem. 
	*/

  virtual bool TransferToWindow() ;
	/**
	 * \brief This overridable function is called when the value in the associated window must be validated.
Return false if the value in the window is not valid; you may pop up an error dialog. 
	 * \param wxWindow*  
	*/

  virtual bool Validate(wxWindow*  parent ) ;
};


#endif
