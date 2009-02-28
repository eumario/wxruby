// wxImageList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxImageList_h_)
#define _wxImageList_h_
class wxImageList : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxImageList() ;
	/**
	 * \brief Constructor specifying the image size, whether image masks should be created, and the initial size of the list. 
	 * \param int   
	 * \param int   
	 * \param const bool   
	 * \param int   
	*/

   wxImageList(int  width , int  height , const bool  mask = true, int  initialCount = 1) ;
	/**
	 * \brief Adds a new image using a bitmap and optional mask bitmap. 
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	*/

  int Add(const wxBitmap&  bitmap , const wxBitmap& mask = wxNullBitmap) ;
	/**
	 * \brief Adds a new image using a bitmap and mask colour. 
	 * \param const wxBitmap&  
	 * \param const wxColour&  
	*/

  int Add(const wxBitmap&  bitmap , const wxColour&  maskColour ) ;
	/**
	 * \brief Adds a new image using an icon. 
	 * \param const wxIcon&  
	*/

  int Add(const wxIcon&  icon ) ;
	/**
	 * \brief Initializes the list. See   for details. 
	 * \param int   
	 * \param int   
	 * \param const bool   
	 * \param int   
	*/

  bool Create(int  width , int  height , const bool  mask = true, int  initialCount = 1) ;
	/**
	 * \brief Draws a specified image onto a device context. 
	 * \param int  
	 * \param wxDC&  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param const bool   
	*/

  bool Draw(int  index , wxDC&  dc , int  x , int  x , int  flags = wxIMAGELIST_DRAW_NORMAL, const bool  solidBackground = false) ;
	/**
	 * \brief Returns the number of images in the list. 
	*/

  int GetImageCount() const;
	/**
	 * \brief Retrieves the size of the images in the list. Currently, the   
parameter is ignored as all images in the list have the same size. 
	 * \param int   
	 * \param int&   
	 * \param int &  
	*/

  bool GetSize(int  index , int&  width , int & height ) const;
	/**
	 * \brief Removes the image at the given position. 
	 * \param int  
	*/

  bool Remove(int  index ) ;
	/**
	 * \brief Removes all the images in the list. 
	*/

  bool RemoveAll() ;
	/**
	 * \brief Replaces the existing image with the new image. 
	 * \param int  
	 * \param const wxBitmap&  
	 * \param const wxBitmap&  
	*/

  bool Replace(int  index , const wxBitmap&  bitmap , const wxBitmap& mask = wxNullBitmap) ;
	/**
	 * \brief Replaces the existing image with the new image. 
	 * \param int  
	 * \param const wxIcon&  
	*/

  bool Replace(int  index , const wxIcon&  icon ) ;
};


#endif
