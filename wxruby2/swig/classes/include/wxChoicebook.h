// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxChoicebook_h_)
#define _wxChoicebook_h_

class wxChoicebook : public wxBookCtrlBase
{
 public:
  wxChoicebook();
  wxChoicebook(wxWindow *parent,
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


  virtual int GetSelection() const;
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

  // returns the choice control
  wxChoice* GetChoiceCtrl() const;
};


#endif
