// wxSplashScreen.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSplashScreen_h_)
#define _wxSplashScreen_h_
class wxSplashScreen : public wxFrame
{
public:
	/**
	 * \brief Construct the splash screen passing a bitmap, a style, a timeout, a window id, optional position
and size, and a window style.

  is a bitlist of some of the following:

 

  is the timeout in milliseconds. 
	 * \param const wxBitmap&   
	 * \param long   
	 * \param int   
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	*/

   wxSplashScreen(const wxBitmap&  bitmap , long  splashStyle , int  milliseconds , wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP) ;
	/**
	 * \brief Destroys the splash screen. 
	*/

  virtual  ~wxSplashScreen() ;
	/**
	 * \brief Reimplement this event handler if you want to set an application variable on window destruction, for example. 
	 * \param wxCloseEvent&   
	*/

  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
	/**
	 * \brief Returns the splash style (see   for
details). 
	*/

  long GetSplashStyle() const;
	/**
	 * \brief Returns the window used to display the bitmap. 
	*/

  wxSplashScreenWindow* GetSplashWindow() const;
	/**
	 * \brief Returns the timeout in milliseconds. 
	*/

  int GetTimeout() const;
};


#endif
