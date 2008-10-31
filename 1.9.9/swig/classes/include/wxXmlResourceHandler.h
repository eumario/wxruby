// wxXmlResourceHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxXmlResourceHandler_h_)
#define _wxXmlResourceHandler_h_
class wxXmlResourceHandler : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxXmlResourceHandler() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxXmlResourceHandler() ;
	/**
	 * \brief Add a style flag (e.g. wxMB_DOCKABLE) to the list of flags
understood by this handler. 
	 * \param const wxString&   
	 * \param int   
	*/

  void AddStyle(const wxString&  name , int  value ) ;
	/**
	 * \brief Add styles common to all wxWindow-derived classes. 
	*/

  void AddWindowStyles() ;
	/**
	 * \brief Returns true if it understands this node and can create
a resource from it, false otherwise. 
	 * \param wxXmlNode*   
	*/

  bool CanHandle(wxXmlNode*  node ) ;
	/**
	 * \brief Creates children. 
	 * \param wxObject*   
	 * \param bool   
	*/

  void CreateChildren(wxObject*  parent , bool  this_hnd_only = false) ;
	/**
	 * \brief Helper function. 
	 * \param wxObject*   
	 * \param wxXmlNode*   
	*/

  void CreateChildrenPrivately(wxObject*  parent , wxXmlNode*  rootnode = NULL) ;
	/**
	 * \brief Creates a resource from a node. 
	 * \param wxXmlNode*   
	 * \param wxObject*   
	 * \param wxObject*   
	*/

  wxObject* CreateResFromNode(wxXmlNode*  node , wxObject*  parent , wxObject*  instance = NULL) ;
	/**
	 * \brief Creates an object (menu, dialog, control, ...) from an XML node.
Should check for validity.   is a higher-level object (usually window, dialog or panel)
that is often necessary to create the resource.
If   is non-NULL it should not create a new instance via 'new' but
should rather use this one, and call its Create method. 
	 * \param wxXmlNode*   
	 * \param wxObject*   
	 * \param wxObject*   
	*/

  wxObject* CreateResource(wxXmlNode*  node , wxObject*  parent , wxObject*  instance ) ;
	/**
	 * \brief Called from CreateResource after variables
were filled. 
	*/

  wxObject* DoCreateResource() ;
	/**
	 * \brief Gets a bitmap. 
	 * \param const wxString&   
	 * \param wxSize   
	*/

  wxBitmap GetBitmap(const wxString&  param = wxT(wxT("bitmap")), wxSize  size = wxDefaultSize) ;
	/**
	 * \brief Gets a bool flag (1, t, yes, on, true are true, everything else is false). 
	 * \param const wxString&   
	 * \param bool   
	*/

  bool GetBool(const wxString&  param , bool  defaultv = false) ;
	/**
	 * \brief Gets colour in HTML syntax (\#RRGGBB). 
	 * \param const wxString&   
	*/

  wxColour GetColour(const wxString&  param ) ;
	/**
	 * \brief Returns the current file system. 
	*/

  wxFileSystem& GetCurFileSystem() ;
	/**
	 * \brief Gets a dimension (may be in dialog units). 
	 * \param const wxString&   
	 * \param wxCoord   
	*/

  wxCoord GetDimension(const wxString&  param , wxCoord  defaultv = 0) ;
	/**
	 * \brief Gets a font. 
	 * \param const wxString&   
	*/

  wxFont GetFont(const wxString&  param = wxT(wxT("font"))) ;
	/**
	 * \brief Returns the XRCID. 
	*/

  int GetID() ;
	/**
	 * \brief Returns an icon. 
	 * \param const wxString&   
	 * \param wxSize   
	*/

  wxIcon GetIcon(const wxString&  param = wxT(wxT("icon")), wxSize  size = wxDefaultSize) ;
	/**
	 * \brief Gets the integer value from the parameter. 
	 * \param const wxString&   
	 * \param long   
	*/

  long GetLong(const wxString&  param , long  defaultv = 0) ;
	/**
	 * \brief Returns the resource name. 
	*/

  wxString GetName() ;
	/**
	 * \brief Gets node content from wxXML_ENTITY_NODE. 
	 * \param wxXmlNode*   
	*/

  wxString GetNodeContent(wxXmlNode*  node ) ;
	/**
	 * \brief Finds the node or returns NULL. 
	 * \param const wxString&   
	*/

  wxXmlNode* GetParamNode(const wxString&  param ) ;
	/**
	 * \brief Finds the parameter value or returns the empty string. 
	 * \param const wxString&   
	*/

  wxString GetParamValue(const wxString&  param ) ;
	/**
	 * \brief Gets the position (may be in dialog units). 
	 * \param const wxString&   
	*/

  wxPoint GetPosition(const wxString&  param = wxT(wxT("pos"))) ;
	/**
	 * \brief Gets the size (may be in dialog units). 
	 * \param const wxString&   
	*/

  wxSize GetSize(const wxString&  param = wxT(wxT("size"))) ;
	/**
	 * \brief Gets style flags from text in form &quot;flag | flag2| flag3 |...&quot;
Only understands flags added with AddStyle. 
	 * \param const wxString&   
	 * \param int   
	*/

  int GetStyle(const wxString&  param = wxT(wxT("style")), int  defaults = 0) ;
	/**
	 * \brief Gets text from param and does some conversions: 
	 * \param const wxString&   
	*/

  wxString GetText(const wxString&  param ) ;
	/**
	 * \brief Check to see if a parameter exists. 
	 * \param const wxString&   
	*/

  bool HasParam(const wxString&  param ) ;
	/**
	 * \brief Convenience function. Returns true if the node has a property class equal to classname,
e.g. &lt;object class=&quot;wxDialog&quot;&gt;. 
	 * \param wxXmlNode*   
	 * \param const wxString&   
	*/

  bool IsOfClass(wxXmlNode*  node , const wxString&  classname ) ;
	/**
	 * \brief Sets the parent resource. 
	 * \param wxXmlResource*   
	*/

  void SetParentResource(wxXmlResource*  res ) ;
	/**
	 * \brief Sets common window options. 
	 * \param wxWindow*   
	*/

  void SetupWindow(wxWindow*  wnd ) ;
};


#endif
