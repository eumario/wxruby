// wxDocChildFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDocChildFrame_h_)
#define _wxDocChildFrame_h_
class wxDocChildFrame : public wxFrame
{
public:
   wxDocChildFrame(wxDocument*  doc , wxView*  view , wxFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = "frame") ;
  virtual  ~wxDocChildFrame() ;
  wxDocument* GetDocument() const;
  wxView* GetView() const;
  virtual void OnActivate(wxActivateEvent  event ) ;
  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
  void SetDocument(wxDocument * doc ) ;
  void SetView(wxView * view ) ;
};


#endif
