// wxTipWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTipWindow_h_)
#define _wxTipWindow_h_
class wxTipWindow : public wxWindow
{
public:
	/**
	 * \brief Constructor. The tip is shown immediately the window is constructed. 
	 * \param wxWindow*   
	 * \param const wxString&   
	 * \param wxCoord   
	 * \param wxTipWindow**   
	*/

  wxTipWindow(wxWindow*  parent , const wxString&  text , wxCoord  maxLength = 100, wxTipWindow**  windowPtr = NULL );
	/**
	 * \brief When the tip window closes itself (which may happen at any moment and
unexpectedly to the caller) it may   out the pointer pointed to by 
 . This is helpful to avoid dereferencing the tip window which
had been already closed and deleted. 
	 * \param wxTipWindow**   
	*/

  void SetTipWindowPtr(wxTipWindow**  windowPtr ) ;
	/**
	 * \brief By default, the tip window disappears when the user clicks the mouse or presses
a keyboard key or if it loses focus in any other way - for example because the
user switched to another application window.

Additionally, if a non empty   is provided, the tip window will
also automatically close if the mouse leaves this area. This is useful to
dismiss the tip mouse when the mouse leaves the object it is associated with. 
	 * \param const wxRect&   
	*/

  void SetBoundingRect(const wxRect&  rectBound ) ;
};


#endif
