// wxGLCanvas.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGLCanvas_h_)
#define _wxGLCanvas_h_
class wxGLCanvas : public wxWindow
{
public:
   wxGLCanvas(wxWindow*  parent , wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = "GLCanvas", int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
   wxGLCanvas(wxWindow*  parent , wxGLCanvas*  sharedCanvas = NULL, wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = "GLCanvas", int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
   wxGLCanvas(wxWindow*  parent , wxGLContext*  sharedContext = NULL, wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = "GLCanvas", int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
  void SetCurrent() ;
  void SetColour(const char*  colour ) ;
  void SwapBuffers() ;
};


#endif
