// wxNotebook.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNotebook_h_)
#define _wxNotebook_h_
class wxNotebook : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxNotebook() ;
	/**
	 * \brief Constructs a notebook control.

Note that sometimes you can reduce flicker by passing the wxCLIP_CHILDREN window style. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

  wxNotebook(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString&  name = wxT("notebook"));
	/**
	 * \brief Destroys the wxNotebook object. 
	*/

  virtual  ~wxNotebook() ;
	/**
	 * \brief Adds a new page. 
	 * \param wxNotebookPage*  
	 * \param const wxString&  
	 * \param bool  
	 * \param int  
	*/

  bool AddPage(wxNotebookPage*  page , const wxString&  text , bool select = false, int imageId = -1) ;
	/**
	 * \brief Cycles through the tabs. 
	 * \param bool  
	*/

  void AdvanceSelection(bool forward = true) ;
	/**
	 * \brief Sets the image list for the page control and takes ownership of
the list. 
	 * \param wxImageList*  
	*/

  void AssignImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Creates a notebook control. See   for a description
of the parameters. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize&  size , long style , const wxString&  name = wxT("notebook"));
	/**
	 * \brief Deletes all pages. 
	*/

  bool DeleteAllPages() ;
	/**
	 * \brief Deletes the specified page, and the associated window. 
	 * \param int  
	*/

  bool DeletePage(int  page ) ;
	/**
	 * \brief  
	*/

  wxImageList* GetImageList() const;
	/**
	 * \brief Returns the window at the given page position. 
	 * \param int  
	*/

  wxNotebookPage* GetPage(int  page ) ;
	/**
	 * \brief Returns the number of pages in the notebook control. 
	*/

  int GetPageCount() const;
	/**
	 * \brief Returns the image index for the given page. 
	 * \param int   
	*/

  int GetPageImage(int  nPage ) const;
	/**
	 * \brief Returns the string for the given page. 
	 * \param int   
	*/

  wxString GetPageText(int  nPage ) const;
	/**
	 * \brief Returns the number of rows in the notebook control. 
	*/

  int GetRowCount() const;
	/**
	 * \brief Returns the currently selected page, or $-1$ if none was selected.

Note that this method may return either the previously or newly selected page
when called from the   handler depending on
the platform and so
  should be
used instead in this case. 
	*/

  int GetSelection() const;
	/**
	 * \brief Inserts a new page at the specified position. 
	 * \param int  
	 * \param wxNotebookPage*  
	 * \param const wxString&  
	 * \param bool  
	 * \param int  
	*/

  bool InsertPage(int  index , wxNotebookPage*  page , const wxString&  text , bool select = false, int imageId = -1) ;
	/**
	 * \brief An event handler function, called when the page selection is changed. 
	 * \param wxNotebookEvent&  
	*/

  virtual void OnSelChange(wxNotebookEvent&  event ) ;
	/**
	 * \brief Deletes the specified page, without deleting the associated window. 
	 * \param int  
	*/

  bool RemovePage(int  page ) ;
	/**
	 * \brief Sets the image list for the page control. It does not take
ownership of the image list, you must delete it yourself. 
	 * \param wxImageList*  
	*/

  void SetImageList(wxImageList*  imageList ) ;
	/**
	 * \brief Sets the amount of space around each page's icon and label, in pixels.

  The vertical padding cannot be changed in wxGTK. 
	 * \param const wxSize&  
	*/

  void SetPadding(const wxSize&  padding ) ;
	/**
	 * \brief Sets the width and height of the pages.

  This method is currently not implemented for wxGTK. 
	 * \param const wxSize&  
	*/

  void SetPageSize(const wxSize&  size ) ;
	/**
	 * \brief Sets the image index for the given page.   is an index into
the image list which was set with  . 
	 * \param int  
	 * \param int   
	*/

  bool SetPageImage(int  page , int  image ) ;
	/**
	 * \brief Sets the text for the given page. 
	 * \param int  
	 * \param const wxString&   
	*/

  bool SetPageText(int  page , const wxString&  text ) ;
	/**
	 * \brief Sets the selection for the given page, returning the previous selection. 
	 * \param int  
	*/

  int SetSelection(int  page ) ;
};


#endif
