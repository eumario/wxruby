// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGLCanvas_h_)
#define _wxGLCanvas_h_
class wxGLCanvas : public wxWindow
{
public:

	wxGLCanvas(wxWindow*  parent , wxWindowID id = -1, const wxPoint&  pos  = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;

  wxGLCanvas(wxWindow*  parent , wxGLCanvas*  sharedCanvas = NULL, wxWindowID id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;

  wxGLCanvas(wxWindow*  parent , wxGLContext*  sharedContext = NULL, wxWindowID id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;

  void SetCurrent() ;

  void SetColour(const wxChar*  colour ) ;

  void SwapBuffers() ;
};


#endif
