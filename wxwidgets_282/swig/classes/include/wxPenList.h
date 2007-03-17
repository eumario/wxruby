// wxPenList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPenList_h_)
#define _wxPenList_h_
class wxPenList
{
public:
	/**
	 * \brief Constructor. The application should not construct its own pen list:
use the object pointer  . 
	*/

   wxPenList() ;
	/**
	 * \brief Used internally by wxWindows to add a pen to the list. 
	 * \param wxPen*  
	*/

  void AddPen(wxPen*  pen ) ;
	/**
	 * \brief Finds a pen with the specified attributes and returns it, else creates a new pen, adds it
to the pen list, and returns it. 
	 * \param const wxColour&   
	 * \param int  
	 * \param int  
	*/

  wxPen* FindOrCreatePen(const wxColour&  colour , int  width , int  style ) ;
	/**
	 * \brief Finds a pen with the specified attributes and returns it, else creates a new pen, adds it
to the pen list, and returns it. 
	 * \param const wxString&   
	 * \param int  
	 * \param int  
	*/

  wxPen* FindOrCreatePen(const wxString&  colourName , int  width , int  style ) ;
	/**
	 * \brief Used by wxWindows to remove a pen from the list. 
	 * \param wxPen*  
	*/

  void RemovePen(wxPen*  pen ) ;
};


#endif
