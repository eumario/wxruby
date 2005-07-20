// wxDC.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDC_h_)
#define _wxDC_h_
class wxDC : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxDC() ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxDC() ;
	/**
	 * \brief Allows optimization of drawing code under MS Windows. Enclose
drawing primitives between   and  
calls.

Drawing to a wxDialog panel device context outside of a
system-generated OnPaint event   this pair of calls to
enclose drawing code. This is because a Windows dialog box does not have
a retained device context associated with it, and selections such as pen
and brush settings would be lost if the device context were obtained and
released for each drawing operation. 
	*/

  void BeginDrawing() ;
	/**
	 * \brief  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxDC*   
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param int  
	 * \param bool   
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  bool Blit(wxCoord  xdest , wxCoord  ydest , wxCoord  width , wxCoord  height , wxDC*  source , wxCoord  xsrc , wxCoord  ysrc , int logicalFunc = wxCOPY, bool  useMask = false, wxCoord xsrcMask = -1, wxCoord ysrcMask = -1)  = 0;
	/**
	 * \brief  
	*/

  static bool CacheEnabled() ;
	/**
	 * \brief Adds the specified point to the bounding box which can be retrieved with 
 ,   and 
 ,   functions. 
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  void CalcBoundingBox(wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Clears the device context using the current background brush.

\begin{comment} 
	*/

  void Clear()  = 0;
	/**
	 * \brief  
	*/

  static void ClearCache() ;
	/**
	 * \brief Displays a cross hair using the current pen. This is a vertical
and horizontal line the height and width of the window, centred
on the given point. 
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void CrossHair(wxCoord  x , wxCoord  y )  = 0;
	/**
	 * \brief Destroys the current clipping region so that none of the DC is clipped.
See also  . 
	*/

  void DestroyClippingRegion() ;
	/**
	 * \brief Convert device X coordinate to logical coordinate, using the current
mapping mode. 
	 * \param wxCoord  
	*/

  wxCoord DeviceToLogicalX(wxCoord  x ) ;
	/**
	 * \brief Convert device X coordinate to relative logical coordinate, using the current
mapping mode but ignoring the x axis orientation.
Use this function for converting a width, for example. 
	 * \param wxCoord  
	*/

  wxCoord DeviceToLogicalXRel(wxCoord  x ) ;
	/**
	 * \brief Converts device Y coordinate to logical coordinate, using the current
mapping mode. 
	 * \param wxCoord  
	*/

  wxCoord DeviceToLogicalY(wxCoord  y ) ;
	/**
	 * \brief Convert device Y coordinate to relative logical coordinate, using the current
mapping mode but ignoring the y axis orientation.
Use this function for converting a height, for example. 
	 * \param wxCoord  
	*/

  wxCoord DeviceToLogicalYRel(wxCoord  y ) ;
	/**
	 * \brief Draws an arc of a circle, centred on ( ), with starting point ( )
and ending at ( ).   The current pen is used for the outline
and the current brush for filling the shape.

The arc is drawn in an anticlockwise direction from the start point to the end point. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param double  
	 * \param double  
	*/

  void DrawArc(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  xc , wxCoord  yc ) = 0;
	/**
	 * \brief Draw a bitmap on the device context at the specified point. If   is true and the bitmap has
a transparency mask, the bitmap will be drawn transparently.

When drawing a mono-bitmap, the current text foreground colour will be used to draw the foreground
of the bitmap (all bits set to 1), and the current text background colour to draw the background
(all bits set to 0). See also  , 
  and  . 
	 * \param const wxBitmap&  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param bool  
	*/

  void DrawBitmap(const wxBitmap&  bitmap , wxCoord  x , wxCoord  y , bool  transparent )  = 0;
	/**
	 * \brief  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawCheckMark(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief Draws a check mark inside the given rectangle. 
	 * \param const wxRect &  
	*/

  void DrawCheckMark(const wxRect & rect ) ;
	/**
	 * \brief  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawCircle(wxCoord  x , wxCoord  y , wxCoord  radius ) ;
	/**
	 * \brief Draws a circle with the given centre and radius. 
	 * \param const wxPoint&  
	 * \param wxCoord  
	*/

  void DrawCircle(const wxPoint&  pt , wxCoord  radius ) ;
	/**
	 * \brief  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawEllipse(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height )  = 0;
	/**
	 * \brief  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	*/

  void DrawEllipse(const wxPoint&  pt , const wxSize&  size )  = 0;
	/**
	 * \brief Draws an ellipse contained in the rectangle specified either with the given top
left corner and the given size or directly. The current pen is used for the
outline and the current brush for filling the shape. 
	 * \param const wxRect&  
	*/

  void DrawEllipse(const wxRect&  rect )  = 0;
	/**
	 * \brief Draws an arc of an ellipse. The current pen is used for drawing the arc and
the current brush is used for drawing the pie.

  and   specify the x and y coordinates of the upper-left corner of the rectangle that contains
the ellipse.

  and   specify the width and height of the rectangle that contains
the ellipse.

  and   specify the start and end of the arc relative to the three-o'clock
position from the center of the rectangle. Angles are specified
in degrees (360 is a complete circle). Positive values mean
counter-clockwise motion. If   is equal to  , a
complete ellipse will be drawn. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param double  
	 * \param double  
	*/

  void DrawEllipticArc(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double  start , double  end )  = 0;
	/**
	 * \brief Draw an icon on the display (does nothing if the device context is PostScript).
This can be the simplest way of drawing bitmaps on a window. 
	 * \param const wxIcon&  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawIcon(const wxIcon&  icon , wxCoord  x , wxCoord  y )  = 0;
	/**
	 * \brief Draws a line from the first point to the second. The current pen is used
for drawing the line. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawLine(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 )  = 0;
	/**
	 * \brief  
	 * \param int  
	 * \param wxPoint  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawLines(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0)  = 0;
	/**
	 * \brief Draws lines using an array of   of size  , or list of
pointers to points, adding the optional offset coordinate. The current
pen is used for drawing the lines.  The programmer is responsible for
deleting the list of points.

\pythonnote{The wxPython version of this method accepts a Python list
of wxPoint objects.}

\perlnote{The wxPerl version of this method accepts 
  as its first parameter a reference to an array
  of wxPoint objects.} 
	 * \param wxList *  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawLines(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0)  = 0;
	/**
	 * \brief  
	 * \param int  
	 * \param wxPoint  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param int   
	*/

  void DrawPolygon(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE)  = 0;
	/**
	 * \brief Draws a filled polygon using an array of   of size  ,
or list of pointers to points, adding the optional offset coordinate.

The last argument specifies the fill rule:   (the
default) or  .

The current pen is used for drawing the outline, and the current brush
for filling the shape.  Using a transparent brush suppresses filling.
The programmer is responsible for deleting the list of points.

Note that wxWindows automatically closes the first and last points.

\pythonnote{The wxPython version of this method accepts a Python list
of wxPoint objects.}

\perlnote{The wxPerl version of this method accepts 
  as its first parameter a reference to an array
  of wxPoint objects.} 
	 * \param wxList *  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param int   
	*/

  void DrawPolygon(wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE)  = 0;
	/**
	 * \brief Draws a point using the current pen. 
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawPoint(wxCoord  x , wxCoord  y )  = 0;
	/**
	 * \brief Draws a rectangle with the given top left corner, and with the given
size.  The current pen is used for the outline and the current brush
for filling the shape. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height )  = 0;
	/**
	 * \brief Draws the text rotated by   degrees.

  Under Win9x only TrueType fonts can be drawn by this function. In
particular, a font different from   should be used as the
latter is not a TrueType font.   is an example of a font
which is. 
	 * \param const wxString&   
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param double  
	*/

  void DrawRotatedText(const wxString&  text , wxCoord  x , wxCoord  y , double  angle )  = 0;
	/**
	 * \brief Draws a rectangle with the given top left corner, and with the given
size.  The corners are quarter-circles using the given radius. The
current pen is used for the outline and the current brush for filling
the shape.

If   is positive, the value is assumed to be the
radius of the rounded corner. If   is negative,
the absolute value is assumed to be the   of the smallest
dimension of the rectangle. This means that the corner can be
a sensible size relative to the size of the rectangle, and also avoids
the strange effects X produces when the corners are too big for
the rectangle. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param double  
	*/

  void DrawRoundedRectangle(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height , double radius )  = 0;
	/**
	 * \brief Draws a spline between all given control points, using the current
pen.  Doesn't delete the wxList and contents. The spline is drawn
using a series of lines, using an algorithm taken from the X drawing
program `XFIG'. 
	 * \param wxList *  
	*/

  void DrawSpline(wxList * points ) ;
	/**
	 * \brief Draws a three-point spline using the current pen.

\pythonnote{The wxPython version of this method accepts a Python list
of wxPoint objects.}

\perlnote{The wxPerl version of this method accepts a reference to an array
  of wxPoint objects.} 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawSpline(wxCoord  x1 , wxCoord  y1 , wxCoord  x2 , wxCoord  y2 , wxCoord  x3 , wxCoord  y3 ) ;
	/**
	 * \brief Draws a text string at the specified point, using the current text font,
and the current text foreground and background colours.

The coordinates refer to the top-left corner of the rectangle bounding
the string. See   for how
to get the dimensions of a text string, which can be used to position the
text more precisely.

  under wxGTK the current 
  is used by this function
but it is ignored by wxMSW. Thus, you should avoid using logical functions
with this function in portable programs.

\begin{comment} 
	 * \param const wxString&   
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void DrawText(const wxString&  text , wxCoord  x , wxCoord  y )  = 0;
	/**
	 * \brief  
	 * \param bool  
	*/

  static void EnableCache(bool  enableCache ) ;
	/**
	 * \brief Ends a document (only relevant when outputting to a printer). 
	*/

  void EndDoc() ;
	/**
	 * \brief Allows optimization of drawing code under MS Windows. Enclose
drawing primitives between   and  
calls. 
	*/

  void EndDrawing() ;
	/**
	 * \brief Ends a document page (only relevant when outputting to a printer). 
	*/

  void EndPage() ;
	/**
	 * \brief Flood fills the device context starting from the given point, using
the  , and using a style:

 

Returns false if the operation failed.

  The present implementation for non-Windows platforms may fail to find
colour borders if the pixels do not match the colour exactly. However the
function will still return true. 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param const wxColour&  
	 * \param int  
	*/

  bool FloodFill(wxCoord  x , wxCoord  y , const wxColour&  colour , int style = wxFLOOD_SURFACE) ;
	/**
	 * \brief  
	*/

  //wxBrush& GetBackground();
	/**
	 * \brief Gets the brush used for painting the background (see  ). 
	*/

  const wxBrush& GetBackground() const;
	/**
	 * \brief Returns the current background mode:   or  . 
	*/

  int GetBackgroundMode() const;
	/**
	 * \brief  
	*/

  //wxBrush& GetBrush();
	/**
	 * \brief Gets the current brush (see  ). 
	*/

  const wxBrush& GetBrush() const;
	/**
	 * \brief Gets the character height of the currently set font. 
	*/

  wxCoord GetCharHeight()  = 0;
	/**
	 * \brief Gets the average character width of the currently set font. 
	*/

  wxCoord GetCharWidth()  = 0;
	/**
	 * \brief Gets the rectangle surrounding the current clipping region.

\pythonnote{No arguments are required and the four values defining the
rectangle are returned as a tuple.}

\perlnote{This method takes no arguments and returns a four element list
 } 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void GetClippingBox(wxCoord  *x , wxCoord  *y , wxCoord  *width , wxCoord  *height ) ;
	/**
	 * \brief  
	*/

  //wxFont& GetFont();
	/**
	 * \brief Gets the current font (see  ). 
	*/

  const wxFont& GetFont() const;
	/**
	 * \brief Gets the current logical function (see  ). 
	*/

  int GetLogicalFunction() ;
	/**
	 * \brief Gets the   for the device context (see  ). 
	*/

  int GetMapMode() ;
	/**
	 * \brief Returns true if device context optimization is on.
See   for details. 
	*/

  bool GetOptimization() ;
	/**
	 * \brief  
	*/

  //wxPen& GetPen();
	/**
	 * \brief Gets the current pen (see  ). 
	*/

  const wxPen& GetPen() const;
	/**
	 * \brief Sets   to the colour at the specified location. Windows only; an X implementation
is being worked on. Not available for wxPostScriptDC or wxMetafileDC.

\pythonnote{For wxPython the wxColour value is returned and is not
required as a parameter.}

\perlnote{This method only takes the parameters   and   and returns
a Wx::Colour value} 
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxColour *  
	*/

  bool GetPixel(wxCoord  x , wxCoord  y , wxColour * colour )  = 0;
	/**
	 * \brief For a PostScript device context, this gets the maximum size of graphics
drawn so far on the device context.

For a Windows printer device context, this gets the horizontal and vertical
resolution. It can be used to scale graphics to fit the page when using
a Windows printer device context. For example, if   and  
represent the maximum horizontal and vertical `pixel' values used in your
application, the following code will scale the graphic to fit on the
printer page:

 

\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
}

\perlnote{In place of a single overloaded method, wxPerl uses:\par
\indented{2cm}{ 
}} 
	 * \param wxCoord *  
	 * \param wxCoord *  
	*/

  void GetSize(wxCoord * width , wxCoord * height )  = 0;
	/**
	 * \brief  
	*/

  //wxColour& GetTextBackground();
	/**
	 * \brief Gets the current text background colour (see  ). 
	*/

  const wxColour& GetTextBackground() const;
	/**
	 * \brief Gets the dimensions of the string using the currently selected font.
  is the text string to measure,   and   are
the total width and height respectively,   is the
dimension from the baseline of the font to the bottom of the
descender, and   is any extra vertical space added
to the font by the font designer (usually is zero).

The optional parameter   specifies an alternative
to the currently selected font: but note that this does not
yet work under Windows, so you need to set a font for
the device context first.

See also  ,  .

\pythonnote{The following methods are implemented in wxPython:\par
\indented{2cm}{ }
}

\perlnote{In wxPerl this method is implemented as 
    returning a four element
  array  
} 
	 * \param const wxString&   
	 * \param wxCoord *  
	 * \param wxCoord *  
	 * \param wxCoord *  
	 * \param wxCoord *  
	 * \param wxFont *  
	*/

  void GetTextExtent(const wxString&  string , wxCoord * w , wxCoord * h , wxCoord * descent = NULL, wxCoord * externalLeading = NULL, wxFont * font = NULL)  = 0;
	/**
	 * \brief  
	*/

  //wxColour& GetTextForeground();
	/**
	 * \brief Gets the current text foreground colour (see  ). 
	*/

  const wxColour& GetTextForeground() const;
	/**
	 * \brief Gets the current user scale factor (set by  ).

\perlnote{In wxPerl this method takes no arguments and return a two element
 array  } 
	 * \param double  
	 * \param double  
	*/

  void GetUserScale(double  *x , double  *y ) ;
	/**
	 * \brief Converts logical X coordinate to device coordinate, using the current
mapping mode. 
	 * \param wxCoord  
	*/

  wxCoord LogicalToDeviceX(wxCoord  x ) ;
	/**
	 * \brief Converts logical X coordinate to relative device coordinate, using the current
mapping mode but ignoring the x axis orientation.
Use this for converting a width, for example. 
	 * \param wxCoord  
	*/

  wxCoord LogicalToDeviceXRel(wxCoord  x ) ;
	/**
	 * \brief Converts logical Y coordinate to device coordinate, using the current
mapping mode. 
	 * \param wxCoord  
	*/

  wxCoord LogicalToDeviceY(wxCoord  y ) ;
	/**
	 * \brief Converts logical Y coordinate to relative device coordinate, using the current
mapping mode but ignoring the y axis orientation.
Use this for converting a height, for example. 
	 * \param wxCoord  
	*/

  wxCoord LogicalToDeviceYRel(wxCoord  y ) ;
	/**
	 * \brief Gets the maximum horizontal extent used in drawing commands so far. 
	*/

  wxCoord MaxX() ;
	/**
	 * \brief Gets the maximum vertical extent used in drawing commands so far. 
	*/

  wxCoord MaxY() ;
	/**
	 * \brief Gets the minimum horizontal extent used in drawing commands so far. 
	*/

  wxCoord MinX() ;
	/**
	 * \brief Gets the minimum vertical extent used in drawing commands so far. 
	*/

  wxCoord MinY() ;
	/**
	 * \brief Returns true if the DC is ok to use. 
	*/

  bool Ok() ;
	/**
	 * \brief Resets the bounding box: after a call to this function, the bounding box
doesn't contain anything. 
	*/

  void ResetBoundingBox() ;
	/**
	 * \brief Sets the x and y axis orientation (i.e., the direction from lowest to
highest values on the axis). The default orientation is the natural
orientation, e.g. x axis from left to right and y axis from bottom up. 
	 * \param bool  
	 * \param bool  
	*/

  void SetAxisOrientation(bool  xLeftRight , bool  yBottomUp ) ;
	/**
	 * \brief Sets the device origin (i.e., the origin in pixels after scaling has been
applied).

This function may be useful in Windows printing
operations for placing a graphic on a page. 
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void SetDeviceOrigin(wxCoord  x , wxCoord  y ) ;
	/**
	 * \brief Sets the current background brush for the DC. 
	 * \param const wxBrush&   
	*/

  void SetBackground(const wxBrush&  brush )  = 0;
	/**
	 * \brief may be one of wxSOLID and wxTRANSPARENT. This setting determines
whether text will be drawn with a background colour or not. 
	 * \param int  
	*/

  void SetBackgroundMode(int  mode )  = 0;
	/**
	 * \brief  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	 * \param wxCoord  
	*/

  void SetClippingRegion(wxCoord  x , wxCoord  y , wxCoord  width , wxCoord  height ) ;
	/**
	 * \brief  
	 * \param const wxPoint&   
	 * \param const wxSize&   
	*/

  void SetClippingRegion(const wxPoint&  pt , const wxSize&  sz ) ;
	/**
	 * \brief  
	 * \param const wxRect&  
	*/

  void SetClippingRegion(const wxRect&  rect ) ;
	/**
	 * \brief  
	 * \param const wxRegion&  
	*/

  void SetClippingRegion(const wxRegion&  region ) ;
	/**
	 * \brief If this is a window DC or memory DC, assigns the given palette to the window
or bitmap associated with the DC. If the argument is wxNullPalette, the current
palette is selected out of the device context, and the original palette
restored.

See   for further details. 
	 * \param const wxPalette&   
	*/

  void SetPalette(const wxPalette&  palette )  = 0;
	/**
	 * \brief Sets the current brush for the DC.

If the argument is wxNullBrush, the current brush is selected out of the device
context, and the original brush restored, allowing the current brush to
be destroyed safely.

See also  .

See also   for the interpretation of colours
when drawing into a monochrome bitmap. 
	 * \param const wxBrush&   
	*/

  void SetBrush(const wxBrush&  brush )  = 0;
	/**
	 * \brief Sets the current font for the DC. It must be a valid font, in particular you
should not pass   to this method.

See also  . 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font )  = 0;
	/**
	 * \brief Sets the current logical function for the device context.  This determines how
a source pixel (from a pen or brush colour, or source device context if
using  ) combines with a destination pixel in the
current device context.

The possible values
and their meaning in terms of source and destination pixel values are
as follows:

 

The default is wxCOPY, which simply draws with the current colour.
The others combine the current colour and the background using a
logical operation.  wxINVERT is commonly used for drawing rubber bands or
moving outlines, since drawing twice reverts to the original colour. 
	 * \param int  
	*/

  void SetLogicalFunction(int  function )  = 0;
	/**
	 * \brief The   of the device context defines the unit of
measurement used to convert logical units to device units. Note that
in X, text drawing isn't handled consistently with the mapping mode; a
font is always specified in point size. However, setting the   (see  ) scales the text appropriately. In
Windows, scalable TrueType fonts are always used; in X, results depend
on availability of fonts, but usually a reasonable match is found.

Note that the coordinate origin should ideally be selectable, but for
now is always at the top left of the screen/printer.

Drawing to a Windows printer device context under UNIX
uses the current mapping mode, but mapping mode is currently ignored for
PostScript output.

The mapping mode can be one of the following: 
	 * \param int  
	*/

  void SetMapMode(int  int ) ;
	/**
	 * \brief If   is true (the default), this function sets optimization mode on.
This currently means that under X, the device context will not try to set a pen or brush
property if it is known to be set already. This approach can fall down
if non-wxWindows code is using the same device context or window, for example
when the window is a panel on which the windowing system draws panel items.
The wxWindows device context 'memory' will now be out of step with reality.

Setting optimization off, drawing, then setting it back on again, is a trick
that must occasionally be employed. 
	 * \param bool   
	*/

  void SetOptimization(bool  optimize ) ;
	/**
	 * \brief Sets the current pen for the DC.

If the argument is wxNullPen, the current pen is selected out of the device
context, and the original pen restored.

See also   for the interpretation of colours
when drawing into a monochrome bitmap. 
	 * \param const wxPen&   
	*/

  void SetPen(const wxPen&  pen )  = 0;
	/**
	 * \brief Sets the current text background colour for the DC. 
	 * \param const wxColour&   
	*/

  void SetTextBackground(const wxColour&  colour ) ;
	/**
	 * \brief Sets the current text foreground colour for the DC.

See also   for the interpretation of colours
when drawing into a monochrome bitmap. 
	 * \param const wxColour&   
	*/

  void SetTextForeground(const wxColour&  colour ) ;
	/**
	 * \brief Sets the user scaling factor, useful for applications which require
`zooming'. 
	 * \param double  
	 * \param double  
	*/

  void SetUserScale(double  xScale , double  yScale ) ;
	/**
	 * \brief Starts a document (only relevant when outputting to a printer).
Message is a message to show whilst printing. 
	 * \param const wxString&   
	*/

  bool StartDoc(const wxString&  message ) ;
	/**
	 * \brief Starts a document page (only relevant when outputting to a printer). 
	*/

  bool StartPage() ;
};


#endif
