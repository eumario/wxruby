// wxTreeCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTreeCtrl_h_)
#define _wxTreeCtrl_h_
class wxTreeCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxTreeCtrl() ;
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

   wxTreeCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
	/**
	 * \brief Destructor, destroying the list control. 
	*/

  virtual  ~wxTreeCtrl() ;
	/**
	 * \brief Adds the root node to the tree, returning the new item.

The   and   parameters are an index within
the normal image list specifying the image to use for unselected and
selected items, respectively.
If   &gt; -1 and   is -1, the same image is used for
both selected and unselected items. 
	 * \param const wxString&  
	 * \param int  
	 * \param int  
	 * \param wxTreeItemData*  
	*/

  wxTreeItemId AddRoot(const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
	/**
	 * \brief Appends an item to the end of the branch identified by  , return a new item id.

The   and   parameters are an index within
the normal image list specifying the image to use for unselected and
selected items, respectively.
If   &gt; -1 and   is -1, the same image is used for
both selected and unselected items. 
	 * \param const wxTreeItemId&   
	 * \param const wxString&  
	 * \param int  
	 * \param int  
	 * \param wxTreeItemData*  
	*/

  wxTreeItemId AppendItem(const wxTreeItemId&  parent , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
	/**
	 * \brief Sets the buttons image list. The button images assigned with this method will
be automatically deleted by wxTreeCtrl as appropriate
(i.e. it takes ownership of the list).

Setting or assigning the button image list enables the display of image buttons.
Once enabled, the only way to disable the display of button images is to set
the button image list to  .

This function is only available in the generic version.

See also  . 
	 * \param wxImageList*  
	*/

  void AssignButtonsImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the normal image list. Image list assigned with this method will
be automatically deleted by wxTreeCtrl as appropriate
(i.e. it takes ownership of the list).

See also  . 
	 * \param wxImageList*  
	*/

  void AssignImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the state image list. Image list assigned with this method will
be automatically deleted by wxTreeCtrl as appropriate
(i.e. it takes ownership of the list).

See also  . 
	 * \param wxImageList*  
	*/

  void AssignStateImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Collapses the given item. 
	 * \param const wxTreeItemId&  
	*/

  void Collapse(const wxTreeItemId&  item ) ;
	/**
	 * \brief Collapses the given item and removes all children. 
	 * \param const wxTreeItemId&  
	*/

  void CollapseAndReset(const wxTreeItemId&  item ) ;
	/**
	 * \brief Creates the tree control. See   for further details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
	/**
	 * \brief Deletes the specified item. A   event will be
generated.

This function may cause a subsequent call to GetNextChild to fail. 
	 * \param const wxTreeItemId&  
	*/

  void Delete(const wxTreeItemId&  item ) ;
	/**
	 * \brief Deletes all the items in the control. Note that this may not generate 
  events under some Windows versions although
normally such event is generated for each removed item. 
	*/

  void DeleteAllItems() ;
	/**
	 * \brief Deletes all children of the given item (but not the item itself). Note that
this will   generate any events unlike 
  method.

If you have called  , you
may need to call it again since   does not automatically
clear the setting. 
	 * \param const wxTreeItemId&   
	*/

  void DeleteChildren(const wxTreeItemId&  item ) ;
	/**
	 * \brief Starts editing the label of the given item. This function generates a
EVT_TREE_BEGIN_LABEL_EDIT event which can be vetoed so that no
text control will appear for in-place editing.

If the user changed the label (i.e. s/he does not press ESC or leave
the text control without changes, a EVT_TREE_END_LABEL_EDIT event
will be sent which can be vetoed as well. 
	 * \param const wxTreeItemId&  
	*/

  void EditLabel(const wxTreeItemId&  item ) ;
	/**
	 * \brief Ends label editing. If   is  , the edit will be cancelled.

This function is currently supported under Windows only. 
	 * \param bool   
	*/

  void EndEditLabel(bool  cancelEdit ) ;
	/**
	 * \brief Scrolls and/or expands items to ensure that the given item is visible. 
	 * \param const wxTreeItemId&  
	*/

  void EnsureVisible(const wxTreeItemId&  item ) ;
	/**
	 * \brief Expands the given item. 
	 * \param const wxTreeItemId&  
	*/

  void Expand(const wxTreeItemId&  item ) ;
	/**
	 * \brief Retrieves the rectangle bounding the  . If   is  ,
only the rectangle around the item's label will be returned, otherwise the
item's image is also taken into account.

The return value is   if the rectangle was successfully retrieved or  
if it was not (in this case   is not changed) - for example, if the
item is currently invisible.

\pythonnote{The wxPython version of this method requires only the
  and   parameters.  The return value is either a
  object or  .}

\perlnote{In wxPerl this method only takes the parameters   and 
   , and returns a Wx::Rect ( or undef ).} 
	 * \param const wxTreeItemId&  
	 * \param wxRect&   
	 * \param bool   
	*/

  bool GetBoundingRect(const wxTreeItemId&  item , wxRect&  rect , bool  textOnly = false) const;
	/**
	 * \brief Returns the buttons image list (from which application-defined button images are taken).

This function is only available in the generic version. 
	*/

  wxImageList* GetButtonsImageList() const;
	/**
	 * \brief Returns the number of items in the branch. If   is  , returns the total number
of descendants, otherwise only one level of children is counted. 
	 * \param const wxTreeItemId&  
	 * \param bool  
	*/

  size_t GetChildrenCount(const wxTreeItemId&  item , bool recursively = true) const;
	/**
	 * \brief Returns the number of items in the control. 
	*/

  int GetCount() const;
	/**
	 * \brief Returns the edit control being currently used to edit a label. Returns  
if no label is being edited.

  It is currently only implemented for wxMSW. 
	*/

  wxTextCtrl * GetEditControl() const;
	/**
	 * \brief  
	 * \param const wxTreeItemId&  
	 * \param long&   
	*/

  wxTreeItemId GetFirstChild(const wxTreeItemId&  item , long&  cookie ) const;
	/**
	 * \brief Returns the first visible item. 
	*/

  wxTreeItemId GetFirstVisibleItem() const;
	/**
	 * \brief Returns the normal image list. 
	*/

  wxImageList* GetImageList() const;
	/**
	 * \brief Returns the current tree control indentation. 
	*/

  int GetIndent() const;
	/**
	 * \brief Returns the background colour of the item. 
	 * \param const wxTreeItemId&  
	*/

  wxColour GetItemBackgroundColour(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the tree item data associated with the item. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemData* GetItemData(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the font of the item label. 
	 * \param const wxTreeItemId&  
	*/

  wxFont GetItemFont(const wxTreeItemId&  item ) const;
	/**
	 * \brief Gets the specified item image. The value of   may be: 
	 * \param const wxTreeItemId&   
	 * \param wxTreeItemIcon   
	*/

  int GetItemImage(const wxTreeItemId&  item , wxTreeItemIcon  which = wxTreeItemIcon_Normal) const;
	/**
	 * \brief Returns the item label. 
	 * \param const wxTreeItemId&  
	*/

  wxString GetItemText(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the colour of the item label. 
	 * \param const wxTreeItemId&  
	*/

  wxColour GetItemTextColour(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the last child of the item (or an invalid tree item if this item has no children). 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetLastChild(const wxTreeItemId&  item ) const;
	/**
	 * \brief  
	 * \param const wxTreeItemId&  
	 * \param long&   
	*/

  wxTreeItemId GetNextChild(const wxTreeItemId&  item , long&  cookie ) const;
	/**
	 * \brief Returns the next sibling of the specified item; call   for the previous sibling.

Returns an invalid tree item if there are no further siblings. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetNextSibling(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the next visible item. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetNextVisible(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the item's parent. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetItemParent(const wxTreeItemId&  item ) const;
	/**
	 * \brief This function is deprecated and will only work if  
is defined.  Use   instead.

Returns the item's parent.

\pythonnote{This method is named   to avoid a name
clash with wxWindow::GetParent.} 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetParent(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the previous sibling of the specified item; call   for the next sibling.

Returns an invalid tree item if there are no further children. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetPrevSibling(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the previous visible item. 
	 * \param const wxTreeItemId&  
	*/

  wxTreeItemId GetPrevVisible(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the root item for the tree control. 
	*/

  wxTreeItemId GetRootItem() const;
	/**
	 * \brief Gets the selected item image (this function is obsolete, use
 ) instead). 
	 * \param const wxTreeItemId&   
	*/

  int GetItemSelectedImage(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns the selection, or an invalid item if there is no selection.
This function only works with the controls without wxTR_MULTIPLE style, use
  for the controls which do have
this style. 
	*/

  wxTreeItemId GetSelection() const;
	/**
	 * \brief Fills the array of tree items passed in with the currently selected items. This
function can be called only if the control has the wxTR_MULTIPLE style.

Returns the number of selected items.

\pythonnote{The wxPython version of this method accepts no parameters
and returns a Python list of  s.}

\perlnote{In wxPerl this method takes no parameters and returns a list of
  s.} 
	 * \param wxArrayTreeItemIds&   
	*/

  size_t GetSelections(wxArrayTreeItemIds&  selection ) const;
	/**
	 * \brief Returns the state image list (from which application-defined state images are taken). 
	*/

  wxImageList* GetStateImageList() const;
	/**
	 * \brief Calculates which (if any) item is under the given point, returning the tree item
id at this point plus extra information  .   is a bitlist of the following:

\twocolwidtha{5cm}
 

\pythonnote{in wxPython both the wxTreeItemId and the flags are
returned as a tuple.}

\perlnote{In wxPerl this method only takes the   parameter
  and returns a 2-element list  .} 
	 * \param const wxPoint&   
	 * \param int&   
	*/

  wxTreeItemId HitTest(const wxPoint&  point , int&  flags ) ;
	/**
	 * \brief  
	 * \param const wxTreeItemId&   
	 * \param const wxTreeItemId&   
	 * \param const wxString&  
	 * \param int  
	 * \param int  
	 * \param wxTreeItemData*  
	*/

  wxTreeItemId InsertItem(const wxTreeItemId&  parent , const wxTreeItemId&  previous , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
	/**
	 * \brief Inserts an item after a given one ( ) or before one identified by its position ( ).
  must be less than the number of children.

The   and   parameters are an index within
the normal image list specifying the image to use for unselected and
selected items, respectively.
If   &gt; -1 and   is -1, the same image is used for
both selected and unselected items.

\pythonnote{The second form of this method is called
  in wxPython.} 
	 * \param const wxTreeItemId&   
	 * \param size_t  
	 * \param const wxString&  
	 * \param int  
	 * \param int  
	 * \param wxTreeItemData*  
	*/

  wxTreeItemId InsertItem(const wxTreeItemId&  parent , size_t  before , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
	/**
	 * \brief Returns   if the given item is in bold state.

See also: 
	 * \param const wxTreeItemId&   
	*/

  bool IsBold(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns   if the item is expanded (only makes sense if it has children). 
	 * \param const wxTreeItemId&  
	*/

  bool IsExpanded(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns   if the item is selected. 
	 * \param const wxTreeItemId&  
	*/

  bool IsSelected(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns   if the item is visible (it might be outside the view, or not expanded). 
	 * \param const wxTreeItemId&  
	*/

  bool IsVisible(const wxTreeItemId&  item ) const;
	/**
	 * \brief Returns   if the item has children. 
	 * \param const wxTreeItemId&  
	*/

  bool ItemHasChildren(const wxTreeItemId&  item ) const;
	/**
	 * \brief Override this function in the derived class to change the sort order of the
items in the tree control. The function should return a negative, zero or
positive value if the first item is less than, equal to or greater than the
second one.

The base class version compares items alphabetically.

See also: 
	 * \param const wxTreeItemId&   
	 * \param const wxTreeItemId&   
	*/

  virtual int OnCompareItems(const wxTreeItemId&  item1 , const wxTreeItemId&  item2 ) ;
	/**
	 * \brief Appends an item as the first child of  , return a new item id.

The   and   parameters are an index within
the normal image list specifying the image to use for unselected and
selected items, respectively.
If   &gt; -1 and   is -1, the same image is used for
both selected and unselected items. 
	 * \param const wxTreeItemId&   
	 * \param const wxString&  
	 * \param int  
	 * \param int  
	 * \param wxTreeItemData*  
	*/

  wxTreeItemId PrependItem(const wxTreeItemId&  parent , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
	/**
	 * \brief Scrolls the specified item into view. 
	 * \param const wxTreeItemId&  
	*/

  void ScrollTo(const wxTreeItemId&  item ) ;
	/**
	 * \brief Selects the given item. 
	 * \param const wxTreeItemId&  
	*/

  bool SelectItem(const wxTreeItemId&  item ) ;
	/**
	 * \brief Sets the buttons image list (from which application-defined button images are taken).
The button images assigned with this method will
  be deleted by wxTreeCtrl's destructor, you must delete it yourself.

Setting or assigning the button image list enables the display of image buttons.
Once enabled, the only way to disable the display of button images is to set
the button image list to  .

This function is only available in the generic version.

See also  . 
	 * \param wxImageList*  
	*/

  void SetButtonsImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the indentation for the tree control. 
	 * \param int   
	*/

  void SetIndent(int  indent ) ;
	/**
	 * \brief Sets the normal image list. Image list assigned with this method will
  be deleted by wxTreeCtrl's destructor, you must delete it yourself.

See also  . 
	 * \param wxImageList*  
	*/

  void SetImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the colour of the item's background. 
	 * \param const wxTreeItemId&  
	 * \param const wxColour&   
	*/

  void SetItemBackgroundColour(const wxTreeItemId&  item , const wxColour&  col ) ;
	/**
	 * \brief Makes item appear in bold font if   parameter is   or resets it to
the normal state.

See also: 
	 * \param const wxTreeItemId&   
	 * \param bool  
	*/

  void SetItemBold(const wxTreeItemId&  item , bool bold = true) ;
	/**
	 * \brief Sets the item client data.

\pythonnote{wxPython provides the following shortcut method:\par
\indented{2cm}{ }
}

\perlnote{wxPerl provides the following shortcut method:
\indented{2cm}{
 }
} 
	 * \param const wxTreeItemId&  
	 * \param wxTreeItemData*   
	*/

  void SetItemData(const wxTreeItemId&  item , wxTreeItemData*  data ) ;
	/**
	 * \brief Sets the item's font. All items in the tree should have the same height to avoid
text clipping, so the fonts height should be the same for all of them,
although font attributes may vary. 
	 * \param const wxTreeItemId&  
	 * \param const wxFont&   
	*/

  void SetItemFont(const wxTreeItemId&  item , const wxFont&  font ) ;
	/**
	 * \brief Force appearance of the button next to the item. This is useful to
allow the user to expand the items which don't have any children now,
but instead adding them only when needed, thus minimizing memory
usage and loading time. 
	 * \param const wxTreeItemId&  
	 * \param bool   
	*/

  void SetItemHasChildren(const wxTreeItemId&  item , bool  hasChildren = true) ;
	/**
	 * \brief Sets the specified item image. See  
for the description of the   parameter. 
	 * \param const wxTreeItemId&  
	 * \param int   
	 * \param wxTreeItemIcon   
	*/

  void SetItemImage(const wxTreeItemId&  item , int  image , wxTreeItemIcon  which = wxTreeItemIcon_Normal) ;
	/**
	 * \brief Sets the selected item image (this function is obsolete, use  ) instead). 
	 * \param const wxTreeItemId&  
	 * \param int   
	*/

  void SetItemSelectedImage(const wxTreeItemId&  item , int  selImage ) ;
	/**
	 * \brief Sets the item label. 
	 * \param const wxTreeItemId&  
	 * \param const wxString&   
	*/

  void SetItemText(const wxTreeItemId&  item , const wxString&  text ) ;
	/**
	 * \brief Sets the colour of the item's text. 
	 * \param const wxTreeItemId&  
	 * \param const wxColour&   
	*/

  void SetItemTextColour(const wxTreeItemId&  item , const wxColour&  col ) ;
	/**
	 * \brief Sets the state image list (from which application-defined state images are taken).
Image list assigned with this method will
  be deleted by wxTreeCtrl's destructor, you must delete it yourself.

See also  . 
	 * \param wxImageList*  
	*/

  void SetStateImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the mode flags associated with the display of the tree control.
The new mode takes effect immediately.
(Generic only; MSW ignores changes.) 
	 * \param long  
	*/

  void SetStateImageList(long styles ) ;
	/**
	 * \brief  
	 * \param const wxTreeItemId&  
	*/

  void SortChildren(const wxTreeItemId&  item ) ;
	/**
	 * \brief Toggles the given item between collapsed and expanded states. 
	 * \param const wxTreeItemId&  
	*/

  void Toggle(const wxTreeItemId&  item ) ;
	/**
	 * \brief Removes the selection from the currently selected item (if any). 
	*/

  void Unselect() ;
	/**
	 * \brief This function either behaves the same as  
if the control doesn't have wxTR_MULTIPLE style, or removes the selection from
all items if it does have this style. 
	*/

  void UnselectAll() ;
};


#endif
