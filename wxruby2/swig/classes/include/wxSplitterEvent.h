// wxSplitterEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSplitterEvent_h_)
#define _wxSplitterEvent_h_
class wxSplitterEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor. Used internally by wxWindows only. 
	 * \param wxEventType  
	 * \param wxSplitterWindow *  
	*/

   wxSplitterEvent(wxEventType eventType = wxEVT_NULL, wxSplitterWindow * splitter = NULL) ;
	/**
	 * \brief Returns the new sash position.

May only be called while processing
wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING and
wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED events. 
	*/

  int GetSashPosition() const;
	/**
	 * \brief Returns the x coordinate of the double-click point.

May only be called while processing
wxEVT_COMMAND_SPLITTER_DOUBLECLICKED events. 
	*/

  int GetX() const;
	/**
	 * \brief Returns the y coordinate of the double-click point.

May only be called while processing
wxEVT_COMMAND_SPLITTER_DOUBLECLICKED events. 
	*/

  int GetY() const;
	/**
	 * \brief Returns a pointer to the window being removed when a splitter window
is unsplit.

May only be called while processing
wxEVT_COMMAND_SPLITTER_UNSPLIT events. 
	*/

  wxWindow* GetWindowBeingRemoved() const;
	/**
	 * \brief In the case of wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED events,
sets the the new sash position. In the case of
wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING events, sets the new
tracking bar position so visual feedback during dragging will
represent that change that will actually take place. Set to -1 from
the event handler code to prevent repositioning.

May only be called while processing
wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING and
wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED events. 
	 * \param int  
	*/

  void SetSashPosition(int  pos ) ;
};


#endif
