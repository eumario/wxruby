// wxHtmlLinkInfo.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlLinkInfo_h_)
#define _wxHtmlLinkInfo_h_
class wxHtmlLinkInfo : public wxObject
{
public:
	/**
	 * \brief Default ctor. 
	*/

   wxHtmlLinkInfo() ;
	/**
	 * \brief Construct hypertext link from HREF (aka URL) and TARGET (name of target
frame). 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

   wxHtmlLinkInfo(const wxString&  href , const wxString&  target = wxEmptyString) ;
	/**
	 * \brief Return pointer to event that generated OnLinkClicked event. Valid
only within  ,
NULL otherwise. 
	*/

  const wxMouseEvent * GetEvent() ;
	/**
	 * \brief Return pointer to the cell that was clicked. Valid
only within  ,
NULL otherwise. 
	*/

  const wxHtmlCell * GetHtmlCell() ;
	/**
	 * \brief Return   value of the   tag. 
	*/

  wxString GetHref() ;
	/**
	 * \brief Return   value of the   tag (this value
is used to specify in which frame should be the page pointed
by   opened). 
	*/

  wxString GetTarget() ;
};


#endif
