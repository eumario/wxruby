// wxHtmlParser.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlParser_h_)
#define _wxHtmlParser_h_
class wxHtmlParser : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlParser() ;
	/**
	 * \brief This may (and may not) be overwritten in derived class.

This method is called each time new tag is about to be added. 
  contains information about the tag. (See  
for details.)

Default (wxHtmlParser) behaviour is this:
First it finds a handler capable of handling this tag and then it calls
handler's HandleTag method. 
	 * \param const wxHtmlTag&   
	*/

  void AddTag(const wxHtmlTag&  tag ) ;
	/**
	 * \brief Adds handler to the internal list (&amp; hash table) of handlers. This
method should not be called directly by user but rather by derived class'
constructor.

This adds the handler to this   of wxHtmlParser, not to
all objects of this class! (Static front-end to AddTagHandler is provided
by wxHtmlWinParser).

All handlers are deleted on object deletion. 
	 * \param wxHtmlTagHandler   
	*/

  virtual void AddTagHandler(wxHtmlTagHandler  *handler ) ;
	/**
	 * \brief Must be overwritten in derived class.

This method is called by  
each time a part of text is parsed.   is NOT only one word, it is
substring of input. It is not formatted or preprocessed (so white spaces are
unmodified). 
	 * \param const char*   
	*/

  virtual void AddText(const char*  txt ) ;
	/**
	 * \brief  
	 * \param int   
	 * \param int   
	*/

  void DoParsing(int  begin_pos , int  end_pos ) ;
	/**
	 * \brief Parses the m_Source from begin_pos to end_pos-1.
(in noparams version it parses whole m_Source) 
	*/

  void DoParsing() ;
	/**
	 * \brief This must be called after DoParsing(). 
	*/

  virtual void DoneParser() ;
	/**
	 * \brief Returns pointer to the file system. Because each tag handler has
reference to it is parent parser it can easily request the file by
calling 
	*/

  wxFileSystem* GetFS() const;
	/**
	 * \brief Returns product of parsing. Returned value is result of parsing
of the document. The type of this result depends on internal
representation in derived parser (but it must be derived from wxObject!).

See wxHtmlWinParser for details. 
	*/

  virtual wxObject* GetProduct() ;
	/**
	 * \brief Returns pointer to the source being parsed. 
	*/

  wxString* GetSource() ;
	/**
	 * \brief Setups the parser for parsing the   string. (Should be overridden
in derived class) 
	 * \param const wxString&   
	*/

  virtual void InitParser(const wxString&  source ) ;
	/**
	 * \brief Opens given URL and returns   object that can be used to read data
from it. This method may return NULL in one of two cases: either the URL doesn't
point to any valid resource or the URL is blocked by overridden implementation
of   in derived class. 
	 * \param wxHtmlURLType   
	 * \param const wxString&   
	*/

  virtual wxFSFile* OpenURL(wxHtmlURLType  type , const wxString&  url ) ;
	/**
	 * \brief Proceeds parsing of the document. This is end-user method. You can simply
call it when you need to obtain parsed output (which is parser-specific)

The method does these things:

\begin{enumerate}\itemsep=0pt
\item calls  
\item calls  
\item calls  
\item calls  
\item returns value returned by GetProduct
\end{enumerate}

You shouldn't use InitParser, DoParsing, GetProduct or DoneParser directly. 
	 * \param const wxString&   
	*/

  wxObject* Parse(const wxString&  source ) ;
	/**
	 * \brief Forces the handler to handle additional tags 
(not returned by  ). 
The handler should already be added to this parser. 
	 * \param wxHtmlTagHandler*   
	 * \param wxString   
	*/

  void PushTagHandler(wxHtmlTagHandler*  handler , wxString  tags ) ;
	/**
	 * \brief Restores parser's state before last call to 
 . 
	*/

  void PopTagHandler() ;
	/**
	 * \brief Sets the virtual file system that will be used to request additional
files. (For example   tag handler requests wxFSFile with the
image data.) 
	 * \param wxFileSystem   
	*/

  void SetFS(wxFileSystem  *fs ) ;
	/**
	 * \brief Call this function to interrupt parsing from a tag handler. No more tags
will be parsed afterward. This function may only be called from
  or any function called
by it (i.e. from tag handlers). 
	*/

  void StopParsing() ;
};


#endif
