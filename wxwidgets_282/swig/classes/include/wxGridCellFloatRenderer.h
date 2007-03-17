//   Copyright 2004-2005 by Kevin Smith
//   released under the MIT-style wxruby2 license

#if !defined(_wxGridCellFloatRenderer_h_)
#define _wxGridCellFloatRenderer_h_
class wxGridCellFloatRenderer : public wxGridCellStringRenderer
{
public:
   wxGridCellFloatRenderer(int  width = -1, int  precision = -1) ;
  int GetPrecision() const;
  int GetWidth() const;
  void SetParameters(const wxString&  params ) ;
  void SetPrecision(int  precision ) ;
  void SetWidth(int  width ) ;
};


#endif
