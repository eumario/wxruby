// wxWizard.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizard_h_)
#define _wxWizard_h_
class wxWizard : public wxDialog
{
public:
   wxWizard() ;
   wxWizard(wxWindow*  parent , int  id = -1, const wxString&  title = wxEmptyString, const wxBitmap&  bitmap = wxNullBitmap, const wxPoint&  pos = wxDefaultPosition) ;
  bool Create(wxWindow*  parent , int  id = -1, const wxString&  title = wxEmptyString, const wxBitmap&  bitmap = wxNullBitmap, const wxPoint&  pos = wxDefaultPosition) ;
  void FitToPage(const wxWizardPage*  firstPage ) ;
  wxWizardPage* GetCurrentPage() const;
  wxSize GetPageSize() const;
  virtual bool HasNextPage(wxWizardPage * page ) ;
  virtual bool HasPrevPage(wxWizardPage * page ) ;
  bool RunWizard(wxWizardPage*  firstPage ) ;
  void SetPageSize(const wxSize&  sizePage ) ;
};


#endif
