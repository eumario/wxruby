// wxDragImage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDragImage_h_)
#define _wxDragImage_h_
class wxDragImage : public wxObject
{
public:
   wxDragImage() ;
   wxDragImage(const wxBitmap&  image , const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0,) ;
   wxDragImage(const wxIcon&  image , const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0,) ;
   wxDragImage(const wxString&  text , const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0,) ;
   wxDragImage(const wxTreeCtrl&  treeCtrl , wxTreeItemId&  id ) ;
   wxDragImage(const wxListCtrl&  treeCtrl , long  id ) ;
   wxDragImage(const wxCursor&  cursor = wxNullCursor, const wxPoint&  cursorHotspot = wxPoint(0,) ;
  bool BeginDrag(const wxPoint&  hotspot , wxWindow*  window , bool fullScreen = false, wxRect* rect = NULL) ;
  bool BeginDrag(const wxPoint&  hotspot , wxWindow*  window , wxWindow*  boundingWindow ) ;
  virtual bool DoDrawImage(wxDC&  dc , const wxPoint&  pos ) ;
  bool EndDrag() ;
  virtual wxRect GetImageRect(const wxPoint&  pos ) const;
  bool Hide() ;
  bool Move(const wxPoint&  pt ) ;
  bool Show() ;
  bool UpdateBackingFromWindow(wxDC&  windowDC , wxMemoryDC&  destDC , const wxRect&  sourceRect , const wxRect&  destRect ) const;
};


#endif
