// wxGLCanvas.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGLCanvas_h_)
#define _wxGLCanvas_h_
class wxGLCanvas : public wxWindow
{
public:
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	 * \param int*  
	 * \param const wxPalette&  
	*/

   wxGLCanvas(wxWindow*  parent , wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxGLCanvas*   
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	 * \param int*  
	 * \param const wxPalette&  
	*/

   wxGLCanvas(wxWindow*  parent , wxGLCanvas*  sharedCanvas = NULL, wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
	/**
	 * \brief Constructor. 
	 * \param wxWindow*   
	 * \param wxGLContext*   
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	 * \param int*  
	 * \param const wxPalette&  
	*/

   wxGLCanvas(wxWindow*  parent , wxGLContext*  sharedContext = NULL, wxWindowID id = -1, const wxPoint&  pos , const wxSize&  size , long style = 0, const wxString&  name = wxT("GLCanvas"), int* attribList = 0, const wxPalette& palette = wxNullPalette) ;
	/**
	 * \brief Sets this canvas as the current recipient of OpenGL calls.
Each canvas contain an OpenGL device context that has been created during
the creation of this window. So this call sets the current device context
as the target device context for OpenGL operations. 
	*/

  void SetCurrent() ;
	/**
	 * \brief Sets the current colour for this window, using the wxWindows colour database to find a named colour. 
	 * \param const char*  
	*/

  void SetColour(const char*  colour ) ;
	/**
	 * \brief Displays the previous OpenGL commands on the window. 
	*/

  void SwapBuffers() ;
};


#endif
