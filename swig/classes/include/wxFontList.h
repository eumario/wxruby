// wxFontList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontList_h_)
#define _wxFontList_h_
class wxFontList : public wxList
{
public:
   wxFontList() ;
  void AddFont(wxFont * font ) ;
  wxFont * FindOrCreateFont(int  point_size , int  family , int  style , int  weight , bool underline = false, const wxString&  facename = NULL, wxFontEncoding  encoding = wxFONTENCODING_DEFAULT) ;
  void RemoveFont(wxFont * font ) ;
};


#endif
