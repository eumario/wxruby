// wxCalendarCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalendarCtrl_h_)
#define _wxCalendarCtrl_h_
class wxCalendarCtrl : public wxControl
{
public:
   wxCalendarCtrl() ;
   wxCalendarCtrl(wxWindow*  parent , wxWindowID  id , const wxDateTime&  date = wxDefaultDateTime, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCAL_SHOW_HOLIDAYS, const wxString&  name = wxCalendarNameStr) ;
  bool Create(wxWindow*  parent , wxWindowID  id , const wxDateTime&  date = wxDefaultDateTime, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCAL_SHOW_HOLIDAYS, const wxString&  name = wxCalendarNameStr) ;
  virtual  ~wxCalendarCtrl() ;
  void SetDate(const wxDateTime&  date ) ;
  const wxDateTime& GetDate() const;
  void EnableYearChange(bool  enable = true) ;
  void EnableMonthChange(bool  enable = true) ;
  void EnableHolidayDisplay(bool  display = true) ;
  void SetHeaderColours(const wxColour&  colFg , const wxColour&  colBg ) ;
  const wxColour& GetHeaderColourFg() const;
  const wxColour& GetHeaderColourBg() const;
  void SetHighlightColours(const wxColour&  colFg , const wxColour&  colBg ) ;
  const wxColour& GetHighlightColourFg() const;
  const wxColour& GetHighlightColourBg() const;
  void SetHolidayColours(const wxColour&  colFg , const wxColour&  colBg ) ;
  const wxColour& GetHolidayColourFg() const;
  const wxColour& GetHolidayColourBg() const;
  wxCalendarDateAttr * GetAttr(size_t  day ) const;
  void SetAttr(size_t  day , wxCalendarDateAttr*  attr ) ;
  void SetHoliday(size_t  day ) ;
  void ResetAttr(size_t  day ) ;
  wxCalendarHitTestResult HitTest(const wxPoint&  pos , wxDateTime*  date = NULL, wxDateTime::WeekDay*  wd = NULL) ;
};


#endif
