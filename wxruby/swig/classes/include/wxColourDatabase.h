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

   void AddColour(const wxString& colourName, const wxColour& colour) ;

    wxColour Find(const wxString& name) const;
    wxString FindName(const wxColour& colour) const;

    // add a new colour to the database
    void AddColour(const wxString& name, const wxColour& colour);

  void Initialize() ;
};


#endif
