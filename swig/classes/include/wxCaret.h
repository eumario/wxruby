// wxCaret.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCaret_h_)
#define _wxCaret_h_
class wxCaret
{
public:
	/**
	 * \brief Default constructor: you must use one of Create() functions later. 
	*/

   wxCaret() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param int   
	 * \param int   
	*/

   wxCaret(wxWindow*  window , int  width , int  height ) ;
	/**
	 * \brief Create the caret of given (in pixels) width and height and associates it
with the given window. 
	 * \param wxWindowBase*   
	 * \param const wxSize&   
	*/

  wxCaret(wxWindow*  window , const wxSize&  size );
	/**
	 * \brief  
	 * \param wxWindowBase*   
	 * \param int   
	 * \param int   
	*/

  bool Create(wxWindowBase*  window , int  width , int  height ) ;
	/**
	 * \brief Create the caret of given (in pixels) width and height and associates it
with the given window (same as constructor). 
	 * \param wxWindowBase*   
	 * \param const wxSize&   
	*/

  bool Create(wxWindowBase*  window , const wxSize&  size ) ;
	/**
	 * \brief Returns the blink time which is measured in milliseconds and is the time elapsed
between 2 inversions of the caret (blink time of the caret is the same
for all carets, so this functions is static). 
	*/

  static int GetBlinkTime() ;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetPosition(int*  x , int*  y ) const;
	/**
	 * \brief Get the caret position (in pixels).

\perlnote{In wxPerl there are two methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	*/

  wxPoint GetPosition() const;
	/**
	 * \brief  
	 * \param int*   
	 * \param int*   
	*/

  void GetSize(int*  width , int*  height ) const;
	/**
	 * \brief Get the caret size.

\perlnote{In wxPerl there are two methods instead of a single overloaded
method:\par
\indented{2cm}{ 
}} 
	*/

  wxSize GetSize() const;
	/**
	 * \brief Get the window the caret is associated with. 
	*/

  wxWindow* GetWindow() const;
	/**
	 * \brief Same as  . 
	*/

  void Hide() ;
	/**
	 * \brief Returns true if the caret was created successfully. 
	*/

  bool IsOk() const;
	/**
	 * \brief Returns true if the caret is visible and false if it is permanently
hidden (if it is is blinking and not shown currently but will be after the
next blink, this method still returns true). 
	*/

  bool IsVisible() const;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void Move(int  x , int  y ) ;
	/**
	 * \brief Move the caret to given position (in logical coordinates). 
	 * \param const wxPoint&   
	*/

  void Move(const wxPoint&  pt ) ;
	/**
	 * \brief Sets the blink time for all the carets. 
	 * \param int   
	*/

  static void SetBlinkTime(int  milliseconds ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void SetSize(int  width , int  height ) ;
	/**
	 * \brief Changes the size of the caret. 
	 * \param const wxSize&   
	*/

  void SetSize(const wxSize&  size ) ;
	/**
	 * \brief Shows or hides the caret. Notice that if the caret was hidden $N$ times, it
must be shown $N$ times as well to reappear on the screen. 
	 * \param bool   
	*/

  void Show(bool  show = true) ;
};


#endif
