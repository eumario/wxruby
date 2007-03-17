// wxHtmlTagHandler.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlTagHandler_h_)
#define _wxHtmlTagHandler_h_
class wxHtmlTagHandler : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlTagHandler() ;
	/**
	 * \brief Returns list of supported tags. The list is in uppercase and tags
are delimited by ','. Example : 
	*/

  virtual wxString GetSupportedTags() ;
	/**
	 * \brief This is the core method of each handler. It is called each time
one of supported tags is detected.   contains all necessary
info (see   for details). 
	 * \param const wxHtmlTag&   
	*/

  virtual bool HandleTag(const wxHtmlTag&  tag ) ;
	/**
	 * \brief This method calls parser's   method
for the string between this tag and the paired ending tag:

 

In this example, a call to ParseInner (with   pointing to A tag)
will parse 'Hello, world!'. 
	 * \param const wxHtmlTag&   
	*/

  void ParseInner(const wxHtmlTag&  tag ) ;
	/**
	 * \brief Assigns   to this handler. Each   of handler 
is guaranteed to be called only from the parser. 
	 * \param wxHtmlParser   
	*/

  virtual void SetParser(wxHtmlParser  *parser ) ;
};


#endif
