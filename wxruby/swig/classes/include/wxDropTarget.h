// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDropTarget_h_)
#define _wxDropTarget_h_
class wxDropTarget
{
public:
   wxDropTarget(wxDataObject* data = NULL) ;
  virtual  ~wxDropTarget() ;
  virtual bool GetData() ;
  virtual wxDragResult OnData(wxCoord x, wxCoord y, wxDragResult def) = 0;
  virtual bool OnDrop(wxCoord x, wxCoord y) ;
  virtual wxDragResult OnEnter(wxCoord x , wxCoord y, wxDragResult  def);
  virtual wxDragResult OnDragOver(wxCoord x, wxCoord y, wxDragResult  def);
  virtual void OnLeave() ;
  wxDataObject *GetDataObject() const;
  void SetDataObject(wxDataObject*  data ) ;
};


#endif
