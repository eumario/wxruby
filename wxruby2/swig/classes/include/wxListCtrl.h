// wxListCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListCtrl_h_)
#define _wxListCtrl_h_
class wxListCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxListCtrl() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxListCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listCtrl") ;
	/**
	 * \brief Destructor, destroying the list control. 
	*/

  virtual  ~wxListCtrl() ;
	/**
	 * \brief Arranges the items in icon or small icon view. This only has effect on Win32.   is one of:

\twocolwidtha{5cm} 
	 * \param int   
	*/

  bool Arrange(int  flag = wxLIST_ALIGN_DEFAULT) ;
	/**
	 * \brief Sets the image list associated with the control and 
takes ownership of it (i.e. the control will, unlike when using
SetImageList, delete the list when destroyed).   is one of
wxIMAGE_LIST_NORMAL, wxIMAGE_LIST_SMALL, wxIMAGE_LIST_STATE (the last is unimplemented). 
	 * \param wxImageList*  
	 * \param int   
	*/

  void AssignImageList(wxImageList*  imageList , int  which ) ;
	/**
	 * \brief Deletes all items and all columns. 
	*/

  void ClearAll() ;
	/**
	 * \brief Creates the list control. See   for further details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "listCtrl") ;
	/**
	 * \brief Deletes all the items in the list control.

  This function does   send the
  event because deleting many items
from the control would be too slow then (unlike  ). 
	*/

  bool DeleteAllItems() ;
	/**
	 * \brief Deletes a column. 
	 * \param int   
	*/

  bool DeleteColumn(int  col ) ;
	/**
	 * \brief Deletes the specified item. This function sends the
  event for the item being deleted.

See also: 
	 * \param long   
	*/

  bool DeleteItem(long  item ) ;
	/**
	 * \brief Starts editing the label of the given item. This function generates a
EVT_LIST_BEGIN_LABEL_EDIT event which can be vetoed so that no
text control will appear for in-place editing.

If the user changed the label (i.e. s/he does not press ESC or leave
the text control without changes, a EVT_LIST_END_LABEL_EDIT event
will be sent which can be vetoed as well. 
	 * \param long   
	*/

  void EditLabel(long  item ) ;
	/**
	 * \brief Ensures this item is visible. 
	 * \param long   
	*/

  bool EnsureVisible(long  item ) ;
	/**
	 * \brief Find an item whose label matches this string, starting from the item after   or
the beginning if   is -1. 
	 * \param long   
	 * \param const wxString&   
	 * \param const bool   
	*/

  long FindItem(long  start , const wxString&  str , const bool  partial = false) ;
	/**
	 * \brief Find an item whose data matches this data, starting from the item after   or
the beginning if 'start' is -1. 
	 * \param long   
	 * \param long   
	*/

  long FindItem(long  start , long  data ) ;
	/**
	 * \brief Find an item nearest this position in the specified direction, starting from
the item after   or the beginning if   is -1.

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl there are three methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	 * \param long   
	 * \param const wxPoint&   
	 * \param int   
	*/

  long FindItem(long  start , const wxPoint&  pt , int  direction ) ;
	/**
	 * \brief Gets information about this column. See   for more
information.

\perlnote{In wxPerl this method takes only the   parameter and
  returns a Wx::ListItem ( or undef ).} 
	 * \param int   
	 * \param wxListItem&   
	*/

  bool GetColumn(int  col , wxListItem&  item ) const;
	/**
	 * \brief Returns the number of columns. 
	*/

  int GetColumnCount() const;
	/**
	 * \brief Gets the column width (report view only). 
	 * \param int   
	*/

  int GetColumnWidth(int  col ) const;
	/**
	 * \brief Gets the number of items that can fit vertically in the
visible area of the list control (list or report view)
or the total number of items in the list control (icon
or small icon view). 
	*/

  int GetCountPerPage() const;
	/**
	 * \brief Returns the edit control being currently used to edit a label. Returns  
if no label is being edited.

  It is currently only implemented for wxMSW. 
	*/

  wxTextCtrl * GetEditControl() const;
	/**
	 * \brief Returns the specified image list.   may be one of:

\twocolwidtha{5cm} 
	 * \param int   
	*/

  wxImageList* GetImageList(int  which ) const;
	/**
	 * \brief Gets information about the item. See   for more
information.

You must call   to the ID of item you're interested in
before calling this method.

\pythonnote{The wxPython version of this method takes an integer parameter
for the item ID, an optional integer for the column number, and
returns the wxListItem object.}

\perlnote{In wxPerl this method takes as parameter the   of the item
and ( optionally ) the column, and returns a Wx::ListItem object.} 
	 * \param wxListItem&   
	*/

  bool GetItem(wxListItem&  info ) const;
	/**
	 * \brief Returns the number of items in the list control. 
	*/

  int GetItemCount() const;
	/**
	 * \brief Gets the application-defined data associated with this item. 
	 * \param long   
	*/

  long GetItemData(long  item ) const;
	/**
	 * \brief Returns the position of the item, in icon or small icon view.

\pythonnote{The wxPython version of this method accepts only the item
ID and returns the wxPoint.}

\perlnote{In wxPerl this method takes only the   parameter and
returns a Wx::Point ( or undef ).} 
	 * \param long   
	 * \param wxPoint&   
	*/

  bool GetItemPosition(long  item , wxPoint&  pos ) const;
	/**
	 * \brief Returns the rectangle representing the item's size and position, in client coordinates.

  is one of wxLIST_RECT_BOUNDS, wxLIST_RECT_ICON, wxLIST_RECT_LABEL.

\pythonnote{The wxPython version of this method accepts only the item
ID and code and returns the wxRect.}

\perlnote{In wxPerl this method takes only the   parameter and
returns a Wx::Rect ( or undef ).} 
	 * \param long   
	 * \param wxRect&   
	 * \param int   
	*/

  bool GetItemRect(long  item , wxRect&  rect , int  code = wxLIST_RECT_BOUNDS) const;
	/**
	 * \brief Retrieves the spacing between icons in pixels.
If   is true, gets the spacing for the small icon
view, otherwise the large icon view. 
	 * \param bool   
	*/

  int GetItemSpacing(bool  isSmall ) const;
	/**
	 * \brief Gets the item state. For a list of state flags, see  .

The   indicates which state flags are of interest. 
	 * \param long   
	 * \param long   
	*/

  int GetItemState(long  item , long  stateMask ) const;
	/**
	 * \brief Gets the item text for this item. 
	 * \param long   
	*/

  wxString GetItemText(long  item ) const;
	/**
	 * \brief Searches for an item with the given geometry or state, starting from
  but excluding the   itself. If   is -1,
the first item that matches the specified flags will be returned.

Returns the first item with given state following   or -1 if
no such item found.

This function may be used to find all selected items in the control like this:

 

  can be one of:

\twocolwidtha{5cm}
 

  this parameters is only supported by wxMSW currently and ignored on
other platforms.

  can be a bitlist of the following:

\twocolwidtha{5cm} 
	 * \param long   
	 * \param int   
	 * \param int   
	*/

  long GetNextItem(long  item , int  geometry = wxLIST_NEXT_ALL, int  state = wxLIST_STATE_DONTCARE) const;
	/**
	 * \brief Returns the number of selected items in the list control. 
	*/

  int GetSelectedItemCount() const;
	/**
	 * \brief Gets the text colour of the list control. 
	*/

  wxColour GetTextColour() const;
	/**
	 * \brief Gets the index of the topmost visible item when in
list or report view. 
	*/

  long GetTopItem() const;
	/**
	 * \brief Determines which item (if any) is at the specified point,
giving details in  .   will be a combination of the following flags:

\twocolwidtha{5cm}
 

\pythonnote{A tuple of values is returned in the wxPython version of
this method. The first value is the item id and the second is the
flags value mentioned above.}

\perlnote{In wxPerl this method only takes the   parameter
  and returns a 2-element list  .} 
	 * \param const wxPoint&   
	 * \param int&   
	*/

  long HitTest(const wxPoint&  point , int&  flags ) ;
	/**
	 * \brief For list view mode (only), inserts a column. For more details, see  . 
	 * \param long   
	 * \param wxListItem&   
	*/

  long InsertColumn(long  col , wxListItem&  info ) ;
	/**
	 * \brief For list view mode (only), inserts a column. For more details, see  .

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param long   
	 * \param const wxString&   
	 * \param int   
	 * \param int   
	*/

  long InsertColumn(long  col , const wxString&  heading , int  format = wxLIST_FORMAT_LEFT, int  width = -1) ;
	/**
	 * \brief Inserts an item, returning the index of the new item if successful,
-1 otherwise. 
	 * \param wxListItem&   
	*/

  long InsertItem(wxListItem&  info ) ;
	/**
	 * \brief Inserts a string item. 
	 * \param long   
	 * \param const wxString&   
	*/

  long InsertItem(long  index , const wxString&  label ) ;
	/**
	 * \brief Inserts an image item. 
	 * \param long   
	 * \param int   
	*/

  long InsertItem(long  index , int  imageIndex ) ;
	/**
	 * \brief Insert an image/string item.











\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl there are four methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	 * \param long   
	 * \param const wxString&   
	 * \param int   
	*/

  long InsertItem(long  index , const wxString&  label , int  imageIndex ) ;
	/**
	 * \brief This function may be overloaded in the derived class for a control with 
  style. It should return the attribute for the
for the specified   or   to use the default appearance
parameters.

The base class version always returns  . 
	 * \param long   
	*/

  //virtual wxListItemAttr * OnGetItemAttr(long  item );
	/**
	 * \brief This function must be overloaded in the derived class for a control with 
  style having an   
(if the control doesn't have an image list, it is not necessary to overload
 it). It should return the index of the items image in the controls image list
or $-1$ for no image.

The base class version always returns $-1$. 
	 * \param long   
	*/

  //virtual int OnGetItemImage(long  item );
	/**
	 * \brief This function   be overloaded in the derived class for a control with 
  style. It should return the string containing the text of
the given   for the specified  . 
	 * \param long   
	 * \param long   
	*/

  //virtual wxString OnGetItemText(long  item , long  column );
	/**
	 * \brief Scrolls the list control. If in icon, small icon or report view mode, 
  specifies the number of pixels to scroll. If in list view mode, 
  specifies the number of columns to scroll.   always specifies
the number of pixels to scroll vertically.

  This method is currently only implemented in the Windows version. 
	 * \param int   
	 * \param int   
	*/

  bool ScrollList(int  dx , int  dy ) ;
	/**
	 * \brief Sets the background colour (GetBackgroundColour already implicit in
wxWindow class). 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  col ) ;
	/**
	 * \brief Sets information about this column. See   for more
information. 
	 * \param int   
	 * \param wxListItem&   
	*/

  bool SetColumn(int  col , wxListItem&  item ) ;
	/**
	 * \brief Sets the column width.

  can be a width in pixels or wxLIST_AUTOSIZE (-1) or wxLIST_AUTOSIZE_USEHEADER (-2).
wxLIST_AUTOSIZE will resize the column to the length of its longest item. wxLIST_AUTOSIZE_USEHEADER
will resize the column to the length of the header (Win32) or 80 pixels (other platforms).

In small or normal icon view,   must be -1, and the column width is set for all columns. 
	 * \param int   
	 * \param int   
	*/

  bool SetColumnWidth(int  col , int  width ) ;
	/**
	 * \brief Sets the image list associated with the control.   is one of
wxIMAGE_LIST_NORMAL, wxIMAGE_LIST_SMALL, wxIMAGE_LIST_STATE (the last is unimplemented).

This method does not take ownership of the image list, you have to
delete it yourself. 
	 * \param wxImageList*  
	 * \param int   
	*/

  void SetImageList(wxImageList*  imageList , int  which ) ;
	/**
	 * \brief  
	 * \param wxListItem&   
	*/

  bool SetItem(wxListItem&  info ) ;
	/**
	 * \brief Sets information about the item.

wxListItem is a class with the following members:

\twocolwidtha{5cm}
 

The   member contains a bitlist specifying which of the other fields are valid. The flags are:

\twocolwidtha{5cm}
 

The   and   members take flags from the following:

The wxListItem object can also contain item-specific colour and font
information: for this you need to call one of SetTextColour(),
SetBackgroundColour() or SetFont() functions on it passing it the colour/font
to use. If the colour/font is not specified, the default list control
colour/font is used.

\twocolwidtha{5cm} 
	 * \param long   
	 * \param int   
	 * \param const   
	 * \param int   
	*/

  long SetItem(long  index , int  col , const  wxString& label , int  imageId = -1) ;
	/**
	 * \brief Sets a string field at a particular column.

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param long   
	 * \param int   
	 * \param const wxString&   
	 * \param int   
	*/

  long SetItem(long  index , int  col , const wxString&  label , int  imageId = -1) ;
	/**
	 * \brief This method can only be used with virtual list controls. It is used to indicate
to the control the number of items it contains. After calling it, the main
program should be ready to handle calls to various item callbacks (such as
 ) for all items in the range
from 0 to  . 
	 * \param long   
	*/

  void SetItemCount(long  count ) ;
	/**
	 * \brief Associates application-defined data with this item. 
	 * \param long   
	 * \param long   
	*/

  bool SetItemData(long  item , long  data ) ;
	/**
	 * \brief Sets the unselected and selected images associated with the item. The images are indices into the
image list associated with the list control. 
	 * \param long   
	 * \param int   
	 * \param int   
	*/

  bool SetItemImage(long  item , int  image , int  selImage ) ;
	/**
	 * \brief Sets the position of the item, in icon or small icon view. 
	 * \param long   
	 * \param const wxPoint&   
	*/

  bool SetItemPosition(long  item , const wxPoint&  pos ) ;
	/**
	 * \brief Sets the item state. For a list of state flags, see  .

The   indicates which state flags are valid. 
	 * \param long   
	 * \param long   
	 * \param long   
	*/

  bool SetItemState(long  item , long  state , long  stateMask ) ;
	/**
	 * \brief Sets the item text for this item. 
	 * \param long   
	 * \param const wxString&   
	*/

  void SetItemText(long  item , const wxString&  text ) ;
	/**
	 * \brief Adds or removes a single window style. 
	 * \param long   
	 * \param const bool   
	*/

  void SetSingleStyle(long  style , const bool  add = true) ;
	/**
	 * \brief Sets the text colour of the list control. 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  col ) ;
	/**
	 * \brief Sets the whole window style. 
	 * \param long   
	*/

  void SetWindowStyleFlag(long  style ) ;
	/**
	 * \brief Call this function to sort the items in the list control. Sorting is done
using the specified   function. This function must have the
following prototype:

 

It is called each time when the two items must be compared and should return 0
if the items are equal, negative value if the first item is less than the
second one and positive value if the first one is greater than the second one
(the same convention as used by  ).









Notice that the control may only be sorted on client data associated with the
items, so you   use   if
you want to be able to sort the items in the control.

Please see the   for an example of
using this function.

\pythonnote{wxPython uses the sortData parameter to pass the Python
function to call, so it is not available for programmer use.  Call
SortItems with a reference to a callable object that expects two
parameters.}

\perlnote{In wxPerl the comparison function must take just two parameters;
 however, you may use a closure to achieve an effect similar to the
 SortItems third parameter.} 
	 * \param wxListCtrlCompare   
	 * \param long   
	*/

  bool SortItems(wxListCtrlCompare  fnSortCallBack , long  data ) ;
};


#endif
