// wxDocTemplate.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocTemplate_h_)
#define _wxDocTemplate_h_
class wxDocTemplate : public wxObject
{
public:
	/**
	 * \brief Constructor. Create instances dynamically near the start of your application after creating
a wxDocManager instance, and before doing any document or view operations.

  is the document manager object which manages this template.

  is a short description of what the template is for. This string will be displayed in the
file filter list of Windows file selectors.

  is an appropriate file filter such as  .

  is the default directory to use for file selectors.

  is the default file extension (such as txt).

  is a name that should be unique for a given type of document, used for
gathering a list of views relevant to a particular document.

  is a name that should be unique for a given view.

  is a pointer to the run-time document class information as returned
by the CLASSINFO macro, e.g. CLASSINFO(MyDocumentClass). If this is not supplied,
you will need to derive a new wxDocTemplate class and override the CreateDocument
member to return a new document instance on demand.

  is a pointer to the run-time view class information as returned
by the CLASSINFO macro, e.g. CLASSINFO(MyViewClass). If this is not supplied,
you will need to derive a new wxDocTemplate class and override the CreateView
member to return a new view instance on demand.

  is a bit list of the following:

 

\perlnote{In wxPerl   and   can be
either   objects or strings which contain the name
of the perl packages which are to be used as   and
  classes (they must have a constructor named  ):\par
\indented{2cm}{ }} 
	 * \param wxDocManager*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxClassInfo*   
	 * \param wxClassInfo*   
	 * \param long  
	*/

   wxDocTemplate(wxDocManager*  manager , const wxString&  descr , const wxString&  filter , const wxString&  dir , const wxString&  ext , const wxString&  docTypeName , const wxString&  viewTypeName , wxClassInfo*  docClassInfo = NULL, wxClassInfo*  viewClassInfo = NULL, long flags = wxDEFAULT_TEMPLATE_FLAGS) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDocTemplate() ;
	/**
	 * \brief Creates a new instance of the associated document class. If you have not supplied
a wxClassInfo parameter to the template constructor, you will need to override this
function to return an appropriate document instance. 
	 * \param const wxString&   
	 * \param long  
	*/

  wxDocument * CreateDocument(const wxString&  path , long flags = 0) ;
	/**
	 * \brief Creates a new instance of the associated view class. If you have not supplied
a wxClassInfo parameter to the template constructor, you will need to override this
function to return an appropriate view instance. 
	 * \param wxDocument *  
	 * \param long  
	*/

  wxView * CreateView(wxDocument * doc , long flags = 0) ;
	/**
	 * \brief Returns the default file extension for the document data, as passed to the document template constructor. 
	*/

  wxString GetDefaultExtension() ;
	/**
	 * \brief Returns the text description of this template, as passed to the document template constructor. 
	*/

  wxString GetDescription() ;
	/**
	 * \brief Returns the default directory, as passed to the document template constructor. 
	*/

  wxString GetDirectory() ;
	/**
	 * \brief Returns a pointer to the document manager instance for which this template was created. 
	*/

  wxDocManager * GetDocumentManager() ;
	/**
	 * \brief Returns the document type name, as passed to the document template constructor. 
	*/

  wxString GetDocumentName() ;
	/**
	 * \brief Returns the file filter, as passed to the document template constructor. 
	*/

  wxString GetFileFilter() ;
	/**
	 * \brief Returns the flags, as passed to the document template constructor. 
	*/

  long GetFlags() ;
	/**
	 * \brief Returns the view type name, as passed to the document template constructor. 
	*/

  wxString GetViewName() ;
	/**
	 * \brief Returns true if the document template can be shown in user dialogs, false otherwise. 
	*/

  bool IsVisible() ;
	/**
	 * \brief Sets the default file extension. 
	 * \param const wxString&   
	*/

  void SetDefaultExtension(const wxString&  ext ) ;
	/**
	 * \brief Sets the template description. 
	 * \param const wxString&   
	*/

  void SetDescription(const wxString&  descr ) ;
	/**
	 * \brief Sets the default directory. 
	 * \param const wxString&   
	*/

  void SetDirectory(const wxString&  dir ) ;
	/**
	 * \brief Sets the pointer to the document manager instance for which this template was created.
Should not be called by the application. 
	 * \param wxDocManager *  
	*/

  void SetDocumentManager(wxDocManager * manager ) ;
	/**
	 * \brief Sets the file filter. 
	 * \param const wxString&   
	*/

  void SetFileFilter(const wxString&  filter ) ;
	/**
	 * \brief Sets the internal document template flags (see the constructor description for more details). 
	 * \param long   
	*/

  void SetFlags(long  flags ) ;
};


#endif
