// wxTabCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTabCtrl_h_)
#define _wxTabCtrl_h_
class wxTabCtrl : public wxControl
{
public:
   wxTabCtrl() ;
   wxTabCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size , long style = 0, const wxString&  name = "tabCtrl") ;
  virtual  ~wxTabCtrl() ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size , long style = 0, const wxString&  name = "tabCtrl") ;
  bool DeleteAllItems() ;
  bool DeleteItem(int  item ) ;
  int GetCurFocus() const;
  wxImageList* GetImageList() const;
  int GetItemCount() const;
  void* GetItemData() const;
  int GetItemImage() const;
  bool GetItemRect(int  item , wxRect&  rect ) const;
  wxString GetItemText() const;
  int GetRowCount() const;
  int GetSelection() const;
  int HitTest(const wxPoint&  pt , long&  flags ) ;
  void InsertItem(int  item , const wxString&  text , int  imageId = -1, void* clientData = NULL) ;
  bool SetItemData(int  item , void*  data ) ;
  bool SetItemImage(int  item , int  image ) ;
  void SetImageList(wxImageList*  imageList ) ;
  void SetItemSize(const wxSize&  size ) ;
  bool SetItemText(int  item , const wxString&  text ) ;
  void SetPadding(const wxSize&  padding ) ;
  int SetSelection(int  item ) ;
};


#endif
