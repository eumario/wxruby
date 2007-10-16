// Copyright 2004-2007, wxRuby development team
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
  wxWizardPage* GetCurrentPage() const;
  wxSize GetPageSize() const;
  virtual bool HasNextPage(wxWizardPage * page ) ;
  virtual bool HasPrevPage(wxWizardPage * page ) ;
  bool RunWizard(wxWizardPage*  firstPage ) ;
  void SetPageSize(const wxSize&  sizePage ) ;
};


#endif
