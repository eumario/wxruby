// wxWizard.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizard_h_)
#define _wxWizard_h_
class wxWizard : public wxDialog
{
public:
	/**
	 * \brief Default constructor. Use this if you wish to derive from wxWizard and then call 
 , for example if you wish to set an extra style
with   between the two
calls. 
	*/

   wxWizard() ;
	/**
	 * \brief Constructor which really creates the wizard -- if you use this constructor, you
shouldn't call  .

Notice that unlike almost all other wxWindows classes, there is no   
parameter in wxWizard constructor because the wizard will have a predefined
default size by default. If you want to change this, you should use the 
  function. 
	 * \param wxWindow*   
	 * \param int   
	 * \param const wxString&   
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	*/

   wxWizard(wxWindow*  parent , int  id = -1, const wxString&  title = wxEmptyString, const wxBitmap&  bitmap = wxNullBitmap, const wxPoint&  pos = wxDefaultPosition) ;
	/**
	 * \brief Creates the wizard dialog. Must be called if the default constructor had been
used to create the object.

Notice that unlike almost all other wxWindows classes, there is no   
parameter in wxWizard constructor because the wizard will have a predefined
default size by default. If you want to change this, you should use the 
  function. 
	 * \param wxWindow*   
	 * \param int   
	 * \param const wxString&   
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	*/

  bool Create(wxWindow*  parent , int  id = -1, const wxString&  title = wxEmptyString, const wxBitmap&  bitmap = wxNullBitmap, const wxPoint&  pos = wxDefaultPosition) ;
	/**
	 * \brief Sets the page size to be big enough for all the pages accessible via the
given  , i.e. this page, its next page and so on.

This method may be called more than once and it will only change the page size
if the size required by the new page is bigger than the previously set one.
This is useful if the decision about which pages to show is taken during the
run-time as in this case, the wizard won't be able to get to all pages starting
from a single one and you should call   separately for the others. 
	 * \param const wxWizardPage*   
	*/

  void FitToPage(const wxWizardPage*  firstPage ) ;
	/**
	 * \brief Get the current page while the wizard is running.   is returned if 
  is not being executed now. 
	*/

  wxWizardPage* GetCurrentPage() const;
	/**
	 * \brief Returns the size available for the pages. 
	*/

  wxSize GetPageSize() const;
	/**
	 * \brief Return   if this page is not the last one in the wizard. The base
class version implements this by calling 
  but this could be undesirable if,
for example, the pages are created on demand only. 
	 * \param wxWizardPage *  
	*/

  virtual bool HasNextPage(wxWizardPage * page ) ;
	/**
	 * \brief Return   if this page is not the last one in the wizard. The base
class version implements this by calling 
  but this could be undesirable if,
for example, the pages are created on demand only. 
	 * \param wxWizardPage *  
	*/

  virtual bool HasPrevPage(wxWizardPage * page ) ;
	/**
	 * \brief Executes the wizard starting from the given page, returns   if it was
successfully finished or   if user cancelled it. The   
can not be  . 
	 * \param wxWizardPage*   
	*/

  bool RunWizard(wxWizardPage*  firstPage ) ;
	/**
	 * \brief Sets the minimal size to be made available for the wizard pages. The wizard
will take into account the size of the bitmap (if any) itself. Also, the
wizard will never be smaller than the default size.

The recommended way to use this function is to layout all wizard pages using
the sizers (even though the wizard is not resizeable) and then use 
  in a loop to calculate the maximum
of minimal sizes of the pages and pass it to SetPageSize(). 
	 * \param const wxSize&   
	*/

  void SetPageSize(const wxSize&  sizePage ) ;
};


#endif
