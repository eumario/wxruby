// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxToolbook_h_)
#define _wxToolbook_h_

class wxToolbook : public wxBookCtrlBase
{
 public:
  wxToolbook();
  wxToolbook(wxWindow *parent,
             wxWindowID id,
             const wxPoint& pos = wxDefaultPosition,
             const wxSize& size = wxDefaultSize,
             long style = 0,
             const wxString& name = wxEmptyString);
  // quasi ctor
  bool Create(wxWindow *parent,
              wxWindowID id,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0,
              const wxString& name = wxEmptyString);


  // implement base class virtuals
  virtual int GetSelection() const;
  int GetPageCount() const;
  virtual bool SetPageText(size_t n, const wxString& strText);
  virtual wxString GetPageText(size_t n) const;
  virtual int GetPageImage(size_t n) const;
  virtual bool SetPageImage(size_t n, int imageId);
  virtual wxSize CalcSizeFromPage(const wxSize& sizePage) const;
  virtual bool AddPage(wxWindow *page,
                       const wxString& text,
                       bool bSelect = false,
                       int imageId = -1);
  virtual bool InsertPage(size_t n,
                          wxWindow *page,
                          const wxString& text,
                          bool bSelect = false,
                          int imageId = -1);
  virtual int SetSelection(size_t n);
  virtual int ChangeSelection(size_t n);

  virtual void AssignImageList(wxImageList *imageList);
  virtual void SetImageList(wxImageList *imageList);

  virtual bool DeleteAllPages();
  bool RemovePage(int page);
  virtual int HitTest(const wxPoint& pt, long *flags = NULL) const;


  // methods which are not part of base wxBookctrl API

  // get the underlying toolbar
  wxToolBarBase* GetToolBar();

  // must be called in OnIdle or by application to realize the toolbar and
  // select the initial page.
  void Realize();
};

#endif
