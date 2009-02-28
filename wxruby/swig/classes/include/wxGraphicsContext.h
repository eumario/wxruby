// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGraphicsContext_h_)
#define _wxGraphicsContext_h_

class wxGraphicsContext : public wxGraphicsObject
{
public:
    wxGraphicsContext(wxGraphicsRenderer* renderer);

    virtual ~wxGraphicsContext();
    
    static wxGraphicsContext* Create( const wxWindowDC& dc) ;
    
#ifdef __WXMSW__
    static wxGraphicsContext * Create( const wxMemoryDC& dc) ;
#endif    

    static wxGraphicsContext* CreateFromNative( void * context ) ;

    static wxGraphicsContext* CreateFromNativeWindow( void * window ) ;

    static wxGraphicsContext* Create( wxWindow* window ) ;

    // create a context that can be used for measuring texts only, no drawing allowed
    static wxGraphicsContext * Create();

    wxGraphicsPath CreatePath() const;
    
    virtual wxGraphicsPen CreatePen(const wxPen& pen) const;
    
    virtual wxGraphicsBrush CreateBrush(const wxBrush& brush ) const;
    
    // sets the brush to a linear gradient, starting at (x1,y1) with color c1 to (x2,y2) with color c2
    virtual wxGraphicsBrush CreateLinearGradientBrush( wxDouble x1, wxDouble y1, wxDouble x2, wxDouble y2, 
        const wxColour&c1, const wxColour&c2) const;

    // sets the brush to a radial gradient originating at (xo,yc) with color oColor and ends on a circle around (xc,yc) 
    // with radius r and color cColor
    virtual wxGraphicsBrush CreateRadialGradientBrush( wxDouble xo, wxDouble yo, wxDouble xc, wxDouble yc, wxDouble radius,
        const wxColour &oColor, const wxColour &cColor) const;

    // sets the font
    virtual wxGraphicsFont CreateFont( const wxFont &font , const wxColour &col = *wxBLACK ) const;

    // create a 'native' matrix corresponding to these values
    virtual wxGraphicsMatrix CreateMatrix( wxDouble a=1.0, wxDouble b=0.0, wxDouble c=0.0, wxDouble d=1.0, 
        wxDouble tx=0.0, wxDouble ty=0.0) const;
    
    // push the current state of the context, ie the transformation matrix on a stack
    virtual void PushState() = 0;

    // pops a stored state from the stack
    virtual void PopState() = 0;

    // clips drawings to the region, combined to current clipping region
    virtual void Clip( const wxRegion &region ) = 0;

    // clips drawings to the rect
    virtual void Clip( wxDouble x, wxDouble y, wxDouble w, wxDouble h ) = 0;
    
    // resets the clipping to original extent
    virtual void ResetClip() = 0 ;

    // returns the native context
    virtual void * GetNativeContext() = 0;

    // returns the current logical function
    virtual int GetLogicalFunction() const { return m_logicalFunction; }
    
    // sets the current logical function, returns true if it supported
    virtual bool SetLogicalFunction(int function) ;

    //
    // transformation : changes the current transformation matrix CTM of the context
    //
    
    // translate
    virtual void Translate( wxDouble dx , wxDouble dy ) = 0;

    // scale
    virtual void Scale( wxDouble xScale , wxDouble yScale ) = 0;

    // rotate (radians)
    virtual void Rotate( wxDouble angle ) = 0;
    
    // concatenates this transform with the current transform of this context
    virtual void ConcatTransform( const wxGraphicsMatrix& matrix ) = 0;

    // sets the transform of this context
    virtual void SetTransform( const wxGraphicsMatrix& matrix ) = 0;

    // gets the matrix of this context
    virtual wxGraphicsMatrix GetTransform() const = 0;
    //
    // setting the paint
    //
    
    // sets the pen
    virtual void SetPen( const wxGraphicsPen& pen );
    
    void SetPen( const wxPen& pen );

    // sets the brush for filling
    virtual void SetBrush( const wxGraphicsBrush& brush );
    
    void SetBrush( const wxBrush& brush );

    // sets the font
    virtual void SetFont( const wxGraphicsFont& font );
    
    void SetFont( const wxFont& font, const wxColour& colour );

    
    // strokes along a path with the current pen
    virtual void StrokePath( const wxGraphicsPath& path ) = 0;

    // fills a path with the current brush
    virtual void FillPath( const wxGraphicsPath& path, int fillStyle = wxODDEVEN_RULE ) = 0;

    // draws a path by first filling and then stroking
    virtual void DrawPath( const wxGraphicsPath& path, int fillStyle = wxODDEVEN_RULE );
    
    //
    // text
    //
    
    virtual void DrawText( const wxString &str, wxDouble x, wxDouble y ) = 0;

    virtual void DrawText( const wxString &str, wxDouble x, wxDouble y, wxDouble angle );

    virtual void DrawText( const wxString &str, wxDouble x, wxDouble y, const wxGraphicsBrush& backgroundBrush ) ;

    virtual void DrawText( const wxString &str, wxDouble x, wxDouble y, wxDouble angle, const wxGraphicsBrush& backgroundBrush );

    virtual void GetTextExtent( const wxString &text, wxDouble *width, wxDouble *height,
        wxDouble *descent, wxDouble *externalLeading ) const  = 0;

    virtual void GetPartialTextExtents(const wxString& text, wxArrayDouble& widths) const = 0;

    //
    // image support
    //

    virtual void DrawBitmap( const wxBitmap &bmp, wxDouble x, wxDouble y, wxDouble w, wxDouble h ) = 0;

    virtual void DrawIcon( const wxIcon &icon, wxDouble x, wxDouble y, wxDouble w, wxDouble h ) = 0;

    //
    // convenience methods
    //
    
    // strokes a single line
    virtual void StrokeLine( wxDouble x1, wxDouble y1, wxDouble x2, wxDouble y2);

    // stroke lines connecting each of the points
    virtual void StrokeLines( size_t n, const wxPoint2DDouble *points);

    // stroke disconnected lines from begin to end points
    virtual void StrokeLines( size_t n, const wxPoint2DDouble *beginPoints, const wxPoint2DDouble *endPoints);

    // draws a polygon
    virtual void DrawLines( size_t n, const wxPoint2DDouble *points, int fillStyle = wxODDEVEN_RULE );

    // draws a polygon
    virtual void DrawRectangle( wxDouble x, wxDouble y, wxDouble w, wxDouble h);

    // draws an ellipse
    virtual void DrawEllipse( wxDouble x, wxDouble y, wxDouble w, wxDouble h);

    // draws a rounded rectangle
    virtual void DrawRoundedRectangle( wxDouble x, wxDouble y, wxDouble w, wxDouble h, wxDouble radius);

     // wrappers using wxPoint2DDouble TODO

    // helper to determine if a 0.5 offset should be applied for the drawing operation
    virtual bool ShouldOffset() const { return false; }

};

#endif
