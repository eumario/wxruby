// wxDocument.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocument_h_)
#define _wxDocument_h_
class wxDocument : public wxEvtHandler
{
public:
	/**
	 * \brief Constructor. Define your own default constructor to initialize application-specific
data. 
	*/

   wxDocument() ;
	/**
	 * \brief Destructor. Removes itself from the document manager. 
	*/

  virtual  ~wxDocument() ;
	/**
	 * \brief If the view is not already in the list of views, adds the view and calls OnChangedViewList. 
	 * \param wxView *  
	*/

  virtual bool AddView(wxView * view ) ;
	/**
	 * \brief Closes the document, by calling OnSaveModified and then (if this returned true) OnCloseDocument.
This does not normally delete the document object: use DeleteAllViews to do this implicitly. 
	*/

  virtual bool Close() ;
	/**
	 * \brief Calls wxView::Close and deletes each view. Deleting the final view will implicitly
delete the document itself, because the wxView destructor calls RemoveView. This
in turns calls wxDocument::OnChangedViewList, whose default implemention is to
save and delete the document if no views exist. 
	*/

  virtual bool DeleteAllViews() ;
	/**
	 * \brief Returns a pointer to the command processor associated with this document.

See  . 
	*/

  wxCommandProcessor* GetCommandProcessor() const;
	/**
	 * \brief Gets a pointer to the template that created the document. 
	*/

  wxDocTemplate* GetDocumentTemplate() const;
	/**
	 * \brief Gets a pointer to the associated document manager. 
	*/

  wxDocManager* GetDocumentManager() const;
	/**
	 * \brief Gets the document type name for this document. See the comment for  . 
	*/

  wxString GetDocumentName() const;
	/**
	 * \brief Intended to return a suitable window for using as a parent for document-related
dialog boxes. By default, uses the frame associated with the first view. 
	*/

  wxWindow* GetDocumentWindow() const;
	/**
	 * \brief Gets the filename associated with this document, or &quot;&quot; if none is
associated. 
	*/

  wxString GetFilename() const;
	/**
	 * \brief A convenience function to get the first view for a document, because
in many cases a document will only have a single view.

See also: 
	*/

  wxView * GetFirstView() const;
	/**
	 * \brief Copies a suitable document name into the supplied   buffer. The default
function uses the title, or if there is no title, uses the filename; or if no
filename, the string  . 
	 * \param wxString&   
	*/

  virtual void GetPrintableName(wxString&  name ) const;
	/**
	 * \brief Gets the title for this document. The document title is used for an associated
frame (if any), and is usually constructed by the framework from
the filename. 
	*/

  wxString GetTitle() const;
	/**
	 * \brief Returns the list whose elements are the views on the document.

See also: 
	*/

  wxList & GetViews() const;
	/**
	 * \brief Returns true if the document has been modified since the last save, false otherwise.
You may need to override this if your document view maintains its own
record of being modified (for example if using wxTextWindow to view and edit the document).

See also  . 
	*/

  virtual bool IsModified() const;
	/**
	 * \brief  
	 * \param istream&   
	*/

  virtual istream& LoadObject(istream&  stream ) ;
	/**
	 * \brief Override this function and call it from your own LoadObject before
streaming your own data. LoadObject is called by the framework
automatically when the document contents need to be loaded.

Note that only one of these forms exists, depending on how wxWindows
was configured. 
	 * \param wxInputStream&   
	*/

  virtual wxInputStream& LoadObject(wxInputStream&  stream ) ;
	/**
	 * \brief Call with true to mark the document as modified since the last save, false otherwise.
You may need to override this if your document view maintains its own
record of being modified (for example if using wxTextWindow to view and edit the document).

See also  . 
	 * \param bool  
	*/

  virtual void Modify(bool  modify ) ;
	/**
	 * \brief Called when a view is added to or deleted from this document. The default
implementation saves and deletes the document if no views exist (the last
one has just been removed). 
	*/

  virtual void OnChangedViewList() ;
	/**
	 * \brief The default implementation calls DeleteContents (an empty implementation)
sets the modified flag to false. Override this to
supply additional behaviour when the document is closed with Close. 
	*/

  virtual bool OnCloseDocument() ;
	/**
	 * \brief Called just after the document object is created to give it a chance
to initialize itself. The default implementation uses the
template associated with the document to create an initial view.
If this function returns false, the document is deleted. 
	 * \param const wxString&   
	 * \param long  
	*/

  virtual bool OnCreate(const wxString&  path , long  flags ) ;
	/**
	 * \brief Override this function if you want a different (or no) command processor
to be created when the document is created. By default, it returns
an instance of wxCommandProcessor.

See  . 
	*/

  virtual wxCommandProcessor* OnCreateCommandProcessor() ;
	/**
	 * \brief The default implementation calls OnSaveModified and DeleteContents, makes a default title for the
document, and notifies the views that the filename (in fact, the title) has changed. 
	*/

  virtual bool OnNewDocument() ;
	/**
	 * \brief Constructs an input file stream for the given filename (which must not be empty),
and calls LoadObject. If LoadObject returns true, the document is set to
unmodified; otherwise, an error message box is displayed. The document's
views are notified that the filename has changed, to give windows an opportunity
to update their titles. All of the document's views are then updated. 
	 * \param const wxString&   
	*/

  virtual bool OnOpenDocument(const wxString&  filename ) ;
	/**
	 * \brief Constructs an output file stream for the given filename (which must not be empty),
and calls SaveObject. If SaveObject returns true, the document is set to
unmodified; otherwise, an error message box is displayed. 
	 * \param const wxString&   
	*/

  virtual bool OnSaveDocument(const wxString&  filename ) ;
	/**
	 * \brief If the document has been modified, prompts the user to ask if the changes should
be changed. If the user replies Yes, the Save function is called. If No, the
document is marked as unmodified and the function succeeds. If Cancel, the
function fails. 
	*/

  virtual bool OnSaveModified() ;
	/**
	 * \brief Removes the view from the document's list of views, and calls OnChangedViewList. 
	 * \param wxView*   
	*/

  virtual bool RemoveView(wxView*  view ) ;
	/**
	 * \brief Saves the document by calling OnSaveDocument if there is an associated filename,
or SaveAs if there is no filename. 
	*/

  virtual bool Save() ;
	/**
	 * \brief Prompts the user for a file to save to, and then calls OnSaveDocument. 
	*/

  virtual bool SaveAs() ;
	/**
	 * \brief  
	 * \param ostream&   
	*/

  virtual ostream& SaveObject(ostream&  stream ) ;
	/**
	 * \brief Override this function and call it from your own SaveObject before
streaming your own data. SaveObject is called by the framework
automatically when the document contents need to be saved.

Note that only one of these forms exists, depending on how wxWindows
was configured. 
	 * \param wxOutputStream&   
	*/

  virtual wxOutputStream& SaveObject(wxOutputStream&  stream ) ;
	/**
	 * \brief Sets the command processor to be used for this document. The document will then be responsible
for its deletion. Normally you should not call this; override OnCreateCommandProcessor
instead.

See  . 
	 * \param wxCommandProcessor *  
	*/

  virtual void SetCommandProcessor(wxCommandProcessor * processor ) ;
	/**
	 * \brief Sets the document type name for this document. See the comment for  . 
	 * \param const wxString&   
	*/

  void SetDocumentName(const wxString&  name ) ;
	/**
	 * \brief Sets the pointer to the template that created the document. Should only be called by the
framework. 
	 * \param wxDocTemplate*   
	*/

  void SetDocumentTemplate(wxDocTemplate*  templ ) ;
	/**
	 * \brief Sets the filename for this document. Usually called by the framework.

If   is true, wxView::OnChangeFilename is called for all views. 
	 * \param const wxString&   
	 * \param bool  
	*/

  void SetFilename(const wxString&  filename , bool notifyViews = false) ;
	/**
	 * \brief Sets the title for this document. The document title is used for an associated
frame (if any), and is usually constructed by the framework from
the filename. 
	 * \param const wxString&   
	*/

  void SetTitle(const wxString&  title ) ;
	/**
	 * \brief Updates all views. If   is non-NULL, does not update this view.

  represents optional information to allow a view to optimize its update. 
	 * \param wxView*   
	 * \param wxObject*  
	*/

  void UpdateAllViews(wxView*  sender = NULL, wxObject* hint = NULL) ;
};


#endif
