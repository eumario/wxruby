// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxBookCtrlBase_h_)
#define _wxBookCtrlBase_h_

class wxBookCtrlBase : public wxControl
{
public:
  wxBookCtrlBase();
  wxBookCtrlBase(wxWindow *parent,
                 wxWindowID winid,
                 const wxPoint& pos = wxDefaultPosition,
                 const wxSize& size = wxDefaultSize,
                 long style = 0,
                 const wxString& name = wxEmptyString);
  bool Create(wxWindow *parent,
              wxWindowID winid,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0,
              const wxString& name = wxEmptyString);

  // dtor
  virtual ~wxBookCtrlBase();

  // get number of pages in the dialog
  virtual size_t GetPageCount() const;

  // get the panel which represents the given page
  wxWindow *GetPage(size_t n);
  wxWindow *GetPage(size_t n) const;

  // get the current page or NULL if none
  wxWindow *GetCurrentPage();
  // get the currently selected page or wxNOT_FOUND if none
  virtual int GetSelection() const = 0;

  // set/get the title of a page
  virtual bool SetPageText(size_t n, const wxString& strText) = 0;
  virtual wxString GetPageText(size_t n) const = 0;

  // sets the image list to use, it is *not* deleted by the control
  virtual void SetImageList(wxImageList *imageList);

  // as SetImageList() but we will delete the image list ourselves
  virtual void AssignImageList(wxImageList *imageList);

  // get pointer (may be NULL) to the associated image list
  wxImageList* GetImageList() const;

  // sets/returns item's image index in the current image list
  virtual int GetPageImage(size_t n) const = 0;
  virtual bool SetPageImage(size_t n, int imageId) = 0;

  virtual void SetPageSize(const wxSize& size);

  // calculate the size of the control from the size of its page
  virtual wxSize CalcSizeFromPage(const wxSize& sizePage) const = 0;

  // get/set size of area between book control area and page area
  unsigned int GetInternalBorder() const;
  void SetInternalBorder(unsigned int border);

  // Sets/gets the margin around the controller
  void SetControlMargin(int margin);
  int GetControlMargin() const;

  // returns true if we have wxBK_TOP or wxBK_BOTTOM style
  bool IsVertical() const;

  // set/get option to shrink to fit current page
  void SetFitToCurrentPage(bool fit);
  bool GetFitToCurrentPage() const;

  // returns the sizer containing the control, if any
  wxSizer* GetControlSizer() const;

  // remove one page from the control and delete it
  virtual bool DeletePage(size_t n);

  // remove one page from the notebook, without deleting it
  virtual bool RemovePage(size_t n);
  // remove all pages and delete them
  virtual bool DeleteAllPages();

  // adds a new page to the control
  virtual bool AddPage(wxWindow *page,
                       const wxString& text,
                       bool bSelect = false,
                       int imageId = -1);
  // the same as AddPage(), but adds the page at the specified position
  virtual bool InsertPage(size_t n,
                          wxWindow *page,
                          const wxString& text,
                          bool bSelect = false,
                          int imageId = -1) = 0;

  // set the currently selected page, return the index of the previously
  // selected one (or -1 on error)
  //
  // NB: this function will generate PAGE_CHANGING/ED events
  virtual int SetSelection(size_t n) = 0;

  // acts as SetSelection but does not generate events
  virtual int ChangeSelection(size_t n) = 0;


  // cycle thru the pages
  void AdvanceSelection(bool forward = true);

  // hit test: returns which page is hit and, optionally, where (icon, label)
  virtual int HitTest(const wxPoint& pt,
                      long * flags = NULL);

  // we do have multiple pages
  virtual bool HasMultiplePages() const;
};

#endif
