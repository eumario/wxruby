// wxDocManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocManager_h_)
#define _wxDocManager_h_
class wxDocManager : public wxEvtHandler
{
public:
	/**
	 * \brief Constructor. Create a document manager instance dynamically near the start of your application
before doing any document or view operations.

  is currently unused.

If   is true, the   function will be called
to create a default history list object. If you derive from wxDocManager, you may wish to call the
base constructor with false, and then call Initialize in your own constructor, to allow
your own Initialize or OnCreateFileHistory functions to be called. 
	 * \param long  
	 * \param bool  
	*/

   wxDocManager(long flags = wxDEFAULT_DOCMAN_FLAGS, bool initialize = true) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDocManager() ;
	/**
	 * \brief Sets the current view. 
	 * \param wxView*   
	 * \param bool  
	 * \param bool  
	*/

  void ActivateView(wxView*  doc , bool  activate , bool  deleting ) ;
	/**
	 * \brief Adds the document to the list of documents. 
	 * \param wxDocument *  
	*/

  void AddDocument(wxDocument * doc ) ;
	/**
	 * \brief Adds a file to the file history list, if we have a pointer to an appropriate file menu. 
	 * \param const wxString&   
	*/

  void AddFileToHistory(const wxString&  filename ) ;
	/**
	 * \brief Adds the template to the document manager's template list. 
	 * \param wxDocTemplate *  
	*/

  void AssociateTemplate(wxDocTemplate * temp ) ;
	/**
	 * \brief Closes all currently opened documents. 
	 * \param bool   
	*/

  bool CloseDocuments(bool  force = true) ;
	/**
	 * \brief Creates a new document in a manner determined by the   parameter, which can be:

 

If wxDOC_NEW is present, a new document will be created and returned, possibly after
asking the user for a template to use if there is more than one document template.
If wxDOC_SILENT is present, a new document will be created and the given file loaded
into it. If neither of these flags is present, the user will be presented with
a file selector for the file to load, and the template to use will be determined by the
extension (Windows) or by popping up a template choice list (other platforms).

If the maximum number of documents has been reached, this function
will delete the oldest currently loaded document before creating a new one. 
	 * \param const wxString&   
	 * \param long  
	*/

  wxDocument* CreateDocument(const wxString&  path , long  flags ) ;
	/**
	 * \brief Creates a new view for the given document. If more than one view is allowed for the
document (by virtue of multiple templates mentioning the same document type), a choice
of view is presented to the user. 
	 * \param wxDocument*  
	 * \param long  
	*/

  wxView* CreateView(wxDocument* doc , long  flags ) ;
	/**
	 * \brief Removes the template from the list of templates. 
	 * \param wxDocTemplate *  
	*/

  void DisassociateTemplate(wxDocTemplate * temp ) ;
	/**
	 * \brief Appends the files in the history list, to all menus managed by the file history object. 
	*/

  void FileHistoryAddFilesToMenu() ;
	/**
	 * \brief Appends the files in the history list, to the given menu only. 
	 * \param wxMenu*  
	*/

  void FileHistoryAddFilesToMenu(wxMenu*  menu ) ;
	/**
	 * \brief Loads the file history from a config object. 
	 * \param wxConfigBase&   
	*/

  void FileHistoryLoad(wxConfigBase&  config ) ;
	/**
	 * \brief Removes the given menu from the list of menus managed by the file history object. 
	 * \param wxMenu*  
	*/

  void FileHistoryRemoveMenu(wxMenu*  menu ) ;
	/**
	 * \brief Saves the file history into a config object. This must be called
explicitly by the application. 
	 * \param wxConfigBase&   
	*/

  void FileHistorySave(wxConfigBase&  resourceFile ) ;
	/**
	 * \brief Use this menu for appending recently-visited document filenames, for convenient
access. Calling this function with a valid menu pointer enables the history
list functionality.

Note that you can add multiple menus using this function, to be managed by the
file history object. 
	 * \param wxMenu*  
	*/

  void FileHistoryUseMenu(wxMenu*  menu ) ;
	/**
	 * \brief Given a path, try to find template that matches the extension. This is only
an approximate method of finding a template for creating a document. 
	 * \param const wxString&   
	*/

  wxDocTemplate * FindTemplateForPath(const wxString&  path ) ;
	/**
	 * \brief Returns the document associated with the currently active view (if any). 
	*/

  wxDocument * GetCurrentDocument() ;
	/**
	 * \brief Returns the currently active view 
	*/

  wxView * GetCurrentView() ;
	/**
	 * \brief Returns a reference to the list of documents. 
	*/

  wxList& GetDocuments() ;
	/**
	 * \brief Returns a pointer to file history. 
	*/

  wxFileHistory * GetFileHistory() ;
	/**
	 * \brief Returns the directory last selected by the user when opening a file. Initially empty. 
	*/

  wxString GetLastDirectory() const;
	/**
	 * \brief Returns the number of documents that can be open simultaneously. 
	*/

  int GetMaxDocsOpen() ;
	/**
	 * \brief Returns the number of files currently stored in the file history. 
	*/

  size_t GetHistoryFilesCount() ;
	/**
	 * \brief Initializes data; currently just calls OnCreateFileHistory. Some data cannot
always be initialized in the constructor because the programmer must be given
the opportunity to override functionality. If OnCreateFileHistory was called
from the constructor, an overridden virtual OnCreateFileHistory would not be
called due to C++'s `interesting' constructor semantics. In fact Initialize
  called from the wxDocManager constructor, but this can be
vetoed by passing false to the second argument, allowing the derived class's
constructor to call Initialize, possibly calling a different OnCreateFileHistory
from the default.

The bottom line: if you're not deriving from Initialize, forget it and
construct wxDocManager with no arguments. 
	*/

  bool Initialize() ;
	/**
	 * \brief Copies a suitable default name into  . This is implemented by
appending an integer counter to the string   and incrementing
the counter. 
	 * \param const wxString&   
	*/

  bool MakeDefaultName(const wxString&  buf ) ;
	/**
	 * \brief A hook to allow a derived class to create a different type of file history. Called
from  . 
	*/

  virtual wxFileHistory * OnCreateFileHistory() ;
	/**
	 * \brief Closes and deletes the currently active document. 
	*/

  virtual void OnFileClose() ;
	/**
	 * \brief Closes and deletes all the currently opened documents. 
	*/

  virtual void OnFileCloseAll() ;
	/**
	 * \brief Creates a document from a list of templates (if more than one template). 
	*/

  virtual void OnFileNew() ;
	/**
	 * \brief Creates a new document and reads in the selected file. 
	*/

  virtual void OnFileOpen() ;
	/**
	 * \brief Saves the current document by calling wxDocument::Save for the current document. 
	*/

  virtual void OnFileSave() ;
	/**
	 * \brief Calls wxDocument::SaveAs for the current document. 
	*/

  virtual void OnFileSaveAs() ;
	/**
	 * \brief Processes menu commands routed from child or parent frames. This deals
with the following predefined menu item identifiers:

 

Unrecognized commands are routed to the currently active wxView's OnMenuCommand. 
	 * \param int  
	*/

  virtual void OnMenuCommand(int  cmd ) ;
	/**
	 * \brief Removes the document from the list of documents. 
	 * \param wxDocument *  
	*/

  void RemoveDocument(wxDocument * doc ) ;
	/**
	 * \brief Under Windows, pops up a file selector with a list of filters corresponding to document templates.
The wxDocTemplate corresponding to the selected file's extension is returned.

On other platforms, if there is more than one document template a choice list is popped up,
followed by a file selector.

This function is used in wxDocManager::CreateDocument.

\perlnote{In wxPerl   is a reference to a list of templates.
If you override this method in your document manager it must return
two values, eg:\par
  (doctemplate, path) = My::DocManager-&gt;SelectDocumentPath( ... );
} 
	 * \param wxDocTemplate **  
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param long  
	 * \param bool  
	*/

  wxDocTemplate * SelectDocumentPath(wxDocTemplate ** templates , int  noTemplates , const wxString&  path , const wxString&  bufSize , long  flags , bool  save ) ;
	/**
	 * \brief Returns a document template by asking the user (if there is more than one template).
This function is used in wxDocManager::CreateDocument.







\perlnote{In wxPerl   is a reference to a list of templates.} 
	 * \param wxDocTemplate **  
	 * \param int  
	 * \param bool  
	*/

  wxDocTemplate * SelectDocumentType(wxDocTemplate ** templates , int  noTemplates , bool sort = false) ;
	/**
	 * \brief Returns a document template by asking the user (if there is more than one template),
displaying a list of valid views. This function is used in wxDocManager::CreateView.
The dialog normally will not appear because the array of templates only contains
those relevant to the document in question, and often there will only be one such.







\perlnote{In wxPerl   is a reference to a list of templates.} 
	 * \param wxDocTemplate **  
	 * \param int  
	 * \param bool  
	*/

  wxDocTemplate * SelectViewType(wxDocTemplate ** templates , int  noTemplates , bool sort = false) ;
	/**
	 * \brief Sets the directory to be displayed to the user when opening a file. Initially this is empty. 
	 * \param const wxString&  
	*/

  void SetLastDirectory(const wxString&  dir ) ;
	/**
	 * \brief Sets the maximum number of documents that can be open at a time. By default, this
is 10,000. If you set it to 1, existing documents will be saved and deleted
when the user tries to open or create a new one (similar to the behaviour
of Windows Write, for example). Allowing multiple documents gives behaviour
more akin to MS Word and other Multiple Document Interface applications. 
	 * \param int  
	*/

  void SetMaxDocsOpen(int  n ) ;
};


#endif
