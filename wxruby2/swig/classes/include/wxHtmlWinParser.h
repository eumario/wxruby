// wxHtmlWinParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlWinParser_h_)
#define _wxHtmlWinParser_h_
class wxHtmlWinParser : public wxHtmlParser
{
public:
	/**
	 * \brief  
	*/

   wxHtmlWinParser() ;
	/**
	 * \brief Constructor. Don't use the default one, use constructor with
  parameter (  is pointer to associated  ) 
	 * \param wxHtmlWindow   
	*/

   wxHtmlWinParser(wxHtmlWindow  *wnd ) ;
	/**
	 * \brief Adds   to the list of wxHtmlWinParser tag handler. 
	 * \param wxHtmlTagsModule   
	*/

  static void AddModule(wxHtmlTagsModule  *module ) ;
	/**
	 * \brief Closes the container, sets actual container to the parent one
and returns pointer to it (see  ). 
	*/

  wxHtmlContainerCell* CloseContainer() ;
	/**
	 * \brief Creates font based on current setting (see 
 , 
 , 
 , 
 , 
 )
and returns pointer to it.
If the font was already created only a pointer is returned. 
	*/

  virtual wxFont* CreateCurrentFont() ;
	/**
	 * \brief Returns actual text colour. 
	*/

  const wxColour& GetActualColor() const;
	/**
	 * \brief Returns default horizontal alignment. 
	*/

  int GetAlign() const;
	/**
	 * \brief Returns (average) char height in standard font. It is used as DC-independent metrics.

  This function doesn't return the   height. If you want to
know the height of the current font, call  . 
	*/

  int GetCharHeight() const;
	/**
	 * \brief Returns average char width in standard font. It is used as DC-independent metrics.

  This function doesn't return the   width. If you want to
know the height of the current font, call 
	*/

  int GetCharWidth() const;
	/**
	 * \brief Returns pointer to the currently opened container (see  ).
Common use: 
	*/

  wxHtmlContainerCell* GetContainer() const;
	/**
	 * \brief Returns pointer to the DC used during parsing. 
	*/

  wxDC* GetDC() ;
	/**
	 * \brief Returns   class used
to do conversion between   
and  . 
	*/

  wxEncodingConverter * GetEncodingConverter() const;
	/**
	 * \brief Returns true if actual font is bold, false otherwise. 
	*/

  int GetFontBold() const;
	/**
	 * \brief Returns actual font face name. 
	*/

  wxString GetFontFace() const;
	/**
	 * \brief Returns true if actual font is fixed face, false otherwise. 
	*/

  int GetFontFixed() const;
	/**
	 * \brief Returns true if actual font is italic, false otherwise. 
	*/

  int GetFontItalic() const;
	/**
	 * \brief Returns actual font size (HTML size varies from -2 to +4) 
	*/

  int GetFontSize() const;
	/**
	 * \brief Returns true if actual font is underlined, false otherwise. 
	*/

  int GetFontUnderlined() const;
	/**
	 * \brief Returns input encoding. 
	*/

  wxFontEncoding GetInputEncoding() const;
	/**
	 * \brief Returns actual hypertext link. (This value has a non-empty 
  string
if the parser is between   and   tags,
wxEmptyString otherwise.) 
	*/

  const wxHtmlLinkInfo& GetLink() const;
	/**
	 * \brief Returns the colour of hypertext link text. 
	*/

  const wxColour& GetLinkColor() const;
	/**
	 * \brief Returns output encoding, i.e. closest match to document's input encoding
that is supported by operating system. 
	*/

  wxFontEncoding GetOutputEncoding() const;
	/**
	 * \brief Returns associated window (wxHtmlWindow). This may be NULL! (You should always
test if it is non-NULL. For example   handler sets window
title only if some window is associated, otherwise it does nothing) 
	*/

  wxHtmlWindow* GetWindow() ;
	/**
	 * \brief Opens new container and returns pointer to it (see  ). 
	*/

  wxHtmlContainerCell* OpenContainer() ;
	/**
	 * \brief Sets actual text colour. Note: this DOESN'T change the colour!
You must create   yourself. 
	 * \param const wxColour&   
	*/

  void SetActualColor(const wxColour&  clr ) ;
	/**
	 * \brief Sets default horizontal alignment (see 
 .)
Alignment of newly opened container is set to this value. 
	 * \param int   
	*/

  void SetAlign(int  a ) ;
	/**
	 * \brief Allows you to directly set opened container. This is not recommended - you should use OpenContainer
wherever possible. 
	 * \param wxHtmlContainerCell *  
	*/

  wxHtmlContainerCell* SetContainer(wxHtmlContainerCell * c ) ;
	/**
	 * \brief Sets the DC. This must be called before  !
   can be used when rendering to high-resolution 
DCs (e.g. printer) to adjust size of pixel metrics. (Many dimensions in 
HTML are given in pixels -- e.g. image sizes. 300x300 image would be only one
inch wide on typical printer. With pixel_scale = 3.0 it would be 3 inches.) 
	 * \param wxDC   
	 * \param double   
	*/

  virtual void SetDC(wxDC  *dc , double  pixel_scale = 1.0) ;
	/**
	 * \brief Sets bold flag of actualfont.   is either true of false. 
	 * \param int   
	*/

  void SetFontBold(int  x ) ;
	/**
	 * \brief Sets current font face to  . This affects either fixed size
font or proportional, depending on context (whether the parser is 
inside   tag or not). 
	 * \param const wxString&   
	*/

  void SetFontFace(const wxString&  face ) ;
	/**
	 * \brief Sets fixed face flag of actualfont.   is either true of false. 
	 * \param int   
	*/

  void SetFontFixed(int  x ) ;
	/**
	 * \brief Sets italic flag of actualfont.   is either true of false. 
	 * \param int   
	*/

  void SetFontItalic(int  x ) ;
	/**
	 * \brief Sets actual font size (HTML size varies from 1 to 7) 
	 * \param int   
	*/

  void SetFontSize(int  s ) ;
	/**
	 * \brief Sets underlined flag of actualfont.   is either true of false. 
	 * \param int   
	*/

  void SetFontUnderlined(int  x ) ;
	/**
	 * \brief Sets fonts. See   for
detailed description. 
	 * \param wxString   
	 * \param wxString   
	 * \param const int   
	*/

  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
	/**
	 * \brief Sets input encoding. The parser uses this information to build conversion
tables from document's encoding to some encoding supported by operating
system. 
	 * \param wxFontEncoding   
	*/

  void SetInputEncoding(wxFontEncoding  enc ) ;
	/**
	 * \brief Sets actual hypertext link. Empty link is represented
by   with   equal
to wxEmptyString. 
	 * \param const wxHtmlLinkInfo&   
	*/

  void SetLink(const wxHtmlLinkInfo&  link ) ;
	/**
	 * \brief Sets colour of hypertext link. 
	 * \param const wxColour&   
	*/

  void SetLinkColor(const wxColour&  clr ) ;
};


#endif
