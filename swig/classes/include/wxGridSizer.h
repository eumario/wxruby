// wxGridSizer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridSizer_h_)
#define _wxGridSizer_h_
class wxGridSizer : public wxSizer
{
public:
   wxGridSizer(int  rows , int  cols , int  vgap , int  hgap ) ;
   wxGridSizer(int  cols , int  vgap = 0, int  hgap = 0) ;
  int GetCols() ;
  int GetHGap() ;
  int GetRows() ;
  int GetVGap() ;
  void SetCols(int  cols ) ;
  void SetHGap(int  gap ) ;
  void SetRows(int  rows ) ;
  void SetVGap(int  gap ) ;
};


#endif
