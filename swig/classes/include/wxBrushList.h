// wxBrushList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBrushList_h_)
#define _wxBrushList_h_
class wxBrushList : public wxList
{
public:
	/**
	 * \brief Constructor. The application should not construct its own brush list:
use the object pointer  . 
	*/

   wxBrushList() ;
	/**
	 * \brief Used internally by wxWindows to add a brush to the list. 
	 * \param wxBrush *  
	*/

  void AddBrush(wxBrush * brush ) ;
	/**
	 * \brief Finds a brush with the specified attributes and returns it, else creates a new brush, adds it
to the brush list, and returns it. 
	 * \param const wxColour&   
	 * \param int  
	*/

  wxBrush * FindOrCreateBrush(const wxColour&  colour , int  style ) ;
	/**
	 * \brief Finds a brush with the specified attributes and returns it, else creates a new brush, adds it
to the brush list, and returns it.

Finds a brush of the given specification, or creates one and adds it to the list. 
	 * \param const wxString&   
	 * \param int  
	*/

  wxBrush * FindOrCreateBrush(const wxString&  colourName , int  style ) ;
	/**
	 * \brief Used by wxWindows to remove a brush from the list. 
	 * \param wxBrush *  
	*/

  void RemoveBrush(wxBrush * brush ) ;
};


#endif
