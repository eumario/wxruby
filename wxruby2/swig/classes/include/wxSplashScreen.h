// wxSplashScreen.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSplashScreen_h_)
#define _wxSplashScreen_h_
class wxSplashScreen : public wxFrame
{
public:
   wxSplashScreen(const wxBitmap&  bitmap , long  splashStyle , int  milliseconds , wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSIMPLE_BORDER|wxFRAME_NO_TASKBAR|wxSTAY_ON_TOP) ;
  virtual  ~wxSplashScreen() ;
  virtual void OnCloseWindow(wxCloseEvent&  event ) ;
  long GetSplashStyle() const;
  wxSplashScreenWindow* GetSplashWindow() const;
  int GetTimeout() const;
};


#endif
