// wxXmlResourceHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxXmlResourceHandler_h_)
#define _wxXmlResourceHandler_h_
class wxXmlResourceHandler : public wxObject
{
public:
   wxXmlResourceHandler() ;
  virtual  ~wxXmlResourceHandler() ;
  void AddStyle(const wxString&  name , int  value ) ;
  void AddWindowStyles() ;
  bool CanHandle(wxXmlNode*  node ) ;
  void CreateChildren(wxObject*  parent , bool  this_hnd_only = false) ;
  void CreateChildrenPrivately(wxObject*  parent , wxXmlNode*  rootnode = NULL) ;
  wxObject* CreateResFromNode(wxXmlNode*  node , wxObject*  parent , wxObject*  instance = NULL) ;
  wxObject* CreateResource(wxXmlNode*  node , wxObject*  parent , wxObject*  instance ) ;
  wxObject* DoCreateResource() ;
  wxBitmap GetBitmap(const wxString&  param = wxT("bitmap"), wxSize  size = wxDefaultSize) ;
  bool GetBool(const wxString&  param , bool  defaultv = false) ;
  wxColour GetColour(const wxString&  param ) ;
  wxFileSystem& GetCurFileSystem() ;
  wxCoord GetDimension(const wxString&  param , wxCoord  defaultv = 0) ;
  wxFont GetFont(const wxString&  param = wxT("font")) ;
  int GetID() ;
  wxIcon GetIcon(const wxString&  param = wxT("icon"), wxSize  size = wxDefaultSize) ;
  long GetLong(const wxString&  param , long  defaultv = 0) ;
  wxString GetName() ;
  wxString GetNodeContent(wxXmlNode*  node ) ;
  wxXmlNode* GetParamNode(const wxString&  param ) ;
  wxString GetParamValue(const wxString&  param ) ;
  wxPoint GetPosition(const wxString&  param = wxT("pos")) ;
  wxSize GetSize(const wxString&  param = wxT("size")) ;
  int GetStyle(const wxString&  param = wxT("style"), int  defaults = 0) ;
  wxString GetText(const wxString&  param ) ;
  bool HasParam(const wxString&  param ) ;
  bool IsOfClass(wxXmlNode*  node , const wxString&  classname ) ;
  void SetParentResource(wxXmlResource*  res ) ;
  void SetupWindow(wxWindow*  wnd ) ;
};


#endif
