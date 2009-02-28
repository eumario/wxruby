// wxHtmlFilter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlFilter_h_)
#define _wxHtmlFilter_h_
class wxHtmlFilter : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlFilter() ;
	/**
	 * \brief Returns true if this filter is capable of reading file  .

Example: 
	 * \param const wxFSFile&   
	*/

  bool CanRead(const wxFSFile&  file ) ;
	/**
	 * \brief Reads the file and returns string with HTML document.

Example: 
	 * \param const wxFSFile&   
	*/

  wxString ReadFile(const wxFSFile&  file ) ;
};


#endif
