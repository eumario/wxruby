// wxBrushList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBrushList_h_)
#define _wxBrushList_h_
class wxBrushList : public wxList
{
public:
   wxBrushList() ;
  void AddBrush(wxBrush * brush ) ;
  wxBrush * FindOrCreateBrush(const wxColour&  colour , int  style ) ;
  wxBrush * FindOrCreateBrush(const wxString&  colourName , int  style ) ;
  void RemoveBrush(wxBrush * brush ) ;
};


#endif
