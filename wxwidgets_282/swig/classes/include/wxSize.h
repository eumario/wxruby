// wxSize.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSize_h_)
#define _wxSize_h_
class wxSize
{
public:
	/**
	 * \brief  
	*/

   wxSize() ;
	/**
	 * \brief Creates a size object. 
	 * \param int  
	 * \param int  
	*/

   wxSize(int  width , int  height ) ;
	/**
	 * \brief Gets the width member. 
	*/

  int GetWidth() const;
	/**
	 * \brief Gets the height member. 
	*/

  int GetHeight() const;
	/**
	 * \brief Sets the width and height members. 
	 * \param int  
	 * \param int  
	*/

  void Set(int  width , int  height ) ;
	/**
	 * \brief Sets the height. 
	 * \param int  
	*/

  void SetHeight(int  height ) ;
	/**
	 * \brief Sets the width. 
	 * \param int  
	*/

  void SetWidth(int  width ) ;
};


#endif
