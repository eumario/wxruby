// wxDocument.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocument_h_)
#define _wxDocument_h_
class wxDocument : public wxEvtHandler
{
public:
   wxDocument() ;
  virtual  ~wxDocument() ;
  virtual bool AddView(wxView * view ) ;
  virtual bool Close() ;
  virtual bool DeleteAllViews() ;
  wxCommandProcessor* GetCommandProcessor() const;
  wxDocTemplate* GetDocumentTemplate() const;
  wxDocManager* GetDocumentManager() const;
  wxString GetDocumentName() const;
  wxWindow* GetDocumentWindow() const;
  wxString GetFilename() const;
  wxView * GetFirstView() const;
  virtual void GetPrintableName(wxString&  name ) const;
  wxString GetTitle() const;
  wxList & GetViews() const;
  virtual bool IsModified() const;
  virtual istream& LoadObject(istream&  stream ) ;
  virtual wxInputStream& LoadObject(wxInputStream&  stream ) ;
  virtual void Modify(bool  modify ) ;
  virtual void OnChangedViewList() ;
  virtual bool OnCloseDocument() ;
  virtual bool OnCreate(const wxString&  path , long  flags ) ;
  virtual wxCommandProcessor* OnCreateCommandProcessor() ;
  virtual bool OnNewDocument() ;
  virtual bool OnOpenDocument(const wxString&  filename ) ;
  virtual bool OnSaveDocument(const wxString&  filename ) ;
  virtual bool OnSaveModified() ;
  virtual bool RemoveView(wxView*  view ) ;
  virtual bool Save() ;
  virtual bool SaveAs() ;
  virtual ostream& SaveObject(ostream&  stream ) ;
  virtual wxOutputStream& SaveObject(wxOutputStream&  stream ) ;
  virtual void SetCommandProcessor(wxCommandProcessor * processor ) ;
  void SetDocumentName(const wxString&  name ) ;
  void SetDocumentTemplate(wxDocTemplate*  templ ) ;
  void SetFilename(const wxString&  filename , bool notifyViews = false) ;
  void SetTitle(const wxString&  title ) ;
  void UpdateAllViews(wxView*  sender = NULL, wxObject* hint = NULL) ;
};


#endif
