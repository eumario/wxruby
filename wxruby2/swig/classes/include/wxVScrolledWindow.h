// wxVScrolledWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVScrolledWindow_h_)
#define _wxVScrolledWindow_h_
class wxVScrolledWindow : public wxPanel
{
public:
	/**
	 * \brief This is the normal constructor, no need to call Create() after using this one.

Note that   is always automatically added to our style, there is
no need to specify it explicitly. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxVScrolledWindow(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief Default constructor, you must call   
later. 
	*/

   wxVScrolledWindow() ;
	/**
	 * \brief Same as the   but returns
status code:   if ok,   if the window couldn't have been created.

Just as with the ctor above,   style is always used, there is no
need to specify it explicitly. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = wxID_ANY, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = 0, const wxString&  name = wxPanelNameStr) ;
	/**
	 * \brief This protected function is used internally by wxVScrolledWindow to estimate the
total height of the window when   
is called. The default implementation uses the brute force approach if the
number of the items in the control is small enough. Otherwise, it tries to find
the average line height using some lines in the beginning, middle and the end.

If it is undesirable to access all these lines (some of which might be never
shown) just for the total height calculation, you may override the function and
provide your own guess better and/or faster.

Note that although returning a totally wrong value would still work, it risks
to result in very strange scrollbar behaviour so this function should really
try to make the best guess possible. 
	*/

  virtual wxCoord EstimateTotalHeight() const;
	/**
	 * \brief Returns the index of the first currently visible line. 
	*/

  size_t GetFirstVisibleLine() const;
	/**
	 * \brief Returns the index of the last currently visible line. 
	*/

  size_t GetLastVisibleLine() const;
	/**
	 * \brief Get the number of lines this window contains (previously set by 
 ) 
	*/

  size_t GetLineCount() const;
	/**
	 * \brief  
	 * \param wxCoord   
	 * \param wxCoord   
	*/

  int HitTest(wxCoord  x , wxCoord  y ) const;
	/**
	 * \brief Return the item at the specified (in physical coordinates) position or
  if none, i.e. if it is below the last item. 
	 * \param const wxPoint&   
	*/

  int HitTest(const wxPoint&  pt ) const;
	/**
	 * \brief Returns   if the given line is (at least partially) visible or 
  otherwise. 
	 * \param size_t   
	*/

  bool IsVisible(size_t  line ) const;
	/**
	 * \brief This protected virtual function must be overridden in the derived class and it
should return the height of the given line in pixels. 
	 * \param size_t   
	*/

  virtual wxCoord OnGetLineHeight(size_t  n ) const;
	/**
	 * \brief This function doesn't have to be overridden but it may be useful to do
it if calculating the lines heights is a relatively expensive operation
as it gives the user code a possibility to calculate several of them at
once.

  is normally called just before 
  but you
shouldn't rely on the latter being called for all lines in the interval
specified here. It is also possible that OnGetLineHeight() will be
called for the lines outside of this interval, so this is really just a
hint, not a promise.

Finally note that   is inclusive, while   is exclusive,
as usual. 
	 * \param size_t   
	 * \param size_t   
	*/

  virtual void OnGetLinesHint(size_t  lineMin , size_t  lineMax ) const;
	/**
	 * \brief Refreshes the specified line -- it will be redrawn during the next main loop
iteration. 
	 * \param size_t   
	*/

  void RefreshLine(size_t  line ) ;
	/**
	 * \brief Refreshes all lines between   and  , inclusive.  
should be less than or equal to  . 
	 * \param size_t   
	 * \param size_t   
	*/

  void RefreshLines(size_t  from , size_t  to ) ;
	/**
	 * \brief This function completely refreshes the control, recalculating the number of
items shown on screen and repaining them. It should be called when the values
returned by   change
for some reason and the window must be updated to reflect this. 
	*/

  void RefreshAll() ;
	/**
	 * \brief  
	 * \param int   
	*/

  bool ScrollLines(int  lines ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  bool ScrollPages(int  pages ) ;
	/**
	 * \brief Scroll to the specified line: it will become the first visible line in
the window.

Return   if we scrolled the window,   if nothing was done. 
	 * \param size_t   
	*/

  bool ScrollToLine(size_t  line ) ;
	/**
	 * \brief Set the number of lines the window contains: the derived class must
provide the heights for all lines with indices up to the one given here
in its  . 
	 * \param size_t   
	*/

  void SetLineCount(size_t  count ) ;
};


#endif
