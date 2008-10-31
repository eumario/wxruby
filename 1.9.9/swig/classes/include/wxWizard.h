// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxWizard_h_)
#define _wxWizard_h_
class wxWizard : public wxDialog
{
public:
   wxWizard() ;
   wxWizard(wxWindow* parent, 
            int id = -1, 
            const wxString& title = wxEmptyString, 
            const wxBitmap& bitmap = wxNullBitmap, 
            const wxPoint& pos = wxDefaultPosition,
            long style = wxDEFAULT_DIALOG_STYLE);
  bool Create(wxWindow* parent, 
              int id = -1, 
              const wxString& title = wxEmptyString, 
              const wxBitmap& bitmap = wxNullBitmap, 
              const wxPoint& pos = wxDefaultPosition, 
              long style = wxDEFAULT_DIALOG_STYLE);
  void FitToPage(const wxWizardPage* firstPage);
  const wxBitmap& GetBitmap() const;
  wxWizardPage* GetCurrentPage() const;
  wxSize GetPageSize() const;
  virtual wxSizer* GetPageAreaSizer() const;
  virtual bool HasNextPage(wxWizardPage * page);
  virtual bool HasPrevPage(wxWizardPage * page);
  bool RunWizard(wxWizardPage* firstPage);
  void SetBitmap(const wxBitmap& bitmap);
  void SetBorder(int border);
  void SetPageSize(const wxSize& sizePage);
};


#endif
