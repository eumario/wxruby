// wxFlexGridSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFlexGridSizer_h_)
#define _wxFlexGridSizer_h_
class wxFlexGridSizer : public wxGridSizer
{
public:
   wxFlexGridSizer(int  rows , int  cols , int  vgap , int  hgap ) ;
   wxFlexGridSizer(int  cols , int  vgap = 0, int  hgap = 0) ;
  void AddGrowableCol(size_t  idx);
  void AddGrowableRow(size_t  idx);
  int GetFlexibleDirection() const;
  int GetNonFlexibleGrowMode() const;
  void RemoveGrowableCol(size_t  idx ) ;
  void RemoveGrowableRow(size_t  idx ) ;
  void SetFlexibleDirection(int  direction ) ;
  void SetNonFlexibleGrowMode(int  mode ) ;
};


#endif
