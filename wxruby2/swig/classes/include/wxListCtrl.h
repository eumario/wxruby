// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxListCtrl_h_)
#define _wxListCtrl_h_
class wxListCtrl : public wxControl
{
public:
   wxListCtrl() ;
   wxListCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
  virtual  ~wxListCtrl() ;
  bool Arrange(int  flag = wxLIST_ALIGN_DEFAULT) ;
  void AssignImageList(wxImageList*  imageList , int  which ) ;
  void ClearAll() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxLC_ICON, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listCtrl")) ;
  bool DeleteAllItems() ;
  bool DeleteColumn(int  col ) ;
  bool DeleteItem(long  item ) ;
  void EditLabel(long  item ) ;
  bool EnsureVisible(long  item ) ;
  long FindItem(long  start , const wxString&  str , const bool  partial = false) ;
  long FindItem(long  start , long  data ) ;
  long FindItem(long  start , const wxPoint&  pt , int  direction ) ;
  bool GetColumn(int  col , wxListItem&  item ) const;
  int GetColumnCount() const;
  int GetColumnWidth(int  col ) const;
  int GetCountPerPage() const;
  wxTextCtrl * GetEditControl() const;
  wxImageList* GetImageList(int  which ) const;
  bool GetItem(wxListItem&  info ) const;
  wxColour GetItemBackgroundColour(long item) const;
  int GetItemCount() const;
  long GetItemData(long  item ) const;
  bool GetItemPosition(long  item , wxPoint&  pos ) const;
  bool GetItemRect(long item, 
				   wxRect& rect, 
				   int code = wxLIST_RECT_BOUNDS) const;

  bool GetSubItemRect(long item, 
					  long subitem, 
					  wxRect& rect, 
					  int code = wxLIST_RECT_BOUNDS) const;
  int GetItemSpacing(bool  isSmall ) const;
  int GetItemState(long  item , long  stateMask ) const;
  wxString GetItemText(long  item ) const;
  long GetNextItem(long  item , int  geometry = wxLIST_NEXT_ALL, int  state = wxLIST_STATE_DONTCARE) const;
  int GetSelectedItemCount() const;

  wxColour GetTextColour() const;
  long GetTopItem() const;
  wxRect GetViewRect() const;
  long HitTest(const wxPoint&  point , int&  flags ) ;
  long InsertColumn(long  col , wxListItem&  info ) ;
  long InsertColumn(long  col , const wxString&  heading , int  format = wxLIST_FORMAT_LEFT, int  width = -1) ;
  long InsertItem(wxListItem&  info ) ;
  long InsertItem(long  index , const wxString&  label ) ;
  long InsertItem(long  index , int  imageIndex ) ;
  long InsertItem(long  index , const wxString&  label , int  imageIndex ) ;
  void RefreshItem(long item);
  void RefreshItems(long itemFrom, long itemTo);
  bool ScrollList(int  dx , int  dy ) ;
  void SetBackgroundColour(const wxColour&  col ) ;
  bool SetColumn(int  col , wxListItem&  item ) ;
  bool SetColumnWidth(int  col , int  width ) ;
  void SetImageList(wxImageList*  imageList , int  which ) ;
  bool SetItem(wxListItem&  info ) ;
  long SetItem(long  index , int  col , const  wxString& label , int  imageId = -1) ;
  void SetItemBackgroundColour(long item, const wxColour& col);
  void SetItemCount(long  count ) ;
  bool SetItemData(long  item , long  data ) ;
  bool SetItemImage(long  item , int  image , int  selImage ) ;
  bool SetItemPosition(long  item , const wxPoint&  pos ) ;
  bool SetItemState(long  item , long  state , long  stateMask ) ;
  void SetItemText(long  item , const wxString&  text ) ;
  void SetSingleStyle(long  style , const bool  add = true) ;
  void SetTextColour(const wxColour&  col ) ;
  void SetWindowStyleFlag(long  style ) ;
  bool SortItems(wxListCtrlCompare  fnSortCallBack , long  data ) ;
 protected:
  virtual wxListItemAttr* OnGetItemAttr(long item) const;
  virtual int OnGetItemImage(long item) const;
  virtual int OnGetItemColumnImage(long item, long column) const;
  virtual wxString OnGetItemText(long  item, long column) const;
};


#endif
