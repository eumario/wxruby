// wxDropSource.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDropSource_h_)
#define _wxDropSource_h_
class wxDropSource
{
public:
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param const wxIconOrCursor&   
	 * \param const wxIconOrCursor&   
	 * \param const wxIconOrCursor&   
	*/

   wxDropSource(wxWindow* win = NULL, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconNone = wxNullIconOrCursor) ;
	/**
	 * \brief The constructors for wxDataObject.

If you use the constructor without   parameter you must call 
  later.

Note that the exact type of   and subsequent parameters differs
between wxMSW and wxGTK: these are cursors under Windows but icons for GTK.
You should use the macro   in portable
programs instead of directly using either of these types.











  is the window which initiates the drag and drop operation. 
	 * \param wxDataObject&  
	 * \param wxWindow*  
	 * \param const wxIconOrCursor&   
	 * \param const wxIconOrCursor&   
	 * \param const wxIconOrCursor&   
	*/

   wxDropSource(wxDataObject&  data , wxWindow* win = NULL, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconCopy = wxNullIconOrCursor, const wxIconOrCursor&  iconNone = wxNullIconOrCursor) ;
	/**
	 * \brief  
	*/

  virtual  ~wxDropSource() ;
	/**
	 * \brief Sets the data   associated with the 
drop source. This will not delete any previously associated data. 
	 * \param wxDataObject&  
	*/

  void SetData(wxDataObject&  data ) ;
	/**
	 * \brief Do it (call this in response to a mouse button press, for example). This starts
the drag-and-drop operation which will terminate when the user releases the
mouse.



. 
	 * \param int   
	*/

  virtual wxDragResult DoDragDrop(int  flags = wxDrag_CopyOnly) ;
	/**
	 * \brief Overridable: you may give some custom UI feedback during the drag and drop operation
in this function. It is called on each mouse move, so your implementation must not be too
slow. 
	 * \param wxDragResult   
	 * \param bool   
	*/

  virtual bool GiveFeedback(wxDragResult  effect , bool  scrolling ) ;
};


#endif
