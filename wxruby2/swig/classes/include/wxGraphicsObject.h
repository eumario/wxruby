// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGraphicsObject_h_)
#define _wxGraphicsObject_h_

class wxGraphicsObject : public wxObject
{
public :
    wxGraphicsObject() ;
    wxGraphicsObject( wxGraphicsRenderer* renderer ) ;
    virtual ~wxGraphicsObject() ;
    
    bool IsNull() const ;

    // returns the renderer that was used to create this instance, or NULL if it has not been initialized yet
    wxGraphicsRenderer* GetRenderer() const ;
    wxGraphicsObjectRefData* GetGraphicsData() const ;
};


#endif
