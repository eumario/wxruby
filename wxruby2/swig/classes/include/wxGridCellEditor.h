// wxGridCellEditor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGridCellEditor_h_)
#define _wxGridCellEditor_h_
class wxGridCellEditor
{
public:
   wxGridCellEditor() ;
  bool IsCreated() ;
  void Create(wxWindow*  parent , wxWindowID  id , wxEvtHandler*  evtHandler ) ;
  void SetSize(const wxRect&  rect ) ;
  void Show(bool  show , wxGridCellAttr*  attr = NULL) ;
  void PaintBackground(const wxRect&  rectCell , wxGridCellAttr*  attr ) ;
  void BeginEdit(int  row , int  col , wxGrid*  grid ) ;
  bool EndEdit(int  row , int  col , wxGrid*  grid ) ;
  void Reset() ;
  void StartingKey(wxKeyEvent&  event ) ;
  void StartingClick() ;
  void HandleReturn(wxKeyEvent&  event ) ;
  void Destroy() ;
  wxGridCellEditor* Clone() const;
  virtual  ~wxGridCellEditor() ;
};


#endif
