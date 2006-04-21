// Copyright 2006 by Kevin Smith
// released under the MIT-style wxruby2 license

#if !defined(_wxTreeCtrl_h_)
#define _wxTreeCtrl_h_
class wxTreeCtrl : public wxControl
{
public:
   wxTreeCtrl() ;
   wxTreeCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
  virtual  ~wxTreeCtrl() ;
  wxTreeItemId AddRoot(const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
  wxTreeItemId AppendItem(const wxTreeItemId&  parent , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;

#ifndef __WXMSW__
  void AssignButtonsImageList(wxImageList*  imageList ) ;
#endif

  void AssignImageList(wxImageList*  imageList ) ;
  void AssignStateImageList(wxImageList*  imageList ) ;
  void Collapse(const wxTreeItemId&  item ) ;
  void CollapseAndReset(const wxTreeItemId&  item ) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTR_HAS_BUTTONS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
  void Delete(const wxTreeItemId&  item ) ;
  void DeleteAllItems() ;
  void DeleteChildren(const wxTreeItemId&  item ) ;
  void EditLabel(const wxTreeItemId&  item ) ;

#if __MSWIN__
  void EndEditLabel(bool  cancelEdit ) ;
#endif

  void EnsureVisible(const wxTreeItemId&  item ) ;
  void Expand(const wxTreeItemId&  item ) ;

/*
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

#ifndef __WXMSW__
  wxImageList* GetButtonsImageList() const;
#endif

  size_t GetChildrenCount(const wxTreeItemId&  item , bool recursively = true) const;
  int GetCount() const;
  wxTextCtrl * GetEditControl() const;
  wxTreeItemId GetFirstChild(const wxTreeItemId&  item , long&  cookie ) const;
  wxTreeItemId GetFirstVisibleItem() const;
  wxImageList* GetImageList() const;
  int GetIndent() const;
  wxColour GetItemBackgroundColour(const wxTreeItemId&  item ) const;
  wxTreeItemData* GetItemData(const wxTreeItemId&  item ) const;
  wxFont GetItemFont(const wxTreeItemId&  item ) const;
  int GetItemImage(const wxTreeItemId&  item , wxTreeItemIcon  which = wxTreeItemIcon_Normal) const;
  wxString GetItemText(const wxTreeItemId&  item ) const;
  wxColour GetItemTextColour(const wxTreeItemId&  item ) const;
  wxTreeItemId GetLastChild(const wxTreeItemId&  item ) const;
  wxTreeItemId GetNextChild(const wxTreeItemId&  item , long&  cookie ) const;
  wxTreeItemId GetNextSibling(const wxTreeItemId&  item ) const;
  wxTreeItemId GetNextVisible(const wxTreeItemId&  item ) const;
  wxTreeItemId GetItemParent(const wxTreeItemId&  item ) const;

	/**
\pythonnote{This method is named   to avoid a name
clash with wxWindow::GetParent.} 
	 * \param const wxTreeItemId&  
	*/
  wxTreeItemId GetParent(const wxTreeItemId&  item ) const;

  wxTreeItemId GetPrevSibling(const wxTreeItemId&  item ) const;
  wxTreeItemId GetPrevVisible(const wxTreeItemId&  item ) const;
  wxTreeItemId GetRootItem() const;
  int GetItemSelectedImage(const wxTreeItemId&  item ) const;
  wxTreeItemId GetSelection() const;

/**
\pythonnote{The wxPython version of this method accepts no parameters
and returns a Python list of  s.}

\perlnote{In wxPerl this method takes no parameters and returns a list of
  s.} 
	 * \param wxArrayTreeItemIds&   
	*/
  size_t GetSelections(wxArrayTreeItemIds&  selection ) const;
  wxImageList* GetStateImageList() const;

/**
\pythonnote{in wxPython both the wxTreeItemId and the flags are
returned as a tuple.}

\perlnote{In wxPerl this method only takes the   parameter
  and returns a 2-element list  .} 
	 * \param const wxPoint&   
	 * \param int&   
	*/
  wxTreeItemId HitTest(const wxPoint& point) ;

  wxTreeItemId HitTest(const wxPoint&  point , int&  flags ) ;
  wxTreeItemId InsertItem(const wxTreeItemId&  parent , const wxTreeItemId&  previous , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;

/**
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
  bool IsBold(const wxTreeItemId&  item ) const;
  bool IsExpanded(const wxTreeItemId&  item ) const;
  bool IsSelected(const wxTreeItemId&  item ) const;
  bool IsVisible(const wxTreeItemId&  item ) const;
  bool ItemHasChildren(const wxTreeItemId&  item ) const;
  virtual int OnCompareItems(const wxTreeItemId&  item1 , const wxTreeItemId&  item2 ) ;
  wxTreeItemId PrependItem(const wxTreeItemId&  parent , const wxString&  text , int image = -1, int selImage = -1, wxTreeItemData* data = NULL) ;
  void ScrollTo(const wxTreeItemId&  item ) ;
  void SelectItem(const wxTreeItemId&  item ) ;

#ifndef __WXMSW__
  void SetButtonsImageList(wxImageList*  imageList ) ;
#endif

  void SetIndent(int  indent ) ;
  void SetImageList(wxImageList*  imageList ) ;
  void SetItemBackgroundColour(const wxTreeItemId&  item , const wxColour&  col ) ;
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

  void SetItemFont(const wxTreeItemId&  item , const wxFont&  font ) ;
  void SetItemHasChildren(const wxTreeItemId&  item , bool  hasChildren = true) ;
  void SetItemImage(const wxTreeItemId&  item , int  image , wxTreeItemIcon  which = wxTreeItemIcon_Normal) ;
  void SetItemSelectedImage(const wxTreeItemId&  item , int  selImage ) ;
  void SetItemText(const wxTreeItemId&  item , const wxString&  text ) ;
  void SetItemTextColour(const wxTreeItemId&  item , const wxColour&  col ) ;
  void SetStateImageList(wxImageList*  imageList ) ;
  void SetStateImageList(long styles ) ;
  void SortChildren(const wxTreeItemId&  item ) ;
  void Toggle(const wxTreeItemId&  item ) ;
  void Unselect() ;
  void UnselectAll() ;
};


#endif
