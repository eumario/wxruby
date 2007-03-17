// wxPlotCurve.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPlotCurve_h_)
#define _wxPlotCurve_h_
class wxPlotCurve : public wxObject
{
public:
	/**
	 * \brief Constructor assigning start values. See below for interpretation. 
	 * \param int   
	 * \param double   
	 * \param double   
	*/

   wxPlotCurve(int  offsetY , double  startY , double  endY ) ;
	/**
	 * \brief Must be overridden. This function should return the index of the last value
of this curve, typically 99 if 100 values have been measured. 
	*/

  wxInt32 GetEndX() ;
	/**
	 * \brief See  . 
	*/

  double GetEndY() ;
	/**
	 * \brief Returns the vertical offset. 
	*/

  int GetOffsetY() ;
	/**
	 * \brief Must be overridden. This function will return the actual Y value corresponding
to the given X value. The x value is of an integer type because it is considered
to be an index in row of measured values. 
	 * \param wxInt32   
	*/

  double GetY(wxInt32  x ) ;
	/**
	 * \brief Must be overridden. This function should return the index of the first value
of this curve, typically zero. 
	*/

  wxInt32 GetStartX() ;
	/**
	 * \brief See  . 
	*/

  double GetStartY() ;
	/**
	 * \brief The value returned by this function tells the plot window what the highest values
in the curve will be so that a suitable scale can be found for the display. If
the Y values in this curve are in the range of -1.5 to 0.5, this function should
return 0.5 or maybe 1.0 for nicer aesthetics. 
	 * \param double   
	*/

  void SetEndY(double  endY ) ;
	/**
	 * \brief When displaying several curves in one window, it is often useful to assign
different offsets to the curves. You should call   
to set this value after you have added the curve to the window. 
	 * \param int   
	*/

  void SetOffsetY(int  offsetY ) ;
	/**
	 * \brief The value returned by this function tells the plot window what the lowest values
in the curve will be so that a suitable scale can be found for the display. If
the Y values in this curve are in the range of -1.5 to 0.5, this function should
return -1.5 or maybe -2.0 for nicer aesthetics. 
	 * \param double   
	*/

  void SetStartY(double  startY ) ;
};


#endif
