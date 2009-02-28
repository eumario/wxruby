// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDropSource_h_)
#define _wxDropSource_h_
class wxDropSource
{
public:
#if defined(__WXGTK__)
   wxDropSource(wxWindow* win = NULL, 
                const wxIcon& iconCopy = wxNullIcon, 
                const wxIcon& iconMove = wxNullIcon, 
                const wxIcon& iconNone = wxNullIcon);

   wxDropSource(wxDataObject& data, 
                wxWindow* win = NULL, 
                const wxIcon& iconCopy = wxNullIcon, 
                const wxIcon& iconMove = wxNullIcon, 
                const wxIcon& iconNone = wxNullIcon);
#else
   wxDropSource(wxWindow* win = NULL, 
                const wxCursor& iconCopy = wxNullCursor, 
                const wxCursor& iconMove = wxNullCursor, 
                const wxCursor& iconNone = wxNullCursor);

   wxDropSource(wxDataObject& data, 
                wxWindow* win = NULL, 
                const wxCursor& iconCopy = wxNullCursor, 
                const wxCursor& iconMove = wxNullCursor, 
                const wxCursor& iconNone = wxNullCursor);
#endif
  virtual  ~wxDropSource();
  wxDataObject* GetDataObject();
  void SetData(wxDataObject& data);
  virtual wxDragResult DoDragDrop(int flags = wxDrag_CopyOnly);
  virtual bool GiveFeedback(wxDragResult effect);
  void SetCursor(wxDragResult res, const wxCursor& cursor);
};


#endif
