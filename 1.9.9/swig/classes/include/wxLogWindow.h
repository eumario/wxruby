// wxLogWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLogWindow_h_)
#define _wxLogWindow_h_
class wxLogWindow : public wxLogPassThrough
{
public:
	/**
	 * \brief Creates the log frame window and starts collecting the messages in it. 
	 * \param wxFrame   
	 * \param const wxChar   
	 * \param bool   
	 * \param bool   
	*/

   wxLogWindow(wxFrame  *parent , const wxChar  *title , bool  show = true, bool  passToOld = true) ;
	/**
	 * \brief Shows or hides the frame. 
	 * \param bool   
	*/

  void Show(bool  show = true) ;
	/**
	 * \brief Returns the associated log frame window. This may be used to position or resize
it but use   to show or hide it. 
	*/

  wxFrame * GetFrame() const;
	/**
	 * \brief Called immediately after the log frame creation allowing for
any extra initializations. 
	 * \param wxFrame   
	*/

  virtual void OnFrameCreate(wxFrame  *frame ) ;
	/**
	 * \brief Called if the user closes the window interactively, will not be
called if it is destroyed for another reason (such as when program
exits).

Return   from here to allow the frame to close,   to
prevent this from happening. 
	 * \param wxFrame   
	*/

  virtual void OnFrameClose(wxFrame  *frame ) ;
	/**
	 * \brief Called right before the log frame is going to be deleted: will
always be called unlike  . 
	 * \param wxFrame   
	*/

  virtual void OnFrameDelete(wxFrame  *frame ) ;
};


#endif
