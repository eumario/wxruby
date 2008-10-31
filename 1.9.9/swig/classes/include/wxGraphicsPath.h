// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGraphicsPath_h_)
#define _wxGraphicsPath_h_

class wxGraphicsPath : public wxGraphicsObject
{
public :
    wxGraphicsPath()  {}
    virtual ~wxGraphicsPath() {}

    virtual void MoveToPoint( wxDouble x, wxDouble y );
    void MoveToPoint( const wxPoint2DDouble& p);

    // adds a straight line from the current point to (x,y) 
    virtual void AddLineToPoint( wxDouble x, wxDouble y );
    void AddLineToPoint( const wxPoint2DDouble& p);

    // adds a cubic Bezier curve from the current point, using two control points and an end point
    virtual void AddCurveToPoint( wxDouble cx1, wxDouble cy1, 
                                  wxDouble cx2, wxDouble cy2, 
                                  wxDouble x, wxDouble y );
    void AddCurveToPoint( const wxPoint2DDouble& c1, 
                          const wxPoint2DDouble& c2, 
                          const wxPoint2DDouble& e);
    
    // adds another path
    virtual void AddPath( const wxGraphicsPath& path );

    // closes the current sub-path
    virtual void CloseSubpath() ;

    // gets the last point of the current path, (0,0) if not yet set
    virtual void GetCurrentPoint( wxDouble* x, wxDouble* y) const;
    wxPoint2DDouble GetCurrentPoint() const;

    // adds an arc of a circle centering at (x,y) with radius (r) from startAngle to endAngle
    virtual void AddArc( wxDouble x, wxDouble y,  wxDouble r, 
                         wxDouble startAngle, wxDouble endAngle, 
                         bool clockwise ) ;
    void AddArc( const wxPoint2DDouble& c, wxDouble r, 
                 wxDouble startAngle, wxDouble endAngle, bool clockwise);


    // adds a quadratic Bezier curve from the current point, using a control point and an end point
    virtual void AddQuadCurveToPoint( wxDouble cx, wxDouble cy, 
                                      wxDouble x, wxDouble y );

    // appends a rectangle as a new closed subpath 
    virtual void AddRectangle( wxDouble x, wxDouble y, 
                               wxDouble w, wxDouble h );

    // appends an ellipsis as a new closed subpath fitting the passed rectangle
    virtual void AddCircle( wxDouble x, wxDouble y, wxDouble r );

    // appends a an arc to two tangents connecting (current) to (x1,y1) and (x1,y1) to (x2,y2), also a straight line from (current) to (x1,y1)
    virtual void AddArcToPoint( wxDouble x1, wxDouble y1, 
                                wxDouble x2, wxDouble y2, 
                                wxDouble r ) ;
    
    // appends an ellipse
    virtual void AddEllipse( wxDouble x, wxDouble y, wxDouble w, wxDouble h);

    // appends a rounded rectangle
    virtual void AddRoundedRectangle( wxDouble x, wxDouble y, 
                                      wxDouble w, wxDouble h, 
                                      wxDouble radius);

    // returns the native path
    virtual void * GetNativePath() const;
    
    // give the native path returned by GetNativePath() back (there might be some deallocations necessary)
    virtual void UnGetNativePath(void *p)const;
    
    // transforms each point of this path by the matrix
    virtual void Transform( const wxGraphicsMatrix& matrix );
    
    // gets the bounding box enclosing all points (possibly including control points)
    virtual void GetBox(wxDouble *x, wxDouble *y, 
                        wxDouble *w, wxDouble *h) const;
    wxRect2DDouble GetBox()const;
    
    virtual bool Contains( wxDouble x, wxDouble y, 
                           int fillStyle = wxODDEVEN_RULE) const;
    bool Contains( const wxPoint2DDouble& c, 
                   int fillStyle = wxODDEVEN_RULE) const;
    
    const wxGraphicsPathData* GetPathData() const;

    wxGraphicsPathData* GetPathData() ;
} ;



#endif
