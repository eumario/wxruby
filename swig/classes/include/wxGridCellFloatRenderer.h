// wxGridCellFloatRenderer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
