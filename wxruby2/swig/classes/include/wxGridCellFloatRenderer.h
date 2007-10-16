// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

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
