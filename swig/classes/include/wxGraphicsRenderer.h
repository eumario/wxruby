// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGraphicsRenderer_h_)
#define _wxGraphicsRenderer_h_

class WXDLLIMPEXP_CORE wxGraphicsRenderer : public wxObject
{
public :
    wxGraphicsRenderer() {}

    virtual ~wxGraphicsRenderer() {}

    static wxGraphicsRenderer* GetDefaultRenderer();

    // Context

    virtual wxGraphicsContext * CreateContext( const wxWindowDC& dc) = 0 ;
#ifdef __WXMSW__
    virtual wxGraphicsContext * CreateContext( const wxMemoryDC& dc) = 0 ;
#endif    
    virtual wxGraphicsContext * CreateContextFromNativeContext( void * context ) = 0;

    virtual wxGraphicsContext * CreateContextFromNativeWindow( void * window ) = 0;

    virtual wxGraphicsContext * CreateContext( wxWindow* window ) = 0;

    // create a context that can be used for measuring texts only, no drawing allowed
    virtual wxGraphicsContext * CreateMeasuringContext() = 0;

    // Path
    
    virtual wxGraphicsPath CreatePath() = 0;

    // Matrix
    
    virtual wxGraphicsMatrix CreateMatrix( wxDouble a=1.0, wxDouble b=0.0, wxDouble c=0.0, wxDouble d=1.0, 
        wxDouble tx=0.0, wxDouble ty=0.0) = 0;
        
    // Paints
    
    virtual wxGraphicsPen CreatePen(const wxPen& pen) = 0 ;
    
    virtual wxGraphicsBrush CreateBrush(const wxBrush& brush ) = 0 ;
    
    // sets the brush to a linear gradient, starting at (x1,y1) with color c1 to (x2,y2) with color c2
    virtual wxGraphicsBrush CreateLinearGradientBrush( wxDouble x1, wxDouble y1, wxDouble x2, wxDouble y2, 
        const wxColour&c1, const wxColour&c2) = 0;

    // sets the brush to a radial gradient originating at (xo,yc) with color oColor and ends on a circle around (xc,yc) 
    // with radius r and color cColor
    virtual wxGraphicsBrush CreateRadialGradientBrush( wxDouble xo, wxDouble yo, wxDouble xc, wxDouble yc, wxDouble radius,
        const wxColour &oColor, const wxColour &cColor) = 0;

   // sets the font
    virtual wxGraphicsFont CreateFont( const wxFont &font , const wxColour &col = *wxBLACK ) = 0;
} ;

#endif
