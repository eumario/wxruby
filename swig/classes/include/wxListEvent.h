// wxListEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListEvent_h_)
#define _wxListEvent_h_
class wxListEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE   
	 * \param int   
	*/

   wxListEvent(WXTYPE  commandType = 0, int  id = 0) ;
	/**
	 * \brief For   event only: return the first item which the
list control advises us to cache. 
	*/

  long GetCacheFrom() const;
	/**
	 * \brief For   event only: return the last item (inclusive)
which the list control advises us to cache. 
	*/

  long GetCacheTo() const;
	/**
	 * \brief Key code if the event is a keypress event. 
	*/

  int GetKeyCode() const;
	/**
	 * \brief The item index. 
	*/

  long GetIndex() const;
	/**
	 * \brief The column position: it is only used with   events. For the column
dragging events, it is the column to the left of the divider being dragged, for
the column click events it may be $-1$ if the user clicked in the list control
header outside any column. 
	*/

  int GetColumn() const;
	/**
	 * \brief The position of the mouse pointer if the event is a drag event. 
	*/

  wxPoint GetPoint() const;
	/**
	 * \brief The label. 
	*/

  const wxString& GetLabel() const;
	/**
	 * \brief The text. 
	*/

  const wxString& GetText() const;
	/**
	 * \brief The image. 
	*/

  int GetImage() const;
	/**
	 * \brief The data. 
	*/

  long GetData() const;
	/**
	 * \brief The mask. 
	*/

  long GetMask() const;
	/**
	 * \brief An item object, used by some events. See also  . 
	*/

  const wxListItem& GetItem() const;
};


#endif
