// wxFontList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontList_h_)
#define _wxFontList_h_
class wxFontList : public wxList
{
public:
	/**
	 * \brief Constructor. The application should not construct its own font list:
use the object pointer  . 
	*/

   wxFontList() ;
	/**
	 * \brief Used by wxWindows to add a font to the list, called in the font constructor. 
	 * \param wxFont *  
	*/

  void AddFont(wxFont * font ) ;
	/**
	 * \brief Finds a font of the given specification, or creates one and adds it to the list. See the   for
details of the arguments. 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param bool  
	 * \param const wxString&   
	 * \param wxFontEncoding   
	*/

  wxFont * FindOrCreateFont(int  point_size , int  family , int  style , int  weight , bool underline = false, const wxString&  facename = NULL, wxFontEncoding  encoding = wxFONTENCODING_DEFAULT) ;
	/**
	 * \brief Used by wxWindows to remove a font from the list. 
	 * \param wxFont *  
	*/

  void RemoveFont(wxFont * font ) ;
};


#endif
