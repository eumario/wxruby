// wxHtmlHelpData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHtmlHelpData_h_)
#define _wxHtmlHelpData_h_
class wxHtmlHelpData : public wxObject
{
public:
   wxHtmlHelpData() ;
  bool AddBook(const wxString&  book_url ) ;
  wxString FindPageById(int  id ) ;
  wxString FindPageByName(const wxString&  page ) ;
  const wxHtmlBookRecArray& GetBookRecArray() ;
  wxHtmlContentsItem* GetContents() ;
  int GetContentsCnt() ;
  wxHtmlContentsItem* GetIndex() ;
  int GetIndexCnt() ;
  void SetTempDir(const wxString&  path ) ;
};


#endif
