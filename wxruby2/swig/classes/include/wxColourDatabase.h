// wxColourDatabase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourDatabase_h_)
#define _wxColourDatabase_h_
class wxColourDatabase : public wxList
{
public:
	/**
	 * \brief Constructs the colour database. 
	*/

   wxColourDatabase() ;
	/**
	 * \brief Finds a colour given the name. Returns NULL if not found. 
	 * \param const wxString&   
	*/

  wxColour* FindColour(const wxString&  colourName ) ;
	/**
	 * \brief Finds a colour name given the colour. Returns NULL if not found. 
	 * \param const wxColour&  
	*/

  wxString FindName(const wxColour&  colour ) const;
	/**
	 * \brief Initializes the database with a number of stock colours.  Called by wxWindows
on start-up. 
	*/

  void Initialize() ;
};


#endif
