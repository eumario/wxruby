// wxTreeEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTreeEvent_h_)
#define _wxTreeEvent_h_
class wxTreeEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	*/

   wxTreeEvent(WXTYPE  commandType = 0, int  id = 0) ;
	/**
	 * \brief Returns the key code if the event was is a key event. Use 
  to get the values of the
modifier keys for this event (i.e. Shift or Ctrl). 
	*/

  int GetKeyCode() const;
	/**
	 * \brief Returns the item (valid for all events). 
	*/

  wxTreeItemId GetItem() const;
	/**
	 * \brief Returns the key event for   events. 
	*/

  const wxKeyEvent& GetKeyEvent() const;
	/**
	 * \brief Returns the label if the event was a begin or end edit label event. 
	*/

  const wxString& GetLabel() const;
	/**
	 * \brief Returns the old item index (valid for EVT_TREE_ITEM_CHANGING and CHANGED events) 
	*/

  wxTreeItemId GetOldItem() const;
	/**
	 * \brief Returns the position of the mouse pointer if the event is a drag event. 
	*/

  wxPoint GetPoint()() const;
	/**
	 * \brief Returns true if the label edit was cancelled. This should be
called from within an EVT_TREE_END_LABEL_EDIT handler. 
	*/

  bool IsEditCancelled()() const;
};


#endif
