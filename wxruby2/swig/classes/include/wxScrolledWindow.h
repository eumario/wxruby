// wxScrolledWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScrolledWindow_h_)
#define _wxScrolledWindow_h_
class wxScrolledWindow : public wxPanel
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxScrolledWindow() ;
	/**
	 * \brief Constructor. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxScrolledWindow(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxHSCROLL, const wxString&  name = wxT("scrolledWindow")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxScrolledWindow() ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int *  
	 * \param int *  
	*/

  void CalcScrolledPosition(int  x , int  y , int * xx , int * yy ) const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	 * \param int *  
	 * \param int *  
	*/

  void CalcUnscrolledPosition(int  x , int  y , int * xx , int * yy ) const;
	/**
	 * \brief Creates the window for two-step construction. Derived classes
should call or replace this function. See  
for details. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxHSCROLL, const wxString&  name = wxT("scrolledWindow")) ;
	/**
	 * \brief Enable or disable physical scrolling in the given direction. Physical
scrolling is the physical transfer of bits up or down the
screen when a scroll event occurs. If the application scrolls by a
variable amount (e.g. if there are different font sizes) then physical
scrolling will not work, and you should switch it off. Note that you
will have to reposition child windows yourself, if physical scrolling
is disabled. 
	 * \param const bool  
	 * \param const bool  
	*/

  void EnableScrolling(const bool  xScrolling , const bool  yScrolling ) ;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetScrollPixelsPerUnit(int*  xUnit , int*  yUnit ) const;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetViewStart(int*  x , int*   y ) const;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetVirtualSize(int*  x , int*  y ) const;
	/**
	 * \brief Motif only: true if the window has a backing bitmap. 
	*/

  bool IsRetained() const;
	/**
	 * \brief Call this function to prepare the device context for drawing a scrolled image. It
sets the device origin according to the current scroll position.

PrepareDC is called automatically within the default wxScrolledWindow::OnPaint event
handler, so your   override
will be passed a 'pre-scrolled' device context. However, if you wish to draw from
outside of OnDraw (via OnPaint), or you wish to implement OnPaint yourself, you must
call this function yourself. For example: 
	 * \param wxDC&   
	*/

  void PrepareDC(wxDC&  dc ) ;
	/**
	 * \brief Called by the default paint event handler to allow the application to define
painting behaviour without having to worry about calling
 .

Instead of overriding this function you may also just process the paint event
in the derived class as usual, but then you will have to call PrepareDC()
yourself. 
	 * \param wxDC&   
	*/

  virtual void OnDraw(wxDC&  dc ) ;
	/**
	 * \brief Scrolls a window so the view start is at the given point. 
	 * \param int  
	 * \param int  
	*/

  void Scroll(int  x , int  y ) ;
	/**
	 * \brief Sets up vertical and/or horizontal scrollbars. 
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int  
	 * \param int   
	 * \param int  
	 * \param bool   
	*/

  void SetScrollbars(int  pixelsPerUnitX , int  pixelsPerUnitY , int  noUnitsX , int  noUnitsY , int  xPos = 0, int yPos = 0, bool  noRefresh = false) ;
	/**
	 * \brief Set the horizontal and vertical scrolling increment only. See the pixelsPerUnit
parameter in SetScrollbars. 
	 * \param int  
	 * \param int  
	*/

  void SetScrollRate(int  xstep , int  ystep ) ;
	/**
	 * \brief Call this function to tell wxScrolledWindow to perform the actual scrolling on
a different window (and not on itself). 
	 * \param wxWindow*   
	*/

  void SetTargetWindow(wxWindow*  window ) ;
};


#endif
