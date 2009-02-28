// wxHtmlHelpData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpData_h_)
#define _wxHtmlHelpData_h_
class wxHtmlHelpData : public wxObject
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxHtmlHelpData() ;
	/**
	 * \brief Adds new book.   is URL (not filename!) of HTML help project (hhp)
or ZIP file that contains arbitrary number of .hhp projects (this zip
file can have either .zip or .htb extension, htb stands for &quot;html book&quot;).
Returns success. 
	 * \param const wxString&   
	*/

  bool AddBook(const wxString&  book_url ) ;
	/**
	 * \brief Returns page's URL based on integer ID stored in project. 
	 * \param int   
	*/

  wxString FindPageById(int  id ) ;
	/**
	 * \brief Returns page's URL based on its (file)name. 
	 * \param const wxString&   
	*/

  wxString FindPageByName(const wxString&  page ) ;
	/**
	 * \brief Returns array with help books info. 
	*/

  const wxHtmlBookRecArray& GetBookRecArray() ;
	/**
	 * \brief Returns contents lists pointer. 
	*/

  wxHtmlContentsItem* GetContents() ;
	/**
	 * \brief Returns size of contents list. 
	*/

  int GetContentsCnt() ;
	/**
	 * \brief Returns pointer to index items list. 
	*/

  wxHtmlContentsItem* GetIndex() ;
	/**
	 * \brief Returns size of index list. 
	*/

  int GetIndexCnt() ;
	/**
	 * \brief Sets temporary directory where binary cached versions of MS HTML Workshop
files will be stored. (This is turned off by default and you can enable
this feature by setting non-empty temp dir.) 
	 * \param const wxString&   
	*/

  void SetTempDir(const wxString&  path ) ;
};


#endif
