// wxLogWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLogWindow_h_)
#define _wxLogWindow_h_
class wxLogWindow : public wxLogPassThrough
{
public:
   wxLogWindow(wxFrame  *parent , const wxChar  *title , bool  show = true, bool  passToOld = true) ;
  void Show(bool  show = true) ;
  wxFrame * GetFrame() const;
  virtual void OnFrameCreate(wxFrame  *frame ) ;
  virtual void OnFrameClose(wxFrame  *frame ) ;
  virtual void OnFrameDelete(wxFrame  *frame ) ;
};


#endif
