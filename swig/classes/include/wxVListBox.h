// wxVListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVListBox_h_)
#define _wxVListBox_h_
class wxVListBox : public wxVScrolledWindow
{
public:
	/**
	 * \brief Normal constructor which calls   internally. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param size_t   
	 * \param long   
	 * \param const wxString&   
	*/

   wxVListBox(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, size_t  countItems = 0, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
	/**
	 * \brief Default constructor, you must call   later. 
	*/

   wxVListBox() ;
	/**
	 * \brief Deletes all items from the control. 
	*/

  void Clear() ;
	/**
	 * \brief Creates the control. To finish creating it you also should call 
  to let it know about the
number of items it contains.

The only special style which may be used with wxVListBox is   
which indicates that the listbox should support multiple selection.

Returns   on success or   if the control couldn't be created 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxVListBoxNameStr) ;
	/**
	 * \brief  
	*/

  bool DeselectAll() ;
	/**
	 * \brief Returns the index of the first selected item in the listbox or 
  if no items are currently selected.

  is an opaque parameter which should be passed to the subsequent
calls to  . It is needed in
order to allow parallel iterations over the selected items.

Here is a typical example of using these functions:
 

This method is only valid for multi selection listboxes. 
	 * \param unsigned long&   
	*/

  int GetFirstSelected(unsigned long&  cookie ) const;
	/**
	 * \brief Get the number of items in the control. 
	*/

  size_t GetItemCount() const;
	/**
	 * \brief Returns the margins used by the control. The   field of the returned
point is the horizontal margine and the   field is the vertical one. 
	*/

  wxPoint GetMargins() const;
	/**
	 * \brief Returns the index of the next selected item or   if there are
no more.

This method is only valid for multi selection listboxes. 
	 * \param unsigned long&   
	*/

  int GetNextSelected(unsigned long&  cookie ) const;
	/**
	 * \brief Returns the number of the items currently selected.

It is valid for both single and multi selection controls. In the former case it
may only return 0 or 1 however. 
	*/

  size_t GetSelectedCount() const;
	/**
	 * \brief Get the currently selected item or $-1$ if there is no selection. 
	*/

  int GetSelection() const;
	/**
	 * \brief Returns the background colour used for the selected cells. By default the
standard system colour is used. 
	*/

  const wxColour& GetSelectionBackground() const;
	/**
	 * \brief Returns   if the listbox was created with   style
and so supports multiple selection or   if it is a single selection
listbox. 
	*/

  bool HasMultipleSelection() const;
	/**
	 * \brief Returns   if this item is the current one,   otherwise.

Current item is always the same as selected one for the single selection
listbox and in this case this method is equivalent to 
  but they are different for multi
selection listboxes where many items may be selected but only one (at most) is
current. 
	 * \param size_t   
	*/

  bool IsCurrent(size_t  item ) const;
	/**
	 * \brief Returns   if this item is selected,   otherwise. 
	 * \param size_t   
	*/

  bool IsSelected(size_t  item ) const;
	/**
	 * \brief The derived class must implement this function to actually draw the item
with the given index on the provided DC. 
	 * \param wxDC&   
	 * \param const wxRect&   
	 * \param size_t   
	*/

  virtual void OnDrawItem(wxDC&  dc , const wxRect&  rect , size_t  n ) const;
	/**
	 * \brief This method may be used to draw separators between the lines. The rectangle
passed to it may be modified, typically to deflate it a bit before passing to
 .

The base class version of this method doesn't do anything. 
	 * \param wxDC&   
	 * \param wxRect&   
	 * \param size_t   
	*/

  virtual void OnDrawSeparator(wxDC&  dc , wxRect&  rect , size_t  n ) const;
	/**
	 * \brief The derived class must implement this method to return the height of the
specified item (in pixels). 
	 * \param size_t   
	*/

  virtual wxCoord OnMeasureItem(size_t  n ) const;
	/**
	 * \brief Selects or deselects the specified item which must be valid (i.e. not
equal to  ).

Return   if the items selection status has changed or  
otherwise.

This function is only valid for the multiple selection listboxes, use 
  for the single selection ones. 
	 * \param size_t   
	 * \param bool   
	*/

  bool Select(size_t  item , bool  select = true) ;
	/**
	 * \brief  
	*/

  bool SelectAll() ;
	/**
	 * \brief  
	 * \param size_t   
	 * \param size_t   
	*/

  bool SelectRange(size_t  from , size_t  to ) ;
	/**
	 * \brief Set the number of items to be shown in the control.

This is just a synonym for
 . 
	 * \param size_t   
	*/

  void SelectRange(size_t  count ) ;
	/**
	 * \brief  
	 * \param const wxPoint&   
	*/

  void SetMargins(const wxPoint&  pt ) ;
	/**
	 * \brief Set the margins: horizontal margin is the distance between the window
border and the item contents while vertical margin is half of the
distance between items.

By default both margins are 0. 
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  void SetMargins(wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Set the selection to the specified item, if it is $-1$ the selection is
unset. The selected item will be automatically scrolled into view if it isn't
currently visible.

This method may be used both with single and multiple selection listboxes. 
	 * \param int   
	*/

  void SetSelection(int  selection ) ;
	/**
	 * \brief Sets the colour to be used for the selected cells background. The background of
the standard cells may be changed by simply calling 
 . 
	 * \param const wxColour&   
	*/

  void SetSelectionBackground(const wxColour&  col ) ;
	/**
	 * \brief Toggles the state of the specified  , i.e. selects it if it was
unselected and deselects it if it was selected.

This method is only valid for multi selection listboxes. 
	 * \param size_t   
	*/

  void Toggle(size_t  item ) ;
};


#endif
