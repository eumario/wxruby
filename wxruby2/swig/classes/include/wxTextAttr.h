// wxTextAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTextAttr_h_)
#define _wxTextAttr_h_
class wxTextAttr
{
public:
   wxTextAttr() ;
   wxTextAttr(const wxColour&  colText , const wxColour&  colBack = wxNullColour, const wxFont&  font = wxNullFont, wxTextAttrAlignment  alignment = wxTEXT_ALIGNMENT_DEFAULT) ;
  wxTextAttrAlignment GetAlignment() const;
  const wxColour& GetBackgroundColour() const;
  const wxFont& GetFont() const;
  int GetLeftIndent() const;
  int GetRightIndent() const;
  const wxArrayInt& GetTabs() const;
  const wxColour& GetTextColour() const;
  bool HasBackgroundColour() const;
  bool HasFont() const;
  bool HasTextColour() const;
  long GetFlags() ;
  bool IsDefault() const;
  void SetAlignment(wxTextAttrAlignment  alignment ) ;
  void SetBackgroundColour(const wxColour&  colour ) ;
  void SetFlags(long  flags ) ;
  void SetFont(const wxFont&  font ) ;
  void SetLeftIndent(int  indent ) ;
  void SetRightIndent(int  indent ) ;
  void SetTabs(const wxArrayInt&  tabs ) ;
  void SetTextColour(const wxColour&  colour ) ;
};


#endif
