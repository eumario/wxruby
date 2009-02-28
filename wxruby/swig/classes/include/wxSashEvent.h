// wxSashEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSashEvent_h_)
#define _wxSashEvent_h_
class wxSashEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param int   
	 * \param wxSashEdgePosition  
	*/

   wxSashEvent(int  id = 0, wxSashEdgePosition edge = wxSASH_NONE) ;
	/**
	 * \brief Returns the dragged edge. The return value is one of wxSASH_TOP, wxSASH_RIGHT, wxSASH_BOTTOM, wxSASH_LEFT. 
	*/

  wxSashEdgePosition GetEdge() const;
	/**
	 * \brief Returns the rectangle representing the new size the window would be if the resize was applied. It is
up to the application to set the window size if required. 
	*/

  wxRect GetDragRect() const;
	/**
	 * \brief Returns the status of the sash: one of wxSASH_STATUS_OK, wxSASH_STATUS_OUT_OF_RANGE.
If the drag caused the notional bounding box of the window to flip over, for example, the drag will be out of rage. 
	*/

  wxSashDragStatus GetDragStatus() const;
};


#endif
