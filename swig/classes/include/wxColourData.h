// wxColourData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourData_h_)
#define _wxColourData_h_
class wxColourData : public wxObject
{
public:
	/**
	 * \brief Constructor. Initializes the custom colours to white, the   setting
to black, and the   setting to true. 
	*/

   wxColourData() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxColourData() ;
	/**
	 * \brief Under Windows, determines whether the Windows colour dialog will display the full dialog
with custom colour selection controls. Has no meaning under other platforms.

The default value is true. 
	*/

  bool GetChooseFull() const;
	/**
	 * \brief Gets the current colour associated with the colour dialog.

The default colour is black. 
	*/

  wxColour GetColour() const;
	/**
	 * \brief Gets the  th custom colour associated with the colour dialog.   should
be an integer between 0 and 15.

The default custom colours are all white. 
	 * \param int  
	*/

  wxColour GetCustomColour(int  i );
	/**
	 * \brief Under Windows, tells the Windows colour dialog to display the full dialog
with custom colour selection controls. Under other platforms, has no effect.

The default value is true. 
	 * \param const bool   
	*/

  void SetChooseFull(const bool  flag ) ;
	/**
	 * \brief Sets the default colour for the colour dialog.

The default colour is black. 
	 * \param const wxColour&  
	*/

  void SetColour(const wxColour&  colour ) ;
	/**
	 * \brief Sets the  th custom colour for the colour dialog.   should
be an integer between 0 and 15.

The default custom colours are all white. 
	 * \param int  
	 * \param const wxColour&  
	*/

  void SetCustomColour(int  i , const wxColour&  colour ) ;
};


#endif
