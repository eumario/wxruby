// wxHtmlTag.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlTag_h_)
#define _wxHtmlTag_h_
class wxHtmlTag : public wxObject
{
public:
	/**
	 * \brief Constructor. You will probably never have to construct a wxHtmlTag object
yourself. Feel free to ignore the constructor parameters.
Have a look at src/html/htmlpars.cpp if you're interested in creating it. 
	 * \param const wxString&   
	 * \param int   
	 * \param int   
	 * \param wxHtmlTagsCache*   
	*/

   wxHtmlTag(const wxString&  source , int  pos , int  end_pos , wxHtmlTagsCache*  cache ) ;
	/**
	 * \brief Returns a string containing all parameters.

Example : tag contains  . Call to
tag.GetAllParams() would return  . 
	*/

  const wxString& GetAllParams() const;
	/**
	 * \brief Returns beginning position of the text   this tag and paired
ending tag. 
See explanation (returned position is marked with `|'): 
	*/

  int GetBeginPos() const;
	/**
	 * \brief Returns ending position of the text   this tag and paired
ending tag.
See explanation (returned position is marked with `|'): 
	*/

  int GetEndPos1() const;
	/**
	 * \brief Returns ending position 2 of the text   this tag and paired
ending tag.
See explanation (returned position is marked with `|'): 
	*/

  int GetEndPos2() const;
	/**
	 * \brief Returns tag's name. The name is always in uppercase and it doesn't contain
'&lt;' or '/' characters. (So the name of   tag is &quot;FONT&quot;
and name of   is &quot;TABLE&quot;) 
	*/

  wxString GetName() const;
	/**
	 * \brief Returns the value of the parameter. You should check whether the
parameter exists or not (use  ) first. 
	 * \param const wxString&   
	 * \param bool   
	*/

  wxString GetParam(const wxString&  par , bool  with_commas = false) const;
	/**
	 * \brief Interprets tag parameter   as colour specification and saves its value
into wxColour variable pointed by  .

Returns true on success and false if   is not colour specification or
if the tag has no such parameter. 
	 * \param const wxString&   
	 * \param wxColour *  
	*/

  bool GetParamAsColour(const wxString&  par , wxColour * clr ) const;
	/**
	 * \brief Interprets tag parameter   as an integer and saves its value
into int variable pointed by  .

Returns true on success and false if   is not an integer or
if the tag has no such parameter. 
	 * \param const wxString&   
	 * \param int *  
	*/

  bool GetParamAsInt(const wxString&  par , int * value ) const;
	/**
	 * \brief Returns true if this tag is paired with ending tag, false otherwise.

See the example of HTML document:

 

In this example tags HTML and BODY have ending tags, first P and BR 
doesn't have ending tag while the second P has. The third P tag (which
is ending itself) of course doesn't have ending tag. 
	*/

  bool HasEnding() const;
	/**
	 * \brief Returns true if the tag has a parameter of the given name. 
Example :   has two parameters named
&quot;SIZE&quot; and &quot;COLOR&quot;. 
	 * \param const wxString&   
	*/

  bool HasParam(const wxString&  par ) const;
	/**
	 * \brief Returns true if this tag is ending one.
(  is ending tag,   is not) 
	*/

  bool IsEnding() const;
	/**
	 * \brief This method scans the given parameter. Usage is exactly the same as sscanf's 
usage except that you don't pass a string but a parameter name as the first
argument
and you can only retrieve one value (i.e. you can use only one &quot;\in  ). 
	 * \param const wxString&   
	 * \param const wxChar *  
	 * \param void *  
	*/

  wxString ScanParam(const wxString&  par , const wxChar * format , void * value ) const;
};


#endif
