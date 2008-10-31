// wxFontData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontData_h_)
#define _wxFontData_h_
class wxFontData : public wxObject
{
public:
	/**
	 * \brief Constructor. Initializes   to black,   to black,
  to true,   to true,
  to 0 and   to 0. 
	*/

   wxFontData() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFontData() ;
	/**
	 * \brief Enables or disables `effects' under MS Windows only. This refers to the
controls for manipulating colour, strikeout and underline properties.

The default value is true. 
	 * \param bool  
	*/

  void EnableEffects(bool  enable ) ;
	/**
	 * \brief Under MS Windows, returns a flag determining whether symbol fonts can be selected. Has no
effect on other platforms.

The default value is true. 
	*/

  bool GetAllowSymbols() ;
	/**
	 * \brief Gets the colour associated with the font dialog.

The default value is black. 
	*/

  const wxColour& GetColour() ;
	/**
	 * \brief Gets the font chosen by the user. If the user pressed OK (wxFontDialog::Show returned true), this returns
a new font which is now `owned' by the application, and should be deleted
if not required. If the user pressed Cancel (wxFontDialog::Show returned false) or
the colour dialog has not been invoked yet, this will return NULL. 
	*/

  wxFont GetChosenFont() ;
	/**
	 * \brief Determines whether `effects' are enabled under Windows. This refers to the
controls for manipulating colour, strikeout and underline properties.

The default value is true. 
	*/

  bool GetEnableEffects() ;
	/**
	 * \brief Gets the font that will be initially used by the font dialog. This should have
previously been set by the application. 
	*/

  wxFont GetInitialFont() ;
	/**
	 * \brief Returns true if the Help button will be shown (Windows only).

The default value is false. 
	*/

  bool GetShowHelp() ;
	/**
	 * \brief Under MS Windows, determines whether symbol fonts can be selected. Has no
effect on other platforms.

The default value is true. 
	 * \param bool  
	*/

  void SetAllowSymbols(bool  allowSymbols ) ;
	/**
	 * \brief Sets the font that will be returned to the user (for internal use only). 
	 * \param const wxFont&   
	*/

  void SetChosenFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the colour that will be used for the font foreground colour.

The default colour is black. 
	 * \param const wxColour&  
	*/

  void SetColour(const wxColour&  colour ) ;
	/**
	 * \brief Sets the font that will be initially used by the font dialog. 
	 * \param const wxFont&  
	*/

  void SetInitialFont(const wxFont& font ) ;
	/**
	 * \brief Sets the valid range for the font point size (Windows only).

The default is 0, 0 (unrestricted range). 
	 * \param int  
	 * \param int  
	*/

  void SetRange(int  min , int  max ) ;
	/**
	 * \brief Determines whether the Help button will be displayed in the font dialog (Windows only).

The default value is false. 
	 * \param bool  
	*/

  void SetShowHelp(bool  showHelp ) ;
};


#endif
