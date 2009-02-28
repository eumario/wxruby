// wxSystemSettings.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSystemSettings_h_)
#define _wxSystemSettings_h_
class wxSystemSettings : public wxObject
{
public:
	/**
	 * \brief Default constructor. You don't need to create an instance of wxSystemSettings
since all of its functions are static. 
	*/

   wxSystemSettings() ;
	/**
	 * \brief Returns a system colour.

  can be one of:

\twocolwidtha{7cm}
 

\pythonnote{This static method is implemented in Python as a
standalone function named  } 
	 * \param wxSystemColour  
	*/

  static wxColour GetColour(wxSystemColour  index ) ;
	/**
	 * \brief Returns a system font.

  can be one of:

\twocolwidtha{7cm}
 

\pythonnote{This static method is implemented in Python as a
standalone function named  } 
	 * \param wxSystemFont  
	*/

  static wxFont GetFont(wxSystemFont  index ) ;
	/**
	 * \brief Returns a system metric.

  can be one of:

\twocolwidtha{7cm}
 

\pythonnote{This static method is implemented in Python as a
standalone function named  } 
	 * \param wxSystemMetric  
	*/

  static int GetMetric(wxSystemMetric  index ) ;
};


#endif
