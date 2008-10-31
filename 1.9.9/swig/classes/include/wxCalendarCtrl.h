// wxCalendarCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalendarCtrl_h_)
#define _wxCalendarCtrl_h_
class wxCalendarCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor, use   after it. 
	*/

   wxCalendarCtrl() ;
	/**
	 * \brief Does the same as   method. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxDateTime&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxCalendarCtrl(wxWindow*  parent , wxWindowID  id , const wxDateTime&  date = wxDefaultDateTime, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCAL_SHOW_HOLIDAYS | wxWANTS_CHARS, const wxString&  name = wxCalendarNameStr) ;
	/**
	 * \brief Creates the control. See   for the meaning of
the parameters and the control overview for the possible styles. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxDateTime&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxDateTime&  date = wxDefaultDateTime, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCAL_SHOW_HOLIDAYS | wxWANTS_CHARS, const wxString&  name = wxCalendarNameStr) ;
	/**
	 * \brief Destroys the control. 
	*/

  virtual  ~wxCalendarCtrl() ;
	/**
	 * \brief Sets the current date. 
	 * \param const wxDateTime&   
	*/

  void SetDate(const wxDateTime&  date ) ;
	/**
	 * \brief Gets the currently selected date. 
	*/

  const wxDateTime& GetDate() const;
	/**
	 * \brief This function should be used instead of changing  
style bit directly. It allows or disallows the user to change the year
interactively. 
	 * \param bool   
	*/

  void EnableYearChange(bool  enable = true) ;
	/**
	 * \brief This function should be used instead of changing 
  style bit. It allows or disallows the user to
change the month interactively. Note that if the month can not be changed, the
year can not be changed neither. 
	 * \param bool   
	*/

  void EnableMonthChange(bool  enable = true) ;
	/**
	 * \brief This function should be used instead of changing  
style bit directly. It enables or disables the special highlighting of the
holidays. 
	 * \param bool   
	*/

  void EnableHolidayDisplay(bool  display = true) ;
	/**
	 * \brief Set the colours used for painting the weekdays at the top of the control. 
	 * \param const wxColour&   
	 * \param const wxColour&   
	*/

  void SetHeaderColours(const wxColour&  colFg , const wxColour&  colBg ) ;
	/**
	 * \brief Gets the foreground colour of the header part of the calendar window. 
	*/

  const wxColour& GetHeaderColourFg() const;
	/**
	 * \brief Gets the background colour of the header part of the calendar window. 
	*/

  const wxColour& GetHeaderColourBg() const;
	/**
	 * \brief Set the colours to be used for highlighting the currently selected date. 
	 * \param const wxColour&   
	 * \param const wxColour&   
	*/

  void SetHighlightColours(const wxColour&  colFg , const wxColour&  colBg ) ;
	/**
	 * \brief Gets the foreground highlight colour. 
	*/

  const wxColour& GetHighlightColourFg() const;
	/**
	 * \brief Gets the background highlight colour. 
	*/

  const wxColour& GetHighlightColourBg() const;
	/**
	 * \brief Sets the colours to be used for the holidays highlighting (only used if the
window style includes   flag). 
	 * \param const wxColour&   
	 * \param const wxColour&   
	*/

  void SetHolidayColours(const wxColour&  colFg , const wxColour&  colBg ) ;
	/**
	 * \brief Return the foreground colour currently used for holiday highlighting. 
	*/

  const wxColour& GetHolidayColourFg() const;
	/**
	 * \brief Return the background colour currently used for holiday highlighting. 
	*/

  const wxColour& GetHolidayColourBg() const;
	/**
	 * \brief Returns the attribute for the given date (should be in the range $1\ldots31$).

The returned pointer may be  . 
	 * \param size_t   
	*/

  wxCalendarDateAttr * GetAttr(size_t  day ) const;
	/**
	 * \brief Associates the attribute with the specified date (in the range $1\ldots31$).

If the pointer is  , the items attribute is cleared. 
	 * \param size_t   
	 * \param wxCalendarDateAttr*   
	*/

  void SetAttr(size_t  day , wxCalendarDateAttr*  attr ) ;
	/**
	 * \brief Marks the specified day as being a holiday in the current month. 
	 * \param size_t   
	*/

  void SetHoliday(size_t  day ) ;
	/**
	 * \brief Clears any attributes associated with the given day (in the range
$1\ldots31$). 
	 * \param size_t   
	*/

  void ResetAttr(size_t  day ) ;
	/**
	 * \brief Returns one of   
  and fills either   or 
  pointer with the corresponding value depending on the hit test code. 
	 * \param const wxPoint&   
	 * \param wxDateTime*   
	 * \param wxDateTime::WeekDay*   
	*/

  wxCalendarHitTestResult HitTest(const wxPoint&  pos , wxDateTime*  date = NULL, wxDateTime::WeekDay*  wd = NULL) ;
};


#endif
