// wxWizardPageSimple.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardPageSimple_h_)
#define _wxWizardPageSimple_h_
class wxWizardPageSimple : public wxWizardPage
{
public:
   wxWizardPageSimple(wxWizard*  parent = NULL, wxWizardPage*  prev = NULL, wxWizardPage*  next = NULL, const wxBitmap&  bitmap = wxNullBitmap) ;
  void SetPrev(wxWizardPage*  prev ) ;
  void SetNext(wxWizardPage*  next ) ;
  static void Chain(wxWizardPageSimple*  first , wxWizardPageSimple*  second ) ;
};


#endif
