// wxGridSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridSizer_h_)
#define _wxGridSizer_h_
class wxGridSizer : public wxSizer
{
public:
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxGridSizer(int  rows , int  cols , int  vgap , int  hgap ) ;
	/**
	 * \brief Constructor for a wxGridSizer.   and   determine the number of
columns and rows in the sizer - if either of the parameters is zero, it will be
calculated to form the total number of children in the sizer, thus making the
sizer grow dynamically.   and   define extra space between
all children. 
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxGridSizer(int  cols , int  vgap = 0, int  hgap = 0) ;
	/**
	 * \brief Returns the number of columns in the sizer. 
	*/

  int GetCols() ;
	/**
	 * \brief Returns the horizontal gap (in pixels) between cells in the sizer. 
	*/

  int GetHGap() ;
	/**
	 * \brief Returns the number of rows in the sizer. 
	*/

  int GetRows() ;
	/**
	 * \brief Returns the vertical gap (in pixels) between the cells in the sizer. 
	*/

  int GetVGap() ;
	/**
	 * \brief Sets the number of columns in the sizer. 
	 * \param int   
	*/

  void SetCols(int  cols ) ;
	/**
	 * \brief Sets the horizontal gap (in pixels) between cells in the sizer. 
	 * \param int   
	*/

  void SetHGap(int  gap ) ;
	/**
	 * \brief Sets the number of rows in the sizer. 
	 * \param int   
	*/

  void SetRows(int  rows ) ;
	/**
	 * \brief Sets the vertical gap (in pixels) between the cells in the sizer. 
	 * \param int   
	*/

  void SetVGap(int  gap ) ;
};


#endif
