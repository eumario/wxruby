// wxColourData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxColourData_h_)
#define _wxColourData_h_
class wxColourData : public wxObject
{
public:
   wxColourData() ;
  virtual  ~wxColourData() ;
  bool GetChooseFull() const;
  wxColour GetColour() const;
  wxColour GetCustomColour(int  i );
  void SetChooseFull(const bool  flag ) ;
  void SetColour(const wxColour&  colour ) ;
  void SetCustomColour(int  i , const wxColour&  colour ) ;
};


#endif
