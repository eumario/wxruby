// wxGridCellAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellAttr_h_)
#define _wxGridCellAttr_h_
class wxGridCellAttr
{
public:
   wxGridCellAttr() ;
   wxGridCellAttr(const wxColour&  colText , const wxColour&  colBack , const wxFont&  font , int  hAlign , int  vAlign ) ;
  wxGridCellAttr* Clone() const;
  void IncRef() ;
  void DecRef() ;
  void SetTextColour(const wxColour&  colText ) ;
  void SetBackgroundColour(const wxColour&  colBack ) ;
  void SetFont(const wxFont&  font ) ;
  void SetAlignment(int  hAlign , int  vAlign ) ;
  void SetReadOnly(bool  isReadOnly = true) ;
  void SetRenderer(wxGridCellRenderer*  renderer ) ;
  void SetEditor(wxGridCellEditor*  editor ) ;
  bool HasTextColour() const;
  bool HasBackgroundColour() const;
  bool HasFont() const;
  bool HasAlignment() const;
  bool HasRenderer() const;
  bool HasEditor() const;
  const wxColour& GetTextColour() const;
  const wxColour& GetBackgroundColour() const;
  const wxFont& GetFont() const;
  void GetAlignment(int*  hAlign , int*  vAlign ) const;
  wxGridCellRenderer* GetRenderer(wxGrid*  grid , int  row , int  col ) const;
  wxGridCellEditor* GetEditor(wxGrid*  grid , int  row , int  col ) const;
  bool IsReadOnly() const;
  void SetDefAttr(wxGridCellAttr*  defAttr ) ;
};


#endif
