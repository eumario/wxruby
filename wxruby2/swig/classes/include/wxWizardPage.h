// wxWizardPage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardPage_h_)
#define _wxWizardPage_h_
class wxWizardPage : public wxPanel
{
public:
   wxWizardPage(wxWizard*  parent , const wxBitmap&  bitmap = wxNullBitmap, const wxChar  *resource = NULL) ;
  wxWizardPage* GetPrev() const;
  wxWizardPage* GetNext() const;
  wxBitmap GetBitmap() const;
};


#endif
