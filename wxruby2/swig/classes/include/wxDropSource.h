// wxDropSource.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropSource_h_)
#define _wxDropSource_h_
class wxDropSource
{
public:
   wxDropSource(wxWindow* win = NULL, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconNone = wxNullIconOrCursor) ;
   wxDropSource(wxDataObject&  data , wxWindow* win = NULL, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconNone = wxNullIconOrCursor) ;
  virtual  ~wxDropSource() ;
  void SetData(wxDataObject&  data ) ;
  virtual wxDragResult DoDragDrop(int  flags = wxDrag_CopyOnly) ;
  virtual bool GiveFeedback(wxDragResult  effect , bool  scrolling ) ;
};


#endif
