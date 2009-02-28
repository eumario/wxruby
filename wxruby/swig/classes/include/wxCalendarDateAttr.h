// wxCalendarDateAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalendarDateAttr_h_)
#define _wxCalendarDateAttr_h_
class wxCalendarDateAttr
{
public:
	/**
	 * \brief  
	*/

   wxCalendarDateAttr() ;
	/**
	 * \brief  
	 * \param const wxColour&   
	 * \param const wxColour&   
	 * \param const wxColour&   
	 * \param const wxFont&   
	 * \param wxCalendarDateBorder   
	*/

   wxCalendarDateAttr(const wxColour&  colText , const wxColour&  colBack = wxNullColour, const wxColour&  colBorder = wxNullColour, const wxFont&  font = wxNullFont, wxCalendarDateBorder  border = wxCAL_BORDER_NONE) ;
	/**
	 * \brief The constructors. 
	 * \param wxCalendarDateBorder   
	 * \param const wxColour&   
	*/

   wxCalendarDateAttr(wxCalendarDateBorder  border , const wxColour&  colBorder = wxNullColour) ;
	/**
	 * \brief Sets the text (foreground) colour to use. 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  colText ) ;
	/**
	 * \brief Sets the text background colour to use. 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  colBack ) ;
	/**
	 * \brief Sets the border colour to use. 
	 * \param const wxColour&   
	*/

  void SetBorderColour(const wxColour&  col ) ;
	/**
	 * \brief Sets the font to use. 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font ) ;
	/**
	 * \brief Sets the 
	 * \param wxCalendarDateBorder   
	*/

  void SetBorder(wxCalendarDateBorder  border ) ;
	/**
	 * \brief Display the date with this attribute as a holiday. 
	 * \param bool   
	*/

  void SetHoliday(bool  holiday ) ;
	/**
	 * \brief Returns   if this item has a non default text foreground colour. 
	*/

  bool HasTextColour() const;
	/**
	 * \brief Returns   if this attribute specifies a non default text background colour. 
	*/

  bool HasBackgroundColour() const;
	/**
	 * \brief Returns   if this attribute specifies a non default border colour. 
	*/

  bool HasBorderColour() const;
	/**
	 * \brief Returns   if this attribute specifies a non default font. 
	*/

  bool HasFont() const;
	/**
	 * \brief Returns   if this attribute specifies a non default (i.e. any) border. 
	*/

  bool HasBorder() const;
	/**
	 * \brief Returns   if this attribute specifies that this item should be
displayed as a holiday. 
	*/

  bool IsHoliday() const;
	/**
	 * \brief Returns the text colour to use for the item with this attribute. 
	*/

  const wxColour& GetTextColour() const;
	/**
	 * \brief Returns the background colour to use for the item with this attribute. 
	*/

  const wxColour& GetBackgroundColour() const;
	/**
	 * \brief Returns the border colour to use for the item with this attribute. 
	*/

  const wxColour& GetBorderColour() const;
	/**
	 * \brief Returns the font to use for the item with this attribute. 
	*/

  const wxFont& GetFont() const;
	/**
	 * \brief Returns the   to use for the item with this attribute. 
	*/

  wxCalendarDateBorder GetBorder() const;
};


#endif
