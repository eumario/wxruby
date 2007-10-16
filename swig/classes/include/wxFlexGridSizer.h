// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxFlexGridSizer_h_)
#define _wxFlexGridSizer_h_
class wxFlexGridSizer : public wxGridSizer
{
public:
   wxFlexGridSizer(int  rows , int  cols , int  vgap , int  hgap ) ;
   wxFlexGridSizer(int  cols , int  vgap = 0, int  hgap = 0) ;
  void AddGrowableCol(size_t  idx, int proportion = 0);
  void AddGrowableRow(size_t  idx, int proportion = 0);
  int GetFlexibleDirection() const;
  int GetNonFlexibleGrowMode() const;
  void RemoveGrowableCol(size_t  idx ) ;
  void RemoveGrowableRow(size_t  idx ) ;
  void SetFlexibleDirection(int  direction ) ;
  void SetNonFlexibleGrowMode(int  mode ) ;

  virtual void RecalcSizes();
  virtual wxSize CalcMin();

};


#endif
