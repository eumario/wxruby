// wxView.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxView_h_)
#define _wxView_h_
class wxView : public wxEvtHandler
{
public:
   wxView() ;
  virtual  ~wxView() ;
  virtual void Activate(bool  activate ) ;
  virtual bool Close(bool deleteWindow = true) ;
  wxDocument* GetDocument() const;
  wxDocumentManager* GetDocumentManager() const;
  wxWindow * GetFrame() ;
  wxString GetViewName() const;
  virtual void OnActivateView(bool  activate , wxView * activeView , wxView * deactiveView ) ;
  virtual void OnChangeFilename() ;
  virtual bool OnClose(bool  deleteWindow ) ;
  virtual void OnClosingDocument() ;
  virtual bool OnCreate(wxDocument*  doc , long  flags ) ;
  virtual wxPrintout* OnCreatePrintout() ;
  virtual void OnUpdate(wxView*  sender , wxObject*  hint ) ;
  void SetDocument(wxDocument*  doc ) ;
  void SetFrame(wxWindow*  frame ) ;
  void SetViewName(const wxString&  name ) ;
};


#endif
