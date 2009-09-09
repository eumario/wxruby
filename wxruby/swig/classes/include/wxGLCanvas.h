// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGLCanvas_h_)
#define _wxGLCanvas_h_

class wxGLCanvas : public wxWindow
{
public:
  // The following constructor is the recommended one
  // but is unavailable for OS X.
  /*
  wxGLCanvas(wxWindow *parent, 
              wxWindowID id = wxID_ANY,
              int* attribList = 0,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0,
              const wxString&  name = wxT("GLCanvas"), 
              const wxPalette& palette = wxNullPalette);
  */

  // The following constructor is the preferred one at the moment
  wxGLCanvas(wxWindow* parent, 
               wxWindowID id = wxID_ANY, 
               const wxPoint& pos = wxDefaultPosition, 
               const wxSize&  size = wxDefaultSize, 
               long style = 0, 
               const wxString&  name = wxT("GLCanvas"), 
               int* attribList = 0, 
               const wxPalette& palette = wxNullPalette) ;

  // Deprecated constructors
  /*
  wxGLCanvas(wxWindow* parent, 
               wxGLCanvas* sharedCanvas = NULL, 
               wxWindowID id = wxID_ANY, 
               const wxPoint& pos = wxDefaultPosition, 
               const wxSize& size = wxDefaultSize, 
               long style = 0, const wxString&  name = wxT("GLCanvas"), 
               int* attribList = 0, 
               const wxPalette& palette = wxNullPalette);
  wxGLCanvas(wxWindow* parent, 
               wxGLContext* sharedContext = NULL, 
               wxWindowID id = wxID_ANY, 
               const wxPoint& pos = wxDefaultPosition, 
               const wxSize& size = wxDefaultSize, 
               long style = 0, 
               const wxString& name = wxT("GLCanvas"), 
               int* attribList = 0, 
               const wxPalette& palette = wxNullPalette);
  */

  // Unavailable for OS X.
  /*
  void SetCurrent(const wxGLContext& RC) const; 
  */
  void SetCurrent();
  void SetColour(const wxChar*  colour );
  void SwapBuffers();
};


#endif
