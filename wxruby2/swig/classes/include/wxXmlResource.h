// wxXmlResource.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxXmlResource_h_)
#define _wxXmlResource_h_
class wxXmlResource : public wxObject
{
public:
   wxXmlResource(const wxString&  filemask , int  flags = wxXRC_USE_LOCALE) ;
   wxXmlResource(int  flags = wxXRC_USE_LOCALE) ;
  virtual  ~wxXmlResource() ;
  void AddHandler(wxXmlResourceHandler*  handler ) ;
  bool AttachUnknownControl(const wxString&  name , wxWindow*  control , wxWindow*  parent = NULL) ;
  void ClearHandlers() ;
  int CompareVersion(int  major , int  minor , int  release , int  revision ) const;
  wxObject* CreateResFromNode(wxXmlNode*  node , wxObject*  parent , wxObject*  instance = NULL) ;
  wxXmlNode* DoFindResource(wxXmlNode*  parent , const wxString&  name , const wxString&  classname , bool  recursive ) ;
  wxXmlNode* FindResource(const wxString&  name , const wxString&  classname , bool  recursive = false) ;
  wxXmlResource* Get() ;
  int GetFlags() ;
  long GetVersion() const;
  int GetXRCID(const wxChar*  str_id ) ;
  void InitAllHandlers() ;
  bool Load(const wxString&  filemask ) ;
  wxBitmap LoadBitmap(const wxString&  name ) ;
  wxDialog* LoadDialog(wxWindow*  parent , const wxString&  name ) ;
  bool LoadDialog(wxDialog*  dlg , wxWindow*  parent , const wxString&  name ) ;
  bool LoadFrame(wxFrame*  frame , wxWindow*  parent , const wxString&  name ) ;
  wxIcon LoadIcon(const wxString&  name ) ;
  wxMenu* LoadMenu(const wxString&  name ) ;
  wxMenuBar* LoadMenuBar(wxWindow*  parent , const wxString&  name ) ;
  wxMenuBar* LoadMenuBar(const wxString&  name ) ;
  wxPanel* LoadPanel(wxWindow*  parent , const wxString&  name ) ;
  bool LoadPanel(wxPanel*  panel , wxWindow*  parent , const wxString&  name ) ;
  wxToolBar* LoadToolBar(wxWindow*  parent , const wxString&  name ) ;
  wxXmlResource* Set(wxXmlResource*  res ) ;
  int SetFlags() ;
  void UpdateResources() ;
};


#endif
