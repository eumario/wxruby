// wxFontData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFontData_h_)
#define _wxFontData_h_
class wxFontData : public wxObject
{
public:
   wxFontData() ;
  virtual  ~wxFontData() ;
  void EnableEffects(bool  enable ) ;
  bool GetAllowSymbols() ;
  wxColour& GetColour() ;
  wxFont GetChosenFont() ;
  bool GetEnableEffects() ;
  wxFont GetInitialFont() ;
  bool GetShowHelp() ;
  void SetAllowSymbols(bool  allowSymbols ) ;
  void SetChosenFont(const wxFont&  font ) ;
  void SetColour(const wxColour&  colour ) ;
  void SetInitialFont(const wxFont& font ) ;
  void SetRange(int  min , int  max ) ;
  void SetShowHelp(bool  showHelp ) ;
};


#endif
