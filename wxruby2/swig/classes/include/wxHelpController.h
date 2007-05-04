// wxHelpController.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHelpController_h_)
#define _wxHelpController_h_
class wxHelpController : public wxObject
{
public:
   wxHelpController() ;
  virtual  ~wxHelpController() ;
  virtual bool Initialize(const wxString&  file ) ;
  virtual bool Initialize(const wxString&  file , int  server ) ;
  virtual bool DisplayBlock(long  blockNo ) ;
  virtual bool DisplayContents() ;
  virtual bool DisplayContextPopup(int  contextId ) ;
  virtual bool DisplaySection(const wxString&  section ) ;
  virtual bool DisplaySection(int  sectionNo ) ;
  virtual bool DisplayTextPopup(const wxString&  text , const wxPoint&  pos ) ;
  virtual wxFrame * GetFrameParameters(wxSize *  size = NULL, wxPoint *  pos = NULL, bool * newFrameEachTime = NULL) ;
  virtual wxWindow* GetParentWindow();
  virtual bool KeywordSearch(const wxString&  keyWord ) ;
  virtual bool LoadFile(const wxString&  file = wxT("")) ;
  virtual void OnQuit() ;
  virtual void SetFrameParameters(const wxString &  title , const wxSize &  size , const wxPoint &  pos = wxDefaultPosition, bool  newFrameEachTime = false) ;
  virtual void SetParentWindow(wxWindow* win);
  virtual void SetViewer(const wxString&  viewer , long  flags ) ;
  virtual bool Quit() ;
};


#endif
