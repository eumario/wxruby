// wxDragImage.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDragImage_h_)
#define _wxDragImage_h_
class wxDragImage : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxDragImage() ;
	/**
	 * \brief Constructs a drag image from a bitmap and optional cursor. 
	 * \param const wxBitmap&   
	 * \param const wxCursor&   
	 * \param const wxPoint&   
	*/

   wxDragImage(const wxBitmap&  image , const wxCursor& cursor = wxNullCursor);
	/**
	 * \brief Constructs a drag image from an icon and optional cursor.

\pythonnote{This constructor is called wxDragIcon in wxPython.} 
	 * \param const wxIcon&   
	 * \param const wxCursor&   
	 * \param const wxPoint&   
	*/

   wxDragImage(const wxIcon&  image , const wxCursor&  cursor = wxNullCursor);
	/**
	 * \brief Constructs a drag image from a text string and optional cursor.

\pythonnote{This constructor is called wxDragString in wxPython.} 
	 * \param const wxString&   
	 * \param const wxCursor&   
	 * \param const wxPoint&   
	*/

   wxDragImage(const wxString&  text , const wxCursor&  cursor = wxNullCursor);
	/**
	 * \brief Constructs a drag image from the text in the given tree control item, and optional cursor.

\pythonnote{This constructor is called wxDragTreeItem in wxPython.} 
	 * \param const wxTreeCtrl&   
	 * \param wxTreeItemId&   
	*/

   wxDragImage(const wxTreeCtrl&  treeCtrl , wxTreeItemId&  id ) ;
	/**
	 * \brief Constructs a drag image from the text in the given tree control item, and optional cursor.

\pythonnote{This constructor is called wxDragListItem in wxPython.} 
	 * \param const wxListCtrl&   
	 * \param long   
	*/

   wxDragImage(const wxListCtrl&  treeCtrl , long  id ) ;
	/**
	 * \brief Constructs a drag image an optional cursor. This constructor is only available for
wxGenericDragImage, and can be used when the application
supplies   and  . 
	 * \param const wxCursor&   
	 * \param const wxPoint&   
	*/

#if !defined(__WXMSW__) || defined(__WXUNIVERSAL__)
   wxDragImage(const wxCursor&  cursor = wxNullCursor);
#endif
	/**
	 * \brief Start dragging the image, in a window or full screen. 
	 * \param const wxPoint&   
	 * \param wxWindow*   
	 * \param bool  
	 * \param wxRect*  
	*/

  bool BeginDrag(const wxPoint&  hotspot , wxWindow*  window , bool fullScreen = false, wxRect* rect = NULL) ;
	/**
	 * \brief Start dragging the image, using the first window to capture the mouse and the second
to specify the bounding area. This form is equivalent to using the first form,
but more convenient than working out the bounding rectangle explicitly.

You need to then call   
and   to show the image on the screen.

Call   when the drag has finished.

Note that this call automatically calls CaptureMouse. 
	 * \param const wxPoint&   
	 * \param wxWindow*   
	 * \param wxWindow*  
	*/

  bool BeginDrag(const wxPoint&  hotspot , wxWindow*  window , wxWindow*  boundingWindow ) ;
	/**
	 * \brief Draws the image on the device context with top-left corner at the given position.

This function is only available with wxGenericDragImage, to allow applications to
draw their own image instead of using an actual bitmap. If you override this function,
you must also override  . 
	 * \param wxDC&  
	 * \param const wxPoint&  
	*/

#if !defined(__WXMSW__) || defined(__WXUNIVERSAL__)
  virtual bool DoDrawImage(wxDC&  dc , const wxPoint&  pos ) ;
#endif
	/**
	 * \brief Call this when the drag has finished.

Note that this call automatically calls ReleaseMouse. 
	*/

  bool EndDrag() ;
	/**
	 * \brief Returns the rectangle enclosing the image, assuming that the image is drawn with its
top-left corner at the given point.

This function is available in wxGenericDragImage only, and may be overridden (together with 
 ) to provide a virtual drawing capability. 
	 * \param const wxPoint&  
	*/

#if !defined(__WXMSW__) || defined(__WXUNIVERSAL__)
  virtual wxRect GetImageRect(const wxPoint&  pos ) const;
#endif
	/**
	 * \brief Hides the image. You may wish to call this before updating the window
contents (perhaps highlighting an item). Then call   
and  . 
	*/

  bool Hide() ;
	/**
	 * \brief Call this to move the image to a new position. The image will only be shown if 
  has been called previously (for example
at the start of the drag).

  is the position in client coordinates (relative to the window specified in BeginDrag).

You can move the image either when the image is hidden or shown, but in general dragging
will be smoother if you move the image when it is shown. 
	 * \param const wxPoint&   
	*/

  bool Move(const wxPoint&  pt ) ;
	/**
	 * \brief Shows the image. Call this at least once when dragging. 
	*/

  bool Show() ;
	/**
	 * \brief Override this if you wish to draw the window contents to the backing bitmap
yourself. This can be desirable if you wish to avoid flicker by not having to
redraw the updated window itself just before dragging, which can cause a flicker just
as the drag starts. Instead, paint the drag image's backing bitmap to show the appropriate
graphic  , and leave the window itself to be updated
by the drag image. This can provide eerily smooth, flicker-free drag behaviour.

The default implementation copies the window contents to the backing bitmap. A new
implementation will normally copy information from another source, such as from its
own backing bitmap if it has one, or directly from internal data structures.

This function is available in wxGenericDragImage only. 
	 * \param wxDC&  
	 * \param wxMemoryDC&  
	 * \param const wxRect&  
	 * \param const wxRect&  
	*/

#if !defined(__WXMSW__) || defined(__WXUNIVERSAL__)
  bool UpdateBackingFromWindow(wxDC&  windowDC , wxMemoryDC&  destDC , const wxRect&  sourceRect , const wxRect&  destRect ) const;
#endif
};


#endif
