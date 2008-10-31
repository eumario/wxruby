// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGraphicsMatrix_h_)
#define _wxGraphicsMatrix_h_

class wxGraphicsMatrix : public wxGraphicsObject
{
 public :
  wxGraphicsMatrix();
  virtual ~wxGraphicsMatrix();

  // concatenates the matrix
  virtual void Concat( const wxGraphicsMatrix *t );
  void Concat( const wxGraphicsMatrix &t );

  // sets the matrix to the respective values
  virtual void Set(wxDouble a=1.0, wxDouble b=0.0, 
                   wxDouble c=0.0, wxDouble d=1.0, 
                   wxDouble tx=0.0, wxDouble ty=0.0);

  // gets the component valuess of the matrix
  virtual void Get(wxDouble* a=NULL, wxDouble* b=NULL,  wxDouble* c=NULL,
                   wxDouble* d=NULL, wxDouble* tx=NULL, wxDouble* ty=NULL) const;
       
  // makes this the inverse matrix
  virtual void Invert();

  // returns true if the elements of the transformation matrix are equal ?
  virtual bool IsEqual( const wxGraphicsMatrix* t) const;
  bool IsEqual( const wxGraphicsMatrix& t);

  // return true if this is the identity matrix
  virtual bool IsIdentity() const;

  //
  // transformation
  //

  // add the translation to this matrix
  virtual void Translate( wxDouble dx , wxDouble dy );

  // add the scale to this matrix
  virtual void Scale( wxDouble xScale , wxDouble yScale );

  // add the rotation to this matrix (radians)
  virtual void Rotate( wxDouble angle );  

  //
  // apply the transforms
  //

  // applies that matrix to the point
  virtual void TransformPoint( wxDouble *x, wxDouble *y ) const;

  // applies the matrix except for translations
  virtual void TransformDistance( wxDouble *dx, wxDouble *dy ) const;

  // returns the native representation
  virtual void * GetNativeMatrix() const;

  const wxGraphicsMatrixData* GetMatrixData() const 
  { return (const wxGraphicsMatrixData*) GetRefData(); }
  wxGraphicsMatrixData* GetMatrixData() 
  { return (wxGraphicsMatrixData*) GetRefData(); }

} ;



#endif
