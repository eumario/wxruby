// wxDocTemplate.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocTemplate_h_)
#define _wxDocTemplate_h_
class wxDocTemplate : public wxObject
{
public:
   wxDocTemplate(wxDocManager*  manager , const wxString&  descr , const wxString&  filter , const wxString&  dir , const wxString&  ext , const wxString&  docTypeName , const wxString&  viewTypeName , wxClassInfo*  docClassInfo = NULL, wxClassInfo*  viewClassInfo = NULL, long flags = wxDEFAULT_TEMPLATE_FLAGS) ;
  virtual  ~wxDocTemplate() ;
  wxDocument * CreateDocument(const wxString&  path , long flags = 0) ;
  wxView * CreateView(wxDocument * doc , long flags = 0) ;
  wxString GetDefaultExtension() ;
  wxString GetDescription() ;
  wxString GetDirectory() ;
  wxDocManager * GetDocumentManager() ;
  wxString GetDocumentName() ;
  wxString GetFileFilter() ;
  long GetFlags() ;
  wxString GetViewName() ;
  bool IsVisible() ;
  void SetDefaultExtension(const wxString&  ext ) ;
  void SetDescription(const wxString&  descr ) ;
  void SetDirectory(const wxString&  dir ) ;
  void SetDocumentManager(wxDocManager * manager ) ;
  void SetFileFilter(const wxString&  filter ) ;
  void SetFlags(long  flags ) ;
};


#endif
