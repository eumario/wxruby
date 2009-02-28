// wxPlotWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPlotWindow_h_)
#define _wxPlotWindow_h_
class wxPlotWindow : public wxScrolledWindow
{
public:
	/**
	 * \brief  
	*/

   wxPlotWindow() ;
	/**
	 * \brief Constructor. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param int   
	*/

   wxPlotWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  flags = wxPLOT_DEFAULT) ;
	/**
	 * \brief The destructor will not delete the curves associated to the window. 
	*/

  virtual  ~wxPlotWindow() ;
	/**
	 * \brief Add a curve to the window. 
	 * \param wxPlotCurve*   
	*/

  void Add(wxPlotCurve*  curve ) ;
	/**
	 * \brief Returns number of curves. 
	*/

  size_t GetCount() ;
	/**
	 * \brief Get the nth curve. 
	 * \param size_t   
	*/

  wxPlotCurve* GetAt(size_t  n ) ;
	/**
	 * \brief Make one curve the current curve. This will emit a wxPlotEvent. 
	 * \param wxPlotCurve*   
	*/

  void SetCurrent(wxPlotCurve*  current ) ;
	/**
	 * \brief Returns a pointer to the current curve, or NULL. 
	*/

  wxPlotCurve* GetCurrent() ;
	/**
	 * \brief Removes a curve from the window and delete is on screen. This does not
delete the actual curve. If the curve removed was the current curve,
the current curve will be set to NULL. 
	 * \param wxPlotCurve*   
	*/

  void Delete(wxPlotCurve*  curve ) ;
	/**
	 * \brief Move the curve   up by   pixels. Down if the
value is negative. 
	 * \param wxPlotCurve*   
	 * \param int   
	*/

  void Move(wxPlotCurve*  curve , int  pixels_up ) ;
	/**
	 * \brief Changes the representation of the given curve. A   of more than
one will stretch the curve vertically. The Y axis will change accordingly. 
	 * \param wxPlotCurve*   
	 * \param double   
	*/

  void Enlarge(wxPlotCurve*  curve , double  factor ) ;
	/**
	 * \brief This sets the virtual units per value. Normally, you will not be interested in
what measured value you see, but what it stands for. If you want to display seconds
on the X axis and the measuring device produced 50 values per second, set this
value to 50. This will affect all curves being displayed. 
	 * \param double   
	*/

  void SetUnitsPerValue(double  upv ) ;
	/**
	 * \brief See  . 
	*/

  double GetUnitsPerValue() ;
	/**
	 * \brief This functions zooms all curves in their horizontal dimension. The X axis will
be changed accordingly. 
	 * \param double   
	*/

  void SetZoom(double  zoom ) ;
	/**
	 * \brief See  . 
	*/

  double GetZoom() ;
	/**
	 * \brief Helper function which redraws both axes and the central area. 
	*/

  void RedrawEverything() ;
	/**
	 * \brief Helper function which redraws the X axis. 
	*/

  void RedrawXAxis() ;
	/**
	 * \brief Helper function which redraws the Y axis. 
	*/

  void RedrawYAxis() ;
	/**
	 * \brief This function controls if the plot area will get scrolled only if the scrollbar thumb
has been release or also if the thumb is being dragged. When displaying large amounts
of data, it might become impossible to display the data fast enough to produce smooth
scrolling and then this function should be called. 
	 * \param bool  
	*/

  void SetScrollOnThumbRelease(bool onrelease = true) ;
	/**
	 * \brief Depending on the kind of data you display, enlarging the individual curves might
have different desired effects. Sometimes, the data will be supposed to get enlarged
with the fixed point being the origin, sometimes the fixed point should be the centre
of the current drawing area. This function controls this behaviour. 
	 * \param bool  
	*/

  void SetEnlargeAroundWindowCentre(bool aroundwindow = true) ;
};


#endif
