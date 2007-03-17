// wxScreenDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScreenDC_h_)
#define _wxScreenDC_h_
class wxScreenDC : public wxDC
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxScreenDC() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	*/

  bool StartDrawingOnTop(wxWindow*  window ) ;
	/**
	 * \brief Use this in conjunction with   to
ensure that drawing to the screen occurs on top of existing windows. Without this,
some window systems (such as X) only allow drawing to take place underneath
other windows.

By using the first form of this function, an application is specifying that
the area that will be drawn on coincides with the given window.

By using the second form, an application can specify an area of the screen
which is to be drawn on. If NULL is passed, the whole screen is available.

It is recommended that an area of the screen is specified because with large regions,
flickering effects are noticeable when destroying the temporary transparent window used
to implement this feature.

You might use this pair of functions when implementing a drag feature, for example
as in the   implementation. 
	 * \param wxRect*  
	*/

  bool StartDrawingOnTop(wxRect* rect = NULL) ;
	/**
	 * \brief Use this in conjunction with  .

This function destroys the temporary window created to implement on-top drawing (X only). 
	*/

  bool EndDrawingOnTop() ;
};


#endif
