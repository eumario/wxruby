// wxHtmlContainerCell.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlContainerCell_h_)
#define _wxHtmlContainerCell_h_
class wxHtmlContainerCell : public wxHtmlCell
{
public:
	/**
	 * \brief Constructor.   is pointer to parent container or NULL. 
	 * \param wxHtmlContainerCell   
	*/

   wxHtmlContainerCell(wxHtmlContainerCell  *parent ) ;
	/**
	 * \brief Returns container's horizontal alignment. 
	*/

  int GetAlignHor() const;
	/**
	 * \brief Returns container's vertical alignment. 
	*/

  int GetAlignVer() const;
	/**
	 * \brief Returns the background colour of the container or   if no background
colour is set. 
	*/

  wxColour GetBackgroundColour() ;
	/**
	 * \brief Returns pointer to the first cell in the list.
You can then use wxHtmlCell's GetNext method to obtain pointer to the next
cell in list.

  This shouldn't be used by the end user. If you need some way of
finding particular cell in the list, try   method
instead. 
	*/

  wxHtmlCell* GetFirstCell() ;
	/**
	 * \brief Returns the indentation.   is one of the   constants.

  You must call   
with same   parameter in order to correctly interpret the returned integer value.
It is NOT always in pixels! 
	 * \param int   
	*/

  int GetIndent(int  ind ) const;
	/**
	 * \brief Returns the units of indentation for   where   is one
of the   constants. 
	 * \param int   
	*/

  int GetIndentUnits(int  ind ) const;
	/**
	 * \brief Inserts new cell into the container. 
	 * \param wxHtmlCell   
	*/

  void InsertCell(wxHtmlCell  *cell ) ;
	/**
	 * \brief Sets the container's alignment (both horizontal and vertical) according to
the values stored in  . (Tags   parameter is extracted.) In fact
it is only a front-end to   
and  . 
	 * \param const wxHtmlTag&   
	*/

  void SetAlign(const wxHtmlTag&  tag ) ;
	/**
	 * \brief Sets the container's  . During   
each line is aligned according to   value. 
	 * \param int   
	*/

  void SetAlignHor(int  al ) ;
	/**
	 * \brief Sets the container's  . This is per-line alignment! 
	 * \param int   
	*/

  void SetAlignVer(int  al ) ;
	/**
	 * \brief Sets the background colour for this container. 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  clr ) ;
	/**
	 * \brief Sets the border (frame) colours. A border is a rectangle around the container. 
	 * \param const wxColour&   
	 * \param const wxColour&   
	*/

  void SetBorder(const wxColour&  clr1 , const wxColour&  clr2 ) ;
	/**
	 * \brief Sets the indentation (free space between borders of container and subcells). 
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  void SetIndent(int  i , int  what , int  units = wxHTML_UNITS_PIXELS) ;
	/**
	 * \brief Sets minimal height of the container.

When container's   is called, m_Height
is set depending on layout of subcells to the height of area covered
by layed-out subcells. Calling this method guarantees you that the height
of container is never smaller than   - even if the subcells cover
much smaller area. 
	 * \param int   
	 * \param int   
	*/

  void SetMinHeight(int  h , int  align = wxHTML_ALIGN_TOP) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetWidthFloat(int  w , int  units ) ;
	/**
	 * \brief Sets floating width adjustment.

The normal behaviour of container is that its width is the same as the width of
parent container (and thus you can have only one sub-container per line).
You can change this by setting FWA.

  is number of real pixels that equals to 1 HTML pixel.









\pythonnote{The second form of this method is named
SetWidthFloatFromTag in wxPython.} 
	 * \param const wxHtmlTag&   
	 * \param double   
	*/

  void SetWidthFloat(const wxHtmlTag&  tag , double  pixel_scale = 1.0) ;
};


#endif
