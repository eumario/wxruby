// wxListbook.h

#if !defined(_wxListbook_h_)
#define _wxListbook_h_
class wxListbook : public wxBookCtrlBase
{
 public:
  wxListbook();

  wxListbook(wxWindow *parent,
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


  // overridden base class methods
  virtual int GetSelection() const;
  virtual bool SetPageText(size_t n, const wxString& strText);
  int GetPageCount() const;
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
  virtual int HitTest(const wxPoint& pt, long *flags = NULL) const;
  virtual void AssignImageList(wxImageList *imageList);
  virtual void SetImageList(wxImageList *imageList);
  bool RemovePage(int page);
  virtual bool DeleteAllPages();

  wxListView* GetListView() const;
};


#endif
