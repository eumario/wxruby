// wxXmlResource.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxXmlResource_h_)
#define _wxXmlResource_h_
class wxXmlResource : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	 * \param const wxString&   
	 * \param int   
	*/

   wxXmlResource(const wxString&  filemask , int  flags = wxXRC_USE_LOCALE) ;
	/**
	 * \brief Constructor. 
	 * \param int   
	*/

   wxXmlResource(int  flags = wxXRC_USE_LOCALE) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxXmlResource() ;
	/**
	 * \brief Initializes only a specific handler (or custom handler). Convention says
that the handler name is equal to the control's name plus 'XmlHandler', for example
wxTextCtrlXmlHandler, wxHtmlWindowXmlHandler. The XML resource compiler
(wxxrc) can create include file that contains initialization code for
all controls used within the resource. 
	 * \param wxXmlResourceHandler*   
	*/

  void AddHandler(wxXmlResourceHandler*  handler ) ;
	/**
	 * \brief Attaches an unknown control to the given panel/window/dialog.
Unknown controls are used in conjunction with &lt;object class=&quot;unknown&quot;&gt;. 
	 * \param const wxString&   
	 * \param wxWindow*   
	 * \param wxWindow*   
	*/

  bool AttachUnknownControl(const wxString&  name , wxWindow*  control , wxWindow*  parent = NULL) ;
	/**
	 * \brief Removes all handlers. 
	*/

  void ClearHandlers() ;
	/**
	 * \brief Compares the XRC version to the argument. Returns -1 if the XRC version
is less than the argument, +1 if greater, and 0 if they equal. 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  int CompareVersion(int  major , int  minor , int  release , int  revision ) const;
	/**
	 * \brief Creates a resource from information in the given node. 
	 * \param wxXmlNode*   
	 * \param wxObject*   
	 * \param wxObject*   
	*/

  wxObject* CreateResFromNode(wxXmlNode*  node , wxObject*  parent , wxObject*  instance = NULL) ;
	/**
	 * \brief Helper function: finds a resource (calls UpdateResources) and returns a node containing it. 
	 * \param wxXmlNode*   
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param bool   
	*/

  wxXmlNode* DoFindResource(wxXmlNode*  parent , const wxString&  name , const wxString&  classname , bool  recursive ) ;
	/**
	 * \brief Finds a resource (calls UpdateResources) and returns a node containing it. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param bool   
	*/

  wxXmlNode* FindResource(const wxString&  name , const wxString&  classname , bool  recursive = false) ;
	/**
	 * \brief Gets the global resources object or creates one if none exists. 
	*/

  wxXmlResource* Get() ;
	/**
	 * \brief Returns flags, which may be a bitlist of wxXRC_USE_LOCALE and wxXRC_NO_SUBCLASSING. 
	*/

  int GetFlags() ;
	/**
	 * \brief Returns version information (a.b.c.d = d+ 256&#42;c + 256^2&#42;b + 256\textasciitilde3&#42;a). 
	*/

  long GetVersion() const;
	/**
	 * \brief Returns a numeric ID that is equivalent to the string ID used in an XML
resource. To be used in event tables.
The macro   is provided for convenience. 
	 * \param const wxChar*   
	*/

  int GetXRCID(const wxChar*  str_id ) ;
	/**
	 * \brief Initializes handlers for all supported controls/windows. This will
make the executable quite big because it forces linking against
most of the wxWindows library. 
	*/

  void InitAllHandlers() ;
	/**
	 * \brief Loads resources from XML files that match given filemask.
This method understands VFS (see filesys.h). 
	 * \param const wxString&   
	*/

  bool Load(const wxString&  filemask ) ;
	/**
	 * \brief Loads a bitmap resource from a file. 
	 * \param const wxString&   
	*/

  wxBitmap LoadBitmap(const wxString&  name ) ;
	/**
	 * \brief Loads a dialog.   points to a parent window (if any). 
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  wxDialog* LoadDialog(wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads a dialog.   points to parent window (if any).

This form is used to finish creation of an already existing instance (the main reason
for this is that you may want to use derived class with a new event table).

Example: 
	 * \param wxDialog*   
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  bool LoadDialog(wxDialog*  dlg , wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads a frame. 
	 * \param wxFrame*   
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  bool LoadFrame(wxFrame*  frame , wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads an icon resource from a file. 
	 * \param const wxString&   
	*/

  wxIcon LoadIcon(const wxString&  name ) ;
	/**
	 * \brief Loads menu from resource. Returns NULL on failure. 
	 * \param const wxString&   
	*/

  wxMenu* LoadMenu(const wxString&  name ) ;
	/**
	 * \brief Loads a menubar from resource. Returns NULL on failure. 
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  wxMenuBar* LoadMenuBar(wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads a menubar from resource. Returns NULL on failure. 
	 * \param const wxString&   
	*/

  wxMenuBar* LoadMenuBar(const wxString&  name ) ;
	/**
	 * \brief Loads a panel.   points to parent window (if any). 
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  wxPanel* LoadPanel(wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads a panel.   points to parent window (if any). This form
is used to finish creation of an already existing instance. 
	 * \param wxPanel*   
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  bool LoadPanel(wxPanel*  panel , wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Loads a toolbar. 
	 * \param wxWindow*   
	 * \param const wxString&   
	*/

  wxToolBar* LoadToolBar(wxWindow*  parent , const wxString&  name ) ;
	/**
	 * \brief Sets the global resources object and returns a pointer to the previous one (may be NULL). 
	 * \param wxXmlResource*   
	*/

  wxXmlResource* Set(wxXmlResource*  res ) ;
	/**
	 * \brief Sets flags (bitlist of wxXRC_USE_LOCALE and wxXRC_NO_SUBCLASSING). 
	*/

  int SetFlags() ;
	/**
	 * \brief Scans the resources list for unloaded files and loads them. Also reloads
files that have been modified since the last load. 
	*/

  void UpdateResources() ;
};


#endif
