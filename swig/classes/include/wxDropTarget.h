// wxDropTarget.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropTarget_h_)
#define _wxDropTarget_h_
class wxDropTarget
{
public:
   wxDropTarget(wxDataObject* data = NULL) ;
  virtual  ~wxDropTarget() ;
  virtual void GetData() ;
  virtual wxDragResult OnData(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
  virtual bool OnDrop(wxCoord  x , wxCoord  y ) ;
  virtual wxDragResult OnEnter(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
  virtual wxDragResult OnDragOver(wxCoord  x , wxCoord  y , wxDragResult  def ) ;
  virtual void OnLeave() ;
  void SetDataObject(wxDataObject*  data ) ;
};


#endif
