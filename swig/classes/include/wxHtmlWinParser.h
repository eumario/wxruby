// wxHtmlWinParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlWinParser_h_)
#define _wxHtmlWinParser_h_
class wxHtmlWinParser : public wxHtmlParser
{
public:
   wxHtmlWinParser() ;
   wxHtmlWinParser(wxHtmlWindow  *wnd ) ;
  static void AddModule(wxHtmlTagsModule  *module ) ;
  wxHtmlContainerCell* CloseContainer() ;
  virtual wxFont* CreateCurrentFont() ;
  const wxColour& GetActualColor() const;
  int GetAlign() const;
  int GetCharHeight() const;
  int GetCharWidth() const;
  wxHtmlContainerCell* GetContainer() const;
  wxDC* GetDC() ;
  wxEncodingConverter * GetEncodingConverter() const;
  int GetFontBold() const;
  wxString GetFontFace() const;
  int GetFontFixed() const;
  int GetFontItalic() const;
  int GetFontSize() const;
  int GetFontUnderlined() const;
  wxFontEncoding GetInputEncoding() const;
  const wxHtmlLinkInfo& GetLink() const;
  const wxColour& GetLinkColor() const;
  wxFontEncoding GetOutputEncoding() const;
  wxHtmlWindow* GetWindow() ;
  wxHtmlContainerCell* OpenContainer() ;
  void SetActualColor(const wxColour&  clr ) ;
  void SetAlign(int  a ) ;
  wxHtmlContainerCell* SetContainer(wxHtmlContainerCell * c ) ;
  virtual void SetDC(wxDC  *dc , double  pixel_scale = 1.0) ;
  void SetFontBold(int  x ) ;
  void SetFontFace(const wxString&  face ) ;
  void SetFontFixed(int  x ) ;
  void SetFontItalic(int  x ) ;
  void SetFontSize(int  s ) ;
  void SetFontUnderlined(int  x ) ;
  void SetFonts(wxString  normal_face , wxString  fixed_face , const int  *sizes = NULL) ;
  void SetInputEncoding(wxFontEncoding  enc ) ;
  void SetLink(const wxHtmlLinkInfo&  link ) ;
  void SetLinkColor(const wxColour&  clr ) ;
};


#endif
