// wxPenList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPenList_h_)
#define _wxPenList_h_
class wxPenList
{
public:
   wxPenList() ;
  void AddPen(wxPen*  pen ) ;
  wxPen* FindOrCreatePen(const wxColour&  colour , int  width , int  style ) ;
  wxPen* FindOrCreatePen(const wxString&  colourName , int  width , int  style ) ;
  void RemovePen(wxPen*  pen ) ;
};


#endif
