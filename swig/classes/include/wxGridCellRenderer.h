// wxGridCellRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellRenderer_h_)
#define _wxGridCellRenderer_h_
class wxGridCellRenderer
{
public:
	/**
	 * \brief Draw the given cell on the provided DC inside the given rectangle
using the style specified by the attribute and the default or selected
state corresponding to the isSelected value.

This pure virtual function has a default implementation which will
prepare the DC using the given attribute: it will draw the rectangle
with the background colour from attr and set the text colour and font. 
	 * \param wxGrid&   
	 * \param wxGridCellAttr&   
	 * \param wxDC&   
	 * \param const wxRect&   
	 * \param int   
	 * \param int   
	 * \param bool   
	*/

  void Draw(wxGrid&  grid , wxGridCellAttr&  attr , wxDC&  dc , const wxRect&  rect , int  row , int  col , bool  isSelected ) ;
	/**
	 * \brief Get the preferred size of the cell for its contents. 
	 * \param wxGrid&   
	 * \param wxGridCellAttr&   
	 * \param wxDC&   
	 * \param int   
	 * \param int   
	*/

  wxSize GetBestSize(wxGrid&  grid , wxGridCellAttr&  attr , wxDC&  dc , int  row , int  col ) ;
	/**
	 * \brief  
	*/

  wxGridCellRenderer* Clone() const;
};


#endif
