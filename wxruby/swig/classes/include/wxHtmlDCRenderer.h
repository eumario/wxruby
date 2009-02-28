// wxHtmlDCRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlDCRenderer_h_)
#define _wxHtmlDCRenderer_h_
class wxHtmlDCRenderer : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlDCRenderer() ;
	/**
	 * \brief Assign DC instance to the renderer.

  can be used when rendering to high-resolution DCs (e.g. printer) to adjust size of pixel metrics.
(Many dimensions in HTML are given in pixels -- e.g. image sizes. 300x300 image would be only one
inch wide on typical printer. With pixel_scale = 3.0 it would be 3 inches.) 
	 * \param wxDC*   
	 * \param double   
	*/

  void SetDC(wxDC*  dc , double  pixel_scale = 1.0) ;
	/**
	 * \brief Sets fonts. See   for
detailed description.

See also  . 
	 * \param wxString   
	 * \param wxString   
	 * \param const int   
	*/

  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
	/**
	 * \brief Set size of output rectangle, in pixels. Note that you   change
width of the rectangle between calls to  !
(You can freely change height.) 
	 * \param int   
	 * \param int   
	*/

  void SetSize(int  width , int  height ) ;
	/**
	 * \brief Assign text to the renderer.   then draws 
the text onto DC. 
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param bool   
	*/

  void SetHtmlText(const wxString&  html , const wxString&  basepath = wxEmptyString, bool  isdir = true) ;
	/**
	 * \brief Renders HTML text to the DC.









Returned value is y coordinate of first cell than didn't fit onto page.
Use this value as   in next call to Render in order to print multipages
document.

\wxheading{Caution!}

The Following three methods   always be called before any call to Render (preferably
in this order): 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

  int Render(int  x , int  y , int  from = 0, int  dont_render = false) ;
	/**
	 * \brief Returns the height of the HTML text. This is important if area height (see  )
is smaller that total height and thus the page cannot fit into it. In that case you're supposed to
call   as long as its return value is smaller than GetTotalHeight's. 
	*/

  int GetTotalHeight() ;
};


#endif
