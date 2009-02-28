// wxTabCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTabCtrl_h_)
#define _wxTabCtrl_h_
class wxTabCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxTabCtrl() ;
	/**
	 * \brief Constructs a tab control. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxTabCtrl(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size , long style = 0, const wxString&  name = wxT("tabCtrl")) ;
	/**
	 * \brief Destroys the wxTabCtrl object. 
	*/

  virtual  ~wxTabCtrl() ;
	/**
	 * \brief Creates a tab control. See   for a description
of the parameters. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize&  size , long style = 0, const wxString&  name = wxT("tabCtrl")) ;
	/**
	 * \brief Deletes all tab items. 
	*/

  bool DeleteAllItems() ;
	/**
	 * \brief Deletes the specified tab item. 
	 * \param int  
	*/

  bool DeleteItem(int  item ) ;
	/**
	 * \brief Returns the index for the tab with the focus, or -1 if none has the focus. 
	*/

  int GetCurFocus() const;
	/**
	 * \brief  
	*/

  wxImageList* GetImageList() const;
	/**
	 * \brief Returns the number of tabs in the tab control. 
	*/

  int GetItemCount() const;
	/**
	 * \brief Returns the client data for the given tab. 
	*/

  void* GetItemData() const;
	/**
	 * \brief Returns the image index for the given tab. 
	*/

  int GetItemImage() const;
	/**
	 * \brief Returns the rectangle bounding the given tab. 
	 * \param int   
	 * \param wxRect&  
	*/

  bool GetItemRect(int  item , wxRect&  rect ) const;
	/**
	 * \brief Returns the string for the given tab. 
	*/

  wxString GetItemText() const;
	/**
	 * \brief Returns the number of rows in the tab control. 
	*/

  int GetRowCount() const;
	/**
	 * \brief Returns the index for the currently selected tab. 
	*/

  int GetSelection() const;
	/**
	 * \brief Tests whether a tab is at the specified position. 
	 * \param const wxPoint&  
	 * \param long&  
	*/

  int HitTest(const wxPoint&  pt , long&  flags ) ;
	/**
	 * \brief Inserts a new tab. 
	 * \param int  
	 * \param const wxString&  
	 * \param int   
	 * \param void*  
	*/

  void InsertItem(int  item , const wxString&  text , int  imageId = -1, void* clientData = NULL) ;
	/**
	 * \brief Sets the client data for a tab. 
	 * \param int  
	 * \param void*  
	*/

  bool SetItemData(int  item , void*  data ) ;
	/**
	 * \brief Sets the image index for the given tab.   is an index into
the image list which was set with  . 
	 * \param int  
	 * \param int   
	*/

  bool SetItemImage(int  item , int  image ) ;
	/**
	 * \brief Sets the image list for the tab control. 
	 * \param wxImageList*  
	*/

  void SetImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the width and height of the tabs. 
	 * \param const wxSize&  
	*/

  void SetItemSize(const wxSize&  size ) ;
	/**
	 * \brief Sets the text for the given tab. 
	 * \param int  
	 * \param const wxString&   
	*/

  bool SetItemText(int  item , const wxString&  text ) ;
	/**
	 * \brief Sets the amount of space around each tab's icon and label. 
	 * \param const wxSize&  
	*/

  void SetPadding(const wxSize&  padding ) ;
	/**
	 * \brief Sets the selection for the given tab, returning the index of the previously
selected tab. Returns -1 if the call was unsuccessful. 
	 * \param int  
	*/

  int SetSelection(int  item ) ;
};


#endif
