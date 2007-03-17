// wxView.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxView_h_)
#define _wxView_h_
class wxView : public wxEvtHandler
{
public:
	/**
	 * \brief Constructor. Define your own default constructor to initialize application-specific
data. 
	*/

   wxView() ;
	/**
	 * \brief Destructor. Removes itself from the document's list of views. 
	*/

  virtual  ~wxView() ;
	/**
	 * \brief Call this from your view frame's OnActivate member to tell the framework which view is
currently active. If your windowing system doesn't call OnActivate, you may need to
call this function from OnMenuCommand or any place where you know the view must
be active, and the framework will need to get the current view.

The prepackaged view frame wxDocChildFrame calls wxView::Activate from its OnActivate member
and from its OnMenuCommand member.

This function calls wxView::OnActivateView. 
	 * \param bool  
	*/

  virtual void Activate(bool  activate ) ;
	/**
	 * \brief Closes the view by calling OnClose. If   is true, this function should
delete the window associated with the view. 
	 * \param bool  
	*/

  virtual bool Close(bool deleteWindow = true) ;
	/**
	 * \brief Gets a pointer to the document associated with the view. 
	*/

  wxDocument* GetDocument() const;
	/**
	 * \brief Returns a pointer to the document manager instance associated with this view. 
	*/

  wxDocumentManager* GetDocumentManager() const;
	/**
	 * \brief Gets the frame associated with the view (if any). Note that this ``frame'' is
not a wxFrame at all in the generic MDI implementation which uses the notebook
pages instead of the frames and this is why this method returns a wxWindow and
not a wxFrame. 
	*/

  wxWindow * GetFrame() ;
	/**
	 * \brief Gets the name associated with the view (passed to the wxDocTemplate constructor).
Not currently used by the framework. 
	*/

  wxString GetViewName() const;
	/**
	 * \brief Called when a view is activated by means of wxView::Activate. The default implementation does
nothing. 
	 * \param bool   
	 * \param wxView *  
	 * \param wxView *  
	*/

  virtual void OnActivateView(bool  activate , wxView * activeView , wxView * deactiveView ) ;
	/**
	 * \brief Called when the filename has changed. The default implementation constructs a
suitable title and sets the title of the view frame (if any). 
	*/

  virtual void OnChangeFilename() ;
	/**
	 * \brief Implements closing behaviour. The default implementation calls wxDocument::Close
to close the associated document. Does not delete the view. The application
may wish to do some cleaning up operations in this function,   a
call to wxDocument::Close succeeded. For example, if your application's
all share the same window, you need to disassociate the window from the view
and perhaps clear the window. If   is true, delete the
frame associated with the view. 
	 * \param bool  
	*/

  virtual bool OnClose(bool  deleteWindow ) ;
	/**
	 * \brief Override this to clean up the view when the document is being
closed. 
	*/

  virtual void OnClosingDocument() ;
	/**
	 * \brief wxDocManager or wxDocument creates a wxView via a wxDocTemplate.
Just after the wxDocTemplate creates the wxView, it calls
wxView::OnCreate. In its OnCreate member function, the wxView can create a wxDocChildFrame
or a derived class. This wxDocChildFrame provides user interface
elements to view and/or edit the contents of the wxDocument.

By default, simply returns true. If the function returns false, the
view will be deleted. 
	 * \param wxDocument*   
	 * \param long  
	*/

  virtual bool OnCreate(wxDocument*  doc , long  flags ) ;
	/**
	 * \brief If the printing framework is enabled in the library, this function returns a
  object for the purposes of printing. It should create a new object
every time it is called; the framework will delete objects it creates.

By default, this function returns an instance of wxDocPrintout, which prints
and previews one page by calling wxView::OnDraw.

Override to return an instance of a class other than wxDocPrintout. 
	*/

  virtual wxPrintout* OnCreatePrintout() ;
	/**
	 * \brief Called when the view should be updated.   is a pointer to the view
that sent the update request, or NULL if no single view requested the update (for instance,
when the document is opened).   is as yet unused but may in future contain
application-specific information for making updating more efficient. 
	 * \param wxView*   
	 * \param wxObject*   
	*/

  virtual void OnUpdate(wxView*  sender , wxObject*  hint ) ;
	/**
	 * \brief Associates the given document with the view. Normally called by the
framework. 
	 * \param wxDocument*   
	*/

  void SetDocument(wxDocument*  doc ) ;
	/**
	 * \brief Sets the frame associated with this view. The application should call this
if possible, to tell the view about the frame.

See   for the explanation about the mismatch
between the ``Frame'' in the method name and the type of its parameter. 
	 * \param wxWindow*   
	*/

  void SetFrame(wxWindow*  frame ) ;
	/**
	 * \brief Sets the view type name. Should only be called by the framework. 
	 * \param const wxString&   
	*/

  void SetViewName(const wxString&  name ) ;
};


#endif
