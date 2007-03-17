// wxListView.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListView_h_)
#define _wxListView_h_
class wxListView : public wxListCtrl
{
public:
	/**
	 * \brief Resets the column image -- after calling this function, no image will be shown. 
	 * \param int   
	*/

  void ClearColumnImage(int  col ) ;
	/**
	 * \brief Sets focus to the item with the given  . 
	 * \param long   
	*/

  void Focus(long  index ) ;
	/**
	 * \brief Returns the first selected item in a (presumably) multiple selection control.
Tigether with   it can be
used to iterate over all selected items in the control. 
	*/

  long GetFirstSelected() const;
	/**
	 * \brief Returns the currently focused item or $-1$ if none. 
	*/

  long GetFocusedItem() const;
	/**
	 * \brief Used together with   to
iterate oevr all selected items in the control. 
	 * \param long   
	*/

  long GetNextSelected(long  item ) const;
	/**
	 * \brief Returns   if the item with the given   is selected, 
  otherwise. 
	 * \param long   
	*/

  bool IsSelected(long  index ) ;
	/**
	 * \brief Selects or unselects the given item. 
	 * \param bool   
	*/

  void Select(bool  on = true) ;
	/**
	 * \brief Sets the column image for the specified column. To use the column images, the
control must have a valid image list with at least one image. 
	 * \param int   
	 * \param int   
	*/

  void SetColumnImage(int  col , int  image ) ;
};


#endif
