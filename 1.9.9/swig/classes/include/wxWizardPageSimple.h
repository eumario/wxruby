// wxWizardPageSimple.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardPageSimple_h_)
#define _wxWizardPageSimple_h_
class wxWizardPageSimple : public wxWizardPage
{
public:
	/**
	 * \brief Constructor takes the previous and next pages. They may be modified later by
  or 
 . 
	 * \param wxWizard*   
	 * \param wxWizardPage*   
	 * \param wxWizardPage*   
	 * \param const wxBitmap&   
	*/

   wxWizardPageSimple(wxWizard*  parent = NULL, wxWizardPage*  prev = NULL, wxWizardPage*  next = NULL, const wxBitmap&  bitmap = wxNullBitmap) ;
	/**
	 * \brief Sets the previous page. 
	 * \param wxWizardPage*   
	*/

  void SetPrev(wxWizardPage*  prev ) ;
	/**
	 * \brief Sets the next page. 
	 * \param wxWizardPage*   
	*/

  void SetNext(wxWizardPage*  next ) ;
	/**
	 * \brief A convenience function to make the pages follow each other.

Example: 
	 * \param wxWizardPageSimple*   
	 * \param wxWizardPageSimple*   
	*/

  static void Chain(wxWizardPageSimple*  first , wxWizardPageSimple*  second ) ;
};


#endif
