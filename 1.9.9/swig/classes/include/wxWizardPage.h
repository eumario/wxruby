// wxWizardPage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardPage_h_)
#define _wxWizardPage_h_
class wxWizardPage : public wxPanel
{
public:
	/**
	 * \brief Constructor accepts an optional bitmap which will be used for this page
instead of the default one for this wizard (note that all bitmaps used should
be of the same size). Notice that no other parameters are needed because the
wizard will resize and reposition the page anyhow. 
	 * \param wxWizard*   
	 * \param const wxBitmap&   
	 * \param const wxChar   
	*/

   wxWizardPage(wxWizard*  parent , const wxBitmap&  bitmap = wxNullBitmap, const wxChar  *resource = NULL) ;
	/**
	 * \brief Get the page which should be shown when the user chooses the  
button: if   is returned, this button will be disabled. The first
page of the wizard will usually return   from here, but the others
will not. 
	*/

  wxWizardPage* GetPrev() const;
	/**
	 * \brief Get the page which should be shown when the user chooses the  
button: if   is returned, this button will be disabled. The last
page of the wizard will usually return   from here, but the others
will not. 
	*/

  wxWizardPage* GetNext() const;
	/**
	 * \brief This method is called by wxWizard to get the bitmap to display alongside the
page. By default,   member variable which was set in the 
 .

If the bitmap was not explicitly set (i.e. if   is returned),
the default bitmap for the wizard should be used.

The only cases when you would want to override this function is if the page
bitmap depends dynamically on the user choices, i.e. almost never. 
	*/

  wxBitmap GetBitmap() const;
};


#endif
