// wxHtmlTagHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlTagHandler_h_)
#define _wxHtmlTagHandler_h_
class wxHtmlTagHandler : public wxObject
{
public:
   wxHtmlTagHandler() ;
  virtual wxString GetSupportedTags() ;
  virtual bool HandleTag(const wxHtmlTag&  tag ) ;
  void ParseInner(const wxHtmlTag&  tag ) ;
  virtual void SetParser(wxHtmlParser  *parser ) ;
};


#endif
