// wxDocManager.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocManager_h_)
#define _wxDocManager_h_
class wxDocManager : public wxEvtHandler
{
public:
   wxDocManager(long flags = wxDEFAULT_DOCMAN_FLAGS, bool initialize = true) ;
  virtual  ~wxDocManager() ;
  void ActivateView(wxView*  doc , bool  activate , bool  deleting ) ;
  void AddDocument(wxDocument * doc ) ;
  void AddFileToHistory(const wxString&  filename ) ;
  void AssociateTemplate(wxDocTemplate * temp ) ;
  bool CloseDocuments(bool  force = true) ;
  wxDocument* CreateDocument(const wxString&  path , long  flags ) ;
  wxView* CreateView(wxDocument* doc , long  flags ) ;
  void DisassociateTemplate(wxDocTemplate * temp ) ;
  void FileHistoryAddFilesToMenu() ;
  void FileHistoryAddFilesToMenu(wxMenu*  menu ) ;
  void FileHistoryLoad(wxConfigBase&  config ) ;
  void FileHistoryRemoveMenu(wxMenu*  menu ) ;
  void FileHistorySave(wxConfigBase&  resourceFile ) ;
  void FileHistoryUseMenu(wxMenu*  menu ) ;
  wxDocTemplate * FindTemplateForPath(const wxString&  path ) ;
  wxDocument * GetCurrentDocument() ;
  wxView * GetCurrentView() ;
  wxList& GetDocuments() ;
  wxFileHistory * GetFileHistory() ;
  wxString GetLastDirectory() const;
  int GetMaxDocsOpen() ;
  size_t GetHistoryFilesCount() ;
  bool Initialize() ;
  bool MakeDefaultName(const wxString&  buf ) ;
  virtual wxFileHistory * OnCreateFileHistory() ;
  virtual void OnFileClose() ;
  virtual void OnFileCloseAll() ;
  virtual void OnFileNew() ;
  virtual void OnFileOpen() ;
  virtual void OnFileSave() ;
  virtual void OnFileSaveAs() ;
  virtual void OnMenuCommand(int  cmd ) ;
  void RemoveDocument(wxDocument * doc ) ;
  wxDocTemplate * SelectDocumentPath(wxDocTemplate ** templates , int  noTemplates , const wxString&  path , const wxString&  bufSize , long  flags , bool  save ) ;
  wxDocTemplate * SelectDocumentType(wxDocTemplate ** templates , int  noTemplates , bool sort = false) ;
  wxDocTemplate * SelectViewType(wxDocTemplate ** templates , int  noTemplates , bool sort = false) ;
  void SetLastDirectory(const wxString&  dir ) ;
  void SetMaxDocsOpen(int  n ) ;
};


#endif
